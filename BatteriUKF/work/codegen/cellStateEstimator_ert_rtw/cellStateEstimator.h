/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: cellStateEstimator.h
 *
 * Code generated for Simulink model 'cellStateEstimator'.
 *
 * Model version                  : 1.74
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Mar 14 20:45:31 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_cellStateEstimator_h_
#define RTW_HEADER_cellStateEstimator_h_
#include <math.h>
#ifndef cellStateEstimator_COMMON_INCLUDES_
#define cellStateEstimator_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* cellStateEstimator_COMMON_INCLUDES_ */

#include "cellStateEstimator_types.h"

/* Macros for accessing real-time model data structure */

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T P_m[4];                       /* '<S2>/DataStoreMemory - P' */
  real_T x[2];                         /* '<S2>/DataStoreMemory - x' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T MeasuredOCV;                  /* '<Root>/Voltage' */
  real_T Measuredcurrent;              /* '<Root>/Current' */
  real_T Measuredtemperature;          /* '<Root>/Temperature' */
  real_T Initialcapacity;              /* '<Root>/Initial Capacity' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T SOC;                          /* '<Root>/SOC' */
  real_T Capacity;                     /* '<Root>/Capacity' */
} ExtY;

/* Block states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void cellStateEstimator_initialize(void);
extern void cellStateEstimator_step(void);

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
 * hilite_system('Main/cellStateEstimator')    - opens subsystem Main/cellStateEstimator
 * hilite_system('Main/cellStateEstimator/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Main'
 * '<S1>'   : 'Main/cellStateEstimator'
 * '<S2>'   : 'Main/cellStateEstimator/Unscented Kalman Filter'
 * '<S3>'   : 'Main/cellStateEstimator/f'
 * '<S4>'   : 'Main/cellStateEstimator/h'
 * '<S5>'   : 'Main/cellStateEstimator/Unscented Kalman Filter/Correct1'
 * '<S6>'   : 'Main/cellStateEstimator/Unscented Kalman Filter/Predict'
 * '<S7>'   : 'Main/cellStateEstimator/Unscented Kalman Filter/Subsystem'
 * '<S8>'   : 'Main/cellStateEstimator/Unscented Kalman Filter/Correct1/Correct'
 * '<S9>'   : 'Main/cellStateEstimator/Unscented Kalman Filter/Predict/Predict'
 * '<S10>'  : 'Main/cellStateEstimator/Unscented Kalman Filter/Subsystem/MATLAB Function'
 * '<S11>'  : 'Main/cellStateEstimator/f/h'
 */
#endif                                 /* RTW_HEADER_cellStateEstimator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
