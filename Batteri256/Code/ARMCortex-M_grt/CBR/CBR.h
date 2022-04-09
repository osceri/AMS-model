#ifndef RTW_HEADER_CBR_h_
#define RTW_HEADER_CBR_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef CBR_COMMON_INCLUDES_
#define CBR_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif

#include "CBR_types.h"

#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

typedef struct {
  real_T y;
} B_MATLABFunction1_CBR_T;

typedef struct {
  B_MATLABFunction1_CBR_T sf_MATLABFunction3;
  B_MATLABFunction1_CBR_T sf_MATLABFunction1;
} B_CBR_T;

typedef struct {
  real_T Memory_PreviousInput;
  real_T Memory1_PreviousInput[126];
  real_T Memory6_PreviousInput;
  real_T Memory5_PreviousInput;
  uint8_T is_active_c5_CBR;
  uint8_T is_c5_CBR;
} DW_CBR_T;

typedef struct {
  real_T Voltages[126];
  real_T SOCs[126];
} ExtU_CBR_T;

typedef struct {
  real_T Current;
  real_T Balances[126];
} ExtY_CBR_T;

struct P_CBR_T_ {
  real_T C_r;
  real_T I_CV;
  real_T Rp[13];
  real_T Rs[13];
  real_T Ts;
  real_T U_CC;
  real_T U_sought;
  real_T U_tol;
  real_T ocv[13];
  real_T soc[13];
  real_T tau[13];
  real_T Memory_InitialCondition;
  real_T Memory1_InitialCondition;
  real_T Memory6_InitialCondition;
  real_T Memory5_InitialCondition;
};

struct tag_RTM_CBR_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

extern P_CBR_T CBR_P;
extern B_CBR_T CBR_B;
extern DW_CBR_T CBR_DW;
extern ExtU_CBR_T CBR_U;
extern ExtY_CBR_T CBR_Y;
extern void CBR_initialize(void);
extern void CBR_step(void);
extern void CBR_terminate(void);
extern RT_MODEL_CBR_T *const CBR_M;

#endif
