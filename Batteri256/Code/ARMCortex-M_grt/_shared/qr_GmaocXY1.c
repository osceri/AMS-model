#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "rt_hypotd_snf.h"
#include "xgemv_Wy0IOmcY.h"
#include "xgerc_EXI1TjPL.h"
#include "xnrm2_FT4aBNcp.h"
#include "qr_GmaocXY1.h"

void qr_GmaocXY1(const real_T A[18], real_T Q[18], real_T R[9])
{
  real_T b_A[18];
  real_T work[3];
  real_T b_atmp;
  real_T beta1;
  real_T tau_idx_0;
  real_T tau_idx_1;
  real_T tau_idx_2;
  int32_T b_coltop;
  int32_T c_lastc;
  int32_T coltop;
  int32_T exitg1;
  int32_T knt;
  boolean_T exitg2;
  memcpy(&b_A[0], &A[0], 18U * sizeof(real_T));
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  b_atmp = b_A[0];
  tau_idx_0 = 0.0;
  beta1 = xnrm2_FT4aBNcp(5, b_A, 2);
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
        for (b_coltop = 1; b_coltop < 6; b_coltop++) {
          b_A[b_coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        b_atmp *= 9.9792015476736E+291;
      } while (!(fabs(beta1) >= 1.0020841800044864E-292));

      beta1 = rt_hypotd_snf(b_atmp, xnrm2_FT4aBNcp(5, b_A, 2));
      if (b_atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - b_atmp) / beta1;
      b_atmp = 1.0 / (b_atmp - beta1);
      for (b_coltop = 1; b_coltop < 6; b_coltop++) {
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
      for (c_lastc = 1; c_lastc < 6; c_lastc++) {
        b_A[c_lastc] *= b_atmp;
      }

      b_atmp = beta1;
    }
  }

  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 6;
    c_lastc = 0;
    while ((knt > 0) && (b_A[c_lastc + 5] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 2;
    exitg2 = false;
    while ((!exitg2) && (c_lastc > 0)) {
      b_coltop = (c_lastc - 1) * 6 + 6;
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
    xgemv_Wy0IOmcY(knt, c_lastc, b_A, 7, b_A, 1, work);
    xgerc_EXI1TjPL(knt, c_lastc, -tau_idx_0, 1, work, b_A, 7);
  }

  b_A[0] = b_atmp;
  b_atmp = b_A[7];
  tau_idx_1 = 0.0;
  beta1 = xnrm2_FT4aBNcp(4, b_A, 9);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[7], beta1);
    if (b_A[7] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        for (b_coltop = 8; b_coltop < 12; b_coltop++) {
          b_A[b_coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        b_atmp *= 9.9792015476736E+291;
      } while (!(fabs(beta1) >= 1.0020841800044864E-292));

      beta1 = rt_hypotd_snf(b_atmp, xnrm2_FT4aBNcp(4, b_A, 9));
      if (b_atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_1 = (beta1 - b_atmp) / beta1;
      b_atmp = 1.0 / (b_atmp - beta1);
      for (b_coltop = 8; b_coltop < 12; b_coltop++) {
        b_A[b_coltop] *= b_atmp;
      }

      for (c_lastc = 0; c_lastc <= knt; c_lastc++) {
        beta1 *= 1.0020841800044864E-292;
      }

      b_atmp = beta1;
    } else {
      tau_idx_1 = (beta1 - b_A[7]) / beta1;
      b_atmp = 1.0 / (b_A[7] - beta1);
      for (c_lastc = 8; c_lastc < 12; c_lastc++) {
        b_A[c_lastc] *= b_atmp;
      }

      b_atmp = beta1;
    }
  }

  b_A[7] = 1.0;
  if (tau_idx_1 != 0.0) {
    knt = 5;
    c_lastc = 6;
    while ((knt > 0) && (b_A[c_lastc + 5] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 1;
    coltop = 13;
    do {
      exitg1 = 0;
      if (coltop + 1 <= 13 + knt) {
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
    xgemv_Wy0IOmcY(knt, c_lastc, b_A, 14, b_A, 8, work);
    xgerc_EXI1TjPL(knt, c_lastc, -tau_idx_1, 8, work, b_A, 14);
  }

  b_A[7] = b_atmp;
  b_atmp = b_A[14];
  tau_idx_2 = 0.0;
  beta1 = xnrm2_FT4aBNcp(3, b_A, 16);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[14], beta1);
    if (b_A[14] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        for (b_coltop = 15; b_coltop < 18; b_coltop++) {
          b_A[b_coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        b_atmp *= 9.9792015476736E+291;
      } while (!(fabs(beta1) >= 1.0020841800044864E-292));

      beta1 = rt_hypotd_snf(b_atmp, xnrm2_FT4aBNcp(3, b_A, 16));
      if (b_atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_2 = (beta1 - b_atmp) / beta1;
      b_atmp = 1.0 / (b_atmp - beta1);
      for (b_coltop = 15; b_coltop < 18; b_coltop++) {
        b_A[b_coltop] *= b_atmp;
      }

      for (c_lastc = 0; c_lastc <= knt; c_lastc++) {
        beta1 *= 1.0020841800044864E-292;
      }

      b_atmp = beta1;
    } else {
      tau_idx_2 = (beta1 - b_A[14]) / beta1;
      b_atmp = 1.0 / (b_A[14] - beta1);
      for (c_lastc = 15; c_lastc < 18; c_lastc++) {
        b_A[c_lastc] *= b_atmp;
      }

      b_atmp = beta1;
    }
  }

  b_A[14] = b_atmp;
  R[0] = b_A[0];
  for (c_lastc = 1; c_lastc + 1 < 4; c_lastc++) {
    R[c_lastc] = 0.0;
  }

  work[0] = 0.0;
  for (c_lastc = 0; c_lastc < 2; c_lastc++) {
    R[c_lastc + 3] = b_A[c_lastc + 6];
  }

  while (c_lastc + 1 < 4) {
    R[c_lastc + 3] = 0.0;
    c_lastc++;
  }

  work[1] = 0.0;
  for (c_lastc = 0; c_lastc < 3; c_lastc++) {
    R[c_lastc + 6] = b_A[c_lastc + 12];
  }

  work[2] = 0.0;
  for (b_coltop = 15; b_coltop < 18; b_coltop++) {
    b_A[b_coltop] *= -tau_idx_2;
  }

  b_A[14] = 1.0 - tau_idx_2;
  for (c_lastc = 0; c_lastc < 2; c_lastc++) {
    b_A[13 - c_lastc] = 0.0;
  }

  b_A[7] = 1.0;
  if (tau_idx_1 != 0.0) {
    c_lastc = 5;
    b_coltop = 13;
    while ((c_lastc > 0) && (b_A[b_coltop - 2] == 0.0)) {
      c_lastc--;
      b_coltop--;
    }

    b_coltop = 1;
    knt = 14;
    do {
      exitg1 = 0;
      if (knt <= c_lastc + 13) {
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
    xgemv_Wy0IOmcY(c_lastc, b_coltop, b_A, 14, b_A, 8, work);
    xgerc_EXI1TjPL(c_lastc, b_coltop, -tau_idx_1, 8, work, b_A, 14);
  }

  for (b_coltop = 8; b_coltop < 12; b_coltop++) {
    b_A[b_coltop] *= -tau_idx_1;
  }

  b_A[7] = 1.0 - tau_idx_1;
  b_A[6] = 0.0;
  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    c_lastc = 6;
    b_coltop = 7;
    while ((c_lastc > 0) && (b_A[b_coltop - 2] == 0.0)) {
      c_lastc--;
      b_coltop--;
    }

    b_coltop = 2;
    exitg2 = false;
    while ((!exitg2) && (b_coltop > 0)) {
      coltop = (b_coltop - 1) * 6 + 7;
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
    xgemv_Wy0IOmcY(c_lastc, b_coltop, b_A, 7, b_A, 1, work);
    xgerc_EXI1TjPL(c_lastc, b_coltop, -tau_idx_0, 1, work, b_A, 7);
  }

  for (b_coltop = 1; b_coltop < 6; b_coltop++) {
    b_A[b_coltop] *= -tau_idx_0;
  }

  b_A[0] = 1.0 - tau_idx_0;
  for (b_coltop = 0; b_coltop < 3; b_coltop++) {
    for (c_lastc = 0; c_lastc < 6; c_lastc++) {
      Q[c_lastc + 6 * b_coltop] = b_A[6 * b_coltop + c_lastc];
    }
  }
}
