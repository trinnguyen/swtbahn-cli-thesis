/*==============================================================
| Hardware architecture specific declarations:
| Cores, mutex and input/output information.
*=============================================================*/
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>

typedef struct {
	long long previous;
	long long current;
	long long elapsed;
} ClockTimeUs;
ClockTimeUs clockTimeUs;

// Returns the current time in microseconds
long long getClockTimeUs(void) {
	struct timespec ts;

	if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0) {
		return (long long) (ts.tv_sec * 1000000 + ts.tv_nsec / 1000);
	} else {
		return 0;
	}
}

// Mapping Pthreads to processor cores
pthread_t cores[3];
pthread_attr_t masterCoreAttribute;
pthread_attr_t slaveCoreAttribute;

// ForeC mutexes

/*==============================================================
| ForeC type definitions:
| Defines the types of storage elements specific to ForeC.
*=============================================================*/
// Status values.
typedef enum {
	// PAR
	FOREC_PAR_OFF,				// 0
	FOREC_PAR_ON,				// 1

	// Core
	FOREC_CORE_REACTING,		// 2
	FOREC_CORE_REACTED,			// 3
	FOREC_CORE_TERMINATED,		// 4
	
	// Shared variables
	FOREC_SHARED_UNMODIFIED,	// 5
	FOREC_SHARED_MODIFIED,		// 6
	FOREC_SHARED_WAS_MODIFIED	// 7
} Status;

// Store child thread information.
typedef struct _Thread {
	void *programCounter;
	struct _Thread *nextThread;
	struct _Thread *prevThread;
} Thread;

// Store parent thread information
typedef struct {
	void *programCounter;
	volatile int parStatus;
	pthread_cond_t parStatusCond;
	pthread_mutex_t parStatusLock;
	volatile int parId;
} Parent;

// Keep track of child threads executing on
// a processor core.
typedef struct {
	volatile int sync;
	volatile int activeThreads;
	volatile int status;
	pthread_cond_t statusCond;
	pthread_mutex_t statusLock;
	volatile int reactionCounter;
	pthread_cond_t reactionCounterCond;
	pthread_mutex_t reactionCounterLock;
} Core;

// Structure to pass input arguments into forecMain.
typedef struct {
	int coreId;
	int argc;
	char **argv;
} Arguments;

// Shared control variables for non-immediate aborts -----------
volatile int init__abortStrongNonImmediate0 = 0;

// Shared control variables for par(...)s ----------------------
// Thread main with par(...)s
Parent mainParParent = { .parStatusCond = PTHREAD_COND_INITIALIZER, .parStatusLock = PTHREAD_MUTEX_INITIALIZER };
Core mainParCore0 = { .statusCond = PTHREAD_COND_INITIALIZER, .statusLock = PTHREAD_MUTEX_INITIALIZER, .reactionCounterCond = PTHREAD_COND_INITIALIZER, .reactionCounterLock = PTHREAD_MUTEX_INITIALIZER};
Core mainParCore1 = { .statusCond = PTHREAD_COND_INITIALIZER, .statusLock = PTHREAD_MUTEX_INITIALIZER, .reactionCounterCond = PTHREAD_COND_INITIALIZER, .reactionCounterLock = PTHREAD_MUTEX_INITIALIZER};
Core mainParCore2 = { .statusCond = PTHREAD_COND_INITIALIZER, .statusLock = PTHREAD_MUTEX_INITIALIZER, .reactionCounterCond = PTHREAD_COND_INITIALIZER, .reactionCounterLock = PTHREAD_MUTEX_INITIALIZER};
volatile int mainParReactionCounter;
pthread_cond_t mainParReactionCounterCond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mainParReactionCounterLock = PTHREAD_MUTEX_INITIALIZER;


/*==============================================================
| Original global declarations:
| Global declarations in the original program code.
*=============================================================*/
// Original main function
void *forecMain(void *args);

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <libgen.h>
#include "dynlib.h"
#include "tick_data.h"
#include "server.h"
#include "dyn_containers_interface.h"

typedef void t_dyn_containers_interface__global_0_0;

#define t_dyn_containers_interface__global_0_0 t_dyn_containers_interface

typedef void t_dyn_shm_config__global_0_0;

#define t_dyn_shm_config__global_0_0 t_dyn_shm_config
#define dyn_containers_mutex__global_0_0 dyn_containers_mutex

typedef void pthread_mutex_t__global_0_0;

#define pthread_mutex_t__global_0_0 pthread_mutex_t

typedef void key_t__global_0_0;

#define key_t__global_0_0 key_t

int NULL__global_0_0;

#define NULL__global_0_0 NULL

typedef int bool__global_0_0;

#define bool__global_0_0 bool

typedef struct {
	/* shared */ int value;
	int status;
} Shared_LOG_NOTICE__global_0_0;
Shared_LOG_NOTICE__global_0_0 LOG_NOTICE__global_0_0 = {.value = 5, .status = FOREC_SHARED_UNMODIFIED};

int LOG_ERR__global_0_0;

#define LOG_ERR__global_0_0 LOG_ERR

int PATH_MAX__global_0_0;

#define PATH_MAX__global_0_0 PATH_MAX

int NAME_MAX__global_0_0;

#define NAME_MAX__global_0_0 NAME_MAX

typedef void dynlib_status__global_0_0;

#define dynlib_status__global_0_0 dynlib_status

typedef void dynlib_data__global_0_0;

#define dynlib_data__global_0_0 dynlib_data

int DYNLIB_COMPILE_SUCCESS__global_0_0;

#define DYNLIB_COMPILE_SUCCESS__global_0_0 DYNLIB_COMPILE_SUCCESS

int DYNLIB_LOAD_SUCCESS__global_0_0;

#define DYNLIB_LOAD_SUCCESS__global_0_0 DYNLIB_LOAD_SUCCESS

int DYNLIB_COMPILE_OBJ_ERR__global_0_0;

#define DYNLIB_COMPILE_OBJ_ERR__global_0_0 DYNLIB_COMPILE_OBJ_ERR

int DYNLIB_COMPILE_SHARED_ERR__global_0_0;

#define DYNLIB_COMPILE_SHARED_ERR__global_0_0 DYNLIB_COMPILE_SHARED_ERR

int DYNLIB_LOAD_ERR__global_0_0;

#define DYNLIB_LOAD_ERR__global_0_0 DYNLIB_LOAD_ERR

int DYNLIB_LOAD_RESET_ERR__global_0_0;

#define DYNLIB_LOAD_RESET_ERR__global_0_0 DYNLIB_LOAD_RESET_ERR

int DYNLIB_LOAD_TICK_ERR__global_0_0;

#define DYNLIB_LOAD_TICK_ERR__global_0_0 DYNLIB_LOAD_TICK_ERR

typedef void TickData__global_0_0;

#define TickData__global_0_0 TickData

/* shared */ static const unsigned int TRAIN_ENGINE_COUNT_MAX__global_0_0 = 4;

static const unsigned int INTERLOCKER_COUNT_MAX__global_0_0 = 4;

typedef struct {
	/* shared */ dynlib_data__global_0_0 value[TRAIN_ENGINE_COUNT_MAX__global_0_0];
	int status;
} Shared_trainEngines__global_0_0;
Shared_trainEngines__global_0_0 trainEngines__global_0_0;

dynlib_data__global_0_0 interlockers__global_0_0[INTERLOCKER_COUNT_MAX__global_0_0];
static const unsigned int TRAIN_ENGINE_DEFINED_COUNT__global_0_0 = 2;
const char *trainEngineFilepaths__global_0_0[TRAIN_ENGINE_DEFINED_COUNT__global_0_0] = {"../src/engines/libtrain_engine_default", "../src/engines/libtrain_engine_linear"};
static const unsigned int TRAIN_ENGINE_INSTANCE_COUNT_MAX__global_0_0 = 5;
static const unsigned int INTERLOCKER_INSTANCE_COUNT_MAX__global_0_0 = 4;
TickData__global_0_0 trainEngineInstanceDataIntern__global_0_0[TRAIN_ENGINE_INSTANCE_COUNT_MAX__global_0_0];
TickData__global_0_0 interlockerInstanceDataIntern__global_0_0[INTERLOCKER_INSTANCE_COUNT_MAX__global_0_0];

typedef struct {
	/* shared */ TickData__global_0_0 *value;
	int status;
} Shared_trainEngineInstanceData__global_0_0;
Shared_trainEngineInstanceData__global_0_0 trainEngineInstanceData__global_0_0 = {.value = trainEngineInstanceDataIntern__global_0_0, .status = FOREC_SHARED_UNMODIFIED} /* combine with keepOneCombine */;
typedef struct {
	/* shared */ TickData__global_0_0 *value;
	int status;
} Shared_interlockerInstanceData__global_0_0;
Shared_interlockerInstanceData__global_0_0 interlockerInstanceData__global_0_0 = {.value = interlockerInstanceDataIntern__global_0_0, .status = FOREC_SHARED_UNMODIFIED} /* combine with keepOneCombine */;

typedef struct {
	volatile bool__global_0_0 terminate;
	int let_period_us;
} t_forec_intern_input__global_0_0;

typedef struct {
	/* shared */ t_forec_intern_input__global_0_0 value;
	int status;
} Shared_forec_intern_input__global_0_0;
Shared_forec_intern_input__global_0_0 forec_intern_input__global_0_0 = {.value = {.terminate = false, .let_period_us = 0}, .status = FOREC_SHARED_UNMODIFIED};

typedef struct {
	bool__global_0_0 load;
	bool__global_0_0 unload;
	char filepath[PATH_MAX + NAME_MAX];
} t_forec_intern_input_train_engine__global_0_0;

typedef struct {
	/* shared */ t_forec_intern_input_train_engine__global_0_0 value;
	int status;
} Shared_forec_intern_input_train_engine_0__global_0_0;
Shared_forec_intern_input_train_engine_0__global_0_0 forec_intern_input_train_engine_0__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_input_train_engine__global_0_0 value;
	int status;
} Shared_forec_intern_input_train_engine_1__global_0_0;
Shared_forec_intern_input_train_engine_1__global_0_0 forec_intern_input_train_engine_1__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_input_train_engine__global_0_0 value;
	int status;
} Shared_forec_intern_input_train_engine_2__global_0_0;
Shared_forec_intern_input_train_engine_2__global_0_0 forec_intern_input_train_engine_2__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_input_train_engine__global_0_0 value;
	int status;
} Shared_forec_intern_input_train_engine_3__global_0_0;
Shared_forec_intern_input_train_engine_3__global_0_0 forec_intern_input_train_engine_3__global_0_0;

typedef struct {
	bool__global_0_0 in_use;
	char *name;
} t_forec_intern_output_train_engine__global_0_0;

typedef struct {
	/* shared */ t_forec_intern_output_train_engine__global_0_0 value;
	int status;
} Shared_forec_intern_output_train_engine_0__global_0_0;
Shared_forec_intern_output_train_engine_0__global_0_0 forec_intern_output_train_engine_0__global_0_0 = {.value = {.name = ""}, .status = FOREC_SHARED_UNMODIFIED};
typedef struct {
	/* shared */ t_forec_intern_output_train_engine__global_0_0 value;
	int status;
} Shared_forec_intern_output_train_engine_1__global_0_0;
Shared_forec_intern_output_train_engine_1__global_0_0 forec_intern_output_train_engine_1__global_0_0 = {.value = {.name = ""}, .status = FOREC_SHARED_UNMODIFIED};
typedef struct {
	/* shared */ t_forec_intern_output_train_engine__global_0_0 value;
	int status;
} Shared_forec_intern_output_train_engine_2__global_0_0;
Shared_forec_intern_output_train_engine_2__global_0_0 forec_intern_output_train_engine_2__global_0_0 = {.value = {.name = ""}, .status = FOREC_SHARED_UNMODIFIED};
typedef struct {
	/* shared */ t_forec_intern_output_train_engine__global_0_0 value;
	int status;
} Shared_forec_intern_output_train_engine_3__global_0_0;
Shared_forec_intern_output_train_engine_3__global_0_0 forec_intern_output_train_engine_3__global_0_0 = {.value = {.name = ""}, .status = FOREC_SHARED_UNMODIFIED};

typedef struct {
	bool__global_0_0 grab;
	bool__global_0_0 release;
	int train_engine_type;
	int requested_speed;
	char requested_forwards;
} t_forec_intern_input_train_engine_instance__global_0_0;

typedef struct {
	/* shared */ t_forec_intern_input_train_engine_instance__global_0_0 value;
	int status;
} Shared_forec_intern_input_train_engine_instance_0__global_0_0;
Shared_forec_intern_input_train_engine_instance_0__global_0_0 forec_intern_input_train_engine_instance_0__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_input_train_engine_instance__global_0_0 value;
	int status;
} Shared_forec_intern_input_train_engine_instance_1__global_0_0;
Shared_forec_intern_input_train_engine_instance_1__global_0_0 forec_intern_input_train_engine_instance_1__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_input_train_engine_instance__global_0_0 value;
	int status;
} Shared_forec_intern_input_train_engine_instance_2__global_0_0;
Shared_forec_intern_input_train_engine_instance_2__global_0_0 forec_intern_input_train_engine_instance_2__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_input_train_engine_instance__global_0_0 value;
	int status;
} Shared_forec_intern_input_train_engine_instance_3__global_0_0;
Shared_forec_intern_input_train_engine_instance_3__global_0_0 forec_intern_input_train_engine_instance_3__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_input_train_engine_instance__global_0_0 value;
	int status;
} Shared_forec_intern_input_train_engine_instance_4__global_0_0;
Shared_forec_intern_input_train_engine_instance_4__global_0_0 forec_intern_input_train_engine_instance_4__global_0_0;

typedef struct {
	bool__global_0_0 in_use;
	int nominal_speed;
	char nominal_forwards;
} t_forec_intern_output_train_engine_instance__global_0_0;

typedef struct {
	/* shared */ t_forec_intern_output_train_engine_instance__global_0_0 value;
	int status;
} Shared_forec_intern_output_train_engine_instance_0__global_0_0;
Shared_forec_intern_output_train_engine_instance_0__global_0_0 forec_intern_output_train_engine_instance_0__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_output_train_engine_instance__global_0_0 value;
	int status;
} Shared_forec_intern_output_train_engine_instance_1__global_0_0;
Shared_forec_intern_output_train_engine_instance_1__global_0_0 forec_intern_output_train_engine_instance_1__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_output_train_engine_instance__global_0_0 value;
	int status;
} Shared_forec_intern_output_train_engine_instance_2__global_0_0;
Shared_forec_intern_output_train_engine_instance_2__global_0_0 forec_intern_output_train_engine_instance_2__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_output_train_engine_instance__global_0_0 value;
	int status;
} Shared_forec_intern_output_train_engine_instance_3__global_0_0;
Shared_forec_intern_output_train_engine_instance_3__global_0_0 forec_intern_output_train_engine_instance_3__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_output_train_engine_instance__global_0_0 value;
	int status;
} Shared_forec_intern_output_train_engine_instance_4__global_0_0;
Shared_forec_intern_output_train_engine_instance_4__global_0_0 forec_intern_output_train_engine_instance_4__global_0_0;

typedef struct {
	bool__global_0_0 load;
} t_forec_intern_input_interlocker__global_0_0;

typedef struct {
	/* shared */ t_forec_intern_input_interlocker__global_0_0 value;
	int status;
} Shared_forec_intern_input_interlocker_0__global_0_0;
Shared_forec_intern_input_interlocker_0__global_0_0 forec_intern_input_interlocker_0__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_input_interlocker__global_0_0 value;
	int status;
} Shared_forec_intern_input_interlocker_1__global_0_0;
Shared_forec_intern_input_interlocker_1__global_0_0 forec_intern_input_interlocker_1__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_input_interlocker__global_0_0 value;
	int status;
} Shared_forec_intern_input_interlocker_2__global_0_0;
Shared_forec_intern_input_interlocker_2__global_0_0 forec_intern_input_interlocker_2__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_input_interlocker__global_0_0 value;
	int status;
} Shared_forec_intern_input_interlocker_3__global_0_0;
Shared_forec_intern_input_interlocker_3__global_0_0 forec_intern_input_interlocker_3__global_0_0;

typedef struct {
	bool__global_0_0 in_use;
} t_forec_intern_output_interlocker__global_0_0;

typedef struct {
	/* shared */ t_forec_intern_output_interlocker__global_0_0 value;
	int status;
} Shared_forec_intern_output_interlocker_0__global_0_0;
Shared_forec_intern_output_interlocker_0__global_0_0 forec_intern_output_interlocker_0__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_output_interlocker__global_0_0 value;
	int status;
} Shared_forec_intern_output_interlocker_1__global_0_0;
Shared_forec_intern_output_interlocker_1__global_0_0 forec_intern_output_interlocker_1__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_output_interlocker__global_0_0 value;
	int status;
} Shared_forec_intern_output_interlocker_2__global_0_0;
Shared_forec_intern_output_interlocker_2__global_0_0 forec_intern_output_interlocker_2__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_output_interlocker__global_0_0 value;
	int status;
} Shared_forec_intern_output_interlocker_3__global_0_0;
Shared_forec_intern_output_interlocker_3__global_0_0 forec_intern_output_interlocker_3__global_0_0;

