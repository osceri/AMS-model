/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: cellStateEstimator.c
 *
 * Code generated for Simulink model 'cellStateEstimator'.
 *
 * Model version                  : 1.71
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Mar 14 17:18:54 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "cellStateEstimator.h"
#include "cellStateEstimator_private.h"
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

/* Block states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Forward declaration for local functions */
static void UKFCorrectorAdditive_getPredict(real_T Rs, const real_T X1[2], const
  real_T S[4], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[2], real_T *Sy);

/* Output and update for Simulink Function: '<S1>/f' */
void batteryStateFcn(const real_T rtu_x[2], real_T rty_x_next[2])
{
  real_T tmp;

  /* MATLAB Function: '<S3>/h' incorporates:
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/Current'
   *  Inport: '<Root>/Initial Capacity'
   *  Lookup_n-D: '<S3>/1-D Lookup Table1'
   *  Lookup_n-D: '<S3>/1-D Lookup Table2'
   *  SignalConversion generated from: '<S3>/u'
   *  SignalConversion generated from: '<S3>/y'
   */
  rty_x_next[0] = rtu_x[0] - 0.2 * rtU.Measuredcurrent / rtU.Initialcapacity;
  tmp = exp(-0.2 / look1_binlxpw(rtu_x[0], rtCP_uDLookupTable1_bp01Data,
             rtCP_uDLookupTable1_tableData, 32U));
  rty_x_next[1] = tmp * rtu_x[1] - (1.0 - tmp) * look1_binlxpw(rtu_x[0],
    rtCP_uDLookupTable2_bp01Data, rtCP_uDLookupTable2_tableData, 32U) *
    rtU.Measuredcurrent;
}

/* Output and update for Simulink Function: '<S1>/h' */
void batteryMeasurementFcn(const real_T rtu_x[2], real_T *rty_y)
{
  /* SignalConversion generated from: '<S4>/y' incorporates:
   *  Inport: '<Root>/Current'
   *  Lookup_n-D: '<S4>/1-D Lookup Table'
   *  Lookup_n-D: '<S4>/1-D Lookup Table1'
   *  Product: '<S4>/Product'
   *  SignalConversion generated from: '<S4>/x'
   *  Sum: '<S4>/Add'
   */
  *rty_y = (look1_binlxpw(rtu_x[0], rtCP_uDLookupTable1_bp01Data_l,
             rtCP_uDLookupTable1_tableData_j, 32U) * rtU.Measuredcurrent +
            look1_binlxpw(rtu_x[0], rtCP_uDLookupTable_bp01Data_e,
             rtCP_uDLookupTable_tableData_g, 32U)) - rtu_x[1];
}

/* Function for MATLAB Function: '<S5>/Correct' */
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
void cellStateEstimator_step(void)
{
  real_T X2state[8];
  real_T Y2[8];
  real_T S[4];
  real_T Ss[4];
  real_T y[4];
  real_T C[2];
  real_T K[2];
  real_T U[2];
  real_T c[2];
  real_T s[2];
  real_T absxk;
  real_T nrmx;
  real_T residual;
  real_T scale;
  real_T t;
  int32_T c_i;
  int32_T coffset;
  int32_T exitg1;
  int8_T p;
  boolean_T b_p;
  boolean_T exitg2;

  /* Outputs for Enabled SubSystem: '<S2>/Correct1' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  /* MATLAB Function: '<S5>/Correct' incorporates:
   *  Constant: '<S2>/R1'
   *  DataStoreRead: '<S5>/Data Store ReadX'
   *  DataStoreWrite: '<S5>/Data Store WriteP'
   *  Inport: '<Root>/Voltage'
   */
  batteryMeasurementFcn(rtDW.x, &residual);
  UKFCorrectorAdditive_getPredict(0.031622776601683791, rtDW.x, rtDW.P_m, 1.0,
    2.0, 0.0, &residual, U, &nrmx);
  residual = rtU.MeasuredOCV - residual;
  C[0] = U[0];
  C[1] = U[1];
  trisolve_3WRXGFtF(nrmx, C);
  K[0] = C[0];
  K[1] = C[1];
  trisolve_3WRXGFtF(nrmx, K);
  U[0] = K[0] * nrmx;
  U[1] = K[1] * nrmx;
  rtDW.P_m[2] = rtDW.P_m[1];
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
    b_p = true;
    c_i = 0;
    exitg2 = false;
    while ((!exitg2) && (c_i < 2)) {
      coffset = c_i + 2;
      do {
        exitg1 = 0;
        if (coffset < 3) {
          if (rtDW.P_m[(c_i << 1) + 1] != 0.0) {
            b_p = false;
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

    if (!b_p) {
      for (c_i = 0; c_i < 4; c_i++) {
        S[c_i] = rtDW.P_m[c_i];
      }

      qr_4aCbWkNT(S, Ss, rtDW.P_m);
    }
  }

  nrmx = rtDW.P_m[1];
  rtDW.P_m[1] = rtDW.P_m[2];
  rtDW.P_m[2] = nrmx;

  /* DataStoreWrite: '<S5>/Data Store WriteX' incorporates:
   *  DataStoreRead: '<S5>/Data Store ReadX'
   *  MATLAB Function: '<S5>/Correct'
   */
  rtDW.x[0] += K[0] * residual;
  rtDW.x[1] += K[1] * residual;

  /* End of Outputs for SubSystem: '<S2>/Correct1' */

  /* Outport: '<Root>/SOC' incorporates:
   *  DataStoreRead: '<S7>/Data Store Read'
   */
  rtY.SOC = rtDW.x[0];

  /* Outport: '<Root>/Capacity' incorporates:
   *  Inport: '<Root>/Initial Capacity'
   */
  rtY.Capacity = rtU.Initialcapacity;

  /* Outputs for Atomic SubSystem: '<S2>/Predict' */
  /* MATLAB Function: '<S6>/Predict' incorporates:
   *  DataStoreRead: '<S6>/Data Store ReadX'
   *  DataStoreWrite: '<S6>/Data Store WriteP'
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

  /* DataStoreWrite: '<S6>/Data Store WriteX' incorporates:
   *  MATLAB Function: '<S6>/Predict'
   */
  UTMeanCovSqrt_14Tzk8eT(C, K, 1.0, U, Y2, c, X2state, rtDW.x, S, Ss);

  /* MATLAB Function: '<S6>/Predict' incorporates:
   *  Constant: '<S2>/Q'
   *  DataStoreWrite: '<S6>/Data Store WriteP'
   */
  Ss[1] = 0.0;
  Ss[2] = 0.0;
  Ss[0] = 1.0;
  Ss[3] = 1.0;
  for (c_i = 0; c_i < 2; c_i++) {
    coffset = c_i << 1;
    residual = Ss[c_i + 2];
    y[coffset] = residual * S[1] + S[0] * Ss[c_i];
    y[coffset + 1] = residual * S[3] + S[2] * Ss[c_i];
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

  /* End of Outputs for SubSystem: '<S2>/Predict' */
}

/* Model initialize function */
void cellStateEstimator_initialize(void)
{
  /* Start for DataStoreMemory: '<S2>/DataStoreMemory - P' */
  rtDW.P_m[0] = 0.1;
  rtDW.P_m[1] = 0.0;
  rtDW.P_m[2] = 0.0;
  rtDW.P_m[3] = 0.63245553203367588;

  /* Start for DataStoreMemory: '<S2>/DataStoreMemory - x' */
  rtDW.x[0] = 0.7;
  rtDW.x[1] = 3.8;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
