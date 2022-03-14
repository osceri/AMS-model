/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: xswap_m0ShlcLK.c
 *
 * Code generated for Simulink model 'Main'.
 *
 * Model version                  : 1.71
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Mar 14 17:16:16 2022
 */

#include "rtwtypes.h"
#include "xswap_m0ShlcLK.h"

/* Function for MATLAB Function: '<S15>/Correct' */
void xswap_m0ShlcLK(real_T x[4], int32_T ix0, int32_T iy0)
{
  real_T temp;
  temp = x[ix0 - 1];
  x[ix0 - 1] = x[iy0 - 1];
  x[iy0 - 1] = temp;
  temp = x[ix0];
  x[ix0] = x[iy0];
  x[iy0] = temp;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
