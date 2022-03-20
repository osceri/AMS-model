/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem_types.h
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.562
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Mar 20 23:25:26 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Subsystem_types_h_
#define RTW_HEADER_Subsystem_types_h_
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
#endif                                 /* RTW_HEADER_Subsystem_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
