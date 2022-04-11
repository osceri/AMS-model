#include "EQV.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>

B_EQV_T EQV_B;
DW_EQV_T EQV_DW;
ExtU_EQV_T EQV_U;
ExtY_EQV_T EQV_Y;
static RT_MODEL_EQV_T EQV_M_;
RT_MODEL_EQV_T *const EQV_M = &EQV_M_;
void EQV_step(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  NeuDiagnosticTree *diagnosticTree_0;
  NeuDiagnosticTree *diagnosticTree_1;
  NeuDiagnosticTree *diagnosticTree_2;
  real_T tmp_1[58];
  real_T tmp_3[58];
  real_T tmp[24];
  real_T tmp_5[24];
  real_T rtb_OUTPUT_1_0[2];
  real_T Product;
  real_T Product1;
  real_T rtb_Add;
  real_T rtb_Memory8;
  real_T rtb_OUTPUT_1_1;
  real_T time;
  real_T time_0;
  real_T time_1;
  real_T time_2;
  real_T time_3;
  real_T time_4;
  real_T time_5;
  real_T time_tmp;
  real_T time_tmp_0;
  int32_T isHit;
  int32_T isHit_0;
  int32_T isHit_1;
  int32_T rowIdx;
  int_T tmp_2[8];
  int_T tmp_4[8];
  int_T tmp_0[7];
  int_T tmp_6[7];
  boolean_T rtb_Logic_a_idx_0;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_Logic_idx_1;
  EQV_B.INPUT_1_1_1[0] = EQV_U.y_f;
  EQV_B.INPUT_1_1_1[1] = 0.0;
  EQV_B.INPUT_1_1_1[2] = 0.0;
  EQV_DW.INPUT_1_1_1_Discrete[0] = !(EQV_B.INPUT_1_1_1[0] ==
    EQV_DW.INPUT_1_1_1_Discrete[1]);
  EQV_DW.INPUT_1_1_1_Discrete[1] = EQV_B.INPUT_1_1_1[0];
  EQV_B.INPUT_1_1_1[0] = EQV_DW.INPUT_1_1_1_Discrete[1];
  EQV_B.INPUT_1_1_1[3] = EQV_DW.INPUT_1_1_1_Discrete[0];
  EQV_B.INPUT_2_1_1[0] = EQV_U.VoltageLevel;
  EQV_B.INPUT_2_1_1[1] = 0.0;
  EQV_B.INPUT_2_1_1[2] = 0.0;
  EQV_DW.INPUT_2_1_1_Discrete[0] = !(EQV_B.INPUT_2_1_1[0] ==
    EQV_DW.INPUT_2_1_1_Discrete[1]);
  EQV_DW.INPUT_2_1_1_Discrete[1] = EQV_B.INPUT_2_1_1[0];
  EQV_B.INPUT_2_1_1[0] = EQV_DW.INPUT_2_1_1_Discrete[1];
  EQV_B.INPUT_2_1_1[3] = EQV_DW.INPUT_2_1_1_Discrete[0];
  rowIdx = (int32_T)(((((uint32_T)EQV_U.AMS_error << 1) + EQV_U.AMS_error_reset)
                      << 1) + EQV_DW.Memory_PreviousInput);
  rtb_Logic_idx_0 = EQV_P.Logic_table[(uint32_T)rowIdx];
  rtb_Logic_idx_1 = EQV_P.Logic_table[rowIdx + 8U];
  rowIdx = (int32_T)(((((uint32_T)EQV_U.IMD_error << 1) + EQV_U.IMD_error_reset)
                      << 1) + EQV_DW.Memory_PreviousInput_m);
  rtb_Logic_a_idx_0 = EQV_P.Logic_table_f[(uint32_T)rowIdx];
  rtb_Memory8 = (rtb_Logic_idx_1 ? (real_T)EQV_P.Logic_table_f[rowIdx + 8U] :
                 0.0) * EQV_U.SC;
  Product = rtb_Memory8 * EQV_DW.Delay1_DSTATE;
  EQV_B.INPUT_3_1_1[0] = Product;
  EQV_B.INPUT_3_1_1[1] = 0.0;
  EQV_B.INPUT_3_1_1[2] = 0.0;
  EQV_DW.INPUT_3_1_1_Discrete[0] = !(EQV_B.INPUT_3_1_1[0] ==
    EQV_DW.INPUT_3_1_1_Discrete[1]);
  EQV_DW.INPUT_3_1_1_Discrete[1] = EQV_B.INPUT_3_1_1[0];
  EQV_B.INPUT_3_1_1[0] = EQV_DW.INPUT_3_1_1_Discrete[1];
  EQV_B.INPUT_3_1_1[3] = EQV_DW.INPUT_3_1_1_Discrete[0];
  Product1 = rtb_Memory8 * EQV_DW.Delay2_DSTATE[0];
  EQV_B.INPUT_4_1_1[0] = Product1;
  EQV_B.INPUT_4_1_1[1] = 0.0;
  EQV_B.INPUT_4_1_1[2] = 0.0;
  EQV_DW.INPUT_4_1_1_Discrete[0] = !(EQV_B.INPUT_4_1_1[0] ==
    EQV_DW.INPUT_4_1_1_Discrete[1]);
  EQV_DW.INPUT_4_1_1_Discrete[1] = EQV_B.INPUT_4_1_1[0];
  EQV_B.INPUT_4_1_1[0] = EQV_DW.INPUT_4_1_1_Discrete[1];
  EQV_B.INPUT_4_1_1[3] = EQV_DW.INPUT_4_1_1_Discrete[0];
  EQV_B.INPUT_5_1_1[0] = EQV_U.y;
  EQV_B.INPUT_5_1_1[1] = 0.0;
  EQV_B.INPUT_5_1_1[2] = 0.0;
  EQV_DW.INPUT_5_1_1_Discrete[0] = !(EQV_B.INPUT_5_1_1[0] ==
    EQV_DW.INPUT_5_1_1_Discrete[1]);
  EQV_DW.INPUT_5_1_1_Discrete[1] = EQV_B.INPUT_5_1_1[0];
  EQV_B.INPUT_5_1_1[0] = EQV_DW.INPUT_5_1_1_Discrete[1];
  EQV_B.INPUT_5_1_1[3] = EQV_DW.INPUT_5_1_1_Discrete[0];
  rtb_Memory8 *= EQV_DW.Delay3_DSTATE[0];
  EQV_B.INPUT_6_1_1[0] = rtb_Memory8;
  EQV_B.INPUT_6_1_1[1] = 0.0;
  EQV_B.INPUT_6_1_1[2] = 0.0;
  EQV_DW.INPUT_6_1_1_Discrete[0] = !(EQV_B.INPUT_6_1_1[0] ==
    EQV_DW.INPUT_6_1_1_Discrete[1]);
  EQV_DW.INPUT_6_1_1_Discrete[1] = EQV_B.INPUT_6_1_1[0];
  EQV_B.INPUT_6_1_1[0] = EQV_DW.INPUT_6_1_1_Discrete[1];
  EQV_B.INPUT_6_1_1[3] = EQV_DW.INPUT_6_1_1_Discrete[0];
  simulationData = (NeslSimulationData *)EQV_DW.STATE_1_SimData;
  time_tmp = ((EQV_M->Timing.clockTick0) * 0.2);
  time = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 18;
  simulationData->mData->mDiscStates.mX = &EQV_DW.STATE_1_Discrete[0];
  simulationData->mData->mModeVector.mN = 16;
  simulationData->mData->mModeVector.mX = &EQV_DW.STATE_1_Modes[0];
  rtb_Logic_idx_1 = false;
  simulationData->mData->mFoundZcEvents = rtb_Logic_idx_1;
  simulationData->mData->mIsMajorTimeStep = true;
  rtb_Logic_idx_1 = false;
  simulationData->mData->mIsSolverAssertCheck = rtb_Logic_idx_1;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = true;
  tmp_0[0] = 0;
  tmp[0] = EQV_B.INPUT_1_1_1[0];
  tmp[1] = EQV_B.INPUT_1_1_1[1];
  tmp[2] = EQV_B.INPUT_1_1_1[2];
  tmp[3] = EQV_B.INPUT_1_1_1[3];
  tmp_0[1] = 4;
  tmp[4] = EQV_B.INPUT_2_1_1[0];
  tmp[5] = EQV_B.INPUT_2_1_1[1];
  tmp[6] = EQV_B.INPUT_2_1_1[2];
  tmp[7] = EQV_B.INPUT_2_1_1[3];
  tmp_0[2] = 8;
  tmp[8] = EQV_B.INPUT_3_1_1[0];
  tmp[9] = EQV_B.INPUT_3_1_1[1];
  tmp[10] = EQV_B.INPUT_3_1_1[2];
  tmp[11] = EQV_B.INPUT_3_1_1[3];
  tmp_0[3] = 12;
  tmp[12] = EQV_B.INPUT_4_1_1[0];
  tmp[13] = EQV_B.INPUT_4_1_1[1];
  tmp[14] = EQV_B.INPUT_4_1_1[2];
  tmp[15] = EQV_B.INPUT_4_1_1[3];
  tmp_0[4] = 16;
  tmp[16] = EQV_B.INPUT_5_1_1[0];
  tmp[17] = EQV_B.INPUT_5_1_1[1];
  tmp[18] = EQV_B.INPUT_5_1_1[2];
  tmp[19] = EQV_B.INPUT_5_1_1[3];
  tmp_0[5] = 20;
  tmp[20] = EQV_B.INPUT_6_1_1[0];
  tmp[21] = EQV_B.INPUT_6_1_1[1];
  tmp[22] = EQV_B.INPUT_6_1_1[2];
  tmp[23] = EQV_B.INPUT_6_1_1[3];
  tmp_0[6] = 24;
  simulationData->mData->mInputValues.mN = 24;
  simulationData->mData->mInputValues.mX = &tmp[0];
  simulationData->mData->mInputOffsets.mN = 7;
  simulationData->mData->mInputOffsets.mX = &tmp_0[0];
  simulationData->mData->mOutputs.mN = 34;
  simulationData->mData->mOutputs.mX = &EQV_B.STATE_1[0];
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  time_tmp_0 = ((EQV_M->Timing.clockTick0) * 0.2);
  time_0 = time_tmp_0;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  isHit = 0;
  simulationData->mData->mSampleHits.mN = 1;
  simulationData->mData->mSampleHits.mX = &isHit;
  simulationData->mData->mIsFundamentalSampleHit = true;
  diagnosticManager = (NeuDiagnosticManager *)EQV_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  rowIdx = ne_simulator_method((NeslSimulator *)EQV_DW.STATE_1_Simulator,
    NESL_SIM_OUTPUTS, simulationData, diagnosticManager);
  if (rowIdx != 0) {
    rtb_Logic_idx_1 = error_buffer_is_empty(rtmGetErrorStatus(EQV_M));
    if (rtb_Logic_idx_1) {
      char *msg;
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(EQV_M, msg);
    }
  }

  simulationData = (NeslSimulationData *)EQV_DW.OUTPUT_1_0_SimData;
  time_1 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_1;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &EQV_DW.OUTPUT_1_0_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &EQV_DW.OUTPUT_1_0_Modes;
  rtb_Logic_idx_1 = false;
  simulationData->mData->mFoundZcEvents = rtb_Logic_idx_1;
  simulationData->mData->mIsMajorTimeStep = true;
  rtb_Logic_idx_1 = false;
  simulationData->mData->mIsSolverAssertCheck = rtb_Logic_idx_1;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = true;
  tmp_2[0] = 0;
  tmp_1[0] = EQV_B.INPUT_1_1_1[0];
  tmp_1[1] = EQV_B.INPUT_1_1_1[1];
  tmp_1[2] = EQV_B.INPUT_1_1_1[2];
  tmp_1[3] = EQV_B.INPUT_1_1_1[3];
  tmp_2[1] = 4;
  tmp_1[4] = EQV_B.INPUT_2_1_1[0];
  tmp_1[5] = EQV_B.INPUT_2_1_1[1];
  tmp_1[6] = EQV_B.INPUT_2_1_1[2];
  tmp_1[7] = EQV_B.INPUT_2_1_1[3];
  tmp_2[2] = 8;
  tmp_1[8] = EQV_B.INPUT_3_1_1[0];
  tmp_1[9] = EQV_B.INPUT_3_1_1[1];
  tmp_1[10] = EQV_B.INPUT_3_1_1[2];
  tmp_1[11] = EQV_B.INPUT_3_1_1[3];
  tmp_2[3] = 12;
  tmp_1[12] = EQV_B.INPUT_4_1_1[0];
  tmp_1[13] = EQV_B.INPUT_4_1_1[1];
  tmp_1[14] = EQV_B.INPUT_4_1_1[2];
  tmp_1[15] = EQV_B.INPUT_4_1_1[3];
  tmp_2[4] = 16;
  tmp_1[16] = EQV_B.INPUT_5_1_1[0];
  tmp_1[17] = EQV_B.INPUT_5_1_1[1];
  tmp_1[18] = EQV_B.INPUT_5_1_1[2];
  tmp_1[19] = EQV_B.INPUT_5_1_1[3];
  tmp_2[5] = 20;
  tmp_1[20] = EQV_B.INPUT_6_1_1[0];
  tmp_1[21] = EQV_B.INPUT_6_1_1[1];
  tmp_1[22] = EQV_B.INPUT_6_1_1[2];
  tmp_1[23] = EQV_B.INPUT_6_1_1[3];
  tmp_2[6] = 24;
  memcpy(&tmp_1[24], &EQV_B.STATE_1[0], 34U * sizeof(real_T));
  tmp_2[7] = 58;
  simulationData->mData->mInputValues.mN = 58;
  simulationData->mData->mInputValues.mX = &tmp_1[0];
  simulationData->mData->mInputOffsets.mN = 8;
  simulationData->mData->mInputOffsets.mX = &tmp_2[0];
  simulationData->mData->mOutputs.mN = 2;
  simulationData->mData->mOutputs.mX = &rtb_OUTPUT_1_0[0];
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  time_2 = time_tmp_0;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_2;
  isHit_0 = 0;
  simulationData->mData->mSampleHits.mN = 1;
  simulationData->mData->mSampleHits.mX = &isHit_0;
  simulationData->mData->mIsFundamentalSampleHit = true;
  diagnosticManager = (NeuDiagnosticManager *)EQV_DW.OUTPUT_1_0_DiagMgr;
  diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  rowIdx = ne_simulator_method((NeslSimulator *)EQV_DW.OUTPUT_1_0_Simulator,
    NESL_SIM_OUTPUTS, simulationData, diagnosticManager);
  if (rowIdx != 0) {
    rtb_Logic_idx_1 = error_buffer_is_empty(rtmGetErrorStatus(EQV_M));
    if (rtb_Logic_idx_1) {
      char *msg_0;
      msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
      rtmSetErrorStatus(EQV_M, msg_0);
    }
  }

  rtb_Add = rtb_OUTPUT_1_0[0] + EQV_U.CurrentLevel;
  simulationData = (NeslSimulationData *)EQV_DW.OUTPUT_1_1_SimData;
  time_3 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_3;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &EQV_DW.OUTPUT_1_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &EQV_DW.OUTPUT_1_1_Modes;
  rtb_Logic_idx_1 = false;
  simulationData->mData->mFoundZcEvents = rtb_Logic_idx_1;
  simulationData->mData->mIsMajorTimeStep = true;
  rtb_Logic_idx_1 = false;
  simulationData->mData->mIsSolverAssertCheck = rtb_Logic_idx_1;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = true;
  tmp_4[0] = 0;
  tmp_3[0] = EQV_B.INPUT_1_1_1[0];
  tmp_3[1] = EQV_B.INPUT_1_1_1[1];
  tmp_3[2] = EQV_B.INPUT_1_1_1[2];
  tmp_3[3] = EQV_B.INPUT_1_1_1[3];
  tmp_4[1] = 4;
  tmp_3[4] = EQV_B.INPUT_2_1_1[0];
  tmp_3[5] = EQV_B.INPUT_2_1_1[1];
  tmp_3[6] = EQV_B.INPUT_2_1_1[2];
  tmp_3[7] = EQV_B.INPUT_2_1_1[3];
  tmp_4[2] = 8;
  tmp_3[8] = EQV_B.INPUT_3_1_1[0];
  tmp_3[9] = EQV_B.INPUT_3_1_1[1];
  tmp_3[10] = EQV_B.INPUT_3_1_1[2];
  tmp_3[11] = EQV_B.INPUT_3_1_1[3];
  tmp_4[3] = 12;
  tmp_3[12] = EQV_B.INPUT_4_1_1[0];
  tmp_3[13] = EQV_B.INPUT_4_1_1[1];
  tmp_3[14] = EQV_B.INPUT_4_1_1[2];
  tmp_3[15] = EQV_B.INPUT_4_1_1[3];
  tmp_4[4] = 16;
  tmp_3[16] = EQV_B.INPUT_5_1_1[0];
  tmp_3[17] = EQV_B.INPUT_5_1_1[1];
  tmp_3[18] = EQV_B.INPUT_5_1_1[2];
  tmp_3[19] = EQV_B.INPUT_5_1_1[3];
  tmp_4[5] = 20;
  tmp_3[20] = EQV_B.INPUT_6_1_1[0];
  tmp_3[21] = EQV_B.INPUT_6_1_1[1];
  tmp_3[22] = EQV_B.INPUT_6_1_1[2];
  tmp_3[23] = EQV_B.INPUT_6_1_1[3];
  tmp_4[6] = 24;
  memcpy(&tmp_3[24], &EQV_B.STATE_1[0], 34U * sizeof(real_T));
  tmp_4[7] = 58;
  simulationData->mData->mInputValues.mN = 58;
  simulationData->mData->mInputValues.mX = &tmp_3[0];
  simulationData->mData->mInputOffsets.mN = 8;
  simulationData->mData->mInputOffsets.mX = &tmp_4[0];
  simulationData->mData->mOutputs.mN = 1;
  simulationData->mData->mOutputs.mX = &rtb_OUTPUT_1_1;
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  time_4 = time_tmp_0;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_4;
  isHit_1 = 0;
  simulationData->mData->mSampleHits.mN = 1;
  simulationData->mData->mSampleHits.mX = &isHit_1;
  simulationData->mData->mIsFundamentalSampleHit = true;
  diagnosticManager = (NeuDiagnosticManager *)EQV_DW.OUTPUT_1_1_DiagMgr;
  diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  rowIdx = ne_simulator_method((NeslSimulator *)EQV_DW.OUTPUT_1_1_Simulator,
    NESL_SIM_OUTPUTS, simulationData, diagnosticManager);
  if (rowIdx != 0) {
    rtb_Logic_idx_1 = error_buffer_is_empty(rtmGetErrorStatus(EQV_M));
    if (rtb_Logic_idx_1) {
      char *msg_1;
      msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
      rtmSetErrorStatus(EQV_M, msg_1);
    }
  }

  EQV_Y.AMS_error_latched = EQV_DW.Memory4_PreviousInput;
  EQV_Y.IMD_error_latched = EQV_DW.Memory5_PreviousInput;
  EQV_Y.Current = EQV_DW.Memory1_PreviousInput;
  EQV_Y.VehicleVoltage = EQV_DW.Memory2_PreviousInput;
  EQV_Y.AccumulatorVoltage = EQV_DW.Memory3_PreviousInput;
  EQV_Y.AirMinus = EQV_DW.Memory6_PreviousInput;
  EQV_Y.AirPlus = EQV_DW.Memory7_PreviousInput;
  EQV_Y.Precharge = EQV_DW.Memory8_PreviousInput;
  EQV_DW.Memory_PreviousInput = rtb_Logic_idx_0;
  EQV_DW.Memory_PreviousInput_m = rtb_Logic_a_idx_0;
  EQV_DW.Delay1_DSTATE = EQV_U.EnablePrecharge;
  EQV_DW.Delay2_DSTATE[0] = EQV_DW.Delay2_DSTATE[1];
  EQV_DW.Delay3_DSTATE[0] = EQV_DW.Delay3_DSTATE[1];
  EQV_DW.Delay2_DSTATE[1] = EQV_DW.Delay2_DSTATE[2];
  EQV_DW.Delay3_DSTATE[1] = EQV_DW.Delay3_DSTATE[2];
  EQV_DW.Delay2_DSTATE[2] = EQV_U.EnableAirPlus;
  EQV_DW.Delay3_DSTATE[2] = EQV_U.EnableAirMinus;
  simulationData = (NeslSimulationData *)EQV_DW.STATE_1_SimData;
  time_5 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_5;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 18;
  simulationData->mData->mDiscStates.mX = &EQV_DW.STATE_1_Discrete[0];
  simulationData->mData->mModeVector.mN = 16;
  simulationData->mData->mModeVector.mX = &EQV_DW.STATE_1_Modes[0];
  rtb_Logic_idx_1 = false;
  simulationData->mData->mFoundZcEvents = rtb_Logic_idx_1;
  simulationData->mData->mIsMajorTimeStep = true;
  rtb_Logic_idx_1 = false;
  simulationData->mData->mIsSolverAssertCheck = rtb_Logic_idx_1;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = true;
  tmp_6[0] = 0;
  tmp_5[0] = EQV_B.INPUT_1_1_1[0];
  tmp_5[1] = EQV_B.INPUT_1_1_1[1];
  tmp_5[2] = EQV_B.INPUT_1_1_1[2];
  tmp_5[3] = EQV_B.INPUT_1_1_1[3];
  tmp_6[1] = 4;
  tmp_5[4] = EQV_B.INPUT_2_1_1[0];
  tmp_5[5] = EQV_B.INPUT_2_1_1[1];
  tmp_5[6] = EQV_B.INPUT_2_1_1[2];
  tmp_5[7] = EQV_B.INPUT_2_1_1[3];
  tmp_6[2] = 8;
  tmp_5[8] = EQV_B.INPUT_3_1_1[0];
  tmp_5[9] = EQV_B.INPUT_3_1_1[1];
  tmp_5[10] = EQV_B.INPUT_3_1_1[2];
  tmp_5[11] = EQV_B.INPUT_3_1_1[3];
  tmp_6[3] = 12;
  tmp_5[12] = EQV_B.INPUT_4_1_1[0];
  tmp_5[13] = EQV_B.INPUT_4_1_1[1];
  tmp_5[14] = EQV_B.INPUT_4_1_1[2];
  tmp_5[15] = EQV_B.INPUT_4_1_1[3];
  tmp_6[4] = 16;
  tmp_5[16] = EQV_B.INPUT_5_1_1[0];
  tmp_5[17] = EQV_B.INPUT_5_1_1[1];
  tmp_5[18] = EQV_B.INPUT_5_1_1[2];
  tmp_5[19] = EQV_B.INPUT_5_1_1[3];
  tmp_6[5] = 20;
  tmp_5[20] = EQV_B.INPUT_6_1_1[0];
  tmp_5[21] = EQV_B.INPUT_6_1_1[1];
  tmp_5[22] = EQV_B.INPUT_6_1_1[2];
  tmp_5[23] = EQV_B.INPUT_6_1_1[3];
  tmp_6[6] = 24;
  simulationData->mData->mInputValues.mN = 24;
  simulationData->mData->mInputValues.mX = &tmp_5[0];
  simulationData->mData->mInputOffsets.mN = 7;
  simulationData->mData->mInputOffsets.mX = &tmp_6[0];
  diagnosticManager = (NeuDiagnosticManager *)EQV_DW.STATE_1_DiagMgr;
  diagnosticTree_2 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  rowIdx = ne_simulator_method((NeslSimulator *)EQV_DW.STATE_1_Simulator,
    NESL_SIM_UPDATE, simulationData, diagnosticManager);
  if (rowIdx != 0) {
    rtb_Logic_idx_1 = error_buffer_is_empty(rtmGetErrorStatus(EQV_M));
    if (rtb_Logic_idx_1) {
      char *msg_2;
      msg_2 = rtw_diagnostics_msg(diagnosticTree_2);
      rtmSetErrorStatus(EQV_M, msg_2);
    }
  }

  EQV_DW.Memory4_PreviousInput = rtb_Logic_idx_0;
  EQV_DW.Memory5_PreviousInput = rtb_Logic_a_idx_0;
  EQV_DW.Memory1_PreviousInput = rtb_Add;
  EQV_DW.Memory2_PreviousInput = rtb_OUTPUT_1_0[1];
  EQV_DW.Memory3_PreviousInput = rtb_OUTPUT_1_1;
  EQV_DW.Memory6_PreviousInput = rtb_Memory8;
  EQV_DW.Memory7_PreviousInput = Product1;
  EQV_DW.Memory8_PreviousInput = Product;
  EQV_M->Timing.clockTick0++;
}

