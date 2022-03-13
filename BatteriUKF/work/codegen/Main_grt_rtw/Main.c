/*
 * Main.c
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

#include "Main.h"
#include "Main_private.h"
#include "UTMeanCovSqrt_VKhUvvBU.h"
#include "cholUpdateFactor_2sWnptMU.h"
#include "qr_IudxEnvM.h"
#include "trisolve_r4j0Li0a.h"

/* Block signals (default storage) */
B_Main_T Main_B;

/* Block states (default storage) */
DW_Main_T Main_DW;

/* Real-time model */
static RT_MODEL_Main_T Main_M_;
RT_MODEL_Main_T *const Main_M = &Main_M_;

/* Output and update for Simulink Function: '<Root>/f' */
void Main_batteryStateFcn(real_T rtu_u, real_T *rty_y)
{
  /* SignalConversion generated from: '<S2>/y' incorporates:
   *  SignalConversion generated from: '<S2>/u'
   */
  *rty_y = rtu_u;
}

/* Output and update for Simulink Function: '<Root>/h' */
void Main_batteryMeasurementFcn(real_T rtu_u, real_T *rty_y)
{
  /* SignalConversion generated from: '<S3>/y' incorporates:
   *  SignalConversion generated from: '<S3>/u'
   */
  *rty_y = rtu_u;
}

