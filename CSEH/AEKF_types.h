/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AEKF_types.h
 *
 * Code generated for Simulink model 'AEKF'.
 *
 * Model version                  : 1.563
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Mar 20 23:41:42 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AEKF_types_h_
#define RTW_HEADER_AEKF_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_AF_state_
#define DEFINED_TYPEDEF_FOR_AF_state_

typedef struct {
  uint16_T Lx;
  uint16_T lx;
  real_T Ex[100];
  real_T Px_[4];
  real_T Px[4];
  real_T Qx[4];
  real_T Rx;
  real_T x_[2];
  real_T x[2];
  real_T p[4];
} AF_state;

#endif
#endif                                 /* RTW_HEADER_AEKF_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
