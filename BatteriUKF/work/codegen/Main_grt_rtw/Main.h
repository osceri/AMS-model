/*
 * Main.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Main".
 *
 * Model version              : 1.9
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Sat Mar 12 20:14:27 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Main_h_
#define RTW_HEADER_Main_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Main_COMMON_INCLUDES_
#define Main_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Main_COMMON_INCLUDES_ */

#include "Main_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T SineWave;                     /* '<Root>/Sine Wave' */
} B_Main_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T P;                            /* '<S1>/DataStoreMemory - P' */
  real_T x;                            /* '<S1>/DataStoreMemory - x' */
} DW_Main_T;

/* Parameters (default storage) */
struct P_Main_T_ {
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T R1_Value;                     /* Expression: p.R{1}
                                        * Referenced by: '<S1>/R1'
                                        */
  real_T MeasurementFcn1Inputs_Value;  /* Expression: 0
                                        * Referenced by: '<S1>/MeasurementFcn1Inputs'
                                        */
  real_T Q_Value;                      /* Expression: p.Q
                                        * Referenced by: '<S1>/Q'
                                        */
  real_T StateTransitionFcnInputs_Value;/* Expression: 0
                                         * Referenced by: '<S1>/StateTransitionFcnInputs'
                                         */
  real_T DataStoreMemoryP_InitialValue;/* Expression: p.InitialCovariance
                                        * Referenced by: '<S1>/DataStoreMemory - P'
                                        */
  real_T DataStoreMemoryx_InitialValue;/* Expression: p.InitialState
                                        * Referenced by: '<S1>/DataStoreMemory - x'
                                        */
  boolean_T yBlockOrdering_Y0;         /* Computed Parameter: yBlockOrdering_Y0
                                        * Referenced by: '<S4>/yBlockOrdering'
                                        */
  boolean_T BlockOrdering_Value;       /* Expression: true()
                                        * Referenced by: '<S1>/BlockOrdering'
                                        */
  boolean_T Enable1_Value;             /* Expression: true()
                                        * Referenced by: '<S1>/Enable1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Main_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Main_T Main_P;

/* Block signals (default storage) */
extern B_Main_T Main_B;

/* Block states (default storage) */
extern DW_Main_T Main_DW;

/* Model entry point functions */
extern void Main_initialize(void);
extern void Main_step(void);
extern void Main_terminate(void);
extern void Main_batteryStateFcn(real_T rtu_u, real_T *rty_y);
extern void Main_batteryMeasurementFcn(real_T rtu_u, real_T *rty_y);

/* Real-time Model object */
extern RT_MODEL_Main_T *const Main_M;

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
 */
#endif                                 /* RTW_HEADER_Main_h_ */
