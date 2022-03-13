/*
 * rotate_YgpoDwi7.c
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
#include <math.h>
#include "rt_hypotd_snf.h"
#include "rotate_YgpoDwi7.h"

/* Function for MATLAB Function: '<S4>/Correct' */
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
    rho = rt_hypotd_snf(absx, fabs(yy));
    *c = absx / rho;
    xx /= absx;
    *s = xx * yy / rho;
    *r = rho * t * xx;
  }
}
