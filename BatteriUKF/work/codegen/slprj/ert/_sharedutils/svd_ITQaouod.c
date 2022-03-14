/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: svd_ITQaouod.c
 *
 * Code generated for Simulink model 'Main'.
 *
 * Model version                  : 1.71
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon Mar 14 17:16:16 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include "xaxpy_awGftAW7.h"
#include "xdotc_9HS6GBPS.h"
#include "xnrm2_23q6hs5C.h"
#include "xrot_Oh5iEeBQ.h"
#include "xrotg_3bzOSYJ0.h"
#include "xscal_rjqkBhIF.h"
#include "xscal_xOI1UZZc.h"
#include "xswap_m0ShlcLK.h"
#include "svd_ITQaouod.h"

/* Function for MATLAB Function: '<S15>/Correct' */
void svd_ITQaouod(const real_T A[4], real_T U[4], real_T s[2], real_T V[4])
{
  real_T b_A[4];
  real_T b_s[2];
  real_T e[2];
  real_T emm1;
  real_T nrm;
  real_T r;
  real_T rt;
  real_T shift;
  real_T smm1;
  real_T sqds;
  int32_T iter;
  int32_T kase;
  int32_T m;
  int32_T q;
  int32_T qs;
  boolean_T exitg1;
  b_A[0] = A[0];
  b_A[1] = A[1];
  b_A[2] = A[2];
  b_A[3] = A[3];
  nrm = xnrm2_23q6hs5C(A);
  if (nrm > 0.0) {
    if (A[0] < 0.0) {
      nrm = -nrm;
    }

    if (fabs(nrm) >= 1.0020841800044864E-292) {
      xscal_xOI1UZZc(1.0 / nrm, b_A);
    } else {
      b_A[0] = A[0] / nrm;
      b_A[1] = A[1] / nrm;
    }

    b_A[0]++;
    b_s[0] = -nrm;
    xaxpy_awGftAW7(-(xdotc_9HS6GBPS(b_A, b_A) / b_A[0]), b_A);
  } else {
    b_s[0] = 0.0;
  }

  m = 0;
  b_s[1] = b_A[3];
  e[1] = 0.0;
  U[0] = b_A[0];
  U[2] = 0.0;
  U[1] = b_A[1];
  U[3] = 1.0;
  if (b_s[0] != 0.0) {
    xaxpy_awGftAW7(-(xdotc_9HS6GBPS(U, U) / b_A[0]), U);
    U[1] = -U[1];
    U[0] = -U[0] + 1.0;
  } else {
    U[1] = 0.0;
    U[0] = 1.0;
  }

  V[2] = 0.0;
  V[3] = 1.0;
  V[1] = 0.0;
  V[0] = 1.0;
  nrm = b_A[2];
  if (b_s[0] != 0.0) {
    rt = fabs(b_s[0]);
    r = b_s[0] / rt;
    b_s[0] = rt;
    nrm = b_A[2] / r;
    xscal_rjqkBhIF(r, U, 1);
  }

  if (nrm != 0.0) {
    rt = fabs(nrm);
    r = rt / nrm;
    nrm = rt;
    b_s[1] = b_A[3] * r;
    xscal_rjqkBhIF(r, V, 3);
  }

  if (b_s[1] != 0.0) {
    rt = fabs(b_s[1]);
    r = b_s[1] / rt;
    b_s[1] = rt;
    xscal_rjqkBhIF(r, U, 3);
  }

  e[0] = nrm;
  iter = 0;
  nrm = fmax(fmax(b_s[0], nrm), fmax(b_s[1], 0.0));
  while ((m + 2 > 0) && (iter < 75)) {
    q = m + 1;
    exitg1 = false;
    while (!(exitg1 || (q == 0))) {
      rt = fabs(e[0]);
      if (rt <= (fabs(b_s[0]) + fabs(b_s[1])) * 2.2204460492503131E-16) {
        e[0] = 0.0;
        exitg1 = true;
      } else if ((rt <= 1.0020841800044864E-292) || ((iter > 20) && (rt <=
                   2.2204460492503131E-16 * nrm))) {
        e[0] = 0.0;
        exitg1 = true;
      } else {
        q = 0;
      }
    }

    if (m + 1 == q) {
      kase = 4;
    } else {
      qs = m + 2;
      kase = m + 2;
      exitg1 = false;
      while ((!exitg1) && (kase >= q)) {
        qs = kase;
        if (kase == q) {
          exitg1 = true;
        } else {
          rt = 0.0;
          if (kase < m + 2) {
            rt = fabs(e[kase - 1]);
          }

          if (kase > q + 1) {
            rt += fabs(e[0]);
          }

          r = fabs(b_s[kase - 1]);
          if ((r <= 2.2204460492503131E-16 * rt) || (r <=
               1.0020841800044864E-292)) {
            b_s[kase - 1] = 0.0;
            exitg1 = true;
          } else {
            kase--;
          }
        }
      }

      if (qs == q) {
        kase = 3;
      } else if (m + 2 == qs) {
        kase = 1;
      } else {
        kase = 2;
        q = qs;
      }
    }

    switch (kase) {
     case 1:
      rt = e[m];
      e[m] = 0.0;
      qs = m + 1;
      while (qs >= q + 1) {
        xrotg_3bzOSYJ0(&b_s[0], &rt, &r, &sqds);
        xrot_Oh5iEeBQ(V, 1, ((m + 1) << 1) + 1, r, sqds);
        qs = 0;
      }
      break;

     case 2:
      rt = e[q - 1];
      e[q - 1] = 0.0;
      for (qs = q; qs < m + 2; qs++) {
        xrotg_3bzOSYJ0(&b_s[qs], &rt, &r, &sqds);
        rt = -sqds * e[qs];
        e[qs] *= r;
        xrot_Oh5iEeBQ(U, (qs << 1) + 1, ((q - 1) << 1) + 1, r, sqds);
      }
      break;

     case 3:
      rt = b_s[m + 1];
      r = fmax(fmax(fmax(fmax(fabs(rt), fabs(b_s[m])), fabs(e[m])), fabs(b_s[q])),
               fabs(e[q]));
      rt /= r;
      smm1 = b_s[m] / r;
      emm1 = e[m] / r;
      sqds = b_s[q] / r;
      smm1 = ((smm1 + rt) * (smm1 - rt) + emm1 * emm1) / 2.0;
      emm1 *= rt;
      emm1 *= emm1;
      if ((smm1 != 0.0) || (emm1 != 0.0)) {
        shift = sqrt(smm1 * smm1 + emm1);
        if (smm1 < 0.0) {
          shift = -shift;
        }

        shift = emm1 / (smm1 + shift);
      } else {
        shift = 0.0;
      }

      rt = (sqds + rt) * (sqds - rt) + shift;
      r = e[q] / r * sqds;
      while (q + 1 <= m + 1) {
        xrotg_3bzOSYJ0(&rt, &r, &sqds, &smm1);
        rt = sqds * b_s[0] + smm1 * e[0];
        e[0] = sqds * e[0] - smm1 * b_s[0];
        r = smm1 * b_s[1];
        b_s[1] *= sqds;
        xrot_Oh5iEeBQ(V, 1, 3, sqds, smm1);
        xrotg_3bzOSYJ0(&rt, &r, &sqds, &smm1);
        b_s[0] = rt;
        rt = sqds * e[0] + smm1 * b_s[1];
        b_s[1] = -smm1 * e[0] + sqds * b_s[1];
        r = smm1 * e[1];
        e[1] *= sqds;
        xrot_Oh5iEeBQ(U, 1, 3, sqds, smm1);
        q = 1;
      }

      e[m] = rt;
      iter++;
      break;

     default:
      if (b_s[q] < 0.0) {
        b_s[q] = -b_s[q];
        xscal_rjqkBhIF(-1.0, V, (q << 1) + 1);
      }

      iter = q + 1;
      while ((q + 1 < 2) && (b_s[q] < b_s[iter])) {
        rt = b_s[q];
        b_s[q] = b_s[iter];
        b_s[iter] = rt;
        xswap_m0ShlcLK(V, (q << 1) + 1, ((q + 1) << 1) + 1);
        xswap_m0ShlcLK(U, (q << 1) + 1, ((q + 1) << 1) + 1);
        q = iter;
        iter++;
      }

      iter = 0;
      m--;
      break;
    }
  }

  s[0] = b_s[0];
  s[1] = b_s[1];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
