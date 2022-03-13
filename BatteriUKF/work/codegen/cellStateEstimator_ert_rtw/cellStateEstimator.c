/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: cellStateEstimator.c
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

#include "cellStateEstimator.h"
#include "cellStateEstimator_private.h"
#include "UTMeanCovSqrt_LjG1rgH8.h"
#include "UTMeanCovSqrt_udr9nQYH.h"
#include "qr_4aCbWkNT.h"
#include "qr_KQupoFeg.h"
#include "rotate_YgpoDwi7.h"
#include "rt_hypotd_snf.h"
#include "rt_powd_snf.h"
#include "svd_ITQaouod.h"
#include "trisolve_3WRXGFtF.h"
#include "xnrm2_hoYimUM0.h"

/* Block states (default storage) */
DW_cellStateEstimator_T cellStateEstimator_DW;

/* External inputs (root inport signals with default storage) */
ExtU_cellStateEstimator_T cellStateEstimator_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_cellStateEstimator_T cellStateEstimator_Y;

/* Real-time model */
static RT_MODEL_cellStateEstimator_T cellStateEstimator_M_;
RT_MODEL_cellStateEstimator_T *const cellStateEstimator_M =
  &cellStateEstimator_M_;

/* Forward declaration for local functions */
static void UKFCorrectorAdditive_getPredict(real_T Rs, const real_T X1[2], const
  real_T S[4], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[2], real_T *Sy);

/*
 * Output and update for atomic system:
 *    '<S3>/Rs'
 *    '<S4>/Rs'
 */
void cellStateEstimator_Rs(real_T rtu_z, real_T *rty_Rs)
{
  *rty_Rs = ((rtu_z * rtu_z * 0.0008656 + 0.001451 * rtu_z) + 0.002515) / (rtu_z
    + 0.5787);
}

/* Output and update for Simulink Function: '<S1>/f' */
void cellStateEstima_batteryStateFcn(const real_T rtu_x[2], real_T rty_x_next[2])
{
  real_T rtb_Rs;
  real_T tmp;

  /* MATLAB Function: '<S3>/Rs' incorporates:
   *  SignalConversion generated from: '<S3>/u'
   */
  cellStateEstimator_Rs(rtu_x[0], &rtb_Rs);

  /* MATLAB Function: '<S3>/Rp' incorporates:
   *  MATLAB Function: '<S3>/Cp'
   *  SignalConversion generated from: '<S3>/u'
   */
  rtb_Rs = (((rtu_x[0] * rtu_x[0] * 150.9 + -31.77 * rtu_x[0]) + -32.56) +
            1039.0) + exp((rtu_x[0] - 0.5) * (rtu_x[0] - 0.5) * -64.48) * 1492.0;

  /* MATLAB Function: '<S3>/h' incorporates:
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/Current'
   *  MATLAB Function: '<S3>/Rp'
   *  Outport: '<Root>/Capacity'
   *  SignalConversion generated from: '<S3>/Capacity'
   *  SignalConversion generated from: '<S3>/u'
   *  SignalConversion generated from: '<S3>/y'
   */
  rty_x_next[0] = rtu_x[0] - 0.2 * cellStateEstimator_U.Measuredcurrent /
    cellStateEstimator_Y.Capacity;
  tmp = exp(-0.2 / (rtb_Rs * rtb_Rs));
  rty_x_next[1] = tmp * rtu_x[1] - (1.0 - tmp) * rtb_Rs *
    cellStateEstimator_U.Measuredcurrent;
}

