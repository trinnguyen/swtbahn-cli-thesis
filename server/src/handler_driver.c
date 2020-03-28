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
#include <glib.h>
#include <string.h>

#include "server.h"
#include "dyn_containers_interface.h"
#include "handler_controller.h"
#include "interlocking.h"
#include "param_verification.h"
#include "bahn_data_util.h"
#include "tick_data.h"
#include "dynlib.h"

#define MICROSECOND 1
#define TRAIN_DRIVE_TIME_STEP 	50000 * MICROSECOND		// 0.05 seconds

pthread_mutex_t grabbed_trains_mutex = PTHREAD_MUTEX_INITIALIZER;

static unsigned int next_grab_id = 0;

t_train_data grabbed_trains[MAX_TRAINS] = {
	{ .is_valid = false, .dyn_containers_engine_instance = -1 }
};

static void increment_next_grab_id(void) {
	if (next_grab_id == MAX_TRAINS - 1) {
		next_grab_id = 0;
	} else {
		next_grab_id++;
	}
}

bool train_grabbed(const char *train) {
	bool grabbed = false;
	pthread_mutex_lock(&grabbed_trains_mutex);
	for (size_t i = 0; i < MAX_TRAINS; i++) {
		if (grabbed_trains[i].is_valid 
				&& grabbed_trains[i].name != NULL 
				&& !strcmp(grabbed_trains[i].name->str, train)) {
			grabbed = true;
			break;
		}
	}
	pthread_mutex_unlock(&grabbed_trains_mutex);
	return grabbed;
}

static bool train_position_is_at(const char *train_id, const char *segment) {
	t_bidib_train_position_query train_position_query = bidib_get_train_position(train_id);

	for (size_t i = 0; i < train_position_query.length; i++) {
		if (!strcmp(segment, train_position_query.segments[i])) {
			bidib_free_train_position_query(train_position_query);
			return true;
		}
	}
	
	bidib_free_train_position_query(train_position_query);
	return false;
}

static interlocking_dynlib_data lib_interlocking = {};

int load_interlocking_library() {
    const char *path = "../src/interlocking/libinterlocking_default";
    dynlib_status status = dynlib_load_interlocking(&lib_interlocking, path);
    if (status == DYNLIB_LOAD_SUCCESS) {
        syslog_server(LOG_NOTICE, "Loaded dynamic interlocking library: %s", path);
        return 0;
    }

    return 1;
}

void close_interlocking_library() {
    dynlib_close_interlocking(&lib_interlocking);
}

/**
 * Finds and grants a requested train route.
 * A requested route is defined by a pair of source and destination signals.
 *
 * @param name of the source signal
 * @param name of the destination signal
 * @return ID of the route if it has been granted, otherwise -1
 */
static char *grant_route_with_algorithm(const char *train_id, const char *source_id, const char *destination_id) {
    pthread_mutex_lock(&interlocker_mutex);

    // init cache
    init_cached_track_state();

    // request route
    request_route_tick_data tick_data = {.src_signal_id = strdup(source_id),
            .dst_signal_id = strdup(destination_id),
            .train_id = strdup(train_id)};

    lib_interlocking.request_reset_func(&tick_data);
    while (tick_data.terminated == 0) {
        lib_interlocking.request_tick_func(&tick_data);
    }

    // Free
    free(tick_data.src_signal_id);
    free(tick_data.dst_signal_id);
    free(tick_data.train_id);
    free_cached_track_state();

    // result
    char *route_id = tick_data.out;
    if (route_id != NULL) {
        syslog_server(LOG_NOTICE, "Grant route with algorithm: Route %s has been granted", route_id);
    } else {
        syslog_server(LOG_ERR, "Grant route with algorithm: Route could not be granted");
    }

    pthread_mutex_unlock(&interlocker_mutex);
    return route_id;
}

static void free_array(char **arr, int len) {
    if (len >= 0 && arr != NULL) {
        for (int i = 0; i < len; ++i) {
            if (arr[i] != NULL) {
                free(arr[i]);
                arr[i] = NULL;
            }
        }
    }
}

