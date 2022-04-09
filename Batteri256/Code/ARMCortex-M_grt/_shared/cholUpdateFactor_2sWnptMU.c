#include "rtwtypes.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "rotate_YgpoDwi7.h"
#include "cholUpdateFactor_2sWnptMU.h"

void cholUpdateFactor_2sWnptMU(real_T *S, real_T U)
{
  real_T R;
  real_T alpha;
  real_T c;
  real_T nrmx;
  real_T temp;
  int8_T p;
  R = *S;
  p = 0;
  if (*S == 0.0) {
    p = 2;
  } else {
    temp = U / *S;
    nrmx = fabs(temp);
    if (nrmx >= 1.0) {
      p = 1;
    } else {
      rotate_YgpoDwi7(sqrt(1.0 - nrmx * nrmx), temp, &R, &c, &alpha);
      R = R * *S - c * 0.0;
    }
  }

  *S = R;
  if (p != 0) {
    temp = R * R - U * U;
    if ((!rtIsInf(temp)) && (!rtIsNaN(temp))) {
      nrmx = 1.0;
      if (temp != 0.0) {
        temp = fabs(temp);
      }
    } else {
      temp = (rtNaN);
      nrmx = (rtNaN);
    }

    *S = nrmx * sqrt(temp);
  }
}
