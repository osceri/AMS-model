/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AEKF.h
 *
 * Code generated for Simulink model 'AEKF'.
 *
 * Model version                  : 1.563
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Mar 20 23:41:42 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AEKF_h_
#define RTW_HEADER_AEKF_h_
#ifndef AEKF_COMMON_INCLUDES_
#define AEKF_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AEKF_COMMON_INCLUDES_ */

#include "AEKF_types.h"

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
extern void AEKF_initialize(void);
extern void AEKF_step(void);

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
 * hilite_system('Main/cellStateEstimator/AEKF')    - opens subsystem Main/cellStateEstimator/AEKF
 * hilite_system('Main/cellStateEstimator/AEKF/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Main/cellStateEstimator'
 * '<S1>'   : 'Main/cellStateEstimator/AEKF'
 * '<S2>'   : 'Main/cellStateEstimator/AEKF/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_AEKF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
