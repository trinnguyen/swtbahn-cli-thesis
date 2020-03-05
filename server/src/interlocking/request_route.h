/*
 * Automatically generated C code by
 * KIELER SCCharts - The Key to Efficient Modeling
 *
 * http://rtsys.informatik.uni-kiel.de/kieler
 */

#ifndef _REQUEST_ROUTE_H_
#define _REQUEST_ROUTE_H_

// The chosen scheduling regime (IUR) uses four states to maintain the status of threads.
typedef enum {
    TERMINATED,       // thread is dead until spawned again (e.g. via fork)
    RUNNING,          // thread is running
    READY,            // thread is waiting to be selected as running
    PAUSING           // thread is paused for this tick instance
} ThreadStatus;

// The interface of the program is used to communicate with the surrounding environment.
typedef struct {
    char* src_signal_id;                                 // Input
    char* dst_signal_id;                                 // Input
    char* train_id;                                      // Input
    char* out;                                           // Output
    char* route_ids[1024];
    int count_routes;
    char* id;
    char is_grantable;
    int _taken_transitions[20];
    char _request_route_local_is_clear;
    char _request_route_local_success;
    char* _request_route_local_point_ids[1024];
    int _request_route_local_points_count;
    int _request_route_local_i;
    char* _request_route_local__src_signal_id_;
    char _request_route_local_success2;
    char _request_route_local__Tterm;
    char* _request_route_local_point_id;
    char* _request_route_local_point_position;
    char _request_route_local_success1;
    char _request_route_local_result;
    char* _request_route_local_src_signal;
    char* _request_route_local_src_state;
    char _request_route_local__Tterm1;
    char _request_route_local__Tterm7;
    char _request_route_local__Tterm2;
    char _request_route_local__Tterm3;
    char* _request_route_local_flank_signals[1024];
    int _request_route_local_flank_signals_count;
    int _request_route_local_i1;
    char _request_route_local__Tterm4;
    char* _request_route_local_flank_signal;
    char* _request_route_local_flank_state;
    char _request_route_local__Tterm5;
    char _request_route_local__Tterm6;
    char _request_route_local__Tterm8;
    char* _request_route_local_segment_ids[1024];
    int _request_route_local_segment_ids_count;
    int _request_route_local_i2;
    char _request_route_local__Tterm9;
    char* _request_route_local_segment_id;
    char _request_route_local_oc;
    char _request_route_local__Tterm10;
    char _request_route_local__Tterm11;
    double _request_route_local_min_len;
    int _request_route_local_i3;
    int _request_route_local_result1;
    char _request_route_local__Tterm12;
    char* _request_route_local_route_id;
    double _request_route_local_len;
    char _request_route_local__Tterm13;
    char _request_route_local__Tterm14;
    char* _request_route_local__train_id_;
    char* _request_route_local_conflict_routes[1024];
    int _request_route_local_count_conflict_routes;
    int _request_route_local_i4;
    char _request_route_local_result2;
    char _request_route_local__Tterm15;
    char* _request_route_local_conflict_route_id;
    char* _request_route_local_conflict_train_id;
    char _request_route_local__Tterm16;
    char _request_route_local__Tterm17;
} Iface;

// This enum contains all states of the TickData region,
// namely _ARun161, finalState1.
typedef enum {
    _ARUN161, FINALSTATE1
} region_ACtrl16State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl16State activeState;                                                                                  // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl16Context;

// This enum contains all states of the TickData region,
// namely _ARun171, finalState2.
typedef enum {
    _ARUN171, FINALSTATE2
} region_ACtrl17State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl17State activeState;                                                                                  // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl17Context;

// This enum contains all states of the TickData region,
// namely _ARun181, finalState3.
typedef enum {
    _ARUN181, FINALSTATE3
} region_ACtrl18State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl18State activeState;                                                                                  // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl18Context;

// This enum contains all states of the TickData region,
// namely S3_0_2_1_01, __sd_Depth58, __te_S32, finalState5.
typedef enum {
    S3_0_2_1_01, __SD_DEPTH58, __TE_S32, FINALSTATE5
} regionregion4State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    regionregion4State activeState;                                                                                   // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} Region4Context;

// This enum contains all states of the TickData region,
// namely S3_0_2_0, __EA_Init, __EA_Main, _AC18, _Tc, finalState6.
typedef enum {
    S3_0_2_0, __EA_INIT, __EA_MAIN, __EA_MAINRUNNING, _AC18, _TC, FINALSTATE6
} region__EA_Entry14State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region__EA_Entry14State activeState;                                                                              // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
    _ACtrl18Context _actrl18context;
    Region4Context region4context;
} __EA_Entry14Context;

// This enum contains all states of the TickData region,
// namely S3_0_02, S3_0_12, __EA_Init, __EA_Main, _AC17, __sd_Depth61, __te_S34, finalState7.
typedef enum {
    S3_0_02, S3_0_12, __EA_INIT2, __EA_MAIN2, __EA_MAIN2RUNNING, _AC17, __SD_DEPTH61, __TE_S34, FINALSTATE7
} region__EA_Entry13State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region__EA_Entry13State activeState;                                                                              // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
    _ACtrl17Context _actrl17context;
    __EA_Entry14Context __ea_entry14context;
} __EA_Entry13Context;

// This enum contains all states of the TickData region,
// namely _ARun201, finalState8.
typedef enum {
    _ARUN201, FINALSTATE8
} region_ACtrl20State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl20State activeState;                                                                                  // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl20Context;

// This enum contains all states of the TickData region,
// namely _ARun211, finalState9.
typedef enum {
    _ARUN211, FINALSTATE9
} region_ACtrl21State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl21State activeState;                                                                                  // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl21Context;

// This enum contains all states of the TickData region,
// namely _ARun221, finalState10.
typedef enum {
    _ARUN221, FINALSTATE10
} region_ACtrl22State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl22State activeState;                                                                                  // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl22Context;

// This enum contains all states of the TickData region,
// namely __sd_Depth72, __te_S37, finalState12.
typedef enum {
    __SD_DEPTH72, __TE_S37, FINALSTATE12
} regionregion11State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    regionregion11State activeState;                                                                                  // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} Region11Context;

// This enum contains all states of the TickData region,
// namely S5_0_2_0, __EA_Init, __EA_Main, _AC22, _Tc, finalState13.
typedef enum {
    S5_0_2_0, __EA_INIT3, __EA_MAIN3, __EA_MAIN3RUNNING, _AC22, _TC2, FINALSTATE13
} region__EA_Entry17State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region__EA_Entry17State activeState;                                                                              // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
    _ACtrl22Context _actrl22context;
    Region11Context region11context;
} __EA_Entry17Context;

// This enum contains all states of the TickData region,
// namely S5_0_01, S5_0_11, __EA_Init, __EA_Main, _AC21, __sd_Depth75, __te_S39, finalState14.
typedef enum {
    S5_0_01, S5_0_11, __EA_INIT4, __EA_MAIN4, __EA_MAIN4RUNNING, _AC21, __SD_DEPTH75, __TE_S39, FINALSTATE14
} region__EA_Entry16State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region__EA_Entry16State activeState;                                                                              // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
    _ACtrl21Context _actrl21context;
    __EA_Entry17Context __ea_entry17context;
} __EA_Entry16Context;

// This enum contains all states of the TickData region,
// namely _ARun41, finalState15.
typedef enum {
    _ARUN41, FINALSTATE15
} region_ACtrl4State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl4State activeState;                                                                                   // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl4Context;

// This enum contains all states of the TickData region,
// namely _ARun51, finalState16.
typedef enum {
    _ARUN51, FINALSTATE16
} region_ACtrl5State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl5State activeState;                                                                                   // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl5Context;

// This enum contains all states of the TickData region,
// namely __sd_Depth21, __te_S17, finalState18.
typedef enum {
    __SD_DEPTH21, __TE_S17, FINALSTATE18
} regionregion17State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    regionregion17State activeState;                                                                                  // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} Region17Context;

// This enum contains all states of the TickData region,
// namely _ARun61, finalState19.
typedef enum {
    _ARUN61, FINALSTATE19
} region_ACtrl6State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl6State activeState;                                                                                   // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl6Context;

// This enum contains all states of the TickData region,
// namely _ARun71, finalState20.
typedef enum {
    _ARUN71, FINALSTATE20
} region_ACtrl7State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl7State activeState;                                                                                   // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl7Context;

// This enum contains all states of the TickData region,
// namely _ARun81, finalState21.
typedef enum {
    _ARUN81, FINALSTATE21
} region_ACtrl8State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl8State activeState;                                                                                   // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl8Context;

// This enum contains all states of the TickData region,
// namely _ARun91, finalState22.
typedef enum {
    _ARUN91, FINALSTATE22
} region_ACtrl9State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl9State activeState;                                                                                   // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl9Context;

// This enum contains all states of the TickData region,
// namely __sd_Depth29, __te_S19, finalState24.
typedef enum {
    __SD_DEPTH29, __TE_S19, FINALSTATE24
} regionregion23State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    regionregion23State activeState;                                                                                  // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} Region23Context;

// This enum contains all states of the TickData region,
// namely S3_3_3_0_2_0, __EA_Init, __EA_Main, _AC9, _Tc, finalState25.
typedef enum {
    S3_3_3_0_2_0, __EA_INIT5, __EA_MAIN5, __EA_MAIN5RUNNING, _AC9, _TC3, FINALSTATE25
} region__EA_Entry6State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region__EA_Entry6State activeState;                                                                               // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
    _ACtrl9Context _actrl9context;
    Region23Context region23context;
} __EA_Entry6Context;

// This enum contains all states of the TickData region,
// namely S3_3_3_0_01, S3_3_3_0_11, __EA_Init, __EA_Main, _AC8, __sd_Depth32, __te_S21, finalState26.
typedef enum {
    S3_3_3_0_01, S3_3_3_0_11, __EA_INIT6, __EA_MAIN6, __EA_MAIN6RUNNING, _AC8, __SD_DEPTH32, __TE_S21, FINALSTATE26
} region__EA_Entry5State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region__EA_Entry5State activeState;                                                                               // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
    _ACtrl8Context _actrl8context;
    __EA_Entry6Context __ea_entry6context;
} __EA_Entry5Context;

