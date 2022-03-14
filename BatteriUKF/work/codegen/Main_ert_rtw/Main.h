/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Main.h
 *
 * Code generated for Simulink model 'Main'.
 *
 * Model version                  : 1.71
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Mar 14 17:16:16 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Main_h_
#define RTW_HEADER_Main_h_
#include <math.h>
#include <string.h>
#ifndef Main_COMMON_INCLUDES_
#define Main_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "nesl_rtw_rtp.h"
#include "Main_45a0674_1_gateway.h"
#include "nesl_rtw.h"
#endif                                 /* Main_COMMON_INCLUDES_ */

#include "Main_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals (default storage) */
typedef struct {
  real_T INPUT_1_1_1[4];               /* '<S11>/INPUT_1_1_1' */
  real_T RTP_1;                        /* '<S4>/RTP_1' */
  real_T STATE_1[16];                  /* '<S11>/STATE_1' */
  real_T OUTPUT_1_0[2];                /* '<S11>/OUTPUT_1_0' */
} B;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T INPUT_1_1_1_Discrete[2];      /* '<S11>/INPUT_1_1_1' */
  real_T STATE_1_Discrete[10];         /* '<S11>/STATE_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S11>/OUTPUT_1_0' */
  real_T P_m[4];                       /* '<S12>/DataStoreMemory - P' */
  real_T x[2];                         /* '<S12>/DataStoreMemory - x' */
  void* RTP_1_RtpManager;              /* '<S4>/RTP_1' */
  void* STATE_1_Simulator;             /* '<S11>/STATE_1' */
  void* STATE_1_SimData;               /* '<S11>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S11>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S11>/STATE_1' */
  void* STATE_1_TsIndex;               /* '<S11>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S11>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S11>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S11>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S11>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsIndex;            /* '<S11>/OUTPUT_1_0' */
  int_T STATE_1_Modes[6];              /* '<S11>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S11>/OUTPUT_1_0' */
  boolean_T RTP_1_SetParametersNeeded; /* '<S4>/RTP_1' */
  boolean_T STATE_1_FirstOutput;       /* '<S11>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S11>/OUTPUT_1_0' */
} DW;

/* Real-time Model Data Structure */
struct tag_RTM {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block signals (default storage) */
extern B rtB;

/* Block states (default storage) */
extern DW rtDW;

/* Model entry point functions */
extern void Main_initialize(void);
extern void Main_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * '<S1>'   : 'Main/Sensing current'
 * '<S2>'   : 'Main/Sensing voltage'
 * '<S3>'   : 'Main/Simulink-PS Converter'
 * '<S4>'   : 'Main/Solver Configuration1'
 * '<S5>'   : 'Main/cellStateEstimator'
 * '<S6>'   : 'Main/Sensing current/PS-Simulink Converter1'
 * '<S7>'   : 'Main/Sensing current/PS-Simulink Converter1/EVAL_KEY'
 * '<S8>'   : 'Main/Sensing voltage/PS-Simulink Converter2'
 * '<S9>'   : 'Main/Sensing voltage/PS-Simulink Converter2/EVAL_KEY'
 * '<S10>'  : 'Main/Simulink-PS Converter/EVAL_KEY'
 * '<S11>'  : 'Main/Solver Configuration1/EVAL_KEY'
 * '<S12>'  : 'Main/cellStateEstimator/Unscented Kalman Filter'
 * '<S13>'  : 'Main/cellStateEstimator/f'
 * '<S14>'  : 'Main/cellStateEstimator/h'
 * '<S15>'  : 'Main/cellStateEstimator/Unscented Kalman Filter/Correct1'
 * '<S16>'  : 'Main/cellStateEstimator/Unscented Kalman Filter/Predict'
 * '<S17>'  : 'Main/cellStateEstimator/Unscented Kalman Filter/Subsystem'
 * '<S18>'  : 'Main/cellStateEstimator/Unscented Kalman Filter/Correct1/Correct'
 * '<S19>'  : 'Main/cellStateEstimator/Unscented Kalman Filter/Predict/Predict'
 * '<S20>'  : 'Main/cellStateEstimator/Unscented Kalman Filter/Subsystem/MATLAB Function'
 * '<S21>'  : 'Main/cellStateEstimator/f/h'
 */
#endif                                 /* RTW_HEADER_Main_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
