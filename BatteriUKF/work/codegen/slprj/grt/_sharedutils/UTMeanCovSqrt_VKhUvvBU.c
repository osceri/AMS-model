/*
 * UTMeanCovSqrt_VKhUvvBU.c
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
 * Created for block: Main
 */

#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "qr_IudxEnvM.h"
#include "rotate_YgpoDwi7.h"
#include "UTMeanCovSqrt_VKhUvvBU.h"

/* Function for MATLAB Function: '<S5>/Predict' */
void UTMeanCovSqrt_VKhUvvBU(const real_T meanWeights[2], const real_T
  covWeights[2], real_T OOM, real_T Y1, const real_T Y2[2], real_T X1, const
  real_T X2[2], real_T *Ymean, real_T *Sy, real_T *Pxy)
{
  real_T W2_0[2];
  real_T a__1[2];
  real_T W2;
  real_T Y2_0;
  real_T Y2_tmp;
  real_T alpha;
  real_T b;
  real_T b_s;
  real_T c;
  real_T covWeights_0;
  real_T nrmx;
  real_T signOOM;
  boolean_T guard1 = false;
  *Ymean = ((Y1 * meanWeights[0] + Y2[0] * meanWeights[1]) + Y2[1] *
            meanWeights[1]) * OOM;
  Y1 -= *Ymean;
  if (OOM < 0.0) {
    signOOM = -1.0;
  } else if (OOM > 0.0) {
    signOOM = 1.0;
  } else if (OOM == 0.0) {
    signOOM = 0.0;
  } else {
    signOOM = (rtNaN);
  }

  Y2_tmp = Y2[0] - *Ymean;
  nrmx = signOOM * covWeights[0];
  Y2_0 = Y2[1] - *Ymean;
  covWeights_0 = signOOM * covWeights[1];
  OOM *= signOOM;
  signOOM = sqrt(OOM);
  W2 = sqrt(covWeights_0);
  W2_0[0] = W2 * Y2_tmp;
  W2_0[1] = W2 * Y2_0;
  qr_IudxEnvM(W2_0, a__1, &b_s);
  if (nrmx < 0.0) {
    nrmx = -1.0;
  } else if (nrmx > 0.0) {
    nrmx = 1.0;
  } else if (nrmx == 0.0) {
    nrmx = 0.0;
  } else {
    nrmx = (rtNaN);
  }

  if (nrmx == 1.0) {
    rotate_YgpoDwi7(b_s, Y1, &W2, &nrmx, &b);
    *Sy = signOOM * b;
  } else {
    guard1 = false;
    if (b_s == 0.0) {
      guard1 = true;
    } else {
      W2 = Y1 / b_s;
      nrmx = fabs(W2);
      if (nrmx >= 1.0) {
        guard1 = true;
      } else {
        rotate_YgpoDwi7(sqrt(1.0 - nrmx * nrmx), W2, &b, &c, &alpha);
        b_s = b * b_s - c * 0.0;
      }
    }

    if (guard1) {
      b_s = b_s * b_s - Y1 * Y1;
      if ((!rtIsInf(b_s)) && (!rtIsNaN(b_s))) {
        W2 = 1.0;
        if (b_s != 0.0) {
          b_s = fabs(b_s);
        }
      } else {
        b_s = (rtNaN);
        W2 = (rtNaN);
      }

      b_s = W2 * sqrt(b_s);
    }

    *Sy = signOOM * b_s;
  }

  *Pxy = ((X2[0] - X1) * Y2_tmp + (X2[1] - X1) * Y2_0) * (covWeights_0 * OOM);
}
