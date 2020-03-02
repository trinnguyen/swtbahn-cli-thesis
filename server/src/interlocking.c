/*
 *
 * Copyright (C) 2020 University of Bamberg, Software Technologies Research Group
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
 * - Eugene Yip <https://github.com/eyip002>
 *
 */
 
#include <bidib.h>
#include <glib.h>
#include <string.h>
#include <stdio.h>

#include "interlocking.h"
#include "server.h"
#include "interlocking_parser.h"


GArray *interlocking_table = NULL;
GHashTable *route_string_to_ids_hashtable = NULL;


void free_interlocking_hashtable_key(void *pointer) {
	char *key = (char *)pointer;
	free(key);
}

void free_interlocking_hashtable_value(void *pointer) {
	GArray *value = (GArray *)pointer;
	g_array_free(value, true);
}

int create_interlocking_hashtable(void) {
	route_string_to_ids_hashtable = g_hash_table_new_full(g_str_hash, g_str_equal, free_interlocking_hashtable_key, free_interlocking_hashtable_value);
	for (int route_index = 0; route_index < interlocking_table->len; ++route_index) {
		t_interlocking_route *route = get_route(route_index);

		// Build key, example: signal3signal6
		size_t len = strlen(route->source.id) + strlen(route->destination.id) + 1;
		char *route_string = malloc(sizeof(char*) * len);
		snprintf(route_string, len, "%s%s", route->source.id, route->destination.id);

		if (g_hash_table_contains(route_string_to_ids_hashtable, route_string)) {
			void *route_ids_ptr = g_hash_table_lookup(route_string_to_ids_hashtable, route_string);
			GArray *route_ids = (GArray *) route_ids_ptr;
			g_array_append_val(route_ids, route->id);
		} else {
			GArray *route_ids = g_array_sized_new(FALSE, FALSE, sizeof(size_t), 8);
			g_array_append_val(route_ids, route->id);
			g_hash_table_insert(route_string_to_ids_hashtable, route_string, route_ids);
		}
	}
	
	syslog_server(LOG_NOTICE, "Interlocking create hash table: successful");
	return 0;
}

void free_interlocking_hashtable(void) {
	if (route_string_to_ids_hashtable != NULL) {
		g_hash_table_destroy(route_string_to_ids_hashtable);
		route_string_to_ids_hashtable = NULL;
	}
}

void free_interlocking_table(void) {
	if (interlocking_table != NULL) {
		g_array_free(interlocking_table, true);
		interlocking_table = NULL;
	}
}

static int interlocking_table_resolve_indices(void) {
	for (int route_id = 0; route_id < interlocking_table->len; ++route_id) {
		t_interlocking_route *route = get_route(route_id);
		// Resolve the libbidib state array indices for track segments,
		// points, and signals.
	
		GString *log = g_string_new("Interlocking resolve indicies: ");
		g_string_append_printf(log, "Route id: %s ", route->id);
		
		char *id = route->source.id;
		route->source.bidib_state_index = bidib_get_signal_state_index(id);
		if (route->source.bidib_state_index == -1) {
			syslog_server(LOG_ERR, "Interlocking resolve indicies: %s not found in BiDiB state", id);
			return 1;
		}
		id = route->destination.id;
		route->destination.bidib_state_index = bidib_get_signal_state_index(id);
		if (route->destination.bidib_state_index == -1) {
			syslog_server(LOG_ERR, "Interlocking resolve indicies: %s not found in BiDiB state", id);
			return 1;
		}
		
		g_string_append_printf(log, "Source: %s (%d) ", 
		                       route->source.id,
		                       route->source.bidib_state_index);
		g_string_append_printf(log, "Destination: %s (%d) ", 
		                       route->destination.id,
		                       route->destination.bidib_state_index);
		
		g_string_append_printf(log, "Path: ");
		if (route->path != NULL) {
			for (int segment_index = 0; segment_index < route->path->len; ++segment_index) {
				t_interlocking_path_segment *segment = &g_array_index(route->path, t_interlocking_path_segment, segment_index);
				id = segment->id;
				segment->bidib_state_index = bidib_get_segment_state_index(id);

				if (segment->bidib_state_index == -1) {
					syslog_server(LOG_ERR, "Interlocking resolve indicies: %s not found in BiDiB state", id);
					return -1;
				}

				g_string_append_printf(log, "%s (%d) ", 
				                       segment->id, 
				                       segment->bidib_state_index);
			}
		}
		
		g_string_append_printf(log, "Points: ");
		if (route->points != NULL) {
			for (int point_index = 0; point_index < route->points->len; ++point_index) {
				t_interlocking_point *point = &g_array_index(route->points, t_interlocking_point, point_index);
				id = point->id;
				point->bidib_state_index = bidib_get_point_state_index(id);

				if (point->bidib_state_index == -1) {
					syslog_server(LOG_ERR, "Interlocking resolve indicies: %s not found in BiDiB state", id);
					return -1;
				}

				g_string_append_printf(log, "%s (%d) ",
				                       point->id,
				                       point->bidib_state_index);
			}
		}
		
		g_string_append_printf(log, "Signals: ");
		if (route->signals != NULL) {
			for (int signal_index = 0; signal_index < route->signals->len; ++signal_index) {
				t_interlocking_signal *signal = &g_array_index(route->signals, t_interlocking_signal, signal_index);
				id = signal->id;
				signal->bidib_state_index = bidib_get_signal_state_index(id);

				if (signal->bidib_state_index == -1) {
					syslog_server(LOG_ERR, "Interlocking resolve indicies: %s not found in BiDiB state", id);
					return -1;
				}

				g_string_append_printf(log, "%s (%d) ", 
				                       signal->id, 
				                       signal->bidib_state_index);
			}
		}
		
		g_string_append_printf(log, "Conflicts: ");
		if (route->conflicts != NULL) {
			for (int conflict_index = 0; conflict_index < route->conflicts->len; ++conflict_index) {
				size_t conflict = g_array_index(route->conflicts, size_t, conflict_index);
				g_string_append_printf(log, "%zu ", conflict);
			}
		}
		
		syslog_server(LOG_NOTICE, "%s", log->str);
		g_string_free(log, true);
	}
	
	syslog_server(LOG_NOTICE, "Interlocking resolve indicies: successful");
	return 0;
}

int interlocking_table_initialise(const char *config_dir) {
	// Parse the interlocking table from the YAML file
	interlocking_table = parse_interlocking_table(config_dir);
	
	int err_indices = interlocking_table_resolve_indices();
	int err_hashtable = create_interlocking_hashtable();
	
	return (err_indices || err_hashtable);
}

GArray *interlocking_table_get_route_ids(const char *source_id, const char *destination_id) {
    size_t len = strlen(source_id) + strlen(destination_id) + 1;
    char route_string[len];
    snprintf(route_string, len, "%s%s", source_id, destination_id);

    if (g_hash_table_contains(route_string_to_ids_hashtable, route_string)) {
        return (GArray *)g_hash_table_lookup(route_string_to_ids_hashtable, route_string);
    }

    return NULL;
}

int interlocking_table_get_route_id(const char *source_id, const char *destination_id) {
    GArray *route_ids = interlocking_table_get_route_ids(source_id, destination_id);
    // Return first route
    if (route_ids != NULL && route_ids->len > 0) {
        return g_array_index(route_ids, size_t, 0);
    }

    return -1;
}

t_interlocking_route *get_route(int route_id) {
	if (route_id < 0 || route_id >= interlocking_table->len) {
		return NULL;
	}

	return &g_array_index(interlocking_table, t_interlocking_route, route_id);
}
