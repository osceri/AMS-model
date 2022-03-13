/*
 * cholUpdateFactor_2sWnptMU.c
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
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "rotate_YgpoDwi7.h"
#include "cholUpdateFactor_2sWnptMU.h"

/* Function for MATLAB Function: '<S4>/Correct' */
void cholUpdateFactor_2sWnptMU(real_T *S, real_T U)
{
  real_T R;
  real_T alpha;
  real_T c;
  real_T nrmx;
  real_T temp;
  int8_T p;
  R = *S;
  p = 0;
  if (*S == 0.0) {
    p = 2;
  } else {
    temp = U / *S;
    nrmx = fabs(temp);
    if (nrmx >= 1.0) {
      p = 1;
    } else {
      rotate_YgpoDwi7(sqrt(1.0 - nrmx * nrmx), temp, &R, &c, &alpha);
      R = R * *S - c * 0.0;
    }
  }

  *S = R;
  if (p != 0) {
    temp = R * R - U * U;
    if ((!rtIsInf(temp)) && (!rtIsNaN(temp))) {
      nrmx = 1.0;
      if (temp != 0.0) {
        temp = fabs(temp);
      }
    } else {
      temp = (rtNaN);
      nrmx = (rtNaN);
    }

    *S = nrmx * sqrt(temp);
  }
}
