/*
 *
 * Copyright (C) 2017 University of Bamberg, Software Technologies Research Group
 * <https://www.uni-bamberg.de/>, <http://www.swt-bamberg.de/>
 * 
 * This file is part of the SWTbahn command line interface (swtbahn-cli), which is
 * a client-server application to interactively control a BiDiB model railway.
 *
 * swtbahn-cli is licensed under the GNU GENERAL PUBLIC LICENSE (Version 3), see
 * the LICENSE file at the project's top-level directory for details or consult
 * <http://www.gnu.org/licenses/>.
 *
 * swtbahn-cli is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or any later version.
 *
 * swtbahn-cli is a RESEARCH PROTOTYPE and distributed WITHOUT ANY WARRANTY, without
 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU General Public License for more details.
 *
 * The following people contributed to the conception and realization of the
 * present swtbahn-cli (in alphabetic order by surname):
 *
 * - Nicolas Gross <https://github.com/nicolasgross>
 *
 */

#include <onion/onion.h>
#include <bidib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "server.h"
#include "param_verification.h"
#include "interlocking.h"

#include "interlocking_algorithm.h"
#include "interlocking/request_route.h"

pthread_mutex_t interlocker_mutex = PTHREAD_MUTEX_INITIALIZER;

bool route_is_unavailable_or_conflicted(const int route_id) {
	t_interlocking_route *route = get_route(route_id);

	// Check if the route has been granted (unavailable)
	if (route->train_id != NULL) {
		syslog_server(LOG_ERR, "Route has already been granted: %d", route_id);
		return true;
	} else {
		syslog_server(LOG_NOTICE, "Route available: %d", route_id);
	}
	
	// Check conflicts
	if (route->conflicts != NULL) {
		for (int i = 0; i < route->conflicts->len; ++i) {
			const size_t conflicted_route_id = g_array_index(route->conflicts, size_t, i);
			if (get_route(conflicted_route_id)->train_id != NULL) {
				syslog_server(LOG_ERR, "Conflicting route has been granted: %d", conflicted_route_id);
				return true;
			}
		}
	}

	return false;
}

bool route_is_clear(const int route_id, const char *train_id) {
	if (route_id == -1) {
		syslog_server(LOG_ERR, "Route is clear: Route %d is invalid", route_id);
		return false;
	} else {
		syslog_server(LOG_NOTICE, "Route is clear: Route %d is valid for train %s", route_id, train_id);
	}
	
	// Read the track state
	t_bidib_track_state track_state = bidib_get_state();

	t_interlocking_route *route = get_route(route_id);
	// Signal at the route source has to be red (stop aspect)
	const size_t source_signal_state_index = route->source.bidib_state_index;
	if (strcmp(track_state.signals_board[source_signal_state_index].data.state_id, "red")) {
		syslog_server(LOG_ERR, "Route is clear: Route %d - source signal is not in the stop aspect", 
		              route_id);
		bidib_free_track_state(track_state);
		return false;
	}
	
	// Signals of tracks that intersect the route have to be red (stop aspect)
	if (route->signals != NULL) {
		for (int signal_index = 0; signal_index < route->signals->len; ++signal_index) {
			t_interlocking_signal signal = g_array_index(route->signals, t_interlocking_signal, signal_index);
			const char *signal_id = signal.id;
			const size_t signal_state_index = signal.bidib_state_index;
			if (strcmp(track_state.signals_board[signal_state_index].data.state_id, "red")) {
				syslog_server(LOG_ERR, "Route is clear: Route %d - signal %s is not in the stop aspect",
				              route_id, signal_id);
				bidib_free_track_state(track_state);
				return false;
			}
		}
	}

	// All track segments on the route have to be clear
	for (int segment_index = 0; segment_index < route->path->len; ++segment_index) {
		t_interlocking_path_segment segment = g_array_index(route->path, t_interlocking_path_segment, segment_index);
		const char *segment_id = segment.id;
		const size_t segment_state_index = segment.bidib_state_index;

		if (track_state.segments[segment_state_index].data.occupied) {
			syslog_server(LOG_ERR, "Route is clear: Route %d - track segment %s has not been cleared",
			              route_id, segment_id);
			bidib_free_track_state(track_state);
			return false;
		}
	}

	bidib_free_track_state(track_state);
	return true;
}

