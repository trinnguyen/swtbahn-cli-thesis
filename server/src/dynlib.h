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

#ifndef DYNLIB_H
#define DYNLIB_H

#include <stdbool.h>
#include <limits.h>

#include "tick_data.h"

typedef enum {
	DYNLIB_COMPILE_SUCCESS,
	DYNLIB_LOAD_SUCCESS,

	// Could not compile library into object file
			DYNLIB_COMPILE_OBJ_ERR,

	// Could not compile library into shared library
			DYNLIB_COMPILE_SHARED_ERR,

	// Could not load the dynamic library
			DYNLIB_LOAD_ERR,

	// Could not find address of reset(...)
			DYNLIB_LOAD_RESET_ERR,

	// Could not find address of tick(...)
			DYNLIB_LOAD_TICK_ERR
} dynlib_status;

typedef struct {
	char name[NAME_MAX];

	// File path of library source code, without the file extension
	char filepath[PATH_MAX + NAME_MAX];

	// Handle to the dynamic library
	void *lib_handle;

	// Library interface functions
	void (*reset_func)(TickData *);
	void (*tick_func)(TickData *);
} dynlib_data;

typedef struct {
    // Handle to the dynamic library
    void *lib_handle;

    // Library interface functions
    void (*request_reset_func)(request_route_tick_data *);
    void (*request_tick_func)(request_route_tick_data *);
    void (*drive_reset_func)(drive_route_tick_data *);
    void (*drive_tick_func)(drive_route_tick_data *);
} interlocking_dynlib_data;

dynlib_status dynlib_compile_scchart(dynlib_data *library, const char filepath[]);
dynlib_status dynlib_compile_c(dynlib_data *library, const char filepath[]);

dynlib_status dynlib_load(dynlib_data *library, const char filepath[]);
bool dynlib_is_loaded(dynlib_data *library);
void dynlib_set_name(dynlib_data *library, const char name[]);
void dynlib_close(dynlib_data *library);
void dynlib_reset(dynlib_data *library, TickData *tick_data);
void dynlib_tick(dynlib_data *library, TickData *TickData);

dynlib_status dynlib_load_interlocking(interlocking_dynlib_data *library, const char filepath[]);
void dynlib_close_interlocking(interlocking_dynlib_data *library);

#endif	// DYNLIB_H