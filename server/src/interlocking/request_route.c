/*
 * Automatically generated C code by
 * KIELER SCCharts - The Key to Efficient Modeling
 *
 * http://rtsys.informatik.uni-kiel.de/kieler
 */

#include "request_route.h"
#include "bahn_data_util.h"

/* reset() sets the program to its initial state.
 * You should call reset() at least once at the start of the application.
 * Additionally, you can always reset the actual status to the initial configuration
 * to restart the application.
 */
void reset(TickData *context) {
    context->region0context.iface = &(context->iface);
    context->region0context._actrl16context.iface = &(context->iface);
    context->region0context.__ea_entry13context.iface = &(context->iface);
    context->region0context.__ea_entry13context._actrl17context.iface = &(context->iface);
    context->region0context.__ea_entry13context.__ea_entry14context.iface = &(context->iface);
    context->region0context.__ea_entry13context.__ea_entry14context._actrl18context.iface = &(context->iface);
    context->region0context.__ea_entry13context.__ea_entry14context.region4context.iface = &(context->iface);
    context->region0context._actrl20context.iface = &(context->iface);
    context->region0context.__ea_entry16context.iface = &(context->iface);
    context->region0context.__ea_entry16context._actrl21context.iface = &(context->iface);
    context->region0context.__ea_entry16context.__ea_entry17context.iface = &(context->iface);
    context->region0context.__ea_entry16context.__ea_entry17context._actrl22context.iface = &(context->iface);
    context->region0context.__ea_entry16context.__ea_entry17context.region11context.iface = &(context->iface);
    context->region0context._actrl4context.iface = &(context->iface);
    context->region0context.__ea_entry2context.iface = &(context->iface);
    context->region0context.__ea_entry2context._actrl5context.iface = &(context->iface);
    context->region0context.__ea_entry2context.region17context.iface = &(context->iface);
    context->region0context.__ea_entry2context._actrl6context.iface = &(context->iface);
    context->region0context.__ea_entry2context.__ea_entry4context.iface = &(context->iface);
    context->region0context.__ea_entry2context.__ea_entry4context._actrl7context.iface = &(context->iface);
    context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context.iface = &(context->iface);
    context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context._actrl8context.iface = &(context->iface);
    context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context.__ea_entry6context.iface = &(context->iface);
    context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context.__ea_entry6context._actrl9context.iface = &(context->iface);
    context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context.__ea_entry6context.region23context.iface = &(context->iface);
    context->region0context._actrl10context.iface = &(context->iface);
    context->region0context.__ea_entry8context.iface = &(context->iface);
    context->region0context.__ea_entry8context._actrl11context.iface = &(context->iface);
    context->region0context.__ea_entry8context.__ea_entry9context.iface = &(context->iface);
    context->region0context.__ea_entry8context.__ea_entry9context._actrl12context.iface = &(context->iface);
    context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context.iface = &(context->iface);
    context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context._actrl13context.iface = &(context->iface);
    context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context.__ea_entry11context.iface = &(context->iface);
    context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context.__ea_entry11context._actrl14context.iface = &(context->iface);
    context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context.__ea_entry11context.region34context.iface = &(context->iface);
    context->region0context._actrl2context.iface = &(context->iface);
    context->region0context.region41context.iface = &(context->iface);

    context->region0context.activeState = __SD_DEPTH79;
    context->region0context.delayedEnabled = 0;
    context->region0context.activePriority = 0;
    context->region0context.threadStatus = READY;
    context->activePriority = 0;
    context->threadStatus = RUNNING;
}

// Logic function of the superstate request_route
static inline void staterequest_routerunning(TickData *context) {
// Set the thread status to waiting for the upcoming tick.
    context->region0context.threadStatus = RUNNING;
    // Call the logic code of thread regionregion0.
    regionregion0(&context->region0context);

    if (context->region0context.threadStatus == TERMINATED) {
        context->threadStatus = TERMINATED;
    }
}

