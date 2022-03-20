/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AEKF.c
 *
 * Code generated for Simulink model 'AEKF'.
 *
 * Model version                  : 1.563
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Mar 20 23:41:42 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AEKF.h"
#include "rtwtypes.h"
#include <math.h>
#include "AEKF_types.h"
#include <string.h>

/* Block states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Forward declaration for local functions */
static real_T interp1(const real_T varargin_1[12], const real_T varargin_2[12],
                      real_T varargin_3);

/* Function for MATLAB Function: '<S1>/MATLAB Function1' */
static real_T interp1(const real_T varargin_1[12], const real_T varargin_2[12],
                      real_T varargin_3)
{
  real_T x[12];
  real_T y[12];
  real_T Vq;
  int32_T high_i;
  memcpy(&y[0], &varargin_2[0], 12U * sizeof(real_T));
  memcpy(&x[0], &varargin_1[0], 12U * sizeof(real_T));
  if (varargin_1[1] < varargin_1[0]) {
    for (high_i = 0; high_i < 6; high_i++) {
      real_T xtmp;
      xtmp = x[high_i];
      x[high_i] = x[11 - high_i];
      x[11 - high_i] = xtmp;
      xtmp = y[high_i];
      y[high_i] = y[11 - high_i];
      y[11 - high_i] = xtmp;
    }
  }

  Vq = 0.0;
  if (varargin_3 > x[11]) {
    Vq = y[11];
  } else if (varargin_3 < x[0]) {
    Vq = y[0];
  } else {
    int32_T low_i;
    int32_T low_ip1;
    high_i = 12;
    low_i = 1;
    low_ip1 = 2;
    while (high_i > low_ip1) {
      int32_T mid_i;
      mid_i = (low_i + high_i) >> 1;
      if (varargin_3 >= x[mid_i - 1]) {
        low_i = mid_i;
        low_ip1 = mid_i + 1;
      } else {
        high_i = mid_i;
      }
    }

    if (x[low_i] - varargin_3 > varargin_3 - x[low_i - 1]) {
      low_i--;
    }

    if (low_i + 1 > 0) {
      Vq = y[low_i];
    }
  }

  return Vq;
}

