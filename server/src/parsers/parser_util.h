//
// Created by Tri Nguyen on 22/02/2020.
//

#ifndef PARSER_UTIL_H
#define PARSER_UTIL_H

#include <syslog.h>
#include <stdbool.h>
#include <yaml.h>
#include <stdio.h>
#include "../server.h"

void log_debug(const char *format, ...);

bool init_config_parser(const char *config_dir, const char *table_file, FILE **fh, yaml_parser_t *parser);

void destroy_parser(FILE *fh, yaml_parser_t *parser);

void parse_yaml_content(yaml_parser_t *parser,
                        void(*sequence_start_handler)(char*),
                        void(*sequence_end_handler)(char*),
                        void(*mapping_start_handler)(char*),
                        void(*mapping_end_handler)(char*),
                        void(*scalar_handler)(char*, char*));

bool str_equal(const char *str1, const char *str2);

float parse_float(const char *str);
#endif //PARSER_UTIL_H