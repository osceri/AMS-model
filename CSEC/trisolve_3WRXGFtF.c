/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: trisolve_3WRXGFtF.c
 *
 * Code generated for Simulink model 'cellStateEstimator'.
 *
 * Model version                  : 1.74
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Mar 14 20:45:31 2022
 */

#include "rtwtypes.h"
#include "trisolve_3WRXGFtF.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void trisolve_3WRXGFtF(real_T A, real_T B_0[2])
{
  if (B_0[0] != 0.0) {
    B_0[0] /= A;
  }

  if (B_0[1] != 0.0) {
    B_0[1] /= A;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
