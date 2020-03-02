//
// Created by Tri Nguyen on 22/02/2020.
//

#include "config_data_parser.h"
#include "parser_util.h"
#include "track_config_parser.h"
#include "train_config_parser.h"
#include "extras_config_parser.h"

const char TRACK_CONFIG_FILENAME[] = "bidib_track_config.yml";
const char TRAIN_CONFIG_FILENAME[] = "bidib_train_config.yml";
const char EXTRAS_CONFIG_FILENAME[] = "extras_config.yml";

bool parse_config(const char *config_dir, const char *filename, t_config_data *data, void (*parse_yaml)(yaml_parser_t *, t_config_data *)) {
    // init
    FILE *fh;
    yaml_parser_t parser;
    if (!init_config_parser(config_dir, filename, &fh, &parser)) {
        return false;
    }

    // parse
    parse_yaml(&parser, data);

    // destroy
    destroy_parser(fh, &parser);
    return true;
}

bool parse_config_data(const char *config_dir, t_config_data *config_data) {

    if (!parse_config(config_dir, TRACK_CONFIG_FILENAME, config_data, parse_track_yaml)) {
        syslog_server(LOG_ERR, "Failed to parse %s", TRACK_CONFIG_FILENAME);
        return false;
    }

    if (!parse_config(config_dir, TRAIN_CONFIG_FILENAME, config_data, parse_train_yaml)) {
        syslog_server(LOG_ERR, "Failed to parse %s", TRAIN_CONFIG_FILENAME);
        return false;
    }

    if (!parse_config(config_dir, EXTRAS_CONFIG_FILENAME, config_data, parse_extras_yaml)) {
        syslog_server(LOG_ERR, "Failed to parse %s", EXTRAS_CONFIG_FILENAME);
        return false;
    }

    return true;
}

void free_config_data(t_config_data config_data) {
    if (config_data.table_segments != NULL) {
        g_hash_table_destroy(config_data.table_segments);
        config_data.table_segments = NULL;
    }

    if (config_data.table_signals != NULL) {
        g_hash_table_destroy(config_data.table_signals);
        config_data.table_signals = NULL;
    }

    if (config_data.table_points != NULL) {
        g_hash_table_destroy(config_data.table_points);
        config_data.table_points = NULL;
    }

    if (config_data.table_trains != NULL) {
        g_hash_table_destroy(config_data.table_trains);
        config_data.table_trains = NULL;
    }

    if (config_data.table_blocks != NULL) {
        g_hash_table_destroy(config_data.table_blocks);
        config_data.table_blocks = NULL;
    }

    if (config_data.table_crossings != NULL) {
        g_hash_table_destroy(config_data.table_crossings);
        config_data.table_crossings = NULL;
    }
}