/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: cholUpdateFactor_2sWnptMU.c
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
    nrmx = R * R - U * U;
    if ((!rtIsInf(nrmx)) && (!rtIsNaN(nrmx))) {
      temp = 1.0;
      if (nrmx != 0.0) {
        nrmx = fabs(nrmx);
      }

      if (nrmx < 0.0) {
        nrmx = -nrmx;
        temp = -1.0;
      }
    } else {
      nrmx = (rtNaN);
      temp = (rtNaN);
    }

    *S = temp * sqrt(nrmx);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
