//
// Created by Tri Nguyen on 22/02/2020.
//

#ifndef CONFIG_DATA_PARSER_H
#define CONFIG_DATA_PARSER_H

#include <stdbool.h>
#include "config_data_intern.h"

bool parse_config_data(const char *config_dir, t_config_data *config_data);

void free_config_data(t_config_data config_data);

#endif //CONFIG_DATA_PARSER_H