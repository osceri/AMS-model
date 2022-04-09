#include "rtwtypes.h"
#include <math.h>
#include "rt_hypotd_snf.h"
#include "rotate_YgpoDwi7.h"

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
