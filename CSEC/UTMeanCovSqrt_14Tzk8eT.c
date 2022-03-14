/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: UTMeanCovSqrt_14Tzk8eT.c
 *
 * Code generated for Simulink model 'cellStateEstimator'.
 *
 * Model version                  : 1.74
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Mar 14 20:45:31 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include "qr_4aCbWkNT.h"
#include "qr_KQupoFeg.h"
#include "rotate_YgpoDwi7.h"
#include "svd_ITQaouod.h"
#include "UTMeanCovSqrt_14Tzk8eT.h"

/* Function for MATLAB Function: '<S6>/Predict' */
void UTMeanCovSqrt_14Tzk8eT(const real_T meanWeights[2], const real_T
  covWeights[2], real_T OOM, real_T Y1[2], real_T Y2[8], const real_T X1[2],
  real_T X2[8], real_T Ymean[2], real_T Sy[4], real_T Pxy[4])
{
  real_T W2_0[8];
  real_T a__1[8];
  real_T Ss[4];
  real_T Y1_0[4];
  real_T c[2];
  real_T s[2];
  real_T W2;
  real_T Ymean_0;
  real_T absxk;
  real_T alpha;
  real_T b_t;
  real_T covWeights_0;
  real_T nrmx;
  real_T scale;
  real_T signOOM;
  real_T t;
  int32_T Ymean_tmp;
  int32_T exitg1;
  int32_T i;
  int32_T kk;
  boolean_T Sy_0;
  boolean_T exitg2;
  boolean_T guard1 = false;
  Ymean[0] = Y1[0] * meanWeights[0];
  Ymean[1] = meanWeights[0] * Y1[1];
  for (kk = 0; kk < 4; kk++) {
    Ymean_tmp = kk << 1;
    Ymean[0] += Y2[Ymean_tmp] * meanWeights[1];
    Ymean[1] += Y2[Ymean_tmp + 1] * meanWeights[1];
  }

  Ymean_0 = Ymean[0] * OOM;
  t = Y1[0] - Ymean_0;
  Ymean[0] = Ymean_0;
  Y1[0] = t;
  Ymean_0 = Ymean[1] * OOM;
  alpha = Y1[1] - Ymean_0;
  Ymean[1] = Ymean_0;
  Y1[1] = alpha;
  for (kk = 0; kk < 4; kk++) {
    Ymean_tmp = kk << 1;
    Y2[Ymean_tmp] -= Ymean[0];
    Y2[Ymean_tmp + 1] -= Ymean_0;
  }

  if (OOM < 0.0) {
    signOOM = -1.0;
  } else if (OOM > 0.0) {
    signOOM = 1.0;
  } else {
    signOOM = OOM;
  }

  covWeights_0 = signOOM * covWeights[0];
  Ymean_0 = signOOM * covWeights[1];
  OOM *= signOOM;
  signOOM = sqrt(OOM);
  W2 = sqrt(Ymean_0);
  for (kk = 0; kk < 2; kk++) {
    Ymean_tmp = kk << 2;
    W2_0[Ymean_tmp] = W2 * Y2[kk];
    W2_0[Ymean_tmp + 1] = Y2[kk + 2] * W2;
    W2_0[Ymean_tmp + 2] = Y2[kk + 4] * W2;
    W2_0[Ymean_tmp + 3] = Y2[kk + 6] * W2;
  }

  qr_KQupoFeg(W2_0, a__1, Sy);
  if (covWeights_0 < 0.0) {
    covWeights_0 = -1.0;
  } else if (covWeights_0 > 0.0) {
    covWeights_0 = 1.0;
  }

  if (covWeights_0 == 1.0) {
    rotate_YgpoDwi7(Sy[0], t, &covWeights_0, &W2, &Sy[0]);
    t = covWeights_0 * alpha - W2 * Sy[2];
    Sy[2] = covWeights_0 * Sy[2] + W2 * alpha;
    rotate_YgpoDwi7(Sy[3], t, &alpha, &covWeights_0, &Sy[3]);
    alpha = Sy[0];
    t = Sy[2];
    W2 = Sy[3];
    Sy[0] = signOOM * alpha;
    Sy[1] = signOOM * t;
    Sy[2] = 0.0;
    Sy[3] = signOOM * W2;
  } else {
    Sy[1] = 0.0;
    if (Sy[0] == 0.0) {
      Sy_0 = true;
    } else {
      Sy_0 = (Sy[3] == 0.0);
    }

    guard1 = false;
    if (Sy_0) {
      guard1 = true;
    } else {
      scale = 3.3121686421112381E-170;
      W2 = t / Sy[0];
      absxk = fabs(W2);
      if (absxk > 3.3121686421112381E-170) {
        nrmx = 1.0;
        scale = absxk;
      } else {
        b_t = absxk / 3.3121686421112381E-170;
        nrmx = b_t * b_t;
      }

      covWeights_0 = (alpha - Sy[2] * W2) / Sy[3];
      absxk = fabs(covWeights_0);
      if (absxk > scale) {
        b_t = scale / absxk;
        nrmx = nrmx * b_t * b_t + 1.0;
        scale = absxk;
      } else {
        b_t = absxk / scale;
        nrmx += b_t * b_t;
      }

      nrmx = scale * sqrt(nrmx);
      if (nrmx >= 1.0) {
        guard1 = true;
      } else {
        rotate_YgpoDwi7(sqrt(1.0 - nrmx * nrmx), covWeights_0, &c[1], &s[1],
                        &alpha);
        covWeights_0 = 0.0;
        rotate_YgpoDwi7(alpha, W2, &c[0], &s[0], &alpha);
        W2 = 0.0;
        for (kk = 0; kk + 1 > 0; kk--) {
          alpha = s[kk] * Sy[kk];
          Sy[kk] = c[kk] * Sy[kk] - s[kk] * W2;
          W2 = c[kk] * W2 + alpha;
        }

        for (kk = 1; kk + 1 > 0; kk--) {
          alpha = Sy[kk + 2];
          Sy[kk + 2] = alpha * c[kk] - s[kk] * covWeights_0;
          covWeights_0 = c[kk] * covWeights_0 + alpha * s[kk];
        }
      }
    }

    if (guard1) {
      for (kk = 0; kk < 2; kk++) {
        W2 = Y1[kk];
        Ss[kk] = 0.0;
        Ymean_tmp = kk << 1;
        covWeights_0 = Sy[Ymean_tmp];
        Ss[kk] += covWeights_0 * Sy[0];
        Y1_0[Ymean_tmp] = t * W2;
        Ss[kk + 2] = 0.0;
        Ss[kk + 2] += covWeights_0 * Sy[2];
        Ss[kk + 2] += Sy[Ymean_tmp + 1] * Sy[3];
        Y1_0[Ymean_tmp + 1] = alpha * W2;
      }

      Sy[0] = Ss[0] - Y1_0[0];
      Sy[1] = Ss[1] - Y1_0[1];
      Sy[2] = Ss[2] - Y1_0[2];
      Sy[3] = Ss[3] - Y1_0[3];
      svd_ITQaouod(Sy, Ss, s, Y1_0);
      Ss[0] = sqrt(s[0]);
      Ss[1] = 0.0;
      Ss[2] = 0.0;
      Ss[3] = sqrt(s[1]);
      for (kk = 0; kk < 2; kk++) {
        Sy[kk] = 0.0;
        Ymean_tmp = kk << 1;
        covWeights_0 = Ss[Ymean_tmp];
        Sy[kk] += covWeights_0 * Y1_0[0];
        alpha = Ss[Ymean_tmp + 1];
        Sy[kk] += alpha * Y1_0[2];
        Sy[kk + 2] = 0.0;
        Sy[kk + 2] += covWeights_0 * Y1_0[1];
        Sy[kk + 2] += alpha * Y1_0[3];
      }

      Sy_0 = true;
      kk = 0;
      exitg2 = false;
      while ((!exitg2) && (kk < 2)) {
        Ymean_tmp = kk + 2;
        do {
          exitg1 = 0;
          if (Ymean_tmp < 3) {
            if (Sy[(kk << 1) + 1] != 0.0) {
              Sy_0 = false;
              exitg1 = 1;
            } else {
              Ymean_tmp = 3;
            }
          } else {
            kk++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      if (!Sy_0) {
        for (i = 0; i < 4; i++) {
          Y1_0[i] = Sy[i];
        }

        qr_4aCbWkNT(Y1_0, Ss, Sy);
      }
    }

    alpha = Sy[0];
    t = Sy[2];
    covWeights_0 = Sy[1];
    W2 = Sy[3];
    Sy[0] = signOOM * alpha;
    Sy[1] = signOOM * t;
    Sy[2] = signOOM * covWeights_0;
    Sy[3] = signOOM * W2;
  }

  for (kk = 0; kk < 4; kk++) {
    Ymean_tmp = kk << 1;
    X2[Ymean_tmp] -= X1[0];
    X2[Ymean_tmp + 1] -= X1[1];
  }

  Ymean_0 *= OOM;
  for (kk = 0; kk < 2; kk++) {
    for (i = 0; i < 2; i++) {
      Ymean_tmp = kk + (i << 1);
      Ss[Ymean_tmp] = 0.0;
      Ss[Ymean_tmp] += X2[kk] * Y2[i];
      Ss[Ymean_tmp] += X2[kk + 2] * Y2[i + 2];
      Ss[Ymean_tmp] += X2[kk + 4] * Y2[i + 4];
      Ss[Ymean_tmp] += X2[kk + 6] * Y2[i + 6];
    }
  }

  Pxy[0] = Ss[0] * Ymean_0;
  Pxy[1] = Ss[1] * Ymean_0;
  Pxy[2] = Ss[2] * Ymean_0;
  Pxy[3] = Ss[3] * Ymean_0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