void EQV_initialize(void)
{
  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeModelParameters modelParameters_1;
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    NeuDiagnosticTree *diagnosticTree_1;
    real_T tmp_2;
    int32_T tmp_3;
    boolean_T tmp_0;
    tmp = nesl_lease_simulator("EQV/EQV/Solver Configuration_1", 0, 0);
    EQV_DW.STATE_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(EQV_DW.STATE_1_Simulator);
    if (tmp_0) {
      EQV_627956e1_1_gateway();
      tmp = nesl_lease_simulator("EQV/EQV/Solver Configuration_1", 0, 0);
      EQV_DW.STATE_1_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    EQV_DW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    EQV_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters.mSolverTolerance = 0.001;
    modelParameters.mSolverAbsTol = 0.001;
    modelParameters.mSolverRelTol = 0.001;
    modelParameters.mVariableStepSolver = false;
    modelParameters.mIsUsingODEN = false;
    modelParameters.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters.mFixedStepSize = 0.001;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters.mRTWModifiedTimeStamp = 5.71617938E+8;
    modelParameters.mZcDisabled = true;
    tmp_2 = 0.001;
    modelParameters.mSolverTolerance = tmp_2;
    tmp_2 = 0.2;
    modelParameters.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters.mIsUsingODEN = tmp_0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)EQV_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)EQV_DW.STATE_1_Simulator,
      &modelParameters, diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(EQV_M));
      if (tmp_0) {
        char *msg;
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(EQV_M, msg);
      }
    }

    tmp = nesl_lease_simulator("EQV/EQV/Solver Configuration_1", 1, 0);
    EQV_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(EQV_DW.OUTPUT_1_0_Simulator);
    if (tmp_0) {
      EQV_627956e1_1_gateway();
      tmp = nesl_lease_simulator("EQV/EQV/Solver Configuration_1", 1, 0);
      EQV_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    EQV_DW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    EQV_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_0.mSolverTolerance = 0.001;
    modelParameters_0.mSolverAbsTol = 0.001;
    modelParameters_0.mSolverRelTol = 0.001;
    modelParameters_0.mVariableStepSolver = false;
    modelParameters_0.mIsUsingODEN = false;
    modelParameters_0.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_0.mFixedStepSize = 0.001;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_0.mRTWModifiedTimeStamp = 5.71617938E+8;
    modelParameters_0.mZcDisabled = true;
    tmp_2 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_2;
    tmp_2 = 0.2;
    modelParameters_0.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_0.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_0.mIsUsingODEN = tmp_0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)EQV_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      EQV_DW.OUTPUT_1_0_Simulator, &modelParameters_0, diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(EQV_M));
      if (tmp_0) {
        char *msg_0;
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(EQV_M, msg_0);
      }
    }

    tmp = nesl_lease_simulator("EQV/EQV/Solver Configuration_1", 1, 1);
    EQV_DW.OUTPUT_1_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(EQV_DW.OUTPUT_1_1_Simulator);
    if (tmp_0) {
      EQV_627956e1_1_gateway();
      tmp = nesl_lease_simulator("EQV/EQV/Solver Configuration_1", 1, 1);
      EQV_DW.OUTPUT_1_1_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    EQV_DW.OUTPUT_1_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    EQV_DW.OUTPUT_1_1_DiagMgr = (void *)diagnosticManager;
    modelParameters_1.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_1.mSolverTolerance = 0.001;
    modelParameters_1.mSolverAbsTol = 0.001;
    modelParameters_1.mSolverRelTol = 0.001;
    modelParameters_1.mVariableStepSolver = false;
    modelParameters_1.mIsUsingODEN = false;
    modelParameters_1.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_1.mFixedStepSize = 0.001;
    modelParameters_1.mStartTime = 0.0;
    modelParameters_1.mLoadInitialState = false;
    modelParameters_1.mUseSimState = false;
    modelParameters_1.mLinTrimCompile = false;
    modelParameters_1.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_1.mRTWModifiedTimeStamp = 5.71617938E+8;
    modelParameters_1.mZcDisabled = true;
    tmp_2 = 0.001;
    modelParameters_1.mSolverTolerance = tmp_2;
    tmp_2 = 0.2;
    modelParameters_1.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_1.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_1.mIsUsingODEN = tmp_0;
    modelParameters_1.mLoadInitialState = false;
    modelParameters_1.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)EQV_DW.OUTPUT_1_1_DiagMgr;
    diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      EQV_DW.OUTPUT_1_1_Simulator, &modelParameters_1, diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(EQV_M));
      if (tmp_0) {
        char *msg_1;
        msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
        rtmSetErrorStatus(EQV_M, msg_1);
      }
    }

    EQV_DW.Memory_PreviousInput = EQV_P.SRFlipFlop2_initial_condition;
    EQV_DW.Memory_PreviousInput_m = EQV_P.SRFlipFlop1_initial_condition;
    EQV_DW.Delay1_DSTATE = EQV_P.Delay1_InitialCondition;
    EQV_DW.Delay2_DSTATE[0] = EQV_P.Delay2_InitialCondition;
    EQV_DW.Delay3_DSTATE[0] = EQV_P.Delay3_InitialCondition;
    EQV_DW.Delay2_DSTATE[1] = EQV_P.Delay2_InitialCondition;
    EQV_DW.Delay3_DSTATE[1] = EQV_P.Delay3_InitialCondition;
    EQV_DW.Delay2_DSTATE[2] = EQV_P.Delay2_InitialCondition;
    EQV_DW.Delay3_DSTATE[2] = EQV_P.Delay3_InitialCondition;
    EQV_DW.Memory4_PreviousInput = EQV_P.Memory4_InitialCondition;
    EQV_DW.Memory5_PreviousInput = EQV_P.Memory5_InitialCondition;
    EQV_DW.Memory1_PreviousInput = EQV_P.Memory1_InitialCondition;
    EQV_DW.Memory2_PreviousInput = EQV_P.Memory2_InitialCondition;
    EQV_DW.Memory3_PreviousInput = EQV_P.Memory3_InitialCondition;
    EQV_DW.Memory6_PreviousInput = EQV_P.Memory6_InitialCondition;
    EQV_DW.Memory7_PreviousInput = EQV_P.Memory7_InitialCondition;
    EQV_DW.Memory8_PreviousInput = EQV_P.Memory8_InitialCondition;
  }
}

void EQV_terminate(void)
{
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)EQV_DW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)EQV_DW.STATE_1_SimData);
  nesl_erase_simulator("EQV/EQV/Solver Configuration_1");
  nesl_destroy_registry();
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    EQV_DW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)EQV_DW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("EQV/EQV/Solver Configuration_1");
  nesl_destroy_registry();
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    EQV_DW.OUTPUT_1_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)EQV_DW.OUTPUT_1_1_SimData);
  nesl_erase_simulator("EQV/EQV/Solver Configuration_1");
  nesl_destroy_registry();
}