static bool drive_route(const int grab_id, const int route_id) {
	const char *train_id = grabbed_trains[grab_id].name->str;
	t_interlocking_route *route = get_route(route_id);
	if (route->train == NULL) {
		pthread_mutex_unlock(&interlocker_mutex);
		syslog_server(LOG_ERR, "Drive route: Route %d not granted to train %s", route_id, train_id);
		return false;
	}

	pthread_mutex_lock(&interlocker_mutex);
	if (strcmp(train_id, route->train) != 0) {
		pthread_mutex_unlock(&interlocker_mutex);
		syslog_server(LOG_ERR, "Drive route: Route %d not granted to train %s", route_id, train_id);
		return false;
	}
	pthread_mutex_unlock(&interlocker_mutex);
	
	// Driving starts
	pthread_mutex_lock(&grabbed_trains_mutex);
	const int engine_instance = grabbed_trains[grab_id].dyn_containers_engine_instance;
	const int requested_speed = 20;
	const char requested_forwards = true; // TODO train direction is no long supported by interlocking table
	dyn_containers_set_train_engine_instance_inputs(engine_instance,
	                                       requested_speed, requested_forwards);
	pthread_mutex_unlock(&grabbed_trains_mutex);
	
	// Set entry signal to red (stop aspect)
	const char *signal_id = route->source;
	if (bidib_set_signal(signal_id, "red")) {
		syslog_server(LOG_ERR, "Drive route: Entry signal not set to stop aspect");
		return false;
	} else {
		syslog_server(LOG_NOTICE, "Drive route: Set signal - signal: %s state: %s",
		              signal_id, "red");
		bidib_flush();
	}

	// prepare tick data
	drive_route_tick_data drive_data = {.route_id = strdup(route->id), .train_id = strdup(train_id)};
		
	// Wait until the destination has been reached
	const int path_count = route->path->len;
	const char *destination = g_array_index(route->path, char *, path_count - 1);
	while (true) {
	    bool is_at_destination = false;

	    // get segments
        t_bidib_train_position_query train_position_query = bidib_get_train_position(train_id);
        int num_segments = train_position_query.length;
        char *segments[num_segments];
        for (size_t i = 0; i < num_segments; i++) {
            if (strcmp(destination, train_position_query.segments[i]) == 0) {
                is_at_destination = true;
                break;
            }

            segments[i] = train_position_query.segments[i];
        }

        bidib_free_train_position_query(train_position_query);

        // check if reach final segment
        if (is_at_destination) {
            free_array(segments, num_segments);
            break;
        }

		// invoke interlocking library
		if (lib_interlocking.drive_reset_func != NULL && lib_interlocking.drive_tick_func != NULL) {
		    // update current segments
            drive_data.count_segments = num_segments;
            for (int i = 0; i < num_segments; ++i) {
                drive_data.segment_ids[i] = segments[i];
            }

		    // call SCCharts reset and tick function
            lib_interlocking.drive_reset_func(&drive_data);
            while (drive_data.terminated == 0) {
                lib_interlocking.drive_tick_func(&drive_data);
            }
		}

		// free
        free_array(segments, num_segments);

        usleep(TRAIN_DRIVE_TIME_STEP);
	}

	// free tick data
	free(drive_data.route_id);
	free(drive_data.train_id);

	// Driving stops
	pthread_mutex_lock(&grabbed_trains_mutex);
	dyn_containers_set_train_engine_instance_inputs(engine_instance, 0, true);
	pthread_mutex_unlock(&grabbed_trains_mutex);
	
	// Controller releases the route
	release_route(route_id);
	return true;
}

static int grab_train(const char *train, const char *engine) {
	pthread_mutex_lock(&grabbed_trains_mutex);
	for (size_t i = 0; i < MAX_TRAINS; i++) {
		if (grabbed_trains[i].is_valid && !strcmp(grabbed_trains[i].name->str, train)) {
			pthread_mutex_unlock(&grabbed_trains_mutex);
			return -1;
		}
	}
	int start = next_grab_id;
	if (grabbed_trains[next_grab_id].is_valid) {
		increment_next_grab_id();
		while (grabbed_trains[next_grab_id].is_valid) {
			if (next_grab_id == start) {
				pthread_mutex_unlock(&grabbed_trains_mutex);
				syslog_server(LOG_ERR, "All grab ids in use");
				return -1;
			}
			increment_next_grab_id();
		}
	}
	int grab_id = next_grab_id;
	increment_next_grab_id();
	grabbed_trains[grab_id].name = g_string_new(train);
	strcpy(grabbed_trains[grab_id].track_output, "master");
	if (dyn_containers_set_train_engine(&grabbed_trains[grab_id], train, engine)) {
		pthread_mutex_unlock(&grabbed_trains_mutex);
		syslog_server(LOG_ERR, "Train engine %s could not be used", engine);
		return -1;
	}
	grabbed_trains[grab_id].is_valid = true;
	pthread_mutex_unlock(&grabbed_trains_mutex);
	syslog_server(LOG_NOTICE, "Train %s grabbed", train);
	return grab_id;
}

