#include "rtwtypes.h"
#include "xdotc_zr3wrcdj.h"

real_T xdotc_zr3wrcdj(int32_T n, const real_T x[9], int32_T ix0, const real_T y
                      [9], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (n >= 1) {
    ix = ix0;
    iy = iy0;
    for (k = 0; k < n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}
