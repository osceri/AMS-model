/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: xscal_rjqkBhIF.c
 *
 * Code generated for Simulink model 'Main'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Mar 13 13:17:04 2022
 */

#include "rtwtypes.h"
#include "xscal_rjqkBhIF.h"

/* Function for MATLAB Function: '<S4>/Correct' */
void xscal_rjqkBhIF(real_T a, real_T x[4], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 1; k++) {
    x[k - 1] *= a;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
