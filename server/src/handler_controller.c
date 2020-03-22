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
#include <string.h>

#include "server.h"
#include "param_verification.h"
#include "interlocking.h"
#include "bahn_data_util.h"
#include "tick_data.h"
#include "dynlib.h"

pthread_mutex_t interlocker_mutex = PTHREAD_MUTEX_INITIALIZER;

char REQUEST_ROUTE_LIB_PATH[] = "../src/interlocking/request_route";
dynlib_data library_request_route = {};

int grant_route_with_algorithm(const char *train_id, const char *source_id, const char *destination_id) {
    pthread_mutex_lock(&interlocker_mutex);

    // init cache
    init_cached_track_state();

    // request route
    TickDataRequestRoute tick_data = {.src_signal_id = strdup(source_id),
                                      .dst_signal_id = strdup(destination_id),
                                      .train_id = strdup(train_id)};

    // execute the interlocking procedure
    if (!dynlib_is_loaded(&library_request_route)) {
        dynlib_load(&library_request_route, REQUEST_ROUTE_LIB_PATH);
        load_symbols(&library_request_route, "request_route_reset", "request_route_tick");
        syslog_server(LOG_NOTICE, "Loaded dynamic interlocking library: %s", library_request_route.filepath);
    }

    library_request_route.reset_func(&tick_data);
    while (tick_data.is_terminated == 0) {
        library_request_route.tick_func(&tick_data);
    }

    // Free

    free(tick_data.src_signal_id);
    free(tick_data.dst_signal_id);
    free(tick_data.train_id);
    free_cached_track_state();

    // result
    char *route_id = tick_data.out;
    int route_id_int = route_id != NULL && strcmp(route_id, "") != 0 ? (int)strtol(route_id, NULL, 10) : -1;
    if (route_id_int >= 0) {
        syslog_server(LOG_NOTICE, "Grant route with algorithm: Route %d has been granted", route_id_int);
    } else {
        syslog_server(LOG_ERR, "Grant route with algorithm: Route could not be granted");
    }

    pthread_mutex_unlock(&interlocker_mutex);
    return route_id_int;
}

void release_route(int route_id) {
	pthread_mutex_lock(&interlocker_mutex);
	t_interlocking_route *route = get_route(route_id);
	if (route->train != NULL) {
	    free(route->train);
        route->train = NULL;
	}

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

