/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: xdotc_9HS6GBPS.c
 *
 * Code generated for Simulink model 'cellStateEstimator'.
 *
 * Model version                  : 1.74
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Mar 14 20:45:31 2022
 */

#include "rtwtypes.h"
#include "xdotc_9HS6GBPS.h"

/* Function for MATLAB Function: '<S5>/Correct' */
real_T xdotc_9HS6GBPS(const real_T x[4], const real_T y[4])
{
  return x[0] * y[2] + x[1] * y[3];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
