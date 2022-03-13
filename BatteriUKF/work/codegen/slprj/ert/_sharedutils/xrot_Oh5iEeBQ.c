/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: xrot_Oh5iEeBQ.c
 *
 * Code generated for Simulink model 'Main'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Mar 13 13:17:04 2022
 */

#include "rtwtypes.h"
#include "xrot_Oh5iEeBQ.h"

/* Function for MATLAB Function: '<S4>/Correct' */
void xrot_Oh5iEeBQ(real_T x[4], int32_T ix0, int32_T iy0, real_T c, real_T s)
{
  real_T temp;
  real_T temp_tmp;
  temp = x[iy0 - 1];
  temp_tmp = x[ix0 - 1];
  x[iy0 - 1] = temp * c - temp_tmp * s;
  x[ix0 - 1] = temp_tmp * c + temp * s;
  temp = x[ix0] * c + x[iy0] * s;
  x[iy0] = x[iy0] * c - x[ix0] * s;
  x[ix0] = temp;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
