#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>
#include "qr_EmoCK6PM.h"
#include "qr_GmaocXY1.h"
#include "rotate_YgpoDwi7.h"
#include "svd_NBhHrtzf.h"
#include "UTMeanCovSqrt_XXn7ctVv.h"

void UTMeanCovSqrt_XXn7ctVv(const real_T meanWeights[2], const real_T
  covWeights[2], real_T OOM, real_T Y1[3], real_T Y2[18], const real_T X1[3],
  real_T X2[18], real_T Ymean[3], real_T Sy[9], real_T Pxy[9])
{
  real_T W2_0[18];
  real_T a__1[18];
  real_T A[9];
  real_T Ss[9];
  real_T Sy_0[9];
  real_T c[3];
  real_T s[3];
  real_T x[3];
  real_T W2;
  real_T absxk;
  real_T b_t;
  real_T covWeights_0;
  real_T covWeights_1;
  real_T scale;
  real_T signOOM;
  int32_T Sy_tmp;
  int32_T exitg1;
  int32_T i;
  int32_T iAcol;
  int32_T kk;
  boolean_T errorCondition;
  boolean_T exitg2;
  boolean_T guard1 = false;
  Ymean[0] = Y1[0] * meanWeights[0];
  Ymean[1] = meanWeights[0] * Y1[1];
  Ymean[2] = meanWeights[0] * Y1[2];
  for (kk = 0; kk < 6; kk++) {
    Ymean[0] += Y2[3 * kk] * meanWeights[1];
    Ymean[1] += Y2[3 * kk + 1] * meanWeights[1];
    Ymean[2] += Y2[3 * kk + 2] * meanWeights[1];
  }

  signOOM = Ymean[0] * OOM;
  scale = Y1[0] - signOOM;
  Ymean[0] = signOOM;
  Y1[0] = scale;
  signOOM = Ymean[1] * OOM;
  absxk = Y1[1] - signOOM;
  Ymean[1] = signOOM;
  Y1[1] = absxk;
  signOOM = Ymean[2] * OOM;
  b_t = Y1[2] - signOOM;
  Ymean[2] = signOOM;
  Y1[2] = b_t;
  for (kk = 0; kk < 6; kk++) {
    Y2[3 * kk] -= Ymean[0];
    iAcol = 3 * kk + 1;
    Y2[iAcol] -= Ymean[1];
    iAcol = 3 * kk + 2;
    Y2[iAcol] -= signOOM;
  }

  if (OOM < 0.0) {
    signOOM = -1.0;
  } else if (OOM > 0.0) {
    signOOM = 1.0;
  } else if (OOM == 0.0) {
    signOOM = 0.0;
  } else {
    signOOM = (rtNaN);
  }

  covWeights_0 = signOOM * covWeights[0];
  covWeights_1 = signOOM * covWeights[1];
  OOM *= signOOM;
  signOOM = sqrt(OOM);
  W2 = sqrt(covWeights_1);
  for (kk = 0; kk < 3; kk++) {
    for (iAcol = 0; iAcol < 6; iAcol++) {
      W2_0[iAcol + 6 * kk] = Y2[3 * iAcol + kk] * W2;
    }
  }

  qr_GmaocXY1(W2_0, a__1, Sy);
  if (covWeights_0 < 0.0) {
    covWeights_0 = -1.0;
  } else if (covWeights_0 > 0.0) {
    covWeights_0 = 1.0;
  } else if (covWeights_0 == 0.0) {
    covWeights_0 = 0.0;
  } else {
    covWeights_0 = (rtNaN);
  }

  if (covWeights_0 == 1.0) {
    for (iAcol = 0; iAcol < 2; iAcol++) {
      Sy[iAcol + 1] = 0.0;
    }

    Sy[5] = 0.0;
    c[2] = 0.0;
    s[2] = 0.0;
    rotate_YgpoDwi7(Sy[0], scale, &c[0], &s[0], &Sy[0]);
    W2 = c[0] * absxk - s[0] * Sy[3];
    Sy[3] = c[0] * Sy[3] + s[0] * absxk;
    rotate_YgpoDwi7(Sy[4], W2, &c[1], &s[1], &Sy[4]);
    W2 = b_t;
    for (iAcol = 0; iAcol < 2; iAcol++) {
      scale = s[iAcol] * W2;
      absxk = Sy[iAcol + 6];
      W2 = c[iAcol] * W2 - absxk * s[iAcol];
      Sy[iAcol + 6] = absxk * c[iAcol] + scale;
    }

    rotate_YgpoDwi7(Sy[8], W2, &c[2], &s[2], &Sy[8]);
    for (kk = 0; kk < 3; kk++) {
      Sy_0[3 * kk] = Sy[kk];
      Sy_0[3 * kk + 1] = Sy[kk + 3];
      Sy_0[3 * kk + 2] = Sy[kk + 6];
    }

    for (kk = 0; kk < 9; kk++) {
      Sy[kk] = signOOM * Sy_0[kk];
    }
  } else {
    for (iAcol = 0; iAcol < 2; iAcol++) {
      Sy[iAcol + 1] = 0.0;
    }

    Sy[5] = 0.0;
    errorCondition = false;
    if ((Sy[0] == 0.0) || (Sy[4] == 0.0) || (Sy[8] == 0.0)) {
      errorCondition = true;
    }

    guard1 = false;
    if (errorCondition) {
      guard1 = true;
    } else {
      x[2] = b_t;
      x[0] = scale / Sy[0];
      x[1] = (absxk - x[0] * Sy[3]) / Sy[4];
      W2 = b_t;
      for (kk = 0; kk < 2; kk++) {
        W2 -= Sy[kk + 6] * x[kk];
      }

      x[2] = W2 / Sy[8];
      scale = 3.3121686421112381E-170;
      absxk = fabs(x[0]);
      if (absxk > 3.3121686421112381E-170) {
        W2 = 1.0;
        scale = absxk;
      } else {
        b_t = absxk / 3.3121686421112381E-170;
        W2 = b_t * b_t;
      }

      absxk = fabs(x[1]);
      if (absxk > scale) {
        b_t = scale / absxk;
        W2 = W2 * b_t * b_t + 1.0;
        scale = absxk;
      } else {
        b_t = absxk / scale;
        W2 += b_t * b_t;
      }

      absxk = fabs(x[2]);
      if (absxk > scale) {
        b_t = scale / absxk;
        W2 = W2 * b_t * b_t + 1.0;
        scale = absxk;
      } else {
        b_t = absxk / scale;
        W2 += b_t * b_t;
      }

      W2 = scale * sqrt(W2);
      if (W2 >= 1.0) {
        guard1 = true;
      } else {
        rotate_YgpoDwi7(sqrt(1.0 - W2 * W2), x[2], &c[2], &s[2], &W2);
        x[2] = 0.0;
        rotate_YgpoDwi7(W2, x[1], &c[1], &s[1], &W2);
        x[1] = 0.0;
        rotate_YgpoDwi7(W2, x[0], &c[0], &s[0], &W2);
        x[0] = 0.0;
        for (iAcol = 0; iAcol + 1 > 0; iAcol--) {
          W2 = s[iAcol] * Sy[iAcol];
          Sy[iAcol] = c[iAcol] * Sy[iAcol] - s[iAcol] * x[0];
          x[0] = c[iAcol] * x[0] + W2;
        }

        for (iAcol = 1; iAcol + 1 > 0; iAcol--) {
          absxk = Sy[iAcol + 3];
          Sy[iAcol + 3] = absxk * c[iAcol] - s[iAcol] * x[1];
          x[1] = c[iAcol] * x[1] + absxk * s[iAcol];
        }

        for (iAcol = 2; iAcol + 1 > 0; iAcol--) {
          absxk = Sy[iAcol + 6];
          Sy[iAcol + 6] = absxk * c[iAcol] - s[iAcol] * x[2];
          x[2] = c[iAcol] * x[2] + absxk * s[iAcol];
        }
      }
    }

    if (guard1) {
      for (kk = 0; kk < 3; kk++) {
        for (iAcol = 0; iAcol < 3; iAcol++) {
          Sy_tmp = kk + 3 * iAcol;
          Sy_0[Sy_tmp] = 0.0;
          Sy_0[Sy_tmp] += Sy[3 * kk] * Sy[3 * iAcol];
          Sy_0[Sy_tmp] += Sy[3 * kk + 1] * Sy[3 * iAcol + 1];
          Sy_0[Sy_tmp] += Sy[3 * kk + 2] * Sy[3 * iAcol + 2];
          Ss[iAcol + 3 * kk] = Y1[iAcol] * Y1[kk];
        }
      }

      errorCondition = true;
      for (kk = 0; kk < 9; kk++) {
        W2 = Sy_0[kk] - Ss[kk];
        if (errorCondition && ((!rtIsInf(W2)) && (!rtIsNaN(W2)))) {
        } else {
          errorCondition = false;
        }

        A[kk] = W2;
      }

      if (errorCondition) {
        svd_NBhHrtzf(A, Ss, s, Sy_0);
      } else {
        s[0] = (rtNaN);
        s[1] = (rtNaN);
        s[2] = (rtNaN);
        for (kk = 0; kk < 9; kk++) {
          Sy_0[kk] = (rtNaN);
        }
      }

      memset(&Ss[0], 0, 9U * sizeof(real_T));
      Ss[0] = s[0];
      Ss[4] = s[1];
      Ss[8] = s[2];
      for (kk = 0; kk < 9; kk++) {
        Ss[kk] = sqrt(Ss[kk]);
      }

      for (kk = 0; kk < 3; kk++) {
        for (iAcol = 0; iAcol < 3; iAcol++) {
          Sy_tmp = kk + 3 * iAcol;
          Sy[Sy_tmp] = 0.0;
          Sy[Sy_tmp] += Ss[3 * kk] * Sy_0[iAcol];
          Sy[Sy_tmp] += Ss[3 * kk + 1] * Sy_0[iAcol + 3];
          Sy[Sy_tmp] += Ss[3 * kk + 2] * Sy_0[iAcol + 6];
        }
      }

      errorCondition = true;
      kk = 0;
      exitg2 = false;
      while ((!exitg2) && (kk < 3)) {
        iAcol = kk + 1;
        do {
          exitg1 = 0;
          if (iAcol + 1 < 4) {
            if (!(Sy[3 * kk + iAcol] == 0.0)) {
              errorCondition = false;
              exitg1 = 1;
            } else {
              iAcol++;
            }
          } else {
            kk++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      if (!errorCondition) {
        memcpy(&Sy_0[0], &Sy[0], 9U * sizeof(real_T));
        qr_EmoCK6PM(Sy_0, Ss, Sy);
      }
    }

    for (kk = 0; kk < 3; kk++) {
      Sy_0[3 * kk] = Sy[kk];
      Sy_0[3 * kk + 1] = Sy[kk + 3];
      Sy_0[3 * kk + 2] = Sy[kk + 6];
    }

    for (kk = 0; kk < 9; kk++) {
      Sy[kk] = signOOM * Sy_0[kk];
    }
  }

  for (kk = 0; kk < 6; kk++) {
    X2[3 * kk] -= X1[0];
    Sy_tmp = 3 * kk + 1;
    X2[Sy_tmp] -= X1[1];
    Sy_tmp = 3 * kk + 2;
    X2[Sy_tmp] -= X1[2];
  }

  signOOM = covWeights_1 * OOM;
  for (kk = 0; kk < 3; kk++) {
    for (iAcol = 0; iAcol < 3; iAcol++) {
      Sy_tmp = kk + 3 * iAcol;
      A[Sy_tmp] = 0.0;
      for (i = 0; i < 6; i++) {
        A[Sy_tmp] += X2[3 * i + kk] * Y2[3 * i + iAcol];
      }
    }
  }

  for (kk = 0; kk < 9; kk++) {
    Pxy[kk] = A[kk] * signOOM;
  }
}