/* Model step function */
void Main_step(void)
{
  real_T X2[2];
  real_T Y2[2];
  real_T a__1[2];
  real_T tmp[2];
  real_T unusedExpr_0[2];
  real_T K;
  real_T P;
  real_T X2_0;
  real_T X2_1;
  real_T Y2_0;
  real_T rtb_DataStoreRead;
  real_T rtb_P_g;
  real_T tempY;
  real_T tempY_0;
  real_T unusedExpr;
  real_T yMeas;
  static const real_T Wmean[2] = { 1.0, -0.5000005000005 };

  /* Sin: '<Root>/Sine Wave' */
  Main_B.SineWave = sin(Main_P.SineWave_Freq * Main_M->Timing.t[0] +
                        Main_P.SineWave_Phase) * Main_P.SineWave_Amp +
    Main_P.SineWave_Bias;

  /* Outputs for Enabled SubSystem: '<S1>/Correct1' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Constant: '<S1>/Enable1' */
  if (Main_P.Enable1_Value) {
    /* DataStoreRead: '<S4>/Data Store ReadP' */
    rtb_P_g = Main_DW.P;

    /* MATLAB Function: '<S4>/Correct' incorporates:
     *  Constant: '<S1>/R1'
     *  DataStoreRead: '<S4>/Data Store ReadP'
     *  DataStoreRead: '<S4>/Data Store ReadX'
     *  DataTypeConversion: '<S1>/DataTypeConversion_y1'
     */
    rtb_DataStoreRead = Main_DW.x;
    yMeas = Main_B.SineWave;
    tmp[1] = Main_P.R1_Value;
    P = Main_DW.P;
    Main_batteryMeasurementFcn(Main_DW.x, &K);
    P *= 0.001;
    X2_1 = P + rtb_DataStoreRead;
    X2_0 = -P;
    Main_batteryMeasurementFcn(X2_1, &tempY);
    Y2[0] = tempY;
    Main_batteryMeasurementFcn(-P + rtb_DataStoreRead, &tempY);
    Y2[1] = tempY;
    Main_batteryMeasurementFcn(rtb_DataStoreRead, &tempY);
    P = tempY;
    P = ((Y2[0] * -0.5000005000005 + P) + Y2[1] * -0.5000005000005) * -999999.0;
    Y2_0 = Y2[0] - P;
    X2[0] = 0.70710713474020326 * Y2_0;
    Y2[0] = Y2_0;
    Y2_0 = Y2[1] - P;
    X2[1] = 0.70710713474020326 * Y2_0;
    qr_IudxEnvM(X2, a__1, &K);
    cholUpdateFactor_2sWnptMU(&K, tempY - P);
    tmp[0] = 999.999499999875 * K;
    qr_IudxEnvM(tmp, a__1, &tempY);
    K = (((X2_0 + rtb_DataStoreRead) - rtb_DataStoreRead) * Y2_0 + (X2_1 -
          rtb_DataStoreRead) * Y2[0]) * 500000.0;
    trisolve_r4j0Li0a(tempY, &K);
    trisolve_r4j0Li0a(tempY, &K);
    cholUpdateFactor_2sWnptMU(&rtb_P_g, K * tempY);

    /* DataStoreWrite: '<S4>/Data Store WriteP' */
    Main_DW.P = rtb_P_g;

    /* DataStoreWrite: '<S4>/Data Store WriteX' incorporates:
     *  MATLAB Function: '<S4>/Correct'
     */
    Main_DW.x = (yMeas - P) * K + rtb_DataStoreRead;
  }

  /* End of Constant: '<S1>/Enable1' */
  /* End of Outputs for SubSystem: '<S1>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S1>/Subsystem' */
  /* DataStoreRead: '<S6>/Data Store Read' */
  rtb_DataStoreRead = Main_DW.x;

  /* End of Outputs for SubSystem: '<S1>/Subsystem' */
  /* Outputs for Atomic SubSystem: '<S1>/Predict' */
  /* MATLAB Function: '<S5>/Predict' incorporates:
   *  Constant: '<S1>/Q'
   *  DataStoreRead: '<S5>/Data Store ReadP'
   *  DataStoreRead: '<S5>/Data Store ReadX'
   */
  rtb_DataStoreRead = Main_DW.x;
  unusedExpr_0[1] = Main_P.Q_Value;
  P = Main_DW.P;
  Main_batteryStateFcn(Main_DW.x, &unusedExpr);
  P *= 0.001;
  X2[0] = P + rtb_DataStoreRead;
  X2[1] = -P + rtb_DataStoreRead;
  Main_batteryStateFcn(P + rtb_DataStoreRead, &tempY_0);
  Y2[0] = tempY_0;
  Main_batteryStateFcn(-P + rtb_DataStoreRead, &tempY_0);
  Y2[1] = tempY_0;
  Main_batteryStateFcn(rtb_DataStoreRead, &tempY_0);
  tmp[0] = 0.999996999998;
  tmp[1] = -0.5000005000005;

  /* DataStoreWrite: '<S5>/Data Store WriteX' incorporates:
   *  MATLAB Function: '<S5>/Predict'
   */
  UTMeanCovSqrt_VKhUvvBU(Wmean, tmp, -999999.0, tempY_0, Y2, rtb_DataStoreRead,
    X2, &Main_DW.x, &unusedExpr, &yMeas);

  /* MATLAB Function: '<S5>/Predict' */
  unusedExpr_0[0] = unusedExpr;

  /* DataStoreWrite: '<S5>/Data Store WriteP' incorporates:
   *  MATLAB Function: '<S5>/Predict'
   */
  qr_IudxEnvM(unusedExpr_0, X2, &Main_DW.P);

  /* End of Outputs for SubSystem: '<S1>/Predict' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(Main_M->rtwLogInfo, (Main_M->Timing.t));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Main_M)!=-1) &&
        !((rtmGetTFinal(Main_M)-Main_M->Timing.t[0]) > Main_M->Timing.t[0] *
          (DBL_EPSILON))) {
      rtmSetErrorStatus(Main_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Main_M->Timing.clockTick0)) {
    ++Main_M->Timing.clockTickH0;
  }

  Main_M->Timing.t[0] = Main_M->Timing.clockTick0 * Main_M->Timing.stepSize0 +
    Main_M->Timing.clockTickH0 * Main_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    Main_M->Timing.clockTick1++;
    if (!Main_M->Timing.clockTick1) {
      Main_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void Main_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Main_M, 0,
                sizeof(RT_MODEL_Main_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Main_M->solverInfo, &Main_M->Timing.simTimeStep);
    rtsiSetTPtr(&Main_M->solverInfo, &rtmGetTPtr(Main_M));
    rtsiSetStepSizePtr(&Main_M->solverInfo, &Main_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Main_M->solverInfo, (&rtmGetErrorStatus(Main_M)));
    rtsiSetRTModelPtr(&Main_M->solverInfo, Main_M);
  }

  rtsiSetSimTimeStep(&Main_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Main_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Main_M, &Main_M->Timing.tArray[0]);
  rtmSetTFinal(Main_M, 10.0);
  Main_M->Timing.stepSize0 = 1.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Main_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Main_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Main_M->rtwLogInfo, (NULL));
    rtliSetLogT(Main_M->rtwLogInfo, "tout");
    rtliSetLogX(Main_M->rtwLogInfo, "");
    rtliSetLogXFinal(Main_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Main_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Main_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Main_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Main_M->rtwLogInfo, 1);
    rtliSetLogY(Main_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Main_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Main_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Main_B), 0,
                sizeof(B_Main_T));

  /* states (dwork) */
  (void) memset((void *)&Main_DW, 0,
                sizeof(DW_Main_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Main_M->rtwLogInfo, 0.0, rtmGetTFinal(Main_M),
    Main_M->Timing.stepSize0, (&rtmGetErrorStatus(Main_M)));

  /* Start for DataStoreMemory: '<S1>/DataStoreMemory - P' */
  Main_DW.P = Main_P.DataStoreMemoryP_InitialValue;

  /* Start for DataStoreMemory: '<S1>/DataStoreMemory - x' */
  Main_DW.x = Main_P.DataStoreMemoryx_InitialValue;
}

/* Model terminate function */
void Main_terminate(void)
{
  /* (no terminate code required) */
}