typedef struct {
	bool__global_0_0 grab;
} t_forec_intern_input_interlocker_instance__global_0_0;

typedef struct {
	/* shared */ t_forec_intern_input_interlocker_instance__global_0_0 value;
	int status;
} Shared_forec_intern_input_interlocker_instance_0__global_0_0;
Shared_forec_intern_input_interlocker_instance_0__global_0_0 forec_intern_input_interlocker_instance_0__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_input_interlocker_instance__global_0_0 value;
	int status;
} Shared_forec_intern_input_interlocker_instance_1__global_0_0;
Shared_forec_intern_input_interlocker_instance_1__global_0_0 forec_intern_input_interlocker_instance_1__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_input_interlocker_instance__global_0_0 value;
	int status;
} Shared_forec_intern_input_interlocker_instance_2__global_0_0;
Shared_forec_intern_input_interlocker_instance_2__global_0_0 forec_intern_input_interlocker_instance_2__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_input_interlocker_instance__global_0_0 value;
	int status;
} Shared_forec_intern_input_interlocker_instance_3__global_0_0;
Shared_forec_intern_input_interlocker_instance_3__global_0_0 forec_intern_input_interlocker_instance_3__global_0_0;

typedef struct {
	bool__global_0_0 in_use;
} t_forec_intern_output_interlocker_instance__global_0_0;

typedef struct {
	/* shared */ t_forec_intern_output_interlocker_instance__global_0_0 value;
	int status;
} Shared_forec_intern_output_interlocker_instance_0__global_0_0;
Shared_forec_intern_output_interlocker_instance_0__global_0_0 forec_intern_output_interlocker_instance_0__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_output_interlocker_instance__global_0_0 value;
	int status;
} Shared_forec_intern_output_interlocker_instance_1__global_0_0;
Shared_forec_intern_output_interlocker_instance_1__global_0_0 forec_intern_output_interlocker_instance_1__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_output_interlocker_instance__global_0_0 value;
	int status;
} Shared_forec_intern_output_interlocker_instance_2__global_0_0;
Shared_forec_intern_output_interlocker_instance_2__global_0_0 forec_intern_output_interlocker_instance_2__global_0_0;
typedef struct {
	/* shared */ t_forec_intern_output_interlocker_instance__global_0_0 value;
	int status;
} Shared_forec_intern_output_interlocker_instance_3__global_0_0;
Shared_forec_intern_output_interlocker_instance_3__global_0_0 forec_intern_output_interlocker_instance_3__global_0_0;
typedef struct {
	/* shared */ t_dyn_containers_interface__global_0_0 *value;
	int status;
} Shared_dyn_containers_interface__global_0_0;
Shared_dyn_containers_interface__global_0_0 dyn_containers_interface__global_0_0;

static t_dyn_shm_config__global_0_0 shm_config__global_0_0;
static const int shm_permissions__global_0_0 = 0666;
static const key_t__global_0_0 shm_key__global_0_0 = 1234;
extern pthread_mutex_t__global_0_0 dyn_containers_mutex__global_0_0;

void copyFilename(char destination[], const char source[], const int name_len, const int path_len);
void copyEngineInputs(t_forec_intern_input_train_engine__global_0_0 *internal, struct t_train_engine_io *external);
void copyEngineOutputs(struct t_train_engine_io *external, t_forec_intern_output_train_engine__global_0_0 *internal);
void copyEngineInstanceInputs(t_forec_intern_input_train_engine_instance__global_0_0 *internal, struct t_train_engine_instance_io *external);
void copyEngineInstanceOutputs(struct t_train_engine_instance_io *external, t_forec_intern_output_train_engine_instance__global_0_0 *internal);
void unloadEngines(void);
void unloadInterlockers(void);
void printout(const char *threadName, const dynlib_status__global_0_0 status, const dynlib_data__global_0_0 *library);
TickData__global_0_0 *keepOneCombine(TickData__global_0_0 *left[], TickData__global_0_0 *right[]);

// thread letInterface__thread(void);
// thread loadEngines__thread(void);
// thread loadInterlockers__thread(void);
// thread engineInstance0__thread(void);
// thread engineInstance1__thread(void);
// thread engineInstance2__thread(void);
// thread engineInstance3__thread(void);
// thread engineInstance4__thread(void);
// thread interlockerInstance0__thread(void);
// thread interlockerInstance1__thread(void);
// thread interlockerInstance2__thread(void);
// thread interlockerInstance3__thread(void);

// Locally declared shared variables -------------------------------

// Global versions of local copies of shared variables -------------
// engineInstance0
Shared_forec_intern_output_train_engine_instance_0__global_0_0 forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0 = {.status = FOREC_SHARED_UNMODIFIED};
Shared_LOG_NOTICE__global_0_0 LOG_NOTICE__global_0_0_copy_engineInstance0 = {.status = FOREC_SHARED_UNMODIFIED};
Shared_trainEngineInstanceData__global_0_0 trainEngineInstanceData__global_0_0_copy_engineInstance0 = {.status = FOREC_SHARED_UNMODIFIED};
// engineInstance1
Shared_forec_intern_output_train_engine_instance_1__global_0_0 forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1 = {.status = FOREC_SHARED_UNMODIFIED};
Shared_LOG_NOTICE__global_0_0 LOG_NOTICE__global_0_0_copy_engineInstance1 = {.status = FOREC_SHARED_UNMODIFIED};
Shared_trainEngineInstanceData__global_0_0 trainEngineInstanceData__global_0_0_copy_engineInstance1 = {.status = FOREC_SHARED_UNMODIFIED};
// engineInstance2
Shared_forec_intern_output_train_engine_instance_2__global_0_0 forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2 = {.status = FOREC_SHARED_UNMODIFIED};
Shared_LOG_NOTICE__global_0_0 LOG_NOTICE__global_0_0_copy_engineInstance2 = {.status = FOREC_SHARED_UNMODIFIED};
Shared_trainEngineInstanceData__global_0_0 trainEngineInstanceData__global_0_0_copy_engineInstance2 = {.status = FOREC_SHARED_UNMODIFIED};
// engineInstance3
Shared_forec_intern_output_train_engine_instance_3__global_0_0 forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3 = {.status = FOREC_SHARED_UNMODIFIED};
Shared_LOG_NOTICE__global_0_0 LOG_NOTICE__global_0_0_copy_engineInstance3 = {.status = FOREC_SHARED_UNMODIFIED};
Shared_trainEngineInstanceData__global_0_0 trainEngineInstanceData__global_0_0_copy_engineInstance3 = {.status = FOREC_SHARED_UNMODIFIED};
// engineInstance4
Shared_forec_intern_output_train_engine_instance_4__global_0_0 forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4 = {.status = FOREC_SHARED_UNMODIFIED};
Shared_LOG_NOTICE__global_0_0 LOG_NOTICE__global_0_0_copy_engineInstance4 = {.status = FOREC_SHARED_UNMODIFIED};
Shared_trainEngineInstanceData__global_0_0 trainEngineInstanceData__global_0_0_copy_engineInstance4 = {.status = FOREC_SHARED_UNMODIFIED};
// interlockerInstance0
// interlockerInstance1
// interlockerInstance2
// interlockerInstance3
// letInterface
Shared_forec_intern_input__global_0_0 forec_intern_input__global_0_0_copy_letInterface = {.status = FOREC_SHARED_UNMODIFIED};
Shared_forec_intern_output_train_engine_0__global_0_0 forec_intern_output_train_engine_0__global_0_0_copy_letInterface = {.status = FOREC_SHARED_UNMODIFIED};
Shared_forec_intern_output_train_engine_1__global_0_0 forec_intern_output_train_engine_1__global_0_0_copy_letInterface = {.status = FOREC_SHARED_UNMODIFIED};
Shared_forec_intern_output_train_engine_2__global_0_0 forec_intern_output_train_engine_2__global_0_0_copy_letInterface = {.status = FOREC_SHARED_UNMODIFIED};
Shared_forec_intern_output_train_engine_3__global_0_0 forec_intern_output_train_engine_3__global_0_0_copy_letInterface = {.status = FOREC_SHARED_UNMODIFIED};
Shared_forec_intern_output_train_engine_instance_0__global_0_0 forec_intern_output_train_engine_instance_0__global_0_0_copy_letInterface = {.status = FOREC_SHARED_UNMODIFIED};
Shared_forec_intern_output_train_engine_instance_1__global_0_0 forec_intern_output_train_engine_instance_1__global_0_0_copy_letInterface = {.status = FOREC_SHARED_UNMODIFIED};
Shared_forec_intern_output_train_engine_instance_2__global_0_0 forec_intern_output_train_engine_instance_2__global_0_0_copy_letInterface = {.status = FOREC_SHARED_UNMODIFIED};
Shared_forec_intern_output_train_engine_instance_3__global_0_0 forec_intern_output_train_engine_instance_3__global_0_0_copy_letInterface = {.status = FOREC_SHARED_UNMODIFIED};
Shared_forec_intern_output_train_engine_instance_4__global_0_0 forec_intern_output_train_engine_instance_4__global_0_0_copy_letInterface = {.status = FOREC_SHARED_UNMODIFIED};
Shared_dyn_containers_interface__global_0_0 dyn_containers_interface__global_0_0_copy_letInterface = {.status = FOREC_SHARED_UNMODIFIED};
// loadEngines
Shared_forec_intern_output_train_engine_0__global_0_0 forec_intern_output_train_engine_0__global_0_0_copy_loadEngines = {.status = FOREC_SHARED_UNMODIFIED};
Shared_forec_intern_output_train_engine_1__global_0_0 forec_intern_output_train_engine_1__global_0_0_copy_loadEngines = {.status = FOREC_SHARED_UNMODIFIED};
Shared_forec_intern_output_train_engine_2__global_0_0 forec_intern_output_train_engine_2__global_0_0_copy_loadEngines = {.status = FOREC_SHARED_UNMODIFIED};
Shared_forec_intern_output_train_engine_3__global_0_0 forec_intern_output_train_engine_3__global_0_0_copy_loadEngines = {.status = FOREC_SHARED_UNMODIFIED};
// loadInterlockers
// main

// forec:scheduler:boot:start
void *forec_dyn_containers(void *_) {

/*==============================================================
| Multicore startup:
| Platform dependent code.  Core identifies itself and
| executes its corresponding start up code.
*=============================================================*/
	int argc__main_0_0 = 0;
	char ** argv__main_0_0 = NULL;

	// Initialise ForeC specific values ---------------------------
	// Thread main with par(...)s
	mainParParent.parStatus = FOREC_PAR_OFF;
	mainParCore0.sync = 1;
	mainParCore0.status = FOREC_CORE_REACTING;
	mainParCore1.sync = 1;
	mainParCore1.status = FOREC_CORE_REACTING;
	mainParCore2.sync = 1;
	mainParCore2.status = FOREC_CORE_REACTING;
	mainParReactionCounter = 0;


	// Reset ForeC mutex values

	// Start core execution
	pthread_attr_init(&masterCoreAttribute);
	pthread_attr_init(&slaveCoreAttribute);
	pthread_attr_setdetachstate(&masterCoreAttribute, PTHREAD_CREATE_JOINABLE);
	pthread_attr_setdetachstate(&slaveCoreAttribute, PTHREAD_CREATE_JOINABLE);
		
	// Master core
	Arguments arguments0 = {.coreId = 0, .argc = argc__main_0_0, .argv = argv__main_0_0};
	pthread_create(&cores[0], &masterCoreAttribute, forecMain, (void *)&arguments0);

	// Slave cores
	Arguments arguments1 = {.coreId = 1, .argc = argc__main_0_0, .argv = argv__main_0_0};
	pthread_create(&cores[1], &slaveCoreAttribute, forecMain, (void *)&arguments1);
	Arguments arguments2 = {.coreId = 2, .argc = argc__main_0_0, .argv = argv__main_0_0};
	pthread_create(&cores[2], &slaveCoreAttribute, forecMain, (void *)&arguments2);

	// End core execution
	pthread_attr_destroy(&masterCoreAttribute);
	pthread_attr_destroy(&slaveCoreAttribute);
	
	// Program termination
	pthread_join(cores[0], NULL);
	pthread_cancel(cores[1]);
	pthread_cond_broadcast(&mainParParent.parStatusCond);
	pthread_join(cores[1], NULL);
	pthread_cancel(cores[2]);
	pthread_cond_broadcast(&mainParParent.parStatusCond);
	pthread_join(cores[2], NULL);

	pthread_exit(NULL);
}


