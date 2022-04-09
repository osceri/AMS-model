/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem.h
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.699
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Apr  7 22:48:14 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Subsystem_h_
#define RTW_HEADER_Subsystem_h_
#include <string.h>
#ifndef Subsystem_COMMON_INCLUDES_
#define Subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "nesl_rtw_rtp.h"
#include "Subsystem_8f6c35c5_1_gateway.h"
#include "nesl_rtw.h"
#endif                                 /* Subsystem_COMMON_INCLUDES_ */

#include "Subsystem_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals (default storage) */
typedef struct {
  real_T INPUT_1_1_1[4];               /* '<S11>/INPUT_1_1_1' */
  real_T RTP_1;                        /* '<S6>/RTP_1' */
  real_T STATE_1[16];                  /* '<S11>/STATE_1' */
} B;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T INPUT_1_1_1_Discrete[2];      /* '<S11>/INPUT_1_1_1' */
  real_T STATE_1_Discrete[10];         /* '<S11>/STATE_1' */
  real_T OUTPUT_1_1_Discrete;          /* '<S11>/OUTPUT_1_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S11>/OUTPUT_1_0' */
  void* RTP_1_RtpManager;              /* '<S6>/RTP_1' */
  void* STATE_1_Simulator;             /* '<S11>/STATE_1' */
  void* STATE_1_SimData;               /* '<S11>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S11>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S11>/STATE_1' */
  void* STATE_1_TsIndex;               /* '<S11>/STATE_1' */
  void* OUTPUT_1_1_Simulator;          /* '<S11>/OUTPUT_1_1' */
  void* OUTPUT_1_1_SimData;            /* '<S11>/OUTPUT_1_1' */
  void* OUTPUT_1_1_DiagMgr;            /* '<S11>/OUTPUT_1_1' */
  void* OUTPUT_1_1_ZcLogger;           /* '<S11>/OUTPUT_1_1' */
  void* OUTPUT_1_1_TsIndex;            /* '<S11>/OUTPUT_1_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S11>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S11>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S11>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S11>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsIndex;            /* '<S11>/OUTPUT_1_0' */
  int_T STATE_1_Modes[6];              /* '<S11>/STATE_1' */
  int_T OUTPUT_1_1_Modes;              /* '<S11>/OUTPUT_1_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S11>/OUTPUT_1_0' */
  boolean_T RTP_1_SetParametersNeeded; /* '<S6>/RTP_1' */
  boolean_T STATE_1_FirstOutput;       /* '<S11>/STATE_1' */
  boolean_T OUTPUT_1_1_FirstOutput;    /* '<S11>/OUTPUT_1_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S11>/OUTPUT_1_0' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T CurrentDraw;                  /* '<Root>/Current Draw' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T SOC;                          /* '<Root>/SOC' */
  real_T Voltage;                      /* '<Root>/Voltage' */
  real_T Current;                      /* '<Root>/Current' */
} ExtY;

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

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Subsystem_initialize(void);
extern void Subsystem_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * hilite_system('Main/Subsystem')    - opens subsystem Main/Subsystem
 * hilite_system('Main/Subsystem/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Main'
 * '<S1>'   : 'Main/Subsystem'
 * '<S2>'   : 'Main/Subsystem/PS-Simulink Converter1'
 * '<S3>'   : 'Main/Subsystem/PS-Simulink Converter2'
 * '<S4>'   : 'Main/Subsystem/PS-Simulink Converter3'
 * '<S5>'   : 'Main/Subsystem/Simulink-PS Converter'
 * '<S6>'   : 'Main/Subsystem/Solver Configuration1'
 * '<S7>'   : 'Main/Subsystem/PS-Simulink Converter1/EVAL_KEY'
 * '<S8>'   : 'Main/Subsystem/PS-Simulink Converter2/EVAL_KEY'
 * '<S9>'   : 'Main/Subsystem/PS-Simulink Converter3/EVAL_KEY'
 * '<S10>'  : 'Main/Subsystem/Simulink-PS Converter/EVAL_KEY'
 * '<S11>'  : 'Main/Subsystem/Solver Configuration1/EVAL_KEY'
 */
#endif                                 /* RTW_HEADER_Subsystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