bool set_route_points_signals(const int route_id) {
	syslog_server(LOG_NOTICE, "set_route_points_signals: route_id = %d", route_id);
	              t_interlocking_route *route = get_route(route_id);

	// Set points
	if (route->points != NULL) {
		for (int point_index = 0; point_index < route->points->len; ++point_index) {
			t_interlocking_point point = g_array_index(route->points, t_interlocking_point, point_index);
			const char *point_id = point.id;
			const e_interlocking_point_position point_position = point.position;

			if (bidib_switch_point(point_id, (point_position == NORMAL) ? "normal" : "reverse")) {
				syslog_server(LOG_ERR, "Execute route: Set point - invalid parameters");
				return false;
			} else {
				syslog_server(LOG_NOTICE, "Execute route: Set point - point: %s state: %s",
				point_id,
				point_position == NORMAL ? "normal" : "reverse");
				bidib_flush();
			}
		}
	}
	
	// Set entry signal to green (proceed aspect)
	const char *signal_id = route->source.id;
	if (bidib_set_signal(signal_id, "green")) {
		syslog_server(LOG_ERR, "Execute route: Set signal - invalid parameters");
		return false;
	} else {
		syslog_server(LOG_NOTICE, "Execute route: Set signal - signal: %s state: %s",
		              signal_id, "green");
		bidib_flush();
	}

	return true;
}

bool block_route(const int route_id, const char *train_id) {
	syslog_server(LOG_NOTICE, "Block route: train %s on route %d", train_id, route_id);
	t_interlocking_route *route = get_route(route_id);
	route->train_id = g_string_new(train_id);
	return true;
}

int grant_route(const char *train_id, const char *source_id, const char *destination_id) {
	pthread_mutex_lock(&interlocker_mutex);

	// Get a possible route from the interlocking table
	int route_id = interlocking_table_get_route_id(source_id, destination_id);
	if (route_id == -1) {
		pthread_mutex_unlock(&interlocker_mutex);
		syslog_server(LOG_ERR, "Grant route: No route found from %s to %s", source_id, destination_id);
		return -1;
	}

	// Check if the route has already been granted, 
	// or is in conflict with another granted route
	if (route_is_unavailable_or_conflicted(route_id)) {
		pthread_mutex_unlock(&interlocker_mutex);
		syslog_server(LOG_ERR, "Grant route: Route %d is blocked or has conflicts", route_id);
		return -1;
	}
		
	// Check if route has been cleared
	if (!route_is_clear(route_id, train_id)) {
		pthread_mutex_unlock(&interlocker_mutex);
		syslog_server(LOG_ERR, "Grant route: Route %d has not been cleared", route_id);
		return -1;
	}
	
	// Block the route for the requesting train
	block_route(route_id, train_id);
	pthread_mutex_unlock(&interlocker_mutex);
	
	// Set the route points and signals
	if (!set_route_points_signals(route_id)) {
		syslog_server(LOG_ERR, "Grant route: Route %d could not be set", route_id);
		return -1;
	}
	
	// Return the ID of the granted route
	syslog_server(LOG_NOTICE, "Grant route: Route %d has been granted", route_id);
	return route_id;
}

int grant_route_with_algorithm(const char *train_id, const char *source_id, const char *destination_id) {
    // request route
    TickData tick_data;
    reset(&tick_data);

    // Set the inputs
    tick_data.iface.src_signal_id = source_id;
    tick_data.iface.dst_signal_id = destination_id;
    tick_data.iface.train_id = train_id;

    // Execute the algorithm
    int cticks = 0;
    while (tick_data.threadStatus != TERMINATED) {
        tick(&tick_data);
        cticks++;
    }

    printf("count ticks: %d\n", cticks);

    // result
    char *route_id = tick_data.iface.out;
    printf("result route: %s\n", route_id);
    return (int)strtol(route_id, NULL, 10);
}

