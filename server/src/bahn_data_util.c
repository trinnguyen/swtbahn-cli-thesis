//
// Created by Tri Nguyen on 09/02/2020.
//

#include <bidib.h>
#include <string.h>

#include "server.h"
#include "interlocking.h"
#include "parsers/config_data_parser.h"
#include "parsers/config_data_intern.h"
#include "bahn_data_util.h"

t_config_data config_data = {};

int get_route_array_string_value(t_interlocking_route *route, const char *prop_name, char **data);

typedef enum {
    TYPE_ROUTE,
    TYPE_SEGMENT,
    TYPE_SIGNAL,
    TYPE_POINT,
    TYPE_TRAIN,
    TYPE_BLOCK,
    TYPE_CROSSING,
    TYPE_SIGNAL_TYPE,
    TYPE_NOT_SUPPORTED
} e_config_type;

bool initialise_config(const char *config_dir) {

    if (!interlocking_table_initialise(config_dir)) {
        return false;
    }

    if (!parse_config_data(config_dir, &config_data)) {
        return false;
    }

    return true;
}

void free_config() {
    free_config_data(config_data);
    free_interlocking_table();
}

bool string_equals(const char *str1, const char *str2) {
    return strcmp(str1, str2) == 0;
}

GArray *cached_allocated_str;

void init_cached_track_state() {
    cached_allocated_str = g_array_sized_new(FALSE, FALSE, sizeof(char *), 16);
}

void free_cached_track_state() {
    if (cached_allocated_str != NULL) {
        g_array_free(cached_allocated_str, true);
        cached_allocated_str = NULL;
    }
}

void add_cache_str(char *state) {
    if (cached_allocated_str != NULL) {
        g_array_append_val(cached_allocated_str, state);
    }
}

char *new_empty_str() {
    char *result = strdup("");
    g_array_append_val(cached_allocated_str, result);
    return result;
}

e_config_type get_config_type(const char *type) {
    if (string_equals(type, "route")) {
        return TYPE_ROUTE;
    }

    if (string_equals(type, "segment")) {
        return TYPE_SEGMENT;
    }

    if (string_equals(type, "signal")) {
        return TYPE_SIGNAL;
    }

    if (string_equals(type, "point")) {
        return TYPE_POINT;
    }

    if (string_equals(type, "train")) {
        return TYPE_TRAIN;
    }

    if (string_equals(type, "block")) {
        return TYPE_BLOCK;
    }

    if (string_equals(type, "crossing")) {
        return TYPE_CROSSING;
    }

    if (string_equals(type, "signaltype")) {
        return TYPE_SIGNAL_TYPE;
    }

    return TYPE_NOT_SUPPORTED;
}

void *get_object(e_config_type config_type, const char *id) {
    GHashTable *tb = NULL;
    switch (config_type) {
        case TYPE_ROUTE:
            return get_route((int)strtol(id, NULL, 10));
        case TYPE_SEGMENT:
            tb = config_data.table_segments;
            break;
        case TYPE_SIGNAL:
            tb = config_data.table_signals;
            break;
        case TYPE_POINT:
            tb = config_data.table_points;
            break;
        case TYPE_TRAIN:
            tb = config_data.table_trains;
            break;
        case TYPE_BLOCK:
            tb = config_data.table_blocks;
            break;
        case TYPE_CROSSING:
            tb = config_data.table_crossings;
            break;
        case TYPE_SIGNAL_TYPE:
            tb = config_data.table_signal_types;
            break;
        default:
            break;
    }

    // check
    if (tb != NULL) {
        if (g_hash_table_contains(tb, id)) {
            return g_hash_table_lookup(tb, id);
        }
    }

    return NULL;
}

int interlocking_table_get_routes(const char *src_signal_id, const char *dst_signal_id, char *route_ids[]) {
    GArray *arr = interlocking_table_get_route_ids(src_signal_id, dst_signal_id);
    if (arr != NULL) {
        for (int i = 0; i < arr->len; ++i) {
            route_ids[i] = g_array_index(arr, char *, i);
        }
        return arr->len;
    }

    return 0;
}

