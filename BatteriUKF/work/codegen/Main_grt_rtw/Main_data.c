/*
 * Main_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Main".
 *
 * Model version              : 1.9
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Sat Mar 12 20:14:27 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Main.h"
#include "Main_private.h"

/* Block parameters (default storage) */
P_Main_T Main_P = {
  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: p.R{1}
   * Referenced by: '<S1>/R1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/MeasurementFcn1Inputs'
   */
  0.0,

  /* Expression: p.Q
   * Referenced by: '<S1>/Q'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/StateTransitionFcnInputs'
   */
  0.0,

  /* Expression: p.InitialCovariance
   * Referenced by: '<S1>/DataStoreMemory - P'
   */
  1.0,

  /* Expression: p.InitialState
   * Referenced by: '<S1>/DataStoreMemory - x'
   */
  0.0,

  /* Computed Parameter: yBlockOrdering_Y0
   * Referenced by: '<S4>/yBlockOrdering'
   */
  false,

  /* Expression: true()
   * Referenced by: '<S1>/BlockOrdering'
   */
  true,

  /* Expression: true()
   * Referenced by: '<S1>/Enable1'
   */
  true
};
