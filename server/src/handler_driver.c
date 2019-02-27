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
#include <syslog.h>
#include <stdio.h>

#include "server.h"
#include "param_verification.h"

#include "train_engine_default.h"
#include "train_engine_linear.h"

#define MAX_TRAINS 32
#define TRAIN_ENGINE_TIME_STEP 200000	// In microseconds

pthread_mutex_t grabbed_trains_mutex = PTHREAD_MUTEX_INITIALIZER;

static unsigned int next_grab_id = 0;


typedef struct {
	bool is_valid;
	GString *name;
	pthread_t engine_thread;
	char track_output[32];
	
	t_tick_data engine_data;
	void (*engine_reset_function)(t_tick_data *engine_data);
	void (*engine_logic_function)(t_tick_data *engine_data);
	void (*engine_tick_function)(t_tick_data *engine_data);	
} t_train_data;

static t_train_data grabbed_trains[MAX_TRAINS] = {{.is_valid = false}};


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

void *grabbed_train_engine(void *args) {
	t_train_data *train_data = (t_train_data *)args;
		
	// Reset the train engine
	(*train_data->engine_reset_function)(&train_data->engine_data);

	do  {
		// Update the target speed and direction
		pthread_mutex_lock(&grabbed_trains_mutex);
		(*train_data->engine_tick_function)(&train_data->engine_data);
		pthread_mutex_unlock(&grabbed_trains_mutex);
		
		if (bidib_set_train_speed(train_data->name->str, 
								  train_data->engine_data.target_forwards 
								  ? train_data->engine_data.target_speed 
								  : -train_data->engine_data.target_speed, 
								  train_data->track_output)) {
			syslog(LOG_ERR, "Request: Set train speed - bad parameter values");
		} else {
			bidib_flush();
			syslog(LOG_NOTICE, "Request: Set train speed - train: %s speed: %d",
				   train_data->name->str, train_data->engine_data.requested_speed);
			pthread_mutex_unlock(&grabbed_trains_mutex);
		}
		
		usleep(TRAIN_ENGINE_TIME_STEP);
	} while (train_data->is_valid);
	
	// Ensure that the train really stops
	bidib_set_train_speed(train_data->name->str, 0, train_data->track_output);
	g_string_free(train_data->name, TRUE);
	return NULL;
}

static int set_train_engine(const int grab_id, const char *train, const char *engine) {
	if (engine != NULL) {
	 	if (!strcmp("default", engine)) {
			grabbed_trains[grab_id].engine_reset_function = &train_engine_default_reset;
			grabbed_trains[grab_id].engine_logic_function = &train_engine_default_logic;
			grabbed_trains[grab_id].engine_tick_function = &train_engine_default_tick;
			syslog(LOG_NOTICE, "Train %s has engine \"%s\"", train, engine);
			return 0;
		} else if (!strcmp("linear", engine)) {
			grabbed_trains[grab_id].engine_reset_function = &train_engine_linear_reset;
			grabbed_trains[grab_id].engine_logic_function = &train_engine_linear_logic;
			grabbed_trains[grab_id].engine_tick_function = &train_engine_linear_tick;
			syslog(LOG_NOTICE, "Train %s has engine \"%s\"", train, engine);
			return 0;
		}
	}
	
	syslog(LOG_ERR, "Train %s has no engine", train);
	return 1;
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
				syslog(LOG_ERR, "All grab ids in use");
				return -1;
			}
			increment_next_grab_id();
		}
	}
	int grab_id = next_grab_id;
	increment_next_grab_id();
	grabbed_trains[grab_id].name = g_string_new(train);
	if (set_train_engine(grab_id, train, engine)) {
		pthread_mutex_unlock(&grabbed_trains_mutex);
		syslog(LOG_ERR, "Train engine %s could not be used", engine);
		return -1;
	}
	grabbed_trains[grab_id].is_valid = true;
	pthread_create(&grabbed_trains[grab_id].engine_thread, NULL, 
	               grabbed_train_engine, &grabbed_trains[grab_id]);
	syslog(LOG_NOTICE, "Train %s grabbed", train);
	pthread_mutex_unlock(&grabbed_trains_mutex);
	return grab_id;
}