// Function of region regionregion0
static inline void regionregion0(Region0Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case __SD_DEPTH79:
                regionregion0_state__sd_Depth79(context);
                break;

            case __TE_S42:
                regionregion0_state__te_S42(context);
                break;

            case __TE_S43:
                regionregion0_state__te_S43(context);
                break;

            case __TE_S44:
                regionregion0_state__te_S44(context);
                break;

            case __TE_S45:
                regionregion0_state__te_S45(context);
                break;

            case __TE_S46:
                regionregion0_state__te_S46(context);
                break;

            case __TE_S47:
                regionregion0_state__te_S47(context);
                break;

            case __TE_S48:
                regionregion0_state__te_S48(context);
                break;

            case __TE_S49:
                regionregion0_state__te_S49(context);
                break;

            case __TE_S50:
                regionregion0_state__te_S50(context);
                break;

            case __TE_S51:
                regionregion0_state__te_S51(context);
                break;

            case __TE_S52:
                regionregion0_state__te_S52(context);
                break;

            case __TE_S53:
                regionregion0_state__te_S53(context);
                break;

            case __TE_S54:
                regionregion0_state__te_S54(context);
                break;

            case __TE_S55:
                regionregion0_state__te_S55(context);
                break;

            case __TE_S56:
                regionregion0_state__te_S56(context);
                break;

            case __TE_S57:
                regionregion0_state__te_S57(context);
                break;

            case __TE_S58:
                regionregion0_state__te_S58(context);
                break;

            case __TE_S59:
                regionregion0_state__te_S59(context);
                break;

            case __TE_S60:
                regionregion0_state__te_S60(context);
                break;

            case S0:
                regionregion0_stateS0(context);
                break;

            case __SD_DEPTH:
                regionregion0_state__sd_Depth(context);
                break;

            case __TE_S1:
                regionregion0_state__te_S1(context);
                break;

            case S04:
                regionregion0_stateS04(context);
                break;

            case S15:
                regionregion0_stateS15(context);
                break;

            case S23:
                regionregion0_stateS23(context);
                break;

            case __EA_INIT13:
                regionregion0_state__EA_Init(context);
                break;

            case __EA_MAIN14:
                regionregion0_state__EA_Main(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN14RUNNING:
                regionregion0_state__EA_Mainrunning(context);
                break;

            case _AC16:
                regionregion0_state_AC16(context);
                break;

            case __TE_S35:
                regionregion0_state__te_S35(context);
                break;

            case S05:
                regionregion0_stateS05(context);
                break;

            case __SD_DEPTH66:
                regionregion0_state__sd_Depth66(context);
                break;

            case S31:
                regionregion0_stateS31(context);
                break;

            case S43:
                regionregion0_stateS43(context);
                break;

            case __EA_INIT14:
                regionregion0_state__EA_Init2(context);
                break;

            case __EA_MAIN15:
                regionregion0_state__EA_Main2(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN15RUNNING:
                regionregion0_state__EA_Main2running(context);
                break;

            case _AC20:
                regionregion0_state_AC20(context);
                break;

            case __TE_S40:
                regionregion0_state__te_S40(context);
                break;

            case __TE_S2:
                regionregion0_state__te_S2(context);
                break;

            case __SD_DEPTH2:
                regionregion0_state__sd_Depth2(context);
                break;

            case __TE_S4:
                regionregion0_state__te_S4(context);
                break;

            case __TE_S5:
                regionregion0_state__te_S5(context);
                break;

            case __TE_S28:
                regionregion0_state__te_S28(context);
                break;

            case __SD_DEPTH51:
                regionregion0_state__sd_Depth51(context);
                break;

            case __TE_S30:
                regionregion0_state__te_S30(context);
                break;

            case S4_01:
                regionregion0_stateS4_01(context);
                break;

            case S03:
                regionregion0_stateS03(context);
                break;

            case S14:
                regionregion0_stateS14(context);
                break;

            case S22:
                regionregion0_stateS22(context);
                break;

            case __EA_INIT15:
                regionregion0_state__EA_Init3(context);
                break;

            case __EA_MAIN16:
                regionregion0_state__EA_Main3(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN16RUNNING:
                regionregion0_state__EA_Main3running(context);
                break;

            case _AC4:
                regionregion0_state_AC4(context);
                break;

            case __EA_INIT16:
                regionregion0_state__EA_Init4(context);
                break;

            case __EA_MAIN17:
                regionregion0_state__EA_Main4(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN17RUNNING:
                regionregion0_state__EA_Main4running(context);
                break;

            case _AC10:
                regionregion0_state_AC10(context);
                break;

            case S53:
                regionregion0_stateS53(context);
                break;

            case __TE_S26:
                regionregion0_state__te_S26(context);
                break;

            case __TE_S6:
                regionregion0_state__te_S6(context);
                break;

            case __SD_DEPTH4:
                regionregion0_state__sd_Depth4(context);
                break;

            case __TE_S8:
                regionregion0_state__te_S8(context);
                break;

            case __TE_S9:
                regionregion0_state__te_S9(context);
                break;

            case __TE_S15:
                regionregion0_state__te_S15(context);
                break;

            case __TE_S27:
                regionregion0_state__te_S27(context);
                break;

            case S4_3_1_01:
                regionregion0_stateS4_3_1_01(context);
                break;

            case S01:
                regionregion0_stateS01(context);
                break;

            case __TE_S10:
                regionregion0_state__te_S10(context);
                break;

            case __SD_DEPTH7:
                regionregion0_state__sd_Depth7(context);
                break;

            case S21:
                regionregion0_stateS21(context);
                break;

            case __EA_INIT17:
                regionregion0_state__EA_Init5(context);
                break;

            case __EA_MAIN18:
                regionregion0_state__EA_Main5(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN18RUNNING:
                regionregion0_state__EA_Main5running(context);
                break;

            case _AC2:
                regionregion0_state_AC2(context);
                break;

            case __TE_S13:
                regionregion0_state__te_S13(context);
                break;

            case __TE_S14:
                regionregion0_state__te_S14(context);
                break;

            case S41:
                regionregion0_stateS41(context);
                break;

            case S52:
                regionregion0_stateS52(context);
                break;

            case S63:
                regionregion0_stateS63(context);
                break;

            case S42:
                regionregion0_stateS42(context);
                break;

            case FINALSTATE43:
                regionregion0_statefinalState43(context);
                break;

        }
    }
}

// Logic function of the simple state __sd_Depth79 in region regionregion0
static inline void regionregion0_state__sd_Depth79(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth79
     *    to
     *   __te_S42
     *   Effects: _taken_transitions[0] = 0
     */
    context->iface->_taken_transitions[0] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S42;
}

// Logic function of the simple state __te_S42 in region regionregion0
static inline void regionregion0_state__te_S42(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S42
     *    to
     *   __te_S43
     *   Effects: _taken_transitions[1] = 0
     */
    context->iface->_taken_transitions[1] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S43;
}

// Logic function of the simple state __te_S43 in region regionregion0
static inline void regionregion0_state__te_S43(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S43
     *    to
     *   __te_S44
     *   Effects: _taken_transitions[2] = 0
     */
    context->iface->_taken_transitions[2] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S44;
}

// Logic function of the simple state __te_S44 in region regionregion0
static inline void regionregion0_state__te_S44(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S44
     *    to
     *   __te_S45
     *   Effects: _taken_transitions[3] = 0
     */
    context->iface->_taken_transitions[3] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S45;
}

// Logic function of the simple state __te_S45 in region regionregion0
static inline void regionregion0_state__te_S45(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S45
     *    to
     *   __te_S46
     *   Effects: _taken_transitions[4] = 0
     */
    context->iface->_taken_transitions[4] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S46;
}

// Logic function of the simple state __te_S46 in region regionregion0
static inline void regionregion0_state__te_S46(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S46
     *    to
     *   __te_S47
     *   Effects: _taken_transitions[5] = 0
     */
    context->iface->_taken_transitions[5] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S47;
}

// Logic function of the simple state __te_S47 in region regionregion0
static inline void regionregion0_state__te_S47(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S47
     *    to
     *   __te_S48
     *   Effects: _taken_transitions[6] = 0
     */
    context->iface->_taken_transitions[6] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S48;
}

// Logic function of the simple state __te_S48 in region regionregion0
static inline void regionregion0_state__te_S48(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S48
     *    to
     *   __te_S49
     *   Effects: _taken_transitions[7] = 0
     */
    context->iface->_taken_transitions[7] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S49;
}

// Logic function of the simple state __te_S49 in region regionregion0
static inline void regionregion0_state__te_S49(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S49
     *    to
     *   __te_S50
     *   Effects: _taken_transitions[8] = 0
     */
    context->iface->_taken_transitions[8] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S50;
}

// Logic function of the simple state __te_S50 in region regionregion0
static inline void regionregion0_state__te_S50(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S50
     *    to
     *   __te_S51
     *   Effects: _taken_transitions[9] = 0
     */
    context->iface->_taken_transitions[9] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S51;
}

// Logic function of the simple state __te_S51 in region regionregion0
static inline void regionregion0_state__te_S51(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S51
     *    to
     *   __te_S52
     *   Effects: _taken_transitions[10] = 0
     */
    context->iface->_taken_transitions[10] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S52;
}

// Logic function of the simple state __te_S52 in region regionregion0
static inline void regionregion0_state__te_S52(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S52
     *    to
     *   __te_S53
     *   Effects: _taken_transitions[11] = 0
     */
    context->iface->_taken_transitions[11] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S53;
}

// Logic function of the simple state __te_S53 in region regionregion0
static inline void regionregion0_state__te_S53(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S53
     *    to
     *   __te_S54
     *   Effects: _taken_transitions[12] = 0
     */
    context->iface->_taken_transitions[12] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S54;
}

// Logic function of the simple state __te_S54 in region regionregion0
static inline void regionregion0_state__te_S54(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S54
     *    to
     *   __te_S55
     *   Effects: _taken_transitions[13] = 0
     */
    context->iface->_taken_transitions[13] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S55;
}

// Logic function of the simple state __te_S55 in region regionregion0
static inline void regionregion0_state__te_S55(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S55
     *    to
     *   __te_S56
     *   Effects: _taken_transitions[14] = 0
     */
    context->iface->_taken_transitions[14] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S56;
}

// Logic function of the simple state __te_S56 in region regionregion0
static inline void regionregion0_state__te_S56(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S56
     *    to
     *   __te_S57
     *   Effects: _taken_transitions[15] = 0
     */
    context->iface->_taken_transitions[15] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S57;
}

// Logic function of the simple state __te_S57 in region regionregion0
static inline void regionregion0_state__te_S57(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S57
     *    to
     *   __te_S58
     *   Effects: _taken_transitions[16] = 0
     */
    context->iface->_taken_transitions[16] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S58;
}

// Logic function of the simple state __te_S58 in region regionregion0
static inline void regionregion0_state__te_S58(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S58
     *    to
     *   __te_S59
     *   Effects: _taken_transitions[17] = 0
     */
    context->iface->_taken_transitions[17] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S59;
}

// Logic function of the simple state __te_S59 in region regionregion0
static inline void regionregion0_state__te_S59(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S59
     *    to
     *   __te_S60
     *   Effects: _taken_transitions[18] = 0
     */
    context->iface->_taken_transitions[18] = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S60;
}

// Logic function of the simple state __te_S60 in region regionregion0
static inline void regionregion0_state__te_S60(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S60
     *    to
     *   S0
     *   Effects: _taken_transitions[19] = 0
     */
    context->iface->_taken_transitions[19] = 0;
    context->delayedEnabled = 0;
    context->activeState = S0;
}

// Logic function of the simple state S0 in region regionregion0
static inline void regionregion0_stateS0(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   S0
     *    to
     *   __sd_Depth
     *   Effects: _taken_transitions[0] += 1
     */
    context->iface->_taken_transitions[0] += 1;
    context->delayedEnabled = 0;
    context->activeState = __SD_DEPTH;
}

// Logic function of the simple state __sd_Depth in region regionregion0
static inline void regionregion0_state__sd_Depth(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth
     *    to
     *   __te_S1
     *   Effects: count_routes = interlocking_table_get_routes(src_signal_id, dst_signal_id, route_ids)
     */
    context->iface->count_routes = interlocking_table_get_routes(context->iface->src_signal_id, context->iface->dst_signal_id, context->iface->route_ids);
    context->delayedEnabled = 0;
    context->activeState = __TE_S1;
}

// Logic function of the simple state __te_S1 in region regionregion0
static inline void regionregion0_state__te_S1(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S1
     *    to
     *   S04
     *   Effects: _taken_transitions[1] += 1
     */
    context->iface->_taken_transitions[1] += 1;
    context->delayedEnabled = 0;
    context->activeState = S04;
}

// Logic function of the simple state S04 in region regionregion0
static inline void regionregion0_stateS04(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   S04
     *    to
     *   S15
     *   Effects: _request_route_local_min_len = 2147483647
     */
    context->iface->_request_route_local_min_len = 2147483647;
    context->delayedEnabled = 0;
    context->activeState = S15;
}

// Logic function of the simple state S15 in region regionregion0
static inline void regionregion0_stateS15(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   S15
     *    to
     *   S23
     *   Effects: _request_route_local_i3 = 0
     */
    context->iface->_request_route_local_i3 = 0;
    context->delayedEnabled = 0;
    context->activeState = S23;
}

// Logic function of the simple state S23 in region regionregion0
static inline void regionregion0_stateS23(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   S23
     *    to
     *   S42
     *   Effects: _request_route_local_result1 = 0
     */
    context->iface->_request_route_local_result1 = 0;
    context->delayedEnabled = 0;
    context->activeState = S42;
}

// Logic function of the simple state __EA_Init in region regionregion0
static inline void regionregion0_state__EA_Init(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm12 = 0
     */
    context->iface->_request_route_local__Tterm12 = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN14;
}

// Init function of superstate __EA_Main in region regionregion0
static inline void regionregion0_state__EA_Main(Region0Context *context) {
    context->activeState = __EA_MAIN14RUNNING;
    context->_actrl16context.activeState = _ARUN161;
    context->_actrl16context.delayedEnabled = 0;
    context->_actrl16context.activePriority = 0;
    context->_actrl16context.threadStatus = READY;
    context->__ea_entry13context.activeState = S3_0_02;
    context->__ea_entry13context.delayedEnabled = 0;
    context->__ea_entry13context.activePriority = 0;
    context->__ea_entry13context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region regionregion0
static inline void regionregion0_state__EA_Mainrunning(Region0Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl16context.threadStatus == READY) {
        if (context->_actrl16context.activePriority == activePriority) {
            context->_actrl16context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl16.
            region_ACtrl16(&context->_actrl16context);
        }
        if (context->_actrl16context.threadStatus == READY) {
            if (context->_actrl16context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl16context.activePriority;
            }
        }
    }
    if (context->__ea_entry13context.threadStatus == READY) {
        if (context->__ea_entry13context.activePriority == activePriority) {
            context->__ea_entry13context.threadStatus = RUNNING;
            // Call the logic code of thread region__EA_Entry13.
            region__EA_Entry13(&context->__ea_entry13context);
        }
        if (context->__ea_entry13context.threadStatus == READY) {
            if (context->__ea_entry13context.activePriority > newActivePriority) {
                newActivePriority = context->__ea_entry13context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl16context.threadStatus != READY &&
        context->__ea_entry13context.threadStatus != READY) {
        if ((context->_actrl16context.activePriority > context->activePriority) &&
            (context->_actrl16context.threadStatus == PAUSING))
            context->activePriority = context->_actrl16context.activePriority;
        if ((context->__ea_entry13context.activePriority > context->activePriority) &&
            (context->__ea_entry13context.threadStatus == PAUSING))
            context->activePriority = context->__ea_entry13context.activePriority;
    }
    if (context->_actrl16context.threadStatus == TERMINATED &&
        context->__ea_entry13context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC16
     *   Trigger: context->_actrl16context.threadStatus == TERMINATED &&
    context->__ea_entry13context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC16;
    } else {
        if (context->_actrl16context.threadStatus == READY ||
            context->__ea_entry13context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl16
static inline void region_ACtrl16(_ACtrl16Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN161:
                region_ACtrl16_state_ARun161(context);
                break;

            case FINALSTATE1:
                region_ACtrl16_statefinalState1(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun161 in region region_ACtrl16
static inline void region_ACtrl16_state_ARun161(_ACtrl16Context *context) {
    if (context->iface->_request_route_local__Tterm12) {
        /* Immediate
     *   Transition 0:
     *   _ARun161
     *    to
     *   finalState1
     *   Trigger: context->iface->_request_route_local__Tterm12
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE1;
    } else {
        /* Immediate
     *   Transition 1:
     *   _ARun161
     *    to
     *   finalState1
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE1;
    }
}

// Logic function of the simple state finalState1 in region region_ACtrl16
static inline void region_ACtrl16_statefinalState1(_ACtrl16Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region region__EA_Entry13
static inline void region__EA_Entry13(__EA_Entry13Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case S3_0_02:
                region__EA_Entry13_stateS3_0_02(context);
                break;

            case S3_0_12:
                region__EA_Entry13_stateS3_0_12(context);
                break;

            case __EA_INIT2:
                region__EA_Entry13_state__EA_Init(context);
                break;

            case __EA_MAIN2:
                region__EA_Entry13_state__EA_Main(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN2RUNNING:
                region__EA_Entry13_state__EA_Mainrunning(context);
                break;

            case _AC17:
                region__EA_Entry13_state_AC17(context);
                break;

            case __SD_DEPTH61:
                region__EA_Entry13_state__sd_Depth61(context);
                break;

            case __TE_S34:
                region__EA_Entry13_state__te_S34(context);
                break;

            case FINALSTATE7:
                region__EA_Entry13_statefinalState7(context);
                break;

        }
    }
}

// Logic function of the simple state S3_0_02 in region region__EA_Entry13
static inline void region__EA_Entry13_stateS3_0_02(__EA_Entry13Context *context) {
    /* Immediate
     *   Transition 0:
     *   S3_0_02
     *    to
     *   S3_0_12
     *   Effects: _request_route_local_route_id = route_ids[_request_route_local_i3]
     */
    context->iface->_request_route_local_route_id = context->iface->route_ids[context->iface->_request_route_local_i3];
    context->delayedEnabled = 0;
    context->activeState = S3_0_12;
}

// Logic function of the simple state S3_0_12 in region region__EA_Entry13
static inline void region__EA_Entry13_stateS3_0_12(__EA_Entry13Context *context) {
    /* Immediate
     *   Transition 0:
     *   S3_0_12
     *    to
     *   __EA_Init
     *   Effects: _request_route_local_len = config_get_scalar_float_value("route", _request_route_local_route_id, "length")
     */
    context->iface->_request_route_local_len = config_get_scalar_float_value("route", context->iface->_request_route_local_route_id, "length");
    context->delayedEnabled = 0;
    context->activeState = __EA_INIT2;
}

// Logic function of the simple state __EA_Init in region region__EA_Entry13
static inline void region__EA_Entry13_state__EA_Init(__EA_Entry13Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm13 = 0
     */
    context->iface->_request_route_local__Tterm13 = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN2;
}

// Init function of superstate __EA_Main in region region__EA_Entry13
static inline void region__EA_Entry13_state__EA_Main(__EA_Entry13Context *context) {
    context->activeState = __EA_MAIN2RUNNING;
    context->_actrl17context.activeState = _ARUN171;
    context->_actrl17context.delayedEnabled = 0;
    context->_actrl17context.activePriority = 0;
    context->_actrl17context.threadStatus = READY;
    context->__ea_entry14context.activeState = S3_0_2_0;
    context->__ea_entry14context.delayedEnabled = 0;
    context->__ea_entry14context.activePriority = 0;
    context->__ea_entry14context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region region__EA_Entry13
static inline void region__EA_Entry13_state__EA_Mainrunning(__EA_Entry13Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl17context.threadStatus == READY) {
        if (context->_actrl17context.activePriority == activePriority) {
            context->_actrl17context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl17.
            region_ACtrl17(&context->_actrl17context);
        }
        if (context->_actrl17context.threadStatus == READY) {
            if (context->_actrl17context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl17context.activePriority;
            }
        }
    }
    if (context->__ea_entry14context.threadStatus == READY) {
        if (context->__ea_entry14context.activePriority == activePriority) {
            context->__ea_entry14context.threadStatus = RUNNING;
            // Call the logic code of thread region__EA_Entry14.
            region__EA_Entry14(&context->__ea_entry14context);
        }
        if (context->__ea_entry14context.threadStatus == READY) {
            if (context->__ea_entry14context.activePriority > newActivePriority) {
                newActivePriority = context->__ea_entry14context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl17context.threadStatus != READY &&
        context->__ea_entry14context.threadStatus != READY) {
        if ((context->_actrl17context.activePriority > context->activePriority) &&
            (context->_actrl17context.threadStatus == PAUSING))
            context->activePriority = context->_actrl17context.activePriority;
        if ((context->__ea_entry14context.activePriority > context->activePriority) &&
            (context->__ea_entry14context.threadStatus == PAUSING))
            context->activePriority = context->__ea_entry14context.activePriority;
    }
    if (context->_actrl17context.threadStatus == TERMINATED &&
        context->__ea_entry14context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC17
     *   Trigger: context->_actrl17context.threadStatus == TERMINATED &&
    context->__ea_entry14context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC17;
    } else {
        if (context->_actrl17context.threadStatus == READY ||
            context->__ea_entry14context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl17
static inline void region_ACtrl17(_ACtrl17Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN171:
                region_ACtrl17_state_ARun171(context);
                break;

            case FINALSTATE2:
                region_ACtrl17_statefinalState2(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun171 in region region_ACtrl17
static inline void region_ACtrl17_state_ARun171(_ACtrl17Context *context) {
    if (context->iface->_request_route_local__Tterm13) {
        /* Immediate
     *   Transition 0:
     *   _ARun171
     *    to
     *   finalState2
     *   Trigger: context->iface->_request_route_local__Tterm13
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE2;
    } else if (context->iface->_request_route_local__Tterm12 || 1) {
        /* Immediate
     *   Transition 1:
     *   _ARun171
     *    to
     *   finalState2
     *   Trigger: context->iface->_request_route_local__Tterm12 || 1
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE2;
    } else {
        // The thread pauses after this state is done.
        context->threadStatus = PAUSING;
        context->activePriority = 0;
    }
}

// Logic function of the simple state finalState2 in region region_ACtrl17
static inline void region_ACtrl17_statefinalState2(_ACtrl17Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region region__EA_Entry14
static inline void region__EA_Entry14(__EA_Entry14Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case S3_0_2_0:
                region__EA_Entry14_stateS3_0_2_0(context);
                break;

            case __EA_INIT:
                region__EA_Entry14_state__EA_Init(context);
                break;

            case __EA_MAIN:
                region__EA_Entry14_state__EA_Main(context);
                // It was a superstate reset, fall through.

            case __EA_MAINRUNNING:
                region__EA_Entry14_state__EA_Mainrunning(context);
                break;

            case _AC18:
                region__EA_Entry14_state_AC18(context);
                break;

            case _TC:
                region__EA_Entry14_state_Tc(context);
                break;

            case FINALSTATE6:
                region__EA_Entry14_statefinalState6(context);
                break;

        }
    }
}

// Logic function of the simple state S3_0_2_0 in region region__EA_Entry14
static inline void region__EA_Entry14_stateS3_0_2_0(__EA_Entry14Context *context) {
    if (context->iface->_request_route_local_len < context->iface->_request_route_local_min_len) {
        /* Immediate
     *   Transition 0:
     *   S3_0_2_0
     *    to
     *   __EA_Init
     *   Trigger: context->iface->_request_route_local_len < context->iface->_request_route_local_min_len
     */
        context->delayedEnabled = 0;
        context->activeState = __EA_INIT;
    } else {
        /* Immediate
     *   Transition 1:
     *   S3_0_2_0
     *    to
     *   _Tc
     */
        context->delayedEnabled = 0;
        context->activeState = _TC;
    }
}

// Logic function of the simple state __EA_Init in region region__EA_Entry14
static inline void region__EA_Entry14_state__EA_Init(__EA_Entry14Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm14 = 0
     */
    context->iface->_request_route_local__Tterm14 = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN;
}

// Init function of superstate __EA_Main in region region__EA_Entry14
static inline void region__EA_Entry14_state__EA_Main(__EA_Entry14Context *context) {
    context->activeState = __EA_MAINRUNNING;
    context->_actrl18context.activeState = _ARUN181;
    context->_actrl18context.delayedEnabled = 0;
    context->_actrl18context.activePriority = 0;
    context->_actrl18context.threadStatus = READY;
    context->region4context.activeState = S3_0_2_1_01;
    context->region4context.delayedEnabled = 0;
    context->region4context.activePriority = 0;
    context->region4context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region region__EA_Entry14
static inline void region__EA_Entry14_state__EA_Mainrunning(__EA_Entry14Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl18context.threadStatus == READY) {
        if (context->_actrl18context.activePriority == activePriority) {
            context->_actrl18context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl18.
            region_ACtrl18(&context->_actrl18context);
        }
        if (context->_actrl18context.threadStatus == READY) {
            if (context->_actrl18context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl18context.activePriority;
            }
        }
    }
    if (context->region4context.threadStatus == READY) {
        if (context->region4context.activePriority == activePriority) {
            context->region4context.threadStatus = RUNNING;
            // Call the logic code of thread regionregion4.
            regionregion4(&context->region4context);
        }
        if (context->region4context.threadStatus == READY) {
            if (context->region4context.activePriority > newActivePriority) {
                newActivePriority = context->region4context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl18context.threadStatus != READY &&
        context->region4context.threadStatus != READY) {
        if ((context->_actrl18context.activePriority > context->activePriority) &&
            (context->_actrl18context.threadStatus == PAUSING))
            context->activePriority = context->_actrl18context.activePriority;
        if ((context->region4context.activePriority > context->activePriority) &&
            (context->region4context.threadStatus == PAUSING))
            context->activePriority = context->region4context.activePriority;
    }
    if (context->_actrl18context.threadStatus == TERMINATED &&
        context->region4context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC18
     *   Trigger: context->_actrl18context.threadStatus == TERMINATED &&
    context->region4context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC18;
    } else {
        if (context->_actrl18context.threadStatus == READY ||
            context->region4context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl18
static inline void region_ACtrl18(_ACtrl18Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN181:
                region_ACtrl18_state_ARun181(context);
                break;

            case FINALSTATE3:
                region_ACtrl18_statefinalState3(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun181 in region region_ACtrl18
static inline void region_ACtrl18_state_ARun181(_ACtrl18Context *context) {
    if (context->iface->_request_route_local__Tterm14) {
        /* Immediate
     *   Transition 0:
     *   _ARun181
     *    to
     *   finalState3
     *   Trigger: context->iface->_request_route_local__Tterm14
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE3;
    } else if (context->iface->_request_route_local__Tterm13 || context->iface->_request_route_local__Tterm12 || 1) {
        /* Immediate
     *   Transition 1:
     *   _ARun181
     *    to
     *   finalState3
     *   Trigger: context->iface->_request_route_local__Tterm13 || context->iface->_request_route_local__Tterm12 || 1
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE3;
    } else {
        // The thread pauses after this state is done.
        context->threadStatus = PAUSING;
        context->activePriority = 0;
    }
}

// Logic function of the simple state finalState3 in region region_ACtrl18
static inline void region_ACtrl18_statefinalState3(_ACtrl18Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region regionregion4
static inline void regionregion4(Region4Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case S3_0_2_1_01:
                regionregion4_stateS3_0_2_1_01(context);
                break;

            case __SD_DEPTH58:
                regionregion4_state__sd_Depth58(context);
                break;

            case __TE_S32:
                regionregion4_state__te_S32(context);
                break;

            case FINALSTATE5:
                regionregion4_statefinalState5(context);
                break;

        }
    }
}

// Logic function of the simple state S3_0_2_1_01 in region regionregion4
static inline void regionregion4_stateS3_0_2_1_01(Region4Context *context) {
    /* Immediate
     *   Transition 0:
     *   S3_0_2_1_01
     *    to
     *   __sd_Depth58
     *   Effects: _request_route_local_min_len = _request_route_local_len
     */
    context->iface->_request_route_local_min_len = context->iface->_request_route_local_len;
    context->delayedEnabled = 0;
    context->activeState = __SD_DEPTH58;
}

// Logic function of the simple state __sd_Depth58 in region regionregion4
static inline void regionregion4_state__sd_Depth58(Region4Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth58
     *    to
     *   __te_S32
     *   Effects: _request_route_local_result1 = _request_route_local_i3
     */
    context->iface->_request_route_local_result1 = context->iface->_request_route_local_i3;
    context->delayedEnabled = 0;
    context->activeState = __TE_S32;
}

// Logic function of the simple state __te_S32 in region regionregion4
static inline void regionregion4_state__te_S32(Region4Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S32
     *    to
     *   finalState5
     *   Effects: _request_route_local__Tterm14 = 1
     */
    context->iface->_request_route_local__Tterm14 = 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE5;
}

// Logic function of the simple state finalState5 in region regionregion4
static inline void regionregion4_statefinalState5(Region4Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC18 in region region__EA_Entry14
static inline void region__EA_Entry14_state_AC18(__EA_Entry14Context *context) {
    if (context->iface->_request_route_local__Tterm14) {
        /* Immediate
     *   Transition 0:
     *   _AC18
     *    to
     *   _Tc
     *   Trigger: context->iface->_request_route_local__Tterm14
     */
        context->delayedEnabled = 0;
        context->activeState = _TC;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC18
     *    to
     *   finalState6
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE6;
    }
}

// Logic function of the simple state _Tc in region region__EA_Entry14
static inline void region__EA_Entry14_state_Tc(__EA_Entry14Context *context) {
    /* Immediate
     *   Transition 0:
     *   _Tc
     *    to
     *   finalState6
     *   Effects: _request_route_local__Tterm13 = 1
     */
    context->iface->_request_route_local__Tterm13 = 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE6;
}

// Logic function of the simple state finalState6 in region region__EA_Entry14
static inline void region__EA_Entry14_statefinalState6(__EA_Entry14Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC17 in region region__EA_Entry13
static inline void region__EA_Entry13_state_AC17(__EA_Entry13Context *context) {
    if (context->iface->_request_route_local__Tterm13) {
        /* Immediate
     *   Transition 0:
     *   _AC17
     *    to
     *   __sd_Depth61
     *   Trigger: context->iface->_request_route_local__Tterm13
     */
        context->delayedEnabled = 0;
        context->activeState = __SD_DEPTH61;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC17
     *    to
     *   finalState7
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE7;
    }
}

// Logic function of the simple state __sd_Depth61 in region region__EA_Entry13
static inline void region__EA_Entry13_state__sd_Depth61(__EA_Entry13Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth61
     *    to
     *   __te_S34
     *   Effects: _request_route_local_i3 = _request_route_local_i3 + 1
     */
    context->iface->_request_route_local_i3 = context->iface->_request_route_local_i3 + 1;
    context->delayedEnabled = 0;
    context->activeState = __TE_S34;
}

// Logic function of the simple state __te_S34 in region region__EA_Entry13
static inline void region__EA_Entry13_state__te_S34(__EA_Entry13Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S34
     *    to
     *   finalState7
     *   Effects: _request_route_local__Tterm12 = 1
     */
    context->iface->_request_route_local__Tterm12 = 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE7;
}

// Logic function of the simple state finalState7 in region region__EA_Entry13
static inline void region__EA_Entry13_statefinalState7(__EA_Entry13Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC16 in region regionregion0
static inline void regionregion0_state_AC16(Region0Context *context) {
    if (context->iface->_request_route_local__Tterm12) {
        /* Immediate
     *   Transition 0:
     *   _AC16
     *    to
     *   S42
     *   Trigger: context->iface->_request_route_local__Tterm12
     */
        context->delayedEnabled = 0;
        context->activeState = S42;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC16
     *    to
     *   __te_S35
     */
        context->delayedEnabled = 0;
        context->activeState = __TE_S35;
    }
}

// Logic function of the simple state __te_S35 in region regionregion0
static inline void regionregion0_state__te_S35(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S35
     *    to
     *   S05
     *   Effects: _taken_transitions[2] += 1
     */
    context->iface->_taken_transitions[2] += 1;
    context->delayedEnabled = 0;
    context->activeState = S05;
}

// Logic function of the simple state S05 in region regionregion0
static inline void regionregion0_stateS05(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   S05
     *    to
     *   __sd_Depth66
     *   Effects: _request_route_local__train_id_ = config_get_scalar_string_value("route", id, "train")
     */
    context->iface->_request_route_local__train_id_ = config_get_scalar_string_value("route", context->iface->id, "train");
    context->delayedEnabled = 0;
    context->activeState = __SD_DEPTH66;
}

// Logic function of the simple state __sd_Depth66 in region regionregion0
static inline void regionregion0_state__sd_Depth66(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth66
     *    to
     *   S31
     *   Effects: _request_route_local_count_conflict_routes = config_get_array_string_value("route", id, "conflicts", _request_route_local_conflict_routes)
     */
    context->iface->_request_route_local_count_conflict_routes = config_get_array_string_value("route", context->iface->id, "conflicts", context->iface->_request_route_local_conflict_routes);
    context->delayedEnabled = 0;
    context->activeState = S31;
}

// Logic function of the simple state S31 in region regionregion0
static inline void regionregion0_stateS31(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   S31
     *    to
     *   S43
     *   Effects: _request_route_local_i4 = 0
     */
    context->iface->_request_route_local_i4 = 0;
    context->delayedEnabled = 0;
    context->activeState = S43;
}

// Logic function of the simple state S43 in region regionregion0
static inline void regionregion0_stateS43(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   S43
     *    to
     *   S63
     *   Effects: _request_route_local_result2 = 1
     */
    context->iface->_request_route_local_result2 = 1;
    context->delayedEnabled = 0;
    context->activeState = S63;
}

// Logic function of the simple state __EA_Init in region regionregion0
static inline void regionregion0_state__EA_Init2(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm15 = 0
     */
    context->iface->_request_route_local__Tterm15 = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN15;
}

// Init function of superstate __EA_Main in region regionregion0
static inline void regionregion0_state__EA_Main2(Region0Context *context) {
    context->activeState = __EA_MAIN15RUNNING;
    context->_actrl20context.activeState = _ARUN201;
    context->_actrl20context.delayedEnabled = 0;
    context->_actrl20context.activePriority = 0;
    context->_actrl20context.threadStatus = READY;
    context->__ea_entry16context.activeState = S5_0_01;
    context->__ea_entry16context.delayedEnabled = 0;
    context->__ea_entry16context.activePriority = 0;
    context->__ea_entry16context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region regionregion0
static inline void regionregion0_state__EA_Main2running(Region0Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl20context.threadStatus == READY) {
        if (context->_actrl20context.activePriority == activePriority) {
            context->_actrl20context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl20.
            region_ACtrl20(&context->_actrl20context);
        }
        if (context->_actrl20context.threadStatus == READY) {
            if (context->_actrl20context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl20context.activePriority;
            }
        }
    }
    if (context->__ea_entry16context.threadStatus == READY) {
        if (context->__ea_entry16context.activePriority == activePriority) {
            context->__ea_entry16context.threadStatus = RUNNING;
            // Call the logic code of thread region__EA_Entry16.
            region__EA_Entry16(&context->__ea_entry16context);
        }
        if (context->__ea_entry16context.threadStatus == READY) {
            if (context->__ea_entry16context.activePriority > newActivePriority) {
                newActivePriority = context->__ea_entry16context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl20context.threadStatus != READY &&
        context->__ea_entry16context.threadStatus != READY) {
        if ((context->_actrl20context.activePriority > context->activePriority) &&
            (context->_actrl20context.threadStatus == PAUSING))
            context->activePriority = context->_actrl20context.activePriority;
        if ((context->__ea_entry16context.activePriority > context->activePriority) &&
            (context->__ea_entry16context.threadStatus == PAUSING))
            context->activePriority = context->__ea_entry16context.activePriority;
    }
    if (context->_actrl20context.threadStatus == TERMINATED &&
        context->__ea_entry16context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC20
     *   Trigger: context->_actrl20context.threadStatus == TERMINATED &&
    context->__ea_entry16context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC20;
    } else {
        if (context->_actrl20context.threadStatus == READY ||
            context->__ea_entry16context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl20
static inline void region_ACtrl20(_ACtrl20Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN201:
                region_ACtrl20_state_ARun201(context);
                break;

            case FINALSTATE8:
                region_ACtrl20_statefinalState8(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun201 in region region_ACtrl20
static inline void region_ACtrl20_state_ARun201(_ACtrl20Context *context) {
    if (context->iface->_request_route_local__Tterm15) {
        /* Immediate
     *   Transition 0:
     *   _ARun201
     *    to
     *   finalState8
     *   Trigger: context->iface->_request_route_local__Tterm15
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE8;
    } else {
        /* Immediate
     *   Transition 1:
     *   _ARun201
     *    to
     *   finalState8
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE8;
    }
}

// Logic function of the simple state finalState8 in region region_ACtrl20
static inline void region_ACtrl20_statefinalState8(_ACtrl20Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region region__EA_Entry16
static inline void region__EA_Entry16(__EA_Entry16Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case S5_0_01:
                region__EA_Entry16_stateS5_0_01(context);
                break;

            case S5_0_11:
                region__EA_Entry16_stateS5_0_11(context);
                break;

            case __EA_INIT4:
                region__EA_Entry16_state__EA_Init(context);
                break;

            case __EA_MAIN4:
                region__EA_Entry16_state__EA_Main(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN4RUNNING:
                region__EA_Entry16_state__EA_Mainrunning(context);
                break;

            case _AC21:
                region__EA_Entry16_state_AC21(context);
                break;

            case __SD_DEPTH75:
                region__EA_Entry16_state__sd_Depth75(context);
                break;

            case __TE_S39:
                region__EA_Entry16_state__te_S39(context);
                break;

            case FINALSTATE14:
                region__EA_Entry16_statefinalState14(context);
                break;

        }
    }
}

// Logic function of the simple state S5_0_01 in region region__EA_Entry16
static inline void region__EA_Entry16_stateS5_0_01(__EA_Entry16Context *context) {
    /* Immediate
     *   Transition 0:
     *   S5_0_01
     *    to
     *   S5_0_11
     *   Effects: _request_route_local_conflict_route_id = _request_route_local_conflict_routes[_request_route_local_i4]
     */
    context->iface->_request_route_local_conflict_route_id = context->iface->_request_route_local_conflict_routes[context->iface->_request_route_local_i4];
    context->delayedEnabled = 0;
    context->activeState = S5_0_11;
}

// Logic function of the simple state S5_0_11 in region region__EA_Entry16
static inline void region__EA_Entry16_stateS5_0_11(__EA_Entry16Context *context) {
    /* Immediate
     *   Transition 0:
     *   S5_0_11
     *    to
     *   __EA_Init
     *   Effects: _request_route_local_conflict_train_id = config_get_scalar_string_value("route", _request_route_local_conflict_route_id, "train")
     */
    context->iface->_request_route_local_conflict_train_id = config_get_scalar_string_value("route", context->iface->_request_route_local_conflict_route_id, "train");
    context->delayedEnabled = 0;
    context->activeState = __EA_INIT4;
}

// Logic function of the simple state __EA_Init in region region__EA_Entry16
static inline void region__EA_Entry16_state__EA_Init(__EA_Entry16Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm16 = 0
     */
    context->iface->_request_route_local__Tterm16 = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN4;
}

// Init function of superstate __EA_Main in region region__EA_Entry16
static inline void region__EA_Entry16_state__EA_Main(__EA_Entry16Context *context) {
    context->activeState = __EA_MAIN4RUNNING;
    context->_actrl21context.activeState = _ARUN211;
    context->_actrl21context.delayedEnabled = 0;
    context->_actrl21context.activePriority = 0;
    context->_actrl21context.threadStatus = READY;
    context->__ea_entry17context.activeState = S5_0_2_0;
    context->__ea_entry17context.delayedEnabled = 0;
    context->__ea_entry17context.activePriority = 0;
    context->__ea_entry17context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region region__EA_Entry16
static inline void region__EA_Entry16_state__EA_Mainrunning(__EA_Entry16Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl21context.threadStatus == READY) {
        if (context->_actrl21context.activePriority == activePriority) {
            context->_actrl21context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl21.
            region_ACtrl21(&context->_actrl21context);
        }
        if (context->_actrl21context.threadStatus == READY) {
            if (context->_actrl21context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl21context.activePriority;
            }
        }
    }
    if (context->__ea_entry17context.threadStatus == READY) {
        if (context->__ea_entry17context.activePriority == activePriority) {
            context->__ea_entry17context.threadStatus = RUNNING;
            // Call the logic code of thread region__EA_Entry17.
            region__EA_Entry17(&context->__ea_entry17context);
        }
        if (context->__ea_entry17context.threadStatus == READY) {
            if (context->__ea_entry17context.activePriority > newActivePriority) {
                newActivePriority = context->__ea_entry17context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl21context.threadStatus != READY &&
        context->__ea_entry17context.threadStatus != READY) {
        if ((context->_actrl21context.activePriority > context->activePriority) &&
            (context->_actrl21context.threadStatus == PAUSING))
            context->activePriority = context->_actrl21context.activePriority;
        if ((context->__ea_entry17context.activePriority > context->activePriority) &&
            (context->__ea_entry17context.threadStatus == PAUSING))
            context->activePriority = context->__ea_entry17context.activePriority;
    }
    if (context->_actrl21context.threadStatus == TERMINATED &&
        context->__ea_entry17context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC21
     *   Trigger: context->_actrl21context.threadStatus == TERMINATED &&
    context->__ea_entry17context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC21;
    } else {
        if (context->_actrl21context.threadStatus == READY ||
            context->__ea_entry17context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl21
static inline void region_ACtrl21(_ACtrl21Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN211:
                region_ACtrl21_state_ARun211(context);
                break;

            case FINALSTATE9:
                region_ACtrl21_statefinalState9(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun211 in region region_ACtrl21
static inline void region_ACtrl21_state_ARun211(_ACtrl21Context *context) {
    if (context->iface->_request_route_local__Tterm16) {
        /* Immediate
     *   Transition 0:
     *   _ARun211
     *    to
     *   finalState9
     *   Trigger: context->iface->_request_route_local__Tterm16
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE9;
    } else if (context->iface->_request_route_local__Tterm15 || 1) {
        /* Immediate
     *   Transition 1:
     *   _ARun211
     *    to
     *   finalState9
     *   Trigger: context->iface->_request_route_local__Tterm15 || 1
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE9;
    } else {
        // The thread pauses after this state is done.
        context->threadStatus = PAUSING;
        context->activePriority = 0;
    }
}

// Logic function of the simple state finalState9 in region region_ACtrl21
static inline void region_ACtrl21_statefinalState9(_ACtrl21Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region region__EA_Entry17
static inline void region__EA_Entry17(__EA_Entry17Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case S5_0_2_0:
                region__EA_Entry17_stateS5_0_2_0(context);
                break;

            case __EA_INIT3:
                region__EA_Entry17_state__EA_Init(context);
                break;

            case __EA_MAIN3:
                region__EA_Entry17_state__EA_Main(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN3RUNNING:
                region__EA_Entry17_state__EA_Mainrunning(context);
                break;

            case _AC22:
                region__EA_Entry17_state_AC22(context);
                break;

            case _TC2:
                region__EA_Entry17_state_Tc(context);
                break;

            case FINALSTATE13:
                region__EA_Entry17_statefinalState13(context);
                break;

        }
    }
}

// Logic function of the simple state S5_0_2_0 in region region__EA_Entry17
static inline void region__EA_Entry17_stateS5_0_2_0(__EA_Entry17Context *context) {
    if (!string_equals(context->iface->_request_route_local_conflict_train_id, "")) {
        /* Immediate
     *   Transition 0:
     *   S5_0_2_0
     *    to
     *   __EA_Init
     *   Trigger: !string_equals(context->iface->_request_route_local_conflict_train_id, "")
     */
        context->delayedEnabled = 0;
        context->activeState = __EA_INIT3;
    } else {
        /* Immediate
     *   Transition 1:
     *   S5_0_2_0
     *    to
     *   _Tc
     */
        context->delayedEnabled = 0;
        context->activeState = _TC2;
    }
}

// Logic function of the simple state __EA_Init in region region__EA_Entry17
static inline void region__EA_Entry17_state__EA_Init(__EA_Entry17Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm17 = 0
     */
    context->iface->_request_route_local__Tterm17 = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN3;
}

// Init function of superstate __EA_Main in region region__EA_Entry17
static inline void region__EA_Entry17_state__EA_Main(__EA_Entry17Context *context) {
    context->activeState = __EA_MAIN3RUNNING;
    context->_actrl22context.activeState = _ARUN221;
    context->_actrl22context.delayedEnabled = 0;
    context->_actrl22context.activePriority = 0;
    context->_actrl22context.threadStatus = READY;
    context->region11context.activeState = __SD_DEPTH72;
    context->region11context.delayedEnabled = 0;
    context->region11context.activePriority = 0;
    context->region11context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region region__EA_Entry17
static inline void region__EA_Entry17_state__EA_Mainrunning(__EA_Entry17Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl22context.threadStatus == READY) {
        if (context->_actrl22context.activePriority == activePriority) {
            context->_actrl22context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl22.
            region_ACtrl22(&context->_actrl22context);
        }
        if (context->_actrl22context.threadStatus == READY) {
            if (context->_actrl22context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl22context.activePriority;
            }
        }
    }
    if (context->region11context.threadStatus == READY) {
        if (context->region11context.activePriority == activePriority) {
            context->region11context.threadStatus = RUNNING;
            // Call the logic code of thread regionregion11.
            regionregion11(&context->region11context);
        }
        if (context->region11context.threadStatus == READY) {
            if (context->region11context.activePriority > newActivePriority) {
                newActivePriority = context->region11context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl22context.threadStatus != READY &&
        context->region11context.threadStatus != READY) {
        if ((context->_actrl22context.activePriority > context->activePriority) &&
            (context->_actrl22context.threadStatus == PAUSING))
            context->activePriority = context->_actrl22context.activePriority;
        if ((context->region11context.activePriority > context->activePriority) &&
            (context->region11context.threadStatus == PAUSING))
            context->activePriority = context->region11context.activePriority;
    }
    if (context->_actrl22context.threadStatus == TERMINATED &&
        context->region11context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC22
     *   Trigger: context->_actrl22context.threadStatus == TERMINATED &&
    context->region11context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC22;
    } else {
        if (context->_actrl22context.threadStatus == READY ||
            context->region11context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl22
static inline void region_ACtrl22(_ACtrl22Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN221:
                region_ACtrl22_state_ARun221(context);
                break;

            case FINALSTATE10:
                region_ACtrl22_statefinalState10(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun221 in region region_ACtrl22
static inline void region_ACtrl22_state_ARun221(_ACtrl22Context *context) {
    if (context->iface->_request_route_local__Tterm17) {
        /* Immediate
     *   Transition 0:
     *   _ARun221
     *    to
     *   finalState10
     *   Trigger: context->iface->_request_route_local__Tterm17
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE10;
    } else if (context->iface->_request_route_local__Tterm16 || context->iface->_request_route_local__Tterm15 || 1) {
        /* Immediate
     *   Transition 1:
     *   _ARun221
     *    to
     *   finalState10
     *   Trigger: context->iface->_request_route_local__Tterm16 || context->iface->_request_route_local__Tterm15 || 1
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE10;
    } else {
        // The thread pauses after this state is done.
        context->threadStatus = PAUSING;
        context->activePriority = 0;
    }
}

// Logic function of the simple state finalState10 in region region_ACtrl22
static inline void region_ACtrl22_statefinalState10(_ACtrl22Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region regionregion11
static inline void regionregion11(Region11Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case __SD_DEPTH72:
                regionregion11_state__sd_Depth72(context);
                break;

            case __TE_S37:
                regionregion11_state__te_S37(context);
                break;

            case FINALSTATE12:
                regionregion11_statefinalState12(context);
                break;

        }
    }
}

// Logic function of the simple state __sd_Depth72 in region regionregion11
static inline void regionregion11_state__sd_Depth72(Region11Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth72
     *    to
     *   __te_S37
     *   Effects: _request_route_local_result2 = 0
     */
    context->iface->_request_route_local_result2 = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S37;
}

// Logic function of the simple state __te_S37 in region regionregion11
static inline void regionregion11_state__te_S37(Region11Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S37
     *    to
     *   finalState12
     *   Effects: _request_route_local__Tterm17 = 1
     */
    context->iface->_request_route_local__Tterm17 = 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE12;
}

// Logic function of the simple state finalState12 in region regionregion11
static inline void regionregion11_statefinalState12(Region11Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC22 in region region__EA_Entry17
static inline void region__EA_Entry17_state_AC22(__EA_Entry17Context *context) {
    if (context->iface->_request_route_local__Tterm17) {
        /* Immediate
     *   Transition 0:
     *   _AC22
     *    to
     *   _Tc
     *   Trigger: context->iface->_request_route_local__Tterm17
     */
        context->delayedEnabled = 0;
        context->activeState = _TC2;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC22
     *    to
     *   finalState13
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE13;
    }
}

// Logic function of the simple state _Tc in region region__EA_Entry17
static inline void region__EA_Entry17_state_Tc(__EA_Entry17Context *context) {
    /* Immediate
     *   Transition 0:
     *   _Tc
     *    to
     *   finalState13
     *   Effects: _request_route_local__Tterm16 = 1
     */
    context->iface->_request_route_local__Tterm16 = 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE13;
}

// Logic function of the simple state finalState13 in region region__EA_Entry17
static inline void region__EA_Entry17_statefinalState13(__EA_Entry17Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC21 in region region__EA_Entry16
static inline void region__EA_Entry16_state_AC21(__EA_Entry16Context *context) {
    if (context->iface->_request_route_local__Tterm16) {
        /* Immediate
     *   Transition 0:
     *   _AC21
     *    to
     *   __sd_Depth75
     *   Trigger: context->iface->_request_route_local__Tterm16
     */
        context->delayedEnabled = 0;
        context->activeState = __SD_DEPTH75;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC21
     *    to
     *   finalState14
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE14;
    }
}

// Logic function of the simple state __sd_Depth75 in region region__EA_Entry16
static inline void region__EA_Entry16_state__sd_Depth75(__EA_Entry16Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth75
     *    to
     *   __te_S39
     *   Effects: _request_route_local_i4 = _request_route_local_i4 + 1
     */
    context->iface->_request_route_local_i4 = context->iface->_request_route_local_i4 + 1;
    context->delayedEnabled = 0;
    context->activeState = __TE_S39;
}

// Logic function of the simple state __te_S39 in region region__EA_Entry16
static inline void region__EA_Entry16_state__te_S39(__EA_Entry16Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S39
     *    to
     *   finalState14
     *   Effects: _request_route_local__Tterm15 = 1
     */
    context->iface->_request_route_local__Tterm15 = 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE14;
}

// Logic function of the simple state finalState14 in region region__EA_Entry16
static inline void region__EA_Entry16_statefinalState14(__EA_Entry16Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC20 in region regionregion0
static inline void regionregion0_state_AC20(Region0Context *context) {
    if (context->iface->_request_route_local__Tterm15) {
        /* Immediate
     *   Transition 0:
     *   _AC20
     *    to
     *   S63
     *   Trigger: context->iface->_request_route_local__Tterm15
     */
        context->delayedEnabled = 0;
        context->activeState = S63;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC20
     *    to
     *   __te_S40
     */
        context->delayedEnabled = 0;
        context->activeState = __TE_S40;
    }
}

// Logic function of the simple state __te_S40 in region regionregion0
static inline void regionregion0_state__te_S40(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S40
     *    to
     *   S4_01
     *   Effects: _taken_transitions[3] += 1
     */
    context->iface->_taken_transitions[3] += 1;
    context->delayedEnabled = 0;
    context->activeState = S4_01;
}

// Logic function of the simple state __te_S2 in region regionregion0
static inline void regionregion0_state__te_S2(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S2
     *    to
     *   __sd_Depth2
     *   Effects: _taken_transitions[5] += 1
     */
    context->iface->_taken_transitions[5] += 1;
    context->delayedEnabled = 0;
    context->activeState = __SD_DEPTH2;
}

// Logic function of the simple state __sd_Depth2 in region regionregion0
static inline void regionregion0_state__sd_Depth2(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth2
     *    to
     *   __te_S4
     *   Effects: id = ""
     */
    context->iface->id = "";
    context->delayedEnabled = 0;
    context->activeState = __TE_S4;
}

// Logic function of the simple state __te_S4 in region regionregion0
static inline void regionregion0_state__te_S4(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S4
     *    to
     *   __te_S5
     *   Effects: _taken_transitions[8] += 1
     */
    context->iface->_taken_transitions[8] += 1;
    context->delayedEnabled = 0;
    context->activeState = __TE_S5;
}

// Logic function of the simple state __te_S5 in region regionregion0
static inline void regionregion0_state__te_S5(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S5
     *    to
     *   __te_S28
     *   Effects: _taken_transitions[7] += 1
     */
    context->iface->_taken_transitions[7] += 1;
    context->delayedEnabled = 0;
    context->activeState = __TE_S28;
}

// Logic function of the simple state __te_S28 in region regionregion0
static inline void regionregion0_state__te_S28(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S28
     *    to
     *   __sd_Depth51
     *   Effects: _taken_transitions[4] += 1
     */
    context->iface->_taken_transitions[4] += 1;
    context->delayedEnabled = 0;
    context->activeState = __SD_DEPTH51;
}

// Logic function of the simple state __sd_Depth51 in region regionregion0
static inline void regionregion0_state__sd_Depth51(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth51
     *    to
     *   __te_S30
     *   Effects: out = id
     */
    context->iface->out = context->iface->id;
    context->delayedEnabled = 0;
    context->activeState = __TE_S30;
}

// Logic function of the simple state __te_S30 in region regionregion0
static inline void regionregion0_state__te_S30(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S30
     *    to
     *   finalState43
     *   Effects: _taken_transitions[19] += 1
     */
    context->iface->_taken_transitions[19] += 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE43;
}

// Logic function of the simple state S4_01 in region regionregion0
static inline void regionregion0_stateS4_01(Region0Context *context) {
    if (!context->iface->is_grantable) {
        /* Immediate
     *   Transition 0:
     *   S4_01
     *    to
     *   __te_S2
     *   Trigger: !context->iface->is_grantable
     */
        context->delayedEnabled = 0;
        context->activeState = __TE_S2;
    } else {
        /* Immediate
     *   Transition 1:
     *   S4_01
     *    to
     *   S03
     *   Effects: _taken_transitions[6] += 1
     */
        context->iface->_taken_transitions[6] += 1;
        context->delayedEnabled = 0;
        context->activeState = S03;
    }
}

// Logic function of the simple state S03 in region regionregion0
static inline void regionregion0_stateS03(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   S03
     *    to
     *   S14
     *   Effects: _request_route_local_result = 1
     */
    context->iface->_request_route_local_result = 1;
    context->delayedEnabled = 0;
    context->activeState = S14;
}

// Logic function of the simple state S14 in region regionregion0
static inline void regionregion0_stateS14(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   S14
     *    to
     *   S22
     *   Effects: _request_route_local_src_signal = config_get_scalar_string_value("route", id, "source")
     */
    context->iface->_request_route_local_src_signal = config_get_scalar_string_value("route", context->iface->id, "source");
    context->delayedEnabled = 0;
    context->activeState = S22;
}

// Logic function of the simple state S22 in region regionregion0
static inline void regionregion0_stateS22(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   S22
     *    to
     *   __EA_Init
     *   Effects: _request_route_local_src_state = track_state_get_value("signal", _request_route_local_src_signal)
     */
    context->iface->_request_route_local_src_state = track_state_get_value("signal", context->iface->_request_route_local_src_signal);
    context->delayedEnabled = 0;
    context->activeState = __EA_INIT15;
}

// Logic function of the simple state __EA_Init in region regionregion0
static inline void regionregion0_state__EA_Init3(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm1 = 0
     */
    context->iface->_request_route_local__Tterm1 = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN16;
}

// Init function of superstate __EA_Main in region regionregion0
static inline void regionregion0_state__EA_Main3(Region0Context *context) {
    context->activeState = __EA_MAIN16RUNNING;
    context->_actrl4context.activeState = _ARUN41;
    context->_actrl4context.delayedEnabled = 0;
    context->_actrl4context.activePriority = 0;
    context->_actrl4context.threadStatus = READY;
    context->__ea_entry2context.activeState = S3_0;
    context->__ea_entry2context.delayedEnabled = 0;
    context->__ea_entry2context.activePriority = 0;
    context->__ea_entry2context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region regionregion0
static inline void regionregion0_state__EA_Main3running(Region0Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl4context.threadStatus == READY) {
        if (context->_actrl4context.activePriority == activePriority) {
            context->_actrl4context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl4.
            region_ACtrl4(&context->_actrl4context);
        }
        if (context->_actrl4context.threadStatus == READY) {
            if (context->_actrl4context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl4context.activePriority;
            }
        }
    }
    if (context->__ea_entry2context.threadStatus == READY) {
        if (context->__ea_entry2context.activePriority == activePriority) {
            context->__ea_entry2context.threadStatus = RUNNING;
            // Call the logic code of thread region__EA_Entry2.
            region__EA_Entry2(&context->__ea_entry2context);
        }
        if (context->__ea_entry2context.threadStatus == READY) {
            if (context->__ea_entry2context.activePriority > newActivePriority) {
                newActivePriority = context->__ea_entry2context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl4context.threadStatus != READY &&
        context->__ea_entry2context.threadStatus != READY) {
        if ((context->_actrl4context.activePriority > context->activePriority) &&
            (context->_actrl4context.threadStatus == PAUSING))
            context->activePriority = context->_actrl4context.activePriority;
        if ((context->__ea_entry2context.activePriority > context->activePriority) &&
            (context->__ea_entry2context.threadStatus == PAUSING))
            context->activePriority = context->__ea_entry2context.activePriority;
    }
    if (context->_actrl4context.threadStatus == TERMINATED &&
        context->__ea_entry2context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC4
     *   Trigger: context->_actrl4context.threadStatus == TERMINATED &&
    context->__ea_entry2context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC4;
    } else {
        if (context->_actrl4context.threadStatus == READY ||
            context->__ea_entry2context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl4
static inline void region_ACtrl4(_ACtrl4Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN41:
                region_ACtrl4_state_ARun41(context);
                break;

            case FINALSTATE15:
                region_ACtrl4_statefinalState15(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun41 in region region_ACtrl4
static inline void region_ACtrl4_state_ARun41(_ACtrl4Context *context) {
    if (context->iface->_request_route_local__Tterm1) {
        /* Immediate
     *   Transition 0:
     *   _ARun41
     *    to
     *   finalState15
     *   Trigger: context->iface->_request_route_local__Tterm1
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE15;
    } else {
        /* Immediate
     *   Transition 1:
     *   _ARun41
     *    to
     *   finalState15
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE15;
    }
}

// Logic function of the simple state finalState15 in region region_ACtrl4
static inline void region_ACtrl4_statefinalState15(_ACtrl4Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region region__EA_Entry2
static inline void region__EA_Entry2(__EA_Entry2Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case __EA_INIT8:
                region__EA_Entry2_state__EA_Init(context);
                break;

            case __EA_MAIN8:
                region__EA_Entry2_state__EA_Main(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN8RUNNING:
                region__EA_Entry2_state__EA_Mainrunning(context);
                break;

            case _AC5:
                region__EA_Entry2_state_AC5(context);
                break;

            case _TC4:
                region__EA_Entry2_state_Tc(context);
                break;

            case S3_0:
                region__EA_Entry2_stateS3_0(context);
                break;

            case __EA_MAIN9:
                region__EA_Entry2_state__EA_Main2(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN9RUNNING:
                region__EA_Entry2_state__EA_Main2running(context);
                break;

            case _AC6:
                region__EA_Entry2_state_AC6(context);
                break;

            case FINALSTATE28:
                region__EA_Entry2_statefinalState28(context);
                break;

        }
    }
}

// Logic function of the simple state __EA_Init in region region__EA_Entry2
static inline void region__EA_Entry2_state__EA_Init(__EA_Entry2Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm2 = 0
     */
    context->iface->_request_route_local__Tterm2 = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN8;
}

// Init function of superstate __EA_Main in region region__EA_Entry2
static inline void region__EA_Entry2_state__EA_Main(__EA_Entry2Context *context) {
    context->activeState = __EA_MAIN8RUNNING;
    context->_actrl5context.activeState = _ARUN51;
    context->_actrl5context.delayedEnabled = 0;
    context->_actrl5context.activePriority = 0;
    context->_actrl5context.threadStatus = READY;
    context->region17context.activeState = __SD_DEPTH21;
    context->region17context.delayedEnabled = 0;
    context->region17context.activePriority = 0;
    context->region17context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region region__EA_Entry2
static inline void region__EA_Entry2_state__EA_Mainrunning(__EA_Entry2Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl5context.threadStatus == READY) {
        if (context->_actrl5context.activePriority == activePriority) {
            context->_actrl5context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl5.
            region_ACtrl5(&context->_actrl5context);
        }
        if (context->_actrl5context.threadStatus == READY) {
            if (context->_actrl5context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl5context.activePriority;
            }
        }
    }
    if (context->region17context.threadStatus == READY) {
        if (context->region17context.activePriority == activePriority) {
            context->region17context.threadStatus = RUNNING;
            // Call the logic code of thread regionregion17.
            regionregion17(&context->region17context);
        }
        if (context->region17context.threadStatus == READY) {
            if (context->region17context.activePriority > newActivePriority) {
                newActivePriority = context->region17context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl5context.threadStatus != READY &&
        context->region17context.threadStatus != READY) {
        if ((context->_actrl5context.activePriority > context->activePriority) &&
            (context->_actrl5context.threadStatus == PAUSING))
            context->activePriority = context->_actrl5context.activePriority;
        if ((context->region17context.activePriority > context->activePriority) &&
            (context->region17context.threadStatus == PAUSING))
            context->activePriority = context->region17context.activePriority;
    }
    if (context->_actrl5context.threadStatus == TERMINATED &&
        context->region17context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC5
     *   Trigger: context->_actrl5context.threadStatus == TERMINATED &&
    context->region17context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC5;
    } else {
        if (context->_actrl5context.threadStatus == READY ||
            context->region17context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl5
static inline void region_ACtrl5(_ACtrl5Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN51:
                region_ACtrl5_state_ARun51(context);
                break;

            case FINALSTATE16:
                region_ACtrl5_statefinalState16(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun51 in region region_ACtrl5
static inline void region_ACtrl5_state_ARun51(_ACtrl5Context *context) {
    if (context->iface->_request_route_local__Tterm2) {
        /* Immediate
     *   Transition 0:
     *   _ARun51
     *    to
     *   finalState16
     *   Trigger: context->iface->_request_route_local__Tterm2
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE16;
    } else if (context->iface->_request_route_local__Tterm1 || 1) {
        /* Immediate
     *   Transition 1:
     *   _ARun51
     *    to
     *   finalState16
     *   Trigger: context->iface->_request_route_local__Tterm1 || 1
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE16;
    } else {
        // The thread pauses after this state is done.
        context->threadStatus = PAUSING;
        context->activePriority = 0;
    }
}

// Logic function of the simple state finalState16 in region region_ACtrl5
static inline void region_ACtrl5_statefinalState16(_ACtrl5Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region regionregion17
static inline void regionregion17(Region17Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case __SD_DEPTH21:
                regionregion17_state__sd_Depth21(context);
                break;

            case __TE_S17:
                regionregion17_state__te_S17(context);
                break;

            case FINALSTATE18:
                regionregion17_statefinalState18(context);
                break;

        }
    }
}

// Logic function of the simple state __sd_Depth21 in region regionregion17
static inline void regionregion17_state__sd_Depth21(Region17Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth21
     *    to
     *   __te_S17
     *   Effects: _request_route_local_result = 0
     */
    context->iface->_request_route_local_result = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S17;
}

// Logic function of the simple state __te_S17 in region regionregion17
static inline void regionregion17_state__te_S17(Region17Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S17
     *    to
     *   finalState18
     *   Effects: _request_route_local__Tterm2 = 1
     */
    context->iface->_request_route_local__Tterm2 = 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE18;
}

// Logic function of the simple state finalState18 in region regionregion17
static inline void regionregion17_statefinalState18(Region17Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC5 in region region__EA_Entry2
static inline void region__EA_Entry2_state_AC5(__EA_Entry2Context *context) {
    if (context->iface->_request_route_local__Tterm2) {
        /* Immediate
     *   Transition 0:
     *   _AC5
     *    to
     *   _Tc
     *   Trigger: context->iface->_request_route_local__Tterm2
     */
        context->delayedEnabled = 0;
        context->activeState = _TC4;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC5
     *    to
     *   finalState28
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE28;
    }
}

// Logic function of the simple state _Tc in region region__EA_Entry2
static inline void region__EA_Entry2_state_Tc(__EA_Entry2Context *context) {
    /* Immediate
     *   Transition 0:
     *   _Tc
     *    to
     *   finalState28
     *   Effects: _request_route_local__Tterm1 = 1
     */
    context->iface->_request_route_local__Tterm1 = 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE28;
}

// Logic function of the simple state S3_0 in region region__EA_Entry2
static inline void region__EA_Entry2_stateS3_0(__EA_Entry2Context *context) {
    if (!string_equals(context->iface->_request_route_local_src_state, "red")) {
        /* Immediate
     *   Transition 0:
     *   S3_0
     *    to
     *   __EA_Init
     *   Trigger: !string_equals(context->iface->_request_route_local_src_state, "red")
     */
        context->delayedEnabled = 0;
        context->activeState = __EA_INIT8;
    } else {
        /* Immediate
     *   Transition 1:
     *   S3_0
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm3 = 0
     */
        context->iface->_request_route_local__Tterm3 = 0;
        context->delayedEnabled = 0;
        context->activeState = __EA_MAIN9;
    }
}

// Init function of superstate __EA_Main in region region__EA_Entry2
static inline void region__EA_Entry2_state__EA_Main2(__EA_Entry2Context *context) {
    context->activeState = __EA_MAIN9RUNNING;
    context->_actrl6context.activeState = _ARUN61;
    context->_actrl6context.delayedEnabled = 0;
    context->_actrl6context.activePriority = 0;
    context->_actrl6context.threadStatus = READY;
    context->__ea_entry4context.activeState = __SD_DEPTH23;
    context->__ea_entry4context.delayedEnabled = 0;
    context->__ea_entry4context.activePriority = 0;
    context->__ea_entry4context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region region__EA_Entry2
static inline void region__EA_Entry2_state__EA_Main2running(__EA_Entry2Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl6context.threadStatus == READY) {
        if (context->_actrl6context.activePriority == activePriority) {
            context->_actrl6context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl6.
            region_ACtrl6(&context->_actrl6context);
        }
        if (context->_actrl6context.threadStatus == READY) {
            if (context->_actrl6context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl6context.activePriority;
            }
        }
    }
    if (context->__ea_entry4context.threadStatus == READY) {
        if (context->__ea_entry4context.activePriority == activePriority) {
            context->__ea_entry4context.threadStatus = RUNNING;
            // Call the logic code of thread region__EA_Entry4.
            region__EA_Entry4(&context->__ea_entry4context);
        }
        if (context->__ea_entry4context.threadStatus == READY) {
            if (context->__ea_entry4context.activePriority > newActivePriority) {
                newActivePriority = context->__ea_entry4context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl6context.threadStatus != READY &&
        context->__ea_entry4context.threadStatus != READY) {
        if ((context->_actrl6context.activePriority > context->activePriority) &&
            (context->_actrl6context.threadStatus == PAUSING))
            context->activePriority = context->_actrl6context.activePriority;
        if ((context->__ea_entry4context.activePriority > context->activePriority) &&
            (context->__ea_entry4context.threadStatus == PAUSING))
            context->activePriority = context->__ea_entry4context.activePriority;
    }
    if (context->_actrl6context.threadStatus == TERMINATED &&
        context->__ea_entry4context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC6
     *   Trigger: context->_actrl6context.threadStatus == TERMINATED &&
    context->__ea_entry4context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC6;
    } else {
        if (context->_actrl6context.threadStatus == READY ||
            context->__ea_entry4context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl6
static inline void region_ACtrl6(_ACtrl6Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN61:
                region_ACtrl6_state_ARun61(context);
                break;

            case FINALSTATE19:
                region_ACtrl6_statefinalState19(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun61 in region region_ACtrl6
static inline void region_ACtrl6_state_ARun61(_ACtrl6Context *context) {
    if (context->iface->_request_route_local__Tterm3) {
        /* Immediate
     *   Transition 0:
     *   _ARun61
     *    to
     *   finalState19
     *   Trigger: context->iface->_request_route_local__Tterm3
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE19;
    } else if (context->iface->_request_route_local__Tterm1 || 1) {
        /* Immediate
     *   Transition 1:
     *   _ARun61
     *    to
     *   finalState19
     *   Trigger: context->iface->_request_route_local__Tterm1 || 1
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE19;
    } else {
        // The thread pauses after this state is done.
        context->threadStatus = PAUSING;
        context->activePriority = 0;
    }
}

// Logic function of the simple state finalState19 in region region_ACtrl6
static inline void region_ACtrl6_statefinalState19(_ACtrl6Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region region__EA_Entry4
static inline void region__EA_Entry4(__EA_Entry4Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case __SD_DEPTH23:
                region__EA_Entry4_state__sd_Depth23(context);
                break;

            case S3_3_21:
                region__EA_Entry4_stateS3_3_21(context);
                break;

            case __EA_INIT7:
                region__EA_Entry4_state__EA_Init(context);
                break;

            case __EA_MAIN7:
                region__EA_Entry4_state__EA_Main(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN7RUNNING:
                region__EA_Entry4_state__EA_Mainrunning(context);
                break;

            case _AC7:
                region__EA_Entry4_state_AC7(context);
                break;

            case S3_3_31:
                region__EA_Entry4_stateS3_3_31(context);
                break;

            case FINALSTATE27:
                region__EA_Entry4_statefinalState27(context);
                break;

        }
    }
}

// Logic function of the simple state __sd_Depth23 in region region__EA_Entry4
static inline void region__EA_Entry4_state__sd_Depth23(__EA_Entry4Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth23
     *    to
     *   S3_3_21
     *   Effects: _request_route_local_flank_signals_count = config_get_array_string_value("route", id, "signals", _request_route_local_flank_signals)
     */
    context->iface->_request_route_local_flank_signals_count = config_get_array_string_value("route", context->iface->id, "signals", context->iface->_request_route_local_flank_signals);
    context->delayedEnabled = 0;
    context->activeState = S3_3_21;
}

// Logic function of the simple state S3_3_21 in region region__EA_Entry4
static inline void region__EA_Entry4_stateS3_3_21(__EA_Entry4Context *context) {
    /* Immediate
     *   Transition 0:
     *   S3_3_21
     *    to
     *   S3_3_31
     *   Effects: _request_route_local_i1 = 0
     */
    context->iface->_request_route_local_i1 = 0;
    context->delayedEnabled = 0;
    context->activeState = S3_3_31;
}

// Logic function of the simple state __EA_Init in region region__EA_Entry4
static inline void region__EA_Entry4_state__EA_Init(__EA_Entry4Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm4 = 0
     */
    context->iface->_request_route_local__Tterm4 = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN7;
}

// Init function of superstate __EA_Main in region region__EA_Entry4
static inline void region__EA_Entry4_state__EA_Main(__EA_Entry4Context *context) {
    context->activeState = __EA_MAIN7RUNNING;
    context->_actrl7context.activeState = _ARUN71;
    context->_actrl7context.delayedEnabled = 0;
    context->_actrl7context.activePriority = 0;
    context->_actrl7context.threadStatus = READY;
    context->__ea_entry5context.activeState = S3_3_3_0_01;
    context->__ea_entry5context.delayedEnabled = 0;
    context->__ea_entry5context.activePriority = 0;
    context->__ea_entry5context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region region__EA_Entry4
static inline void region__EA_Entry4_state__EA_Mainrunning(__EA_Entry4Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl7context.threadStatus == READY) {
        if (context->_actrl7context.activePriority == activePriority) {
            context->_actrl7context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl7.
            region_ACtrl7(&context->_actrl7context);
        }
        if (context->_actrl7context.threadStatus == READY) {
            if (context->_actrl7context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl7context.activePriority;
            }
        }
    }
    if (context->__ea_entry5context.threadStatus == READY) {
        if (context->__ea_entry5context.activePriority == activePriority) {
            context->__ea_entry5context.threadStatus = RUNNING;
            // Call the logic code of thread region__EA_Entry5.
            region__EA_Entry5(&context->__ea_entry5context);
        }
        if (context->__ea_entry5context.threadStatus == READY) {
            if (context->__ea_entry5context.activePriority > newActivePriority) {
                newActivePriority = context->__ea_entry5context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl7context.threadStatus != READY &&
        context->__ea_entry5context.threadStatus != READY) {
        if ((context->_actrl7context.activePriority > context->activePriority) &&
            (context->_actrl7context.threadStatus == PAUSING))
            context->activePriority = context->_actrl7context.activePriority;
        if ((context->__ea_entry5context.activePriority > context->activePriority) &&
            (context->__ea_entry5context.threadStatus == PAUSING))
            context->activePriority = context->__ea_entry5context.activePriority;
    }
    if (context->_actrl7context.threadStatus == TERMINATED &&
        context->__ea_entry5context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC7
     *   Trigger: context->_actrl7context.threadStatus == TERMINATED &&
    context->__ea_entry5context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC7;
    } else {
        if (context->_actrl7context.threadStatus == READY ||
            context->__ea_entry5context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl7
static inline void region_ACtrl7(_ACtrl7Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN71:
                region_ACtrl7_state_ARun71(context);
                break;

            case FINALSTATE20:
                region_ACtrl7_statefinalState20(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun71 in region region_ACtrl7
static inline void region_ACtrl7_state_ARun71(_ACtrl7Context *context) {
    if (context->iface->_request_route_local__Tterm4) {
        /* Immediate
     *   Transition 0:
     *   _ARun71
     *    to
     *   finalState20
     *   Trigger: context->iface->_request_route_local__Tterm4
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE20;
    } else if (context->iface->_request_route_local__Tterm3 || context->iface->_request_route_local__Tterm1 || 1) {
        /* Immediate
     *   Transition 1:
     *   _ARun71
     *    to
     *   finalState20
     *   Trigger: context->iface->_request_route_local__Tterm3 || context->iface->_request_route_local__Tterm1 || 1
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE20;
    } else {
        // The thread pauses after this state is done.
        context->threadStatus = PAUSING;
        context->activePriority = 0;
    }
}

// Logic function of the simple state finalState20 in region region_ACtrl7
static inline void region_ACtrl7_statefinalState20(_ACtrl7Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region region__EA_Entry5
static inline void region__EA_Entry5(__EA_Entry5Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case S3_3_3_0_01:
                region__EA_Entry5_stateS3_3_3_0_01(context);
                break;

            case S3_3_3_0_11:
                region__EA_Entry5_stateS3_3_3_0_11(context);
                break;

            case __EA_INIT6:
                region__EA_Entry5_state__EA_Init(context);
                break;

            case __EA_MAIN6:
                region__EA_Entry5_state__EA_Main(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN6RUNNING:
                region__EA_Entry5_state__EA_Mainrunning(context);
                break;

            case _AC8:
                region__EA_Entry5_state_AC8(context);
                break;

            case __SD_DEPTH32:
                region__EA_Entry5_state__sd_Depth32(context);
                break;

            case __TE_S21:
                region__EA_Entry5_state__te_S21(context);
                break;

            case FINALSTATE26:
                region__EA_Entry5_statefinalState26(context);
                break;

        }
    }
}

// Logic function of the simple state S3_3_3_0_01 in region region__EA_Entry5
static inline void region__EA_Entry5_stateS3_3_3_0_01(__EA_Entry5Context *context) {
    /* Immediate
     *   Transition 0:
     *   S3_3_3_0_01
     *    to
     *   S3_3_3_0_11
     *   Effects: _request_route_local_flank_signal = _request_route_local_flank_signals[_request_route_local_i1]
     */
    context->iface->_request_route_local_flank_signal = context->iface->_request_route_local_flank_signals[context->iface->_request_route_local_i1];
    context->delayedEnabled = 0;
    context->activeState = S3_3_3_0_11;
}

// Logic function of the simple state S3_3_3_0_11 in region region__EA_Entry5
static inline void region__EA_Entry5_stateS3_3_3_0_11(__EA_Entry5Context *context) {
    /* Immediate
     *   Transition 0:
     *   S3_3_3_0_11
     *    to
     *   __EA_Init
     *   Effects: _request_route_local_flank_state = track_state_get_value("signal", _request_route_local_flank_signal)
     */
    context->iface->_request_route_local_flank_state = track_state_get_value("signal", context->iface->_request_route_local_flank_signal);
    context->delayedEnabled = 0;
    context->activeState = __EA_INIT6;
}

// Logic function of the simple state __EA_Init in region region__EA_Entry5
static inline void region__EA_Entry5_state__EA_Init(__EA_Entry5Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm5 = 0
     */
    context->iface->_request_route_local__Tterm5 = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN6;
}

// Init function of superstate __EA_Main in region region__EA_Entry5
static inline void region__EA_Entry5_state__EA_Main(__EA_Entry5Context *context) {
    context->activeState = __EA_MAIN6RUNNING;
    context->_actrl8context.activeState = _ARUN81;
    context->_actrl8context.delayedEnabled = 0;
    context->_actrl8context.activePriority = 0;
    context->_actrl8context.threadStatus = READY;
    context->__ea_entry6context.activeState = S3_3_3_0_2_0;
    context->__ea_entry6context.delayedEnabled = 0;
    context->__ea_entry6context.activePriority = 0;
    context->__ea_entry6context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region region__EA_Entry5
static inline void region__EA_Entry5_state__EA_Mainrunning(__EA_Entry5Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl8context.threadStatus == READY) {
        if (context->_actrl8context.activePriority == activePriority) {
            context->_actrl8context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl8.
            region_ACtrl8(&context->_actrl8context);
        }
        if (context->_actrl8context.threadStatus == READY) {
            if (context->_actrl8context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl8context.activePriority;
            }
        }
    }
    if (context->__ea_entry6context.threadStatus == READY) {
        if (context->__ea_entry6context.activePriority == activePriority) {
            context->__ea_entry6context.threadStatus = RUNNING;
            // Call the logic code of thread region__EA_Entry6.
            region__EA_Entry6(&context->__ea_entry6context);
        }
        if (context->__ea_entry6context.threadStatus == READY) {
            if (context->__ea_entry6context.activePriority > newActivePriority) {
                newActivePriority = context->__ea_entry6context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl8context.threadStatus != READY &&
        context->__ea_entry6context.threadStatus != READY) {
        if ((context->_actrl8context.activePriority > context->activePriority) &&
            (context->_actrl8context.threadStatus == PAUSING))
            context->activePriority = context->_actrl8context.activePriority;
        if ((context->__ea_entry6context.activePriority > context->activePriority) &&
            (context->__ea_entry6context.threadStatus == PAUSING))
            context->activePriority = context->__ea_entry6context.activePriority;
    }
    if (context->_actrl8context.threadStatus == TERMINATED &&
        context->__ea_entry6context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC8
     *   Trigger: context->_actrl8context.threadStatus == TERMINATED &&
    context->__ea_entry6context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC8;
    } else {
        if (context->_actrl8context.threadStatus == READY ||
            context->__ea_entry6context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl8
static inline void region_ACtrl8(_ACtrl8Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN81:
                region_ACtrl8_state_ARun81(context);
                break;

            case FINALSTATE21:
                region_ACtrl8_statefinalState21(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun81 in region region_ACtrl8
static inline void region_ACtrl8_state_ARun81(_ACtrl8Context *context) {
    if (context->iface->_request_route_local__Tterm5) {
        /* Immediate
     *   Transition 0:
     *   _ARun81
     *    to
     *   finalState21
     *   Trigger: context->iface->_request_route_local__Tterm5
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE21;
    } else if (context->iface->_request_route_local__Tterm4 || context->iface->_request_route_local__Tterm3 || context->iface->_request_route_local__Tterm1 || 1) {
        /* Immediate
     *   Transition 1:
     *   _ARun81
     *    to
     *   finalState21
     *   Trigger: context->iface->_request_route_local__Tterm4 || context->iface->_request_route_local__Tterm3 || context->iface->_request_route_local__Tterm1 || 1
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE21;
    } else {
        // The thread pauses after this state is done.
        context->threadStatus = PAUSING;
        context->activePriority = 0;
    }
}

// Logic function of the simple state finalState21 in region region_ACtrl8
static inline void region_ACtrl8_statefinalState21(_ACtrl8Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region region__EA_Entry6
static inline void region__EA_Entry6(__EA_Entry6Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case S3_3_3_0_2_0:
                region__EA_Entry6_stateS3_3_3_0_2_0(context);
                break;

            case __EA_INIT5:
                region__EA_Entry6_state__EA_Init(context);
                break;

            case __EA_MAIN5:
                region__EA_Entry6_state__EA_Main(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN5RUNNING:
                region__EA_Entry6_state__EA_Mainrunning(context);
                break;

            case _AC9:
                region__EA_Entry6_state_AC9(context);
                break;

            case _TC3:
                region__EA_Entry6_state_Tc(context);
                break;

            case FINALSTATE25:
                region__EA_Entry6_statefinalState25(context);
                break;

        }
    }
}

// Logic function of the simple state S3_3_3_0_2_0 in region region__EA_Entry6
static inline void region__EA_Entry6_stateS3_3_3_0_2_0(__EA_Entry6Context *context) {
    if (!string_equals(context->iface->_request_route_local_flank_signal, "red")) {
        /* Immediate
     *   Transition 0:
     *   S3_3_3_0_2_0
     *    to
     *   __EA_Init
     *   Trigger: !string_equals(context->iface->_request_route_local_flank_signal, "red")
     */
        context->delayedEnabled = 0;
        context->activeState = __EA_INIT5;
    } else {
        /* Immediate
     *   Transition 1:
     *   S3_3_3_0_2_0
     *    to
     *   _Tc
     */
        context->delayedEnabled = 0;
        context->activeState = _TC3;
    }
}

// Logic function of the simple state __EA_Init in region region__EA_Entry6
static inline void region__EA_Entry6_state__EA_Init(__EA_Entry6Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm6 = 0
     */
    context->iface->_request_route_local__Tterm6 = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN5;
}

// Init function of superstate __EA_Main in region region__EA_Entry6
static inline void region__EA_Entry6_state__EA_Main(__EA_Entry6Context *context) {
    context->activeState = __EA_MAIN5RUNNING;
    context->_actrl9context.activeState = _ARUN91;
    context->_actrl9context.delayedEnabled = 0;
    context->_actrl9context.activePriority = 0;
    context->_actrl9context.threadStatus = READY;
    context->region23context.activeState = __SD_DEPTH29;
    context->region23context.delayedEnabled = 0;
    context->region23context.activePriority = 0;
    context->region23context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region region__EA_Entry6
static inline void region__EA_Entry6_state__EA_Mainrunning(__EA_Entry6Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl9context.threadStatus == READY) {
        if (context->_actrl9context.activePriority == activePriority) {
            context->_actrl9context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl9.
            region_ACtrl9(&context->_actrl9context);
        }
        if (context->_actrl9context.threadStatus == READY) {
            if (context->_actrl9context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl9context.activePriority;
            }
        }
    }
    if (context->region23context.threadStatus == READY) {
        if (context->region23context.activePriority == activePriority) {
            context->region23context.threadStatus = RUNNING;
            // Call the logic code of thread regionregion23.
            regionregion23(&context->region23context);
        }
        if (context->region23context.threadStatus == READY) {
            if (context->region23context.activePriority > newActivePriority) {
                newActivePriority = context->region23context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl9context.threadStatus != READY &&
        context->region23context.threadStatus != READY) {
        if ((context->_actrl9context.activePriority > context->activePriority) &&
            (context->_actrl9context.threadStatus == PAUSING))
            context->activePriority = context->_actrl9context.activePriority;
        if ((context->region23context.activePriority > context->activePriority) &&
            (context->region23context.threadStatus == PAUSING))
            context->activePriority = context->region23context.activePriority;
    }
    if (context->_actrl9context.threadStatus == TERMINATED &&
        context->region23context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC9
     *   Trigger: context->_actrl9context.threadStatus == TERMINATED &&
    context->region23context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC9;
    } else {
        if (context->_actrl9context.threadStatus == READY ||
            context->region23context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl9
static inline void region_ACtrl9(_ACtrl9Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN91:
                region_ACtrl9_state_ARun91(context);
                break;

            case FINALSTATE22:
                region_ACtrl9_statefinalState22(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun91 in region region_ACtrl9
static inline void region_ACtrl9_state_ARun91(_ACtrl9Context *context) {
    if (context->iface->_request_route_local__Tterm6) {
        /* Immediate
     *   Transition 0:
     *   _ARun91
     *    to
     *   finalState22
     *   Trigger: context->iface->_request_route_local__Tterm6
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE22;
    } else if (context->iface->_request_route_local__Tterm5 || context->iface->_request_route_local__Tterm4 || context->iface->_request_route_local__Tterm3 || context->iface->_request_route_local__Tterm1 || 1) {
        /* Immediate
     *   Transition 1:
     *   _ARun91
     *    to
     *   finalState22
     *   Trigger: context->iface->_request_route_local__Tterm5 || context->iface->_request_route_local__Tterm4 || context->iface->_request_route_local__Tterm3 || context->iface->_request_route_local__Tterm1 || 1
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE22;
    } else {
        // The thread pauses after this state is done.
        context->threadStatus = PAUSING;
        context->activePriority = 0;
    }
}

// Logic function of the simple state finalState22 in region region_ACtrl9
static inline void region_ACtrl9_statefinalState22(_ACtrl9Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region regionregion23
static inline void regionregion23(Region23Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case __SD_DEPTH29:
                regionregion23_state__sd_Depth29(context);
                break;

            case __TE_S19:
                regionregion23_state__te_S19(context);
                break;

            case FINALSTATE24:
                regionregion23_statefinalState24(context);
                break;

        }
    }
}

// Logic function of the simple state __sd_Depth29 in region regionregion23
static inline void regionregion23_state__sd_Depth29(Region23Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth29
     *    to
     *   __te_S19
     *   Effects: _request_route_local_result = 0
     */
    context->iface->_request_route_local_result = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S19;
}

// Logic function of the simple state __te_S19 in region regionregion23
static inline void regionregion23_state__te_S19(Region23Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S19
     *    to
     *   finalState24
     *   Effects: _request_route_local__Tterm6 = 1
     */
    context->iface->_request_route_local__Tterm6 = 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE24;
}

// Logic function of the simple state finalState24 in region regionregion23
static inline void regionregion23_statefinalState24(Region23Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC9 in region region__EA_Entry6
static inline void region__EA_Entry6_state_AC9(__EA_Entry6Context *context) {
    if (context->iface->_request_route_local__Tterm6) {
        /* Immediate
     *   Transition 0:
     *   _AC9
     *    to
     *   _Tc
     *   Trigger: context->iface->_request_route_local__Tterm6
     */
        context->delayedEnabled = 0;
        context->activeState = _TC3;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC9
     *    to
     *   finalState25
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE25;
    }
}

// Logic function of the simple state _Tc in region region__EA_Entry6
static inline void region__EA_Entry6_state_Tc(__EA_Entry6Context *context) {
    /* Immediate
     *   Transition 0:
     *   _Tc
     *    to
     *   finalState25
     *   Effects: _request_route_local__Tterm5 = 1
     */
    context->iface->_request_route_local__Tterm5 = 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE25;
}

// Logic function of the simple state finalState25 in region region__EA_Entry6
static inline void region__EA_Entry6_statefinalState25(__EA_Entry6Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC8 in region region__EA_Entry5
static inline void region__EA_Entry5_state_AC8(__EA_Entry5Context *context) {
    if (context->iface->_request_route_local__Tterm5) {
        /* Immediate
     *   Transition 0:
     *   _AC8
     *    to
     *   __sd_Depth32
     *   Trigger: context->iface->_request_route_local__Tterm5
     */
        context->delayedEnabled = 0;
        context->activeState = __SD_DEPTH32;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC8
     *    to
     *   finalState26
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE26;
    }
}

// Logic function of the simple state __sd_Depth32 in region region__EA_Entry5
static inline void region__EA_Entry5_state__sd_Depth32(__EA_Entry5Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth32
     *    to
     *   __te_S21
     *   Effects: _request_route_local_i1 = _request_route_local_i1 + 1
     */
    context->iface->_request_route_local_i1 = context->iface->_request_route_local_i1 + 1;
    context->delayedEnabled = 0;
    context->activeState = __TE_S21;
}

// Logic function of the simple state __te_S21 in region region__EA_Entry5
static inline void region__EA_Entry5_state__te_S21(__EA_Entry5Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S21
     *    to
     *   finalState26
     *   Effects: _request_route_local__Tterm4 = 1
     */
    context->iface->_request_route_local__Tterm4 = 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE26;
}

// Logic function of the simple state finalState26 in region region__EA_Entry5
static inline void region__EA_Entry5_statefinalState26(__EA_Entry5Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC7 in region region__EA_Entry4
static inline void region__EA_Entry4_state_AC7(__EA_Entry4Context *context) {
    if (context->iface->_request_route_local__Tterm4) {
        /* Immediate
     *   Transition 0:
     *   _AC7
     *    to
     *   S3_3_31
     *   Trigger: context->iface->_request_route_local__Tterm4
     */
        context->delayedEnabled = 0;
        context->activeState = S3_3_31;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC7
     *    to
     *   finalState27
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE27;
    }
}

// Logic function of the simple state S3_3_31 in region region__EA_Entry4
static inline void region__EA_Entry4_stateS3_3_31(__EA_Entry4Context *context) {
    if (context->iface->_request_route_local_i1 < context->iface->_request_route_local_flank_signals_count) {
        /* Immediate
     *   Transition 0:
     *   S3_3_31
     *    to
     *   __EA_Init
     *   Trigger: context->iface->_request_route_local_i1 < context->iface->_request_route_local_flank_signals_count
     */
        context->delayedEnabled = 0;
        context->activeState = __EA_INIT7;
    } else {
        /* Immediate
     *   Transition 1:
     *   S3_3_31
     *    to
     *   finalState27
     *   Effects: _request_route_local__Tterm3 = 1
     */
        context->iface->_request_route_local__Tterm3 = 1;
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE27;
    }
}

// Logic function of the simple state finalState27 in region region__EA_Entry4
static inline void region__EA_Entry4_statefinalState27(__EA_Entry4Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC6 in region region__EA_Entry2
static inline void region__EA_Entry2_state_AC6(__EA_Entry2Context *context) {
    if (context->iface->_request_route_local__Tterm3) {
        /* Immediate
     *   Transition 0:
     *   _AC6
     *    to
     *   _Tc
     *   Trigger: context->iface->_request_route_local__Tterm3
     */
        context->delayedEnabled = 0;
        context->activeState = _TC4;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC6
     *    to
     *   finalState28
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE28;
    }
}

// Logic function of the simple state finalState28 in region region__EA_Entry2
static inline void region__EA_Entry2_statefinalState28(__EA_Entry2Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC4 in region regionregion0
static inline void regionregion0_state_AC4(Region0Context *context) {
    if (context->iface->_request_route_local__Tterm1) {
        /* Immediate
     *   Transition 0:
     *   _AC4
     *    to
     *   __EA_Init
     *   Trigger: context->iface->_request_route_local__Tterm1
     */
        context->delayedEnabled = 0;
        context->activeState = __EA_INIT16;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC4
     *    to
     *   __te_S26
     */
        context->delayedEnabled = 0;
        context->activeState = __TE_S26;
    }
}

// Logic function of the simple state __EA_Init in region regionregion0
static inline void regionregion0_state__EA_Init4(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm7 = 0
     */
    context->iface->_request_route_local__Tterm7 = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN17;
}

// Init function of superstate __EA_Main in region regionregion0
static inline void regionregion0_state__EA_Main4(Region0Context *context) {
    context->activeState = __EA_MAIN17RUNNING;
    context->_actrl10context.activeState = _ARUN101;
    context->_actrl10context.delayedEnabled = 0;
    context->_actrl10context.activePriority = 0;
    context->_actrl10context.threadStatus = READY;
    context->__ea_entry8context.activeState = S4_0;
    context->__ea_entry8context.delayedEnabled = 0;
    context->__ea_entry8context.activePriority = 0;
    context->__ea_entry8context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region regionregion0
static inline void regionregion0_state__EA_Main4running(Region0Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl10context.threadStatus == READY) {
        if (context->_actrl10context.activePriority == activePriority) {
            context->_actrl10context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl10.
            region_ACtrl10(&context->_actrl10context);
        }
        if (context->_actrl10context.threadStatus == READY) {
            if (context->_actrl10context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl10context.activePriority;
            }
        }
    }
    if (context->__ea_entry8context.threadStatus == READY) {
        if (context->__ea_entry8context.activePriority == activePriority) {
            context->__ea_entry8context.threadStatus = RUNNING;
            // Call the logic code of thread region__EA_Entry8.
            region__EA_Entry8(&context->__ea_entry8context);
        }
        if (context->__ea_entry8context.threadStatus == READY) {
            if (context->__ea_entry8context.activePriority > newActivePriority) {
                newActivePriority = context->__ea_entry8context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl10context.threadStatus != READY &&
        context->__ea_entry8context.threadStatus != READY) {
        if ((context->_actrl10context.activePriority > context->activePriority) &&
            (context->_actrl10context.threadStatus == PAUSING))
            context->activePriority = context->_actrl10context.activePriority;
        if ((context->__ea_entry8context.activePriority > context->activePriority) &&
            (context->__ea_entry8context.threadStatus == PAUSING))
            context->activePriority = context->__ea_entry8context.activePriority;
    }
    if (context->_actrl10context.threadStatus == TERMINATED &&
        context->__ea_entry8context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC10
     *   Trigger: context->_actrl10context.threadStatus == TERMINATED &&
    context->__ea_entry8context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC10;
    } else {
        if (context->_actrl10context.threadStatus == READY ||
            context->__ea_entry8context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl10
static inline void region_ACtrl10(_ACtrl10Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN101:
                region_ACtrl10_state_ARun101(context);
                break;

            case FINALSTATE29:
                region_ACtrl10_statefinalState29(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun101 in region region_ACtrl10
static inline void region_ACtrl10_state_ARun101(_ACtrl10Context *context) {
    if (context->iface->_request_route_local__Tterm7) {
        /* Immediate
     *   Transition 0:
     *   _ARun101
     *    to
     *   finalState29
     *   Trigger: context->iface->_request_route_local__Tterm7
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE29;
    } else {
        /* Immediate
     *   Transition 1:
     *   _ARun101
     *    to
     *   finalState29
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE29;
    }
}

// Logic function of the simple state finalState29 in region region_ACtrl10
static inline void region_ACtrl10_statefinalState29(_ACtrl10Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region region__EA_Entry8
static inline void region__EA_Entry8(__EA_Entry8Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case S4_0:
                region__EA_Entry8_stateS4_0(context);
                break;

            case __EA_INIT12:
                region__EA_Entry8_state__EA_Init(context);
                break;

            case __EA_MAIN13:
                region__EA_Entry8_state__EA_Main(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN13RUNNING:
                region__EA_Entry8_state__EA_Mainrunning(context);
                break;

            case _AC11:
                region__EA_Entry8_state_AC11(context);
                break;

            case _TC6:
                region__EA_Entry8_state_Tc(context);
                break;

            case FINALSTATE39:
                region__EA_Entry8_statefinalState39(context);
                break;

        }
    }
}

// Logic function of the simple state S4_0 in region region__EA_Entry8
static inline void region__EA_Entry8_stateS4_0(__EA_Entry8Context *context) {
    if (context->iface->_request_route_local_result) {
        /* Immediate
     *   Transition 0:
     *   S4_0
     *    to
     *   __EA_Init
     *   Trigger: context->iface->_request_route_local_result
     */
        context->delayedEnabled = 0;
        context->activeState = __EA_INIT12;
    } else {
        /* Immediate
     *   Transition 1:
     *   S4_0
     *    to
     *   _Tc
     */
        context->delayedEnabled = 0;
        context->activeState = _TC6;
    }
}

// Logic function of the simple state __EA_Init in region region__EA_Entry8
static inline void region__EA_Entry8_state__EA_Init(__EA_Entry8Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm8 = 0
     */
    context->iface->_request_route_local__Tterm8 = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN13;
}

// Init function of superstate __EA_Main in region region__EA_Entry8
static inline void region__EA_Entry8_state__EA_Main(__EA_Entry8Context *context) {
    context->activeState = __EA_MAIN13RUNNING;
    context->_actrl11context.activeState = _ARUN111;
    context->_actrl11context.delayedEnabled = 0;
    context->_actrl11context.activePriority = 0;
    context->_actrl11context.threadStatus = READY;
    context->__ea_entry9context.activeState = __SD_DEPTH36;
    context->__ea_entry9context.delayedEnabled = 0;
    context->__ea_entry9context.activePriority = 0;
    context->__ea_entry9context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region region__EA_Entry8
static inline void region__EA_Entry8_state__EA_Mainrunning(__EA_Entry8Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl11context.threadStatus == READY) {
        if (context->_actrl11context.activePriority == activePriority) {
            context->_actrl11context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl11.
            region_ACtrl11(&context->_actrl11context);
        }
        if (context->_actrl11context.threadStatus == READY) {
            if (context->_actrl11context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl11context.activePriority;
            }
        }
    }
    if (context->__ea_entry9context.threadStatus == READY) {
        if (context->__ea_entry9context.activePriority == activePriority) {
            context->__ea_entry9context.threadStatus = RUNNING;
            // Call the logic code of thread region__EA_Entry9.
            region__EA_Entry9(&context->__ea_entry9context);
        }
        if (context->__ea_entry9context.threadStatus == READY) {
            if (context->__ea_entry9context.activePriority > newActivePriority) {
                newActivePriority = context->__ea_entry9context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl11context.threadStatus != READY &&
        context->__ea_entry9context.threadStatus != READY) {
        if ((context->_actrl11context.activePriority > context->activePriority) &&
            (context->_actrl11context.threadStatus == PAUSING))
            context->activePriority = context->_actrl11context.activePriority;
        if ((context->__ea_entry9context.activePriority > context->activePriority) &&
            (context->__ea_entry9context.threadStatus == PAUSING))
            context->activePriority = context->__ea_entry9context.activePriority;
    }
    if (context->_actrl11context.threadStatus == TERMINATED &&
        context->__ea_entry9context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC11
     *   Trigger: context->_actrl11context.threadStatus == TERMINATED &&
    context->__ea_entry9context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC11;
    } else {
        if (context->_actrl11context.threadStatus == READY ||
            context->__ea_entry9context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl11
static inline void region_ACtrl11(_ACtrl11Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN111:
                region_ACtrl11_state_ARun111(context);
                break;

            case FINALSTATE30:
                region_ACtrl11_statefinalState30(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun111 in region region_ACtrl11
static inline void region_ACtrl11_state_ARun111(_ACtrl11Context *context) {
    if (context->iface->_request_route_local__Tterm8) {
        /* Immediate
     *   Transition 0:
     *   _ARun111
     *    to
     *   finalState30
     *   Trigger: context->iface->_request_route_local__Tterm8
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE30;
    } else if (context->iface->_request_route_local__Tterm7 || 1) {
        /* Immediate
     *   Transition 1:
     *   _ARun111
     *    to
     *   finalState30
     *   Trigger: context->iface->_request_route_local__Tterm7 || 1
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE30;
    } else {
        // The thread pauses after this state is done.
        context->threadStatus = PAUSING;
        context->activePriority = 0;
    }
}

// Logic function of the simple state finalState30 in region region_ACtrl11
static inline void region_ACtrl11_statefinalState30(_ACtrl11Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region region__EA_Entry9
static inline void region__EA_Entry9(__EA_Entry9Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case __SD_DEPTH36:
                region__EA_Entry9_state__sd_Depth36(context);
                break;

            case S4_1_21:
                region__EA_Entry9_stateS4_1_21(context);
                break;

            case __EA_INIT11:
                region__EA_Entry9_state__EA_Init(context);
                break;

            case __EA_MAIN12:
                region__EA_Entry9_state__EA_Main(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN12RUNNING:
                region__EA_Entry9_state__EA_Mainrunning(context);
                break;

            case _AC12:
                region__EA_Entry9_state_AC12(context);
                break;

            case S4_1_31:
                region__EA_Entry9_stateS4_1_31(context);
                break;

            case FINALSTATE38:
                region__EA_Entry9_statefinalState38(context);
                break;

        }
    }
}

// Logic function of the simple state __sd_Depth36 in region region__EA_Entry9
static inline void region__EA_Entry9_state__sd_Depth36(__EA_Entry9Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth36
     *    to
     *   S4_1_21
     *   Effects: _request_route_local_segment_ids_count = config_get_array_string_value("route", id, "path", _request_route_local_segment_ids)
     */
    context->iface->_request_route_local_segment_ids_count = config_get_array_string_value("route", context->iface->id, "path", context->iface->_request_route_local_segment_ids);
    context->delayedEnabled = 0;
    context->activeState = S4_1_21;
}

// Logic function of the simple state S4_1_21 in region region__EA_Entry9
static inline void region__EA_Entry9_stateS4_1_21(__EA_Entry9Context *context) {
    /* Immediate
     *   Transition 0:
     *   S4_1_21
     *    to
     *   S4_1_31
     *   Effects: _request_route_local_i2 = 0
     */
    context->iface->_request_route_local_i2 = 0;
    context->delayedEnabled = 0;
    context->activeState = S4_1_31;
}

// Logic function of the simple state __EA_Init in region region__EA_Entry9
static inline void region__EA_Entry9_state__EA_Init(__EA_Entry9Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm9 = 0
     */
    context->iface->_request_route_local__Tterm9 = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN12;
}

// Init function of superstate __EA_Main in region region__EA_Entry9
static inline void region__EA_Entry9_state__EA_Main(__EA_Entry9Context *context) {
    context->activeState = __EA_MAIN12RUNNING;
    context->_actrl12context.activeState = _ARUN121;
    context->_actrl12context.delayedEnabled = 0;
    context->_actrl12context.activePriority = 0;
    context->_actrl12context.threadStatus = READY;
    context->__ea_entry10context.activeState = S4_1_3_0_01;
    context->__ea_entry10context.delayedEnabled = 0;
    context->__ea_entry10context.activePriority = 0;
    context->__ea_entry10context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region region__EA_Entry9
static inline void region__EA_Entry9_state__EA_Mainrunning(__EA_Entry9Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl12context.threadStatus == READY) {
        if (context->_actrl12context.activePriority == activePriority) {
            context->_actrl12context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl12.
            region_ACtrl12(&context->_actrl12context);
        }
        if (context->_actrl12context.threadStatus == READY) {
            if (context->_actrl12context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl12context.activePriority;
            }
        }
    }
    if (context->__ea_entry10context.threadStatus == READY) {
        if (context->__ea_entry10context.activePriority == activePriority) {
            context->__ea_entry10context.threadStatus = RUNNING;
            // Call the logic code of thread region__EA_Entry10.
            region__EA_Entry10(&context->__ea_entry10context);
        }
        if (context->__ea_entry10context.threadStatus == READY) {
            if (context->__ea_entry10context.activePriority > newActivePriority) {
                newActivePriority = context->__ea_entry10context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl12context.threadStatus != READY &&
        context->__ea_entry10context.threadStatus != READY) {
        if ((context->_actrl12context.activePriority > context->activePriority) &&
            (context->_actrl12context.threadStatus == PAUSING))
            context->activePriority = context->_actrl12context.activePriority;
        if ((context->__ea_entry10context.activePriority > context->activePriority) &&
            (context->__ea_entry10context.threadStatus == PAUSING))
            context->activePriority = context->__ea_entry10context.activePriority;
    }
    if (context->_actrl12context.threadStatus == TERMINATED &&
        context->__ea_entry10context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC12
     *   Trigger: context->_actrl12context.threadStatus == TERMINATED &&
    context->__ea_entry10context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC12;
    } else {
        if (context->_actrl12context.threadStatus == READY ||
            context->__ea_entry10context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl12
static inline void region_ACtrl12(_ACtrl12Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN121:
                region_ACtrl12_state_ARun121(context);
                break;

            case FINALSTATE31:
                region_ACtrl12_statefinalState31(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun121 in region region_ACtrl12
static inline void region_ACtrl12_state_ARun121(_ACtrl12Context *context) {
    if (context->iface->_request_route_local__Tterm9) {
        /* Immediate
     *   Transition 0:
     *   _ARun121
     *    to
     *   finalState31
     *   Trigger: context->iface->_request_route_local__Tterm9
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE31;
    } else if (context->iface->_request_route_local__Tterm8 || context->iface->_request_route_local__Tterm7 || 1) {
        /* Immediate
     *   Transition 1:
     *   _ARun121
     *    to
     *   finalState31
     *   Trigger: context->iface->_request_route_local__Tterm8 || context->iface->_request_route_local__Tterm7 || 1
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE31;
    } else {
        // The thread pauses after this state is done.
        context->threadStatus = PAUSING;
        context->activePriority = 0;
    }
}

// Logic function of the simple state finalState31 in region region_ACtrl12
static inline void region_ACtrl12_statefinalState31(_ACtrl12Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region region__EA_Entry10
static inline void region__EA_Entry10(__EA_Entry10Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case S4_1_3_0_01:
                region__EA_Entry10_stateS4_1_3_0_01(context);
                break;

            case S4_1_3_0_11:
                region__EA_Entry10_stateS4_1_3_0_11(context);
                break;

            case __EA_INIT10:
                region__EA_Entry10_state__EA_Init(context);
                break;

            case __EA_MAIN11:
                region__EA_Entry10_state__EA_Main(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN11RUNNING:
                region__EA_Entry10_state__EA_Mainrunning(context);
                break;

            case _AC13:
                region__EA_Entry10_state_AC13(context);
                break;

            case __SD_DEPTH45:
                region__EA_Entry10_state__sd_Depth45(context);
                break;

            case __TE_S25:
                region__EA_Entry10_state__te_S25(context);
                break;

            case FINALSTATE37:
                region__EA_Entry10_statefinalState37(context);
                break;

        }
    }
}

// Logic function of the simple state S4_1_3_0_01 in region region__EA_Entry10
static inline void region__EA_Entry10_stateS4_1_3_0_01(__EA_Entry10Context *context) {
    /* Immediate
     *   Transition 0:
     *   S4_1_3_0_01
     *    to
     *   S4_1_3_0_11
     *   Effects: _request_route_local_segment_id = _request_route_local_segment_ids[_request_route_local_i2]
     */
    context->iface->_request_route_local_segment_id = context->iface->_request_route_local_segment_ids[context->iface->_request_route_local_i2];
    context->delayedEnabled = 0;
    context->activeState = S4_1_3_0_11;
}

// Logic function of the simple state S4_1_3_0_11 in region region__EA_Entry10
static inline void region__EA_Entry10_stateS4_1_3_0_11(__EA_Entry10Context *context) {
    /* Immediate
     *   Transition 0:
     *   S4_1_3_0_11
     *    to
     *   __EA_Init
     *   Effects: _request_route_local_oc = is_segment_occupied(_request_route_local_segment_id)
     */
    context->iface->_request_route_local_oc = is_segment_occupied(context->iface->_request_route_local_segment_id);
    context->delayedEnabled = 0;
    context->activeState = __EA_INIT10;
}

// Logic function of the simple state __EA_Init in region region__EA_Entry10
static inline void region__EA_Entry10_state__EA_Init(__EA_Entry10Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm10 = 0
     */
    context->iface->_request_route_local__Tterm10 = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN11;
}

// Init function of superstate __EA_Main in region region__EA_Entry10
static inline void region__EA_Entry10_state__EA_Main(__EA_Entry10Context *context) {
    context->activeState = __EA_MAIN11RUNNING;
    context->_actrl13context.activeState = _ARUN131;
    context->_actrl13context.delayedEnabled = 0;
    context->_actrl13context.activePriority = 0;
    context->_actrl13context.threadStatus = READY;
    context->__ea_entry11context.activeState = S4_1_3_0_2_0;
    context->__ea_entry11context.delayedEnabled = 0;
    context->__ea_entry11context.activePriority = 0;
    context->__ea_entry11context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region region__EA_Entry10
static inline void region__EA_Entry10_state__EA_Mainrunning(__EA_Entry10Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl13context.threadStatus == READY) {
        if (context->_actrl13context.activePriority == activePriority) {
            context->_actrl13context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl13.
            region_ACtrl13(&context->_actrl13context);
        }
        if (context->_actrl13context.threadStatus == READY) {
            if (context->_actrl13context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl13context.activePriority;
            }
        }
    }
    if (context->__ea_entry11context.threadStatus == READY) {
        if (context->__ea_entry11context.activePriority == activePriority) {
            context->__ea_entry11context.threadStatus = RUNNING;
            // Call the logic code of thread region__EA_Entry11.
            region__EA_Entry11(&context->__ea_entry11context);
        }
        if (context->__ea_entry11context.threadStatus == READY) {
            if (context->__ea_entry11context.activePriority > newActivePriority) {
                newActivePriority = context->__ea_entry11context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl13context.threadStatus != READY &&
        context->__ea_entry11context.threadStatus != READY) {
        if ((context->_actrl13context.activePriority > context->activePriority) &&
            (context->_actrl13context.threadStatus == PAUSING))
            context->activePriority = context->_actrl13context.activePriority;
        if ((context->__ea_entry11context.activePriority > context->activePriority) &&
            (context->__ea_entry11context.threadStatus == PAUSING))
            context->activePriority = context->__ea_entry11context.activePriority;
    }
    if (context->_actrl13context.threadStatus == TERMINATED &&
        context->__ea_entry11context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC13
     *   Trigger: context->_actrl13context.threadStatus == TERMINATED &&
    context->__ea_entry11context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC13;
    } else {
        if (context->_actrl13context.threadStatus == READY ||
            context->__ea_entry11context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl13
static inline void region_ACtrl13(_ACtrl13Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN131:
                region_ACtrl13_state_ARun131(context);
                break;

            case FINALSTATE32:
                region_ACtrl13_statefinalState32(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun131 in region region_ACtrl13
static inline void region_ACtrl13_state_ARun131(_ACtrl13Context *context) {
    if (context->iface->_request_route_local__Tterm10) {
        /* Immediate
     *   Transition 0:
     *   _ARun131
     *    to
     *   finalState32
     *   Trigger: context->iface->_request_route_local__Tterm10
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE32;
    } else if (context->iface->_request_route_local__Tterm9 || context->iface->_request_route_local__Tterm8 || context->iface->_request_route_local__Tterm7 || 1) {
        /* Immediate
     *   Transition 1:
     *   _ARun131
     *    to
     *   finalState32
     *   Trigger: context->iface->_request_route_local__Tterm9 || context->iface->_request_route_local__Tterm8 || context->iface->_request_route_local__Tterm7 || 1
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE32;
    } else {
        // The thread pauses after this state is done.
        context->threadStatus = PAUSING;
        context->activePriority = 0;
    }
}

// Logic function of the simple state finalState32 in region region_ACtrl13
static inline void region_ACtrl13_statefinalState32(_ACtrl13Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region region__EA_Entry11
static inline void region__EA_Entry11(__EA_Entry11Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case S4_1_3_0_2_0:
                region__EA_Entry11_stateS4_1_3_0_2_0(context);
                break;

            case __EA_INIT9:
                region__EA_Entry11_state__EA_Init(context);
                break;

            case __EA_MAIN10:
                region__EA_Entry11_state__EA_Main(context);
                // It was a superstate reset, fall through.

            case __EA_MAIN10RUNNING:
                region__EA_Entry11_state__EA_Mainrunning(context);
                break;

            case _AC14:
                region__EA_Entry11_state_AC14(context);
                break;

            case _TC5:
                region__EA_Entry11_state_Tc(context);
                break;

            case FINALSTATE36:
                region__EA_Entry11_statefinalState36(context);
                break;

        }
    }
}

// Logic function of the simple state S4_1_3_0_2_0 in region region__EA_Entry11
static inline void region__EA_Entry11_stateS4_1_3_0_2_0(__EA_Entry11Context *context) {
    if (context->iface->_request_route_local_oc) {
        /* Immediate
     *   Transition 0:
     *   S4_1_3_0_2_0
     *    to
     *   __EA_Init
     *   Trigger: context->iface->_request_route_local_oc
     */
        context->delayedEnabled = 0;
        context->activeState = __EA_INIT9;
    } else {
        /* Immediate
     *   Transition 1:
     *   S4_1_3_0_2_0
     *    to
     *   _Tc
     */
        context->delayedEnabled = 0;
        context->activeState = _TC5;
    }
}

// Logic function of the simple state __EA_Init in region region__EA_Entry11
static inline void region__EA_Entry11_state__EA_Init(__EA_Entry11Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm11 = 0
     */
    context->iface->_request_route_local__Tterm11 = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN10;
}

// Init function of superstate __EA_Main in region region__EA_Entry11
static inline void region__EA_Entry11_state__EA_Main(__EA_Entry11Context *context) {
    context->activeState = __EA_MAIN10RUNNING;
    context->_actrl14context.activeState = _ARUN141;
    context->_actrl14context.delayedEnabled = 0;
    context->_actrl14context.activePriority = 0;
    context->_actrl14context.threadStatus = READY;
    context->region34context.activeState = __SD_DEPTH42;
    context->region34context.delayedEnabled = 0;
    context->region34context.activePriority = 0;
    context->region34context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region region__EA_Entry11
static inline void region__EA_Entry11_state__EA_Mainrunning(__EA_Entry11Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl14context.threadStatus == READY) {
        if (context->_actrl14context.activePriority == activePriority) {
            context->_actrl14context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl14.
            region_ACtrl14(&context->_actrl14context);
        }
        if (context->_actrl14context.threadStatus == READY) {
            if (context->_actrl14context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl14context.activePriority;
            }
        }
    }
    if (context->region34context.threadStatus == READY) {
        if (context->region34context.activePriority == activePriority) {
            context->region34context.threadStatus = RUNNING;
            // Call the logic code of thread regionregion34.
            regionregion34(&context->region34context);
        }
        if (context->region34context.threadStatus == READY) {
            if (context->region34context.activePriority > newActivePriority) {
                newActivePriority = context->region34context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl14context.threadStatus != READY &&
        context->region34context.threadStatus != READY) {
        if ((context->_actrl14context.activePriority > context->activePriority) &&
            (context->_actrl14context.threadStatus == PAUSING))
            context->activePriority = context->_actrl14context.activePriority;
        if ((context->region34context.activePriority > context->activePriority) &&
            (context->region34context.threadStatus == PAUSING))
            context->activePriority = context->region34context.activePriority;
    }
    if (context->_actrl14context.threadStatus == TERMINATED &&
        context->region34context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC14
     *   Trigger: context->_actrl14context.threadStatus == TERMINATED &&
    context->region34context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC14;
    } else {
        if (context->_actrl14context.threadStatus == READY ||
            context->region34context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl14
static inline void region_ACtrl14(_ACtrl14Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN141:
                region_ACtrl14_state_ARun141(context);
                break;

            case FINALSTATE33:
                region_ACtrl14_statefinalState33(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun141 in region region_ACtrl14
static inline void region_ACtrl14_state_ARun141(_ACtrl14Context *context) {
    if (context->iface->_request_route_local__Tterm11) {
        /* Immediate
     *   Transition 0:
     *   _ARun141
     *    to
     *   finalState33
     *   Trigger: context->iface->_request_route_local__Tterm11
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE33;
    } else if (context->iface->_request_route_local__Tterm10 || context->iface->_request_route_local__Tterm9 || context->iface->_request_route_local__Tterm8 || context->iface->_request_route_local__Tterm7 || 1) {
        /* Immediate
     *   Transition 1:
     *   _ARun141
     *    to
     *   finalState33
     *   Trigger: context->iface->_request_route_local__Tterm10 || context->iface->_request_route_local__Tterm9 || context->iface->_request_route_local__Tterm8 || context->iface->_request_route_local__Tterm7 || 1
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE33;
    } else {
        // The thread pauses after this state is done.
        context->threadStatus = PAUSING;
        context->activePriority = 0;
    }
}

// Logic function of the simple state finalState33 in region region_ACtrl14
static inline void region_ACtrl14_statefinalState33(_ACtrl14Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region regionregion34
static inline void regionregion34(Region34Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case __SD_DEPTH42:
                regionregion34_state__sd_Depth42(context);
                break;

            case __TE_S23:
                regionregion34_state__te_S23(context);
                break;

            case FINALSTATE35:
                regionregion34_statefinalState35(context);
                break;

        }
    }
}

// Logic function of the simple state __sd_Depth42 in region regionregion34
static inline void regionregion34_state__sd_Depth42(Region34Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth42
     *    to
     *   __te_S23
     *   Effects: _request_route_local_result = 0
     */
    context->iface->_request_route_local_result = 0;
    context->delayedEnabled = 0;
    context->activeState = __TE_S23;
}

// Logic function of the simple state __te_S23 in region regionregion34
static inline void regionregion34_state__te_S23(Region34Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S23
     *    to
     *   finalState35
     *   Effects: _request_route_local__Tterm11 = 1
     */
    context->iface->_request_route_local__Tterm11 = 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE35;
}

// Logic function of the simple state finalState35 in region regionregion34
static inline void regionregion34_statefinalState35(Region34Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC14 in region region__EA_Entry11
static inline void region__EA_Entry11_state_AC14(__EA_Entry11Context *context) {
    if (context->iface->_request_route_local__Tterm11) {
        /* Immediate
     *   Transition 0:
     *   _AC14
     *    to
     *   _Tc
     *   Trigger: context->iface->_request_route_local__Tterm11
     */
        context->delayedEnabled = 0;
        context->activeState = _TC5;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC14
     *    to
     *   finalState36
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE36;
    }
}

// Logic function of the simple state _Tc in region region__EA_Entry11
static inline void region__EA_Entry11_state_Tc(__EA_Entry11Context *context) {
    /* Immediate
     *   Transition 0:
     *   _Tc
     *    to
     *   finalState36
     *   Effects: _request_route_local__Tterm10 = 1
     */
    context->iface->_request_route_local__Tterm10 = 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE36;
}

// Logic function of the simple state finalState36 in region region__EA_Entry11
static inline void region__EA_Entry11_statefinalState36(__EA_Entry11Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC13 in region region__EA_Entry10
static inline void region__EA_Entry10_state_AC13(__EA_Entry10Context *context) {
    if (context->iface->_request_route_local__Tterm10) {
        /* Immediate
     *   Transition 0:
     *   _AC13
     *    to
     *   __sd_Depth45
     *   Trigger: context->iface->_request_route_local__Tterm10
     */
        context->delayedEnabled = 0;
        context->activeState = __SD_DEPTH45;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC13
     *    to
     *   finalState37
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE37;
    }
}

// Logic function of the simple state __sd_Depth45 in region region__EA_Entry10
static inline void region__EA_Entry10_state__sd_Depth45(__EA_Entry10Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth45
     *    to
     *   __te_S25
     *   Effects: _request_route_local_i2 = _request_route_local_i2 + 1
     */
    context->iface->_request_route_local_i2 = context->iface->_request_route_local_i2 + 1;
    context->delayedEnabled = 0;
    context->activeState = __TE_S25;
}

// Logic function of the simple state __te_S25 in region region__EA_Entry10
static inline void region__EA_Entry10_state__te_S25(__EA_Entry10Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S25
     *    to
     *   finalState37
     *   Effects: _request_route_local__Tterm9 = 1
     */
    context->iface->_request_route_local__Tterm9 = 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE37;
}

// Logic function of the simple state finalState37 in region region__EA_Entry10
static inline void region__EA_Entry10_statefinalState37(__EA_Entry10Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC12 in region region__EA_Entry9
static inline void region__EA_Entry9_state_AC12(__EA_Entry9Context *context) {
    if (context->iface->_request_route_local__Tterm9) {
        /* Immediate
     *   Transition 0:
     *   _AC12
     *    to
     *   S4_1_31
     *   Trigger: context->iface->_request_route_local__Tterm9
     */
        context->delayedEnabled = 0;
        context->activeState = S4_1_31;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC12
     *    to
     *   finalState38
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE38;
    }
}

// Logic function of the simple state S4_1_31 in region region__EA_Entry9
static inline void region__EA_Entry9_stateS4_1_31(__EA_Entry9Context *context) {
    if (context->iface->_request_route_local_i2 < context->iface->_request_route_local_segment_ids_count && context->iface->_request_route_local_result) {
        /* Immediate
     *   Transition 0:
     *   S4_1_31
     *    to
     *   __EA_Init
     *   Trigger: context->iface->_request_route_local_i2 < context->iface->_request_route_local_segment_ids_count && context->iface->_request_route_local_result
     */
        context->delayedEnabled = 0;
        context->activeState = __EA_INIT11;
    } else {
        /* Immediate
     *   Transition 1:
     *   S4_1_31
     *    to
     *   finalState38
     *   Effects: _request_route_local__Tterm8 = 1
     */
        context->iface->_request_route_local__Tterm8 = 1;
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE38;
    }
}

// Logic function of the simple state finalState38 in region region__EA_Entry9
static inline void region__EA_Entry9_statefinalState38(__EA_Entry9Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC11 in region region__EA_Entry8
static inline void region__EA_Entry8_state_AC11(__EA_Entry8Context *context) {
    if (context->iface->_request_route_local__Tterm8) {
        /* Immediate
     *   Transition 0:
     *   _AC11
     *    to
     *   _Tc
     *   Trigger: context->iface->_request_route_local__Tterm8
     */
        context->delayedEnabled = 0;
        context->activeState = _TC6;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC11
     *    to
     *   finalState39
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE39;
    }
}

// Logic function of the simple state _Tc in region region__EA_Entry8
static inline void region__EA_Entry8_state_Tc(__EA_Entry8Context *context) {
    /* Immediate
     *   Transition 0:
     *   _Tc
     *    to
     *   finalState39
     *   Effects: _request_route_local__Tterm7 = 1
     */
    context->iface->_request_route_local__Tterm7 = 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE39;
}

// Logic function of the simple state finalState39 in region region__EA_Entry8
static inline void region__EA_Entry8_statefinalState39(__EA_Entry8Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC10 in region regionregion0
static inline void regionregion0_state_AC10(Region0Context *context) {
    if (context->iface->_request_route_local__Tterm7) {
        /* Immediate
     *   Transition 0:
     *   _AC10
     *    to
     *   S53
     *   Trigger: context->iface->_request_route_local__Tterm7
     */
        context->delayedEnabled = 0;
        context->activeState = S53;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC10
     *    to
     *   __te_S26
     */
        context->delayedEnabled = 0;
        context->activeState = __TE_S26;
    }
}

// Logic function of the simple state S53 in region regionregion0
static inline void regionregion0_stateS53(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   S53
     *    to
     *   __te_S26
     *   Effects: _request_route_local_is_clear = _request_route_local_result
     */
    context->iface->_request_route_local_is_clear = context->iface->_request_route_local_result;
    context->delayedEnabled = 0;
    context->activeState = __TE_S26;
}

// Logic function of the simple state __te_S26 in region regionregion0
static inline void regionregion0_state__te_S26(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S26
     *    to
     *   S4_3_1_01
     *   Effects: _taken_transitions[10] += 1
     */
    context->iface->_taken_transitions[10] += 1;
    context->delayedEnabled = 0;
    context->activeState = S4_3_1_01;
}

// Logic function of the simple state __te_S6 in region regionregion0
static inline void regionregion0_state__te_S6(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S6
     *    to
     *   __sd_Depth4
     *   Effects: _taken_transitions[12] += 1
     */
    context->iface->_taken_transitions[12] += 1;
    context->delayedEnabled = 0;
    context->activeState = __SD_DEPTH4;
}

// Logic function of the simple state __sd_Depth4 in region regionregion0
static inline void regionregion0_state__sd_Depth4(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth4
     *    to
     *   __te_S8
     *   Effects: id = ""
     */
    context->iface->id = "";
    context->delayedEnabled = 0;
    context->activeState = __TE_S8;
}

// Logic function of the simple state __te_S8 in region regionregion0
static inline void regionregion0_state__te_S8(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S8
     *    to
     *   __te_S9
     *   Effects: _taken_transitions[15] += 1
     */
    context->iface->_taken_transitions[15] += 1;
    context->delayedEnabled = 0;
    context->activeState = __TE_S9;
}

// Logic function of the simple state __te_S9 in region regionregion0
static inline void regionregion0_state__te_S9(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S9
     *    to
     *   __te_S15
     *   Effects: _taken_transitions[14] += 1
     */
    context->iface->_taken_transitions[14] += 1;
    context->delayedEnabled = 0;
    context->activeState = __TE_S15;
}

// Logic function of the simple state __te_S15 in region regionregion0
static inline void regionregion0_state__te_S15(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S15
     *    to
     *   __te_S27
     *   Effects: _taken_transitions[11] += 1
     */
    context->iface->_taken_transitions[11] += 1;
    context->delayedEnabled = 0;
    context->activeState = __TE_S27;
}

// Logic function of the simple state __te_S27 in region regionregion0
static inline void regionregion0_state__te_S27(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S27
     *    to
     *   __te_S28
     *   Effects: _taken_transitions[9] += 1
     */
    context->iface->_taken_transitions[9] += 1;
    context->delayedEnabled = 0;
    context->activeState = __TE_S28;
}

// Logic function of the simple state S4_3_1_01 in region regionregion0
static inline void regionregion0_stateS4_3_1_01(Region0Context *context) {
    if (!context->iface->_request_route_local_is_clear) {
        /* Immediate
     *   Transition 0:
     *   S4_3_1_01
     *    to
     *   __te_S6
     *   Trigger: !context->iface->_request_route_local_is_clear
     */
        context->delayedEnabled = 0;
        context->activeState = __TE_S6;
    } else {
        /* Immediate
     *   Transition 1:
     *   S4_3_1_01
     *    to
     *   S01
     *   Effects: _taken_transitions[13] += 1
     */
        context->iface->_taken_transitions[13] += 1;
        context->delayedEnabled = 0;
        context->activeState = S01;
    }
}

// Logic function of the simple state S01 in region regionregion0
static inline void regionregion0_stateS01(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   S01
     *    to
     *   __te_S10
     *   Effects: _request_route_local_success = config_set_scalar_string_value("route", id, "train", train_id)
     */
    context->iface->_request_route_local_success = config_set_scalar_string_value("route", context->iface->id, "train", context->iface->train_id);
    context->delayedEnabled = 0;
    context->activeState = __TE_S10;
}

// Logic function of the simple state __te_S10 in region regionregion0
static inline void regionregion0_state__te_S10(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S10
     *    to
     *   __sd_Depth7
     *   Effects: _taken_transitions[17] += 1
     */
    context->iface->_taken_transitions[17] += 1;
    context->delayedEnabled = 0;
    context->activeState = __SD_DEPTH7;
}

// Logic function of the simple state __sd_Depth7 in region regionregion0
static inline void regionregion0_state__sd_Depth7(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth7
     *    to
     *   S21
     *   Effects: _request_route_local_points_count = config_get_array_string_value("route", id, "points", _request_route_local_point_ids)
     */
    context->iface->_request_route_local_points_count = config_get_array_string_value("route", context->iface->id, "points", context->iface->_request_route_local_point_ids);
    context->delayedEnabled = 0;
    context->activeState = S21;
}

// Logic function of the simple state S21 in region regionregion0
static inline void regionregion0_stateS21(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   S21
     *    to
     *   S41
     *   Effects: _request_route_local_i = 0
     */
    context->iface->_request_route_local_i = 0;
    context->delayedEnabled = 0;
    context->activeState = S41;
}

// Logic function of the simple state __EA_Init in region regionregion0
static inline void regionregion0_state__EA_Init5(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __EA_Init
     *    to
     *   __EA_Main
     *   Effects: _request_route_local__Tterm = 0
     */
    context->iface->_request_route_local__Tterm = 0;
    context->delayedEnabled = 0;
    context->activeState = __EA_MAIN18;
}

// Init function of superstate __EA_Main in region regionregion0
static inline void regionregion0_state__EA_Main5(Region0Context *context) {
    context->activeState = __EA_MAIN18RUNNING;
    context->_actrl2context.activeState = _ARUN24;
    context->_actrl2context.delayedEnabled = 0;
    context->_actrl2context.activePriority = 0;
    context->_actrl2context.threadStatus = READY;
    context->region41context.activeState = S3_0_01;
    context->region41context.delayedEnabled = 0;
    context->region41context.activePriority = 0;
    context->region41context.threadStatus = READY;
}

// Logic function of the superstate __EA_Main in region regionregion0
static inline void regionregion0_state__EA_Main5running(Region0Context *context) {
// Set the thread status to waiting for the upcoming tick.
    // Calculate the highest active priority.
    int activePriority = context->activePriority;
    int newActivePriority = 0;

    if (context->_actrl2context.threadStatus == READY) {
        if (context->_actrl2context.activePriority == activePriority) {
            context->_actrl2context.threadStatus = RUNNING;
            // Call the logic code of thread region_ACtrl2.
            region_ACtrl2(&context->_actrl2context);
        }
        if (context->_actrl2context.threadStatus == READY) {
            if (context->_actrl2context.activePriority > newActivePriority) {
                newActivePriority = context->_actrl2context.activePriority;
            }
        }
    }
    if (context->region41context.threadStatus == READY) {
        if (context->region41context.activePriority == activePriority) {
            context->region41context.threadStatus = RUNNING;
            // Call the logic code of thread regionregion41.
            regionregion41(&context->region41context);
        }
        if (context->region41context.threadStatus == READY) {
            if (context->region41context.activePriority > newActivePriority) {
                newActivePriority = context->region41context.activePriority;
            }
        }
    }

    context->activePriority = newActivePriority;


    if (context->_actrl2context.threadStatus != READY &&
        context->region41context.threadStatus != READY) {
        if ((context->_actrl2context.activePriority > context->activePriority) &&
            (context->_actrl2context.threadStatus == PAUSING))
            context->activePriority = context->_actrl2context.activePriority;
        if ((context->region41context.activePriority > context->activePriority) &&
            (context->region41context.threadStatus == PAUSING))
            context->activePriority = context->region41context.activePriority;
    }
    if (context->_actrl2context.threadStatus == TERMINATED &&
        context->region41context.threadStatus == TERMINATED) {
        /* Immediate
     *   Transition 0:
     *   __EA_Main
     *    to
     *   _AC2
     *   Trigger: context->_actrl2context.threadStatus == TERMINATED &&
    context->region41context.threadStatus == TERMINATED
     */
        context->delayedEnabled = 0;
        context->activeState = _AC2;
    } else {
        if (context->_actrl2context.threadStatus == READY ||
            context->region41context.threadStatus == READY) {
            context->threadStatus = READY;
        } else {
            context->threadStatus = PAUSING;
        }
    }
}

// Function of region region_ACtrl2
static inline void region_ACtrl2(_ACtrl2Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case _ARUN24:
                region_ACtrl2_state_ARun24(context);
                break;

            case FINALSTATE40:
                region_ACtrl2_statefinalState40(context);
                break;

        }
    }
}

// Logic function of the simple state _ARun24 in region region_ACtrl2
static inline void region_ACtrl2_state_ARun24(_ACtrl2Context *context) {
    if (context->iface->_request_route_local__Tterm) {
        /* Immediate
     *   Transition 0:
     *   _ARun24
     *    to
     *   finalState40
     *   Trigger: context->iface->_request_route_local__Tterm
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE40;
    } else {
        /* Immediate
     *   Transition 1:
     *   _ARun24
     *    to
     *   finalState40
     */
        context->delayedEnabled = 0;
        context->activeState = FINALSTATE40;
    }
}

// Logic function of the simple state finalState40 in region region_ACtrl2
static inline void region_ACtrl2_statefinalState40(_ACtrl2Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Function of region regionregion41
static inline void regionregion41(Region41Context *context) {
    // Cycle through the states of the region as long as this thread is set to RUNNING.
    while(context->threadStatus == RUNNING) {
        switch(context->activeState) {
            case S3_0_01:
                regionregion41_stateS3_0_01(context);
                break;

            case S3_0_11:
                regionregion41_stateS3_0_11(context);
                break;

            case S3_0_21:
                regionregion41_stateS3_0_21(context);
                break;

            case __SD_DEPTH13:
                regionregion41_state__sd_Depth13(context);
                break;

            case __TE_S12:
                regionregion41_state__te_S12(context);
                break;

            case FINALSTATE42:
                regionregion41_statefinalState42(context);
                break;

        }
    }
}

// Logic function of the simple state S3_0_01 in region regionregion41
static inline void regionregion41_stateS3_0_01(Region41Context *context) {
    /* Immediate
     *   Transition 0:
     *   S3_0_01
     *    to
     *   S3_0_11
     *   Effects: _request_route_local_point_id = _request_route_local_point_ids[_request_route_local_i]
     */
    context->iface->_request_route_local_point_id = context->iface->_request_route_local_point_ids[context->iface->_request_route_local_i];
    context->delayedEnabled = 0;
    context->activeState = S3_0_11;
}

// Logic function of the simple state S3_0_11 in region regionregion41
static inline void regionregion41_stateS3_0_11(Region41Context *context) {
    /* Immediate
     *   Transition 0:
     *   S3_0_11
     *    to
     *   S3_0_21
     *   Effects: _request_route_local_point_position = config_get_scalar_string_value("route_point", _request_route_local_point_id, "position")
     */
    context->iface->_request_route_local_point_position = config_get_scalar_string_value("route_point", context->iface->_request_route_local_point_id, "position");
    context->delayedEnabled = 0;
    context->activeState = S3_0_21;
}

// Logic function of the simple state S3_0_21 in region regionregion41
static inline void regionregion41_stateS3_0_21(Region41Context *context) {
    /* Immediate
     *   Transition 0:
     *   S3_0_21
     *    to
     *   __sd_Depth13
     *   Effects: _request_route_local_success1 = track_state_set_value("point", _request_route_local_point_id, _request_route_local_point_position)
     */
    context->iface->_request_route_local_success1 = track_state_set_value("point", context->iface->_request_route_local_point_id, context->iface->_request_route_local_point_position);
    context->delayedEnabled = 0;
    context->activeState = __SD_DEPTH13;
}

// Logic function of the simple state __sd_Depth13 in region regionregion41
static inline void regionregion41_state__sd_Depth13(Region41Context *context) {
    /* Immediate
     *   Transition 0:
     *   __sd_Depth13
     *    to
     *   __te_S12
     *   Effects: _request_route_local_i = _request_route_local_i + 1
     */
    context->iface->_request_route_local_i = context->iface->_request_route_local_i + 1;
    context->delayedEnabled = 0;
    context->activeState = __TE_S12;
}

// Logic function of the simple state __te_S12 in region regionregion41
static inline void regionregion41_state__te_S12(Region41Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S12
     *    to
     *   finalState42
     *   Effects: _request_route_local__Tterm = 1
     */
    context->iface->_request_route_local__Tterm = 1;
    context->delayedEnabled = 0;
    context->activeState = FINALSTATE42;
}

// Logic function of the simple state finalState42 in region regionregion41
static inline void regionregion41_statefinalState42(Region41Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}

// Logic function of the simple state _AC2 in region regionregion0
static inline void regionregion0_state_AC2(Region0Context *context) {
    if (context->iface->_request_route_local__Tterm) {
        /* Immediate
     *   Transition 0:
     *   _AC2
     *    to
     *   S41
     *   Trigger: context->iface->_request_route_local__Tterm
     */
        context->delayedEnabled = 0;
        context->activeState = S41;
    } else {
        /* Immediate
     *   Transition 1:
     *   _AC2
     *    to
     *   __te_S13
     */
        context->delayedEnabled = 0;
        context->activeState = __TE_S13;
    }
}

// Logic function of the simple state __te_S13 in region regionregion0
static inline void regionregion0_state__te_S13(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S13
     *    to
     *   __te_S14
     *   Effects: _taken_transitions[18] += 1
     */
    context->iface->_taken_transitions[18] += 1;
    context->delayedEnabled = 0;
    context->activeState = __TE_S14;
}

// Logic function of the simple state __te_S14 in region regionregion0
static inline void regionregion0_state__te_S14(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   __te_S14
     *    to
     *   __te_S15
     *   Effects: _taken_transitions[16] += 1
     */
    context->iface->_taken_transitions[16] += 1;
    context->delayedEnabled = 0;
    context->activeState = __TE_S15;
}

// Logic function of the simple state S41 in region regionregion0
static inline void regionregion0_stateS41(Region0Context *context) {
    if (context->iface->_request_route_local_i < context->iface->_request_route_local_points_count) {
        /* Immediate
     *   Transition 0:
     *   S41
     *    to
     *   __EA_Init
     *   Trigger: context->iface->_request_route_local_i < context->iface->_request_route_local_points_count
     */
        context->delayedEnabled = 0;
        context->activeState = __EA_INIT17;
    } else {
        /* Immediate
     *   Transition 1:
     *   S41
     *    to
     *   S52
     *   Effects: _request_route_local__src_signal_id_ = config_get_scalar_string_value("route", id, "source")
     */
        context->iface->_request_route_local__src_signal_id_ = config_get_scalar_string_value("route", context->iface->id, "source");
        context->delayedEnabled = 0;
        context->activeState = S52;
    }
}

// Logic function of the simple state S52 in region regionregion0
static inline void regionregion0_stateS52(Region0Context *context) {
    /* Immediate
     *   Transition 0:
     *   S52
     *    to
     *   __te_S13
     *   Effects: _request_route_local_success2 = track_state_set_value("signal", _request_route_local__src_signal_id_, "green")
     */
    context->iface->_request_route_local_success2 = track_state_set_value("signal", context->iface->_request_route_local__src_signal_id_, "green");
    context->delayedEnabled = 0;
    context->activeState = __TE_S13;
}

// Logic function of the simple state S63 in region regionregion0
static inline void regionregion0_stateS63(Region0Context *context) {
    if (context->iface->_request_route_local_i4 < context->iface->_request_route_local_count_conflict_routes) {
        /* Immediate
     *   Transition 0:
     *   S63
     *    to
     *   __EA_Init
     *   Trigger: context->iface->_request_route_local_i4 < context->iface->_request_route_local_count_conflict_routes
     */
        context->delayedEnabled = 0;
        context->activeState = __EA_INIT14;
    } else {
        /* Immediate
     *   Transition 1:
     *   S63
     *    to
     *   __te_S40
     *   Effects: is_grantable = _request_route_local_result2
     */
        context->iface->is_grantable = context->iface->_request_route_local_result2;
        context->delayedEnabled = 0;
        context->activeState = __TE_S40;
    }
}

// Logic function of the simple state S42 in region regionregion0
static inline void regionregion0_stateS42(Region0Context *context) {
    if (context->iface->_request_route_local_i3 < context->iface->count_routes) {
        /* Immediate
     *   Transition 0:
     *   S42
     *    to
     *   __EA_Init
     *   Trigger: context->iface->_request_route_local_i3 < context->iface->count_routes
     */
        context->delayedEnabled = 0;
        context->activeState = __EA_INIT13;
    } else {
        /* Immediate
     *   Transition 1:
     *   S42
     *    to
     *   __te_S35
     *   Effects: id = route_ids[_request_route_local_result1]
     */
        context->iface->id = context->iface->route_ids[context->iface->_request_route_local_result1];
        context->delayedEnabled = 0;
        context->activeState = __TE_S35;
    }
}

// Logic function of the simple state finalState43 in region regionregion0
static inline void regionregion0_statefinalState43(Region0Context *context) {
    // The thread becomes inactive after this state is done.
    context->threadStatus = TERMINATED;
}


/* The surrounding application should call tick() once per clock tick.
 * The interface inside the TickData struct should be used to communicate with the logic.
 * Set the inputs before you call tick() and read out the outputs afterwards.
 */
void tick(TickData *context) {
    if (!context->threadStatus) return;
    if (context->region0context._actrl16context.threadStatus == PAUSING) {
        context->region0context._actrl16context.threadStatus = READY;
        context->region0context._actrl16context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry13context._actrl17context.threadStatus == PAUSING) {
        context->region0context.__ea_entry13context._actrl17context.threadStatus = READY;
        context->region0context.__ea_entry13context._actrl17context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry13context.__ea_entry14context._actrl18context.threadStatus == PAUSING) {
        context->region0context.__ea_entry13context.__ea_entry14context._actrl18context.threadStatus = READY;
        context->region0context.__ea_entry13context.__ea_entry14context._actrl18context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry13context.__ea_entry14context.region4context.threadStatus == PAUSING) {
        context->region0context.__ea_entry13context.__ea_entry14context.region4context.threadStatus = READY;
        context->region0context.__ea_entry13context.__ea_entry14context.region4context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry13context.__ea_entry14context.threadStatus == PAUSING) {
        context->region0context.__ea_entry13context.__ea_entry14context.threadStatus = READY;
        context->region0context.__ea_entry13context.__ea_entry14context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry13context.threadStatus == PAUSING) {
        context->region0context.__ea_entry13context.threadStatus = READY;
        context->region0context.__ea_entry13context.delayedEnabled = 1;
    }
    if (context->region0context._actrl20context.threadStatus == PAUSING) {
        context->region0context._actrl20context.threadStatus = READY;
        context->region0context._actrl20context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry16context._actrl21context.threadStatus == PAUSING) {
        context->region0context.__ea_entry16context._actrl21context.threadStatus = READY;
        context->region0context.__ea_entry16context._actrl21context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry16context.__ea_entry17context._actrl22context.threadStatus == PAUSING) {
        context->region0context.__ea_entry16context.__ea_entry17context._actrl22context.threadStatus = READY;
        context->region0context.__ea_entry16context.__ea_entry17context._actrl22context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry16context.__ea_entry17context.region11context.threadStatus == PAUSING) {
        context->region0context.__ea_entry16context.__ea_entry17context.region11context.threadStatus = READY;
        context->region0context.__ea_entry16context.__ea_entry17context.region11context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry16context.__ea_entry17context.threadStatus == PAUSING) {
        context->region0context.__ea_entry16context.__ea_entry17context.threadStatus = READY;
        context->region0context.__ea_entry16context.__ea_entry17context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry16context.threadStatus == PAUSING) {
        context->region0context.__ea_entry16context.threadStatus = READY;
        context->region0context.__ea_entry16context.delayedEnabled = 1;
    }
    if (context->region0context._actrl4context.threadStatus == PAUSING) {
        context->region0context._actrl4context.threadStatus = READY;
        context->region0context._actrl4context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry2context._actrl5context.threadStatus == PAUSING) {
        context->region0context.__ea_entry2context._actrl5context.threadStatus = READY;
        context->region0context.__ea_entry2context._actrl5context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry2context.region17context.threadStatus == PAUSING) {
        context->region0context.__ea_entry2context.region17context.threadStatus = READY;
        context->region0context.__ea_entry2context.region17context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry2context._actrl6context.threadStatus == PAUSING) {
        context->region0context.__ea_entry2context._actrl6context.threadStatus = READY;
        context->region0context.__ea_entry2context._actrl6context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry2context.__ea_entry4context._actrl7context.threadStatus == PAUSING) {
        context->region0context.__ea_entry2context.__ea_entry4context._actrl7context.threadStatus = READY;
        context->region0context.__ea_entry2context.__ea_entry4context._actrl7context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context._actrl8context.threadStatus == PAUSING) {
        context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context._actrl8context.threadStatus = READY;
        context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context._actrl8context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context.__ea_entry6context._actrl9context.threadStatus == PAUSING) {
        context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context.__ea_entry6context._actrl9context.threadStatus = READY;
        context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context.__ea_entry6context._actrl9context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context.__ea_entry6context.region23context.threadStatus == PAUSING) {
        context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context.__ea_entry6context.region23context.threadStatus = READY;
        context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context.__ea_entry6context.region23context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context.__ea_entry6context.threadStatus == PAUSING) {
        context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context.__ea_entry6context.threadStatus = READY;
        context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context.__ea_entry6context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context.threadStatus == PAUSING) {
        context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context.threadStatus = READY;
        context->region0context.__ea_entry2context.__ea_entry4context.__ea_entry5context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry2context.__ea_entry4context.threadStatus == PAUSING) {
        context->region0context.__ea_entry2context.__ea_entry4context.threadStatus = READY;
        context->region0context.__ea_entry2context.__ea_entry4context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry2context.threadStatus == PAUSING) {
        context->region0context.__ea_entry2context.threadStatus = READY;
        context->region0context.__ea_entry2context.delayedEnabled = 1;
    }
    if (context->region0context._actrl10context.threadStatus == PAUSING) {
        context->region0context._actrl10context.threadStatus = READY;
        context->region0context._actrl10context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry8context._actrl11context.threadStatus == PAUSING) {
        context->region0context.__ea_entry8context._actrl11context.threadStatus = READY;
        context->region0context.__ea_entry8context._actrl11context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry8context.__ea_entry9context._actrl12context.threadStatus == PAUSING) {
        context->region0context.__ea_entry8context.__ea_entry9context._actrl12context.threadStatus = READY;
        context->region0context.__ea_entry8context.__ea_entry9context._actrl12context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context._actrl13context.threadStatus == PAUSING) {
        context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context._actrl13context.threadStatus = READY;
        context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context._actrl13context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context.__ea_entry11context._actrl14context.threadStatus == PAUSING) {
        context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context.__ea_entry11context._actrl14context.threadStatus = READY;
        context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context.__ea_entry11context._actrl14context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context.__ea_entry11context.region34context.threadStatus == PAUSING) {
        context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context.__ea_entry11context.region34context.threadStatus = READY;
        context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context.__ea_entry11context.region34context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context.__ea_entry11context.threadStatus == PAUSING) {
        context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context.__ea_entry11context.threadStatus = READY;
        context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context.__ea_entry11context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context.threadStatus == PAUSING) {
        context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context.threadStatus = READY;
        context->region0context.__ea_entry8context.__ea_entry9context.__ea_entry10context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry8context.__ea_entry9context.threadStatus == PAUSING) {
        context->region0context.__ea_entry8context.__ea_entry9context.threadStatus = READY;
        context->region0context.__ea_entry8context.__ea_entry9context.delayedEnabled = 1;
    }
    if (context->region0context.__ea_entry8context.threadStatus == PAUSING) {
        context->region0context.__ea_entry8context.threadStatus = READY;
        context->region0context.__ea_entry8context.delayedEnabled = 1;
    }
    if (context->region0context._actrl2context.threadStatus == PAUSING) {
        context->region0context._actrl2context.threadStatus = READY;
        context->region0context._actrl2context.delayedEnabled = 1;
    }
    if (context->region0context.region41context.threadStatus == PAUSING) {
        context->region0context.region41context.threadStatus = READY;
        context->region0context.region41context.delayedEnabled = 1;
    }
    if (context->region0context.threadStatus == PAUSING) {
        context->region0context.threadStatus = READY;
        context->region0context.delayedEnabled = 1;
    }

    do {
        staterequest_routerunning(context);
    } while (context->region0context.threadStatus == READY);

}
