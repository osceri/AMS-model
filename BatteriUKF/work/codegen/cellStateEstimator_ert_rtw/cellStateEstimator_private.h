/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: cellStateEstimator_private.h
 *
 * Code generated for Simulink model 'cellStateEstimator'.
 *
 * Model version                  : 1.61
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Mar 13 19:14:07 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_cellStateEstimator_private_h_
#define RTW_HEADER_cellStateEstimator_private_h_
#include "rtwtypes.h"
#include "cellStateEstimator.h"

extern void cellStateEstimator_Rs(real_T rtu_z, real_T *rty_Rs);
extern void cellStateEstima_batteryStateFcn(const real_T rtu_x[2], real_T
  rty_x_next[2]);
extern void cellState_batteryMeasurementFcn(const real_T rtu_x[2], real_T *rty_y);

#endif                            /* RTW_HEADER_cellStateEstimator_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