static bool free_train(int grab_id) {
	bool success = false;
	pthread_mutex_lock(&grabbed_trains_mutex);
	if (grabbed_trains[grab_id].is_valid) {
		grabbed_trains[grab_id].is_valid = false;
		dyn_containers_free_train_engine_instance(grabbed_trains[grab_id].dyn_containers_engine_instance);
		syslog_server(LOG_NOTICE, "Train %s released", grabbed_trains[grab_id].name->str);
		g_string_free(grabbed_trains[grab_id].name, TRUE);
		success = true;
	}
	pthread_mutex_unlock(&grabbed_trains_mutex);
	return success;
}

void free_all_grabbed_trains(void) {
	for (size_t i = 0; i < MAX_TRAINS; i++) {
		free_train(i);
	}
}

onion_connection_status handler_grab_train(void *_, onion_request *req,
                                           onion_response *res) {
	build_response_header(res);
	if (running && ((onion_request_get_flags(req) & OR_METHODS) == OR_POST)) {
		const char *data_train = onion_request_get_post(req, "train");
		const char *data_engine = onion_request_get_post(req, "engine");		
		if (data_train == NULL || data_engine == NULL) {
			syslog_server(LOG_ERR, "Request: Grab train - invalid parameters");
			return OCS_NOT_IMPLEMENTED;
		} else {
			t_bidib_train_state_query train_state =
				bidib_get_train_state(data_train);
			if (!train_state.known) {
				bidib_free_train_state_query(train_state);
				syslog_server(LOG_ERR, "Request: Grab train - train not known");
				return OCS_NOT_IMPLEMENTED;
			} else {
				bidib_free_train_state_query(train_state);
				int grab_id = grab_train(data_train, data_engine);
				if (grab_id == -1) {
					syslog_server(LOG_ERR, "Request: Grab train - train already grabbed");
					return OCS_NOT_IMPLEMENTED;
				} else {
					syslog_server(LOG_NOTICE, "Request: Grab train - train: %s", data_train);
					onion_response_printf(res, "%ld,%d", session_id, grab_id);
					return OCS_PROCESSED;
				}
			}
		}
	} else {
		syslog_server(LOG_ERR, "Request: Grab train - system not running or wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}
}

onion_connection_status handler_release_train(void *_, onion_request *req,
                                              onion_response *res) {
	build_response_header(res);
	if (running && ((onion_request_get_flags(req) & OR_METHODS) == OR_POST)) {
		const char *data_session_id = onion_request_get_post(req, "session-id");
		const char *data_grab_id = onion_request_get_post(req, "grab-id");
		int client_session_id = params_check_session_id(data_session_id);
		int grab_id = params_check_grab_id(data_grab_id, MAX_TRAINS);
		if (client_session_id != session_id) {
			syslog_server(LOG_ERR, "Request: Release train - invalid session id");
			return OCS_NOT_IMPLEMENTED;
		} else if (!grabbed_trains[grab_id].is_valid) {
			syslog_server(LOG_ERR, "Request: Release train - invalid grab id");
			return OCS_NOT_IMPLEMENTED;
		}
		
		t_bidib_train_state_query train_state = 
			bidib_get_train_state(grabbed_trains[grab_id].name->str);

		if (train_state.data.set_speed_step != 0) {
			syslog_server(LOG_ERR, "Request: Release train - train still moving");
			return OCS_NOT_IMPLEMENTED;
		} else if (grab_id == -1 || !free_train(grab_id)) {
			syslog_server(LOG_ERR, "Request: Release train - invalid grab id");
			return OCS_NOT_IMPLEMENTED;
		} else {
			syslog_server(LOG_NOTICE, "Request: Release train");
			return OCS_PROCESSED;
		}
	} else {
		syslog_server(LOG_ERR, "Request: Free train - system not running or wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}
}

onion_connection_status handler_request_route(void *_, onion_request *req,
                                              onion_response *res) {
	build_response_header(res);
	if (running && ((onion_request_get_flags(req) & OR_METHODS) == OR_POST)) {
		const char *data_session_id = onion_request_get_post(req, "session-id");
		const char *data_grab_id = onion_request_get_post(req, "grab-id");
		const char *data_source_name = onion_request_get_post(req, "source");
		const char *data_destination_name = onion_request_get_post(req, "destination");
		const int client_session_id = params_check_session_id(data_session_id);
		const int grab_id = params_check_grab_id(data_grab_id, MAX_TRAINS);
		if (client_session_id != session_id) {
			syslog_server(LOG_ERR, "Request: Request train route - invalid session id");
			return OCS_NOT_IMPLEMENTED;
		} else if (grab_id == -1 || !grabbed_trains[grab_id].is_valid) {
			syslog_server(LOG_ERR, "Request: Request train route - bad grab id");
			return OCS_NOT_IMPLEMENTED;
		} else if (data_source_name == NULL || data_destination_name == NULL) {
			syslog_server(LOG_ERR, "Request: Request train route - invalid parameters");
			return OCS_NOT_IMPLEMENTED;
		} else {
			// Call interlocking function to find and grant a route
			const char *route_id = grant_route_with_algorithm(grabbed_trains[grab_id].name->str,
			                                                data_source_name, 
			                                                data_destination_name);
			if (route_id != NULL) {
				syslog_server(LOG_NOTICE, "Request: Request train route - "
				              "train: %s route %s",
				              grabbed_trains[grab_id].name->str, route_id);
				onion_response_printf(res, "%s", route_id);
				return OCS_PROCESSED;
			} else {
				syslog_server(LOG_ERR, "Request: Request train route - "
				              "train: %s route not granted",
				              grabbed_trains[grab_id].name->str);
				return OCS_NOT_IMPLEMENTED;
			}
		}
	} else {
		syslog_server(LOG_ERR, "Request: Request train route - system not running or wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}                                       
}

onion_connection_status handler_drive_route(void *_, onion_request *req,
                                              onion_response *res) {
	build_response_header(res);
	if (running && ((onion_request_get_flags(req) & OR_METHODS) == OR_POST)) {
		const char *data_session_id = onion_request_get_post(req, "session-id");
		const char *data_grab_id = onion_request_get_post(req, "grab-id");
		const char *data_route_id = onion_request_get_post(req, "route-id");
		const int client_session_id = params_check_session_id(data_session_id);
		const int grab_id = params_check_grab_id(data_grab_id, MAX_TRAINS);
		const int route_id = params_check_route_id(data_route_id);
		if (client_session_id != session_id) {
			syslog_server(LOG_ERR, "Request: Drive route - invalid session id");
			return OCS_NOT_IMPLEMENTED;
		} else if (grab_id == -1 || !grabbed_trains[grab_id].is_valid) {
			syslog_server(LOG_ERR, "Request: Drive route - bad grab id");
			return OCS_NOT_IMPLEMENTED;
		} else if (route_id == -1) {
			syslog_server(LOG_ERR, "Request: Drive route - invalid parameter");
			return OCS_NOT_IMPLEMENTED;
		} else {
			if (drive_route(grab_id, route_id)) {
				return OCS_PROCESSED;
			} else {
				return OCS_NOT_IMPLEMENTED;
			}
		}
	} else {
		syslog_server(LOG_ERR, "Request: Drive route - system not running or wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}  
}

onion_connection_status handler_set_dcc_train_speed(void *_, onion_request *req,
                                                    onion_response *res) {
	build_response_header(res);
	if (running && ((onion_request_get_flags(req) & OR_METHODS) == OR_POST)) {
		const char *data_session_id = onion_request_get_post(req, "session-id");
		const char *data_grab_id = onion_request_get_post(req, "grab-id");
		const char *data_speed = onion_request_get_post(req, "speed");
		const char *data_track_output = onion_request_get_post(req, "track-output");
		int client_session_id = params_check_session_id(data_session_id);
		int grab_id = params_check_grab_id(data_grab_id, MAX_TRAINS);
		int speed = params_check_speed(data_speed);
		if (client_session_id != session_id) {
			syslog_server(LOG_ERR, "Request: Set train speed - invalid session id");
			return OCS_NOT_IMPLEMENTED;
		} else if (grab_id == -1 || !grabbed_trains[grab_id].is_valid) {
			syslog_server(LOG_ERR, "Request: Set train speed - bad grab id");
			return OCS_NOT_IMPLEMENTED;
		} else if (speed == 999) {
			syslog_server(LOG_ERR, "Request: Set train speed - bad speed");
			return OCS_NOT_IMPLEMENTED;
		} else if (data_track_output == NULL) {
			syslog_server(LOG_ERR, "Request: Set train speed - bad track output");
			return OCS_NOT_IMPLEMENTED;
		} else {
			pthread_mutex_lock(&grabbed_trains_mutex);
			strcpy(grabbed_trains[grab_id].track_output, data_track_output);
			int dyn_containers_engine_instance = grabbed_trains[grab_id].dyn_containers_engine_instance;
			if (speed < 0) {
				dyn_containers_set_train_engine_instance_inputs(dyn_containers_engine_instance,
				                                                -speed, false);
			} else {
				dyn_containers_set_train_engine_instance_inputs(dyn_containers_engine_instance,
				                                                speed, true);
			}
			pthread_mutex_unlock(&grabbed_trains_mutex);
			return OCS_PROCESSED;
		}
	} else {
		syslog_server(LOG_ERR, "Request: Set train speed - system not running or wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}
}

onion_connection_status handler_set_calibrated_train_speed(void *_,
                                                           onion_request *req,
                                                           onion_response *res) {
	build_response_header(res);
	if (running && ((onion_request_get_flags(req) & OR_METHODS) == OR_POST)) {
		const char *data_session_id = onion_request_get_post(req, "session-id");
		const char *data_grab_id = onion_request_get_post(req, "grab-id");
		const char *data_speed = onion_request_get_post(req, "speed");
		const char *data_track_output = onion_request_get_post(req, "track-output");
		int client_session_id = params_check_session_id(data_session_id);
		int grab_id = params_check_grab_id(data_grab_id, MAX_TRAINS);
		int speed  = params_check_calibrated_speed(data_speed);
		if (client_session_id != session_id) {
			syslog_server(LOG_ERR, "Request: Set calibrated train speed - invalid session id");
			return OCS_NOT_IMPLEMENTED;
		} else if (grab_id == -1 || !grabbed_trains[grab_id].is_valid) {
			syslog_server(LOG_ERR, "Request: Set calibrated train speed - bad grab id");
			return OCS_NOT_IMPLEMENTED;
		} else if (speed == 999) {
			syslog_server(LOG_ERR, "Request: Set calibrated train speed - bad speed");
			return OCS_NOT_IMPLEMENTED;
		} else if (data_track_output == NULL) {
			syslog_server(LOG_ERR, "Request: Set calibrated train speed - bad track output");
			return OCS_NOT_IMPLEMENTED;
		} else {
			pthread_mutex_lock(&grabbed_trains_mutex);
			if (bidib_set_calibrated_train_speed(grabbed_trains[grab_id].name->str,
		                                         speed, data_track_output)) {
				syslog_server(LOG_ERR, "Request: Set calibrated train speed - bad "
				              "parameter values");
				pthread_mutex_unlock(&grabbed_trains_mutex);
				return OCS_NOT_IMPLEMENTED;
			} else {
				bidib_flush();
				syslog_server(LOG_NOTICE, "Request: Set calibrated train speed - "
				              "train: %s speed: %d",
				              grabbed_trains[grab_id].name->str, speed);
				pthread_mutex_unlock(&grabbed_trains_mutex);
				return OCS_PROCESSED;
			}
		}
	} else {
		syslog_server(LOG_ERR, "Request: Set calibrated train speed - system not running "
		       "or wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}
}

onion_connection_status handler_set_train_emergency_stop(void *_,
                                                         onion_request *req,
                                                         onion_response *res) {
	build_response_header(res);
	if (running && ((onion_request_get_flags(req) & OR_METHODS) == OR_POST)) {
		const char *data_session_id = onion_request_get_post(req, "session-id");
		const char *data_grab_id = onion_request_get_post(req, "grab-id");
		const char *data_track_output = onion_request_get_post(req, "track-output");
		int client_session_id = params_check_session_id(data_session_id);
		int grab_id = params_check_grab_id(data_grab_id, MAX_TRAINS);
		if (client_session_id != session_id) {
			syslog_server(LOG_ERR, "Request: Set train emergency stop - invalid session id");
			return OCS_NOT_IMPLEMENTED;
		} else if (grab_id == -1 || !grabbed_trains[grab_id].is_valid) {
			syslog_server(LOG_ERR, "Request: Set train emergency stop - bad grab id");
			return OCS_NOT_IMPLEMENTED;
		} else if (data_track_output == NULL) {
			syslog_server(LOG_ERR, "Request: Set train emergency stop - bad track output");
			return OCS_NOT_IMPLEMENTED;
		} else {
			pthread_mutex_lock(&grabbed_trains_mutex);
			if (bidib_emergency_stop_train(grabbed_trains[grab_id].name->str,
		                                   data_track_output)) {
				syslog_server(LOG_ERR, "Request: Set train emergency stop - bad "
				              "parameter values");
				pthread_mutex_unlock(&grabbed_trains_mutex);
				return OCS_NOT_IMPLEMENTED;
			} else {
				bidib_flush();
				syslog_server(LOG_NOTICE, "Request: Set train emergency stop - train: %s",
				              grabbed_trains[grab_id].name->str);
				pthread_mutex_unlock(&grabbed_trains_mutex);
				return OCS_PROCESSED;
			}
		}
	} else {
		syslog_server(LOG_ERR, "Request: Set train emergency stop - system not running "
		              "or wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}
}

onion_connection_status handler_set_train_peripheral(void *_,
                                                     onion_request *req,
                                                     onion_response *res) {
	build_response_header(res);
	if (running && ((onion_request_get_flags(req) & OR_METHODS) == OR_POST)) {
		const char *data_session_id = onion_request_get_post(req, "session-id");
		const char *data_grab_id = onion_request_get_post(req, "grab-id");
		const char *data_peripheral = onion_request_get_post(req, "peripheral");
		const char *data_state = onion_request_get_post(req, "state");
		const char *data_track_output = onion_request_get_post(req, "track-output");
		int client_session_id = params_check_session_id(data_session_id);
		int grab_id = params_check_grab_id(data_grab_id, MAX_TRAINS);
		int state = params_check_state(data_state);
		if (client_session_id != session_id) {
			syslog_server(LOG_ERR, "Request: Set train peripheral - invalid session id");
			return OCS_NOT_IMPLEMENTED;
		} else if (grab_id == -1 || !grabbed_trains[grab_id].is_valid) {
			syslog_server(LOG_ERR, "Request: Set train peripheral - bad grab id");
			return OCS_NOT_IMPLEMENTED;
		} else if (state == -1) {
			syslog_server(LOG_ERR, "Request: Set train peripheral - bad state");
			return OCS_NOT_IMPLEMENTED;
		} else if (data_peripheral == NULL) {
			syslog_server(LOG_ERR, "Request: Set train peripheral - bad peripheral");
			return OCS_NOT_IMPLEMENTED;
		} else if (data_track_output == NULL) {
			syslog_server(LOG_ERR, "Request: Set train peripheral - bad track output");
			return OCS_NOT_IMPLEMENTED;
		} else {
			pthread_mutex_lock(&grabbed_trains_mutex);
			if (bidib_set_train_peripheral(grabbed_trains[grab_id].name->str,
			                               data_peripheral, state,
			                               data_track_output)) {
				syslog_server(LOG_ERR, "Request: Set train peripheral - bad "
				              "parameter values");
				pthread_mutex_unlock(&grabbed_trains_mutex);
				return OCS_NOT_IMPLEMENTED;
			} else {
				bidib_flush();
				syslog_server(LOG_NOTICE, "Request: Set train peripheral - train: %s "
				              "peripheral: %s state: 0x%02x",
				              grabbed_trains[grab_id].name->str,
				              data_peripheral, state);
				pthread_mutex_unlock(&grabbed_trains_mutex);
				return OCS_PROCESSED;
			}
		}
	} else {
		syslog_server(LOG_ERR, "Request: Set train peripheral - system not running or "
		              "wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}
}