static bool free_train(int grab_id) {
	bool success = false;
	pthread_mutex_lock(&grabbed_trains_mutex);
	if (grabbed_trains[grab_id].is_valid) {
		grabbed_trains[grab_id].is_valid = false;
		syslog(LOG_NOTICE, "Train %s released", grabbed_trains[grab_id].name->str);
		success = true;
	}
	pthread_mutex_unlock(&grabbed_trains_mutex);
	return success;
}

void free_all_grabbed_trains(void) {
	pthread_mutex_lock(&grabbed_trains_mutex);
	for (size_t i = 0; i < MAX_TRAINS; i++) {
		free_train(i);
	}
	pthread_mutex_unlock(&grabbed_trains_mutex);
}

onion_connection_status handler_grab_train(void *_, onion_request *req,
                                           onion_response *res) {
	if (running && ((onion_request_get_flags(req) & OR_METHODS) == OR_POST)) {
		const char *data_train = onion_request_get_post(req, "train");
		const char *data_engine = onion_request_get_post(req, "engine");		
		if (data_train == NULL || data_engine == NULL) {
			syslog(LOG_ERR, "Request: Grab train - invalid parameters");
			return OCS_NOT_IMPLEMENTED;
		} else {
			t_bidib_train_state_query train_state =
				bidib_get_train_state(data_train);
			if (!train_state.known) {
				bidib_free_train_state_query(train_state);
				syslog(LOG_ERR, "Request: Grab train - train not known");
				return OCS_NOT_IMPLEMENTED;
			} else {
				bidib_free_train_state_query(train_state);
				int grab_id = grab_train(data_train, data_engine);
				if (grab_id == -1) {
					syslog(LOG_ERR, "Request: Grab train - train already grabbed");
					return OCS_NOT_IMPLEMENTED;
				} else {
					syslog(LOG_NOTICE, "Request: Grab train - train: %s", data_train);
					onion_response_printf(res, "%ld,%d", session_id, grab_id);
					return OCS_PROCESSED;
				}
			}
		}
	} else {
		syslog(LOG_ERR, "Request: Grab train - system not running or wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}
}

onion_connection_status handler_release_train(void *_, onion_request *req,
                                              onion_response *res) {
	if (running && ((onion_request_get_flags(req) & OR_METHODS) == OR_POST)) {
		const char *data_session_id = onion_request_get_post(req, "session-id");
		const char *data_grab_id = onion_request_get_post(req, "grab-id");
		int client_session_id = params_check_session_id(data_session_id);
		int grab_id = params_check_grab_id(data_grab_id, MAX_TRAINS);
		if (client_session_id != session_id) {
			syslog(LOG_NOTICE, "Request: Free train - invalid session id");
			onion_response_printf(res, "invalid session id");
			return OCS_PROCESSED;
		} else if (grab_id == -1 || !free_train(grab_id)) {
			syslog(LOG_ERR, "Request: Free train - invalid grab id");
			onion_response_printf(res, "invalid grab id");
			return OCS_PROCESSED;
		} else {
			syslog(LOG_NOTICE, "Request: Free train");
			return OCS_PROCESSED;
		}
	} else {
		syslog(LOG_ERR, "Request: Free train - system not running or wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}
}

onion_connection_status handler_set_dcc_train_speed(void *_, onion_request *req,
                                                    onion_response *res) {
	if (running && ((onion_request_get_flags(req) & OR_METHODS) == OR_POST)) {
		const char *data_session_id = onion_request_get_post(req, "session-id");
		const char *data_grab_id = onion_request_get_post(req, "grab-id");
		const char *data_speed = onion_request_get_post(req, "speed");
		const char *data_track_output = onion_request_get_post(req, "track-output");
		int client_session_id = params_check_session_id(data_session_id);
		int grab_id = params_check_grab_id(data_grab_id, MAX_TRAINS);
		int speed = params_check_speed(data_speed);
		if (client_session_id != session_id) {
			syslog(LOG_NOTICE, "Request: Set train speed - invalid session id");
			onion_response_printf(res, "invalid session id");
			return OCS_PROCESSED;
		} else if (grab_id == -1 || !grabbed_trains[grab_id].is_valid) {
			syslog(LOG_ERR, "Request: Set train speed - bad grab id");
			onion_response_printf(res, "invalid grab id");
			return OCS_PROCESSED;
		} else if (speed == 999) {
			syslog(LOG_ERR, "Request: Set train speed - bad speed");
			return OCS_NOT_IMPLEMENTED;
		} else if (data_track_output == NULL) {
			syslog(LOG_ERR, "Request: Set train speed - bad track output");
			return OCS_NOT_IMPLEMENTED;
		} else {
			pthread_mutex_lock(&grabbed_trains_mutex);
			strcpy(grabbed_trains[grab_id].track_output, data_track_output);
			if (speed < 0) {
				grabbed_trains[grab_id].engine_data.requested_forwards = 0;
				grabbed_trains[grab_id].engine_data.requested_speed = -speed;
			} else {
				grabbed_trains[grab_id].engine_data.requested_forwards = 1;
				grabbed_trains[grab_id].engine_data.requested_speed = speed;
			}
			pthread_mutex_unlock(&grabbed_trains_mutex);
			return OCS_PROCESSED;
		}
	} else {
		syslog(LOG_ERR, "Request: Set train speed - system not running or wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}
}

onion_connection_status handler_set_calibrated_train_speed(void *_,
                                                           onion_request *req,
                                                           onion_response *res) {
	if (running && ((onion_request_get_flags(req) & OR_METHODS) == OR_POST)) {
		const char *data_session_id = onion_request_get_post(req, "session-id");
		const char *data_grab_id = onion_request_get_post(req, "grab-id");
		const char *data_speed = onion_request_get_post(req, "speed");
		const char *data_track_output = onion_request_get_post(req, "track-output");
		int client_session_id = params_check_session_id(data_session_id);
		int grab_id = params_check_grab_id(data_grab_id, MAX_TRAINS);
		int speed  = params_check_calibrated_speed(data_speed);
		if (client_session_id != session_id) {
			syslog(LOG_ERR, "Request: Set calibrated train speed - invalid session id");
			onion_response_printf(res, "invalid session id");
			return OCS_PROCESSED;
		} else if (grab_id == -1 || !grabbed_trains[grab_id].is_valid) {
			syslog(LOG_ERR, "Request: Set calibrated train speed - bad grab id");
			onion_response_printf(res, "invalid grab id");
			return OCS_PROCESSED;
		} else if (speed == 999) {
			syslog(LOG_ERR, "Request: Set calibrated train speed - bad speed");
			return OCS_NOT_IMPLEMENTED;
		} else if (data_track_output == NULL) {
			syslog(LOG_ERR, "Request: Set calibrated train speed - bad track output");
			return OCS_NOT_IMPLEMENTED;
		} else {
			pthread_mutex_lock(&grabbed_trains_mutex);
			if (bidib_set_calibrated_train_speed(grabbed_trains[grab_id].name->str,
		                                         speed, data_track_output)) {
				syslog(LOG_ERR, "Request: Set calibrated train speed - bad "
				                "parameter values");
				pthread_mutex_unlock(&grabbed_trains_mutex);
				return OCS_NOT_IMPLEMENTED;
			} else {
				bidib_flush();
				syslog(LOG_NOTICE, "Request: Set calibrated train speed - "
				                   "train: %s speed: %d",
				       grabbed_trains[grab_id].name->str, speed);
				pthread_mutex_unlock(&grabbed_trains_mutex);
				return OCS_PROCESSED;
			}
		}
	} else {
		syslog(LOG_ERR, "Request: Set calibrated train speed - system not running "
		       "or wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}
}

onion_connection_status handler_set_train_emergency_stop(void *_,
                                                         onion_request *req,
                                                         onion_response *res) {
	if (running && ((onion_request_get_flags(req) & OR_METHODS) == OR_POST)) {
		const char *data_session_id = onion_request_get_post(req, "session-id");
		const char *data_grab_id = onion_request_get_post(req, "grab-id");
		const char *data_track_output = onion_request_get_post(req, "track-output");
		int client_session_id = params_check_session_id(data_session_id);
		int grab_id = params_check_grab_id(data_grab_id, MAX_TRAINS);
		if (client_session_id != session_id) {
			syslog(LOG_ERR, "Request: Set train emergency stop - invalid session id");
			onion_response_printf(res, "invalid session id");
			return OCS_PROCESSED;
		} else if (grab_id == -1 || !grabbed_trains[grab_id].is_valid) {
			syslog(LOG_ERR, "Request: Set train emergency stop - bad grab id");
			onion_response_printf(res, "invalid grab id");
			return OCS_PROCESSED;
		} else if (data_track_output == NULL) {
			syslog(LOG_ERR, "Request: Set train emergency stop - bad track output");
			return OCS_NOT_IMPLEMENTED;
		} else {
			pthread_mutex_lock(&grabbed_trains_mutex);
			if (bidib_emergency_stop_train(grabbed_trains[grab_id].name->str,
		                                   data_track_output)) {
				syslog(LOG_ERR, "Request: Set train emergency stop - bad "
				                "parameter values");
				pthread_mutex_unlock(&grabbed_trains_mutex);
				return OCS_NOT_IMPLEMENTED;
			} else {
				bidib_flush();
				syslog(LOG_NOTICE, "Request: Set train emergency stop - train: %s",
				       grabbed_trains[grab_id].name->str);
				pthread_mutex_unlock(&grabbed_trains_mutex);
				return OCS_PROCESSED;
			}
		}
	} else {
		syslog(LOG_ERR, "Request: Set train emergency stop - system not running "
		       "or wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}
}

onion_connection_status handler_set_train_peripheral(void *_,
                                                     onion_request *req,
                                                     onion_response *res) {
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
			syslog(LOG_ERR, "Request: Set train peripheral - invalid session id");
			onion_response_printf(res, "invalid session id");
			return OCS_PROCESSED;
		} else if (grab_id == -1 || !grabbed_trains[grab_id].is_valid) {
			syslog(LOG_ERR, "Request: Set train peripheral - bad grab id");
			onion_response_printf(res, "invalid grab id");
			return OCS_PROCESSED;
		} else if (state == -1) {
			syslog(LOG_ERR, "Request: Set train peripheral - bad state");
			return OCS_NOT_IMPLEMENTED;
		} else if (data_peripheral == NULL) {
			syslog(LOG_ERR, "Request: Set train peripheral - bad peripheral");
			return OCS_NOT_IMPLEMENTED;
		} else if (data_track_output == NULL) {
			syslog(LOG_ERR, "Request: Set train peripheral - bad track output");
			return OCS_NOT_IMPLEMENTED;
		} else {
			pthread_mutex_lock(&grabbed_trains_mutex);
			if (bidib_set_train_peripheral(grabbed_trains[grab_id].name->str,
			                               data_peripheral, state,
			                               data_track_output)) {
				syslog(LOG_ERR, "Request: Set train peripheral - bad "
				                "parameter values");
				pthread_mutex_unlock(&grabbed_trains_mutex);
				return OCS_NOT_IMPLEMENTED;
			} else {
				bidib_flush();
				syslog(LOG_NOTICE, "Request: Set train peripheral - train: %s "
				                   "peripheral: %s state: 0x%02x",
				                   grabbed_trains[grab_id].name->str,
				                   data_peripheral, state);
				pthread_mutex_unlock(&grabbed_trains_mutex);
				return OCS_PROCESSED;
			}
		}
	} else {
		syslog(LOG_ERR, "Request: Set train peripheral - system not running or "
		       "wrong request type");
		return OCS_NOT_IMPLEMENTED;
	}
}