/* Model step function */
void AEKF_step(void)
{
  real_T x[100];
  real_T Ax[4];
  real_T Ax_0[4];
  real_T tmp[4];
  real_T tmp_0[2];
  real_T Cx_idx_1;
  real_T Cx_tmp;
  real_T Ex;
  real_T Kx_idx_0;
  real_T muj;
  real_T temp;
  int32_T i;
  uint32_T tmp_1;
  uint16_T r;
  static const real_T c[12] = { 0.0, 0.0909090909090909, 0.181818181818182,
    0.272727272727273, 0.363636363636364, 0.454545454545455, 0.545454545454545,
    0.636363636363636, 0.727272727272727, 0.818181818181818, 0.909090909090909,
    1.0 };

  static const real_T d[12] = { 0.00446224960061823, 0.00395928973129493,
    0.00365723545490869, 0.00346135878439388, 0.00332839611795259,
    0.00323577769308545, 0.00317057626115591, 0.00312485453442757,
    0.00309346940400882, 0.00307294184679812, 0.00306083426030356,
    0.00305538791678206 };

  static const real_T e[12] = { 0.00132849731829051, 0.00133071540686515,
    0.00133106364620441, 0.00133282418704394, 0.00133927918011939,
    0.00135371077616641, 0.00137940112592065, 0.00141963238011775,
    0.00147768668949337, 0.00155684620478314, 0.00166039307672272,
    0.00179160945604776 };

  static const real_T f[12] = { 950.871946837005, 952.459545918238,
    952.715608141667, 956.801088701637, 1116.9800008749899, 2163.29230815358,
    2204.3466729378397, 1183.99583949683, 1060.79424954235, 1114.3206284707098,
    1188.42633649718, 1282.34445639369 };

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/u'
   *  Inport: '<Root>/y'
   */
  Cx_tmp = pow(rtDW.s.x_[1], 4.0);
  Kx_idx_0 = pow(rtDW.s.x_[1], 3.0);
  Ex = rtDW.s.x_[1] * rtDW.s.x_[1];
  Cx_idx_1 = (((-5.90241040764213 * Cx_tmp + 13.2176608408928 * Kx_idx_0) + Ex *
               -6.67518652537707) + -2.97531430827542 * rtDW.s.x_[1]) +
    3.52891506032032;
  Ex = rtU.Measuredterminalvoltage - (((((((-5.90241040764213 * pow(rtDW.s.x_[1],
    5.0) + 13.2176608408928 * Cx_tmp) + -6.67518652537707 * Kx_idx_0) + Ex *
    -2.97531430827542) + 3.52891506032032 * rtDW.s.x_[1]) + 2.99808472821531) -
    rtU.Measuredcurrent * rtDW.s.p[0]) - rtDW.s.x_[0]);
  muj = 1.0 / (((Cx_idx_1 * rtDW.s.Px_[3] + -rtDW.s.Px_[2]) * Cx_idx_1 +
                -(Cx_idx_1 * rtDW.s.Px_[1] + -rtDW.s.Px_[0])) + rtDW.s.Rx);
  Cx_tmp = (rtDW.s.Px_[2] * Cx_idx_1 + -rtDW.s.Px_[0]) * muj;
  rtDW.s.x[0] = Cx_tmp * Ex + rtDW.s.x_[0];
  Kx_idx_0 = Cx_tmp;
  Cx_tmp = (rtDW.s.Px_[3] * Cx_idx_1 + -rtDW.s.Px_[1]) * muj;
  rtDW.s.x[1] = Cx_tmp * Ex + rtDW.s.x_[1];
  temp = 0.0 - Kx_idx_0 * Cx_idx_1;
  muj = Cx_tmp * Cx_idx_1;
  for (i = 0; i < 2; i++) {
    int32_T tmp_2;
    tmp_2 = i << 1;
    rtDW.s.Px[tmp_2] = 0.0;
    rtDW.s.Px[tmp_2] += (1.0 - (-Kx_idx_0)) * rtDW.s.Px_[tmp_2];
    rtDW.s.Px[tmp_2] += rtDW.s.Px_[tmp_2 + 1] * temp;
    rtDW.s.Px[tmp_2 + 1] = 0.0;
    rtDW.s.Px[tmp_2 + 1] += (0.0 - (-Cx_tmp)) * rtDW.s.Px_[tmp_2];
    rtDW.s.Px[tmp_2 + 1] += rtDW.s.Px_[tmp_2 + 1] * (1.0 - muj);
  }

  muj = 0.0;
  for (i = 0; i < 100; i++) {
    x[i] = rtDW.s.Ex[i];
    muj += rtDW.s.Ex[i];
  }

  muj /= 100.0;
  temp = 0.0;
  for (i = 0; i < 100; i++) {
    real_T x_0;
    x_0 = x[i] - muj;
    temp += x_0 * x_0;
    x[i] = x_0;
  }

  temp *= 0.010101010101010102;
  tmp_1 = rtDW.s.lx + 1U;
  if (rtDW.s.lx + 1U > 65535U) {
    tmp_1 = 65535U;
  }

  if (rtDW.s.Lx == 0) {
    r = (uint16_T)tmp_1;
  } else {
    r = (uint16_T)((uint32_T)(uint16_T)tmp_1 - (uint16_T)((uint32_T)(uint16_T)
      ((uint32_T)(uint16_T)tmp_1 / rtDW.s.Lx) * rtDW.s.Lx));
  }

  tmp_1 = r + 1U;
  if (r + 1U > 65535U) {
    tmp_1 = 65535U;
  }

  rtDW.s.lx = (uint16_T)tmp_1;
  rtDW.s.Ex[rtDW.s.lx - 1] = Ex;
  rtDW.s.Rx = (((Cx_idx_1 * rtDW.s.Px[3] + -rtDW.s.Px[2]) * Cx_idx_1 +
                -(Cx_idx_1 * rtDW.s.Px[1] + -rtDW.s.Px[0])) + temp) *
    0.050000000000000044 + 0.95 * rtDW.s.Rx;
  muj = Kx_idx_0 * temp;
  rtDW.s.Qx[0] = muj * Kx_idx_0 * 0.050000000000000044 + 0.95 * rtDW.s.Qx[0];
  Cx_idx_1 = Cx_tmp * temp;
  rtDW.s.Qx[1] = Cx_idx_1 * Kx_idx_0 * 0.050000000000000044 + 0.95 * rtDW.s.Qx[1];
  rtDW.s.Qx[2] = muj * Cx_tmp * 0.050000000000000044 + 0.95 * rtDW.s.Qx[2];
  rtDW.s.Qx[3] = Cx_idx_1 * Cx_tmp * 0.050000000000000044 + 0.95 * rtDW.s.Qx[3];
  rtDW.s.p[0] = interp1(c, d, rtDW.s.x[1]);
  rtDW.s.p[1] = interp1(c, e, rtDW.s.x[1]);
  rtDW.s.p[2] = interp1(c, f, rtDW.s.x[1]);
  Cx_idx_1 = exp(-0.2 / rtDW.s.p[2]);
  Ax[0] = Cx_idx_1;
  Ax[2] = 0.0;
  tmp[0] = Cx_idx_1;
  tmp[2] = 0.0;
  Ax[1] = 0.0;
  tmp[1] = 0.0;
  Ax[3] = 1.0;
  tmp[3] = 1.0;
  tmp_0[0] = (1.0 - Cx_idx_1) * rtDW.s.p[1] * rtU.Measuredcurrent;
  tmp_0[1] = 0.2 / rtDW.s.p[3] * rtU.Measuredcurrent;
  for (i = 0; i < 2; i++) {
    Ax_0[i] = 0.0;
    Ax_0[i] += Ax[i] * rtDW.s.Px[0];
    Cx_tmp = Ax[i + 2];
    Ax_0[i] += Cx_tmp * rtDW.s.Px[1];
    Ax_0[i + 2] = 0.0;
    Ax_0[i + 2] += Ax[i] * rtDW.s.Px[2];
    Ax_0[i + 2] += Cx_tmp * rtDW.s.Px[3];
    rtDW.s.x_[i] = (tmp[i + 2] * rtDW.s.x[1] + tmp[i] * rtDW.s.x[0]) + tmp_0[i];
    rtDW.s.Px_[i] = Ax_0[i] * Cx_idx_1 + rtDW.s.Qx[i];
    rtDW.s.Px_[i + 2] = Ax_0[i + 2] + rtDW.s.Qx[i + 2];

    /* Outport: '<Root>/xhat' */
    rtY.xhat[i] = rtDW.s.x_[i];
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function1' */
}

/* Model initialize function */
void AEKF_initialize(void)
{
  /* Start for DataStoreMemory: '<S1>/Data Store Memory' */
  rtDW.s = rtConstP.DataStoreMemory_InitialValue;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
