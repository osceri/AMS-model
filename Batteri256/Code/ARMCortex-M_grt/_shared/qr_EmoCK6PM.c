#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "rt_hypotd_snf.h"
#include "xgemv_YUCucuUc.h"
#include "xgerc_gpDDvQUP.h"
#include "xnrm2_jjztiUbW.h"
#include "qr_EmoCK6PM.h"

void qr_EmoCK6PM(const real_T A[9], real_T Q[9], real_T R[9])
{
  real_T b_A[9];
  real_T work[3];
  real_T b_atmp;
  real_T beta1;
  real_T tau_idx_0;
  real_T tau_idx_1;
  int32_T b_coltop;
  int32_T c_lastc;
  int32_T coltop;
  int32_T exitg1;
  int32_T knt;
  boolean_T exitg2;
  tau_idx_0 = 0.0;
  tau_idx_1 = 0.0;
  memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  b_atmp = b_A[0];
  beta1 = xnrm2_jjztiUbW(2, b_A, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[0], beta1);
    if (b_A[0] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = -1;
      c_lastc = 0;
      do {
        knt++;
        for (b_coltop = 1; b_coltop < 3; b_coltop++) {
          b_A[b_coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        b_atmp *= 9.9792015476736E+291;
      } while (!(fabs(beta1) >= 1.0020841800044864E-292));

      beta1 = rt_hypotd_snf(b_atmp, xnrm2_jjztiUbW(2, b_A, 2));
      if (b_atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - b_atmp) / beta1;
      b_atmp = 1.0 / (b_atmp - beta1);
      for (b_coltop = 1; b_coltop < 3; b_coltop++) {
        b_A[b_coltop] *= b_atmp;
      }

      while (c_lastc <= knt) {
        beta1 *= 1.0020841800044864E-292;
        c_lastc++;
      }

      b_atmp = beta1;
    } else {
      tau_idx_0 = (beta1 - b_A[0]) / beta1;
      b_atmp = 1.0 / (b_A[0] - beta1);
      for (c_lastc = 1; c_lastc < 3; c_lastc++) {
        b_A[c_lastc] *= b_atmp;
      }

      b_atmp = beta1;
    }
  }

  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 3;
    c_lastc = 0;
    while ((knt > 0) && (b_A[c_lastc + 2] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 2;
    exitg2 = false;
    while ((!exitg2) && (c_lastc > 0)) {
      b_coltop = (c_lastc - 1) * 3 + 3;
      coltop = b_coltop;
      do {
        exitg1 = 0;
        if (coltop + 1 <= b_coltop + knt) {
          if (b_A[coltop] != 0.0) {
            exitg1 = 1;
          } else {
            coltop++;
          }
        } else {
          c_lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    knt = 0;
    c_lastc = 0;
  }

  if (knt > 0) {
    xgemv_YUCucuUc(knt, c_lastc, b_A, 4, b_A, 1, work);
    xgerc_gpDDvQUP(knt, c_lastc, -tau_idx_0, 1, work, b_A, 4);
  }

  b_A[0] = b_atmp;
  b_atmp = b_A[4];
  beta1 = xnrm2_jjztiUbW(1, b_A, 6);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[4], beta1);
    if (b_A[4] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        for (b_coltop = 5; b_coltop < 6; b_coltop++) {
          b_A[b_coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        b_atmp *= 9.9792015476736E+291;
      } while (!(fabs(beta1) >= 1.0020841800044864E-292));

      beta1 = rt_hypotd_snf(b_atmp, xnrm2_jjztiUbW(1, b_A, 6));
      if (b_atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_1 = (beta1 - b_atmp) / beta1;
      b_atmp = 1.0 / (b_atmp - beta1);
      for (b_coltop = 5; b_coltop < 6; b_coltop++) {
        b_A[b_coltop] *= b_atmp;
      }

      for (c_lastc = 0; c_lastc <= knt; c_lastc++) {
        beta1 *= 1.0020841800044864E-292;
      }

      b_atmp = beta1;
    } else {
      tau_idx_1 = (beta1 - b_A[4]) / beta1;
      b_atmp = 1.0 / (b_A[4] - beta1);
      for (c_lastc = 5; c_lastc < 6; c_lastc++) {
        b_A[c_lastc] *= b_atmp;
      }

      b_atmp = beta1;
    }
  }

  b_A[4] = 1.0;
  if (tau_idx_1 != 0.0) {
    knt = 2;
    c_lastc = 3;
    while ((knt > 0) && (b_A[c_lastc + 2] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 1;
    coltop = 7;
    do {
      exitg1 = 0;
      if (coltop + 1 <= 7 + knt) {
        if (b_A[coltop] != 0.0) {
          exitg1 = 1;
        } else {
          coltop++;
        }
      } else {
        c_lastc = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    knt = 0;
    c_lastc = 0;
  }

  if (knt > 0) {
    xgemv_YUCucuUc(knt, c_lastc, b_A, 8, b_A, 5, work);
    xgerc_gpDDvQUP(knt, c_lastc, -tau_idx_1, 5, work, b_A, 8);
  }

  b_A[4] = b_atmp;
  R[0] = b_A[0];
  for (c_lastc = 1; c_lastc + 1 < 4; c_lastc++) {
    R[c_lastc] = 0.0;
  }

  work[0] = 0.0;
  for (c_lastc = 0; c_lastc < 2; c_lastc++) {
    R[c_lastc + 3] = b_A[c_lastc + 3];
  }

  while (c_lastc + 1 < 4) {
    R[c_lastc + 3] = 0.0;
    c_lastc++;
  }

  work[1] = 0.0;
  for (c_lastc = 0; c_lastc < 3; c_lastc++) {
    R[c_lastc + 6] = b_A[c_lastc + 6];
  }

  work[2] = 0.0;
  b_A[8] = 1.0;
  for (c_lastc = 0; c_lastc < 2; c_lastc++) {
    b_A[7 - c_lastc] = 0.0;
  }

  b_A[4] = 1.0;
  if (tau_idx_1 != 0.0) {
    b_coltop = 7;
    while ((c_lastc > 0) && (b_A[b_coltop - 2] == 0.0)) {
      c_lastc--;
      b_coltop--;
    }

    b_coltop = 1;
    knt = 8;
    do {
      exitg1 = 0;
      if (knt <= c_lastc + 7) {
        if (b_A[knt - 1] != 0.0) {
          exitg1 = 1;
        } else {
          knt++;
        }
      } else {
        b_coltop = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    c_lastc = 0;
    b_coltop = 0;
  }

  if (c_lastc > 0) {
    xgemv_YUCucuUc(c_lastc, b_coltop, b_A, 8, b_A, 5, work);
    xgerc_gpDDvQUP(c_lastc, b_coltop, -tau_idx_1, 5, work, b_A, 8);
  }

  for (b_coltop = 5; b_coltop < 6; b_coltop++) {
    b_A[b_coltop] *= -tau_idx_1;
  }

  b_A[4] = 1.0 - tau_idx_1;
  b_A[3] = 0.0;
  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    c_lastc = 3;
    b_coltop = 4;
    while ((c_lastc > 0) && (b_A[b_coltop - 2] == 0.0)) {
      c_lastc--;
      b_coltop--;
    }

    b_coltop = 2;
    exitg2 = false;
    while ((!exitg2) && (b_coltop > 0)) {
      coltop = (b_coltop - 1) * 3 + 4;
      knt = coltop;
      do {
        exitg1 = 0;
        if (knt <= (coltop + c_lastc) - 1) {
          if (b_A[knt - 1] != 0.0) {
            exitg1 = 1;
          } else {
            knt++;
          }
        } else {
          b_coltop--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    c_lastc = 0;
    b_coltop = 0;
  }

  if (c_lastc > 0) {
    xgemv_YUCucuUc(c_lastc, b_coltop, b_A, 4, b_A, 1, work);
    xgerc_gpDDvQUP(c_lastc, b_coltop, -tau_idx_0, 1, work, b_A, 4);
  }

  for (b_coltop = 1; b_coltop < 3; b_coltop++) {
    b_A[b_coltop] *= -tau_idx_0;
  }

  b_A[0] = 1.0 - tau_idx_0;
  for (c_lastc = 0; c_lastc < 3; c_lastc++) {
    Q[3 * c_lastc] = b_A[3 * c_lastc];
    b_coltop = 3 * c_lastc + 1;
    Q[b_coltop] = b_A[b_coltop];
    b_coltop = 3 * c_lastc + 2;
    Q[b_coltop] = b_A[b_coltop];
  }
}
