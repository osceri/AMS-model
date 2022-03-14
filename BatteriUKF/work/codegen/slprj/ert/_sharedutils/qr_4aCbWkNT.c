/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: qr_4aCbWkNT.c
 *
 * Code generated for Simulink model 'Main'.
 *
 * Model version                  : 1.71
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Mar 14 17:16:16 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_hypotd.h"
#include "xgemv_XwGam4Tu.h"
#include "xgerc_VszxCftQ.h"
#include "xnrm2_CJ11MXKb.h"
#include "qr_4aCbWkNT.h"

/* Function for MATLAB Function: '<S15>/Correct' */
void qr_4aCbWkNT(const real_T A[4], real_T Q[4], real_T R[4])
{
  real_T b_A[4];
  real_T work[2];
  real_T atmp;
  real_T b;
  real_T beta1;
  int32_T b_ia;
  int32_T c_lastc;
  int32_T exitg1;
  int32_T knt;
  b_A[0] = A[0];
  b_A[1] = A[1];
  b_A[2] = A[2];
  b_A[3] = A[3];
  work[0] = 0.0;
  work[1] = 0.0;
  atmp = A[0];
  b = 0.0;
  beta1 = xnrm2_CJ11MXKb(1, b_A, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd(A[0], beta1);
    if (A[0] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        for (c_lastc = 1; c_lastc < 2; c_lastc++) {
          b_A[c_lastc] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        atmp *= 9.9792015476736E+291;
      } while (fabs(beta1) < 1.0020841800044864E-292);

      beta1 = rt_hypotd(atmp, xnrm2_CJ11MXKb(1, b_A, 2));
      if (atmp >= 0.0) {
        beta1 = -beta1;
      }

      b = (beta1 - atmp) / beta1;
      atmp = 1.0 / (atmp - beta1);
      for (c_lastc = 1; c_lastc < 2; c_lastc++) {
        b_A[c_lastc] *= atmp;
      }

      for (c_lastc = 0; c_lastc <= knt; c_lastc++) {
        beta1 *= 1.0020841800044864E-292;
      }

      atmp = beta1;
    } else {
      b = (beta1 - A[0]) / beta1;
      atmp = 1.0 / (A[0] - beta1);
      for (knt = 1; knt < 2; knt++) {
        b_A[knt] *= atmp;
      }

      atmp = beta1;
    }
  }

  b_A[0] = 1.0;
  if (b != 0.0) {
    knt = 2;
    c_lastc = 1;
    while ((knt > 0) && (b_A[c_lastc] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 1;
    b_ia = 0;
    do {
      exitg1 = 0;
      if (b_ia + 3 <= knt + 2) {
        if (b_A[b_ia + 2] != 0.0) {
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
    xgemv_XwGam4Tu(knt, c_lastc, b_A, 3, b_A, 1, work);
    xgerc_VszxCftQ(knt, c_lastc, -b, 1, work, b_A, 3);
  }

  b_A[0] = atmp;
  R[0] = atmp;
  R[1] = 0.0;
  work[0] = 0.0;
  for (knt = 0; knt < 2; knt++) {
    R[knt + 2] = b_A[knt + 2];
  }

  work[1] = 0.0;
  b_A[3] = 1.0;
  b_A[2] = 0.0;
  b_A[0] = 1.0;
  if (b != 0.0) {
    knt = 2;
    c_lastc = 1;
    while ((knt > 0) && (b_A[c_lastc] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 1;
    b_ia = 1;
    do {
      exitg1 = 0;
      if (b_ia + 2 <= knt + 2) {
        if (b_A[b_ia + 1] != 0.0) {
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
    xgemv_XwGam4Tu(knt, c_lastc, b_A, 3, b_A, 1, work);
    xgerc_VszxCftQ(knt, c_lastc, -b, 1, work, b_A, 3);
  }

  for (knt = 1; knt < 2; knt++) {
    b_A[knt] *= -b;
  }

  Q[0] = 1.0 - b;
  Q[1] = b_A[1];
  Q[2] = b_A[2];
  Q[3] = b_A[3];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
