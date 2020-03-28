//
// Created by Tri Nguyen on 22/02/2020.
//

#ifndef CONFIG_DATA_INTERN_H
#define CONFIG_DATA_INTERN_H

#include <glib.h>

typedef struct {
    GHashTable *table_segments;
    GHashTable *table_signals;
    GHashTable *table_points;
    GHashTable *table_trains;
    GHashTable *table_blocks; // store: blocks and platforms
    GHashTable *table_crossings;
} t_config_data;

typedef struct {
    char *id;
    float length;
} t_config_segment;

typedef struct {
    char *id;
    char *initial;
    GArray *aspects;
    char *type;
} t_config_signal;

typedef struct {
    char *id;
    char *initial;
    char *segment;
    char *normal_aspect;
    char *reverse_aspect;
} t_config_point;

typedef struct {
    char *id;
    float length;
    float weight;
    char *type;
    GArray *peripherals;
    GArray *calibration;
} t_config_train;

typedef struct {
    char *id;
    float length;
    GArray *train_types;
    GArray *signals;
    char *main_segment;
    GArray *overlaps;
    char *direction;
} t_config_block;

typedef struct {
    char *id;
    char *main_segment;
} t_config_crossing;


#endif //CONFIG_DATA_INTERN_H