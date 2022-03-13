/*
 * xnrm2_hoYimUM0.c
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
#include "xnrm2_hoYimUM0.h"

/* Function for MATLAB Function: '<S4>/Correct' */
real_T xnrm2_hoYimUM0(int32_T n, const real_T x[2], int32_T ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}
