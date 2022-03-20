/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Main.c
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

#include "Main.h"
#include "Main_private.h"
#include "UTMeanCovSqrt_14Tzk8eT.h"
#include "UTMeanCovSqrt_nmwxOcMg.h"
#include "look1_binlxpw.h"
#include "qr_4aCbWkNT.h"
#include "qr_KQupoFeg.h"
#include "rotate_YgpoDwi7.h"
#include "rt_hypotd.h"
#include "svd_ITQaouod.h"
#include "trisolve_3WRXGFtF.h"
#include "xnrm2_hoYimUM0.h"

/* Block signals (default storage) */
B rtB;

/* Block states (default storage) */
DW rtDW;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static void UKFCorrectorAdditive_getPredict(real_T Rs, const real_T X1[2], const
  real_T S[4], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[2], real_T *Sy);

/* Output and update for Simulink Function: '<S5>/f' */
void batteryStateFcn(const real_T rtu_x[2], real_T rty_x_next[2])
{
  real_T tmp;

  /* MATLAB Function: '<S13>/h' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S13>/Constant'
   *  Lookup_n-D: '<S13>/1-D Lookup Table1'
   *  Lookup_n-D: '<S13>/1-D Lookup Table2'
   *  SignalConversion generated from: '<S13>/Capacity'
   *  SignalConversion generated from: '<S13>/Current'
   *  SignalConversion generated from: '<S13>/u'
   *  SignalConversion generated from: '<S13>/y'
   */
  rty_x_next[0] = rtu_x[0] - 0.2 * rtB.OUTPUT_1_0[0] / 16632.0;
  tmp = exp(-0.2 / look1_binlxpw(rtu_x[0], rtCP_uDLookupTable1_bp01Data,
             rtCP_uDLookupTable1_tableData, 32U));
  rty_x_next[1] = tmp * rtu_x[1] - (1.0 - tmp) * look1_binlxpw(rtu_x[0],
    rtCP_uDLookupTable2_bp01Data, rtCP_uDLookupTable2_tableData, 32U) *
    rtB.OUTPUT_1_0[0];
}

/* Output and update for Simulink Function: '<S5>/h' */
void batteryMeasurementFcn(const real_T rtu_x[2], real_T *rty_y)
{
  /* SignalConversion generated from: '<S14>/y' incorporates:
   *  Lookup_n-D: '<S14>/1-D Lookup Table'
   *  Lookup_n-D: '<S14>/1-D Lookup Table1'
   *  Product: '<S14>/Product'
   *  SignalConversion generated from: '<S14>/Current'
   *  SignalConversion generated from: '<S14>/x'
   *  Sum: '<S14>/Add'
   */
  *rty_y = (look1_binlxpw(rtu_x[0], rtCP_uDLookupTable1_bp01Data_l,
             rtCP_uDLookupTable1_tableData_j, 32U) * rtB.OUTPUT_1_0[0] +
            look1_binlxpw(rtu_x[0], rtCP_uDLookupTable_bp01Data_e,
             rtCP_uDLookupTable_tableData_g, 32U)) - rtu_x[1];
}