// This enum contains all states of the TickData region,
// namely __sd_Depth23, S3_3_21, __EA_Init, __EA_Main, _AC7, S3_3_31, finalState27.
typedef enum {
    __SD_DEPTH23, S3_3_21, __EA_INIT7, __EA_MAIN7, __EA_MAIN7RUNNING, _AC7, S3_3_31, FINALSTATE27
} region__EA_Entry4State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region__EA_Entry4State activeState;                                                                               // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
    _ACtrl7Context _actrl7context;
    __EA_Entry5Context __ea_entry5context;
} __EA_Entry4Context;

// This enum contains all states of the TickData region,
// namely __EA_Init, __EA_Main, _AC5, _Tc, S3_0, __EA_Main, _AC6, finalState28.
typedef enum {
    __EA_INIT8, __EA_MAIN8, __EA_MAIN8RUNNING, _AC5, _TC4, S3_0, __EA_MAIN9, __EA_MAIN9RUNNING, _AC6, FINALSTATE28
} region__EA_Entry2State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region__EA_Entry2State activeState;                                                                               // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
    _ACtrl5Context _actrl5context;
    Region17Context region17context;
    _ACtrl6Context _actrl6context;
    __EA_Entry4Context __ea_entry4context;
} __EA_Entry2Context;

// This enum contains all states of the TickData region,
// namely _ARun101, finalState29.
typedef enum {
    _ARUN101, FINALSTATE29
} region_ACtrl10State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl10State activeState;                                                                                  // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl10Context;

// This enum contains all states of the TickData region,
// namely _ARun111, finalState30.
typedef enum {
    _ARUN111, FINALSTATE30
} region_ACtrl11State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl11State activeState;                                                                                  // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl11Context;

// This enum contains all states of the TickData region,
// namely _ARun121, finalState31.
typedef enum {
    _ARUN121, FINALSTATE31
} region_ACtrl12State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl12State activeState;                                                                                  // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl12Context;

// This enum contains all states of the TickData region,
// namely _ARun131, finalState32.
typedef enum {
    _ARUN131, FINALSTATE32
} region_ACtrl13State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl13State activeState;                                                                                  // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl13Context;

// This enum contains all states of the TickData region,
// namely _ARun141, finalState33.
typedef enum {
    _ARUN141, FINALSTATE33
} region_ACtrl14State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl14State activeState;                                                                                  // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl14Context;

// This enum contains all states of the TickData region,
// namely __sd_Depth42, __te_S23, finalState35.
typedef enum {
    __SD_DEPTH42, __TE_S23, FINALSTATE35
} regionregion34State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    regionregion34State activeState;                                                                                  // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} Region34Context;

// This enum contains all states of the TickData region,
// namely S4_1_3_0_2_0, __EA_Init, __EA_Main, _AC14, _Tc, finalState36.
typedef enum {
    S4_1_3_0_2_0, __EA_INIT9, __EA_MAIN10, __EA_MAIN10RUNNING, _AC14, _TC5, FINALSTATE36
} region__EA_Entry11State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region__EA_Entry11State activeState;                                                                              // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
    _ACtrl14Context _actrl14context;
    Region34Context region34context;
} __EA_Entry11Context;

// This enum contains all states of the TickData region,
// namely S4_1_3_0_01, S4_1_3_0_11, __EA_Init, __EA_Main, _AC13, __sd_Depth45, __te_S25, finalState37.
typedef enum {
    S4_1_3_0_01, S4_1_3_0_11, __EA_INIT10, __EA_MAIN11, __EA_MAIN11RUNNING, _AC13, __SD_DEPTH45, __TE_S25, FINALSTATE37
} region__EA_Entry10State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region__EA_Entry10State activeState;                                                                              // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
    _ACtrl13Context _actrl13context;
    __EA_Entry11Context __ea_entry11context;
} __EA_Entry10Context;

// This enum contains all states of the TickData region,
// namely __sd_Depth36, S4_1_21, __EA_Init, __EA_Main, _AC12, S4_1_31, finalState38.
typedef enum {
    __SD_DEPTH36, S4_1_21, __EA_INIT11, __EA_MAIN12, __EA_MAIN12RUNNING, _AC12, S4_1_31, FINALSTATE38
} region__EA_Entry9State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region__EA_Entry9State activeState;                                                                               // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
    _ACtrl12Context _actrl12context;
    __EA_Entry10Context __ea_entry10context;
} __EA_Entry9Context;

// This enum contains all states of the TickData region,
// namely S4_0, __EA_Init, __EA_Main, _AC11, _Tc, finalState39.
typedef enum {
    S4_0, __EA_INIT12, __EA_MAIN13, __EA_MAIN13RUNNING, _AC11, _TC6, FINALSTATE39
} region__EA_Entry8State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region__EA_Entry8State activeState;                                                                               // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
    _ACtrl11Context _actrl11context;
    __EA_Entry9Context __ea_entry9context;
} __EA_Entry8Context;

// This enum contains all states of the TickData region,
// namely _ARun24, finalState40.
typedef enum {
    _ARUN24, FINALSTATE40
} region_ACtrl2State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    region_ACtrl2State activeState;                                                                                   // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} _ACtrl2Context;

// This enum contains all states of the TickData region,
// namely S3_0_01, S3_0_11, S3_0_21, __sd_Depth13, __te_S12, finalState42.
typedef enum {
    S3_0_01, S3_0_11, S3_0_21, __SD_DEPTH13, __TE_S12, FINALSTATE42
} regionregion41State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    regionregion41State activeState;                                                                                  // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
} Region41Context;

// This enum contains all states of the TickData region,
// namely __sd_Depth79, __te_S42, __te_S43, __te_S44, __te_S45, __te_S46, __te_S47, __te_S48, __te_S49, __te_S50, __te_S51, __te_S52, __te_S53, __te_S54, __te_S55, __te_S56, __te_S57, __te_S58, __te_S59, __te_S60, S0, __sd_Depth, __te_S1, S04, S15, S23, __EA_Init, __EA_Main, _AC16, __te_S35, S05, __sd_Depth66, S31, S43, __EA_Init, __EA_Main, _AC20, __te_S40, __te_S2, __sd_Depth2, __te_S4, __te_S5, __te_S28, __sd_Depth51, __te_S30, S4_01, S03, S14, S22, __EA_Init, __EA_Main, _AC4, __EA_Init, __EA_Main, _AC10, S53, __te_S26, __te_S6, __sd_Depth4, __te_S8, __te_S9, __te_S15, __te_S27, S4_3_1_01, S01, __te_S10, __sd_Depth7, S21, __EA_Init, __EA_Main, _AC2, __te_S13, __te_S14, S41, S52, S63, S42, finalState43.
typedef enum {
    __SD_DEPTH79, __TE_S42, __TE_S43, __TE_S44, __TE_S45, __TE_S46, __TE_S47, __TE_S48, __TE_S49, __TE_S50, __TE_S51, __TE_S52, __TE_S53, __TE_S54, __TE_S55, __TE_S56, __TE_S57, __TE_S58, __TE_S59, __TE_S60, S0, __SD_DEPTH, __TE_S1, S04, S15, S23, __EA_INIT13, __EA_MAIN14, __EA_MAIN14RUNNING, _AC16, __TE_S35, S05, __SD_DEPTH66, S31, S43, __EA_INIT14, __EA_MAIN15, __EA_MAIN15RUNNING, _AC20, __TE_S40, __TE_S2, __SD_DEPTH2, __TE_S4, __TE_S5, __TE_S28, __SD_DEPTH51, __TE_S30, S4_01, S03, S14, S22, __EA_INIT15, __EA_MAIN16, __EA_MAIN16RUNNING, _AC4, __EA_INIT16, __EA_MAIN17, __EA_MAIN17RUNNING, _AC10, S53, __TE_S26, __TE_S6, __SD_DEPTH4, __TE_S8, __TE_S9, __TE_S15, __TE_S27, S4_3_1_01, S01, __TE_S10, __SD_DEPTH7, S21, __EA_INIT17, __EA_MAIN18, __EA_MAIN18RUNNING, _AC2, __TE_S13, __TE_S14, S41, S52, S63, S42, FINALSTATE43
} regionregion0State;

// The thread data of TickData
typedef struct {
    ThreadStatus threadStatus;                                                                                        // status of the thread (see ThreadStatus enum)
    regionregion0State activeState;                                                                                   // the active state
    int activePriority;                    // active priority of the thread for scheduling
    char delayedEnabled;     // active state at the beginning of the tick
    Iface* iface;                                                                                                     // pointer to the program interface for communication
    _ACtrl16Context _actrl16context;
    __EA_Entry13Context __ea_entry13context;
    _ACtrl20Context _actrl20context;
    __EA_Entry16Context __ea_entry16context;
    _ACtrl4Context _actrl4context;
    __EA_Entry2Context __ea_entry2context;
    _ACtrl10Context _actrl10context;
    __EA_Entry8Context __ea_entry8context;
    _ACtrl2Context _actrl2context;
    Region41Context region41context;
} Region0Context;

// Root level data of the program
typedef struct {
    Iface iface;
    int activePriority;
    ThreadStatus threadStatus;
    Region0Context region0context;
} TickData;


// Forward declarations of the root level functions

/* reset() sets the program to its initial state.
 * You should call reset() at least once at the start of the application.
 * Additionally, you can always reset the actual status to the initial configuration
 * to restart the application.
 */
void reset(TickData *context);

// request_route() contains the logic of the rootState of the statechart.
static inline void request_route(TickData *context);

/* The surrounding application should call tick() once per clock tick.
 * The interface inside the TickData struct should be used to communicate with the logic.
 * Set the inputs before you call tick() and read out the outputs afterwards.
 */
void tick(TickData *context);


