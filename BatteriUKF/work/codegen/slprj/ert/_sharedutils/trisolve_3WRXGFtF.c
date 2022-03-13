/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: trisolve_3WRXGFtF.c
 *
 * Code generated for Simulink model 'Main'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Mar 13 13:17:04 2022
 */

#include "rtwtypes.h"
#include "trisolve_3WRXGFtF.h"

/* Function for MATLAB Function: '<S4>/Correct' */
void trisolve_3WRXGFtF(real_T A, real_T B[2])
{
  if (B[0] != 0.0) {
    B[0] /= A;
  }

  if (B[1] != 0.0) {
    B[1] /= A;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
