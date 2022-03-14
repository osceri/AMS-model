/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: qr_KQupoFeg.c
 *
 * Code generated for Simulink model 'cellStateEstimator'.
 *
 * Model version                  : 1.74
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Mar 14 20:45:31 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "rt_hypotd.h"
#include "xgemv_Zzn7jOKN.h"
#include "xgerc_ndvvueXd.h"
#include "xnrm2_nysWLBvB.h"
#include "qr_KQupoFeg.h"

/* Function for MATLAB Function: '<S6>/Predict' */
void qr_KQupoFeg(const real_T A[8], real_T Q[8], real_T R[4])
{
  real_T b_A[8];
  real_T work[2];
  real_T atmp;
  real_T beta1;
  real_T tau_idx_0;
  real_T tau_idx_1;
  int32_T b_ia;
  int32_T c_lastc;
  int32_T exitg1;
  int32_T knt;
  tau_idx_0 = 0.0;
  tau_idx_1 = 0.0;
  memcpy(&b_A[0], &A[0], sizeof(real_T) << 3U);
  work[0] = 0.0;
  work[1] = 0.0;
  atmp = b_A[0];
  beta1 = xnrm2_nysWLBvB(3, b_A, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd(b_A[0], beta1);
    if (b_A[0] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        for (c_lastc = 1; c_lastc < 4; c_lastc++) {
          b_A[c_lastc] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        atmp *= 9.9792015476736E+291;
      } while (fabs(beta1) < 1.0020841800044864E-292);

      beta1 = rt_hypotd(atmp, xnrm2_nysWLBvB(3, b_A, 2));
      if (atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - atmp) / beta1;
      atmp = 1.0 / (atmp - beta1);
      for (c_lastc = 1; c_lastc < 4; c_lastc++) {
        b_A[c_lastc] *= atmp;
      }

      for (c_lastc = 0; c_lastc <= knt; c_lastc++) {
        beta1 *= 1.0020841800044864E-292;
      }

      atmp = beta1;
    } else {
      tau_idx_0 = (beta1 - b_A[0]) / beta1;
      atmp = 1.0 / (b_A[0] - beta1);
      for (knt = 1; knt < 4; knt++) {
        b_A[knt] *= atmp;
      }

      atmp = beta1;
    }
  }

  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 4;
    c_lastc = 3;
    while ((knt > 0) && (b_A[c_lastc] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 1;
    b_ia = 0;
    do {
      exitg1 = 0;
      if (b_ia + 5 <= knt + 4) {
        if (b_A[b_ia + 4] != 0.0) {
          exitg1 = 1;
        } else {
          b_ia++;
        }
      } else {
        c_lastc = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    knt = 0;
    c_lastc = 0;
  }

  if (knt > 0) {
    xgemv_Zzn7jOKN(knt, c_lastc, b_A, 5, b_A, 1, work);
    xgerc_ndvvueXd(knt, c_lastc, -tau_idx_0, 1, work, b_A, 5);
  }

  b_A[0] = atmp;
  atmp = b_A[5];
  beta1 = xnrm2_nysWLBvB(2, b_A, 7);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd(b_A[5], beta1);
    if (b_A[5] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        for (c_lastc = 6; c_lastc < 8; c_lastc++) {
          b_A[c_lastc] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        atmp *= 9.9792015476736E+291;
      } while (fabs(beta1) < 1.0020841800044864E-292);

      beta1 = rt_hypotd(atmp, xnrm2_nysWLBvB(2, b_A, 7));
      if (atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_1 = (beta1 - atmp) / beta1;
      atmp = 1.0 / (atmp - beta1);
      for (c_lastc = 6; c_lastc < 8; c_lastc++) {
        b_A[c_lastc] *= atmp;
      }

      for (c_lastc = 0; c_lastc <= knt; c_lastc++) {
        beta1 *= 1.0020841800044864E-292;
      }

      atmp = beta1;
    } else {
      tau_idx_1 = (beta1 - b_A[5]) / beta1;
      atmp = 1.0 / (b_A[5] - beta1);
      for (knt = 6; knt < 8; knt++) {
        b_A[knt] *= atmp;
      }

      atmp = beta1;
    }
  }

  b_A[5] = atmp;
  R[0] = b_A[0];
  R[1] = 0.0;
  work[0] = 0.0;
  for (knt = 0; knt < 2; knt++) {
    R[knt + 2] = b_A[knt + 4];
  }

  work[1] = 0.0;
  for (knt = 6; knt < 8; knt++) {
    b_A[knt] *= -tau_idx_1;
  }

  b_A[5] = 1.0 - tau_idx_1;
  b_A[4] = 0.0;
  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 4;
    c_lastc = 5;
    while ((knt > 0) && (b_A[c_lastc - 2] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 1;
    b_ia = 5;
    do {
      exitg1 = 0;
      if (b_ia <= knt + 4) {
        if (b_A[b_ia - 1] != 0.0) {
          exitg1 = 1;
        } else {
          b_ia++;
        }
      } else {
        c_lastc = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    knt = 0;
    c_lastc = 0;
  }

  if (knt > 0) {
    xgemv_Zzn7jOKN(knt, c_lastc, b_A, 5, b_A, 1, work);
    xgerc_ndvvueXd(knt, c_lastc, -tau_idx_0, 1, work, b_A, 5);
  }

  for (knt = 1; knt < 4; knt++) {
    b_A[knt] *= -tau_idx_0;
  }

  b_A[0] = 1.0 - tau_idx_0;
  for (knt = 0; knt < 2; knt++) {
    c_lastc = knt << 2;
    Q[c_lastc] = b_A[c_lastc];
    Q[c_lastc + 1] = b_A[c_lastc + 1];
    Q[c_lastc + 2] = b_A[c_lastc + 2];
    Q[c_lastc + 3] = b_A[c_lastc + 3];
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