int grant_route_with_algorithm_bak(const char *train_id, const char *source_id, const char *destination_id) {
	t_interlocking_algorithm_tick_data interlocking_data;
	interlocking_algorithm_reset(&interlocking_data);

	// Set the inputs
	interlocking_data.request_available = true;
	interlocking_data.train_id = train_id;
	interlocking_data.source_id = source_id;
	interlocking_data.destination_id = destination_id;
	
	// Execute the algorithm
	pthread_mutex_lock(&interlocker_mutex);
	interlocking_algorithm_tick(&interlocking_data);
	pthread_mutex_unlock(&interlocker_mutex);

	interlocking_data.request_available = false;

	switch (interlocking_data.route_id) {
		case (-1):
			syslog_server(LOG_ERR, "Grant route with algorithm: Route could not be granted (1. Wait)");
			return -1;
		case (-2):
			syslog_server(LOG_ERR, "Grant route with algorithm: Route could not be granted (2. Find)");
			return -1;
		case (-3):
			syslog_server(LOG_ERR, "Grant route with algorithm: Route could not be granted (3. Grantable)");
			return -1;
		case (-4):
			syslog_server(LOG_ERR, "Grant route with algorithm: Route could not be granted (3. Clearance)");
			return -1;
		default:
			break;
	} 
	
	// Return the ID of the granted route
	syslog_server(LOG_NOTICE, "Grant route with algorithm: Route %d has been granted", interlocking_data.route_id);
	return interlocking_data.route_id;
}

void release_route(const int route_id) {
	pthread_mutex_lock(&interlocker_mutex);
	t_interlocking_route *route = get_route(route_id);
	g_string_free(route->train_id, TRUE);
	route->train_id = NULL;
	pthread_mutex_unlock(&interlocker_mutex);
}

onion_connection_status handler_release_route(void *_, onion_request *req,
                                          onion_response *res) {
	build_response_header(res);
	if (running && ((onion_request_get_flags(req) & OR_METHODS) == OR_POST)) {
		const char *data_route_id = onion_request_get_post(req, "route-id");
		const int route_id = params_check_route_id(data_route_id);
		if (route_id == -1) {
			syslog_server(LOG_ERR, "Request: Release route - invalid parameters");
			return OCS_NOT_IMPLEMENTED;
		} else {
			release_route(route_id);
			syslog_server(LOG_NOTICE, "Request: Release route - route: %d", route_id);
			return OCS_PROCESSED;
		}
	} else {
		syslog_server(LOG_ERR, "Request: Release route - system not running or wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}
}

onion_connection_status handler_set_point(void *_, onion_request *req,
                                          onion_response *res) {
	build_response_header(res);
	if (running && ((onion_request_get_flags(req) & OR_METHODS) == OR_POST)) {
		const char *data_point = onion_request_get_post(req, "point");
		const char *data_state = onion_request_get_post(req, "state");
		if (data_point == NULL || data_state == NULL) {
			syslog_server(LOG_ERR, "Request: Set point - invalid parameters");
			return OCS_NOT_IMPLEMENTED;
		} else {
			if (bidib_switch_point(data_point, data_state)) {
				syslog_server(LOG_ERR, "Request: Set point - invalid parameters");
				bidib_flush();
				return OCS_NOT_IMPLEMENTED;
			} else {
				syslog_server(LOG_NOTICE, "Request: Set point - point: %s state: %s",
				       data_point, data_state);
				bidib_flush();
				return OCS_PROCESSED;
			}
		}
	} else {
		syslog_server(LOG_ERR, "Request: Set point - system not running or wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}
}

onion_connection_status handler_set_signal(void *_, onion_request *req,
                                           onion_response *res) {
	build_response_header(res);
	if (running && ((onion_request_get_flags(req) & OR_METHODS) == OR_POST)) {
		const char *data_signal = onion_request_get_post(req, "signal");
		const char *data_state = onion_request_get_post(req, "state");
		if (data_signal == NULL || data_state == NULL) {
			syslog_server(LOG_ERR, "Request: Set signal - invalid parameters");
			return OCS_NOT_IMPLEMENTED;
		} else {
			if (bidib_set_signal(data_signal, data_state)) {
				syslog_server(LOG_ERR, "Request: Set signal - invalid parameters");
				return OCS_NOT_IMPLEMENTED;
			} else {
				syslog_server(LOG_NOTICE, "Request: Set signal - signal: %s state: %s",
				              data_signal, data_state);
				bidib_flush();
				return OCS_PROCESSED;
			}
		}
	} else {
		syslog_server(LOG_ERR, "Request: Set signal - system not running or wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}
}

