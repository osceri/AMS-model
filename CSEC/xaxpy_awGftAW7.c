/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: xaxpy_awGftAW7.c
 *
 * Code generated for Simulink model 'cellStateEstimator'.
 *
 * Model version                  : 1.74
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Mar 14 20:45:31 2022
 */

#include "rtwtypes.h"
#include "xaxpy_awGftAW7.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void xaxpy_awGftAW7(real_T a, real_T y[4])
{
  if (a != 0.0) {
    y[2] += a * y[0];
    y[3] += a * y[1];
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
