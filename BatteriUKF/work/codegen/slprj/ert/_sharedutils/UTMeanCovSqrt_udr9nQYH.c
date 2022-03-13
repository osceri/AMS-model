/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: UTMeanCovSqrt_udr9nQYH.c
 *
 * Code generated for Simulink model 'Main'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Mar 13 13:17:04 2022
 */

#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "cholUpdateFactor_2sWnptMU.h"
#include "rotate_YgpoDwi7.h"
#include "rt_hypotd_snf.h"
#include "xnrm2_CJ11MXKb.h"
#include "UTMeanCovSqrt_udr9nQYH.h"

/* Function for MATLAB Function: '<S4>/Correct' */
void UTMeanCovSqrt_udr9nQYH(const real_T meanWeights[2], const real_T
  covWeights[2], real_T OOM, real_T Y1, const real_T Y2[4], const real_T X1[2],
  real_T X2[8], real_T *Ymean, real_T *Sy, real_T Pxy[2])
{
  real_T A[4];
  real_T S;
  real_T Y2_tmp;
  real_T Y2_tmp_0;
  real_T Y2_tmp_1;
  real_T Y2_tmp_2;
  real_T covWeights_0;
  real_T covWeights_1;
  real_T signOOM;
  real_T xnorm;
  int32_T b_k;
  int32_T knt;
  *Ymean = ((((Y1 * meanWeights[0] + Y2[0] * meanWeights[1]) + Y2[1] *
              meanWeights[1]) + meanWeights[1] * Y2[2]) + meanWeights[1] * Y2[3])
    * OOM;
  Y1 -= *Ymean;
  Y2_tmp = Y2[0] - *Ymean;
  Y2_tmp_0 = Y2[1] - *Ymean;
  Y2_tmp_1 = Y2[2] - *Ymean;
  Y2_tmp_2 = Y2[3] - *Ymean;
  if (OOM < 0.0) {
    signOOM = -1.0;
  } else if (OOM > 0.0) {
    signOOM = 1.0;
  } else if (OOM == 0.0) {
    signOOM = 0.0;
  } else {
    signOOM = (rtNaN);
  }

  covWeights_0 = signOOM * covWeights[0];
  covWeights_1 = signOOM * covWeights[1];
  OOM *= signOOM;
  signOOM = sqrt(covWeights_1);
  A[0] = signOOM * Y2_tmp;
  A[1] = signOOM * Y2_tmp_0;
  A[2] = signOOM * Y2_tmp_1;
  A[3] = signOOM * Y2_tmp_2;
  signOOM = A[0];
  xnorm = xnrm2_CJ11MXKb(3, A, 2);
  if (xnorm != 0.0) {
    xnorm = rt_hypotd_snf(A[0], xnorm);
    if (A[0] >= 0.0) {
      xnorm = -xnorm;
    }

    if (fabs(xnorm) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        for (b_k = 1; b_k < 4; b_k++) {
          A[b_k] *= 9.9792015476736E+291;
        }

        xnorm *= 9.9792015476736E+291;
        signOOM *= 9.9792015476736E+291;
      } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

      xnorm = rt_hypotd_snf(signOOM, xnrm2_CJ11MXKb(3, A, 2));
      if (signOOM >= 0.0) {
        xnorm = -xnorm;
      }

      for (b_k = 0; b_k <= knt; b_k++) {
        xnorm *= 1.0020841800044864E-292;
      }

      signOOM = xnorm;
    } else {
      signOOM = xnorm;
    }
  }

  if (covWeights_0 < 0.0) {
    covWeights_0 = -1.0;
  } else if (covWeights_0 > 0.0) {
    covWeights_0 = 1.0;
  } else if (covWeights_0 == 0.0) {
    covWeights_0 = 0.0;
  } else {
    covWeights_0 = (rtNaN);
  }

  if (covWeights_0 == 1.0) {
    rotate_YgpoDwi7(signOOM, Y1, &covWeights_0, &xnorm, &S);
    *Sy = sqrt(OOM) * S;
  } else {
    cholUpdateFactor_2sWnptMU(&signOOM, Y1);
    *Sy = sqrt(OOM) * signOOM;
  }

  for (knt = 0; knt < 4; knt++) {
    b_k = knt << 1;
    X2[b_k] -= X1[0];
    X2[b_k + 1] -= X1[1];
  }

  covWeights_1 *= OOM;
  for (knt = 0; knt < 2; knt++) {
    Pxy[knt] = (X2[knt + 6] * Y2_tmp_2 + (X2[knt + 4] * Y2_tmp_1 + (X2[knt + 2] *
      Y2_tmp_0 + X2[knt] * Y2_tmp))) * covWeights_1;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