char *config_get_scalar_string_value(const char *type, const char *id, const char *prop_name) {
    e_config_type config_type = get_config_type(type);
    void *obj = get_object(config_type, id);
    char *result = NULL;
    if (obj != NULL) {
        switch (config_type) {
            case TYPE_ROUTE:
                if (string_equals(prop_name, "id")) {
                    result = ((t_interlocking_route *) obj)->id;
                    break;
                }

                if (string_equals(prop_name, "source")) {
                    result = ((t_interlocking_route *) obj)->source;
                    break;
                }

                if (string_equals(prop_name, "destination")) {
                    result = ((t_interlocking_route *) obj)->destination;
                    break;
                }

                if (string_equals(prop_name, "train")) {
                    result = ((t_interlocking_route *) obj)->train;
                    break;
                }

                break;
            case TYPE_SEGMENT:
                if (string_equals(prop_name, "id")) {
                    result = ((t_config_segment *) obj)->id;
                    break;
                }

                break;
            case TYPE_SIGNAL:
                if (string_equals(prop_name, "id")) {
                    result = ((t_config_signal *) obj)->id;
                    break;
                }

                if (string_equals(prop_name, "initial")) {
                    result = ((t_config_signal *) obj)->initial;
                    break;
                }

                if (string_equals(prop_name, "type")) {
                    result = ((t_config_signal *) obj)->type;
                    break;
                }

                break;
            case TYPE_POINT:
                if (string_equals(prop_name, "id")) {
                    result = ((t_config_point *) obj)->id;
                    break;
                }

                if (string_equals(prop_name, "initial")) {
                    result = ((t_config_point *) obj)->initial;
                    break;
                }

                if (string_equals(prop_name, "segment")) {
                    result = ((t_config_point *) obj)->segment;
                    break;
                }

                if (string_equals(prop_name, "normal")) {
                    result = ((t_config_point *) obj)->normal_aspect;
                    break;
                }

                if (string_equals(prop_name, "reverse")) {
                    result = ((t_config_point *) obj)->reverse_aspect;
                    break;
                }

                break;
            case TYPE_TRAIN:
                if (string_equals(prop_name, "id")) {
                    result = ((t_config_train *) obj)->id;
                    break;
                }

                if (string_equals(prop_name, "type")) {
                    result = ((t_config_train *) obj)->type;
                    break;
                }

                break;
            case TYPE_BLOCK:
                if (string_equals(prop_name, "id")) {
                    result = ((t_config_block *) obj)->id;
                    break;
                }

                if (string_equals(prop_name, "segment")) {
                    result = ((t_config_block *) obj)->main_segment;
                    break;
                }

                if (string_equals(prop_name, "direction")) {
                    result = ((t_config_block *) obj)->direction;
                    break;
                }

                break;
            case TYPE_CROSSING:
                if (string_equals(prop_name, "id")) {
                    result = ((t_config_crossing *) obj)->id;
                    break;
                }

                if (string_equals(prop_name, "segment")) {
                    result = ((t_config_crossing *) obj)->main_segment;
                    break;
                }

                break;
            case TYPE_SIGNAL_TYPE:
                if (string_equals(prop_name, "id")) {
                    result = ((t_config_signal_type *) obj)->id;
                    break;
                }

                break;
            default:
                break;
        }
    }

    result = result != NULL ? result : new_empty_str();
    syslog_server(LOG_DEBUG, "Get scalar string: %s %s.%s => %s", type, id, prop_name, result);
    return result;
}

int config_get_scalar_int_value(const char *type, const char *id, const char *prop_name) {
    // No object type has int property
    return 0;
}

float config_get_scalar_float_value(const char *type, const char *id, const char *prop_name) {
    e_config_type config_type = get_config_type(type);
    void *obj = get_object(config_type, id);
    float result = 0;
    if (obj != NULL) {
        switch (config_type) {
            case TYPE_ROUTE:
                if (string_equals(prop_name, "length")) {
                    result = ((t_interlocking_route *) obj)->length;
                }
                break;
            case TYPE_BLOCK:
                if (string_equals(prop_name, "length")) {
                    result = ((t_config_block *) obj)->length;
                    break;
                }

                if (string_equals(prop_name, "limit")) {
                    result = ((t_config_block *) obj)->limit_speed;
                }

                break;

            case TYPE_SEGMENT:
                if (string_equals(prop_name, "length")) {
                    result = ((t_config_segment *) obj)->length;
                }
                break;
            case TYPE_TRAIN:
                if (string_equals(prop_name, "length")) {
                    result = ((t_config_train *) obj)->length;
                    break;
                }

                if (string_equals(prop_name, "weight")) {
                    result = ((t_config_train *) obj)->weight;
                }
                break;
            default:
                break;
        }
    }

    syslog_server(LOG_DEBUG, "Get scalar float: %s %s.%s => %.2f", type, id, prop_name, result);
    return result;
}

bool config_get_scalar_bool_value(const char *type, const char *id, const char *prop_name) {
    // No object type has bool property
    return false;
}

