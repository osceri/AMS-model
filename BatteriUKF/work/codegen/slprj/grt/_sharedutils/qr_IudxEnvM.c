/*
 * qr_IudxEnvM.c
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
#include <math.h>
#include "rt_hypotd_snf.h"
#include "xnrm2_hoYimUM0.h"
#include "qr_IudxEnvM.h"

/* Function for MATLAB Function: '<S4>/Correct' */
void qr_IudxEnvM(const real_T A[2], real_T Q[2], real_T *R)
{
  real_T c_A[2];
  real_T tau;
  real_T xnorm;
  int32_T c_k;
  int32_T knt;
  c_A[0] = A[0];
  c_A[1] = A[1];
  *R = A[0];
  tau = 0.0;
  xnorm = xnrm2_hoYimUM0(1, A, 2);
  if (xnorm != 0.0) {
    xnorm = rt_hypotd_snf(A[0], xnorm);
    if (A[0] >= 0.0) {
      xnorm = -xnorm;
    }

    if (fabs(xnorm) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        c_A[1] *= 9.9792015476736E+291;
        xnorm *= 9.9792015476736E+291;
        *R *= 9.9792015476736E+291;
      } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

      xnorm = rt_hypotd_snf(*R, xnrm2_hoYimUM0(1, c_A, 2));
      if (*R >= 0.0) {
        xnorm = -xnorm;
      }

      tau = (xnorm - *R) / xnorm;
      c_A[1] *= 1.0 / (*R - xnorm);
      for (c_k = 0; c_k <= knt; c_k++) {
        xnorm *= 1.0020841800044864E-292;
      }

      *R = xnorm;
    } else {
      tau = (xnorm - A[0]) / xnorm;
      c_A[1] = 1.0 / (A[0] - xnorm) * A[1];
      *R = xnorm;
    }
  }

  Q[0] = 1.0 - tau;
  Q[1] = -tau * c_A[1];
}
