//
// Created by Tri Nguyen on 23/02/2020.
//

#ifndef SCCHARTS_GEN_TRAIN_CONFIG_PARSER_H
#define SCCHARTS_GEN_TRAIN_CONFIG_PARSER_H

#include <yaml.h>
#include "config_data_intern.h"

void parse_train_yaml(yaml_parser_t *parser, t_config_data *data);

#endif //SCCHARTS_GEN_TRAIN_CONFIG_PARSER_H