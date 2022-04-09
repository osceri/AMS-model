#ifndef RTW_HEADER_UTMeanCovSqrt_XXn7ctVv_h_
#define RTW_HEADER_UTMeanCovSqrt_XXn7ctVv_h_
#include "rtwtypes.h"

extern void UTMeanCovSqrt_XXn7ctVv(const real_T meanWeights[2], const real_T
  covWeights[2], real_T OOM, real_T Y1[3], real_T Y2[18], const real_T X1[3],
  real_T X2[18], real_T Ymean[3], real_T Sy[9], real_T Pxy[9]);

#endif