/*==============================================================
| Original main(...) function:
*=============================================================*/
void *forecMain(void *args) {
	Arguments *arguments = (Arguments *)args;
	int coreId = arguments->coreId;
	int argc__main_0_0 __attribute__((unused)) = arguments->argc;
	char **argv__main_0_0 __attribute__((unused)) = arguments->argv;

	// Variables for par()s ----------------------------------------
	// par0
	Thread engineInstance0__thread;
	Thread engineInstance1__thread;
	Thread engineInstance2__thread;
	Thread engineInstance3__thread;
	Thread engineInstance4__thread;
	Thread interlockerInstance0__thread;
	Thread interlockerInstance1__thread;
	Thread interlockerInstance2__thread;
	Thread interlockerInstance3__thread;
	Thread letInterface__thread;
	Thread loadEngines__thread;
	Thread loadInterlockers__thread;
	Thread mainReactionStartMaster0;
	Thread mainReactionStartSlave1;
	Thread mainReactionStartSlave2;
	Thread mainReactionEndMaster0;
	Thread mainReactionEndSlave1;
	Thread mainReactionEndSlave2;
	Thread abortStrongNonImmediate0Check0;
	Thread abortStrongNonImmediate0Check1;
	Thread abortStrongNonImmediate0Check2;


	// Let cores jump to their code segment ------------------------
	switch (coreId) {
		case (0):
			goto mainParCore0;

		case (1):
			goto mainParCore1;

		case (2):
			goto mainParCore2;

		default:
			// Terminate unused cores.
			pthread_exit(NULL);
	}
// forec:scheduler:boot:end

/*==============================================================
| Core specific instructions:
| Contains par, abort and synchronisation handlers.
*=============================================================*/
	/*--------------------------------------------------------------
	| Master core: core0
	| ForeC program's main() function:
	| Original main() function code with ForeC constructs
	| translated into C code.
	*-------------------------------------------------------------*/
	
	// Thread local declarations -----------------------------------
	// No declarations.
mainParCore0: {
	// forec:scheduler:counter:start
	// Initialise and start timing each reaction.
	clockTimeUs.previous = getClockTimeUs();
	// forec:scheduler:counter:end
	
	//--------------------------------------------------------------

	syslog_server(LOG_NOTICE__global_0_0.value, "ForeC: Starting dynamic library containers");
	dyn_containers_shm_create(&shm_config__global_0_0, shm_permissions__global_0_0, shm_key__global_0_0, &dyn_containers_interface__global_0_0.value);

	/* abortStrongNonImmediate0 */ {
		init__abortStrongNonImmediate0 = 0;
		// forec:statement:abort:abortStrongNonImmediate0:start
		if (forec_intern_input__global_0_0.value.terminate && init__abortStrongNonImmediate0 == 1) {
			goto abortEnd_abortStrongNonImmediate0;
		}
		init__abortStrongNonImmediate0 = 1;
		// forec:statement:abort:abortStrongNonImmediate0:end

		// par0(letInterface__thread, loadEngines__thread, loadInterlockers__thread, engineInstance0__thread, engineInstance1__thread, engineInstance2__thread, engineInstance3__thread, engineInstance4__thread, interlockerInstance0__thread, interlockerInstance1__thread, interlockerInstance2__thread, interlockerInstance3__thread);
		// forec:statement:par:par0:start
		// Set the par(...) information.
		mainParParent.parId = 0;
		pthread_mutex_lock(&mainParParent.parStatusLock);
		mainParParent.parStatus = FOREC_PAR_ON;
		pthread_cond_broadcast(&mainParParent.parStatusCond);
		pthread_mutex_unlock(&mainParParent.parStatusLock);

		// Link the threads and handlers together.
		mainReactionStartMaster0.programCounter = &&mainReactionStartMaster0;
		abortStrongNonImmediate0Check0.programCounter = &&abortStrongNonImmediate0Check0;
		mainReactionStartMaster0.nextThread = &abortStrongNonImmediate0Check0;
		abortStrongNonImmediate0Check0.prevThread = &mainReactionStartMaster0;
		letInterface__thread.programCounter = &&letInterface__thread;
		abortStrongNonImmediate0Check0.nextThread = &letInterface__thread;
		letInterface__thread.prevThread = &abortStrongNonImmediate0Check0;
		mainReactionEndMaster0.programCounter = &&mainReactionEndMaster0;
		letInterface__thread.nextThread = &mainReactionEndMaster0;
		mainReactionEndMaster0.prevThread = &letInterface__thread;

		// Link the last and first threads/handlers together.
		mainReactionEndMaster0.nextThread = &mainReactionStartMaster0;
		mainReactionStartMaster0.prevThread = &mainReactionEndMaster0;

		// Set the join address.
		mainParParent.programCounter = &&par0JoinAddress_mainParCore0;

		// Set the core information.
		mainParCore0.activeThreads = 1;
		mainParCore0.reactionCounter = mainParReactionCounter;

		// Go to the first thread.
		goto letInterface__thread;
		par0JoinAddress_mainParCore0:;
		// forec:statement:par:par0:end
		abortEnd_abortStrongNonImmediate0:;
	} // when (forec_intern_input__global_0_0.value.terminate && init__abortStrongNonImmediate0 == 1);
	// forec:statement:abort:abortStrongNonImmediate0:scope:end

	unloadEngines();
	syslog_server(LOG_NOTICE__global_0_0.value, "ForeC: Unloaded train engines and instances");
	unloadInterlockers();
	syslog_server(LOG_NOTICE__global_0_0.value, "ForeC: Unloaded interlockers and instances");
	dyn_containers_shm_detach(&dyn_containers_interface__global_0_0.value);
	syslog_server(LOG_NOTICE__global_0_0.value, "ForeC: Detached shared memory");

	//--------------------------------------------------------------

	// forec:scheduler:threadRemove:main:start

	// forec:scheduler:counter:start
	clockTimeUs.current = getClockTimeUs();
	clockTimeUs.elapsed = clockTimeUs.current - clockTimeUs.previous;
	if (clockTimeUs.elapsed < 0) {
		usleep(0 - clockTimeUs.elapsed);
	}
	clockTimeUs.previous = getClockTimeUs();
	// forec:scheduler:counter:end
	
	pthread_exit(NULL);
	// forec:scheduler:threadRemove:main:end
} // mainParCore0
	// forec:thread:main:end

// forec:scheduler:parHandler:main:master:0:start
mainParHandlerMaster0: {
	if (mainParParent.parId == -2) {
		// Iteration
		// Wait for other cores to complete their reaction.
		pthread_mutex_lock(&mainParCore1.statusLock);
		while(mainParCore1.status == FOREC_CORE_REACTING) { pthread_testcancel(); pthread_cond_wait(&mainParCore1.statusCond, &mainParCore1.statusLock); }
		pthread_mutex_unlock(&mainParCore1.statusLock);
		pthread_mutex_lock(&mainParCore2.statusLock);
		while(mainParCore2.status == FOREC_CORE_REACTING) { pthread_testcancel(); pthread_cond_wait(&mainParCore2.statusCond, &mainParCore2.statusLock); }
		pthread_mutex_unlock(&mainParCore2.statusLock);

		pthread_mutex_lock(&mainParParent.parStatusLock);
		mainParParent.parStatus = FOREC_PAR_OFF;
		pthread_cond_broadcast(&mainParParent.parStatusCond);
		pthread_mutex_unlock(&mainParParent.parStatusLock);
		mainParParent.parId = -1;

		// Set slave cores' status to reacting.
		mainParCore1.status = FOREC_CORE_REACTING;
		mainParCore2.status = FOREC_CORE_REACTING;

		// Increment the reaction counter for synchronisation.
		pthread_mutex_lock(&mainParReactionCounterLock);
		mainParReactionCounter++;
		pthread_cond_broadcast(&mainParReactionCounterCond);
		pthread_mutex_unlock(&mainParReactionCounterLock);

		// Return to thread main.
		goto *mainParParent.programCounter;
	}

	// Control should not reach here.
	goto mainParHandlerMaster0;
}
// forec:scheduler:parHandler:main:master:0:end


	// Nested par(...) handlers ------------------------------------


	// Reaction start handlers ---------------------------------------
	// forec:scheduler:reactionStart:main:master:0:start
	//-- main:
mainReactionStartMaster0: {
	// Go to the next thread.
	goto *mainReactionStartMaster0.nextThread -> programCounter;
}
	// forec:scheduler:reactionStart:main:master:0:end
 


	// Reaction end handlers ---------------------------------------
	// forec:scheduler:reactionEnd:main:master:0:start
	//-- main:
mainReactionEndMaster0: {
	// Determine if the core can still react or not.
	pthread_mutex_lock(&mainParCore0.statusLock);
	if (mainParCore0.activeThreads) {
		mainParCore0.status = FOREC_CORE_REACTED;
	} else {
		mainParCore0.status = FOREC_CORE_TERMINATED;
	}
	pthread_cond_signal(&mainParCore0.statusCond);
	pthread_mutex_unlock(&mainParCore0.statusLock);
	
	// Wait for other cores to complete their reaction.
	pthread_mutex_lock(&mainParCore1.statusLock);
	while(mainParCore1.status == FOREC_CORE_REACTING) { pthread_testcancel(); pthread_cond_wait(&mainParCore1.statusCond, &mainParCore1.statusLock); }
	pthread_mutex_unlock(&mainParCore1.statusLock);
	pthread_mutex_lock(&mainParCore2.statusLock);
	while(mainParCore2.status == FOREC_CORE_REACTING) { pthread_testcancel(); pthread_cond_wait(&mainParCore2.statusCond, &mainParCore2.statusLock); }
	pthread_mutex_unlock(&mainParCore2.statusLock);

	// Reset the mutex.

	// Combine shared variables.
	int parId = mainParParent.parId;
	if (parId == 0) {
		int index;
		int numberOfModifiedCopies;

		// forec_intern_input__global_0_0
		if (forec_intern_input__global_0_0_copy_letInterface.status == FOREC_SHARED_MODIFIED) {
			forec_intern_input__global_0_0_copy_letInterface.status = FOREC_SHARED_UNMODIFIED;
			forec_intern_input__global_0_0.value = forec_intern_input__global_0_0_copy_letInterface.value;
		}

		// forec_intern_output_train_engine_0__global_0_0
		if (forec_intern_output_train_engine_0__global_0_0_copy_loadEngines.status == FOREC_SHARED_MODIFIED) {
			forec_intern_output_train_engine_0__global_0_0_copy_loadEngines.status = FOREC_SHARED_UNMODIFIED;
			forec_intern_output_train_engine_0__global_0_0.value = forec_intern_output_train_engine_0__global_0_0_copy_loadEngines.value;
		}

		// forec_intern_output_train_engine_1__global_0_0
		if (forec_intern_output_train_engine_1__global_0_0_copy_loadEngines.status == FOREC_SHARED_MODIFIED) {
			forec_intern_output_train_engine_1__global_0_0_copy_loadEngines.status = FOREC_SHARED_UNMODIFIED;
			forec_intern_output_train_engine_1__global_0_0.value = forec_intern_output_train_engine_1__global_0_0_copy_loadEngines.value;
		}

		// forec_intern_output_train_engine_2__global_0_0
		if (forec_intern_output_train_engine_2__global_0_0_copy_loadEngines.status == FOREC_SHARED_MODIFIED) {
			forec_intern_output_train_engine_2__global_0_0_copy_loadEngines.status = FOREC_SHARED_UNMODIFIED;
			forec_intern_output_train_engine_2__global_0_0.value = forec_intern_output_train_engine_2__global_0_0_copy_loadEngines.value;
		}

		// forec_intern_output_train_engine_3__global_0_0
		if (forec_intern_output_train_engine_3__global_0_0_copy_loadEngines.status == FOREC_SHARED_MODIFIED) {
			forec_intern_output_train_engine_3__global_0_0_copy_loadEngines.status = FOREC_SHARED_UNMODIFIED;
			forec_intern_output_train_engine_3__global_0_0.value = forec_intern_output_train_engine_3__global_0_0_copy_loadEngines.value;
		}

		// forec_intern_output_train_engine_instance_0__global_0_0
		if (forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0.status == FOREC_SHARED_MODIFIED) {
			forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0.status = FOREC_SHARED_UNMODIFIED;
			forec_intern_output_train_engine_instance_0__global_0_0.value = forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0.value;
		}

		// forec_intern_output_train_engine_instance_1__global_0_0
		if (forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1.status == FOREC_SHARED_MODIFIED) {
			forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1.status = FOREC_SHARED_UNMODIFIED;
			forec_intern_output_train_engine_instance_1__global_0_0.value = forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1.value;
		}

		// forec_intern_output_train_engine_instance_2__global_0_0
		if (forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2.status == FOREC_SHARED_MODIFIED) {
			forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2.status = FOREC_SHARED_UNMODIFIED;
			forec_intern_output_train_engine_instance_2__global_0_0.value = forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2.value;
		}

		// forec_intern_output_train_engine_instance_3__global_0_0
		if (forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3.status == FOREC_SHARED_MODIFIED) {
			forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3.status = FOREC_SHARED_UNMODIFIED;
			forec_intern_output_train_engine_instance_3__global_0_0.value = forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3.value;
		}

		// forec_intern_output_train_engine_instance_4__global_0_0
		if (forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4.status == FOREC_SHARED_MODIFIED) {
			forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4.status = FOREC_SHARED_UNMODIFIED;
			forec_intern_output_train_engine_instance_4__global_0_0.value = forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4.value;
		}

		// trainEngineInstanceData__global_0_0
		numberOfModifiedCopies = 0;
		Shared_trainEngineInstanceData__global_0_0 *modified_trainEngineInstanceData__global_0_0[5];
		// Find the modified copies.
		if (trainEngineInstanceData__global_0_0_copy_engineInstance0.status == FOREC_SHARED_MODIFIED) {
			trainEngineInstanceData__global_0_0_copy_engineInstance0.status = FOREC_SHARED_UNMODIFIED;
			modified_trainEngineInstanceData__global_0_0[numberOfModifiedCopies] = &trainEngineInstanceData__global_0_0_copy_engineInstance0;
			++numberOfModifiedCopies;
		}
		if (trainEngineInstanceData__global_0_0_copy_engineInstance1.status == FOREC_SHARED_MODIFIED) {
			trainEngineInstanceData__global_0_0_copy_engineInstance1.status = FOREC_SHARED_UNMODIFIED;
			modified_trainEngineInstanceData__global_0_0[numberOfModifiedCopies] = &trainEngineInstanceData__global_0_0_copy_engineInstance1;
			++numberOfModifiedCopies;
		}
		if (trainEngineInstanceData__global_0_0_copy_engineInstance2.status == FOREC_SHARED_MODIFIED) {
			trainEngineInstanceData__global_0_0_copy_engineInstance2.status = FOREC_SHARED_UNMODIFIED;
			modified_trainEngineInstanceData__global_0_0[numberOfModifiedCopies] = &trainEngineInstanceData__global_0_0_copy_engineInstance2;
			++numberOfModifiedCopies;
		}
		if (trainEngineInstanceData__global_0_0_copy_engineInstance3.status == FOREC_SHARED_MODIFIED) {
			trainEngineInstanceData__global_0_0_copy_engineInstance3.status = FOREC_SHARED_UNMODIFIED;
			modified_trainEngineInstanceData__global_0_0[numberOfModifiedCopies] = &trainEngineInstanceData__global_0_0_copy_engineInstance3;
			++numberOfModifiedCopies;
		}
		if (trainEngineInstanceData__global_0_0_copy_engineInstance4.status == FOREC_SHARED_MODIFIED) {
			trainEngineInstanceData__global_0_0_copy_engineInstance4.status = FOREC_SHARED_UNMODIFIED;
			modified_trainEngineInstanceData__global_0_0[numberOfModifiedCopies] = &trainEngineInstanceData__global_0_0_copy_engineInstance4;
			++numberOfModifiedCopies;
		}
		// Assign the first modified copy.
		if (numberOfModifiedCopies > 0) {
			trainEngineInstanceData__global_0_0.value = modified_trainEngineInstanceData__global_0_0[0]->value;
		}
		// Combine with the remaining modified copies.
		for (index = 1; index < numberOfModifiedCopies; ++index) {
			trainEngineInstanceData__global_0_0.value = keepOneCombine(&trainEngineInstanceData__global_0_0.value, &modified_trainEngineInstanceData__global_0_0[index]->value);
		}
	} else {
		// Nothing.
	}

	// Return back to the parent thread if all the cores have terminated.
	if (1 && mainParCore0.status == FOREC_CORE_TERMINATED && mainParCore1.status == FOREC_CORE_TERMINATED && mainParCore2.status == FOREC_CORE_TERMINATED) {
		pthread_mutex_lock(&mainParParent.parStatusLock);
		mainParParent.parStatus = FOREC_PAR_OFF;
		pthread_cond_broadcast(&mainParParent.parStatusCond);
		pthread_mutex_unlock(&mainParParent.parStatusLock);
		mainParParent.parId = -1;
		
		// Set slave cores' status to reacting
		mainParCore1.status = FOREC_CORE_REACTING;
		mainParCore2.status = FOREC_CORE_REACTING;

		// Increment the reaction counter for synchronization.
		pthread_mutex_lock(&mainParReactionCounterLock);
		mainParReactionCounter++;
		pthread_cond_broadcast(&mainParReactionCounterCond);
		pthread_mutex_unlock(&mainParReactionCounterLock);

		goto *mainParParent.programCounter;
	}

	// Set slave cores' status to reacting
	mainParCore1.status = FOREC_CORE_REACTING;
	mainParCore2.status = FOREC_CORE_REACTING;

	// forec:scheduler:counter:start
	clockTimeUs.current = getClockTimeUs();
	clockTimeUs.elapsed = clockTimeUs.current - clockTimeUs.previous;
	if (clockTimeUs.elapsed < 0) {
		usleep(0 - clockTimeUs.elapsed);
	}
	clockTimeUs.previous = getClockTimeUs();
	// forec:scheduler:counter:end

	// Increment the reaction counter for synchronization.
	pthread_mutex_lock(&mainParReactionCounterLock);
	mainParReactionCounter++;
	pthread_cond_broadcast(&mainParReactionCounterCond);
	pthread_mutex_unlock(&mainParReactionCounterLock);

	// Go to the next thread.
	goto *mainReactionEndMaster0.nextThread -> programCounter;
}
	// forec:scheduler:reactionEnd:main:master:0:end
 


	// Abort check handlers ----------------------------------------
	// forec:scheduler:abortHandler:abortStrongNonImmediate0:0:start
	// abortStrongNonImmediate0 (forec_intern_input__global_0_0.value.terminate && init__abortStrongNonImmediate0 == 1)
abortStrongNonImmediate0Check0: {
	// Check the abort condition.
	if (forec_intern_input__global_0_0.value.terminate && init__abortStrongNonImmediate0 == 1) {
		// Force the reaction end handler to terminate the par(...).
		mainParCore0.activeThreads = 0;

		// Update the parent thread to resume at the end of the abort scope.
		mainParParent.programCounter = &&abortEnd_abortStrongNonImmediate0;
		
		goto mainReactionEndMaster0;
	}
	
	// Continue to the next thread.
	goto *abortStrongNonImmediate0Check0.nextThread -> programCounter;
}
	// forec:scheduler:abortHandler:abortStrongNonImmediate0:0:end


// forec:scheduler:parHandler:main:slave:1:start
/*--------------------------------------------------------------
| Slave core: core1
*-------------------------------------------------------------*/
mainParCore1: {
	// Check the execution status of the root par(...)s.
	// TODO: pthread_mutex_lock(&mainParParent.parStatusLock);
	while (mainParParent.parStatus == FOREC_PAR_OFF) { pthread_testcancel(); /* TODO: pthread_cond_wait(&mainParParent.parStatusCond, &mainParParent.parStatusLock); */ }
	// TODO: pthread_mutex_unlock(&mainParParent.parStatusLock);

	int parId = mainParParent.parId;

	// Check the par(...) ID.
	if (parId == 0) {
		asm("# par0 start");
		// Link the threads and handlers together.
		mainReactionStartSlave1.programCounter = &&mainReactionStartSlave1;
		abortStrongNonImmediate0Check1.programCounter = &&abortStrongNonImmediate0Check1;
		mainReactionStartSlave1.nextThread = &abortStrongNonImmediate0Check1;
		abortStrongNonImmediate0Check1.prevThread = &mainReactionStartSlave1;
		loadEngines__thread.programCounter = &&loadEngines__thread;
		abortStrongNonImmediate0Check1.nextThread = &loadEngines__thread;
		loadEngines__thread.prevThread = &abortStrongNonImmediate0Check1;
		engineInstance0__thread.programCounter = &&engineInstance0__thread;
		loadEngines__thread.nextThread = &engineInstance0__thread;
		engineInstance0__thread.prevThread = &loadEngines__thread;
		engineInstance2__thread.programCounter = &&engineInstance2__thread;
		engineInstance0__thread.nextThread = &engineInstance2__thread;
		engineInstance2__thread.prevThread = &engineInstance0__thread;
		engineInstance4__thread.programCounter = &&engineInstance4__thread;
		engineInstance2__thread.nextThread = &engineInstance4__thread;
		engineInstance4__thread.prevThread = &engineInstance2__thread;
		interlockerInstance1__thread.programCounter = &&interlockerInstance1__thread;
		engineInstance4__thread.nextThread = &interlockerInstance1__thread;
		interlockerInstance1__thread.prevThread = &engineInstance4__thread;
		interlockerInstance3__thread.programCounter = &&interlockerInstance3__thread;
		interlockerInstance1__thread.nextThread = &interlockerInstance3__thread;
		interlockerInstance3__thread.prevThread = &interlockerInstance1__thread;
		mainReactionEndSlave1.programCounter = &&mainReactionEndSlave1;
		interlockerInstance3__thread.nextThread = &mainReactionEndSlave1;
		mainReactionEndSlave1.prevThread = &interlockerInstance3__thread;

		// Link the last and first threads/handlers together.
		mainReactionEndSlave1.nextThread = &mainReactionStartSlave1;
		mainReactionStartSlave1.prevThread = &mainReactionEndSlave1;

		// Set the core information.
		mainParCore1.activeThreads = 6;
		mainParCore1.reactionCounter = mainParReactionCounter;

		// Go to the first thread.
		goto loadEngines__thread;
		asm("# par0 end");
	} else {
		// Unscheduled par(...)
		mainParCore1.reactionCounter = mainParReactionCounter;
		
		// Wait for the par(...) to terminate.
		do {
			pthread_mutex_lock(&mainParCore1.statusLock);
			mainParCore1.status = FOREC_CORE_TERMINATED;
			pthread_cond_signal(&mainParCore1.statusCond);
			pthread_mutex_unlock(&mainParCore1.statusLock);
			
			// Wait for the next tick.
			pthread_mutex_lock(&mainParReactionCounterLock);
			while (mainParCore1.reactionCounter == mainParReactionCounter) { pthread_testcancel(); pthread_cond_wait(&mainParReactionCounterCond, &mainParReactionCounterLock); }
			pthread_mutex_unlock(&mainParReactionCounterLock);
			mainParCore1.reactionCounter++;
			
		} while (mainParParent.parStatus == FOREC_PAR_ON && mainParParent.parId == parId);
		
		// Go back to the top and wait for the next nested par(...) 
		goto mainParCore1;
	}
	
	// Control shouldn't reach here.
	goto mainParCore1;
}
// forec:scheduler:parHandler:main:slave:1:end

	// Nested par(...) handlers ------------------------------------


	// Reaction start handlers ---------------------------------------
	// forec:scheduler:reactionStart:main:slave:1:start
	//-- main:
mainReactionStartSlave1: {
	// Go to the next thread.
	goto *mainReactionStartSlave1.nextThread -> programCounter;
}
	// forec:scheduler:reactionStart:main:slave:1:end
 


	// Reaction end handlers ---------------------------------------
	// forec:scheduler:reactionEnd:main:slave:1:start
	//-- main:
mainReactionEndSlave1: {
	// Determine if the core can still react or not.
	if (mainParCore1.activeThreads) {
		pthread_mutex_lock(&mainParCore1.statusLock);
		mainParCore1.status = FOREC_CORE_REACTED;
		pthread_cond_signal(&mainParCore1.statusCond);
		pthread_mutex_unlock(&mainParCore1.statusLock);
		
		// Wait for the next tick.
		pthread_mutex_lock(&mainParReactionCounterLock);
		while (mainParCore1.reactionCounter == mainParReactionCounter) { pthread_testcancel(); pthread_cond_wait(&mainParReactionCounterCond, &mainParReactionCounterLock); }
		pthread_mutex_unlock(&mainParReactionCounterLock);
		mainParCore1.reactionCounter++;
		
		// Continue reacting.
		goto *mainReactionEndSlave1.nextThread -> programCounter;
	} else {
		int parId = mainParParent.parId;

		mainReactionEndSlave1.programCounter = &&terminated_mainReactionEndSlave1;
		terminated_mainReactionEndSlave1:;
		
		pthread_mutex_lock(&mainParCore1.statusLock);
		mainParCore1.status = FOREC_CORE_TERMINATED;
		pthread_cond_signal(&mainParCore1.statusCond);
		pthread_mutex_unlock(&mainParCore1.statusLock);
		
		// Wait for the next tick.
		pthread_mutex_lock(&mainParReactionCounterLock);
		while (mainParCore1.reactionCounter == mainParReactionCounter) { pthread_testcancel(); pthread_cond_wait(&mainParReactionCounterCond, &mainParReactionCounterLock); }
		pthread_mutex_unlock(&mainParReactionCounterLock);
		mainParCore1.reactionCounter++;
		
		// Wait for the par(...) to terminate.
		if (mainParParent.parStatus == FOREC_PAR_ON && mainParParent.parId == parId) {
			goto *mainReactionEndSlave1.nextThread -> programCounter;
		}

		goto mainParCore1;
	}
	
	// Control shouldn't reach here.
	goto mainReactionEndSlave1;
}
	// forec:scheduler:reactionEnd:main:slave:1:end
 


	// Abort check handlers ----------------------------------------
	// forec:scheduler:abortHandler:abortStrongNonImmediate0:1:start
	// abortStrongNonImmediate0 (forec_intern_input__global_0_0.value.terminate && init__abortStrongNonImmediate0 == 1)
abortStrongNonImmediate0Check1: {
	// Check the abort condition.
	if (forec_intern_input__global_0_0.value.terminate && init__abortStrongNonImmediate0 == 1) {
		// Force the reaction end handler to terminate the par(...).
		mainParCore1.activeThreads = 0;
		
		goto mainReactionEndSlave1;
	}
	
	// Continue to the next thread.
	goto *abortStrongNonImmediate0Check1.nextThread -> programCounter;
}
	// forec:scheduler:abortHandler:abortStrongNonImmediate0:1:end

// forec:scheduler:parHandler:main:slave:2:start
/*--------------------------------------------------------------
| Slave core: core2
*-------------------------------------------------------------*/
mainParCore2: {
	// Check the execution status of the root par(...)s.
	// TODO: pthread_mutex_lock(&mainParParent.parStatusLock);
	while (mainParParent.parStatus == FOREC_PAR_OFF) { pthread_testcancel(); /* TODO: pthread_cond_wait(&mainParParent.parStatusCond, &mainParParent.parStatusLock); */ }
	// TODO: pthread_mutex_unlock(&mainParParent.parStatusLock);

	int parId = mainParParent.parId;

	// Check the par(...) ID.
	if (parId == 0) {
		asm("# par0 start");
		// Link the threads and handlers together.
		mainReactionStartSlave2.programCounter = &&mainReactionStartSlave2;
		abortStrongNonImmediate0Check2.programCounter = &&abortStrongNonImmediate0Check2;
		mainReactionStartSlave2.nextThread = &abortStrongNonImmediate0Check2;
		abortStrongNonImmediate0Check2.prevThread = &mainReactionStartSlave2;
		loadInterlockers__thread.programCounter = &&loadInterlockers__thread;
		abortStrongNonImmediate0Check2.nextThread = &loadInterlockers__thread;
		loadInterlockers__thread.prevThread = &abortStrongNonImmediate0Check2;
		engineInstance1__thread.programCounter = &&engineInstance1__thread;
		loadInterlockers__thread.nextThread = &engineInstance1__thread;
		engineInstance1__thread.prevThread = &loadInterlockers__thread;
		engineInstance3__thread.programCounter = &&engineInstance3__thread;
		engineInstance1__thread.nextThread = &engineInstance3__thread;
		engineInstance3__thread.prevThread = &engineInstance1__thread;
		interlockerInstance0__thread.programCounter = &&interlockerInstance0__thread;
		engineInstance3__thread.nextThread = &interlockerInstance0__thread;
		interlockerInstance0__thread.prevThread = &engineInstance3__thread;
		interlockerInstance2__thread.programCounter = &&interlockerInstance2__thread;
		interlockerInstance0__thread.nextThread = &interlockerInstance2__thread;
		interlockerInstance2__thread.prevThread = &interlockerInstance0__thread;
		mainReactionEndSlave2.programCounter = &&mainReactionEndSlave2;
		interlockerInstance2__thread.nextThread = &mainReactionEndSlave2;
		mainReactionEndSlave2.prevThread = &interlockerInstance2__thread;

		// Link the last and first threads/handlers together.
		mainReactionEndSlave2.nextThread = &mainReactionStartSlave2;
		mainReactionStartSlave2.prevThread = &mainReactionEndSlave2;

		// Set the core information.
		mainParCore2.activeThreads = 5;
		mainParCore2.reactionCounter = mainParReactionCounter;

		// Go to the first thread.
		goto loadInterlockers__thread;
		asm("# par0 end");
	} else {
		// Unscheduled par(...)
		mainParCore2.reactionCounter = mainParReactionCounter;
		
		// Wait for the par(...) to terminate.
		do {
			pthread_mutex_lock(&mainParCore2.statusLock);
			mainParCore2.status = FOREC_CORE_TERMINATED;
			pthread_cond_signal(&mainParCore2.statusCond);
			pthread_mutex_unlock(&mainParCore2.statusLock);
			
			// Wait for the next tick.
			pthread_mutex_lock(&mainParReactionCounterLock);
			while (mainParCore2.reactionCounter == mainParReactionCounter) { pthread_testcancel(); pthread_cond_wait(&mainParReactionCounterCond, &mainParReactionCounterLock); }
			pthread_mutex_unlock(&mainParReactionCounterLock);
			mainParCore2.reactionCounter++;
			
		} while (mainParParent.parStatus == FOREC_PAR_ON && mainParParent.parId == parId);
		
		// Go back to the top and wait for the next nested par(...) 
		goto mainParCore2;
	}
	
	// Control shouldn't reach here.
	goto mainParCore2;
}
// forec:scheduler:parHandler:main:slave:2:end

	// Nested par(...) handlers ------------------------------------


	// Reaction start handlers ---------------------------------------
	// forec:scheduler:reactionStart:main:slave:2:start
	//-- main:
mainReactionStartSlave2: {
	// Go to the next thread.
	goto *mainReactionStartSlave2.nextThread -> programCounter;
}
	// forec:scheduler:reactionStart:main:slave:2:end
 


	// Reaction end handlers ---------------------------------------
	// forec:scheduler:reactionEnd:main:slave:2:start
	//-- main:
mainReactionEndSlave2: {
	// Determine if the core can still react or not.
	if (mainParCore2.activeThreads) {
		pthread_mutex_lock(&mainParCore2.statusLock);
		mainParCore2.status = FOREC_CORE_REACTED;
		pthread_cond_signal(&mainParCore2.statusCond);
		pthread_mutex_unlock(&mainParCore2.statusLock);
		
		// Wait for the next tick.
		pthread_mutex_lock(&mainParReactionCounterLock);
		while (mainParCore2.reactionCounter == mainParReactionCounter) { pthread_testcancel(); pthread_cond_wait(&mainParReactionCounterCond, &mainParReactionCounterLock); }
		pthread_mutex_unlock(&mainParReactionCounterLock);
		mainParCore2.reactionCounter++;
		
		// Continue reacting.
		goto *mainReactionEndSlave2.nextThread -> programCounter;
	} else {
		int parId = mainParParent.parId;

		mainReactionEndSlave2.programCounter = &&terminated_mainReactionEndSlave2;
		terminated_mainReactionEndSlave2:;
		
		pthread_mutex_lock(&mainParCore2.statusLock);
		mainParCore2.status = FOREC_CORE_TERMINATED;
		pthread_cond_signal(&mainParCore2.statusCond);
		pthread_mutex_unlock(&mainParCore2.statusLock);
		
		// Wait for the next tick.
		pthread_mutex_lock(&mainParReactionCounterLock);
		while (mainParCore2.reactionCounter == mainParReactionCounter) { pthread_testcancel(); pthread_cond_wait(&mainParReactionCounterCond, &mainParReactionCounterLock); }
		pthread_mutex_unlock(&mainParReactionCounterLock);
		mainParCore2.reactionCounter++;
		
		// Wait for the par(...) to terminate.
		if (mainParParent.parStatus == FOREC_PAR_ON && mainParParent.parId == parId) {
			goto *mainReactionEndSlave2.nextThread -> programCounter;
		}

		goto mainParCore2;
	}
	
	// Control shouldn't reach here.
	goto mainReactionEndSlave2;
}
	// forec:scheduler:reactionEnd:main:slave:2:end
 


	// Abort check handlers ----------------------------------------
	// forec:scheduler:abortHandler:abortStrongNonImmediate0:2:start
	// abortStrongNonImmediate0 (forec_intern_input__global_0_0.value.terminate && init__abortStrongNonImmediate0 == 1)
abortStrongNonImmediate0Check2: {
	// Check the abort condition.
	if (forec_intern_input__global_0_0.value.terminate && init__abortStrongNonImmediate0 == 1) {
		// Force the reaction end handler to terminate the par(...).
		mainParCore2.activeThreads = 0;
		
		goto mainReactionEndSlave2;
	}
	
	// Continue to the next thread.
	goto *abortStrongNonImmediate0Check2.nextThread -> programCounter;
}
	// forec:scheduler:abortHandler:abortStrongNonImmediate0:2:end



/*==============================================================
| ForeC threads:
| Threads' code translated into C code.
*=============================================================*/
	// forec:thread:engineInstance0:start
	/*--------------------------------------------------------------
	| Thread engineInstance0
	*-------------------------------------------------------------*/

	// Thread local declarations -----------------------------------
	Shared_forec_intern_output_train_engine_instance_0__global_0_0 forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local;
	Shared_LOG_NOTICE__global_0_0 LOG_NOTICE__global_0_0_copy_engineInstance0_local;
	Shared_trainEngineInstanceData__global_0_0 trainEngineInstanceData__global_0_0_copy_engineInstance0_local;
	unsigned int instance__engineInstance0_0_0;
	const char *threadName__engineInstance0_0_0;
	int trainEngineType__engineInstance0_0_0;

	// Thread body -------------------------------------------------
	engineInstance0__thread: {
		// Initialise the local copies of shared variables.
		forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local.value = forec_intern_output_train_engine_instance_0__global_0_0.value;
		forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local.status = FOREC_SHARED_UNMODIFIED;
		LOG_NOTICE__global_0_0_copy_engineInstance0_local.value = LOG_NOTICE__global_0_0.value;
		LOG_NOTICE__global_0_0_copy_engineInstance0_local.status = FOREC_SHARED_UNMODIFIED;
		trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value = trainEngineInstanceData__global_0_0.value;
		trainEngineInstanceData__global_0_0_copy_engineInstance0_local.status = FOREC_SHARED_UNMODIFIED;
		//--------------------------------------------------------------

		instance__engineInstance0_0_0 = 0;
		threadName__engineInstance0_0_0 = "engineInstance0";
		trainEngineType__engineInstance0_0_0 = -1;

		while (true) {
			while (!forec_intern_input_train_engine_instance_0__global_0_0.value.grab) {
				// pause;
				// Write the local copy of shared variables back to their global copy.
				forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0 = forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local;
				trainEngineInstanceData__global_0_0_copy_engineInstance0 = trainEngineInstanceData__global_0_0_copy_engineInstance0_local;
				// forec:statement:pause:pause2:start
				engineInstance0__thread.programCounter = &&pause2;
				goto *engineInstance0__thread.nextThread -> programCounter;
				pause2:;
				// forec:statement:pause:pause2:end
				// Update the values of the used shared variables from their global copy.
				forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local = forec_intern_output_train_engine_instance_0__global_0_0;
				LOG_NOTICE__global_0_0_copy_engineInstance0_local = LOG_NOTICE__global_0_0;
				trainEngineInstanceData__global_0_0_copy_engineInstance0_local = trainEngineInstanceData__global_0_0;

			}

			trainEngineType__engineInstance0_0_0 = forec_intern_input_train_engine_instance_0__global_0_0.value.train_engine_type;
			forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local.value.in_use = true;
			forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local.status = FOREC_SHARED_MODIFIED;
			dynlib_reset(&trainEngines__global_0_0.value[trainEngineType__engineInstance0_0_0], &trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0]);
			dynlib_tick(&trainEngines__global_0_0.value[trainEngineType__engineInstance0_0_0], &trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0]);
			syslog_server(LOG_NOTICE__global_0_0_copy_engineInstance0_local.value, "%s: Reset container  %d %d -> %d %d", threadName__engineInstance0_0_0, trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0].requested_speed, trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0].requested_forwards, trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0].nominal_speed, trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0].nominal_forwards);

			while (!forec_intern_input_train_engine_instance_0__global_0_0.value.release) {
				trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0].requested_speed = forec_intern_input_train_engine_instance_0__global_0_0.value.requested_speed;
				trainEngineInstanceData__global_0_0_copy_engineInstance0_local.status = FOREC_SHARED_MODIFIED;
				trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0].requested_forwards = forec_intern_input_train_engine_instance_0__global_0_0.value.requested_forwards;
				trainEngineInstanceData__global_0_0_copy_engineInstance0_local.status = FOREC_SHARED_MODIFIED;
				dynlib_tick(&trainEngines__global_0_0.value[trainEngineType__engineInstance0_0_0], &trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0]);
				if (trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0].nominal_speed != forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local.value.nominal_speed || trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0].nominal_forwards != forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local.value.nominal_forwards) {
					syslog_server(LOG_NOTICE__global_0_0_copy_engineInstance0_local.value, "%s: %s.tick()  %d %d -> %d %d", threadName__engineInstance0_0_0, trainEngines__global_0_0.value[trainEngineType__engineInstance0_0_0].name, trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0].requested_speed, trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0].requested_forwards, trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0].nominal_speed, trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0].nominal_forwards);
					forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local.value.nominal_speed = trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0].nominal_speed;
					forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local.status = FOREC_SHARED_MODIFIED;
					forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local.value.nominal_forwards = trainEngineInstanceData__global_0_0_copy_engineInstance0_local.value[instance__engineInstance0_0_0].nominal_forwards;
					forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local.status = FOREC_SHARED_MODIFIED;
				} else {
					// if14
				}

				// pause;
				// Write the local copy of shared variables back to their global copy.
				forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0 = forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local;
				trainEngineInstanceData__global_0_0_copy_engineInstance0 = trainEngineInstanceData__global_0_0_copy_engineInstance0_local;
				// forec:statement:pause:pause3:start
				engineInstance0__thread.programCounter = &&pause3;
				goto *engineInstance0__thread.nextThread -> programCounter;
				pause3:;
				// forec:statement:pause:pause3:end
				// Update the values of the used shared variables from their global copy.
				forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local = forec_intern_output_train_engine_instance_0__global_0_0;
				LOG_NOTICE__global_0_0_copy_engineInstance0_local = LOG_NOTICE__global_0_0;
				trainEngineInstanceData__global_0_0_copy_engineInstance0_local = trainEngineInstanceData__global_0_0;

			}

			trainEngineType__engineInstance0_0_0 = -1;
			forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local.value.in_use = false;
			forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local.status = FOREC_SHARED_MODIFIED;
			syslog_server(LOG_NOTICE__global_0_0_copy_engineInstance0_local.value, "%s: Released container", threadName__engineInstance0_0_0);

			// pause;
			// Write the local copy of shared variables back to their global copy.
			forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0 = forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local;
			trainEngineInstanceData__global_0_0_copy_engineInstance0 = trainEngineInstanceData__global_0_0_copy_engineInstance0_local;
			// forec:statement:pause:pause4:start
			engineInstance0__thread.programCounter = &&pause4;
			goto *engineInstance0__thread.nextThread -> programCounter;
			pause4:;
			// forec:statement:pause:pause4:end
			// Update the values of the used shared variables from their global copy.
			forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local = forec_intern_output_train_engine_instance_0__global_0_0;
			LOG_NOTICE__global_0_0_copy_engineInstance0_local = LOG_NOTICE__global_0_0;
			trainEngineInstanceData__global_0_0_copy_engineInstance0_local = trainEngineInstanceData__global_0_0;

		}

		//--------------------------------------------------------------
		// Write the defined shared variables back to their global copy.
		forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0 = forec_intern_output_train_engine_instance_0__global_0_0_copy_engineInstance0_local;
		trainEngineInstanceData__global_0_0_copy_engineInstance0 = trainEngineInstanceData__global_0_0_copy_engineInstance0_local;

		// forec:scheduler:threadRemove:engineInstance0:start

		// Delete thread from the linked list and core.
		mainParCore1.activeThreads--;
		engineInstance0__thread.nextThread -> prevThread = engineInstance0__thread.prevThread;
		engineInstance0__thread.prevThread -> nextThread = engineInstance0__thread.nextThread;
		goto *engineInstance0__thread.nextThread -> programCounter;
		// forec:scheduler:threadRemove:engineInstance0:end
	} // engineInstance0__thread
	// forec:thread:engineInstance0:end

	// forec:thread:engineInstance1:start
	/*--------------------------------------------------------------
	| Thread engineInstance1
	*-------------------------------------------------------------*/

	// Thread local declarations -----------------------------------
	Shared_forec_intern_output_train_engine_instance_1__global_0_0 forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local;
	Shared_LOG_NOTICE__global_0_0 LOG_NOTICE__global_0_0_copy_engineInstance1_local;
	Shared_trainEngineInstanceData__global_0_0 trainEngineInstanceData__global_0_0_copy_engineInstance1_local;
	unsigned int instance__engineInstance1_0_0;
	const char *threadName__engineInstance1_0_0;
	int trainEngineType__engineInstance1_0_0;

	// Thread body -------------------------------------------------
	engineInstance1__thread: {
		// Initialise the local copies of shared variables.
		forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local.value = forec_intern_output_train_engine_instance_1__global_0_0.value;
		forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local.status = FOREC_SHARED_UNMODIFIED;
		LOG_NOTICE__global_0_0_copy_engineInstance1_local.value = LOG_NOTICE__global_0_0.value;
		LOG_NOTICE__global_0_0_copy_engineInstance1_local.status = FOREC_SHARED_UNMODIFIED;
		trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value = trainEngineInstanceData__global_0_0.value;
		trainEngineInstanceData__global_0_0_copy_engineInstance1_local.status = FOREC_SHARED_UNMODIFIED;
		//--------------------------------------------------------------

		instance__engineInstance1_0_0 = 1;
		threadName__engineInstance1_0_0 = "engineInstance1";
		trainEngineType__engineInstance1_0_0 = -1;

		while (true) {
			while (!forec_intern_input_train_engine_instance_1__global_0_0.value.grab) {
				// pause;
				// Write the local copy of shared variables back to their global copy.
				forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1 = forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local;
				trainEngineInstanceData__global_0_0_copy_engineInstance1 = trainEngineInstanceData__global_0_0_copy_engineInstance1_local;
				// forec:statement:pause:pause5:start
				engineInstance1__thread.programCounter = &&pause5;
				goto *engineInstance1__thread.nextThread -> programCounter;
				pause5:;
				// forec:statement:pause:pause5:end
				// Update the values of the used shared variables from their global copy.
				forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local = forec_intern_output_train_engine_instance_1__global_0_0;
				LOG_NOTICE__global_0_0_copy_engineInstance1_local = LOG_NOTICE__global_0_0;
				trainEngineInstanceData__global_0_0_copy_engineInstance1_local = trainEngineInstanceData__global_0_0;

			}

			trainEngineType__engineInstance1_0_0 = forec_intern_input_train_engine_instance_1__global_0_0.value.train_engine_type;
			forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local.value.in_use = true;
			forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local.status = FOREC_SHARED_MODIFIED;
			dynlib_reset(&trainEngines__global_0_0.value[trainEngineType__engineInstance1_0_0], &trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0]);
			dynlib_tick(&trainEngines__global_0_0.value[trainEngineType__engineInstance1_0_0], &trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0]);
			syslog_server(LOG_NOTICE__global_0_0_copy_engineInstance1_local.value, "%s: Reset container  %d %d -> %d %d", threadName__engineInstance1_0_0, trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0].requested_speed, trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0].requested_forwards, trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0].nominal_speed, trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0].nominal_forwards);

			while (!forec_intern_input_train_engine_instance_1__global_0_0.value.release) {
				trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0].requested_speed = forec_intern_input_train_engine_instance_1__global_0_0.value.requested_speed;
				trainEngineInstanceData__global_0_0_copy_engineInstance1_local.status = FOREC_SHARED_MODIFIED;
				trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0].requested_forwards = forec_intern_input_train_engine_instance_1__global_0_0.value.requested_forwards;
				trainEngineInstanceData__global_0_0_copy_engineInstance1_local.status = FOREC_SHARED_MODIFIED;
				dynlib_tick(&trainEngines__global_0_0.value[trainEngineType__engineInstance1_0_0], &trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0]);
				if (trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0].nominal_speed != forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local.value.nominal_speed || trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0].nominal_forwards != forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local.value.nominal_forwards) {
					syslog_server(LOG_NOTICE__global_0_0_copy_engineInstance1_local.value, "%s: %s.tick()  %d %d -> %d %d", threadName__engineInstance1_0_0, trainEngines__global_0_0.value[trainEngineType__engineInstance1_0_0].name, trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0].requested_speed, trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0].requested_forwards, trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0].nominal_speed, trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0].nominal_forwards);
					forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local.value.nominal_speed = trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0].nominal_speed;
					forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local.status = FOREC_SHARED_MODIFIED;
					forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local.value.nominal_forwards = trainEngineInstanceData__global_0_0_copy_engineInstance1_local.value[instance__engineInstance1_0_0].nominal_forwards;
					forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local.status = FOREC_SHARED_MODIFIED;
				} else {
					// if15
				}

				// pause;
				// Write the local copy of shared variables back to their global copy.
				forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1 = forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local;
				trainEngineInstanceData__global_0_0_copy_engineInstance1 = trainEngineInstanceData__global_0_0_copy_engineInstance1_local;
				// forec:statement:pause:pause6:start
				engineInstance1__thread.programCounter = &&pause6;
				goto *engineInstance1__thread.nextThread -> programCounter;
				pause6:;
				// forec:statement:pause:pause6:end
				// Update the values of the used shared variables from their global copy.
				forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local = forec_intern_output_train_engine_instance_1__global_0_0;
				LOG_NOTICE__global_0_0_copy_engineInstance1_local = LOG_NOTICE__global_0_0;
				trainEngineInstanceData__global_0_0_copy_engineInstance1_local = trainEngineInstanceData__global_0_0;

			}

			trainEngineType__engineInstance1_0_0 = -1;
			forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local.value.in_use = false;
			forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local.status = FOREC_SHARED_MODIFIED;
			syslog_server(LOG_NOTICE__global_0_0_copy_engineInstance1_local.value, "%s: Released container", threadName__engineInstance1_0_0);

			// pause;
			// Write the local copy of shared variables back to their global copy.
			forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1 = forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local;
			trainEngineInstanceData__global_0_0_copy_engineInstance1 = trainEngineInstanceData__global_0_0_copy_engineInstance1_local;
			// forec:statement:pause:pause7:start
			engineInstance1__thread.programCounter = &&pause7;
			goto *engineInstance1__thread.nextThread -> programCounter;
			pause7:;
			// forec:statement:pause:pause7:end
			// Update the values of the used shared variables from their global copy.
			forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local = forec_intern_output_train_engine_instance_1__global_0_0;
			LOG_NOTICE__global_0_0_copy_engineInstance1_local = LOG_NOTICE__global_0_0;
			trainEngineInstanceData__global_0_0_copy_engineInstance1_local = trainEngineInstanceData__global_0_0;

		}

		//--------------------------------------------------------------
		// Write the defined shared variables back to their global copy.
		forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1 = forec_intern_output_train_engine_instance_1__global_0_0_copy_engineInstance1_local;
		trainEngineInstanceData__global_0_0_copy_engineInstance1 = trainEngineInstanceData__global_0_0_copy_engineInstance1_local;

		// forec:scheduler:threadRemove:engineInstance1:start

		// Delete thread from the linked list and core.
		mainParCore2.activeThreads--;
		engineInstance1__thread.nextThread -> prevThread = engineInstance1__thread.prevThread;
		engineInstance1__thread.prevThread -> nextThread = engineInstance1__thread.nextThread;
		goto *engineInstance1__thread.nextThread -> programCounter;
		// forec:scheduler:threadRemove:engineInstance1:end
	} // engineInstance1__thread
	// forec:thread:engineInstance1:end

	// forec:thread:engineInstance2:start
	/*--------------------------------------------------------------
	| Thread engineInstance2
	*-------------------------------------------------------------*/

	// Thread local declarations -----------------------------------
	Shared_forec_intern_output_train_engine_instance_2__global_0_0 forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local;
	Shared_LOG_NOTICE__global_0_0 LOG_NOTICE__global_0_0_copy_engineInstance2_local;
	Shared_trainEngineInstanceData__global_0_0 trainEngineInstanceData__global_0_0_copy_engineInstance2_local;
	unsigned int instance__engineInstance2_0_0;
	const char *threadName__engineInstance2_0_0;
	int trainEngineType__engineInstance2_0_0;

	// Thread body -------------------------------------------------
	engineInstance2__thread: {
		// Initialise the local copies of shared variables.
		forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local.value = forec_intern_output_train_engine_instance_2__global_0_0.value;
		forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local.status = FOREC_SHARED_UNMODIFIED;
		LOG_NOTICE__global_0_0_copy_engineInstance2_local.value = LOG_NOTICE__global_0_0.value;
		LOG_NOTICE__global_0_0_copy_engineInstance2_local.status = FOREC_SHARED_UNMODIFIED;
		trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value = trainEngineInstanceData__global_0_0.value;
		trainEngineInstanceData__global_0_0_copy_engineInstance2_local.status = FOREC_SHARED_UNMODIFIED;
		//--------------------------------------------------------------

		instance__engineInstance2_0_0 = 2;
		threadName__engineInstance2_0_0 = "engineInstance2";
		trainEngineType__engineInstance2_0_0 = -1;

		while (true) {
			while (!forec_intern_input_train_engine_instance_2__global_0_0.value.grab) {
				// pause;
				// Write the local copy of shared variables back to their global copy.
				forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2 = forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local;
				trainEngineInstanceData__global_0_0_copy_engineInstance2 = trainEngineInstanceData__global_0_0_copy_engineInstance2_local;
				// forec:statement:pause:pause8:start
				engineInstance2__thread.programCounter = &&pause8;
				goto *engineInstance2__thread.nextThread -> programCounter;
				pause8:;
				// forec:statement:pause:pause8:end
				// Update the values of the used shared variables from their global copy.
				forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local = forec_intern_output_train_engine_instance_2__global_0_0;
				LOG_NOTICE__global_0_0_copy_engineInstance2_local = LOG_NOTICE__global_0_0;
				trainEngineInstanceData__global_0_0_copy_engineInstance2_local = trainEngineInstanceData__global_0_0;

			}

			trainEngineType__engineInstance2_0_0 = forec_intern_input_train_engine_instance_2__global_0_0.value.train_engine_type;
			forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local.value.in_use = true;
			forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local.status = FOREC_SHARED_MODIFIED;
			dynlib_reset(&trainEngines__global_0_0.value[trainEngineType__engineInstance2_0_0], &trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0]);
			dynlib_tick(&trainEngines__global_0_0.value[trainEngineType__engineInstance2_0_0], &trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0]);
			syslog_server(LOG_NOTICE__global_0_0_copy_engineInstance2_local.value, "%s: Reset container  %d %d -> %d %d", threadName__engineInstance2_0_0, trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0].requested_speed, trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0].requested_forwards, trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0].nominal_speed, trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0].nominal_forwards);

			while (!forec_intern_input_train_engine_instance_2__global_0_0.value.release) {
				trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0].requested_speed = forec_intern_input_train_engine_instance_2__global_0_0.value.requested_speed;
				trainEngineInstanceData__global_0_0_copy_engineInstance2_local.status = FOREC_SHARED_MODIFIED;
				trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0].requested_forwards = forec_intern_input_train_engine_instance_2__global_0_0.value.requested_forwards;
				trainEngineInstanceData__global_0_0_copy_engineInstance2_local.status = FOREC_SHARED_MODIFIED;
				dynlib_tick(&trainEngines__global_0_0.value[trainEngineType__engineInstance2_0_0], &trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0]);
				if (trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0].nominal_speed != forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local.value.nominal_speed || trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0].nominal_forwards != forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local.value.nominal_forwards) {
					syslog_server(LOG_NOTICE__global_0_0_copy_engineInstance2_local.value, "%s: %s.tick()  %d %d -> %d %d", threadName__engineInstance2_0_0, trainEngines__global_0_0.value[trainEngineType__engineInstance2_0_0].name, trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0].requested_speed, trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0].requested_forwards, trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0].nominal_speed, trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0].nominal_forwards);
					forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local.value.nominal_speed = trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0].nominal_speed;
					forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local.status = FOREC_SHARED_MODIFIED;
					forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local.value.nominal_forwards = trainEngineInstanceData__global_0_0_copy_engineInstance2_local.value[instance__engineInstance2_0_0].nominal_forwards;
					forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local.status = FOREC_SHARED_MODIFIED;
				} else {
					// if16
				}

				// pause;
				// Write the local copy of shared variables back to their global copy.
				forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2 = forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local;
				trainEngineInstanceData__global_0_0_copy_engineInstance2 = trainEngineInstanceData__global_0_0_copy_engineInstance2_local;
				// forec:statement:pause:pause9:start
				engineInstance2__thread.programCounter = &&pause9;
				goto *engineInstance2__thread.nextThread -> programCounter;
				pause9:;
				// forec:statement:pause:pause9:end
				// Update the values of the used shared variables from their global copy.
				forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local = forec_intern_output_train_engine_instance_2__global_0_0;
				LOG_NOTICE__global_0_0_copy_engineInstance2_local = LOG_NOTICE__global_0_0;
				trainEngineInstanceData__global_0_0_copy_engineInstance2_local = trainEngineInstanceData__global_0_0;

			}

			trainEngineType__engineInstance2_0_0 = -1;
			forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local.value.in_use = false;
			forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local.status = FOREC_SHARED_MODIFIED;
			syslog_server(LOG_NOTICE__global_0_0_copy_engineInstance2_local.value, "%s: Released container", threadName__engineInstance2_0_0);

			// pause;
			// Write the local copy of shared variables back to their global copy.
			forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2 = forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local;
			trainEngineInstanceData__global_0_0_copy_engineInstance2 = trainEngineInstanceData__global_0_0_copy_engineInstance2_local;
			// forec:statement:pause:pause10:start
			engineInstance2__thread.programCounter = &&pause10;
			goto *engineInstance2__thread.nextThread -> programCounter;
			pause10:;
			// forec:statement:pause:pause10:end
			// Update the values of the used shared variables from their global copy.
			forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local = forec_intern_output_train_engine_instance_2__global_0_0;
			LOG_NOTICE__global_0_0_copy_engineInstance2_local = LOG_NOTICE__global_0_0;
			trainEngineInstanceData__global_0_0_copy_engineInstance2_local = trainEngineInstanceData__global_0_0;

		}

		//--------------------------------------------------------------
		// Write the defined shared variables back to their global copy.
		forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2 = forec_intern_output_train_engine_instance_2__global_0_0_copy_engineInstance2_local;
		trainEngineInstanceData__global_0_0_copy_engineInstance2 = trainEngineInstanceData__global_0_0_copy_engineInstance2_local;

		// forec:scheduler:threadRemove:engineInstance2:start

		// Delete thread from the linked list and core.
		mainParCore1.activeThreads--;
		engineInstance2__thread.nextThread -> prevThread = engineInstance2__thread.prevThread;
		engineInstance2__thread.prevThread -> nextThread = engineInstance2__thread.nextThread;
		goto *engineInstance2__thread.nextThread -> programCounter;
		// forec:scheduler:threadRemove:engineInstance2:end
	} // engineInstance2__thread
	// forec:thread:engineInstance2:end

	// forec:thread:engineInstance3:start
	/*--------------------------------------------------------------
	| Thread engineInstance3
	*-------------------------------------------------------------*/

	// Thread local declarations -----------------------------------
	Shared_forec_intern_output_train_engine_instance_3__global_0_0 forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local;
	Shared_LOG_NOTICE__global_0_0 LOG_NOTICE__global_0_0_copy_engineInstance3_local;
	Shared_trainEngineInstanceData__global_0_0 trainEngineInstanceData__global_0_0_copy_engineInstance3_local;
	unsigned int instance__engineInstance3_0_0;
	const char *threadName__engineInstance3_0_0;
	int trainEngineType__engineInstance3_0_0;

	// Thread body -------------------------------------------------
	engineInstance3__thread: {
		// Initialise the local copies of shared variables.
		forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local.value = forec_intern_output_train_engine_instance_3__global_0_0.value;
		forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local.status = FOREC_SHARED_UNMODIFIED;
		LOG_NOTICE__global_0_0_copy_engineInstance3_local.value = LOG_NOTICE__global_0_0.value;
		LOG_NOTICE__global_0_0_copy_engineInstance3_local.status = FOREC_SHARED_UNMODIFIED;
		trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value = trainEngineInstanceData__global_0_0.value;
		trainEngineInstanceData__global_0_0_copy_engineInstance3_local.status = FOREC_SHARED_UNMODIFIED;
		//--------------------------------------------------------------

		instance__engineInstance3_0_0 = 3;
		threadName__engineInstance3_0_0 = "engineInstance3";
		trainEngineType__engineInstance3_0_0 = -1;

		while (true) {
			while (!forec_intern_input_train_engine_instance_3__global_0_0.value.grab) {
				// pause;
				// Write the local copy of shared variables back to their global copy.
				forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3 = forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local;
				trainEngineInstanceData__global_0_0_copy_engineInstance3 = trainEngineInstanceData__global_0_0_copy_engineInstance3_local;
				// forec:statement:pause:pause11:start
				engineInstance3__thread.programCounter = &&pause11;
				goto *engineInstance3__thread.nextThread -> programCounter;
				pause11:;
				// forec:statement:pause:pause11:end
				// Update the values of the used shared variables from their global copy.
				forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local = forec_intern_output_train_engine_instance_3__global_0_0;
				LOG_NOTICE__global_0_0_copy_engineInstance3_local = LOG_NOTICE__global_0_0;
				trainEngineInstanceData__global_0_0_copy_engineInstance3_local = trainEngineInstanceData__global_0_0;

			}

			trainEngineType__engineInstance3_0_0 = forec_intern_input_train_engine_instance_3__global_0_0.value.train_engine_type;
			forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local.value.in_use = true;
			forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local.status = FOREC_SHARED_MODIFIED;
			dynlib_reset(&trainEngines__global_0_0.value[trainEngineType__engineInstance3_0_0], &trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0]);
			dynlib_tick(&trainEngines__global_0_0.value[trainEngineType__engineInstance3_0_0], &trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0]);
			syslog_server(LOG_NOTICE__global_0_0_copy_engineInstance3_local.value, "%s: Reset container  %d %d -> %d %d", threadName__engineInstance3_0_0, trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0].requested_speed, trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0].requested_forwards, trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0].nominal_speed, trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0].nominal_forwards);

			while (!forec_intern_input_train_engine_instance_3__global_0_0.value.release) {
				trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0].requested_speed = forec_intern_input_train_engine_instance_3__global_0_0.value.requested_speed;
				trainEngineInstanceData__global_0_0_copy_engineInstance3_local.status = FOREC_SHARED_MODIFIED;
				trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0].requested_forwards = forec_intern_input_train_engine_instance_3__global_0_0.value.requested_forwards;
				trainEngineInstanceData__global_0_0_copy_engineInstance3_local.status = FOREC_SHARED_MODIFIED;
				dynlib_tick(&trainEngines__global_0_0.value[trainEngineType__engineInstance3_0_0], &trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0]);
				if (trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0].nominal_speed != forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local.value.nominal_speed || trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0].nominal_forwards != forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local.value.nominal_forwards) {
					syslog_server(LOG_NOTICE__global_0_0_copy_engineInstance3_local.value, "%s: %s.tick()  %d %d -> %d %d", threadName__engineInstance3_0_0, trainEngines__global_0_0.value[trainEngineType__engineInstance3_0_0].name, trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0].requested_speed, trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0].requested_forwards, trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0].nominal_speed, trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0].nominal_forwards);
					forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local.value.nominal_speed = trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0].nominal_speed;
					forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local.status = FOREC_SHARED_MODIFIED;
					forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local.value.nominal_forwards = trainEngineInstanceData__global_0_0_copy_engineInstance3_local.value[instance__engineInstance3_0_0].nominal_forwards;
					forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local.status = FOREC_SHARED_MODIFIED;
				} else {
					// if17
				}

				// pause;
				// Write the local copy of shared variables back to their global copy.
				forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3 = forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local;
				trainEngineInstanceData__global_0_0_copy_engineInstance3 = trainEngineInstanceData__global_0_0_copy_engineInstance3_local;
				// forec:statement:pause:pause12:start
				engineInstance3__thread.programCounter = &&pause12;
				goto *engineInstance3__thread.nextThread -> programCounter;
				pause12:;
				// forec:statement:pause:pause12:end
				// Update the values of the used shared variables from their global copy.
				forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local = forec_intern_output_train_engine_instance_3__global_0_0;
				LOG_NOTICE__global_0_0_copy_engineInstance3_local = LOG_NOTICE__global_0_0;
				trainEngineInstanceData__global_0_0_copy_engineInstance3_local = trainEngineInstanceData__global_0_0;

			}

			trainEngineType__engineInstance3_0_0 = -1;
			forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local.value.in_use = false;
			forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local.status = FOREC_SHARED_MODIFIED;
			syslog_server(LOG_NOTICE__global_0_0_copy_engineInstance3_local.value, "%s: Released container", threadName__engineInstance3_0_0);

			// pause;
			// Write the local copy of shared variables back to their global copy.
			forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3 = forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local;
			trainEngineInstanceData__global_0_0_copy_engineInstance3 = trainEngineInstanceData__global_0_0_copy_engineInstance3_local;
			// forec:statement:pause:pause13:start
			engineInstance3__thread.programCounter = &&pause13;
			goto *engineInstance3__thread.nextThread -> programCounter;
			pause13:;
			// forec:statement:pause:pause13:end
			// Update the values of the used shared variables from their global copy.
			forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local = forec_intern_output_train_engine_instance_3__global_0_0;
			LOG_NOTICE__global_0_0_copy_engineInstance3_local = LOG_NOTICE__global_0_0;
			trainEngineInstanceData__global_0_0_copy_engineInstance3_local = trainEngineInstanceData__global_0_0;

		}

		//--------------------------------------------------------------
		// Write the defined shared variables back to their global copy.
		forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3 = forec_intern_output_train_engine_instance_3__global_0_0_copy_engineInstance3_local;
		trainEngineInstanceData__global_0_0_copy_engineInstance3 = trainEngineInstanceData__global_0_0_copy_engineInstance3_local;

		// forec:scheduler:threadRemove:engineInstance3:start

		// Delete thread from the linked list and core.
		mainParCore2.activeThreads--;
		engineInstance3__thread.nextThread -> prevThread = engineInstance3__thread.prevThread;
		engineInstance3__thread.prevThread -> nextThread = engineInstance3__thread.nextThread;
		goto *engineInstance3__thread.nextThread -> programCounter;
		// forec:scheduler:threadRemove:engineInstance3:end
	} // engineInstance3__thread
	// forec:thread:engineInstance3:end

	// forec:thread:engineInstance4:start
	/*--------------------------------------------------------------
	| Thread engineInstance4
	*-------------------------------------------------------------*/

	// Thread local declarations -----------------------------------
	Shared_forec_intern_output_train_engine_instance_4__global_0_0 forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local;
	Shared_LOG_NOTICE__global_0_0 LOG_NOTICE__global_0_0_copy_engineInstance4_local;
	Shared_trainEngineInstanceData__global_0_0 trainEngineInstanceData__global_0_0_copy_engineInstance4_local;
	unsigned int instance__engineInstance4_0_0;
	const char *threadName__engineInstance4_0_0;
	int trainEngineType__engineInstance4_0_0;

	// Thread body -------------------------------------------------
	engineInstance4__thread: {
		// Initialise the local copies of shared variables.
		forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local.value = forec_intern_output_train_engine_instance_4__global_0_0.value;
		forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local.status = FOREC_SHARED_UNMODIFIED;
		LOG_NOTICE__global_0_0_copy_engineInstance4_local.value = LOG_NOTICE__global_0_0.value;
		LOG_NOTICE__global_0_0_copy_engineInstance4_local.status = FOREC_SHARED_UNMODIFIED;
		trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value = trainEngineInstanceData__global_0_0.value;
		trainEngineInstanceData__global_0_0_copy_engineInstance4_local.status = FOREC_SHARED_UNMODIFIED;
		//--------------------------------------------------------------

		instance__engineInstance4_0_0 = 4;
		threadName__engineInstance4_0_0 = "engineInstance4";
		trainEngineType__engineInstance4_0_0 = -1;

		while (true) {
			while (!forec_intern_input_train_engine_instance_4__global_0_0.value.grab) {
				// pause;
				// Write the local copy of shared variables back to their global copy.
				forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4 = forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local;
				trainEngineInstanceData__global_0_0_copy_engineInstance4 = trainEngineInstanceData__global_0_0_copy_engineInstance4_local;
				// forec:statement:pause:pause14:start
				engineInstance4__thread.programCounter = &&pause14;
				goto *engineInstance4__thread.nextThread -> programCounter;
				pause14:;
				// forec:statement:pause:pause14:end
				// Update the values of the used shared variables from their global copy.
				forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local = forec_intern_output_train_engine_instance_4__global_0_0;
				LOG_NOTICE__global_0_0_copy_engineInstance4_local = LOG_NOTICE__global_0_0;
				trainEngineInstanceData__global_0_0_copy_engineInstance4_local = trainEngineInstanceData__global_0_0;

			}

			trainEngineType__engineInstance4_0_0 = forec_intern_input_train_engine_instance_4__global_0_0.value.train_engine_type;
			forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local.value.in_use = true;
			forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local.status = FOREC_SHARED_MODIFIED;
			dynlib_reset(&trainEngines__global_0_0.value[trainEngineType__engineInstance4_0_0], &trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0]);
			dynlib_tick(&trainEngines__global_0_0.value[trainEngineType__engineInstance4_0_0], &trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0]);
			syslog_server(LOG_NOTICE__global_0_0_copy_engineInstance4_local.value, "%s: Reset container  %d %d -> %d %d", threadName__engineInstance4_0_0, trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0].requested_speed, trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0].requested_forwards, trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0].nominal_speed, trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0].nominal_forwards);

			while (!forec_intern_input_train_engine_instance_4__global_0_0.value.release) {
				trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0].requested_speed = forec_intern_input_train_engine_instance_4__global_0_0.value.requested_speed;
				trainEngineInstanceData__global_0_0_copy_engineInstance4_local.status = FOREC_SHARED_MODIFIED;
				trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0].requested_forwards = forec_intern_input_train_engine_instance_4__global_0_0.value.requested_forwards;
				trainEngineInstanceData__global_0_0_copy_engineInstance4_local.status = FOREC_SHARED_MODIFIED;
				dynlib_tick(&trainEngines__global_0_0.value[trainEngineType__engineInstance4_0_0], &trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0]);
				if (trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0].nominal_speed != forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local.value.nominal_speed || trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0].nominal_forwards != forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local.value.nominal_forwards) {
					syslog_server(LOG_NOTICE__global_0_0_copy_engineInstance4_local.value, "%s: %s.tick()  %d %d -> %d %d", threadName__engineInstance4_0_0, trainEngines__global_0_0.value[trainEngineType__engineInstance4_0_0].name, trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0].requested_speed, trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0].requested_forwards, trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0].nominal_speed, trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0].nominal_forwards);
					forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local.value.nominal_speed = trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0].nominal_speed;
					forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local.status = FOREC_SHARED_MODIFIED;
					forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local.value.nominal_forwards = trainEngineInstanceData__global_0_0_copy_engineInstance4_local.value[instance__engineInstance4_0_0].nominal_forwards;
					forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local.status = FOREC_SHARED_MODIFIED;
				} else {
					// if18
				}

				// pause;
				// Write the local copy of shared variables back to their global copy.
				forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4 = forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local;
				trainEngineInstanceData__global_0_0_copy_engineInstance4 = trainEngineInstanceData__global_0_0_copy_engineInstance4_local;
				// forec:statement:pause:pause15:start
				engineInstance4__thread.programCounter = &&pause15;
				goto *engineInstance4__thread.nextThread -> programCounter;
				pause15:;
				// forec:statement:pause:pause15:end
				// Update the values of the used shared variables from their global copy.
				forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local = forec_intern_output_train_engine_instance_4__global_0_0;
				LOG_NOTICE__global_0_0_copy_engineInstance4_local = LOG_NOTICE__global_0_0;
				trainEngineInstanceData__global_0_0_copy_engineInstance4_local = trainEngineInstanceData__global_0_0;

			}

			trainEngineType__engineInstance4_0_0 = -1;
			forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local.value.in_use = false;
			forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local.status = FOREC_SHARED_MODIFIED;
			syslog_server(LOG_NOTICE__global_0_0_copy_engineInstance4_local.value, "%s: Released container", threadName__engineInstance4_0_0);

			// pause;
			// Write the local copy of shared variables back to their global copy.
			forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4 = forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local;
			trainEngineInstanceData__global_0_0_copy_engineInstance4 = trainEngineInstanceData__global_0_0_copy_engineInstance4_local;
			// forec:statement:pause:pause16:start
			engineInstance4__thread.programCounter = &&pause16;
			goto *engineInstance4__thread.nextThread -> programCounter;
			pause16:;
			// forec:statement:pause:pause16:end
			// Update the values of the used shared variables from their global copy.
			forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local = forec_intern_output_train_engine_instance_4__global_0_0;
			LOG_NOTICE__global_0_0_copy_engineInstance4_local = LOG_NOTICE__global_0_0;
			trainEngineInstanceData__global_0_0_copy_engineInstance4_local = trainEngineInstanceData__global_0_0;

		}

		//--------------------------------------------------------------
		// Write the defined shared variables back to their global copy.
		forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4 = forec_intern_output_train_engine_instance_4__global_0_0_copy_engineInstance4_local;
		trainEngineInstanceData__global_0_0_copy_engineInstance4 = trainEngineInstanceData__global_0_0_copy_engineInstance4_local;

		// forec:scheduler:threadRemove:engineInstance4:start

		// Delete thread from the linked list and core.
		mainParCore1.activeThreads--;
		engineInstance4__thread.nextThread -> prevThread = engineInstance4__thread.prevThread;
		engineInstance4__thread.prevThread -> nextThread = engineInstance4__thread.nextThread;
		goto *engineInstance4__thread.nextThread -> programCounter;
		// forec:scheduler:threadRemove:engineInstance4:end
	} // engineInstance4__thread
	// forec:thread:engineInstance4:end

	// forec:thread:interlockerInstance0:start
	/*--------------------------------------------------------------
	| Thread interlockerInstance0
	*-------------------------------------------------------------*/

	// Thread local declarations -----------------------------------
	// No declarations.

	// Thread body -------------------------------------------------
	interlockerInstance0__thread: {
		// No statements found.

		// forec:scheduler:threadRemove:interlockerInstance0:start

		// Delete thread from the linked list and core.
		mainParCore2.activeThreads--;
		interlockerInstance0__thread.nextThread -> prevThread = interlockerInstance0__thread.prevThread;
		interlockerInstance0__thread.prevThread -> nextThread = interlockerInstance0__thread.nextThread;
		goto *interlockerInstance0__thread.nextThread -> programCounter;
		// forec:scheduler:threadRemove:interlockerInstance0:end
	} // interlockerInstance0__thread
	// forec:thread:interlockerInstance0:end

	// forec:thread:interlockerInstance1:start
	/*--------------------------------------------------------------
	| Thread interlockerInstance1
	*-------------------------------------------------------------*/

	// Thread local declarations -----------------------------------
	// No declarations.

	// Thread body -------------------------------------------------
	interlockerInstance1__thread: {
		// No statements found.

		// forec:scheduler:threadRemove:interlockerInstance1:start

		// Delete thread from the linked list and core.
		mainParCore1.activeThreads--;
		interlockerInstance1__thread.nextThread -> prevThread = interlockerInstance1__thread.prevThread;
		interlockerInstance1__thread.prevThread -> nextThread = interlockerInstance1__thread.nextThread;
		goto *interlockerInstance1__thread.nextThread -> programCounter;
		// forec:scheduler:threadRemove:interlockerInstance1:end
	} // interlockerInstance1__thread
	// forec:thread:interlockerInstance1:end

	// forec:thread:interlockerInstance2:start
	/*--------------------------------------------------------------
	| Thread interlockerInstance2
	*-------------------------------------------------------------*/

	// Thread local declarations -----------------------------------
	// No declarations.

	// Thread body -------------------------------------------------
	interlockerInstance2__thread: {
		// No statements found.

		// forec:scheduler:threadRemove:interlockerInstance2:start

		// Delete thread from the linked list and core.
		mainParCore2.activeThreads--;
		interlockerInstance2__thread.nextThread -> prevThread = interlockerInstance2__thread.prevThread;
		interlockerInstance2__thread.prevThread -> nextThread = interlockerInstance2__thread.nextThread;
		goto *interlockerInstance2__thread.nextThread -> programCounter;
		// forec:scheduler:threadRemove:interlockerInstance2:end
	} // interlockerInstance2__thread
	// forec:thread:interlockerInstance2:end

	// forec:thread:interlockerInstance3:start
	/*--------------------------------------------------------------
	| Thread interlockerInstance3
	*-------------------------------------------------------------*/

	// Thread local declarations -----------------------------------
	// No declarations.

	// Thread body -------------------------------------------------
	interlockerInstance3__thread: {
		// No statements found.

		// forec:scheduler:threadRemove:interlockerInstance3:start

		// Delete thread from the linked list and core.
		mainParCore1.activeThreads--;
		interlockerInstance3__thread.nextThread -> prevThread = interlockerInstance3__thread.prevThread;
		interlockerInstance3__thread.prevThread -> nextThread = interlockerInstance3__thread.nextThread;
		goto *interlockerInstance3__thread.nextThread -> programCounter;
		// forec:scheduler:threadRemove:interlockerInstance3:end
	} // interlockerInstance3__thread
	// forec:thread:interlockerInstance3:end

	// forec:thread:letInterface:start
	/*--------------------------------------------------------------
	| Thread letInterface
	*-------------------------------------------------------------*/

	// Thread local declarations -----------------------------------
	Shared_forec_intern_input__global_0_0 forec_intern_input__global_0_0_copy_letInterface_local;
	Shared_forec_intern_output_train_engine_0__global_0_0 forec_intern_output_train_engine_0__global_0_0_copy_letInterface_local;
	Shared_forec_intern_output_train_engine_1__global_0_0 forec_intern_output_train_engine_1__global_0_0_copy_letInterface_local;
	Shared_forec_intern_output_train_engine_2__global_0_0 forec_intern_output_train_engine_2__global_0_0_copy_letInterface_local;
	Shared_forec_intern_output_train_engine_3__global_0_0 forec_intern_output_train_engine_3__global_0_0_copy_letInterface_local;
	Shared_forec_intern_output_train_engine_instance_0__global_0_0 forec_intern_output_train_engine_instance_0__global_0_0_copy_letInterface_local;
	Shared_forec_intern_output_train_engine_instance_1__global_0_0 forec_intern_output_train_engine_instance_1__global_0_0_copy_letInterface_local;
	Shared_forec_intern_output_train_engine_instance_2__global_0_0 forec_intern_output_train_engine_instance_2__global_0_0_copy_letInterface_local;
	Shared_forec_intern_output_train_engine_instance_3__global_0_0 forec_intern_output_train_engine_instance_3__global_0_0_copy_letInterface_local;
	Shared_forec_intern_output_train_engine_instance_4__global_0_0 forec_intern_output_train_engine_instance_4__global_0_0_copy_letInterface_local;
	Shared_dyn_containers_interface__global_0_0 dyn_containers_interface__global_0_0_copy_letInterface_local;
	char *threadName__letInterface_0_0;

	// Thread body -------------------------------------------------
	letInterface__thread: {
		// Initialise the local copies of shared variables.
		forec_intern_input__global_0_0_copy_letInterface_local.value = forec_intern_input__global_0_0.value;
		forec_intern_input__global_0_0_copy_letInterface_local.status = FOREC_SHARED_UNMODIFIED;
		forec_intern_output_train_engine_0__global_0_0_copy_letInterface_local.value = forec_intern_output_train_engine_0__global_0_0.value;
		forec_intern_output_train_engine_0__global_0_0_copy_letInterface_local.status = FOREC_SHARED_UNMODIFIED;
		forec_intern_output_train_engine_1__global_0_0_copy_letInterface_local.value = forec_intern_output_train_engine_1__global_0_0.value;
		forec_intern_output_train_engine_1__global_0_0_copy_letInterface_local.status = FOREC_SHARED_UNMODIFIED;
		forec_intern_output_train_engine_2__global_0_0_copy_letInterface_local.value = forec_intern_output_train_engine_2__global_0_0.value;
		forec_intern_output_train_engine_2__global_0_0_copy_letInterface_local.status = FOREC_SHARED_UNMODIFIED;
		forec_intern_output_train_engine_3__global_0_0_copy_letInterface_local.value = forec_intern_output_train_engine_3__global_0_0.value;
		forec_intern_output_train_engine_3__global_0_0_copy_letInterface_local.status = FOREC_SHARED_UNMODIFIED;
		forec_intern_output_train_engine_instance_0__global_0_0_copy_letInterface_local.value = forec_intern_output_train_engine_instance_0__global_0_0.value;
		forec_intern_output_train_engine_instance_0__global_0_0_copy_letInterface_local.status = FOREC_SHARED_UNMODIFIED;
		forec_intern_output_train_engine_instance_1__global_0_0_copy_letInterface_local.value = forec_intern_output_train_engine_instance_1__global_0_0.value;
		forec_intern_output_train_engine_instance_1__global_0_0_copy_letInterface_local.status = FOREC_SHARED_UNMODIFIED;
		forec_intern_output_train_engine_instance_2__global_0_0_copy_letInterface_local.value = forec_intern_output_train_engine_instance_2__global_0_0.value;
		forec_intern_output_train_engine_instance_2__global_0_0_copy_letInterface_local.status = FOREC_SHARED_UNMODIFIED;
		forec_intern_output_train_engine_instance_3__global_0_0_copy_letInterface_local.value = forec_intern_output_train_engine_instance_3__global_0_0.value;
		forec_intern_output_train_engine_instance_3__global_0_0_copy_letInterface_local.status = FOREC_SHARED_UNMODIFIED;
		forec_intern_output_train_engine_instance_4__global_0_0_copy_letInterface_local.value = forec_intern_output_train_engine_instance_4__global_0_0.value;
		forec_intern_output_train_engine_instance_4__global_0_0_copy_letInterface_local.status = FOREC_SHARED_UNMODIFIED;
		dyn_containers_interface__global_0_0_copy_letInterface_local.value = dyn_containers_interface__global_0_0.value;
		dyn_containers_interface__global_0_0_copy_letInterface_local.status = FOREC_SHARED_UNMODIFIED;
		//--------------------------------------------------------------

		threadName__letInterface_0_0 = "letInterface";
		pthread_mutex_lock(&dyn_containers_mutex__global_0_0);
		forec_intern_input__global_0_0_copy_letInterface_local.value.let_period_us = dyn_containers_interface__global_0_0_copy_letInterface_local.value->let_period_us;
		forec_intern_input__global_0_0_copy_letInterface_local.status = FOREC_SHARED_MODIFIED;
		pthread_mutex_unlock(&dyn_containers_mutex__global_0_0);

		while (true) {
			pthread_mutex_lock(&dyn_containers_mutex__global_0_0);
			forec_intern_input__global_0_0_copy_letInterface_local.value.terminate = dyn_containers_interface__global_0_0_copy_letInterface_local.value->terminate;
			forec_intern_input__global_0_0_copy_letInterface_local.status = FOREC_SHARED_MODIFIED;
			copyEngineInputs(&forec_intern_input_train_engine_0__global_0_0.value, &dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engines_io[0]);
			copyEngineInputs(&forec_intern_input_train_engine_1__global_0_0.value, &dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engines_io[1]);
			copyEngineInputs(&forec_intern_input_train_engine_2__global_0_0.value, &dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engines_io[2]);
			copyEngineInputs(&forec_intern_input_train_engine_3__global_0_0.value, &dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engines_io[3]);
			copyEngineInstanceInputs(&forec_intern_input_train_engine_instance_0__global_0_0.value, &dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engine_instances_io[0]);
			copyEngineInstanceInputs(&forec_intern_input_train_engine_instance_1__global_0_0.value, &dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engine_instances_io[1]);
			copyEngineInstanceInputs(&forec_intern_input_train_engine_instance_2__global_0_0.value, &dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engine_instances_io[2]);
			copyEngineInstanceInputs(&forec_intern_input_train_engine_instance_3__global_0_0.value, &dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engine_instances_io[3]);
			copyEngineInstanceInputs(&forec_intern_input_train_engine_instance_4__global_0_0.value, &dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engine_instances_io[4]);
			pthread_mutex_unlock(&dyn_containers_mutex__global_0_0);
			usleep(forec_intern_input__global_0_0_copy_letInterface_local.value.let_period_us);
			pthread_mutex_lock(&dyn_containers_mutex__global_0_0);
			copyEngineOutputs(&dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engines_io[0], &forec_intern_output_train_engine_0__global_0_0_copy_letInterface_local.value);
			copyEngineOutputs(&dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engines_io[1], &forec_intern_output_train_engine_1__global_0_0_copy_letInterface_local.value);
			copyEngineOutputs(&dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engines_io[2], &forec_intern_output_train_engine_2__global_0_0_copy_letInterface_local.value);
			copyEngineOutputs(&dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engines_io[3], &forec_intern_output_train_engine_3__global_0_0_copy_letInterface_local.value);
			copyEngineInstanceOutputs(&dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engine_instances_io[0], &forec_intern_output_train_engine_instance_0__global_0_0_copy_letInterface_local.value);
			copyEngineInstanceOutputs(&dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engine_instances_io[1], &forec_intern_output_train_engine_instance_1__global_0_0_copy_letInterface_local.value);
			copyEngineInstanceOutputs(&dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engine_instances_io[2], &forec_intern_output_train_engine_instance_2__global_0_0_copy_letInterface_local.value);
			copyEngineInstanceOutputs(&dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engine_instances_io[3], &forec_intern_output_train_engine_instance_3__global_0_0_copy_letInterface_local.value);
			copyEngineInstanceOutputs(&dyn_containers_interface__global_0_0_copy_letInterface_local.value->train_engine_instances_io[4], &forec_intern_output_train_engine_instance_4__global_0_0_copy_letInterface_local.value);
			pthread_mutex_unlock(&dyn_containers_mutex__global_0_0);

			// pause;
			// Write the local copy of shared variables back to their global copy.
			forec_intern_input__global_0_0_copy_letInterface = forec_intern_input__global_0_0_copy_letInterface_local;
			// forec:statement:pause:pause0:start
			letInterface__thread.programCounter = &&pause0;
			goto *letInterface__thread.nextThread -> programCounter;
			pause0:;
			// forec:statement:pause:pause0:end
			// Update the values of the used shared variables from their global copy.
			forec_intern_input__global_0_0_copy_letInterface_local = forec_intern_input__global_0_0;
			forec_intern_output_train_engine_0__global_0_0_copy_letInterface_local = forec_intern_output_train_engine_0__global_0_0;
			forec_intern_output_train_engine_1__global_0_0_copy_letInterface_local = forec_intern_output_train_engine_1__global_0_0;
			forec_intern_output_train_engine_2__global_0_0_copy_letInterface_local = forec_intern_output_train_engine_2__global_0_0;
			forec_intern_output_train_engine_3__global_0_0_copy_letInterface_local = forec_intern_output_train_engine_3__global_0_0;
			forec_intern_output_train_engine_instance_0__global_0_0_copy_letInterface_local = forec_intern_output_train_engine_instance_0__global_0_0;
			forec_intern_output_train_engine_instance_1__global_0_0_copy_letInterface_local = forec_intern_output_train_engine_instance_1__global_0_0;
			forec_intern_output_train_engine_instance_2__global_0_0_copy_letInterface_local = forec_intern_output_train_engine_instance_2__global_0_0;
			forec_intern_output_train_engine_instance_3__global_0_0_copy_letInterface_local = forec_intern_output_train_engine_instance_3__global_0_0;
			forec_intern_output_train_engine_instance_4__global_0_0_copy_letInterface_local = forec_intern_output_train_engine_instance_4__global_0_0;
			dyn_containers_interface__global_0_0_copy_letInterface_local = dyn_containers_interface__global_0_0;

		}

		//--------------------------------------------------------------
		// Write the defined shared variables back to their global copy.
		forec_intern_input__global_0_0_copy_letInterface = forec_intern_input__global_0_0_copy_letInterface_local;

		// forec:scheduler:threadRemove:letInterface:start

		// Delete thread from the linked list and core.
		mainParCore0.activeThreads--;
		letInterface__thread.nextThread -> prevThread = letInterface__thread.prevThread;
		letInterface__thread.prevThread -> nextThread = letInterface__thread.nextThread;
		goto *letInterface__thread.nextThread -> programCounter;
		// forec:scheduler:threadRemove:letInterface:end
	} // letInterface__thread
	// forec:thread:letInterface:end

	// forec:thread:loadEngines:start
	/*--------------------------------------------------------------
	| Thread loadEngines
	*-------------------------------------------------------------*/

	// Thread local declarations -----------------------------------
	Shared_forec_intern_output_train_engine_0__global_0_0 forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local;
	Shared_forec_intern_output_train_engine_1__global_0_0 forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local;
	Shared_forec_intern_output_train_engine_2__global_0_0 forec_intern_output_train_engine_2__global_0_0_copy_loadEngines_local;
	Shared_forec_intern_output_train_engine_3__global_0_0 forec_intern_output_train_engine_3__global_0_0_copy_loadEngines_local;
	const char *threadName__loadEngines_0_0;
	dynlib_status__global_0_0 load_status__loadEngines_0_0;
	unsigned int container__loadEngines_1_2;
	dynlib_status__global_0_0 load_status__loadEngines_2_0;
	dynlib_status__global_0_0 load_status__loadEngines_2_1;
	dynlib_status__global_0_0 load_status__loadEngines_2_2;
	dynlib_status__global_0_0 load_status__loadEngines_2_3;

	// Thread body -------------------------------------------------
	loadEngines__thread: {
		// Initialise the local copies of shared variables.
		forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local.value = forec_intern_output_train_engine_0__global_0_0.value;
		forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_UNMODIFIED;
		forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local.value = forec_intern_output_train_engine_1__global_0_0.value;
		forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_UNMODIFIED;
		forec_intern_output_train_engine_2__global_0_0_copy_loadEngines_local.value = forec_intern_output_train_engine_2__global_0_0.value;
		forec_intern_output_train_engine_2__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_UNMODIFIED;
		forec_intern_output_train_engine_3__global_0_0_copy_loadEngines_local.value = forec_intern_output_train_engine_3__global_0_0.value;
		forec_intern_output_train_engine_3__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_UNMODIFIED;
		//--------------------------------------------------------------

		threadName__loadEngines_0_0 = "loadEngines";
		load_status__loadEngines_0_0 = dynlib_load(&trainEngines__global_0_0.value[0], trainEngineFilepaths__global_0_0[0]);
		printout(threadName__loadEngines_0_0, load_status__loadEngines_0_0, &trainEngines__global_0_0.value[0]);
		if (load_status__loadEngines_0_0 == DYNLIB_LOAD_SUCCESS__global_0_0) {
			forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local.value.in_use = true;
			forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_MODIFIED;
			copyFilename(trainEngines__global_0_0.value[0].name, trainEngineFilepaths__global_0_0[0], NAME_MAX__global_0_0, PATH_MAX__global_0_0 + NAME_MAX__global_0_0);
			forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local.value.name = trainEngines__global_0_0.value[0].name;
			forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_MODIFIED;
		} else {
			// if0
		}
		load_status__loadEngines_0_0 = dynlib_load(&trainEngines__global_0_0.value[1], trainEngineFilepaths__global_0_0[1]);
		printout(threadName__loadEngines_0_0, load_status__loadEngines_0_0, &trainEngines__global_0_0.value[1]);
		if (load_status__loadEngines_0_0 == DYNLIB_LOAD_SUCCESS__global_0_0) {
			forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local.value.in_use = true;
			forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_MODIFIED;
			copyFilename(trainEngines__global_0_0.value[1].name, trainEngineFilepaths__global_0_0[1], NAME_MAX__global_0_0, PATH_MAX__global_0_0 + NAME_MAX__global_0_0);
			forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local.value.name = trainEngines__global_0_0.value[1].name;
			forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_MODIFIED;
		} else {
			// if1
		}

		while (true) {
			container__loadEngines_1_2 = 0;
			if (forec_intern_input_train_engine_0__global_0_0.value.load && !forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local.value.in_use) {
				load_status__loadEngines_2_0 = dynlib_load(&trainEngines__global_0_0.value[container__loadEngines_1_2], forec_intern_input_train_engine_0__global_0_0.value.filepath);
				printout(threadName__loadEngines_0_0, load_status__loadEngines_2_0, &trainEngines__global_0_0.value[container__loadEngines_1_2]);
				if (load_status__loadEngines_2_0 == DYNLIB_LOAD_SUCCESS__global_0_0) {
					forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local.value.in_use = true;
					forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_MODIFIED;
					copyFilename(trainEngines__global_0_0.value[container__loadEngines_1_2].name, forec_intern_input_train_engine_0__global_0_0.value.filepath, NAME_MAX__global_0_0, PATH_MAX__global_0_0 + NAME_MAX__global_0_0);
					forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local.value.name = trainEngines__global_0_0.value[container__loadEngines_1_2].name;
					forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_MODIFIED;
				} else {
					// if2
				}
			} else {
				// ifElse4
				if (forec_intern_input_train_engine_0__global_0_0.value.unload) {
					dynlib_close(&trainEngines__global_0_0.value[container__loadEngines_1_2]);
					forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local.value.in_use = false;
					forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_MODIFIED;
				} else {
					// if3
				}
			}
			container__loadEngines_1_2 = 1;
			if (forec_intern_input_train_engine_1__global_0_0.value.load && !forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local.value.in_use) {
				load_status__loadEngines_2_1 = dynlib_load(&trainEngines__global_0_0.value[container__loadEngines_1_2], forec_intern_input_train_engine_1__global_0_0.value.filepath);
				printout(threadName__loadEngines_0_0, load_status__loadEngines_2_1, &trainEngines__global_0_0.value[container__loadEngines_1_2]);
				if (load_status__loadEngines_2_1 == DYNLIB_LOAD_SUCCESS__global_0_0) {
					forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local.value.in_use = true;
					forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_MODIFIED;
					copyFilename(trainEngines__global_0_0.value[container__loadEngines_1_2].name, forec_intern_input_train_engine_1__global_0_0.value.filepath, NAME_MAX__global_0_0, PATH_MAX__global_0_0 + NAME_MAX__global_0_0);
					forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local.value.name = trainEngines__global_0_0.value[container__loadEngines_1_2].name;
					forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_MODIFIED;
				} else {
					// if5
				}
			} else {
				// ifElse7
				if (forec_intern_input_train_engine_1__global_0_0.value.unload) {
					dynlib_close(&trainEngines__global_0_0.value[container__loadEngines_1_2]);
					forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local.value.in_use = false;
					forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_MODIFIED;
				} else {
					// if6
				}
			}
			container__loadEngines_1_2 = 2;
			if (forec_intern_input_train_engine_2__global_0_0.value.load && !forec_intern_output_train_engine_2__global_0_0_copy_loadEngines_local.value.in_use) {
				load_status__loadEngines_2_2 = dynlib_load(&trainEngines__global_0_0.value[container__loadEngines_1_2], forec_intern_input_train_engine_2__global_0_0.value.filepath);
				printout(threadName__loadEngines_0_0, load_status__loadEngines_2_2, &trainEngines__global_0_0.value[container__loadEngines_1_2]);
				if (load_status__loadEngines_2_2 == DYNLIB_LOAD_SUCCESS__global_0_0) {
					forec_intern_output_train_engine_2__global_0_0_copy_loadEngines_local.value.in_use = true;
					forec_intern_output_train_engine_2__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_MODIFIED;
					copyFilename(trainEngines__global_0_0.value[container__loadEngines_1_2].name, forec_intern_input_train_engine_2__global_0_0.value.filepath, NAME_MAX__global_0_0, PATH_MAX__global_0_0 + NAME_MAX__global_0_0);
					forec_intern_output_train_engine_2__global_0_0_copy_loadEngines_local.value.name = trainEngines__global_0_0.value[container__loadEngines_1_2].name;
					forec_intern_output_train_engine_2__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_MODIFIED;
				} else {
					// if8
				}
			} else {
				// ifElse10
				if (forec_intern_input_train_engine_2__global_0_0.value.unload) {
					dynlib_close(&trainEngines__global_0_0.value[container__loadEngines_1_2]);
					forec_intern_output_train_engine_2__global_0_0_copy_loadEngines_local.value.in_use = false;
					forec_intern_output_train_engine_2__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_MODIFIED;
				} else {
					// if9
				}
			}
			container__loadEngines_1_2 = 3;
			if (forec_intern_input_train_engine_3__global_0_0.value.load && !forec_intern_output_train_engine_3__global_0_0_copy_loadEngines_local.value.in_use) {
				load_status__loadEngines_2_3 = dynlib_load(&trainEngines__global_0_0.value[container__loadEngines_1_2], forec_intern_input_train_engine_3__global_0_0.value.filepath);
				printout(threadName__loadEngines_0_0, load_status__loadEngines_2_3, &trainEngines__global_0_0.value[container__loadEngines_1_2]);
				if (load_status__loadEngines_2_3 == DYNLIB_LOAD_SUCCESS__global_0_0) {
					forec_intern_output_train_engine_3__global_0_0_copy_loadEngines_local.value.in_use = true;
					forec_intern_output_train_engine_3__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_MODIFIED;
					copyFilename(trainEngines__global_0_0.value[container__loadEngines_1_2].name, forec_intern_input_train_engine_3__global_0_0.value.filepath, NAME_MAX__global_0_0, PATH_MAX__global_0_0 + NAME_MAX__global_0_0);
					forec_intern_output_train_engine_3__global_0_0_copy_loadEngines_local.value.name = trainEngines__global_0_0.value[container__loadEngines_1_2].name;
					forec_intern_output_train_engine_3__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_MODIFIED;
				} else {
					// if11
				}
			} else {
				// ifElse13
				if (forec_intern_input_train_engine_3__global_0_0.value.unload) {
					dynlib_close(&trainEngines__global_0_0.value[container__loadEngines_1_2]);
					forec_intern_output_train_engine_3__global_0_0_copy_loadEngines_local.value.in_use = false;
					forec_intern_output_train_engine_3__global_0_0_copy_loadEngines_local.status = FOREC_SHARED_MODIFIED;
				} else {
					// if12
				}
			}

			// pause;
			// Write the local copy of shared variables back to their global copy.
			forec_intern_output_train_engine_0__global_0_0_copy_loadEngines = forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local;
			forec_intern_output_train_engine_1__global_0_0_copy_loadEngines = forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local;
			forec_intern_output_train_engine_2__global_0_0_copy_loadEngines = forec_intern_output_train_engine_2__global_0_0_copy_loadEngines_local;
			forec_intern_output_train_engine_3__global_0_0_copy_loadEngines = forec_intern_output_train_engine_3__global_0_0_copy_loadEngines_local;
			// forec:statement:pause:pause1:start
			loadEngines__thread.programCounter = &&pause1;
			goto *loadEngines__thread.nextThread -> programCounter;
			pause1:;
			// forec:statement:pause:pause1:end
			// Update the values of the used shared variables from their global copy.
			forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local = forec_intern_output_train_engine_0__global_0_0;
			forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local = forec_intern_output_train_engine_1__global_0_0;
			forec_intern_output_train_engine_2__global_0_0_copy_loadEngines_local = forec_intern_output_train_engine_2__global_0_0;
			forec_intern_output_train_engine_3__global_0_0_copy_loadEngines_local = forec_intern_output_train_engine_3__global_0_0;

		}

		//--------------------------------------------------------------
		// Write the defined shared variables back to their global copy.
		forec_intern_output_train_engine_0__global_0_0_copy_loadEngines = forec_intern_output_train_engine_0__global_0_0_copy_loadEngines_local;
		forec_intern_output_train_engine_1__global_0_0_copy_loadEngines = forec_intern_output_train_engine_1__global_0_0_copy_loadEngines_local;
		forec_intern_output_train_engine_2__global_0_0_copy_loadEngines = forec_intern_output_train_engine_2__global_0_0_copy_loadEngines_local;
		forec_intern_output_train_engine_3__global_0_0_copy_loadEngines = forec_intern_output_train_engine_3__global_0_0_copy_loadEngines_local;

		// forec:scheduler:threadRemove:loadEngines:start

		// Delete thread from the linked list and core.
		mainParCore1.activeThreads--;
		loadEngines__thread.nextThread -> prevThread = loadEngines__thread.prevThread;
		loadEngines__thread.prevThread -> nextThread = loadEngines__thread.nextThread;
		goto *loadEngines__thread.nextThread -> programCounter;
		// forec:scheduler:threadRemove:loadEngines:end
	} // loadEngines__thread
	// forec:thread:loadEngines:end

	// forec:thread:loadInterlockers:start
	/*--------------------------------------------------------------
	| Thread loadInterlockers
	*-------------------------------------------------------------*/

	// Thread local declarations -----------------------------------
	// No declarations.

	// Thread body -------------------------------------------------
	loadInterlockers__thread: {
		// No statements found.

		// forec:scheduler:threadRemove:loadInterlockers:start

		// Delete thread from the linked list and core.
		mainParCore2.activeThreads--;
		loadInterlockers__thread.nextThread -> prevThread = loadInterlockers__thread.prevThread;
		loadInterlockers__thread.prevThread -> nextThread = loadInterlockers__thread.nextThread;
		goto *loadInterlockers__thread.nextThread -> programCounter;
		// forec:scheduler:threadRemove:loadInterlockers:end
	} // loadInterlockers__thread
	// forec:thread:loadInterlockers:end


} // End of the main() function.

