/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem.h
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.562
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Mar 20 23:25:26 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Subsystem_h_
#define RTW_HEADER_Subsystem_h_
#include <math.h>
#include <string.h>
#ifndef Subsystem_COMMON_INCLUDES_
#define Subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Subsystem_COMMON_INCLUDES_ */

#include "Subsystem_types.h"

/* Macros for accessing real-time model data structure */

/* Block states (default storage) for system '<Root>' */
typedef struct {
  AF_state s;                          /* '<S1>/Data Store Memory' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: s0
   * Referenced by: '<S1>/Data Store Memory'
   */
  AF_state DataStoreMemory_InitialValue;
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Measuredterminalvoltage;      /* '<Root>/y' */
  real_T Measuredcurrent;              /* '<Root>/u' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T xhat[2];                      /* '<Root>/xhat' */
} ExtY;

/* Block states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void Subsystem_initialize(void);
extern void Subsystem_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Main/cellStateEstimator/Subsystem')    - opens subsystem Main/cellStateEstimator/Subsystem
 * hilite_system('Main/cellStateEstimator/Subsystem/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Main/cellStateEstimator'
 * '<S1>'   : 'Main/cellStateEstimator/Subsystem'
 * '<S2>'   : 'Main/cellStateEstimator/Subsystem/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_Subsystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