int config_get_array_string_value(const char *type, const char *id, const char *prop_name, char* data[]) {
    e_config_type config_type = get_config_type(type);
    void *obj = get_object(config_type, id);
    int result = 0;
    if (obj != NULL) {
        GArray *arr = NULL;
        switch (config_type) {
            case TYPE_ROUTE:
                result = get_route_array_string_value((t_interlocking_route *)obj, prop_name, data);
                break;
            case TYPE_SIGNAL:
                if (string_equals(prop_name, "aspects")) {
                    arr = ((t_config_signal *) obj)->aspects;
                    break;
                }
            case TYPE_TRAIN:
                if (string_equals(prop_name, "peripherals")) {
                    arr = ((t_config_train *) obj)->peripherals;
                    break;
                }

            case TYPE_BLOCK:
                if (string_equals(prop_name, "train_types")) {
                    arr = ((t_config_block *) obj)->train_types;
                    break;
                }

                if (string_equals(prop_name, "block_signals")) {
                    arr = ((t_config_block *) obj)->signals;
                    break;
                }

                if (string_equals(prop_name, "overlaps")) {
                    arr = ((t_config_block *) obj)->overlaps;
                    break;
                }

            case TYPE_SIGNAL_TYPE:
                if (string_equals(prop_name, "aspects")) {
                    arr = ((t_config_signal_type *) obj)->aspects;
                    break;
                }
            default:
                break;
        }

        if (arr != NULL) {
            for (int i = 0; i < arr->len; ++i) {
                data[i] = g_array_index(arr, char *, i);
            }
            result = arr->len;
        }
    }

    syslog_server(LOG_DEBUG, "Get array string: %s %s.%s => %d", type, id, prop_name, result);
    return result;
}

int get_route_array_string_value(t_interlocking_route *route, const char *prop_name, char* data[]) {
    if (string_equals(prop_name, "path")) {
        if (route->path != NULL) {
            for (int i = 0; i < route->path->len; ++i) {
                data[i] = g_array_index(route->path, char *, i);
            }
            return route->path->len;
        }
    }

    if (string_equals(prop_name, "sections")) {
        if (route->sections != NULL) {
            for (int i = 0; i < route->sections->len; ++i) {
                data[i] = g_array_index(route->sections, char *, i);
            }
            return route->sections->len;
        }
    }

    if (string_equals(prop_name, "points")) {
        if (route->points != NULL) {
            for (int i = 0; i < route->points->len; ++i) {
                data[i] = (&g_array_index(route->points, t_interlocking_point, i))->id;
            }
            return route->points->len;
        }
    }

    if (string_equals(prop_name, "route_signals")) {
        if (route->signals != NULL) {
            for (int i = 0; i < route->signals->len; ++i) {
                data[i] = g_array_index(route->signals, char *, i);
            }
            return route->signals->len;
        }
    }

    if (string_equals(prop_name, "conflicts")) {
        if (route->conflicts != NULL) {
            for (int i = 0; i < route->conflicts->len; ++i) {
                data[i] = g_array_index(route->conflicts, char *, i);
            }
            return route->conflicts->len;
        }
    }

    return 0;
}

int config_get_array_int_value(const char *type, const char *id, const char *prop_name, int data[]) {
    e_config_type config_type = get_config_type(type);
    void *obj = get_object(config_type, id);
    int result = 0;
    if (obj != NULL) {
        GArray *arr = NULL;
        switch (config_type) {
            case TYPE_TRAIN:
                if (string_equals(prop_name, "calibration")) {
                    arr = ((t_config_train *) obj)->calibration;
                    break;
                }
            default:
                break;
        }

        if (arr != NULL) {
            for (int i = 0; i < arr->len; ++i) {
                data[i] = g_array_index(arr, int, i);
            }
            result = arr->len;
        }
    }

    syslog_server(LOG_DEBUG, "Get array int: %s %s.%s => %d", type, id, prop_name, result);
    return result;
}

int config_get_array_float_value(const char *type, const char *id, const char *prop_name, float data[]) {
    // No object type has float array property
    return 0;
}

int config_get_array_bool_value(const char *type, const char *id, const char *prop_name, bool data[]) {
    // No object type has bool array property
    return 0;
}

bool config_set_scalar_string_value(const char *type, const char *id, const char *prop_name, char *value) {
    e_config_type config_type = get_config_type(type);
    void *obj = get_object(config_type, id);
    bool result = false;
    if (obj != NULL && config_type == TYPE_ROUTE) {
        if (string_equals(prop_name, "train")) {
            // Set train
            t_interlocking_route *route = (t_interlocking_route *) obj;
            route->train = strdup(value);
            result = true;
        }
    }

    syslog_server(LOG_DEBUG, "Set scalar string: %s %s.%s = %s => %s", type, id, prop_name, value, result ? "true" : "false");
    return result;
}

