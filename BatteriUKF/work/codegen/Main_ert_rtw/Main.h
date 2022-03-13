/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Main.h
 *
 * Code generated for Simulink model 'Main'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Mar 13 13:17:04 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Main_h_
#define RTW_HEADER_Main_h_
#include <math.h>
#ifndef Main_COMMON_INCLUDES_
#define Main_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Main_COMMON_INCLUDES_ */

#include "Main_types.h"
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
  real_T P[4];                         /* '<S1>/DataStoreMemory - P' */
  real_T x[2];                         /* '<S1>/DataStoreMemory - x' */
  real_T Memory_PreviousInput[2];      /* '<S2>/Memory' */
} DW_Main_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T MeasuredOCV;                  /* '<Root>/Voltage' */
  real_T Measuredcurrent;              /* '<Root>/Current' */
  real_T Measuredcurrent_p;            /* '<Root>/Temperature' */
  real_T Currentcounting;              /* '<Root>/Current counting' */
} ExtU_Main_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T SOC;                          /* '<Root>/SOC' */
  real_T Capacity;                     /* '<Root>/Capacity' */
} ExtY_Main_T;

/* Real-time Model Data Structure */
struct tag_RTM_Main_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Main_T Main_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Main_T Main_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Main_T Main_Y;

/* Model entry point functions */
extern void Main_initialize(void);
extern void Main_step(void);
extern void Main_terminate(void);
extern void Main_batteryStateFcn(const real_T rtu_x[2], real_T rty_x_next[2]);
extern real_T Main_batteryMeasurementFcn(const real_T rtu_x[2]);

/* Real-time Model object */
extern RT_MODEL_Main_T *const Main_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S5>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S1>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S1>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S1>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S1>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S1>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S1>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
 * Block '<S1>/DataTypeConversion_uState' : Eliminate redundant data type conversion
 * Block '<S1>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Main'
 * '<S1>'   : 'Main/Unscented Kalman Filter'
 * '<S2>'   : 'Main/f'
 * '<S3>'   : 'Main/h'
 * '<S4>'   : 'Main/Unscented Kalman Filter/Correct1'
 * '<S5>'   : 'Main/Unscented Kalman Filter/Predict'
 * '<S6>'   : 'Main/Unscented Kalman Filter/Subsystem'
 * '<S7>'   : 'Main/Unscented Kalman Filter/Correct1/Correct'
 * '<S8>'   : 'Main/Unscented Kalman Filter/Predict/Predict'
 * '<S9>'   : 'Main/Unscented Kalman Filter/Subsystem/MATLAB Function'
 * '<S10>'  : 'Main/f/Cp'
 * '<S11>'  : 'Main/f/Rp'
 * '<S12>'  : 'Main/f/Rs'
 * '<S13>'  : 'Main/f/h'
 * '<S14>'  : 'Main/h/Rs'
 * '<S15>'  : 'Main/h/ocv'
 */
#endif                                 /* RTW_HEADER_Main_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