/* Function for MATLAB Function: '<S15>/Correct' */
static void UKFCorrectorAdditive_getPredict(real_T Rs, const real_T X1[2], const
  real_T S[4], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[2], real_T *Sy)
{
  real_T X2[8];
  real_T Y2[4];
  real_T Wcov[2];
  real_T Wmean[2];
  real_T Wcov_0;
  real_T Wmean_0;
  real_T tempY;
  real_T xnorm;
  int32_T X2_tmp;
  int32_T knt;
  xnorm = alpha * alpha;
  tempY = xnorm * (kappa + 2.0);
  Wmean[0] = 1.0 - 2.0 / tempY;
  Wmean[1] = 1.0 / (2.0 * tempY);
  Wcov[0] = ((1.0 - xnorm) + beta) + Wmean[0];
  Wcov[1] = Wmean[1];
  if (Wmean[0] != 0.0) {
    xnorm = Wmean[0];
    Wmean_0 = Wmean[0];
    Wmean[0] /= Wmean[0];
    Wcov[0] /= xnorm;
    Wcov_0 = Wmean[1];
    Wmean[1] /= Wmean_0;
    Wcov[1] = Wcov_0 / xnorm;
  } else {
    xnorm = 1.0;
  }

  tempY = sqrt(tempY);
  Wmean_0 = tempY * S[0];
  X2[0] = Wmean_0;
  X2[4] = -Wmean_0;
  Wmean_0 = tempY * S[1];
  X2[1] = Wmean_0;
  X2[5] = -Wmean_0;
  Wmean_0 = tempY * S[2];
  X2[2] = Wmean_0;
  X2[6] = -Wmean_0;
  Wmean_0 = tempY * S[3];
  X2[3] = Wmean_0;
  X2[7] = -Wmean_0;
  for (knt = 0; knt < 4; knt++) {
    X2_tmp = knt << 1;
    X2[X2_tmp] += X1[0];
    X2[X2_tmp + 1] += X1[1];
  }

  batteryMeasurementFcn(&X2[0], &tempY);
  Y2[0] = tempY;
  batteryMeasurementFcn(&X2[2], &tempY);
  Y2[1] = tempY;
  batteryMeasurementFcn(&X2[4], &tempY);
  Y2[2] = tempY;
  batteryMeasurementFcn(&X2[6], &tempY);
  Y2[3] = tempY;
  batteryMeasurementFcn(X1, &tempY);
  UTMeanCovSqrt_nmwxOcMg(Wmean, Wcov, xnorm, tempY, Y2, X1, X2, Ymean, Sy, Pxy);
  Wmean[0] = *Sy;
  Wmean[1] = Rs;
  xnorm = xnrm2_hoYimUM0(1, Wmean, 2);
  if (xnorm != 0.0) {
    xnorm = rt_hypotd(*Sy, xnorm);
    if (*Sy >= 0.0) {
      xnorm = -xnorm;
    }

    if (fabs(xnorm) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        Wmean[1] *= 9.9792015476736E+291;
        xnorm *= 9.9792015476736E+291;
        *Sy *= 9.9792015476736E+291;
      } while (fabs(xnorm) < 1.0020841800044864E-292);

      xnorm = rt_hypotd(*Sy, xnrm2_hoYimUM0(1, Wmean, 2));
      if (*Sy >= 0.0) {
        xnorm = -xnorm;
      }

      for (X2_tmp = 0; X2_tmp <= knt; X2_tmp++) {
        xnorm *= 1.0020841800044864E-292;
      }

      *Sy = xnorm;
    } else {
      *Sy = xnorm;
    }
  }
}

