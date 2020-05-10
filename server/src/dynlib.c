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

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

#include "dynlib.h"
#include "server.h"

const char dynlib_symbol_reset[] = "reset";
const char dynlib_symbol_tick[] = "tick";


// TODO: Compiles C code from a given SCCharts model
dynlib_status dynlib_compile_scchart(dynlib_data *library, const char filepath[]) {
    strncpy(library->filepath, filepath, PATH_MAX + NAME_MAX);

    return DYNLIB_COMPILE_SUCCESS;
}

// FIXME: UNTESTED: Compiles a dynamic library from a given C file
dynlib_status dynlib_compile_c(dynlib_data *library, const char filepath[]) {
    strncpy(library->filepath, filepath, PATH_MAX + NAME_MAX);

    char command[MAX_INPUT + 2 * (PATH_MAX + NAME_MAX)];
    sprintf(command, "gcc -c -fpic %s.c", library->filepath);
    if (system(command) == -1) {
        return DYNLIB_COMPILE_OBJ_ERR;
    }

    sprintf(command, "gcc -shared -fpic -o %s.so %s.c", library->filepath, library->filepath);
    if (system(command) == -1) {
        return DYNLIB_COMPILE_SHARED_ERR;
    }

    return DYNLIB_COMPILE_SUCCESS;
}

// Loads a dynamic library from a given filepath
dynlib_status dynlib_load(dynlib_data *library, const char filepath[]) {
    // Make sure no library has been loaded
    dynlib_close(library);

    // Clear the last error that occured in the dynamic linking loader
    // THREAD SAFETY: This probably needs to be in a semaphore
    dlerror();

    // Try and load the dynamic library with *.so extension
    sprintf(library->filepath, "%s.so", filepath);
    library->lib_handle = dlopen(library->filepath, RTLD_LAZY);
    if (library->lib_handle == NULL) {
        // Try and load the dynamic library  with *.dylib extension
        sprintf(library->filepath, "%s.dylib", filepath);
        library->lib_handle = dlopen(library->filepath, RTLD_LAZY);

        if (library->lib_handle == NULL) {
            syslog_server(LOG_ERR, "Could not load dynamic library %s.\n%s", library->filepath, dlerror());
            return DYNLIB_LOAD_ERR;
        }
    }

    // Try and locate the functions of the library interface

    /* Since the value of a symbol in the dynamic library could
     * actually be NULL (so that a NULL return from dlsym() need not
     * indicate an error), the correct way to test for an error is
     * to call dlerror() to clear any old error conditions, then
     * call dlsym(), and then call dlerror() again, saving its return
     * value into a variable, and check whether this saved value is not NULL.
     */
    dlerror();

    *(void **) (&library->reset_func) = dlsym(library->lib_handle, dynlib_symbol_reset);
    char *error;
    if ((error = dlerror()) != NULL) {
        syslog_server(LOG_ERR, "Could not find address of symbol %s.\n%s", dynlib_symbol_reset, error);
        return DYNLIB_LOAD_RESET_ERR;
    }

    dlerror();
    *(void **) (&library->tick_func) = dlsym(library->lib_handle, dynlib_symbol_tick);
    if ((error = dlerror()) != NULL) {
        syslog_server(LOG_ERR, "Could not find address of symbol %s.\n%s", dynlib_symbol_tick, error);
        return DYNLIB_LOAD_TICK_ERR;
    }

    return DYNLIB_LOAD_SUCCESS;
}

bool dynlib_is_loaded(dynlib_data *library) {
    return (library->lib_handle != NULL);
}

void dynlib_set_name(dynlib_data *library, const char name[]) {
    strncpy(library->name, name, NAME_MAX);
}

void dynlib_close(dynlib_data *library) {
    if (dynlib_is_loaded(library)) {
        dlclose(library->lib_handle);
        library->lib_handle = NULL;
        library->name[0] = '\0';
    }
}

void dynlib_reset(dynlib_data *library, TickData *tick_data) {
    if (dynlib_is_loaded(library)) {
        (*library->reset_func)(tick_data);
    }
}

void dynlib_tick(dynlib_data *library, TickData *tick_data) {
    if (dynlib_is_loaded(library)) {
        (*library->tick_func)(tick_data);
    }
}

dynlib_status dynlib_load_interlocking(interlocking_dynlib_data *library, const char filepath[]) {
    char path[PATH_MAX + NAME_MAX];
    sprintf(path, "%s.so", filepath);

    // open on linux
    library->lib_handle = dlopen(path, RTLD_LAZY);
    if (library->lib_handle == NULL) {
        // open on macOS
        sprintf(path, "%s.dylib", filepath);
        library->lib_handle = dlopen(path, RTLD_LAZY);
    }

    if (library->lib_handle == NULL) {
        syslog_server(LOG_ERR, "Could not load dynamic library %s.\n%s", filepath, dlerror());
        return DYNLIB_LOAD_ERR;
    }

    // load symbols
    *(void **) (&library->request_reset_func) = dlsym(library->lib_handle, "request_route_reset");
    *(void **) (&library->request_tick_func) = dlsym(library->lib_handle, "request_route_tick");
    *(void **) (&library->drive_reset_func) = dlsym(library->lib_handle, "drive_route_reset");
    *(void **) (&library->drive_tick_func) = dlsym(library->lib_handle, "drive_route_tick");

    // check
    if (library->request_reset_func == NULL
        || library->request_tick_func == NULL
        || library->drive_reset_func == NULL
        || library->drive_tick_func == NULL) {
        syslog_server(LOG_ERR, "Could not find interlocking symbols.\n%s", dlerror());
        return DYNLIB_LOAD_ERR;
    }

    return DYNLIB_LOAD_SUCCESS;
}

void dynlib_close_interlocking(interlocking_dynlib_data *library) {
    if (library->lib_handle != NULL) {
        dlclose(library->lib_handle);
        library->lib_handle = NULL;
        library->request_reset_func = NULL;
        library->request_tick_func = NULL;
        library->drive_reset_func = NULL;
        library->drive_tick_func = NULL;
    }
}
