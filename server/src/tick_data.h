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
 * - Tri Nguyen <https://github.com/trinnguyen>
 *
 */

#ifndef TICK_DATA_H
#define TICK_DATA_H

typedef struct {
  int requested_speed;
  char requested_forwards;
  int nominal_speed;
  char nominal_forwards;
  
  char internal_variables[1024];
} TickData;

typedef struct {
    char* src_signal_id;                                                    // Input
    char* dst_signal_id;                                                    // Input
    char* train_id;                                                         // Input
    char* out;                                                              // Output

    int terminated;
} request_route_tick_data;

typedef struct {
    char* route_id;                                                    // Input
    char* train_id;                                                    // Input
    char* segment_ids[1024];                                           // Input
    int count_segments;                                                // Input

    int terminated;
} drive_route_tick_data;

#endif // TICK_DATA_H
