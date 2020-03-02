//
// Created by Tri Nguyen on 09/02/2020.
//

#include "bahn_data_util.h"
#include "string.h"
#include "../parsers/config_data_parser.h"
#include "../interlocking.h"
#include <bidib.h>
#include "../server.h"

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
    TYPE_NOT_SUPPORTED
} e_config_type;

bool initialise_config(const char *config_dir) {
    if (parse_config_data(config_dir, &config_data)) {
        return true;
    }

    return false;
}

void free_config() {
    free_config_data(config_data);
}

bool equal(const char *str1, const char *str2) {
    return strcmp(str1, str2) == 0;
}

e_config_type get_config_type(const char *type) {
    if (equal(type, "route")) {
        return TYPE_ROUTE;
    }

    if (equal(type, "segment")) {
        return TYPE_SEGMENT;
    }

    if (equal(type, "signal")) {
        return TYPE_SIGNAL;
    }

    if (equal(type, "point")) {
        return TYPE_POINT;
    }

    if (equal(type, "train")) {
        return TYPE_TRAIN;
    }

    if (equal(type, "block")) {
        return TYPE_BLOCK;
    }

    if (equal(type, "crossing")) {
        return TYPE_CROSSING;
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
                if (equal(prop_name, "source")) {
                    result = ((t_interlocking_route *) obj)->source.id;
                    break;
                }

                if (equal(prop_name, "destination")) {
                    result = ((t_interlocking_route *) obj)->destination.id;
                    break;
                }

                if (equal(prop_name, "train")) {
                    GString *train_id = ((t_interlocking_route *) obj)->train_id;
                    if (train_id != NULL) {
                        result = train_id->str;
                    }
                    break;
                }

            case TYPE_SEGMENT:
                if (equal(prop_name, "id")) {
                    result = ((t_config_segment *) obj)->id;
                    break;
                }

            case TYPE_SIGNAL:
                if (equal(prop_name, "id")) {
                    result = ((t_config_signal *) obj)->id;
                    break;
                }

                if (equal(prop_name, "initial")) {
                    result = ((t_config_signal *) obj)->initial;
                    break;
                }

            case TYPE_POINT:
                if (equal(prop_name, "id")) {
                    result = ((t_config_point *) obj)->id;
                    break;
                }

                if (equal(prop_name, "initial")) {
                    result = ((t_config_point *) obj)->initial;
                    break;
                }

                if (equal(prop_name, "segment")) {
                    result = ((t_config_point *) obj)->segment;
                    break;
                }

                if (equal(prop_name, "normal")) {
                    result = ((t_config_point *) obj)->normal_aspect;
                    break;
                }

                if (equal(prop_name, "reverse")) {
                    result = ((t_config_point *) obj)->reverse_aspect;
                    break;
                }

            case TYPE_TRAIN:
                if (equal(prop_name, "id")) {
                    result = ((t_config_train *) obj)->id;
                    break;
                }

                if (equal(prop_name, "type")) {
                    result = ((t_config_train *) obj)->type;
                    break;
                }

            case TYPE_BLOCK:
                if (equal(prop_name, "id")) {
                    result = ((t_config_block *) obj)->id;
                    break;
                }

                if (equal(prop_name, "main")) {
                    result = ((t_config_block *) obj)->main_segment;
                    break;
                }

                if (equal(prop_name, "direction")) {
                    result = ((t_config_block *) obj)->direction;
                    break;
                }

            case TYPE_CROSSING:
                if (equal(prop_name, "id")) {
                    result = ((t_config_crossing *) obj)->id;
                    break;
                }

                if (equal(prop_name, "segment")) {
                    result = ((t_config_crossing *) obj)->main_segment;
                    break;
                }

            default:
                break;
        }
    }

    result = result != NULL ? result : "";
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
                if (equal(prop_name, "length")) {
                    result = ((t_interlocking_route *) obj)->length;
                }
                break;
            case TYPE_BLOCK:
                if (equal(prop_name, "length")) {
                    result = ((t_config_block *) obj)->length;
                }
                break;
            case TYPE_SEGMENT:
                if (equal(prop_name, "length")) {
                    result = ((t_config_segment *) obj)->length;
                }
                break;
            case TYPE_TRAIN:
                if (equal(prop_name, "length")) {
                    result = ((t_config_train *) obj)->length;
                    break;
                }

                if (equal(prop_name, "weight")) {
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
                if (equal(prop_name, "aspects")) {
                    arr = ((t_config_signal *) obj)->aspects;
                    break;
                }
            case TYPE_TRAIN:
                if (equal(prop_name, "peripherals")) {
                    arr = ((t_config_train *) obj)->peripherals;
                    break;
                }

                if (equal(prop_name, "calibration")) {
                    arr = ((t_config_train *) obj)->calibration;
                    break;
                }

            case TYPE_BLOCK:
                if (equal(prop_name, "trains")) {
                    arr = ((t_config_block *) obj)->train_types;
                    break;
                }

                if (equal(prop_name, "signals")) {
                    arr = ((t_config_block *) obj)->signals;
                    break;
                }

                if (equal(prop_name, "overlaps")) {
                    arr = ((t_config_block *) obj)->overlaps;
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
    if (equal(prop_name, "path")) {
        if (route->path != NULL) {
            for (int i = 0; i < route->path->len; ++i) {
                data[i] = (&g_array_index(route->path, t_interlocking_path_segment, i))->id;
            }
            return route->path->len;
        }
    }

    if (equal(prop_name, "points")) {
        if (route->points != NULL) {
            for (int i = 0; i < route->points->len; ++i) {
                data[i] = (&g_array_index(route->points, t_interlocking_point, i))->id;
            }
            return route->points->len;
        }
    }

    if (equal(prop_name, "signals")) {
        if (route->signals != NULL) {
            for (int i = 0; i < route->signals->len; ++i) {
                data[i] = (&g_array_index(route->signals, t_interlocking_signal, i))->id;
            }
            return route->signals->len;
        }
    }

    if (equal(prop_name, "conflicts")) {
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
                if (equal(prop_name, "calibration")) {
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
        if (equal(prop_name, "train")) {
            // Set train
            t_interlocking_route *route = (t_interlocking_route *) obj;
            route->train_id = g_string_new(value);
            result = true;
        }
    }

    syslog_server(LOG_DEBUG, "Set scalar string: %s %s.%s = %s => %s", type, id, prop_name, value, result ? "true" : "false");
    return result;
}

char *track_state_get_value(const char *type, const char *id) {
    e_config_type config_type = get_config_type(type);
    void *obj = get_object(config_type, id);
    char *state = NULL;
    if (obj != NULL) {
        t_bidib_track_state track_state = bidib_get_state();
        int index = -1;
        switch (config_type) {
            case TYPE_POINT:
                index = bidib_get_point_state_index(id);
                if (index >= 0 && index < track_state.points_board_count) {
                    state = track_state.points_board[index].data.state_id;
                }
                break;
            case TYPE_SIGNAL:
                index = bidib_get_signal_state_index(id);
                if (index >= 0 && index < track_state.signals_board_count) {
                    state = track_state.signals_board[index].data.state_id;
                }
                break;
            default:
                break;
        }

        bidib_free_track_state(track_state);
    }

    state = state != NULL ? state : "";
    syslog_server(LOG_DEBUG, "Get track state: %s %s => %s", type, id, state);
    return state;
}

bool track_state_set_value(const char *type, const char *id, const char *value) {
    bool result = false;
    switch (get_config_type(type)) {
        case TYPE_POINT:
            result = bidib_switch_point(id, value) == 0;
            break;
        case TYPE_SIGNAL:
            result = bidib_set_signal(id, value) == 0;
            break;
        default:
            break;
    }

    syslog_server(LOG_DEBUG, "Set track state: %s %s => %s", type, id, result ? "true" : "false");
    return result;
}

bool is_segment_occupied(const char *id) {
    int index = bidib_get_segment_state_index(id);
    bool result = false;
    if (index >= 0) {
        t_bidib_track_state track_state = bidib_get_state();
        result = track_state.segments[index].data.occupied;
        bidib_free_track_state(track_state);
    }

    syslog_server(LOG_DEBUG, "Is segment occupied: %s => %s", id, result ? "true" : "false");
    return result;
}

char *config_get_point_position(const char *route_id, const char *point_id) {
    void * obj = get_object(TYPE_ROUTE, route_id);
    char *result = NULL;

    if (obj != NULL) {
        t_interlocking_route *route = (t_interlocking_route *) obj;
        for (int i = 0; i < route->points->len; ++i) {
            t_interlocking_point *point = &g_array_index(route->points, t_interlocking_point, i);
            if (equal(point->id, point_id)) {
                result = point->position == NORMAL ? "normal" : "reverse";
                break;
            }
        }
    }

    result = result != NULL ? result : "";
    syslog_server(LOG_DEBUG, "Get route point position: %s.%s => %s", route_id, point_id, result);
    return result;
}