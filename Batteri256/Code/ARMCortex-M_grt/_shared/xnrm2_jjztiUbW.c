#include "rtwtypes.h"
#include <math.h>
#include "xnrm2_jjztiUbW.h"

real_T xnrm2_jjztiUbW(int32_T n, const real_T x[9], int32_T ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}