void copyFilename(char destination__copyFilename_0_0[], const char source__copyFilename_0_0[], const int name_len__copyFilename_0_0, const int path_len__copyFilename_0_0) {
	char source_copy__copyFilename_0_0[path_len__copyFilename_0_0];
	strncpy(source_copy__copyFilename_0_0, source__copyFilename_0_0, path_len__copyFilename_0_0);
	const char *filename__copyFilename_0_0 = basename(source_copy__copyFilename_0_0);
	strncpy(destination__copyFilename_0_0, filename__copyFilename_0_0, name_len__copyFilename_0_0);
}

void copyEngineInputs(t_forec_intern_input_train_engine__global_0_0 *internal__copyEngineInputs_0_0, struct t_train_engine_io *external__copyEngineInputs_0_0) {
	internal__copyEngineInputs_0_0->load = external__copyEngineInputs_0_0->input_load;
	internal__copyEngineInputs_0_0->unload = external__copyEngineInputs_0_0->input_unload;
	strncpy(internal__copyEngineInputs_0_0->filepath, external__copyEngineInputs_0_0->input_filepath, PATH_MAX__global_0_0 + NAME_MAX__global_0_0);
}

void copyEngineOutputs(struct t_train_engine_io *external__copyEngineOutputs_0_0, t_forec_intern_output_train_engine__global_0_0 *internal__copyEngineOutputs_0_0) {
	external__copyEngineOutputs_0_0->output_in_use = internal__copyEngineOutputs_0_0->in_use;
	strncpy(external__copyEngineOutputs_0_0->output_name, internal__copyEngineOutputs_0_0->name, NAME_MAX__global_0_0);
}