e_config_type get_track_state_type(const char *id) {
    if (id == NULL)
        return TYPE_NOT_SUPPORTED;

    if (g_hash_table_contains(config_data.table_signals, id)) {
        return TYPE_SIGNAL;
    }

    if (g_hash_table_contains(config_data.table_points, id)) {
        return TYPE_POINT;
    }

    return TYPE_NOT_SUPPORTED;
}

char *track_state_get_value(const char *id) {
    char *result = NULL;
    e_config_type config_type = get_track_state_type(id);
    if (config_type == TYPE_POINT)
        return "normal";

    return "red";

    void *obj = get_object(config_type, id);
    if (obj != NULL) {
        t_bidib_unified_accessory_state_query state_query = {};
        switch (config_type) {
            case TYPE_POINT:
                state_query = bidib_get_point_state(id);
                break;
            case TYPE_SIGNAL:
                state_query = bidib_get_signal_state(id);
                break;
            default:
                break;
        }

        // read data
        if (state_query.known) {
            result = strdup(state_query.board_accessory_state.state_id);
        }

        // free
        bidib_free_unified_accessory_state_query(state_query);
    }

    if (result != NULL) {
        add_cache_str(result);
    } else {
        result = new_empty_str();
    }

    syslog_server(LOG_DEBUG, "Get track state: %s => %s", id, result);
    return result;
}

static bool is_track_state_aspect_valid(e_config_type config_type, const char *id, const char *value) {
    if (value == NULL)
        return false;

    char *signal_type_id = NULL;
    switch (config_type) {
        case TYPE_POINT:
            if (string_equals(value, "normal") || string_equals(value, "reverse")) {
                return true;
            }
            break;
        case TYPE_SIGNAL:
            // ensure valid aspect by checking the type of the signal
            signal_type_id = config_get_scalar_string_value("signal", id, "type");
            if (signal_type_id == NULL || string_equals(signal_type_id, "")) {
                return false;
            }

            // get signal type
            if (g_hash_table_contains(config_data.table_signal_types, signal_type_id)) {
                t_config_signal_type *signal_type = g_hash_table_lookup(config_data.table_signal_types, signal_type_id);
                if (signal_type->aspects != NULL) {
                    for (int i = 0; i < signal_type->aspects->len; ++i) {
                        char *aspect = g_array_index(signal_type->aspects, char *, i);
                        if (string_equals(value, aspect)) {
                            return true;
                        }
                    }
                }
            }

            return false;
        default:
            break;
    }

    return false;
}

bool track_state_set_value(const char *id, const char *value) {
    e_config_type config_type = get_track_state_type(id);
    if (!is_track_state_aspect_valid(config_type, id, value)) {
        syslog_server(LOG_DEBUG, "Invalid aspect: %s", value);
        return false;
    }

    return true;
    bool result = false;
    switch (config_type) {
        case TYPE_POINT:
            result = bidib_switch_point(id, value) == 0;
            syslog_server(LOG_DEBUG, "Set point state: %s to %s => %s", id, value, result ? "true" : "false");
            return result;
        case TYPE_SIGNAL:
            result = bidib_set_signal(id, value) == 0;
            syslog_server(LOG_DEBUG, "Set signal state: %s to %s => %s", id, value, result ? "true" : "false");
            return result;
        default:
            return false;
    }
}

bool is_segment_occupied(const char *id) {
    syslog_server(LOG_DEBUG, "Is segment occupied: %s => false", id);
    return false;
    bool result = false;
    if (g_hash_table_contains(config_data.table_segments, id)) {
        t_bidib_segment_state_query state_query = bidib_get_segment_state(id);
        result = state_query.known && state_query.data.occupied;
        bidib_free_segment_state_query(state_query);
    }

    syslog_server(LOG_DEBUG, "Is segment occupied: %s => %s", id, result ? "true" : "false");
    return result;
}

char *config_get_point_position(const char *route_id, const char *point_id) {
    void *obj = get_object(TYPE_ROUTE, route_id);
    char *result = NULL;

    if (obj != NULL) {
        t_interlocking_route *route = (t_interlocking_route *) obj;
        for (int i = 0; i < route->points->len; ++i) {
            t_interlocking_point *point = &g_array_index(route->points, t_interlocking_point, i);
            if (string_equals(point->id, point_id)) {
                result = point->position == NORMAL ? "normal" : "reverse";
                break;
            }
        }
    }

    result = result != NULL ? result : new_empty_str();
    syslog_server(LOG_DEBUG, "Get route point position: %s.%s => %s", route_id, point_id, result);
    return result;
}