//
// Created by Tri Nguyen on 23/02/2020.
//

#include "extras_config_parser.h"
#include "parser_util.h"

typedef enum {
    EXTRAS_ROOT,
    BLOCK,
    CROSSING,
    SIGNAL_TYPE
} e_extras_mapping_level;

typedef enum {
    EXTRAS_SEQ_NONE,
    BLOCKS,
    BLOCK_SIGNALS,
    BLOCK_OVERLAPS,
    BLOCK_TRAIN_TYPES,
    CROSSINGS,
    SIGNAL_TYPES,
    SIGNAL_TYPE_ASPECTS
} e_extras_sequence_level;

GHashTable *tb_blocks;
GHashTable *tb_crossing;
GHashTable *tb_signal_types;
t_config_block *cur_block;
t_config_crossing *cur_crossing;
t_config_signal_type *cur_signal_type;

e_extras_mapping_level extras_mapping = EXTRAS_ROOT;
e_extras_sequence_level extras_sequence = EXTRAS_SEQ_NONE;

void free_extras_id_key(void *pointer) {
    log_debug("free key: %s", (char *) pointer);
    free(pointer);
}

void free_block(void *pointer) {
    t_config_block *block = (t_config_block *) pointer;
    log_debug("free block: %s", block->id);

    if (block->overlaps != NULL) {
        log_debug("free block overlaps");
        for (int i = 0; i < block->overlaps->len; ++i) {
            log_debug("\t\t%s", g_array_index(block->overlaps, char *, i));
        }
        g_array_free(block->overlaps, true);
    }

    if (block->signals != NULL) {
        log_debug("free block signals");
        for (int i = 0; i < block->signals->len; ++i) {
            log_debug("\t\t%s", g_array_index(block->signals, char *, i));
        }
        g_array_free(block->signals, true);
    }

    if (block->train_types != NULL) {
        log_debug("free block train types");
        for (int i = 0; i < block->train_types->len; ++i) {
            log_debug("\t\t%s", g_array_index(block->train_types, char *, i));
        }
        g_array_free(block->train_types, true);
    }

    free(block);
}

void free_crossing(void *pointer) {
    t_config_crossing *crossing = (t_config_crossing *) pointer;
    log_debug("free crossing: %s", crossing->id);
    free(crossing);
}

void free_signal_type(void *pointer) {
    t_config_signal_type *signal_type = (t_config_signal_type *) pointer;
    log_debug("free signal type: %s", signal_type->id);
    free(signal_type);
}

void extras_yaml_sequence_start(char *scalar) {
    log_debug("extras_yaml_sequence_start: %s", scalar);
    switch (extras_mapping) {
        case EXTRAS_ROOT:
            if (str_equal(scalar, "blocks") || str_equal(scalar, "platforms")) {
                extras_sequence = BLOCKS;
                if (tb_blocks == NULL)
                    tb_blocks = g_hash_table_new_full(g_str_hash, g_str_equal, free_extras_id_key, free_block);
                return;
            }

            if (str_equal(scalar, "crossings")) {
                extras_sequence = CROSSINGS;
                tb_crossing = g_hash_table_new_full(g_str_hash, g_str_equal, free_extras_id_key, free_crossing);
                return;
            }

            if (str_equal(scalar, "signaltypes")) {
                extras_sequence = SIGNAL_TYPES;
                tb_signal_types = g_hash_table_new_full(g_str_hash, g_str_equal, free_extras_id_key, free_signal_type);
                return;
            }
            break;
        case BLOCK:
            if (str_equal(scalar, "overlaps")) {
                extras_sequence = BLOCK_OVERLAPS;
                cur_block->overlaps = g_array_sized_new(false, false, sizeof(char *), 2);
                return;
            }

            if (str_equal(scalar, "signals")) {
                extras_sequence = BLOCK_SIGNALS;
                cur_block->signals = g_array_sized_new(false, false, sizeof(char *), 2);
                return;
            }

            if (str_equal(scalar, "trains")) {
                extras_sequence = BLOCK_TRAIN_TYPES;
                cur_block->train_types = g_array_sized_new(false, false, sizeof(char *), 8);
                return;
            }
            break;
        case SIGNAL_TYPE:
            if (str_equal(scalar, "aspects")) {
                extras_sequence = SIGNAL_TYPE_ASPECTS;
                cur_signal_type->aspects = g_array_sized_new(false, false, sizeof(char *), 3);
                return;
            }
            break;
        default:
            break;
    }
}

