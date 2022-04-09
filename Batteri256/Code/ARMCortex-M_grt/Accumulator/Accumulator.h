#ifndef RTW_HEADER_Accumulator_h_
#define RTW_HEADER_Accumulator_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef Accumulator_COMMON_INCLUDES_
#define Accumulator_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif

#include "Accumulator_types.h"

#include "multiword_types.h"
#include "rt_nonfinite.h"

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
  real_T Memory4_PreviousInput[126];
  real_T Memory3_PreviousInput;
  real_T Memory_PreviousInput[126];
  real_T Memory2_PreviousInput[126];
  real_T Memory1_PreviousInput;
} DW_Accumulator_T;

typedef struct {
  real_T Current;
  real_T Balances[126];
} ExtU_Accumulator_T;

typedef struct {
  real_T Voltages[126];
  real_T SOCs[126];
  real_T Capacities[126];
} ExtY_Accumulator_T;

struct P_Accumulator_T_ {
  real_T C_r;
  real_T Cap_det;
  real_T R_short;
  real_T Rp[13];
  real_T Rs[13];
  real_T Ts_sim;
  real_T cCap[126];
  real_T cQur[126];
  real_T ocv[13];
  real_T soc[13];
  real_T tau[13];
  real_T Memory4_InitialCondition[126];
  real_T Memory3_InitialCondition;
  real_T Memory1_InitialCondition;
  real_T Constant1_Value;
};

struct tag_RTM_Accumulator_T {
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

extern P_Accumulator_T Accumulator_P;
extern DW_Accumulator_T Accumulator_DW;
extern ExtU_Accumulator_T Accumulator_U;
extern ExtY_Accumulator_T Accumulator_Y;
extern void Accumulator_initialize(void);
extern void Accumulator_step(void);
extern void Accumulator_terminate(void);
extern RT_MODEL_Accumulator_T *const Accumulator_M;

#endif