void copyEngineInstanceInputs(t_forec_intern_input_train_engine_instance__global_0_0 *internal__copyEngineInstanceInputs_0_0, struct t_train_engine_instance_io *external__copyEngineInstanceInputs_0_0) {
	internal__copyEngineInstanceInputs_0_0->grab = external__copyEngineInstanceInputs_0_0->input_grab;
	internal__copyEngineInstanceInputs_0_0->release = external__copyEngineInstanceInputs_0_0->input_release;
	internal__copyEngineInstanceInputs_0_0->train_engine_type = external__copyEngineInstanceInputs_0_0->input_train_engine_type;
	internal__copyEngineInstanceInputs_0_0->requested_speed = external__copyEngineInstanceInputs_0_0->input_requested_speed;
	internal__copyEngineInstanceInputs_0_0->requested_forwards = external__copyEngineInstanceInputs_0_0->input_requested_forwards;
}

void copyEngineInstanceOutputs(struct t_train_engine_instance_io *external__copyEngineInstanceOutputs_0_0, t_forec_intern_output_train_engine_instance__global_0_0 *internal__copyEngineInstanceOutputs_0_0) {
	external__copyEngineInstanceOutputs_0_0->output_in_use = internal__copyEngineInstanceOutputs_0_0->in_use;
	external__copyEngineInstanceOutputs_0_0->output_nominal_speed = internal__copyEngineInstanceOutputs_0_0->nominal_speed;
	external__copyEngineInstanceOutputs_0_0->output_nominal_forwards = internal__copyEngineInstanceOutputs_0_0->nominal_forwards;
}

