/*
 * trisolve_r4j0Li0a.c
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
 * Created for block: Main
 */

#include "rtwtypes.h"
#include "trisolve_r4j0Li0a.h"

/* Function for MATLAB Function: '<S4>/Correct' */
void trisolve_r4j0Li0a(real_T A, real_T *B)
{
  if (*B != 0.0) {
    *B /= A;
  }
}
