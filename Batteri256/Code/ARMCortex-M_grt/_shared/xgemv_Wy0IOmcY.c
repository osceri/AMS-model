#include "rtwtypes.h"
#include "xgemv_Wy0IOmcY.h"

void xgemv_Wy0IOmcY(int32_T m, int32_T n, const real_T A[18], int32_T ia0, const
                    real_T x[18], int32_T ix0, real_T y[3])
{
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  if ((m != 0) && (n != 0)) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * 6 + ia0;
    for (iac = ia0; iac <= b; iac += 6) {
      ix = ix0;
      c = 0.0;
      d = (iac + m) - 1;
      for (ia = iac; ia <= d; ia++) {
        c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[b_iy] += c;
      b_iy++;
    }
  }
}