void unloadEngines(void) {
	for (int i__unloadEngines_1_0 = 0; i__unloadEngines_1_0 < TRAIN_ENGINE_COUNT_MAX__global_0_0; i__unloadEngines_1_0++) {
		dynlib_close(&trainEngines__global_0_0.value[i__unloadEngines_1_0]);
	}
	forec_intern_output_train_engine_0__global_0_0.value.in_use = false;
	forec_intern_output_train_engine_1__global_0_0.value.in_use = false;
	forec_intern_output_train_engine_2__global_0_0.value.in_use = false;
	forec_intern_output_train_engine_3__global_0_0.value.in_use = false;
	forec_intern_output_train_engine_instance_0__global_0_0.value.in_use = false;
	forec_intern_output_train_engine_instance_1__global_0_0.value.in_use = false;
	forec_intern_output_train_engine_instance_2__global_0_0.value.in_use = false;
	forec_intern_output_train_engine_instance_3__global_0_0.value.in_use = false;
	forec_intern_output_train_engine_instance_4__global_0_0.value.in_use = false;
}

void unloadInterlockers(void) {
	for (int i__unloadInterlockers_1_0 = 0; i__unloadInterlockers_1_0 < INTERLOCKER_COUNT_MAX__global_0_0; i__unloadInterlockers_1_0++) {
		dynlib_close(&interlockers__global_0_0[i__unloadInterlockers_1_0]);
	}
	forec_intern_output_interlocker_0__global_0_0.value.in_use = false;
	forec_intern_output_interlocker_1__global_0_0.value.in_use = false;
	forec_intern_output_interlocker_2__global_0_0.value.in_use = false;
	forec_intern_output_interlocker_3__global_0_0.value.in_use = false;
	forec_intern_output_interlocker_instance_0__global_0_0.value.in_use = false;
	forec_intern_output_interlocker_instance_1__global_0_0.value.in_use = false;
	forec_intern_output_interlocker_instance_2__global_0_0.value.in_use = false;
	forec_intern_output_interlocker_instance_3__global_0_0.value.in_use = false;
}