/* Output and update for Simulink Function: '<S1>/h' */
void cellState_batteryMeasurementFcn(const real_T rtu_x[2], real_T *rty_y)
{
  real_T rtb_EstimatedOCV;
  real_T tmp;

  /* MATLAB Function: '<S4>/Rs' incorporates:
   *  SignalConversion generated from: '<S4>/x'
   */
  cellStateEstimator_Rs(rtu_x[0], &rtb_EstimatedOCV);

  /* MATLAB Function: '<S4>/ocv' incorporates:
   *  SignalConversion generated from: '<S4>/x'
   */
  tmp = rtu_x[0] * rtu_x[0];

  /* SignalConversion generated from: '<S4>/y' incorporates:
   *  Inport: '<Root>/Current'
   *  MATLAB Function: '<S4>/ocv'
   *  Product: '<S4>/Product'
   *  SignalConversion generated from: '<S4>/x'
   *  Sum: '<S4>/Add'
   */
  *rty_y = ((((tmp * 2.087 + 1.383 * rt_powd_snf(rtu_x[0], 3.0)) + -0.6693 *
              rtu_x[0]) + 0.4484) / ((tmp + -0.3742 * rtu_x[0]) + 0.1495) +
            rtb_EstimatedOCV * cellStateEstimator_U.Measuredcurrent) - rtu_x[1];
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

  cellState_batteryMeasurementFcn(&X2[0], &tempY);
  Y2[0] = tempY;
  cellState_batteryMeasurementFcn(&X2[2], &tempY);
  Y2[1] = tempY;
  cellState_batteryMeasurementFcn(&X2[4], &tempY);
  Y2[2] = tempY;
  cellState_batteryMeasurementFcn(&X2[6], &tempY);
  Y2[3] = tempY;
  cellState_batteryMeasurementFcn(X1, &tempY);
  UTMeanCovSqrt_udr9nQYH(Wmean, Wcov, xnorm, tempY, Y2, X1, X2, Ymean, Sy, Pxy);
  Wmean[0] = *Sy;
  Wmean[1] = Rs;
  xnorm = xnrm2_hoYimUM0(1, Wmean, 2);
  if (xnorm != 0.0) {
    xnorm = rt_hypotd_snf(*Sy, xnorm);
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
      } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

      xnorm = rt_hypotd_snf(*Sy, xnrm2_hoYimUM0(1, Wmean, 2));
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
  real_T Ss[4];
  real_T V[4];
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
  boolean_T d_p;
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
  cellState_batteryMeasurementFcn(cellStateEstimator_DW.x, &residual);
  UKFCorrectorAdditive_getPredict(0.031622776601683791, cellStateEstimator_DW.x,
    cellStateEstimator_DW.P, 1.0, 2.0, 0.0, &residual, U, &nrmx);
  residual = cellStateEstimator_U.MeasuredOCV - residual;
  C[0] = U[0];
  C[1] = U[1];
  trisolve_3WRXGFtF(nrmx, C);
  K[0] = C[0];
  K[1] = C[1];
  trisolve_3WRXGFtF(nrmx, K);
  U[0] = K[0] * nrmx;
  U[1] = K[1] * nrmx;
  cellStateEstimator_DW.P[2] = cellStateEstimator_DW.P[1];
  cellStateEstimator_DW.P[1] = 0.0;
  p = 0;
  if ((cellStateEstimator_DW.P[0] == 0.0) || (cellStateEstimator_DW.P[3] == 0.0))
  {
    p = 2;
  } else {
    scale = 3.3121686421112381E-170;
    C[0] = U[0] / cellStateEstimator_DW.P[0];
    absxk = fabs(C[0]);
    if (absxk > 3.3121686421112381E-170) {
      nrmx = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      nrmx = t * t;
    }

    C[1] = (U[1] - C[0] * cellStateEstimator_DW.P[2]) / cellStateEstimator_DW.P
      [3];
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
        nrmx = s[c_i] * cellStateEstimator_DW.P[c_i];
        cellStateEstimator_DW.P[c_i] = c[c_i] * cellStateEstimator_DW.P[c_i] -
          s[c_i] * C[0];
        C[0] = c[c_i] * C[0] + nrmx;
      }

      for (c_i = 1; c_i + 1 > 0; c_i--) {
        nrmx = cellStateEstimator_DW.P[c_i + 2];
        cellStateEstimator_DW.P[c_i + 2] = nrmx * c[c_i] - s[c_i] * C[1];
        C[1] = c[c_i] * C[1] + nrmx * s[c_i];
      }
    }
  }

  if (p != 0) {
    for (c_i = 0; c_i < 2; c_i++) {
      V[c_i] = 0.0;
      coffset = c_i << 1;
      V[c_i] += cellStateEstimator_DW.P[coffset] * cellStateEstimator_DW.P[0];
      V[c_i] += cellStateEstimator_DW.P[coffset + 1] * cellStateEstimator_DW.P[1];
      Ss[coffset] = U[0] * U[c_i];
      V[c_i + 2] = 0.0;
      V[c_i + 2] += cellStateEstimator_DW.P[coffset] * cellStateEstimator_DW.P[2];
      V[c_i + 2] += cellStateEstimator_DW.P[coffset + 1] *
        cellStateEstimator_DW.P[3];
      Ss[coffset + 1] = U[1] * U[c_i];
    }

    cellStateEstimator_DW.P[0] = V[0] - Ss[0];
    d_p = ((!rtIsInf(cellStateEstimator_DW.P[0])) && (!rtIsNaN
            (cellStateEstimator_DW.P[0])));
    cellStateEstimator_DW.P[1] = V[1] - Ss[1];
    if (d_p && (rtIsInf(cellStateEstimator_DW.P[1]) || rtIsNaN
                (cellStateEstimator_DW.P[1]))) {
      d_p = false;
    }

    cellStateEstimator_DW.P[2] = V[2] - Ss[2];
    if (d_p && (rtIsInf(cellStateEstimator_DW.P[2]) || rtIsNaN
                (cellStateEstimator_DW.P[2]))) {
      d_p = false;
    }

    cellStateEstimator_DW.P[3] = V[3] - Ss[3];
    if (d_p && ((!rtIsInf(cellStateEstimator_DW.P[3])) && (!rtIsNaN
          (cellStateEstimator_DW.P[3])))) {
      svd_ITQaouod(cellStateEstimator_DW.P, Ss, s, V);
    } else {
      s[0] = (rtNaN);
      s[1] = (rtNaN);
      V[0] = (rtNaN);
      V[1] = (rtNaN);
      V[2] = (rtNaN);
      V[3] = (rtNaN);
    }

    Ss[0] = sqrt(s[0]);
    Ss[1] = 0.0;
    Ss[2] = 0.0;
    Ss[3] = sqrt(s[1]);
    for (c_i = 0; c_i < 2; c_i++) {
      cellStateEstimator_DW.P[c_i] = 0.0;
      coffset = c_i << 1;
      nrmx = Ss[coffset];
      cellStateEstimator_DW.P[c_i] += nrmx * V[0];
      scale = Ss[coffset + 1];
      cellStateEstimator_DW.P[c_i] += scale * V[2];
      cellStateEstimator_DW.P[c_i + 2] = 0.0;
      cellStateEstimator_DW.P[c_i + 2] += nrmx * V[1];
      cellStateEstimator_DW.P[c_i + 2] += scale * V[3];
    }

    d_p = true;
    c_i = 0;
    exitg2 = false;
    while ((!exitg2) && (c_i < 2)) {
      coffset = c_i + 2;
      do {
        exitg1 = 0;
        if (coffset < 3) {
          if (!(cellStateEstimator_DW.P[(c_i << 1) + 1] == 0.0)) {
            d_p = false;
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

    if (!d_p) {
      for (c_i = 0; c_i < 4; c_i++) {
        V[c_i] = cellStateEstimator_DW.P[c_i];
      }

      qr_4aCbWkNT(V, Ss, cellStateEstimator_DW.P);
    }
  }

  nrmx = cellStateEstimator_DW.P[1];
  cellStateEstimator_DW.P[1] = cellStateEstimator_DW.P[2];
  cellStateEstimator_DW.P[2] = nrmx;

  /* DataStoreWrite: '<S5>/Data Store WriteX' incorporates:
   *  DataStoreRead: '<S5>/Data Store ReadX'
   *  MATLAB Function: '<S5>/Correct'
   */
  cellStateEstimator_DW.x[0] += K[0] * residual;
  cellStateEstimator_DW.x[1] += K[1] * residual;

  /* End of Outputs for SubSystem: '<S2>/Correct1' */

  /* Outport: '<Root>/SOC' incorporates:
   *  DataStoreRead: '<S7>/Data Store Read'
   */
  cellStateEstimator_Y.SOC = cellStateEstimator_DW.x[0];

  /* Sum: '<S1>/Add' incorporates:
   *  Inport: '<Root>/Current Counting'
   *  Inport: '<Root>/Initial Capacity'
   *  Outport: '<Root>/Capacity'
   */
  cellStateEstimator_Y.Capacity = cellStateEstimator_U.Initialcapacity +
    cellStateEstimator_U.CurrentCounting;

  /* Outputs for Atomic SubSystem: '<S2>/Predict' */
  /* MATLAB Function: '<S6>/Predict' incorporates:
   *  DataStoreRead: '<S6>/Data Store ReadX'
   *  DataStoreWrite: '<S6>/Data Store WriteP'
   */
  cellStateEstima_batteryStateFcn(cellStateEstimator_DW.x, U);
  cellStateEstimator_DW.P[0] *= 1.4142135623730951;
  X2state[0] = cellStateEstimator_DW.P[0];
  X2state[4] = -cellStateEstimator_DW.P[0];
  cellStateEstimator_DW.P[1] *= 1.4142135623730951;
  X2state[1] = cellStateEstimator_DW.P[1];
  X2state[5] = -cellStateEstimator_DW.P[1];
  cellStateEstimator_DW.P[2] *= 1.4142135623730951;
  X2state[2] = cellStateEstimator_DW.P[2];
  X2state[6] = -cellStateEstimator_DW.P[2];
  cellStateEstimator_DW.P[3] *= 1.4142135623730951;
  X2state[3] = cellStateEstimator_DW.P[3];
  X2state[7] = -cellStateEstimator_DW.P[3];
  for (c_i = 0; c_i < 4; c_i++) {
    coffset = c_i << 1;
    X2state[coffset] += cellStateEstimator_DW.x[0];
    X2state[coffset + 1] += cellStateEstimator_DW.x[1];
  }

  for (c_i = 0; c_i < 4; c_i++) {
    cellStateEstima_batteryStateFcn(&X2state[c_i << 1], U);
    coffset = c_i << 1;
    Y2[coffset] = U[0];
    Y2[coffset + 1] = U[1];
  }

  cellStateEstima_batteryStateFcn(cellStateEstimator_DW.x, U);
  C[0] = 0.0;
  K[0] = 2.0;
  C[1] = 0.25;
  K[1] = 0.25;
  for (c_i = 0; c_i < 2; c_i++) {
    c[c_i] = cellStateEstimator_DW.x[c_i];
  }

  /* DataStoreWrite: '<S6>/Data Store WriteX' incorporates:
   *  MATLAB Function: '<S6>/Predict'
   */
  UTMeanCovSqrt_LjG1rgH8(C, K, 1.0, U, Y2, c, X2state, cellStateEstimator_DW.x,
    Ss, V);

  /* MATLAB Function: '<S6>/Predict' incorporates:
   *  Constant: '<S2>/Q'
   *  DataStoreWrite: '<S6>/Data Store WriteP'
   */
  V[1] = 0.0;
  V[2] = 0.0;
  V[0] = 1.0;
  V[3] = 1.0;
  for (c_i = 0; c_i < 2; c_i++) {
    coffset = c_i << 1;
    residual = V[c_i + 2];
    y[coffset] = residual * Ss[1] + Ss[0] * V[c_i];
    y[coffset + 1] = residual * Ss[3] + Ss[2] * V[c_i];
  }

  Y2[0] = y[0];
  Y2[2] = 0.00014142135623730951;
  Y2[1] = y[1];
  Y2[3] = 0.0;
  Y2[4] = y[2];
  Y2[6] = 0.0;
  Y2[5] = y[3];
  Y2[7] = 0.00054772255750516611;
  qr_KQupoFeg(Y2, X2state, V);
  cellStateEstimator_DW.P[0] = V[0];
  cellStateEstimator_DW.P[1] = V[2];
  cellStateEstimator_DW.P[2] = V[1];
  cellStateEstimator_DW.P[3] = V[3];

  /* End of Outputs for SubSystem: '<S2>/Predict' */
}

/* Model initialize function */
void cellStateEstimator_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for DataStoreMemory: '<S2>/DataStoreMemory - P' */
  cellStateEstimator_DW.P[0] = 0.1;
  cellStateEstimator_DW.P[1] = 0.0;
  cellStateEstimator_DW.P[2] = 0.0;
  cellStateEstimator_DW.P[3] = 1.0;

  /* Start for DataStoreMemory: '<S2>/DataStoreMemory - x' */
  cellStateEstimator_DW.x[0] = 1.0;
  cellStateEstimator_DW.x[1] = 0.0;
}

/* Model terminate function */
void cellStateEstimator_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