/* Model step function */
void Main_step(void)
{
  NeParameterBundle expl_temp;
  NeslSimulationData *simulationData_tmp_tmp;
  NeuDiagnosticManager *diag;
  NeuDiagnosticTree *diagTree;
  NeuDiagnosticTree *diagnosticTree;
  NeuDiagnosticTree *diagnosticTree_0;
  NeuDiagnosticTree *diagnosticTree_1;
  char *msg;
  char *msg_0;
  char *msg_1;
  char *msg_2;
  real_T tmp_2[20];
  real_T X2state[8];
  real_T Y2[8];
  real_T S[4];
  real_T Ss[4];
  real_T tmp_0[4];
  real_T tmp_4[4];
  real_T y[4];
  real_T C[2];
  real_T K[2];
  real_T U[2];
  real_T c[2];
  real_T s[2];
  real_T absxk;
  real_T nrmx;
  real_T rtb_Gain;
  real_T scale;
  real_T t;
  real_T time;
  real_T time_0;
  real_T time_1;
  real_T time_tmp;
  real_T tmp;
  int32_T c_i;
  int32_T coffset;
  int32_T exitg1;
  int_T tmp_3[3];
  int_T tmp_1[2];
  int_T tmp_5[2];
  int8_T p;
  boolean_T exitg2;
  boolean_T ok;

  /* SimscapeInputBlock: '<S11>/INPUT_1_1_1' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  rtB.INPUT_1_1_1[0] = -3.0;
  rtB.INPUT_1_1_1[1] = 0.0;
  rtB.INPUT_1_1_1[2] = 0.0;
  rtDW.INPUT_1_1_1_Discrete[0] = (rtB.INPUT_1_1_1[0] !=
    rtDW.INPUT_1_1_1_Discrete[1]);
  rtDW.INPUT_1_1_1_Discrete[1] = rtB.INPUT_1_1_1[0];
  rtB.INPUT_1_1_1[0] = rtDW.INPUT_1_1_1_Discrete[1];
  rtB.INPUT_1_1_1[3] = rtDW.INPUT_1_1_1_Discrete[0];

  /* SimscapeRtp: '<S4>/RTP_1' incorporates:
   *  Constant: '<Root>/Subsystem_around_RTP_375D5FF6_stateOfCharge'
   */
  if (rtDW.RTP_1_SetParametersNeeded) {
    tmp = 0.7;
    diag = rtw_create_diagnostics();
    diagTree = neu_diagnostic_manager_get_initial_tree(diag);
    expl_temp.mRealParameters.mN = 1;
    expl_temp.mRealParameters.mX = &tmp;
    expl_temp.mLogicalParameters.mN = 0;
    expl_temp.mLogicalParameters.mX = NULL;
    expl_temp.mIntegerParameters.mN = 0;
    expl_temp.mIntegerParameters.mX = NULL;
    expl_temp.mIndexParameters.mN = 0;
    expl_temp.mIndexParameters.mX = NULL;
    ok = nesl_rtp_manager_set_rtps((NeslRtpManager *)rtDW.RTP_1_RtpManager,
      ((rtM->Timing.clockTick0) * 0.2), expl_temp, diag);
    if (!ok) {
      ok = error_buffer_is_empty(((void*) 0));
      if (ok) {
        msg = rtw_diagnostics_msg(diagTree);
        ((void) 0);
      }
    }
  }

  rtDW.RTP_1_SetParametersNeeded = false;

  /* End of SimscapeRtp: '<S4>/RTP_1' */

  /* SimscapeExecutionBlock: '<S11>/STATE_1' incorporates:
   *  SimscapeExecutionBlock: '<S11>/OUTPUT_1_0'
   */
  simulationData_tmp_tmp = (NeslSimulationData *)rtDW.STATE_1_SimData;
  time_tmp = ((rtM->Timing.clockTick0) * 0.2);
  time = time_tmp;
  simulationData_tmp_tmp->mData->mTime.mN = 1;
  simulationData_tmp_tmp->mData->mTime.mX = &time;
  simulationData_tmp_tmp->mData->mContStates.mN = 0;
  simulationData_tmp_tmp->mData->mContStates.mX = NULL;
  simulationData_tmp_tmp->mData->mDiscStates.mN = 10;
  simulationData_tmp_tmp->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete[0];
  simulationData_tmp_tmp->mData->mModeVector.mN = 6;
  simulationData_tmp_tmp->mData->mModeVector.mX = &rtDW.STATE_1_Modes[0];
  ok = false;
  simulationData_tmp_tmp->mData->mFoundZcEvents = ok;
  simulationData_tmp_tmp->mData->mIsMajorTimeStep = true;
  ok = false;
  simulationData_tmp_tmp->mData->mIsSolverAssertCheck = ok;
  simulationData_tmp_tmp->mData->mIsSolverCheckingCIC = false;
  simulationData_tmp_tmp->mData->mIsComputingJacobian = false;
  simulationData_tmp_tmp->mData->mIsEvaluatingF0 = false;
  simulationData_tmp_tmp->mData->mIsSolverRequestingReset = false;
  simulationData_tmp_tmp->mData->mIsOkayToUpdateMode = true;
  tmp_1[0] = 0;
  tmp_0[0] = rtB.INPUT_1_1_1[0];
  tmp_0[1] = rtB.INPUT_1_1_1[1];
  tmp_0[2] = rtB.INPUT_1_1_1[2];
  tmp_0[3] = rtB.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  simulationData_tmp_tmp->mData->mInputValues.mN = 4;
  simulationData_tmp_tmp->mData->mInputValues.mX = &tmp_0[0];
  simulationData_tmp_tmp->mData->mInputOffsets.mN = 2;
  simulationData_tmp_tmp->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData_tmp_tmp->mData->mOutputs.mN = 16;
  simulationData_tmp_tmp->mData->mOutputs.mX = &rtB.STATE_1[0];
  simulationData_tmp_tmp->mData->mSampleHits.mN = 0;
  simulationData_tmp_tmp->mData->mSampleHits.mX = NULL;
  ok = 1;
  simulationData_tmp_tmp->mData->mIsFundamentalSampleHit = ok;
  simulationData_tmp_tmp->mData->mTolerances.mN = 0;
  simulationData_tmp_tmp->mData->mTolerances.mX = NULL;
  simulationData_tmp_tmp->mData->mCstateHasChanged = false;
  diag = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diag);
  c_i = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
    NESL_SIM_OUTPUTS, simulationData_tmp_tmp, diag);
  if (c_i != 0) {
    ok = error_buffer_is_empty(((void*) 0));
    if (ok) {
      msg_0 = rtw_diagnostics_msg(diagnosticTree);
      ((void) 0);
    }
  }

  /* End of SimscapeExecutionBlock: '<S11>/STATE_1' */

  /* SimscapeExecutionBlock: '<S11>/OUTPUT_1_0' */
  simulationData_tmp_tmp = (NeslSimulationData *)rtDW.OUTPUT_1_0_SimData;
  time_0 = time_tmp;
  simulationData_tmp_tmp->mData->mTime.mN = 1;
  simulationData_tmp_tmp->mData->mTime.mX = &time_0;
  simulationData_tmp_tmp->mData->mContStates.mN = 0;
  simulationData_tmp_tmp->mData->mContStates.mX = NULL;
  simulationData_tmp_tmp->mData->mDiscStates.mN = 0;
  simulationData_tmp_tmp->mData->mDiscStates.mX = &rtDW.OUTPUT_1_0_Discrete;
  simulationData_tmp_tmp->mData->mModeVector.mN = 0;
  simulationData_tmp_tmp->mData->mModeVector.mX = &rtDW.OUTPUT_1_0_Modes;
  ok = false;
  simulationData_tmp_tmp->mData->mFoundZcEvents = ok;
  simulationData_tmp_tmp->mData->mIsMajorTimeStep = true;
  ok = false;
  simulationData_tmp_tmp->mData->mIsSolverAssertCheck = ok;
  simulationData_tmp_tmp->mData->mIsSolverCheckingCIC = false;
  simulationData_tmp_tmp->mData->mIsComputingJacobian = false;
  simulationData_tmp_tmp->mData->mIsEvaluatingF0 = false;
  simulationData_tmp_tmp->mData->mIsSolverRequestingReset = false;
  simulationData_tmp_tmp->mData->mIsOkayToUpdateMode = true;
  tmp_3[0] = 0;
  tmp_2[0] = rtB.INPUT_1_1_1[0];
  tmp_2[1] = rtB.INPUT_1_1_1[1];
  tmp_2[2] = rtB.INPUT_1_1_1[2];
  tmp_2[3] = rtB.INPUT_1_1_1[3];
  tmp_3[1] = 4;
  memcpy(&tmp_2[4], &rtB.STATE_1[0], sizeof(real_T) << 4U);
  tmp_3[2] = 20;
  simulationData_tmp_tmp->mData->mInputValues.mN = 20;
  simulationData_tmp_tmp->mData->mInputValues.mX = &tmp_2[0];
  simulationData_tmp_tmp->mData->mInputOffsets.mN = 3;
  simulationData_tmp_tmp->mData->mInputOffsets.mX = &tmp_3[0];
  simulationData_tmp_tmp->mData->mOutputs.mN = 2;
  simulationData_tmp_tmp->mData->mOutputs.mX = &rtB.OUTPUT_1_0[0];
  simulationData_tmp_tmp->mData->mSampleHits.mN = 0;
  simulationData_tmp_tmp->mData->mSampleHits.mX = NULL;
  ok = 1;
  simulationData_tmp_tmp->mData->mIsFundamentalSampleHit = ok;
  simulationData_tmp_tmp->mData->mTolerances.mN = 0;
  simulationData_tmp_tmp->mData->mTolerances.mX = NULL;
  simulationData_tmp_tmp->mData->mCstateHasChanged = false;
  diag = (NeuDiagnosticManager *)rtDW.OUTPUT_1_0_DiagMgr;
  diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diag);
  c_i = ne_simulator_method((NeslSimulator *)rtDW.OUTPUT_1_0_Simulator,
    NESL_SIM_OUTPUTS, simulationData_tmp_tmp, diag);
  if (c_i != 0) {
    ok = error_buffer_is_empty(((void*) 0));
    if (ok) {
      msg_1 = rtw_diagnostics_msg(diagnosticTree_0);
      ((void) 0);
    }
  }

  /* Gain: '<S2>/Gain' */
  rtb_Gain = -rtB.OUTPUT_1_0[1];

  /* Outputs for Enabled SubSystem: '<S12>/Correct1' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  /* MATLAB Function: '<S15>/Correct' incorporates:
   *  Constant: '<S12>/R1'
   *  DataStoreRead: '<S15>/Data Store ReadX'
   *  DataStoreWrite: '<S15>/Data Store WriteP'
   */
  batteryMeasurementFcn(rtDW.x, &nrmx);
  UKFCorrectorAdditive_getPredict(0.031622776601683791, rtDW.x, rtDW.P_m, 1.0,
    2.0, 0.0, &scale, U, &nrmx);
  rtb_Gain -= scale;
  C[0] = U[0];
  C[1] = U[1];
  trisolve_3WRXGFtF(nrmx, C);
  K[0] = C[0];
  K[1] = C[1];
  trisolve_3WRXGFtF(nrmx, K);
  U[0] = K[0] * nrmx;
  U[1] = K[1] * nrmx;
  nrmx = rtDW.P_m[1];
  rtDW.P_m[1] = rtDW.P_m[2];
  rtDW.P_m[2] = nrmx;
  rtDW.P_m[1] = 0.0;
  p = 0;
  if ((rtDW.P_m[0] == 0.0) || (rtDW.P_m[3] == 0.0)) {
    p = 2;
  } else {
    scale = 3.3121686421112381E-170;
    C[0] = U[0] / rtDW.P_m[0];
    absxk = fabs(C[0]);
    if (absxk > 3.3121686421112381E-170) {
      nrmx = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      nrmx = t * t;
    }

    C[1] = (U[1] - C[0] * rtDW.P_m[2]) / rtDW.P_m[3];
    absxk = fabs(C[1]);
    if (absxk > scale) {
      t = scale / absxk;
      nrmx = nrmx * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      nrmx += t * t;
    }

    nrmx = scale * sqrt(nrmx);
    if (nrmx >= 1.0) {
      p = 1;
    } else {
      rotate_YgpoDwi7(sqrt(1.0 - nrmx * nrmx), C[1], &c[1], &s[1], &scale);
      C[1] = 0.0;
      rotate_YgpoDwi7(scale, C[0], &c[0], &s[0], &scale);
      C[0] = 0.0;
      for (c_i = 0; c_i + 1 > 0; c_i--) {
        nrmx = s[c_i] * rtDW.P_m[c_i];
        rtDW.P_m[c_i] = c[c_i] * rtDW.P_m[c_i] - s[c_i] * C[0];
        C[0] = c[c_i] * C[0] + nrmx;
      }

      for (c_i = 1; c_i + 1 > 0; c_i--) {
        nrmx = rtDW.P_m[c_i + 2];
        rtDW.P_m[c_i + 2] = nrmx * c[c_i] - s[c_i] * C[1];
        C[1] = c[c_i] * C[1] + nrmx * s[c_i];
      }
    }
  }

  if (p != 0) {
    for (c_i = 0; c_i < 2; c_i++) {
      S[c_i] = 0.0;
      coffset = c_i << 1;
      S[c_i] += rtDW.P_m[coffset] * rtDW.P_m[0];
      S[c_i] += rtDW.P_m[coffset + 1] * rtDW.P_m[1];
      Ss[coffset] = U[0] * U[c_i];
      S[c_i + 2] = 0.0;
      S[c_i + 2] += rtDW.P_m[coffset] * rtDW.P_m[2];
      S[c_i + 2] += rtDW.P_m[coffset + 1] * rtDW.P_m[3];
      Ss[coffset + 1] = U[1] * U[c_i];
    }

    y[0] = S[0] - Ss[0];
    y[1] = S[1] - Ss[1];
    y[2] = S[2] - Ss[2];
    y[3] = S[3] - Ss[3];
    svd_ITQaouod(y, Ss, s, rtDW.P_m);
    Ss[0] = sqrt(s[0]);
    Ss[1] = 0.0;
    Ss[2] = 0.0;
    Ss[3] = sqrt(s[1]);
    for (c_i = 0; c_i < 2; c_i++) {
      S[c_i] = 0.0;
      coffset = c_i << 1;
      nrmx = Ss[coffset];
      S[c_i] += nrmx * rtDW.P_m[0];
      scale = Ss[coffset + 1];
      S[c_i] += scale * rtDW.P_m[2];
      S[c_i + 2] = 0.0;
      S[c_i + 2] += nrmx * rtDW.P_m[1];
      S[c_i + 2] += scale * rtDW.P_m[3];
    }

    rtDW.P_m[0] = S[0];
    rtDW.P_m[1] = S[1];
    rtDW.P_m[2] = S[2];
    rtDW.P_m[3] = S[3];
    ok = true;
    c_i = 0;
    exitg2 = false;
    while ((!exitg2) && (c_i < 2)) {
      coffset = c_i + 2;
      do {
        exitg1 = 0;
        if (coffset < 3) {
          if (rtDW.P_m[(c_i << 1) + 1] != 0.0) {
            ok = false;
            exitg1 = 1;
          } else {
            coffset = 3;
          }
        } else {
          c_i++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (!ok) {
      for (c_i = 0; c_i < 4; c_i++) {
        S[c_i] = rtDW.P_m[c_i];
      }

      qr_4aCbWkNT(S, Ss, rtDW.P_m);
    }
  }

  nrmx = rtDW.P_m[1];
  rtDW.P_m[1] = rtDW.P_m[2];
  rtDW.P_m[2] = nrmx;

  /* DataStoreWrite: '<S15>/Data Store WriteX' incorporates:
   *  DataStoreRead: '<S15>/Data Store ReadX'
   *  MATLAB Function: '<S15>/Correct'
   */
  rtDW.x[0] += K[0] * rtb_Gain;
  rtDW.x[1] += K[1] * rtb_Gain;

  /* End of Outputs for SubSystem: '<S12>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S12>/Predict' */
  /* MATLAB Function: '<S16>/Predict' incorporates:
   *  DataStoreRead: '<S16>/Data Store ReadX'
   *  DataStoreWrite: '<S16>/Data Store WriteP'
   */
  batteryStateFcn(rtDW.x, U);
  rtDW.P_m[0] *= 1.4142135623730951;
  X2state[0] = rtDW.P_m[0];
  X2state[4] = -rtDW.P_m[0];
  rtDW.P_m[1] *= 1.4142135623730951;
  X2state[1] = rtDW.P_m[1];
  X2state[5] = -rtDW.P_m[1];
  rtDW.P_m[2] *= 1.4142135623730951;
  X2state[2] = rtDW.P_m[2];
  X2state[6] = -rtDW.P_m[2];
  rtDW.P_m[3] *= 1.4142135623730951;
  X2state[3] = rtDW.P_m[3];
  X2state[7] = -rtDW.P_m[3];
  for (c_i = 0; c_i < 4; c_i++) {
    coffset = c_i << 1;
    X2state[coffset] += rtDW.x[0];
    X2state[coffset + 1] += rtDW.x[1];
  }

  for (c_i = 0; c_i < 4; c_i++) {
    batteryStateFcn(&X2state[c_i << 1], U);
    coffset = c_i << 1;
    Y2[coffset] = U[0];
    Y2[coffset + 1] = U[1];
  }

  batteryStateFcn(rtDW.x, U);
  C[0] = 0.0;
  K[0] = 2.0;
  C[1] = 0.25;
  K[1] = 0.25;
  for (c_i = 0; c_i < 2; c_i++) {
    c[c_i] = rtDW.x[c_i];
  }

  /* DataStoreWrite: '<S16>/Data Store WriteX' incorporates:
   *  MATLAB Function: '<S16>/Predict'
   */
  UTMeanCovSqrt_14Tzk8eT(C, K, 1.0, U, Y2, c, X2state, rtDW.x, S, Ss);

  /* MATLAB Function: '<S16>/Predict' incorporates:
   *  Constant: '<S12>/Q'
   *  DataStoreWrite: '<S16>/Data Store WriteP'
   */
  Ss[1] = 0.0;
  Ss[2] = 0.0;
  Ss[0] = 1.0;
  Ss[3] = 1.0;
  for (c_i = 0; c_i < 2; c_i++) {
    coffset = c_i << 1;
    rtb_Gain = Ss[c_i + 2];
    y[coffset] = rtb_Gain * S[1] + S[0] * Ss[c_i];
    y[coffset + 1] = rtb_Gain * S[3] + S[2] * Ss[c_i];
  }

  Y2[0] = y[0];
  Y2[2] = 0.00014142135623730951;
  Y2[1] = y[1];
  Y2[3] = 0.0;
  Y2[4] = y[2];
  Y2[6] = 0.0;
  Y2[5] = y[3];
  Y2[7] = 0.00054772255750516611;
  qr_KQupoFeg(Y2, X2state, Ss);
  rtDW.P_m[0] = Ss[0];
  rtDW.P_m[1] = Ss[2];
  rtDW.P_m[2] = Ss[1];
  rtDW.P_m[3] = Ss[3];

  /* End of Outputs for SubSystem: '<S12>/Predict' */

  /* Update for SimscapeExecutionBlock: '<S11>/STATE_1' */
  simulationData_tmp_tmp = (NeslSimulationData *)rtDW.STATE_1_SimData;
  time_1 = time_tmp;
  simulationData_tmp_tmp->mData->mTime.mN = 1;
  simulationData_tmp_tmp->mData->mTime.mX = &time_1;
  simulationData_tmp_tmp->mData->mContStates.mN = 0;
  simulationData_tmp_tmp->mData->mContStates.mX = NULL;
  simulationData_tmp_tmp->mData->mDiscStates.mN = 10;
  simulationData_tmp_tmp->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete[0];
  simulationData_tmp_tmp->mData->mModeVector.mN = 6;
  simulationData_tmp_tmp->mData->mModeVector.mX = &rtDW.STATE_1_Modes[0];
  ok = false;
  simulationData_tmp_tmp->mData->mFoundZcEvents = ok;
  simulationData_tmp_tmp->mData->mIsMajorTimeStep = true;
  ok = false;
  simulationData_tmp_tmp->mData->mIsSolverAssertCheck = ok;
  simulationData_tmp_tmp->mData->mIsSolverCheckingCIC = false;
  simulationData_tmp_tmp->mData->mIsComputingJacobian = false;
  simulationData_tmp_tmp->mData->mIsEvaluatingF0 = false;
  simulationData_tmp_tmp->mData->mIsSolverRequestingReset = false;
  simulationData_tmp_tmp->mData->mIsOkayToUpdateMode = true;
  tmp_5[0] = 0;
  tmp_4[0] = rtB.INPUT_1_1_1[0];
  tmp_4[1] = rtB.INPUT_1_1_1[1];
  tmp_4[2] = rtB.INPUT_1_1_1[2];
  tmp_4[3] = rtB.INPUT_1_1_1[3];
  tmp_5[1] = 4;
  simulationData_tmp_tmp->mData->mInputValues.mN = 4;
  simulationData_tmp_tmp->mData->mInputValues.mX = &tmp_4[0];
  simulationData_tmp_tmp->mData->mInputOffsets.mN = 2;
  simulationData_tmp_tmp->mData->mInputOffsets.mX = &tmp_5[0];
  diag = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
  diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diag);
  c_i = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
    NESL_SIM_UPDATE, simulationData_tmp_tmp, diag);
  if (c_i != 0) {
    ok = error_buffer_is_empty(((void*) 0));
    if (ok) {
      msg_2 = rtw_diagnostics_msg(diagnosticTree_1);
      ((void) 0);
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  rtM->Timing.clockTick0++;
}

/* Model initialize function */
void Main_initialize(void)
{
  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeslRtpManager *manager;
    NeslRtpManager *manager_0;
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp_0;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    char *msg;
    char *msg_0;
    real_T tmp_2;
    int32_T tmp_3;
    boolean_T tmp;

    /* Start for SimscapeRtp: '<S4>/RTP_1' */
    manager_0 = nesl_lease_rtp_manager("Main/Solver Configuration1_1", 0);
    manager = manager_0;
    tmp = pointer_is_null(manager_0);
    if (tmp) {
      Main_45a0674_1_gateway();
      manager = nesl_lease_rtp_manager("Main/Solver Configuration1_1", 0);
    }

    rtDW.RTP_1_RtpManager = (void *)manager;
    rtDW.RTP_1_SetParametersNeeded = true;

    /* End of Start for SimscapeRtp: '<S4>/RTP_1' */

    /* Start for SimscapeExecutionBlock: '<S11>/STATE_1' */
    tmp_0 = nesl_lease_simulator("Main/Solver Configuration1_1", 0, 0);
    rtDW.STATE_1_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(rtDW.STATE_1_Simulator);
    if (tmp) {
      Main_45a0674_1_gateway();
      tmp_0 = nesl_lease_simulator("Main/Solver Configuration1_1", 0, 0);
      rtDW.STATE_1_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    rtDW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    rtDW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DISCRETE;
    modelParameters.mSolverTolerance = 0.001;
    modelParameters.mVariableStepSolver = false;
    modelParameters.mIsUsingODEN = false;
    modelParameters.mFixedStepSize = 0.001;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_ALL;
    modelParameters.mRTWModifiedTimeStamp = 5.69159444E+8;
    tmp_2 = 0.001;
    modelParameters.mSolverTolerance = tmp_2;
    tmp_2 = 0.2;
    modelParameters.mFixedStepSize = tmp_2;
    tmp = false;
    modelParameters.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters.mIsUsingODEN = tmp;
    modelParameters.mLoadInitialState = false;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)rtDW.STATE_1_Simulator,
      &modelParameters, diagnosticManager);
    if (tmp_3 != 0) {
      tmp = error_buffer_is_empty(((void*) 0));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        ((void) 0);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S11>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S11>/OUTPUT_1_0' */
    tmp_0 = nesl_lease_simulator("Main/Solver Configuration1_1", 1, 0);
    rtDW.OUTPUT_1_0_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(rtDW.OUTPUT_1_0_Simulator);
    if (tmp) {
      Main_45a0674_1_gateway();
      tmp_0 = nesl_lease_simulator("Main/Solver Configuration1_1", 1, 0);
      rtDW.OUTPUT_1_0_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    rtDW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    rtDW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DISCRETE;
    modelParameters_0.mSolverTolerance = 0.001;
    modelParameters_0.mVariableStepSolver = false;
    modelParameters_0.mIsUsingODEN = false;
    modelParameters_0.mFixedStepSize = 0.001;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_ALL;
    modelParameters_0.mRTWModifiedTimeStamp = 5.69159444E+8;
    tmp_2 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_2;
    tmp_2 = 0.2;
    modelParameters_0.mFixedStepSize = tmp_2;
    tmp = false;
    modelParameters_0.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters_0.mIsUsingODEN = tmp;
    modelParameters_0.mLoadInitialState = false;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)rtDW.OUTPUT_1_0_Simulator,
      &modelParameters_0, diagnosticManager);
    if (tmp_3 != 0) {
      tmp = error_buffer_is_empty(((void*) 0));
      if (tmp) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        ((void) 0);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S11>/OUTPUT_1_0' */

    /* Start for DataStoreMemory: '<S12>/DataStoreMemory - P' */
    rtDW.P_m[0] = 0.1;
    rtDW.P_m[1] = 0.0;
    rtDW.P_m[2] = 0.0;
    rtDW.P_m[3] = 0.63245553203367588;

    /* Start for DataStoreMemory: '<S12>/DataStoreMemory - x' */
    rtDW.x[0] = 0.7;
    rtDW.x[1] = 3.8;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