void printout(const char *threadName__printout_0_0, const dynlib_status__global_0_0 status__printout_0_0, const dynlib_data__global_0_0 *library__printout_0_0) {
	switch (status__printout_0_0) {
			
		case (DYNLIB_COMPILE_SUCCESS):
			syslog_server(LOG_NOTICE__global_0_0.value, "%s: Compiled dynamic library '%s'", threadName__printout_0_0, library__printout_0_0->filepath);
			break;
			
		case (DYNLIB_LOAD_SUCCESS):
			syslog_server(LOG_NOTICE__global_0_0.value, "%s: Loaded dynamic library '%s'", threadName__printout_0_0, library__printout_0_0->filepath);
			break;
			
		case (DYNLIB_COMPILE_OBJ_ERR):
			syslog_server(LOG_ERR__global_0_0, "%s: Could not compile library into object file '%s'", threadName__printout_0_0, library__printout_0_0->filepath);
			break;
			
		case (DYNLIB_COMPILE_SHARED_ERR):
			syslog_server(LOG_ERR__global_0_0, "%s: Could not compile library into shared library '%s'", threadName__printout_0_0, library__printout_0_0->filepath);
			break;
			
		case (DYNLIB_LOAD_ERR):
			syslog_server(LOG_ERR__global_0_0, "%s: Could not load the dynamic library '%s'", threadName__printout_0_0, library__printout_0_0->filepath);
			break;
			
		case (DYNLIB_LOAD_RESET_ERR):
			syslog_server(LOG_ERR__global_0_0, "%s: Could not find the address of reset(...) in '%s'", threadName__printout_0_0, library__printout_0_0->filepath);
			break;
			
		case (DYNLIB_LOAD_TICK_ERR):
			syslog_server(LOG_ERR__global_0_0, "%s: Could not find the address of tick(...) in '%s'", threadName__printout_0_0, library__printout_0_0->filepath);
			break;
			
		default:
			syslog_server(LOG_ERR__global_0_0, "%s: Unknown error %d in '%s'", threadName__printout_0_0, status__printout_0_0, library__printout_0_0->filepath);
			break;
	}
}

TickData__global_0_0 *keepOneCombine(TickData__global_0_0 *left__keepOneCombine_0_0[], TickData__global_0_0 *right__keepOneCombine_0_0[]) {
	return * left__keepOneCombine_0_0;
}

