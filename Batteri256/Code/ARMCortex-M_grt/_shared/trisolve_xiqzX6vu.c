#include "rtwtypes.h"
#include "trisolve_xiqzX6vu.h"

void trisolve_xiqzX6vu(real_T A, real_T B[3])
{
  if (B[0] != 0.0) {
    B[0] /= A;
  }

  if (B[1] != 0.0) {
    B[1] /= A;
  }

  if (B[2] != 0.0) {
    B[2] /= A;
  }
}
