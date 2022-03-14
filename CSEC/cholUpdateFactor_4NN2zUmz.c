/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: cholUpdateFactor_4NN2zUmz.c
 *
 * Code generated for Simulink model 'cellStateEstimator'.
 *
 * Model version                  : 1.74
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Mar 14 20:45:31 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include "rotate_YgpoDwi7.h"
#include "cholUpdateFactor_4NN2zUmz.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void cholUpdateFactor_4NN2zUmz(real_T *S, real_T U)
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
      R *= *S;
    }
  }

  *S = R;
  if (p != 0) {
    temp = R * R - U * U;
    nrmx = 1.0;
    if (temp != 0.0) {
      temp = fabs(temp);
    }

    if (temp < 0.0) {
      temp = -temp;
      nrmx = -1.0;
    }

    *S = nrmx * sqrt(temp);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
