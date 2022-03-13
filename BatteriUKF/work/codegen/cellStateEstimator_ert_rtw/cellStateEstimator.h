/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: cellStateEstimator.h
 *
 * Code generated for Simulink model 'cellStateEstimator'.
 *
 * Model version                  : 1.61
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Mar 13 19:14:07 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
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
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T P[4];                         /* '<S2>/DataStoreMemory - P' */
  real_T x[2];                         /* '<S2>/DataStoreMemory - x' */
} DW_cellStateEstimator_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T MeasuredOCV;                  /* '<Root>/Voltage' */
  real_T Measuredcurrent;              /* '<Root>/Current' */
  real_T Measuredtemperature;          /* '<Root>/Temperature' */
  real_T CurrentCounting;              /* '<Root>/Current Counting' */
  real_T Initialcapacity;              /* '<Root>/Initial Capacity' */
} ExtU_cellStateEstimator_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T SOC;                          /* '<Root>/SOC' */
  real_T Capacity;                     /* '<Root>/Capacity' */
} ExtY_cellStateEstimator_T;

/* Real-time Model Data Structure */
struct tag_RTM_cellStateEstimator_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_cellStateEstimator_T cellStateEstimator_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_cellStateEstimator_T cellStateEstimator_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_cellStateEstimator_T cellStateEstimator_Y;

/* Model entry point functions */
extern void cellStateEstimator_initialize(void);
extern void cellStateEstimator_step(void);
extern void cellStateEstimator_terminate(void);

/* Real-time Model object */
extern RT_MODEL_cellStateEstimator_T *const cellStateEstimator_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S6>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S2>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S2>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S2>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S2>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S2>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S2>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
 * Block '<S2>/DataTypeConversion_uState' : Eliminate redundant data type conversion
 * Block '<S2>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 */

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
 * '<S11>'  : 'Main/cellStateEstimator/f/Cp'
 * '<S12>'  : 'Main/cellStateEstimator/f/Rp'
 * '<S13>'  : 'Main/cellStateEstimator/f/Rs'
 * '<S14>'  : 'Main/cellStateEstimator/f/h'
 * '<S15>'  : 'Main/cellStateEstimator/h/Rs'
 * '<S16>'  : 'Main/cellStateEstimator/h/ocv'
 */
#endif                                 /* RTW_HEADER_cellStateEstimator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
