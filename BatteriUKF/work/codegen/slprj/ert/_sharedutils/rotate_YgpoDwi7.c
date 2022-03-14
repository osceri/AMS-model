/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rotate_YgpoDwi7.c
 *
 * Code generated for Simulink model 'Main'.
 *
 * Model version                  : 1.71
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Mar 14 17:16:16 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_hypotd.h"
#include "rotate_YgpoDwi7.h"

/* Function for MATLAB Function: '<S15>/Correct' */
void rotate_YgpoDwi7(real_T x, real_T y, real_T *c, real_T *s, real_T *r)
{
  real_T absx;
  real_T rho;
  real_T t;
  real_T xx;
  real_T yy;
  t = fabs(x);
  xx = fabs(y);
  if (xx == 0.0) {
    *c = 1.0;
    *s = 0.0;
    *r = x;
  } else if (t == 0.0) {
    *c = 0.0;
    *s = 1.0;
    *r = y;
  } else {
    t += xx;
    xx = x / t;
    yy = y / t;
    absx = fabs(xx);
    rho = rt_hypotd(absx, fabs(yy));
    *c = absx / rho;
    xx /= absx;
    *s = xx * yy / rho;
    *r = rho * t * xx;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
