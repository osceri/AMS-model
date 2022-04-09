#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "cholUpdateFactor_2sWnptMU.h"
#include "rotate_YgpoDwi7.h"
#include "rt_hypotd_snf.h"
#include "xnrm2_5iCqcdaj.h"
#include "UTMeanCovSqrt_Cre0pFhD.h"

void UTMeanCovSqrt_Cre0pFhD(const real_T meanWeights[2], const real_T
  covWeights[2], real_T OOM, real_T Y1, real_T Y2[6], const real_T X1[3], real_T
  X2[18], real_T *Ymean, real_T *Sy, real_T Pxy[3])
{
  real_T A[6];
  real_T X2_0[3];
  real_T covWeights_0;
  real_T covWeights_1;
  real_T signOOM;
  real_T xnorm;
  int32_T b_k;
  int32_T knt;
  *Ymean = Y1 * meanWeights[0];
  for (knt = 0; knt < 6; knt++) {
    *Ymean += Y2[knt] * meanWeights[1];
  }

  *Ymean *= OOM;
  Y1 -= *Ymean;
  for (knt = 0; knt < 6; knt++) {
    Y2[knt] -= *Ymean;
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
  signOOM = sqrt(covWeights_1);
  for (knt = 0; knt < 6; knt++) {
    A[knt] = signOOM * Y2[knt];
  }

  signOOM = A[0];
  xnorm = xnrm2_5iCqcdaj(5, A, 2);
  if (xnorm != 0.0) {
    xnorm = rt_hypotd_snf(A[0], xnorm);
    if (A[0] >= 0.0) {
      xnorm = -xnorm;
    }

    if (fabs(xnorm) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        for (b_k = 1; b_k < 6; b_k++) {
          A[b_k] *= 9.9792015476736E+291;
        }

        xnorm *= 9.9792015476736E+291;
        signOOM *= 9.9792015476736E+291;
      } while (!(fabs(xnorm) >= 1.0020841800044864E-292));

      xnorm = rt_hypotd_snf(signOOM, xnrm2_5iCqcdaj(5, A, 2));
      if (signOOM >= 0.0) {
        xnorm = -xnorm;
      }

      for (b_k = 0; b_k <= knt; b_k++) {
        xnorm *= 1.0020841800044864E-292;
      }

      signOOM = xnorm;
    } else {
      signOOM = xnorm;
    }
  }

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
    rotate_YgpoDwi7(signOOM, Y1, &signOOM, &xnorm, &covWeights_0);
    *Sy = sqrt(OOM) * covWeights_0;
  } else {
    cholUpdateFactor_2sWnptMU(&signOOM, Y1);
    *Sy = sqrt(OOM) * signOOM;
  }

  for (knt = 0; knt < 6; knt++) {
    X2[3 * knt] -= X1[0];
    b_k = 3 * knt + 1;
    X2[b_k] -= X1[1];
    b_k = 3 * knt + 2;
    X2[b_k] -= X1[2];
  }

  signOOM = covWeights_1 * OOM;
  for (knt = 0; knt < 3; knt++) {
    X2_0[knt] = 0.0;
    for (b_k = 0; b_k < 6; b_k++) {
      X2_0[knt] += X2[3 * b_k + knt] * Y2[b_k];
    }

    Pxy[knt] = X2_0[knt] * signOOM;
  }
}
