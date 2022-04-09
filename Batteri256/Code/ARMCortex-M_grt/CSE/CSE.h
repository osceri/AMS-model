#ifndef RTW_HEADER_CSE_h_
#define RTW_HEADER_CSE_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef CSE_COMMON_INCLUDES_
#define CSE_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif

#include "CSE_types.h"

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
  real_T P[9];
  real_T x[3];
} DW_CSE_T;

typedef struct {
  real_T u;
  real_T y;
} ExtU_CSE_T;

typedef struct {
  real_T soc;
  real_T C;
} ExtY_CSE_T;

struct P_CSE_T_ {
  real_T Rp[13];
  real_T Rs[13];
  real_T Ts;
  real_T ocv[13];
  real_T soc[13];
  real_T tau[13];
  real_T R1_Value;
  real_T MeasurementFcn1Inputs_Value;
  real_T Q_Value[9];
  real_T StateTransitionFcnInputs_Value;
  real_T DataStoreMemoryP_InitialValue[9];
  real_T DataStoreMemoryx_InitialValue[3];
  boolean_T yBlockOrdering_Y0;
  boolean_T BlockOrdering_Value;
  boolean_T Enable1_Value;
};

struct tag_RTM_CSE_T {
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

extern P_CSE_T CSE_P;
extern DW_CSE_T CSE_DW;
extern ExtU_CSE_T CSE_U;
extern ExtY_CSE_T CSE_Y;
extern void CSE_initialize(void);
extern void CSE_step(void);
extern void CSE_terminate(void);
extern RT_MODEL_CSE_T *const CSE_M;

#endif
