#ifndef RTW_HEADER_CBR_private_h_
#define RTW_HEADER_CBR_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "CBR.h"

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void CBR_MATLABFunction1(const real_T rtu_u[126], B_MATLABFunction1_CBR_T
  *localB);

#endif
