#ifndef RTW_HEADER_EQV_h_
#define RTW_HEADER_EQV_h_
#ifndef EQV_COMMON_INCLUDES_
#define EQV_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "nesl_rtw.h"
#include "EQV_627956e1_1_gateway.h"
#endif

#include "EQV_types.h"

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct {
  real_T INPUT_1_1_1[4];
  real_T INPUT_2_1_1[4];
  real_T INPUT_3_1_1[4];
  real_T INPUT_4_1_1[4];
  real_T INPUT_5_1_1[4];
  real_T INPUT_6_1_1[4];
  real_T STATE_1[34];
} B_EQV_T;

typedef struct {
  real_T INPUT_1_1_1_Discrete[2];
  real_T INPUT_2_1_1_Discrete[2];
  real_T Delay1_DSTATE;
  real_T INPUT_3_1_1_Discrete[2];
  real_T Delay2_DSTATE[3];
  real_T INPUT_4_1_1_Discrete[2];
  real_T INPUT_5_1_1_Discrete[2];
  real_T Delay3_DSTATE[3];
  real_T INPUT_6_1_1_Discrete[2];
  real_T STATE_1_Discrete[18];
  real_T OUTPUT_1_0_Discrete;
  real_T OUTPUT_1_1_Discrete;
  real_T Memory4_PreviousInput;
  real_T Memory5_PreviousInput;
  real_T Memory1_PreviousInput;
  real_T Memory2_PreviousInput;
  real_T Memory3_PreviousInput;
  real_T Memory6_PreviousInput;
  real_T Memory7_PreviousInput;
  real_T Memory8_PreviousInput;
  void* STATE_1_Simulator;
  void* STATE_1_SimData;
  void* STATE_1_DiagMgr;
  void* STATE_1_ZcLogger;
  void* STATE_1_TsInfo;
  void* OUTPUT_1_0_Simulator;
  void* OUTPUT_1_0_SimData;
  void* OUTPUT_1_0_DiagMgr;
  void* OUTPUT_1_0_ZcLogger;
  void* OUTPUT_1_0_TsInfo;
  void* OUTPUT_1_1_Simulator;
  void* OUTPUT_1_1_SimData;
  void* OUTPUT_1_1_DiagMgr;
  void* OUTPUT_1_1_ZcLogger;
  void* OUTPUT_1_1_TsInfo;
  int_T STATE_1_Modes[16];
  int_T OUTPUT_1_0_Modes;
  int_T OUTPUT_1_1_Modes;
  boolean_T Memory_PreviousInput;
  boolean_T Memory_PreviousInput_m;
  boolean_T STATE_1_FirstOutput;
  boolean_T OUTPUT_1_0_FirstOutput;
  boolean_T OUTPUT_1_1_FirstOutput;
} DW_EQV_T;

typedef struct {
  boolean_T AMS_error;
  boolean_T AMS_error_reset;
  boolean_T IMD_error;
  boolean_T IMD_error_reset;
  real_T SC;
  real_T y;
  real_T EnableAirMinus;
  real_T EnableAirPlus;
  real_T EnablePrecharge;
  real_T y_f;
  real_T CurrentLevel;
  real_T VoltageLevel;
} ExtU_EQV_T;

typedef struct {
  real_T AMS_error_latched;
  real_T IMD_error_latched;
  real_T Current;
  real_T VehicleVoltage;
  real_T AccumulatorVoltage;
  real_T AirMinus;
  real_T AirPlus;
  real_T Precharge;
} ExtY_EQV_T;

struct P_EQV_T_ {
  boolean_T SRFlipFlop2_initial_condition;
  boolean_T SRFlipFlop1_initial_condition;
  real_T Delay1_InitialCondition;
  real_T Delay2_InitialCondition;
  real_T Delay3_InitialCondition;
  real_T Memory4_InitialCondition;
  real_T Memory5_InitialCondition;
  real_T Memory1_InitialCondition;
  real_T Memory2_InitialCondition;
  real_T Memory3_InitialCondition;
  real_T Memory6_InitialCondition;
  real_T Memory7_InitialCondition;
  real_T Memory8_InitialCondition;
  boolean_T Logic_table[16];
  boolean_T Logic_table_f[16];
};

struct tag_RTM_EQV_T {
  const char_T * volatile errorStatus;
  struct {
    uint32_T clockTick0;
  } Timing;
};

extern P_EQV_T EQV_P;
extern B_EQV_T EQV_B;
extern DW_EQV_T EQV_DW;
extern ExtU_EQV_T EQV_U;
extern ExtY_EQV_T EQV_Y;
extern void EQV_initialize(void);
extern void EQV_step(void);
extern void EQV_terminate(void);
extern RT_MODEL_EQV_T *const EQV_M;

#endif

