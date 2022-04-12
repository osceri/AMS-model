#ifndef RTW_HEADER_SIM0_h_
#define RTW_HEADER_SIM0_h_
#ifndef SIM0_COMMON_INCLUDES_
#define SIM0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "nesl_rtw.h"
#include "SIM0_627956e1_1_gateway.h"
#endif

#include "SIM0_types.h"

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct {
  real_T INPUT_7_1_1[4];
  real_T INPUT_8_1_1[4];
  real_T INPUT_2_1_1[4];
  real_T INPUT_1_1_1[4];
  real_T INPUT_3_1_1[4];
  real_T INPUT_4_1_1[4];
  real_T INPUT_5_1_1[4];
  real_T INPUT_6_1_1[4];
  real_T STATE_1[33];
} B_SIM0_T;

typedef struct {
  real_T Delay3_DSTATE[2];
  real_T Delay2_DSTATE[2];
  real_T INPUT_7_1_1_Discrete[2];
  real_T INPUT_8_1_1_Discrete[2];
  real_T INPUT_2_1_1_Discrete[2];
  real_T INPUT_1_1_1_Discrete[2];
  real_T Delay1_DSTATE;
  real_T INPUT_3_1_1_Discrete[2];
  real_T INPUT_4_1_1_Discrete[2];
  real_T INPUT_5_1_1_Discrete[2];
  real_T INPUT_6_1_1_Discrete[2];
  real_T STATE_1_Discrete[17];
  real_T Memory15_PreviousInput[126];
  real_T Memory12_PreviousInput[126];
  real_T Memory20_PreviousInput;
  real_T Memory11_PreviousInput;
  real_T Memory_PreviousInput[126];
  real_T Memory10_PreviousInput[126];
  real_T Memory9_PreviousInput;
  real_T Memory19_PreviousInput[126];
  real_T Memory21_PreviousInput[126];
  real_T Memory6_PreviousInput;
  real_T Memory7_PreviousInput;
  real_T Memory16_PreviousInput;
  real_T Memory17_PreviousInput;
  real_T Memory18_PreviousInput;
  real_T Memory1_PreviousInput;
  real_T Memory2_PreviousInput;
  real_T Memory3_PreviousInput;
  real_T Memory4_PreviousInput;
  real_T Memory5_PreviousInput;
  real_T Memory22_PreviousInput;
  real_T OUTPUT_1_0_Discrete;
  real_T OUTPUT_1_1_Discrete;
  real_T OUTPUT_1_2_Discrete;
  real_T Memory13_PreviousInput;
  real_T Memory14_PreviousInput;
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
  void* OUTPUT_1_2_Simulator;
  void* OUTPUT_1_2_SimData;
  void* OUTPUT_1_2_DiagMgr;
  void* OUTPUT_1_2_ZcLogger;
  void* OUTPUT_1_2_TsInfo;
  int_T STATE_1_Modes[16];
  int_T OUTPUT_1_0_Modes;
  int_T OUTPUT_1_1_Modes;
  int_T OUTPUT_1_2_Modes;
  boolean_T Memory_PreviousInput_e;
  boolean_T Memory_PreviousInput_m;
  boolean_T STATE_1_FirstOutput;
  boolean_T OUTPUT_1_0_FirstOutput;
  boolean_T OUTPUT_1_1_FirstOutput;
  boolean_T OUTPUT_1_2_FirstOutput;
} DW_SIM0_T;

typedef struct {
  real_T AMS_error;
  real_T AMS_error_reset;
  real_T IMD_error;
  real_T IMD_error_reset;
  real_T SC;
  real_T EnableAirMinus;
  real_T EnableAirPlus;
  real_T EnablePrecharge;
  real_T VoltageLimit;
  real_T CurrentLimit;
  real_T EnableCharge;
  real_T charge;
  real_T drive;
  real_T BalanceOut[126];
  real_T drive_current;
} ExtU_SIM0_T;

typedef struct {
  boolean_T AMS_error_latched;
  boolean_T IMD_error_latched;
  real_T SC_probe;
  real_T AIR_minus_closed;
  real_T AIR_plus_closed;
  real_T precharge_closed;
  real_T current;
  real_T vehicle_voltage;
  real_T accumulator_voltage;
  real_T cell_voltages[126];
  real_T cell_socs[126];
  real_T cell_capacities[126];
  real_T cell_temperatures[60];
  real_T IMD_ok;
} ExtY_SIM0_T;

struct P_SIM0_T_ {
  real_T C_r;
  real_T Cap_det;
  real_T IMD_ok;
  real_T R_short;
  real_T Rp[13];
  real_T Rs[13];
  real_T Ts;
  real_T cCap[126];
  real_T cQur[126];
  real_T cTmp[60];
  real_T ocv[13];
  real_T soc[13];
  real_T tau[13];
  boolean_T SRFlipFlop2_initial_condition;
  boolean_T SRFlipFlop1_initial_condition;
  real_T Memory15_InitialCondition;
  real_T Memory12_InitialCondition[126];
  real_T Memory20_InitialCondition;
  real_T Memory11_InitialCondition;
  real_T Memory9_InitialCondition;
  real_T Memory19_InitialCondition;
  real_T Memory21_InitialCondition;
  real_T Gain_Gain;
  real_T Constant1_Value;
  real_T Memory6_InitialCondition;
  real_T Memory7_InitialCondition;
  real_T Memory16_InitialCondition;
  real_T Memory17_InitialCondition;
  real_T Memory18_InitialCondition;
  real_T Memory1_InitialCondition;
  real_T Memory2_InitialCondition;
  real_T Memory3_InitialCondition;
  real_T Memory4_InitialCondition;
  real_T Memory5_InitialCondition;
  real_T Delay3_InitialCondition;
  real_T Delay2_InitialCondition;
  real_T Memory22_InitialCondition;
  real_T Delay1_InitialCondition;
  real_T Memory13_InitialCondition;
  real_T Memory14_InitialCondition;
  real_T Memory8_InitialCondition;
  boolean_T Logic_table[16];
  boolean_T Logic_table_f[16];
};

struct tag_RTM_SIM0_T {
  const char_T * volatile errorStatus;
  struct {
    uint32_T clockTick0;
  } Timing;
};

extern P_SIM0_T SIM0_P;
extern B_SIM0_T SIM0_B;
extern DW_SIM0_T SIM0_DW;
extern ExtU_SIM0_T SIM0_U;
extern ExtY_SIM0_T SIM0_Y;
extern void SIM0_initialize(void);
extern void SIM0_step(void);
extern void SIM0_terminate(void);
extern RT_MODEL_SIM0_T *const SIM0_M;

#endif