void extras_yaml_sequence_end(char *scalar) {
    log_debug("extras_yaml_sequence_end: %s", scalar);
    // decrease sequence level
    switch (extras_sequence) {
        case BLOCKS:
        case CROSSINGS:
        case SIGNAL_TYPES:
            extras_sequence = EXTRAS_SEQ_NONE;
            break;
        case BLOCK_OVERLAPS:
        case BLOCK_SIGNALS:
        case BLOCK_TRAIN_TYPES:
            extras_sequence = BLOCKS;
            break;
        case SIGNAL_TYPE_ASPECTS:
            extras_sequence = SIGNAL_TYPES;
            break;
        default:
            break;
    }
}

void extras_yaml_mapping_start(char *scalar) {
    log_debug("extras_yaml_mapping_start: %s", scalar);
    switch (extras_sequence) {
        case BLOCKS:
            extras_mapping = BLOCK;
            cur_block = malloc(sizeof(t_config_block));
            cur_block->id = NULL;
            cur_block->train_types = NULL;
            cur_block->signals = NULL;
            cur_block->main_segment = NULL;
            cur_block->overlaps = NULL;
            cur_block->direction = NULL;
            break;
        case CROSSINGS:
            extras_mapping = CROSSING;
            cur_crossing = malloc(sizeof(t_config_crossing));
            cur_crossing->id = NULL;
            cur_crossing->main_segment = NULL;
            break;
        case SIGNAL_TYPES:
            extras_mapping = SIGNAL_TYPE;
            cur_signal_type = malloc(sizeof(t_config_signal_type));
            cur_signal_type->id = NULL;
            cur_signal_type->aspects = NULL;
            break;
        default:
            break;
    }
}

void extras_yaml_mapping_end(char *scalar) {
    log_debug("extras_yaml_mapping_end: %s", scalar);

    // insert mapping to hash table
    switch (extras_mapping) {
        case BLOCK:
            log_debug("insert block: %s", cur_block->id);
            g_hash_table_insert(tb_blocks, strdup(cur_block->id), cur_block);
            break;
        case CROSSING:
            log_debug("insert crossing: %s", cur_crossing->id);
            g_hash_table_insert(tb_crossing, strdup(cur_crossing->id), cur_crossing);
            break;
        case SIGNAL_TYPE:
            log_debug("insert signal type: %s", cur_signal_type->id);
            g_hash_table_insert(tb_signal_types, strdup(cur_signal_type->id), cur_signal_type);
            break;
        default:
            break;
    }

    // decrease mapping level
    switch (extras_mapping) {
        case BLOCK:
        case CROSSING:
        case SIGNAL_TYPE:
            extras_mapping = EXTRAS_ROOT;
            break;
        default:
            break;
    }
}

void extras_yaml_scalar(char *last_scalar, char *cur_scalar) {
    if (extras_sequence == BLOCK_OVERLAPS) {
        g_array_append_val(cur_block->overlaps, cur_scalar);
        return;
    }

    if (extras_sequence == BLOCK_SIGNALS) {
        g_array_append_val(cur_block->signals, cur_scalar);
        return;
    }

    if (extras_sequence == BLOCK_TRAIN_TYPES) {
        g_array_append_val(cur_block->train_types, cur_scalar);
        return;
    }

    if (extras_sequence == SIGNAL_TYPE_ASPECTS) {
        log_debug("insert aspect to signal type: %s, %s", cur_signal_type->id, cur_scalar);
        g_array_append_val(cur_signal_type->aspects, cur_scalar);
        return;
    }

    switch (extras_mapping) {
        case BLOCK:
            if (str_equal(last_scalar, "id")) {
                cur_block->id = cur_scalar;
                return;
            }

            if (str_equal(last_scalar, "length")) {
                cur_block->length = strtof(cur_scalar, NULL);
                break;
            }

            if (str_equal(last_scalar, "limit")) {
                cur_block->limit_speed = strtol(cur_scalar, NULL, 10);
                break;
            }

            if (str_equal(last_scalar, "main")) {
                cur_block->main_segment = cur_scalar;
                return;
            }

            if (str_equal(last_scalar, "direction")) {
                cur_block->direction = cur_scalar;
                return;
            }
            break;
        case CROSSING:
            if (str_equal(last_scalar, "id")) {
                cur_crossing->id = cur_scalar;
                return;
            }

            if (str_equal(last_scalar, "segment")) {
                cur_crossing->main_segment = cur_scalar;
                return;
            }
            break;
        case SIGNAL_TYPE:
            if (str_equal(last_scalar, "id")) {
                cur_signal_type->id = cur_scalar;
                return;
            }
            break;
        default:
            break;
    }
}

void parse_extras_yaml(yaml_parser_t *parser, t_config_data *data) {
    parse_yaml_content(parser, extras_yaml_sequence_start, extras_yaml_sequence_end, extras_yaml_mapping_start, extras_yaml_mapping_end, extras_yaml_scalar);
    data->table_blocks = tb_blocks;
    data->table_crossings = tb_crossing;
    data->table_signal_types = tb_signal_types;
}