// Forward declarations of the program structure functions
static inline void staterequest_routerunning(TickData *context);
// Logic function of the simple state __sd_Depth79 in region regionregion0
static inline void regionregion0_state__sd_Depth79(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth79
 *    to
 *   __te_S42
 *   Effects: _taken_transitions[0] = 0
 */

// Logic function of the simple state __te_S42 in region regionregion0
static inline void regionregion0_state__te_S42(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S42
 *    to
 *   __te_S43
 *   Effects: _taken_transitions[1] = 0
 */

// Logic function of the simple state __te_S43 in region regionregion0
static inline void regionregion0_state__te_S43(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S43
 *    to
 *   __te_S44
 *   Effects: _taken_transitions[2] = 0
 */

// Logic function of the simple state __te_S44 in region regionregion0
static inline void regionregion0_state__te_S44(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S44
 *    to
 *   __te_S45
 *   Effects: _taken_transitions[3] = 0
 */

// Logic function of the simple state __te_S45 in region regionregion0
static inline void regionregion0_state__te_S45(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S45
 *    to
 *   __te_S46
 *   Effects: _taken_transitions[4] = 0
 */

// Logic function of the simple state __te_S46 in region regionregion0
static inline void regionregion0_state__te_S46(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S46
 *    to
 *   __te_S47
 *   Effects: _taken_transitions[5] = 0
 */

// Logic function of the simple state __te_S47 in region regionregion0
static inline void regionregion0_state__te_S47(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S47
 *    to
 *   __te_S48
 *   Effects: _taken_transitions[6] = 0
 */

// Logic function of the simple state __te_S48 in region regionregion0
static inline void regionregion0_state__te_S48(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S48
 *    to
 *   __te_S49
 *   Effects: _taken_transitions[7] = 0
 */

// Logic function of the simple state __te_S49 in region regionregion0
static inline void regionregion0_state__te_S49(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S49
 *    to
 *   __te_S50
 *   Effects: _taken_transitions[8] = 0
 */

// Logic function of the simple state __te_S50 in region regionregion0
static inline void regionregion0_state__te_S50(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S50
 *    to
 *   __te_S51
 *   Effects: _taken_transitions[9] = 0
 */

// Logic function of the simple state __te_S51 in region regionregion0
static inline void regionregion0_state__te_S51(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S51
 *    to
 *   __te_S52
 *   Effects: _taken_transitions[10] = 0
 */

// Logic function of the simple state __te_S52 in region regionregion0
static inline void regionregion0_state__te_S52(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S52
 *    to
 *   __te_S53
 *   Effects: _taken_transitions[11] = 0
 */

// Logic function of the simple state __te_S53 in region regionregion0
static inline void regionregion0_state__te_S53(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S53
 *    to
 *   __te_S54
 *   Effects: _taken_transitions[12] = 0
 */

// Logic function of the simple state __te_S54 in region regionregion0
static inline void regionregion0_state__te_S54(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S54
 *    to
 *   __te_S55
 *   Effects: _taken_transitions[13] = 0
 */

// Logic function of the simple state __te_S55 in region regionregion0
static inline void regionregion0_state__te_S55(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S55
 *    to
 *   __te_S56
 *   Effects: _taken_transitions[14] = 0
 */

// Logic function of the simple state __te_S56 in region regionregion0
static inline void regionregion0_state__te_S56(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S56
 *    to
 *   __te_S57
 *   Effects: _taken_transitions[15] = 0
 */

// Logic function of the simple state __te_S57 in region regionregion0
static inline void regionregion0_state__te_S57(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S57
 *    to
 *   __te_S58
 *   Effects: _taken_transitions[16] = 0
 */

// Logic function of the simple state __te_S58 in region regionregion0
static inline void regionregion0_state__te_S58(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S58
 *    to
 *   __te_S59
 *   Effects: _taken_transitions[17] = 0
 */

// Logic function of the simple state __te_S59 in region regionregion0
static inline void regionregion0_state__te_S59(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S59
 *    to
 *   __te_S60
 *   Effects: _taken_transitions[18] = 0
 */

// Logic function of the simple state __te_S60 in region regionregion0
static inline void regionregion0_state__te_S60(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S60
 *    to
 *   S0
 *   Effects: _taken_transitions[19] = 0
 */

// Logic function of the simple state S0 in region regionregion0
static inline void regionregion0_stateS0(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S0
 *    to
 *   __sd_Depth
 *   Effects: _taken_transitions[0] += 1
 */

// Logic function of the simple state __sd_Depth in region regionregion0
static inline void regionregion0_state__sd_Depth(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth
 *    to
 *   __te_S1
 *   Effects: count_routes = interlocking_table_get_routes(src_signal_id, dst_signal_id, route_ids)
 */

// Logic function of the simple state __te_S1 in region regionregion0
static inline void regionregion0_state__te_S1(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S1
 *    to
 *   S04
 *   Effects: _taken_transitions[1] += 1
 */

// Logic function of the simple state S04 in region regionregion0
static inline void regionregion0_stateS04(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S04
 *    to
 *   S15
 *   Effects: _request_route_local_min_len = 2147483647
 */

// Logic function of the simple state S15 in region regionregion0
static inline void regionregion0_stateS15(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S15
 *    to
 *   S23
 *   Effects: _request_route_local_i3 = 0
 */

// Logic function of the simple state S23 in region regionregion0
static inline void regionregion0_stateS23(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S23
 *    to
 *   S42
 *   Effects: _request_route_local_result1 = 0
 */

// Logic function of the simple state __EA_Init in region regionregion0
static inline void regionregion0_state__EA_Init(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm12 = 0
 */

static inline void regionregion0_state__EA_Main(Region0Context *context); // State __EA_Main  in region regionregion0 logic
static inline void regionregion0_state__EA_Mainrunning(Region0Context *context);
// Logic function of the simple state _ARun161 in region region_ACtrl16
static inline void region_ACtrl16_state_ARun161(_ACtrl16Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun161
 *    to
 *   finalState1
 *   Trigger: context->iface->_request_route_local__Tterm12
 */

/* Immediate
 *   Transition 1:
 *   _ARun161
 *    to
 *   finalState1
 */

// Logic function of the simple state finalState1 in region region_ACtrl16
static inline void region_ACtrl16_statefinalState1(_ACtrl16Context *context);
static inline void region_ACtrl16(_ACtrl16Context *context); // Region region_ACtrl16

// Logic function of the simple state S3_0_02 in region region__EA_Entry13
static inline void region__EA_Entry13_stateS3_0_02(__EA_Entry13Context *context);
/* Immediate
 *   Transition 0:
 *   S3_0_02
 *    to
 *   S3_0_12
 *   Effects: _request_route_local_route_id = route_ids[_request_route_local_i3]
 */

// Logic function of the simple state S3_0_12 in region region__EA_Entry13
static inline void region__EA_Entry13_stateS3_0_12(__EA_Entry13Context *context);
/* Immediate
 *   Transition 0:
 *   S3_0_12
 *    to
 *   __EA_Init
 *   Effects: _request_route_local_len = config_get_scalar_float_value("route", _request_route_local_route_id, "length")
 */

// Logic function of the simple state __EA_Init in region region__EA_Entry13
static inline void region__EA_Entry13_state__EA_Init(__EA_Entry13Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm13 = 0
 */

static inline void region__EA_Entry13_state__EA_Main(__EA_Entry13Context *context); // State __EA_Main  in region region__EA_Entry13 logic
static inline void region__EA_Entry13_state__EA_Mainrunning(__EA_Entry13Context *context);
// Logic function of the simple state _ARun171 in region region_ACtrl17
static inline void region_ACtrl17_state_ARun171(_ACtrl17Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun171
 *    to
 *   finalState2
 *   Trigger: context->iface->_request_route_local__Tterm13
 */

/* Immediate
 *   Transition 1:
 *   _ARun171
 *    to
 *   finalState2
 *   Trigger: context->iface->_request_route_local__Tterm12 || 1
 */

// Logic function of the simple state finalState2 in region region_ACtrl17
static inline void region_ACtrl17_statefinalState2(_ACtrl17Context *context);
static inline void region_ACtrl17(_ACtrl17Context *context); // Region region_ACtrl17

// Logic function of the simple state S3_0_2_0 in region region__EA_Entry14
static inline void region__EA_Entry14_stateS3_0_2_0(__EA_Entry14Context *context);
/* Immediate
 *   Transition 0:
 *   S3_0_2_0
 *    to
 *   __EA_Init
 *   Trigger: context->iface->_request_route_local_len < context->iface->_request_route_local_min_len
 */

/* Immediate
 *   Transition 1:
 *   S3_0_2_0
 *    to
 *   _Tc
 */

// Logic function of the simple state __EA_Init in region region__EA_Entry14
static inline void region__EA_Entry14_state__EA_Init(__EA_Entry14Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm14 = 0
 */

static inline void region__EA_Entry14_state__EA_Main(__EA_Entry14Context *context); // State __EA_Main  in region region__EA_Entry14 logic
static inline void region__EA_Entry14_state__EA_Mainrunning(__EA_Entry14Context *context);
// Logic function of the simple state _ARun181 in region region_ACtrl18
static inline void region_ACtrl18_state_ARun181(_ACtrl18Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun181
 *    to
 *   finalState3
 *   Trigger: context->iface->_request_route_local__Tterm14
 */

/* Immediate
 *   Transition 1:
 *   _ARun181
 *    to
 *   finalState3
 *   Trigger: context->iface->_request_route_local__Tterm13 || context->iface->_request_route_local__Tterm12 || 1
 */

// Logic function of the simple state finalState3 in region region_ACtrl18
static inline void region_ACtrl18_statefinalState3(_ACtrl18Context *context);
static inline void region_ACtrl18(_ACtrl18Context *context); // Region region_ACtrl18

// Logic function of the simple state S3_0_2_1_01 in region regionregion4
static inline void regionregion4_stateS3_0_2_1_01(Region4Context *context);
/* Immediate
 *   Transition 0:
 *   S3_0_2_1_01
 *    to
 *   __sd_Depth58
 *   Effects: _request_route_local_min_len = _request_route_local_len
 */

// Logic function of the simple state __sd_Depth58 in region regionregion4
static inline void regionregion4_state__sd_Depth58(Region4Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth58
 *    to
 *   __te_S32
 *   Effects: _request_route_local_result1 = _request_route_local_i3
 */

// Logic function of the simple state __te_S32 in region regionregion4
static inline void regionregion4_state__te_S32(Region4Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S32
 *    to
 *   finalState5
 *   Effects: _request_route_local__Tterm14 = 1
 */

// Logic function of the simple state finalState5 in region regionregion4
static inline void regionregion4_statefinalState5(Region4Context *context);
static inline void regionregion4(Region4Context *context); // Region regionregion4

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC18
 *   Trigger: context->_actrl18context.threadStatus == TERMINATED &&
  context->region4context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC18 in region region__EA_Entry14
static inline void region__EA_Entry14_state_AC18(__EA_Entry14Context *context);
/* Immediate
 *   Transition 0:
 *   _AC18
 *    to
 *   _Tc
 *   Trigger: context->iface->_request_route_local__Tterm14
 */

/* Immediate
 *   Transition 1:
 *   _AC18
 *    to
 *   finalState6
 */

// Logic function of the simple state _Tc in region region__EA_Entry14
static inline void region__EA_Entry14_state_Tc(__EA_Entry14Context *context);
/* Immediate
 *   Transition 0:
 *   _Tc
 *    to
 *   finalState6
 *   Effects: _request_route_local__Tterm13 = 1
 */

// Logic function of the simple state finalState6 in region region__EA_Entry14
static inline void region__EA_Entry14_statefinalState6(__EA_Entry14Context *context);
static inline void region__EA_Entry14(__EA_Entry14Context *context); // Region region__EA_Entry14

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC17
 *   Trigger: context->_actrl17context.threadStatus == TERMINATED &&
  context->__ea_entry14context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC17 in region region__EA_Entry13
static inline void region__EA_Entry13_state_AC17(__EA_Entry13Context *context);
/* Immediate
 *   Transition 0:
 *   _AC17
 *    to
 *   __sd_Depth61
 *   Trigger: context->iface->_request_route_local__Tterm13
 */

/* Immediate
 *   Transition 1:
 *   _AC17
 *    to
 *   finalState7
 */

// Logic function of the simple state __sd_Depth61 in region region__EA_Entry13
static inline void region__EA_Entry13_state__sd_Depth61(__EA_Entry13Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth61
 *    to
 *   __te_S34
 *   Effects: _request_route_local_i3 = _request_route_local_i3 + 1
 */

// Logic function of the simple state __te_S34 in region region__EA_Entry13
static inline void region__EA_Entry13_state__te_S34(__EA_Entry13Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S34
 *    to
 *   finalState7
 *   Effects: _request_route_local__Tterm12 = 1
 */

// Logic function of the simple state finalState7 in region region__EA_Entry13
static inline void region__EA_Entry13_statefinalState7(__EA_Entry13Context *context);
static inline void region__EA_Entry13(__EA_Entry13Context *context); // Region region__EA_Entry13

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC16
 *   Trigger: context->_actrl16context.threadStatus == TERMINATED &&
  context->__ea_entry13context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC16 in region regionregion0
static inline void regionregion0_state_AC16(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   _AC16
 *    to
 *   S42
 *   Trigger: context->iface->_request_route_local__Tterm12
 */

/* Immediate
 *   Transition 1:
 *   _AC16
 *    to
 *   __te_S35
 */

// Logic function of the simple state __te_S35 in region regionregion0
static inline void regionregion0_state__te_S35(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S35
 *    to
 *   S05
 *   Effects: _taken_transitions[2] += 1
 */

// Logic function of the simple state S05 in region regionregion0
static inline void regionregion0_stateS05(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S05
 *    to
 *   __sd_Depth66
 *   Effects: _request_route_local__train_id_ = config_get_scalar_string_value("route", id, "train")
 */

// Logic function of the simple state __sd_Depth66 in region regionregion0
static inline void regionregion0_state__sd_Depth66(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth66
 *    to
 *   S31
 *   Effects: _request_route_local_count_conflict_routes = config_get_array_string_value("route", id, "conflicts", _request_route_local_conflict_routes)
 */

// Logic function of the simple state S31 in region regionregion0
static inline void regionregion0_stateS31(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S31
 *    to
 *   S43
 *   Effects: _request_route_local_i4 = 0
 */

// Logic function of the simple state S43 in region regionregion0
static inline void regionregion0_stateS43(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S43
 *    to
 *   S63
 *   Effects: _request_route_local_result2 = 1
 */

// Logic function of the simple state __EA_Init in region regionregion0
static inline void regionregion0_state__EA_Init2(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm15 = 0
 */

static inline void regionregion0_state__EA_Main2(Region0Context *context); // State __EA_Main  in region regionregion0 logic
static inline void regionregion0_state__EA_Main2running(Region0Context *context);
// Logic function of the simple state _ARun201 in region region_ACtrl20
static inline void region_ACtrl20_state_ARun201(_ACtrl20Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun201
 *    to
 *   finalState8
 *   Trigger: context->iface->_request_route_local__Tterm15
 */

/* Immediate
 *   Transition 1:
 *   _ARun201
 *    to
 *   finalState8
 */

// Logic function of the simple state finalState8 in region region_ACtrl20
static inline void region_ACtrl20_statefinalState8(_ACtrl20Context *context);
static inline void region_ACtrl20(_ACtrl20Context *context); // Region region_ACtrl20

// Logic function of the simple state S5_0_01 in region region__EA_Entry16
static inline void region__EA_Entry16_stateS5_0_01(__EA_Entry16Context *context);
/* Immediate
 *   Transition 0:
 *   S5_0_01
 *    to
 *   S5_0_11
 *   Effects: _request_route_local_conflict_route_id = _request_route_local_conflict_routes[_request_route_local_i4]
 */

// Logic function of the simple state S5_0_11 in region region__EA_Entry16
static inline void region__EA_Entry16_stateS5_0_11(__EA_Entry16Context *context);
/* Immediate
 *   Transition 0:
 *   S5_0_11
 *    to
 *   __EA_Init
 *   Effects: _request_route_local_conflict_train_id = config_get_scalar_string_value("route", _request_route_local_conflict_route_id, "train")
 */

// Logic function of the simple state __EA_Init in region region__EA_Entry16
static inline void region__EA_Entry16_state__EA_Init(__EA_Entry16Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm16 = 0
 */

static inline void region__EA_Entry16_state__EA_Main(__EA_Entry16Context *context); // State __EA_Main  in region region__EA_Entry16 logic
static inline void region__EA_Entry16_state__EA_Mainrunning(__EA_Entry16Context *context);
// Logic function of the simple state _ARun211 in region region_ACtrl21
static inline void region_ACtrl21_state_ARun211(_ACtrl21Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun211
 *    to
 *   finalState9
 *   Trigger: context->iface->_request_route_local__Tterm16
 */

/* Immediate
 *   Transition 1:
 *   _ARun211
 *    to
 *   finalState9
 *   Trigger: context->iface->_request_route_local__Tterm15 || 1
 */

// Logic function of the simple state finalState9 in region region_ACtrl21
static inline void region_ACtrl21_statefinalState9(_ACtrl21Context *context);
static inline void region_ACtrl21(_ACtrl21Context *context); // Region region_ACtrl21

// Logic function of the simple state S5_0_2_0 in region region__EA_Entry17
static inline void region__EA_Entry17_stateS5_0_2_0(__EA_Entry17Context *context);
/* Immediate
 *   Transition 0:
 *   S5_0_2_0
 *    to
 *   __EA_Init
 *   Trigger: !string_equals(context->iface->_request_route_local_conflict_train_id, "")
 */

/* Immediate
 *   Transition 1:
 *   S5_0_2_0
 *    to
 *   _Tc
 */

// Logic function of the simple state __EA_Init in region region__EA_Entry17
static inline void region__EA_Entry17_state__EA_Init(__EA_Entry17Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm17 = 0
 */

static inline void region__EA_Entry17_state__EA_Main(__EA_Entry17Context *context); // State __EA_Main  in region region__EA_Entry17 logic
static inline void region__EA_Entry17_state__EA_Mainrunning(__EA_Entry17Context *context);
// Logic function of the simple state _ARun221 in region region_ACtrl22
static inline void region_ACtrl22_state_ARun221(_ACtrl22Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun221
 *    to
 *   finalState10
 *   Trigger: context->iface->_request_route_local__Tterm17
 */

/* Immediate
 *   Transition 1:
 *   _ARun221
 *    to
 *   finalState10
 *   Trigger: context->iface->_request_route_local__Tterm16 || context->iface->_request_route_local__Tterm15 || 1
 */

// Logic function of the simple state finalState10 in region region_ACtrl22
static inline void region_ACtrl22_statefinalState10(_ACtrl22Context *context);
static inline void region_ACtrl22(_ACtrl22Context *context); // Region region_ACtrl22

// Logic function of the simple state __sd_Depth72 in region regionregion11
static inline void regionregion11_state__sd_Depth72(Region11Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth72
 *    to
 *   __te_S37
 *   Effects: _request_route_local_result2 = 0
 */

// Logic function of the simple state __te_S37 in region regionregion11
static inline void regionregion11_state__te_S37(Region11Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S37
 *    to
 *   finalState12
 *   Effects: _request_route_local__Tterm17 = 1
 */

// Logic function of the simple state finalState12 in region regionregion11
static inline void regionregion11_statefinalState12(Region11Context *context);
static inline void regionregion11(Region11Context *context); // Region regionregion11

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC22
 *   Trigger: context->_actrl22context.threadStatus == TERMINATED &&
  context->region11context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC22 in region region__EA_Entry17
static inline void region__EA_Entry17_state_AC22(__EA_Entry17Context *context);
/* Immediate
 *   Transition 0:
 *   _AC22
 *    to
 *   _Tc
 *   Trigger: context->iface->_request_route_local__Tterm17
 */

/* Immediate
 *   Transition 1:
 *   _AC22
 *    to
 *   finalState13
 */

// Logic function of the simple state _Tc in region region__EA_Entry17
static inline void region__EA_Entry17_state_Tc(__EA_Entry17Context *context);
/* Immediate
 *   Transition 0:
 *   _Tc
 *    to
 *   finalState13
 *   Effects: _request_route_local__Tterm16 = 1
 */

// Logic function of the simple state finalState13 in region region__EA_Entry17
static inline void region__EA_Entry17_statefinalState13(__EA_Entry17Context *context);
static inline void region__EA_Entry17(__EA_Entry17Context *context); // Region region__EA_Entry17

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC21
 *   Trigger: context->_actrl21context.threadStatus == TERMINATED &&
  context->__ea_entry17context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC21 in region region__EA_Entry16
static inline void region__EA_Entry16_state_AC21(__EA_Entry16Context *context);
/* Immediate
 *   Transition 0:
 *   _AC21
 *    to
 *   __sd_Depth75
 *   Trigger: context->iface->_request_route_local__Tterm16
 */

/* Immediate
 *   Transition 1:
 *   _AC21
 *    to
 *   finalState14
 */

// Logic function of the simple state __sd_Depth75 in region region__EA_Entry16
static inline void region__EA_Entry16_state__sd_Depth75(__EA_Entry16Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth75
 *    to
 *   __te_S39
 *   Effects: _request_route_local_i4 = _request_route_local_i4 + 1
 */

// Logic function of the simple state __te_S39 in region region__EA_Entry16
static inline void region__EA_Entry16_state__te_S39(__EA_Entry16Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S39
 *    to
 *   finalState14
 *   Effects: _request_route_local__Tterm15 = 1
 */

// Logic function of the simple state finalState14 in region region__EA_Entry16
static inline void region__EA_Entry16_statefinalState14(__EA_Entry16Context *context);
static inline void region__EA_Entry16(__EA_Entry16Context *context); // Region region__EA_Entry16

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC20
 *   Trigger: context->_actrl20context.threadStatus == TERMINATED &&
  context->__ea_entry16context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC20 in region regionregion0
static inline void regionregion0_state_AC20(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   _AC20
 *    to
 *   S63
 *   Trigger: context->iface->_request_route_local__Tterm15
 */

/* Immediate
 *   Transition 1:
 *   _AC20
 *    to
 *   __te_S40
 */

// Logic function of the simple state __te_S40 in region regionregion0
static inline void regionregion0_state__te_S40(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S40
 *    to
 *   S4_01
 *   Effects: _taken_transitions[3] += 1
 */

// Logic function of the simple state __te_S2 in region regionregion0
static inline void regionregion0_state__te_S2(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S2
 *    to
 *   __sd_Depth2
 *   Effects: _taken_transitions[5] += 1
 */

// Logic function of the simple state __sd_Depth2 in region regionregion0
static inline void regionregion0_state__sd_Depth2(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth2
 *    to
 *   __te_S4
 *   Effects: id = ""
 */

// Logic function of the simple state __te_S4 in region regionregion0
static inline void regionregion0_state__te_S4(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S4
 *    to
 *   __te_S5
 *   Effects: _taken_transitions[8] += 1
 */

// Logic function of the simple state __te_S5 in region regionregion0
static inline void regionregion0_state__te_S5(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S5
 *    to
 *   __te_S28
 *   Effects: _taken_transitions[7] += 1
 */

// Logic function of the simple state __te_S28 in region regionregion0
static inline void regionregion0_state__te_S28(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S28
 *    to
 *   __sd_Depth51
 *   Effects: _taken_transitions[4] += 1
 */

// Logic function of the simple state __sd_Depth51 in region regionregion0
static inline void regionregion0_state__sd_Depth51(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth51
 *    to
 *   __te_S30
 *   Effects: out = id
 */

// Logic function of the simple state __te_S30 in region regionregion0
static inline void regionregion0_state__te_S30(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S30
 *    to
 *   finalState43
 *   Effects: _taken_transitions[19] += 1
 */

// Logic function of the simple state S4_01 in region regionregion0
static inline void regionregion0_stateS4_01(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S4_01
 *    to
 *   __te_S2
 *   Trigger: !context->iface->is_grantable
 */

/* Immediate
 *   Transition 1:
 *   S4_01
 *    to
 *   S03
 *   Effects: _taken_transitions[6] += 1
 */

// Logic function of the simple state S03 in region regionregion0
static inline void regionregion0_stateS03(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S03
 *    to
 *   S14
 *   Effects: _request_route_local_result = 1
 */

// Logic function of the simple state S14 in region regionregion0
static inline void regionregion0_stateS14(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S14
 *    to
 *   S22
 *   Effects: _request_route_local_src_signal = config_get_scalar_string_value("route", id, "source")
 */

// Logic function of the simple state S22 in region regionregion0
static inline void regionregion0_stateS22(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S22
 *    to
 *   __EA_Init
 *   Effects: _request_route_local_src_state = track_state_get_value("signal", _request_route_local_src_signal)
 */

// Logic function of the simple state __EA_Init in region regionregion0
static inline void regionregion0_state__EA_Init3(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm1 = 0
 */

static inline void regionregion0_state__EA_Main3(Region0Context *context); // State __EA_Main  in region regionregion0 logic
static inline void regionregion0_state__EA_Main3running(Region0Context *context);
// Logic function of the simple state _ARun41 in region region_ACtrl4
static inline void region_ACtrl4_state_ARun41(_ACtrl4Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun41
 *    to
 *   finalState15
 *   Trigger: context->iface->_request_route_local__Tterm1
 */

/* Immediate
 *   Transition 1:
 *   _ARun41
 *    to
 *   finalState15
 */

// Logic function of the simple state finalState15 in region region_ACtrl4
static inline void region_ACtrl4_statefinalState15(_ACtrl4Context *context);
static inline void region_ACtrl4(_ACtrl4Context *context); // Region region_ACtrl4

// Logic function of the simple state __EA_Init in region region__EA_Entry2
static inline void region__EA_Entry2_state__EA_Init(__EA_Entry2Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm2 = 0
 */

static inline void region__EA_Entry2_state__EA_Main(__EA_Entry2Context *context); // State __EA_Main  in region region__EA_Entry2 logic
static inline void region__EA_Entry2_state__EA_Mainrunning(__EA_Entry2Context *context);
// Logic function of the simple state _ARun51 in region region_ACtrl5
static inline void region_ACtrl5_state_ARun51(_ACtrl5Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun51
 *    to
 *   finalState16
 *   Trigger: context->iface->_request_route_local__Tterm2
 */

/* Immediate
 *   Transition 1:
 *   _ARun51
 *    to
 *   finalState16
 *   Trigger: context->iface->_request_route_local__Tterm1 || 1
 */

// Logic function of the simple state finalState16 in region region_ACtrl5
static inline void region_ACtrl5_statefinalState16(_ACtrl5Context *context);
static inline void region_ACtrl5(_ACtrl5Context *context); // Region region_ACtrl5

// Logic function of the simple state __sd_Depth21 in region regionregion17
static inline void regionregion17_state__sd_Depth21(Region17Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth21
 *    to
 *   __te_S17
 *   Effects: _request_route_local_result = 0
 */

// Logic function of the simple state __te_S17 in region regionregion17
static inline void regionregion17_state__te_S17(Region17Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S17
 *    to
 *   finalState18
 *   Effects: _request_route_local__Tterm2 = 1
 */

// Logic function of the simple state finalState18 in region regionregion17
static inline void regionregion17_statefinalState18(Region17Context *context);
static inline void regionregion17(Region17Context *context); // Region regionregion17

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC5
 *   Trigger: context->_actrl5context.threadStatus == TERMINATED &&
  context->region17context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC5 in region region__EA_Entry2
static inline void region__EA_Entry2_state_AC5(__EA_Entry2Context *context);
/* Immediate
 *   Transition 0:
 *   _AC5
 *    to
 *   _Tc
 *   Trigger: context->iface->_request_route_local__Tterm2
 */

/* Immediate
 *   Transition 1:
 *   _AC5
 *    to
 *   finalState28
 */

// Logic function of the simple state _Tc in region region__EA_Entry2
static inline void region__EA_Entry2_state_Tc(__EA_Entry2Context *context);
/* Immediate
 *   Transition 0:
 *   _Tc
 *    to
 *   finalState28
 *   Effects: _request_route_local__Tterm1 = 1
 */

// Logic function of the simple state S3_0 in region region__EA_Entry2
static inline void region__EA_Entry2_stateS3_0(__EA_Entry2Context *context);
/* Immediate
 *   Transition 0:
 *   S3_0
 *    to
 *   __EA_Init
 *   Trigger: !string_equals(context->iface->_request_route_local_src_state, "red")
 */

/* Immediate
 *   Transition 1:
 *   S3_0
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm3 = 0
 */

static inline void region__EA_Entry2_state__EA_Main2(__EA_Entry2Context *context); // State __EA_Main  in region region__EA_Entry2 logic
static inline void region__EA_Entry2_state__EA_Main2running(__EA_Entry2Context *context);
// Logic function of the simple state _ARun61 in region region_ACtrl6
static inline void region_ACtrl6_state_ARun61(_ACtrl6Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun61
 *    to
 *   finalState19
 *   Trigger: context->iface->_request_route_local__Tterm3
 */

/* Immediate
 *   Transition 1:
 *   _ARun61
 *    to
 *   finalState19
 *   Trigger: context->iface->_request_route_local__Tterm1 || 1
 */

// Logic function of the simple state finalState19 in region region_ACtrl6
static inline void region_ACtrl6_statefinalState19(_ACtrl6Context *context);
static inline void region_ACtrl6(_ACtrl6Context *context); // Region region_ACtrl6

// Logic function of the simple state __sd_Depth23 in region region__EA_Entry4
static inline void region__EA_Entry4_state__sd_Depth23(__EA_Entry4Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth23
 *    to
 *   S3_3_21
 *   Effects: _request_route_local_flank_signals_count = config_get_array_string_value("route", id, "signals", _request_route_local_flank_signals)
 */

// Logic function of the simple state S3_3_21 in region region__EA_Entry4
static inline void region__EA_Entry4_stateS3_3_21(__EA_Entry4Context *context);
/* Immediate
 *   Transition 0:
 *   S3_3_21
 *    to
 *   S3_3_31
 *   Effects: _request_route_local_i1 = 0
 */

// Logic function of the simple state __EA_Init in region region__EA_Entry4
static inline void region__EA_Entry4_state__EA_Init(__EA_Entry4Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm4 = 0
 */

static inline void region__EA_Entry4_state__EA_Main(__EA_Entry4Context *context); // State __EA_Main  in region region__EA_Entry4 logic
static inline void region__EA_Entry4_state__EA_Mainrunning(__EA_Entry4Context *context);
// Logic function of the simple state _ARun71 in region region_ACtrl7
static inline void region_ACtrl7_state_ARun71(_ACtrl7Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun71
 *    to
 *   finalState20
 *   Trigger: context->iface->_request_route_local__Tterm4
 */

/* Immediate
 *   Transition 1:
 *   _ARun71
 *    to
 *   finalState20
 *   Trigger: context->iface->_request_route_local__Tterm3 || context->iface->_request_route_local__Tterm1 || 1
 */

// Logic function of the simple state finalState20 in region region_ACtrl7
static inline void region_ACtrl7_statefinalState20(_ACtrl7Context *context);
static inline void region_ACtrl7(_ACtrl7Context *context); // Region region_ACtrl7

// Logic function of the simple state S3_3_3_0_01 in region region__EA_Entry5
static inline void region__EA_Entry5_stateS3_3_3_0_01(__EA_Entry5Context *context);
/* Immediate
 *   Transition 0:
 *   S3_3_3_0_01
 *    to
 *   S3_3_3_0_11
 *   Effects: _request_route_local_flank_signal = _request_route_local_flank_signals[_request_route_local_i1]
 */

// Logic function of the simple state S3_3_3_0_11 in region region__EA_Entry5
static inline void region__EA_Entry5_stateS3_3_3_0_11(__EA_Entry5Context *context);
/* Immediate
 *   Transition 0:
 *   S3_3_3_0_11
 *    to
 *   __EA_Init
 *   Effects: _request_route_local_flank_state = track_state_get_value("signal", _request_route_local_flank_signal)
 */

// Logic function of the simple state __EA_Init in region region__EA_Entry5
static inline void region__EA_Entry5_state__EA_Init(__EA_Entry5Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm5 = 0
 */

static inline void region__EA_Entry5_state__EA_Main(__EA_Entry5Context *context); // State __EA_Main  in region region__EA_Entry5 logic
static inline void region__EA_Entry5_state__EA_Mainrunning(__EA_Entry5Context *context);
// Logic function of the simple state _ARun81 in region region_ACtrl8
static inline void region_ACtrl8_state_ARun81(_ACtrl8Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun81
 *    to
 *   finalState21
 *   Trigger: context->iface->_request_route_local__Tterm5
 */

/* Immediate
 *   Transition 1:
 *   _ARun81
 *    to
 *   finalState21
 *   Trigger: context->iface->_request_route_local__Tterm4 || context->iface->_request_route_local__Tterm3 || context->iface->_request_route_local__Tterm1 || 1
 */

// Logic function of the simple state finalState21 in region region_ACtrl8
static inline void region_ACtrl8_statefinalState21(_ACtrl8Context *context);
static inline void region_ACtrl8(_ACtrl8Context *context); // Region region_ACtrl8

// Logic function of the simple state S3_3_3_0_2_0 in region region__EA_Entry6
static inline void region__EA_Entry6_stateS3_3_3_0_2_0(__EA_Entry6Context *context);
/* Immediate
 *   Transition 0:
 *   S3_3_3_0_2_0
 *    to
 *   __EA_Init
 *   Trigger: !string_equals(context->iface->_request_route_local_flank_signal, "red")
 */

/* Immediate
 *   Transition 1:
 *   S3_3_3_0_2_0
 *    to
 *   _Tc
 */

// Logic function of the simple state __EA_Init in region region__EA_Entry6
static inline void region__EA_Entry6_state__EA_Init(__EA_Entry6Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm6 = 0
 */

static inline void region__EA_Entry6_state__EA_Main(__EA_Entry6Context *context); // State __EA_Main  in region region__EA_Entry6 logic
static inline void region__EA_Entry6_state__EA_Mainrunning(__EA_Entry6Context *context);
// Logic function of the simple state _ARun91 in region region_ACtrl9
static inline void region_ACtrl9_state_ARun91(_ACtrl9Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun91
 *    to
 *   finalState22
 *   Trigger: context->iface->_request_route_local__Tterm6
 */

/* Immediate
 *   Transition 1:
 *   _ARun91
 *    to
 *   finalState22
 *   Trigger: context->iface->_request_route_local__Tterm5 || context->iface->_request_route_local__Tterm4 || context->iface->_request_route_local__Tterm3 || context->iface->_request_route_local__Tterm1 || 1
 */

// Logic function of the simple state finalState22 in region region_ACtrl9
static inline void region_ACtrl9_statefinalState22(_ACtrl9Context *context);
static inline void region_ACtrl9(_ACtrl9Context *context); // Region region_ACtrl9

// Logic function of the simple state __sd_Depth29 in region regionregion23
static inline void regionregion23_state__sd_Depth29(Region23Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth29
 *    to
 *   __te_S19
 *   Effects: _request_route_local_result = 0
 */

// Logic function of the simple state __te_S19 in region regionregion23
static inline void regionregion23_state__te_S19(Region23Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S19
 *    to
 *   finalState24
 *   Effects: _request_route_local__Tterm6 = 1
 */

// Logic function of the simple state finalState24 in region regionregion23
static inline void regionregion23_statefinalState24(Region23Context *context);
static inline void regionregion23(Region23Context *context); // Region regionregion23

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC9
 *   Trigger: context->_actrl9context.threadStatus == TERMINATED &&
  context->region23context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC9 in region region__EA_Entry6
static inline void region__EA_Entry6_state_AC9(__EA_Entry6Context *context);
/* Immediate
 *   Transition 0:
 *   _AC9
 *    to
 *   _Tc
 *   Trigger: context->iface->_request_route_local__Tterm6
 */

/* Immediate
 *   Transition 1:
 *   _AC9
 *    to
 *   finalState25
 */

// Logic function of the simple state _Tc in region region__EA_Entry6
static inline void region__EA_Entry6_state_Tc(__EA_Entry6Context *context);
/* Immediate
 *   Transition 0:
 *   _Tc
 *    to
 *   finalState25
 *   Effects: _request_route_local__Tterm5 = 1
 */

// Logic function of the simple state finalState25 in region region__EA_Entry6
static inline void region__EA_Entry6_statefinalState25(__EA_Entry6Context *context);
static inline void region__EA_Entry6(__EA_Entry6Context *context); // Region region__EA_Entry6

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC8
 *   Trigger: context->_actrl8context.threadStatus == TERMINATED &&
  context->__ea_entry6context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC8 in region region__EA_Entry5
static inline void region__EA_Entry5_state_AC8(__EA_Entry5Context *context);
/* Immediate
 *   Transition 0:
 *   _AC8
 *    to
 *   __sd_Depth32
 *   Trigger: context->iface->_request_route_local__Tterm5
 */

/* Immediate
 *   Transition 1:
 *   _AC8
 *    to
 *   finalState26
 */

// Logic function of the simple state __sd_Depth32 in region region__EA_Entry5
static inline void region__EA_Entry5_state__sd_Depth32(__EA_Entry5Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth32
 *    to
 *   __te_S21
 *   Effects: _request_route_local_i1 = _request_route_local_i1 + 1
 */

// Logic function of the simple state __te_S21 in region region__EA_Entry5
static inline void region__EA_Entry5_state__te_S21(__EA_Entry5Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S21
 *    to
 *   finalState26
 *   Effects: _request_route_local__Tterm4 = 1
 */

// Logic function of the simple state finalState26 in region region__EA_Entry5
static inline void region__EA_Entry5_statefinalState26(__EA_Entry5Context *context);
static inline void region__EA_Entry5(__EA_Entry5Context *context); // Region region__EA_Entry5

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC7
 *   Trigger: context->_actrl7context.threadStatus == TERMINATED &&
  context->__ea_entry5context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC7 in region region__EA_Entry4
static inline void region__EA_Entry4_state_AC7(__EA_Entry4Context *context);
/* Immediate
 *   Transition 0:
 *   _AC7
 *    to
 *   S3_3_31
 *   Trigger: context->iface->_request_route_local__Tterm4
 */

/* Immediate
 *   Transition 1:
 *   _AC7
 *    to
 *   finalState27
 */

// Logic function of the simple state S3_3_31 in region region__EA_Entry4
static inline void region__EA_Entry4_stateS3_3_31(__EA_Entry4Context *context);
/* Immediate
 *   Transition 0:
 *   S3_3_31
 *    to
 *   __EA_Init
 *   Trigger: context->iface->_request_route_local_i1 < context->iface->_request_route_local_flank_signals_count
 */

/* Immediate
 *   Transition 1:
 *   S3_3_31
 *    to
 *   finalState27
 *   Effects: _request_route_local__Tterm3 = 1
 */

// Logic function of the simple state finalState27 in region region__EA_Entry4
static inline void region__EA_Entry4_statefinalState27(__EA_Entry4Context *context);
static inline void region__EA_Entry4(__EA_Entry4Context *context); // Region region__EA_Entry4

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC6
 *   Trigger: context->_actrl6context.threadStatus == TERMINATED &&
  context->__ea_entry4context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC6 in region region__EA_Entry2
static inline void region__EA_Entry2_state_AC6(__EA_Entry2Context *context);
/* Immediate
 *   Transition 0:
 *   _AC6
 *    to
 *   _Tc
 *   Trigger: context->iface->_request_route_local__Tterm3
 */

/* Immediate
 *   Transition 1:
 *   _AC6
 *    to
 *   finalState28
 */

// Logic function of the simple state finalState28 in region region__EA_Entry2
static inline void region__EA_Entry2_statefinalState28(__EA_Entry2Context *context);
static inline void region__EA_Entry2(__EA_Entry2Context *context); // Region region__EA_Entry2

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC4
 *   Trigger: context->_actrl4context.threadStatus == TERMINATED &&
  context->__ea_entry2context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC4 in region regionregion0
static inline void regionregion0_state_AC4(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   _AC4
 *    to
 *   __EA_Init
 *   Trigger: context->iface->_request_route_local__Tterm1
 */

/* Immediate
 *   Transition 1:
 *   _AC4
 *    to
 *   __te_S26
 */

// Logic function of the simple state __EA_Init in region regionregion0
static inline void regionregion0_state__EA_Init4(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm7 = 0
 */

static inline void regionregion0_state__EA_Main4(Region0Context *context); // State __EA_Main  in region regionregion0 logic
static inline void regionregion0_state__EA_Main4running(Region0Context *context);
// Logic function of the simple state _ARun101 in region region_ACtrl10
static inline void region_ACtrl10_state_ARun101(_ACtrl10Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun101
 *    to
 *   finalState29
 *   Trigger: context->iface->_request_route_local__Tterm7
 */

/* Immediate
 *   Transition 1:
 *   _ARun101
 *    to
 *   finalState29
 */

// Logic function of the simple state finalState29 in region region_ACtrl10
static inline void region_ACtrl10_statefinalState29(_ACtrl10Context *context);
static inline void region_ACtrl10(_ACtrl10Context *context); // Region region_ACtrl10

// Logic function of the simple state S4_0 in region region__EA_Entry8
static inline void region__EA_Entry8_stateS4_0(__EA_Entry8Context *context);
/* Immediate
 *   Transition 0:
 *   S4_0
 *    to
 *   __EA_Init
 *   Trigger: context->iface->_request_route_local_result
 */

/* Immediate
 *   Transition 1:
 *   S4_0
 *    to
 *   _Tc
 */

// Logic function of the simple state __EA_Init in region region__EA_Entry8
static inline void region__EA_Entry8_state__EA_Init(__EA_Entry8Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm8 = 0
 */

static inline void region__EA_Entry8_state__EA_Main(__EA_Entry8Context *context); // State __EA_Main  in region region__EA_Entry8 logic
static inline void region__EA_Entry8_state__EA_Mainrunning(__EA_Entry8Context *context);
// Logic function of the simple state _ARun111 in region region_ACtrl11
static inline void region_ACtrl11_state_ARun111(_ACtrl11Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun111
 *    to
 *   finalState30
 *   Trigger: context->iface->_request_route_local__Tterm8
 */

/* Immediate
 *   Transition 1:
 *   _ARun111
 *    to
 *   finalState30
 *   Trigger: context->iface->_request_route_local__Tterm7 || 1
 */

// Logic function of the simple state finalState30 in region region_ACtrl11
static inline void region_ACtrl11_statefinalState30(_ACtrl11Context *context);
static inline void region_ACtrl11(_ACtrl11Context *context); // Region region_ACtrl11

// Logic function of the simple state __sd_Depth36 in region region__EA_Entry9
static inline void region__EA_Entry9_state__sd_Depth36(__EA_Entry9Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth36
 *    to
 *   S4_1_21
 *   Effects: _request_route_local_segment_ids_count = config_get_array_string_value("route", id, "path", _request_route_local_segment_ids)
 */

// Logic function of the simple state S4_1_21 in region region__EA_Entry9
static inline void region__EA_Entry9_stateS4_1_21(__EA_Entry9Context *context);
/* Immediate
 *   Transition 0:
 *   S4_1_21
 *    to
 *   S4_1_31
 *   Effects: _request_route_local_i2 = 0
 */

// Logic function of the simple state __EA_Init in region region__EA_Entry9
static inline void region__EA_Entry9_state__EA_Init(__EA_Entry9Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm9 = 0
 */

static inline void region__EA_Entry9_state__EA_Main(__EA_Entry9Context *context); // State __EA_Main  in region region__EA_Entry9 logic
static inline void region__EA_Entry9_state__EA_Mainrunning(__EA_Entry9Context *context);
// Logic function of the simple state _ARun121 in region region_ACtrl12
static inline void region_ACtrl12_state_ARun121(_ACtrl12Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun121
 *    to
 *   finalState31
 *   Trigger: context->iface->_request_route_local__Tterm9
 */

/* Immediate
 *   Transition 1:
 *   _ARun121
 *    to
 *   finalState31
 *   Trigger: context->iface->_request_route_local__Tterm8 || context->iface->_request_route_local__Tterm7 || 1
 */

// Logic function of the simple state finalState31 in region region_ACtrl12
static inline void region_ACtrl12_statefinalState31(_ACtrl12Context *context);
static inline void region_ACtrl12(_ACtrl12Context *context); // Region region_ACtrl12

// Logic function of the simple state S4_1_3_0_01 in region region__EA_Entry10
static inline void region__EA_Entry10_stateS4_1_3_0_01(__EA_Entry10Context *context);
/* Immediate
 *   Transition 0:
 *   S4_1_3_0_01
 *    to
 *   S4_1_3_0_11
 *   Effects: _request_route_local_segment_id = _request_route_local_segment_ids[_request_route_local_i2]
 */

// Logic function of the simple state S4_1_3_0_11 in region region__EA_Entry10
static inline void region__EA_Entry10_stateS4_1_3_0_11(__EA_Entry10Context *context);
/* Immediate
 *   Transition 0:
 *   S4_1_3_0_11
 *    to
 *   __EA_Init
 *   Effects: _request_route_local_oc = is_segment_occupied(_request_route_local_segment_id)
 */

// Logic function of the simple state __EA_Init in region region__EA_Entry10
static inline void region__EA_Entry10_state__EA_Init(__EA_Entry10Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm10 = 0
 */

static inline void region__EA_Entry10_state__EA_Main(__EA_Entry10Context *context); // State __EA_Main  in region region__EA_Entry10 logic
static inline void region__EA_Entry10_state__EA_Mainrunning(__EA_Entry10Context *context);
// Logic function of the simple state _ARun131 in region region_ACtrl13
static inline void region_ACtrl13_state_ARun131(_ACtrl13Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun131
 *    to
 *   finalState32
 *   Trigger: context->iface->_request_route_local__Tterm10
 */

/* Immediate
 *   Transition 1:
 *   _ARun131
 *    to
 *   finalState32
 *   Trigger: context->iface->_request_route_local__Tterm9 || context->iface->_request_route_local__Tterm8 || context->iface->_request_route_local__Tterm7 || 1
 */

// Logic function of the simple state finalState32 in region region_ACtrl13
static inline void region_ACtrl13_statefinalState32(_ACtrl13Context *context);
static inline void region_ACtrl13(_ACtrl13Context *context); // Region region_ACtrl13

// Logic function of the simple state S4_1_3_0_2_0 in region region__EA_Entry11
static inline void region__EA_Entry11_stateS4_1_3_0_2_0(__EA_Entry11Context *context);
/* Immediate
 *   Transition 0:
 *   S4_1_3_0_2_0
 *    to
 *   __EA_Init
 *   Trigger: context->iface->_request_route_local_oc
 */

/* Immediate
 *   Transition 1:
 *   S4_1_3_0_2_0
 *    to
 *   _Tc
 */

// Logic function of the simple state __EA_Init in region region__EA_Entry11
static inline void region__EA_Entry11_state__EA_Init(__EA_Entry11Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm11 = 0
 */

static inline void region__EA_Entry11_state__EA_Main(__EA_Entry11Context *context); // State __EA_Main  in region region__EA_Entry11 logic
static inline void region__EA_Entry11_state__EA_Mainrunning(__EA_Entry11Context *context);
// Logic function of the simple state _ARun141 in region region_ACtrl14
static inline void region_ACtrl14_state_ARun141(_ACtrl14Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun141
 *    to
 *   finalState33
 *   Trigger: context->iface->_request_route_local__Tterm11
 */

/* Immediate
 *   Transition 1:
 *   _ARun141
 *    to
 *   finalState33
 *   Trigger: context->iface->_request_route_local__Tterm10 || context->iface->_request_route_local__Tterm9 || context->iface->_request_route_local__Tterm8 || context->iface->_request_route_local__Tterm7 || 1
 */

// Logic function of the simple state finalState33 in region region_ACtrl14
static inline void region_ACtrl14_statefinalState33(_ACtrl14Context *context);
static inline void region_ACtrl14(_ACtrl14Context *context); // Region region_ACtrl14

// Logic function of the simple state __sd_Depth42 in region regionregion34
static inline void regionregion34_state__sd_Depth42(Region34Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth42
 *    to
 *   __te_S23
 *   Effects: _request_route_local_result = 0
 */

// Logic function of the simple state __te_S23 in region regionregion34
static inline void regionregion34_state__te_S23(Region34Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S23
 *    to
 *   finalState35
 *   Effects: _request_route_local__Tterm11 = 1
 */

// Logic function of the simple state finalState35 in region regionregion34
static inline void regionregion34_statefinalState35(Region34Context *context);
static inline void regionregion34(Region34Context *context); // Region regionregion34

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC14
 *   Trigger: context->_actrl14context.threadStatus == TERMINATED &&
  context->region34context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC14 in region region__EA_Entry11
static inline void region__EA_Entry11_state_AC14(__EA_Entry11Context *context);
/* Immediate
 *   Transition 0:
 *   _AC14
 *    to
 *   _Tc
 *   Trigger: context->iface->_request_route_local__Tterm11
 */

/* Immediate
 *   Transition 1:
 *   _AC14
 *    to
 *   finalState36
 */

// Logic function of the simple state _Tc in region region__EA_Entry11
static inline void region__EA_Entry11_state_Tc(__EA_Entry11Context *context);
/* Immediate
 *   Transition 0:
 *   _Tc
 *    to
 *   finalState36
 *   Effects: _request_route_local__Tterm10 = 1
 */

// Logic function of the simple state finalState36 in region region__EA_Entry11
static inline void region__EA_Entry11_statefinalState36(__EA_Entry11Context *context);
static inline void region__EA_Entry11(__EA_Entry11Context *context); // Region region__EA_Entry11

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC13
 *   Trigger: context->_actrl13context.threadStatus == TERMINATED &&
  context->__ea_entry11context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC13 in region region__EA_Entry10
static inline void region__EA_Entry10_state_AC13(__EA_Entry10Context *context);
/* Immediate
 *   Transition 0:
 *   _AC13
 *    to
 *   __sd_Depth45
 *   Trigger: context->iface->_request_route_local__Tterm10
 */

/* Immediate
 *   Transition 1:
 *   _AC13
 *    to
 *   finalState37
 */

// Logic function of the simple state __sd_Depth45 in region region__EA_Entry10
static inline void region__EA_Entry10_state__sd_Depth45(__EA_Entry10Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth45
 *    to
 *   __te_S25
 *   Effects: _request_route_local_i2 = _request_route_local_i2 + 1
 */

// Logic function of the simple state __te_S25 in region region__EA_Entry10
static inline void region__EA_Entry10_state__te_S25(__EA_Entry10Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S25
 *    to
 *   finalState37
 *   Effects: _request_route_local__Tterm9 = 1
 */

// Logic function of the simple state finalState37 in region region__EA_Entry10
static inline void region__EA_Entry10_statefinalState37(__EA_Entry10Context *context);
static inline void region__EA_Entry10(__EA_Entry10Context *context); // Region region__EA_Entry10

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC12
 *   Trigger: context->_actrl12context.threadStatus == TERMINATED &&
  context->__ea_entry10context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC12 in region region__EA_Entry9
static inline void region__EA_Entry9_state_AC12(__EA_Entry9Context *context);
/* Immediate
 *   Transition 0:
 *   _AC12
 *    to
 *   S4_1_31
 *   Trigger: context->iface->_request_route_local__Tterm9
 */

/* Immediate
 *   Transition 1:
 *   _AC12
 *    to
 *   finalState38
 */

// Logic function of the simple state S4_1_31 in region region__EA_Entry9
static inline void region__EA_Entry9_stateS4_1_31(__EA_Entry9Context *context);
/* Immediate
 *   Transition 0:
 *   S4_1_31
 *    to
 *   __EA_Init
 *   Trigger: context->iface->_request_route_local_i2 < context->iface->_request_route_local_segment_ids_count && context->iface->_request_route_local_result
 */

/* Immediate
 *   Transition 1:
 *   S4_1_31
 *    to
 *   finalState38
 *   Effects: _request_route_local__Tterm8 = 1
 */

// Logic function of the simple state finalState38 in region region__EA_Entry9
static inline void region__EA_Entry9_statefinalState38(__EA_Entry9Context *context);
static inline void region__EA_Entry9(__EA_Entry9Context *context); // Region region__EA_Entry9

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC11
 *   Trigger: context->_actrl11context.threadStatus == TERMINATED &&
  context->__ea_entry9context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC11 in region region__EA_Entry8
static inline void region__EA_Entry8_state_AC11(__EA_Entry8Context *context);
/* Immediate
 *   Transition 0:
 *   _AC11
 *    to
 *   _Tc
 *   Trigger: context->iface->_request_route_local__Tterm8
 */

/* Immediate
 *   Transition 1:
 *   _AC11
 *    to
 *   finalState39
 */

// Logic function of the simple state _Tc in region region__EA_Entry8
static inline void region__EA_Entry8_state_Tc(__EA_Entry8Context *context);
/* Immediate
 *   Transition 0:
 *   _Tc
 *    to
 *   finalState39
 *   Effects: _request_route_local__Tterm7 = 1
 */

// Logic function of the simple state finalState39 in region region__EA_Entry8
static inline void region__EA_Entry8_statefinalState39(__EA_Entry8Context *context);
static inline void region__EA_Entry8(__EA_Entry8Context *context); // Region region__EA_Entry8

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC10
 *   Trigger: context->_actrl10context.threadStatus == TERMINATED &&
  context->__ea_entry8context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC10 in region regionregion0
static inline void regionregion0_state_AC10(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   _AC10
 *    to
 *   S53
 *   Trigger: context->iface->_request_route_local__Tterm7
 */

/* Immediate
 *   Transition 1:
 *   _AC10
 *    to
 *   __te_S26
 */

// Logic function of the simple state S53 in region regionregion0
static inline void regionregion0_stateS53(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S53
 *    to
 *   __te_S26
 *   Effects: _request_route_local_is_clear = _request_route_local_result
 */

// Logic function of the simple state __te_S26 in region regionregion0
static inline void regionregion0_state__te_S26(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S26
 *    to
 *   S4_3_1_01
 *   Effects: _taken_transitions[10] += 1
 */

// Logic function of the simple state __te_S6 in region regionregion0
static inline void regionregion0_state__te_S6(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S6
 *    to
 *   __sd_Depth4
 *   Effects: _taken_transitions[12] += 1
 */

// Logic function of the simple state __sd_Depth4 in region regionregion0
static inline void regionregion0_state__sd_Depth4(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth4
 *    to
 *   __te_S8
 *   Effects: id = ""
 */

// Logic function of the simple state __te_S8 in region regionregion0
static inline void regionregion0_state__te_S8(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S8
 *    to
 *   __te_S9
 *   Effects: _taken_transitions[15] += 1
 */

// Logic function of the simple state __te_S9 in region regionregion0
static inline void regionregion0_state__te_S9(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S9
 *    to
 *   __te_S15
 *   Effects: _taken_transitions[14] += 1
 */

// Logic function of the simple state __te_S15 in region regionregion0
static inline void regionregion0_state__te_S15(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S15
 *    to
 *   __te_S27
 *   Effects: _taken_transitions[11] += 1
 */

// Logic function of the simple state __te_S27 in region regionregion0
static inline void regionregion0_state__te_S27(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S27
 *    to
 *   __te_S28
 *   Effects: _taken_transitions[9] += 1
 */

// Logic function of the simple state S4_3_1_01 in region regionregion0
static inline void regionregion0_stateS4_3_1_01(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S4_3_1_01
 *    to
 *   __te_S6
 *   Trigger: !context->iface->_request_route_local_is_clear
 */

/* Immediate
 *   Transition 1:
 *   S4_3_1_01
 *    to
 *   S01
 *   Effects: _taken_transitions[13] += 1
 */

// Logic function of the simple state S01 in region regionregion0
static inline void regionregion0_stateS01(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S01
 *    to
 *   __te_S10
 *   Effects: _request_route_local_success = config_set_scalar_string_value("route", id, "train", train_id)
 */

// Logic function of the simple state __te_S10 in region regionregion0
static inline void regionregion0_state__te_S10(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S10
 *    to
 *   __sd_Depth7
 *   Effects: _taken_transitions[17] += 1
 */

// Logic function of the simple state __sd_Depth7 in region regionregion0
static inline void regionregion0_state__sd_Depth7(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth7
 *    to
 *   S21
 *   Effects: _request_route_local_points_count = config_get_array_string_value("route", id, "points", _request_route_local_point_ids)
 */

// Logic function of the simple state S21 in region regionregion0
static inline void regionregion0_stateS21(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S21
 *    to
 *   S41
 *   Effects: _request_route_local_i = 0
 */

// Logic function of the simple state __EA_Init in region regionregion0
static inline void regionregion0_state__EA_Init5(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __EA_Init
 *    to
 *   __EA_Main
 *   Effects: _request_route_local__Tterm = 0
 */

static inline void regionregion0_state__EA_Main5(Region0Context *context); // State __EA_Main  in region regionregion0 logic
static inline void regionregion0_state__EA_Main5running(Region0Context *context);
// Logic function of the simple state _ARun24 in region region_ACtrl2
static inline void region_ACtrl2_state_ARun24(_ACtrl2Context *context);
/* Immediate
 *   Transition 0:
 *   _ARun24
 *    to
 *   finalState40
 *   Trigger: context->iface->_request_route_local__Tterm
 */

/* Immediate
 *   Transition 1:
 *   _ARun24
 *    to
 *   finalState40
 */

// Logic function of the simple state finalState40 in region region_ACtrl2
static inline void region_ACtrl2_statefinalState40(_ACtrl2Context *context);
static inline void region_ACtrl2(_ACtrl2Context *context); // Region region_ACtrl2

// Logic function of the simple state S3_0_01 in region regionregion41
static inline void regionregion41_stateS3_0_01(Region41Context *context);
/* Immediate
 *   Transition 0:
 *   S3_0_01
 *    to
 *   S3_0_11
 *   Effects: _request_route_local_point_id = _request_route_local_point_ids[_request_route_local_i]
 */

// Logic function of the simple state S3_0_11 in region regionregion41
static inline void regionregion41_stateS3_0_11(Region41Context *context);
/* Immediate
 *   Transition 0:
 *   S3_0_11
 *    to
 *   S3_0_21
 *   Effects: _request_route_local_point_position = config_get_scalar_string_value("route_point", _request_route_local_point_id, "position")
 */

// Logic function of the simple state S3_0_21 in region regionregion41
static inline void regionregion41_stateS3_0_21(Region41Context *context);
/* Immediate
 *   Transition 0:
 *   S3_0_21
 *    to
 *   __sd_Depth13
 *   Effects: _request_route_local_success1 = track_state_set_value("point", _request_route_local_point_id, _request_route_local_point_position)
 */

// Logic function of the simple state __sd_Depth13 in region regionregion41
static inline void regionregion41_state__sd_Depth13(Region41Context *context);
/* Immediate
 *   Transition 0:
 *   __sd_Depth13
 *    to
 *   __te_S12
 *   Effects: _request_route_local_i = _request_route_local_i + 1
 */

// Logic function of the simple state __te_S12 in region regionregion41
static inline void regionregion41_state__te_S12(Region41Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S12
 *    to
 *   finalState42
 *   Effects: _request_route_local__Tterm = 1
 */

// Logic function of the simple state finalState42 in region regionregion41
static inline void regionregion41_statefinalState42(Region41Context *context);
static inline void regionregion41(Region41Context *context); // Region regionregion41

/* Immediate
 *   Transition 0:
 *   __EA_Main
 *    to
 *   _AC2
 *   Trigger: context->_actrl2context.threadStatus == TERMINATED &&
  context->region41context.threadStatus == TERMINATED
 */

// Logic function of the simple state _AC2 in region regionregion0
static inline void regionregion0_state_AC2(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   _AC2
 *    to
 *   S41
 *   Trigger: context->iface->_request_route_local__Tterm
 */

/* Immediate
 *   Transition 1:
 *   _AC2
 *    to
 *   __te_S13
 */

// Logic function of the simple state __te_S13 in region regionregion0
static inline void regionregion0_state__te_S13(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S13
 *    to
 *   __te_S14
 *   Effects: _taken_transitions[18] += 1
 */

// Logic function of the simple state __te_S14 in region regionregion0
static inline void regionregion0_state__te_S14(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   __te_S14
 *    to
 *   __te_S15
 *   Effects: _taken_transitions[16] += 1
 */

// Logic function of the simple state S41 in region regionregion0
static inline void regionregion0_stateS41(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S41
 *    to
 *   __EA_Init
 *   Trigger: context->iface->_request_route_local_i < context->iface->_request_route_local_points_count
 */

/* Immediate
 *   Transition 1:
 *   S41
 *    to
 *   S52
 *   Effects: _request_route_local__src_signal_id_ = config_get_scalar_string_value("route", id, "source")
 */

// Logic function of the simple state S52 in region regionregion0
static inline void regionregion0_stateS52(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S52
 *    to
 *   __te_S13
 *   Effects: _request_route_local_success2 = track_state_set_value("signal", _request_route_local__src_signal_id_, "green")
 */

// Logic function of the simple state S63 in region regionregion0
static inline void regionregion0_stateS63(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S63
 *    to
 *   __EA_Init
 *   Trigger: context->iface->_request_route_local_i4 < context->iface->_request_route_local_count_conflict_routes
 */

/* Immediate
 *   Transition 1:
 *   S63
 *    to
 *   __te_S40
 *   Effects: is_grantable = _request_route_local_result2
 */

// Logic function of the simple state S42 in region regionregion0
static inline void regionregion0_stateS42(Region0Context *context);
/* Immediate
 *   Transition 0:
 *   S42
 *    to
 *   __EA_Init
 *   Trigger: context->iface->_request_route_local_i3 < context->iface->count_routes
 */

/* Immediate
 *   Transition 1:
 *   S42
 *    to
 *   __te_S35
 *   Effects: id = route_ids[_request_route_local_result1]
 */

// Logic function of the simple state finalState43 in region regionregion0
static inline void regionregion0_statefinalState43(Region0Context *context);
static inline void regionregion0(Region0Context *context); // Region regionregion0


#endif