#include "SIM0.h"
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>
#include "look1_binlxpw.h"

B_SIM0_T SIM0_B;
DW_SIM0_T SIM0_DW;
ExtU_SIM0_T SIM0_U;
ExtY_SIM0_T SIM0_Y;
static RT_MODEL_SIM0_T SIM0_M_;
RT_MODEL_SIM0_T *const SIM0_M = &SIM0_M_;
void SIM0_step(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  NeuDiagnosticTree *diagnosticTree_0;
  NeuDiagnosticTree *diagnosticTree_1;
  NeuDiagnosticTree *diagnosticTree_2;
  NeuDiagnosticTree *diagnosticTree_3;
  real_T rtb_Memory15[126];
  real_T rtb_Memory21[126];
  real_T rtb_Rpz[126];
  real_T rtb_Rsz[126];
  real_T rtb_Switch[126];
  real_T rtb_tauz[126];
  real_T tmp_1[65];
  real_T tmp_3[65];
  real_T tmp_5[65];
  real_T tmp[32];
  real_T tmp_7[32];
  real_T rtb_Add2;
  real_T rtb_Current;
  real_T rtb_Exp;
  real_T rtb_Memory20;
  real_T rtb_OUTPUT_1_0;
  real_T rtb_Product9;
  real_T rtb_is_charge;
  real_T rtb_is_drive;
  real_T time;
  real_T time_0;
  real_T time_1;
  real_T time_2;
  real_T time_3;
  real_T time_4;
  real_T time_5;
  real_T time_6;
  real_T time_7;
  real_T y;
  int32_T i;
  int32_T isHit;
  int32_T isHit_0;
  int32_T isHit_1;
  int32_T isHit_2;
  int_T tmp_2[10];
  int_T tmp_4[10];
  int_T tmp_6[10];
  int_T tmp_0[9];
  int_T tmp_8[9];
  boolean_T rtb_Logic_a_idx_0;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_Logic_idx_1;
  rtb_Memory20 = SIM0_DW.Memory20_PreviousInput;
  rtb_Add2 = SIM0_DW.Memory9_PreviousInput;
  rtb_Exp = exp(SIM0_P.Cap_det / (SIM0_P.C_r * 3600.0) *
                SIM0_DW.Memory9_PreviousInput);
  for (i = 0; i < 126; i++) {
    rtb_Memory15[i] = SIM0_DW.Memory15_PreviousInput[i];
    y = SIM0_DW.Memory_PreviousInput[i] / SIM0_DW.Memory10_PreviousInput[i];
    rtb_is_charge = look1_binlxpw(y, SIM0_P.soc, SIM0_P.Rs, 12U);
    rtb_is_drive = look1_binlxpw(y, SIM0_P.soc, SIM0_P.tau, 12U);
    rtb_Current = rtb_is_charge * rtb_is_drive;
    rtb_is_charge = (rtb_is_charge + look1_binlxpw(y, SIM0_P.soc, SIM0_P.Rp, 12U))
      * SIM0_P.Ts;
    rtb_is_charge = (((2.0 * rtb_Current + rtb_is_charge) * rtb_Memory20 +
                      (rtb_is_charge - 2.0 * rtb_Current) *
                      SIM0_DW.Memory11_PreviousInput) - (SIM0_P.Ts - 2.0 *
      rtb_is_drive) * SIM0_DW.Memory12_PreviousInput[i]) / (2.0 * rtb_is_drive +
      SIM0_P.Ts);
    rtb_is_drive = rtb_is_charge + look1_binlxpw(y, SIM0_P.soc, SIM0_P.ocv, 12U);
    SIM0_Y.cell_voltages[i] = rtb_is_drive;
    SIM0_Y.cell_socs[i] = y;
    SIM0_Y.cell_capacities[i] = SIM0_DW.Memory10_PreviousInput[i];
    rtb_Memory21[i] = SIM0_DW.Memory10_PreviousInput[i] * rtb_Exp;
    rtb_Rsz[i] = rtb_is_charge;
    rtb_Rpz[i] = rtb_is_drive;
  }

  rtb_Exp = SIM0_P.Ts * rtb_Memory20;
  for (i = 0; i < 126; i++) {
    y = SIM0_DW.Memory21_PreviousInput[i] / SIM0_P.R_short
      * SIM0_DW.Memory19_PreviousInput[i] * SIM0_P.Gain_Gain + (rtb_Exp +
      SIM0_DW.Memory_PreviousInput[i]);
    if (y < SIM0_P.Constant1_Value) {
      rtb_tauz[i] = SIM0_P.Constant1_Value;
    } else {
      rtb_tauz[i] = y;
    }

    rtb_Switch[i] = y;
  }

  SIM0_B.INPUT_5_1_1[0] = 1.0;
  rtb_is_charge = 0.0;
  rtb_is_drive = 0.0;
  if (SIM0_DW.Memory6_PreviousInput != 0.0) {
    SIM0_B.INPUT_5_1_1[0] = 2.0;
    rtb_is_charge = 1.0;
  } else if (SIM0_DW.Memory7_PreviousInput != 0.0) {
    SIM0_B.INPUT_5_1_1[0] = 3.0;
    rtb_is_drive = 1.0;
  }

  y = rtb_Memory15[0];
  for (i = 0; i < 125; i++) {
    y += rtb_Memory15[i + 1];
  }

  if (SIM0_DW.Memory16_PreviousInput != 0.0) {
    rtb_Current = SIM0_DW.Memory17_PreviousInput - y;
    if (rtb_Current < 0.0) {
      rtb_Current = 0.0;
    }

    if (SIM0_DW.Memory18_PreviousInput < rtb_Current) {
      rtb_Current = SIM0_DW.Memory18_PreviousInput;
    }
  } else {
    rtb_Current = 0.0;
  }

  i = (int32_T)(((((uint32_T)(SIM0_DW.Memory1_PreviousInput != 0.0) << 1) +
                  (SIM0_DW.Memory2_PreviousInput != 0.0)) << 1) +
                SIM0_DW.Memory_PreviousInput_e);
  rtb_Logic_idx_0 = SIM0_P.Logic_table[(uint32_T)i];
  rtb_Logic_idx_1 = SIM0_P.Logic_table[i + 8U];
  i = (int32_T)(((((uint32_T)(SIM0_DW.Memory3_PreviousInput != 0.0) << 1) +
                  (SIM0_DW.Memory4_PreviousInput != 0.0)) << 1) +
                SIM0_DW.Memory_PreviousInput_m);
  rtb_Logic_a_idx_0 = SIM0_P.Logic_table_f[(uint32_T)i];
  rtb_Exp = (rtb_Logic_idx_1 ? (real_T)SIM0_P.Logic_table_f[i + 8U] : 0.0) *
    SIM0_DW.Memory5_PreviousInput;
  SIM0_Y.AIR_minus_closed = rtb_Exp * SIM0_DW.Delay3_DSTATE[0];
  SIM0_Y.AIR_plus_closed = rtb_Exp * SIM0_DW.Delay2_DSTATE[0];
  rtb_Product9 = SIM0_Y.AIR_minus_closed * SIM0_Y.AIR_plus_closed;
  SIM0_B.INPUT_7_1_1[0] = rtb_is_charge * rtb_Current * rtb_Product9;
  SIM0_B.INPUT_7_1_1[1] = 0.0;
  SIM0_B.INPUT_7_1_1[2] = 0.0;
  SIM0_DW.INPUT_7_1_1_Discrete[0] = !(SIM0_B.INPUT_7_1_1[0] ==
    SIM0_DW.INPUT_7_1_1_Discrete[1]);
  SIM0_DW.INPUT_7_1_1_Discrete[1] = SIM0_B.INPUT_7_1_1[0];
  SIM0_B.INPUT_7_1_1[0] = SIM0_DW.INPUT_7_1_1_Discrete[1];
  SIM0_B.INPUT_7_1_1[3] = SIM0_DW.INPUT_7_1_1_Discrete[0];
  rtb_is_charge = SIM0_DW.Memory22_PreviousInput;
  SIM0_B.INPUT_8_1_1[0] = rtb_is_drive * rtb_is_charge * rtb_Product9;
  SIM0_B.INPUT_8_1_1[1] = 0.0;
  SIM0_B.INPUT_8_1_1[2] = 0.0;
  SIM0_DW.INPUT_8_1_1_Discrete[0] = !(SIM0_B.INPUT_8_1_1[0] ==
    SIM0_DW.INPUT_8_1_1_Discrete[1]);
  SIM0_DW.INPUT_8_1_1_Discrete[1] = SIM0_B.INPUT_8_1_1[0];
  SIM0_B.INPUT_8_1_1[0] = SIM0_DW.INPUT_8_1_1_Discrete[1];
  SIM0_B.INPUT_8_1_1[3] = SIM0_DW.INPUT_8_1_1_Discrete[0];
  SIM0_B.INPUT_2_1_1[0] = y;
  SIM0_B.INPUT_2_1_1[1] = 0.0;
  SIM0_B.INPUT_2_1_1[2] = 0.0;
  SIM0_DW.INPUT_2_1_1_Discrete[0] = !(SIM0_B.INPUT_2_1_1[0] ==
    SIM0_DW.INPUT_2_1_1_Discrete[1]);
  SIM0_DW.INPUT_2_1_1_Discrete[1] = SIM0_B.INPUT_2_1_1[0];
  SIM0_B.INPUT_2_1_1[0] = SIM0_DW.INPUT_2_1_1_Discrete[1];
  SIM0_B.INPUT_2_1_1[3] = SIM0_DW.INPUT_2_1_1_Discrete[0];
  SIM0_B.INPUT_1_1_1[0] = y;
  SIM0_B.INPUT_1_1_1[1] = 0.0;
  SIM0_B.INPUT_1_1_1[2] = 0.0;
  SIM0_DW.INPUT_1_1_1_Discrete[0] = !(SIM0_B.INPUT_1_1_1[0] ==
    SIM0_DW.INPUT_1_1_1_Discrete[1]);
  SIM0_DW.INPUT_1_1_1_Discrete[1] = SIM0_B.INPUT_1_1_1[0];
  SIM0_B.INPUT_1_1_1[0] = SIM0_DW.INPUT_1_1_1_Discrete[1];
  SIM0_B.INPUT_1_1_1[3] = SIM0_DW.INPUT_1_1_1_Discrete[0];
  SIM0_Y.precharge_closed = rtb_Exp * SIM0_DW.Delay1_DSTATE;
  SIM0_B.INPUT_3_1_1[0] = SIM0_Y.precharge_closed;
  SIM0_B.INPUT_3_1_1[1] = 0.0;
  SIM0_B.INPUT_3_1_1[2] = 0.0;
  SIM0_DW.INPUT_3_1_1_Discrete[0] = !(SIM0_B.INPUT_3_1_1[0] ==
    SIM0_DW.INPUT_3_1_1_Discrete[1]);
  SIM0_DW.INPUT_3_1_1_Discrete[1] = SIM0_B.INPUT_3_1_1[0];
  SIM0_B.INPUT_3_1_1[0] = SIM0_DW.INPUT_3_1_1_Discrete[1];
  SIM0_B.INPUT_3_1_1[3] = SIM0_DW.INPUT_3_1_1_Discrete[0];
  SIM0_B.INPUT_4_1_1[0] = SIM0_Y.AIR_plus_closed;
  SIM0_B.INPUT_4_1_1[1] = 0.0;
  SIM0_B.INPUT_4_1_1[2] = 0.0;
  SIM0_DW.INPUT_4_1_1_Discrete[0] = !(SIM0_B.INPUT_4_1_1[0] ==
    SIM0_DW.INPUT_4_1_1_Discrete[1]);
  SIM0_DW.INPUT_4_1_1_Discrete[1] = SIM0_B.INPUT_4_1_1[0];
  SIM0_B.INPUT_4_1_1[0] = SIM0_DW.INPUT_4_1_1_Discrete[1];
  SIM0_B.INPUT_4_1_1[3] = SIM0_DW.INPUT_4_1_1_Discrete[0];
  SIM0_B.INPUT_5_1_1[1] = 0.0;
  SIM0_B.INPUT_5_1_1[2] = 0.0;
  SIM0_DW.INPUT_5_1_1_Discrete[0] = !(SIM0_B.INPUT_5_1_1[0] ==
    SIM0_DW.INPUT_5_1_1_Discrete[1]);
  SIM0_DW.INPUT_5_1_1_Discrete[1] = SIM0_B.INPUT_5_1_1[0];
  SIM0_B.INPUT_5_1_1[0] = SIM0_DW.INPUT_5_1_1_Discrete[1];
  SIM0_B.INPUT_5_1_1[3] = SIM0_DW.INPUT_5_1_1_Discrete[0];
  SIM0_B.INPUT_6_1_1[0] = SIM0_Y.AIR_minus_closed;
  SIM0_B.INPUT_6_1_1[1] = 0.0;
  SIM0_B.INPUT_6_1_1[2] = 0.0;
  SIM0_DW.INPUT_6_1_1_Discrete[0] = !(SIM0_B.INPUT_6_1_1[0] ==
    SIM0_DW.INPUT_6_1_1_Discrete[1]);
  SIM0_DW.INPUT_6_1_1_Discrete[1] = SIM0_B.INPUT_6_1_1[0];
  SIM0_B.INPUT_6_1_1[0] = SIM0_DW.INPUT_6_1_1_Discrete[1];
  SIM0_B.INPUT_6_1_1[3] = SIM0_DW.INPUT_6_1_1_Discrete[0];
  simulationData = (NeslSimulationData *)SIM0_DW.STATE_1_SimData;
  rtb_is_drive = ((SIM0_M->Timing.clockTick0) * 0.2);
  time = rtb_is_drive;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 17;
  simulationData->mData->mDiscStates.mX = &SIM0_DW.STATE_1_Discrete[0];
  simulationData->mData->mModeVector.mN = 16;
  simulationData->mData->mModeVector.mX = &SIM0_DW.STATE_1_Modes[0];
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
  tmp[0] = SIM0_B.INPUT_8_1_1[0];
  tmp[1] = SIM0_B.INPUT_8_1_1[1];
  tmp[2] = SIM0_B.INPUT_8_1_1[2];
  tmp[3] = SIM0_B.INPUT_8_1_1[3];
  tmp_0[1] = 4;
  tmp[4] = SIM0_B.INPUT_7_1_1[0];
  tmp[5] = SIM0_B.INPUT_7_1_1[1];
  tmp[6] = SIM0_B.INPUT_7_1_1[2];
  tmp[7] = SIM0_B.INPUT_7_1_1[3];
  tmp_0[2] = 8;
  tmp[8] = SIM0_B.INPUT_2_1_1[0];
  tmp[9] = SIM0_B.INPUT_2_1_1[1];
  tmp[10] = SIM0_B.INPUT_2_1_1[2];
  tmp[11] = SIM0_B.INPUT_2_1_1[3];
  tmp_0[3] = 12;
  tmp[12] = SIM0_B.INPUT_1_1_1[0];
  tmp[13] = SIM0_B.INPUT_1_1_1[1];
  tmp[14] = SIM0_B.INPUT_1_1_1[2];
  tmp[15] = SIM0_B.INPUT_1_1_1[3];
  tmp_0[4] = 16;
  tmp[16] = SIM0_B.INPUT_3_1_1[0];
  tmp[17] = SIM0_B.INPUT_3_1_1[1];
  tmp[18] = SIM0_B.INPUT_3_1_1[2];
  tmp[19] = SIM0_B.INPUT_3_1_1[3];
  tmp_0[5] = 20;
  tmp[20] = SIM0_B.INPUT_4_1_1[0];
  tmp[21] = SIM0_B.INPUT_4_1_1[1];
  tmp[22] = SIM0_B.INPUT_4_1_1[2];
  tmp[23] = SIM0_B.INPUT_4_1_1[3];
  tmp_0[6] = 24;
  tmp[24] = SIM0_B.INPUT_5_1_1[0];
  tmp[25] = SIM0_B.INPUT_5_1_1[1];
  tmp[26] = SIM0_B.INPUT_5_1_1[2];
  tmp[27] = SIM0_B.INPUT_5_1_1[3];
  tmp_0[7] = 28;
  tmp[28] = SIM0_B.INPUT_6_1_1[0];
  tmp[29] = SIM0_B.INPUT_6_1_1[1];
  tmp[30] = SIM0_B.INPUT_6_1_1[2];
  tmp[31] = SIM0_B.INPUT_6_1_1[3];
  tmp_0[8] = 32;
  simulationData->mData->mInputValues.mN = 32;
  simulationData->mData->mInputValues.mX = &tmp[0];
  simulationData->mData->mInputOffsets.mN = 9;
  simulationData->mData->mInputOffsets.mX = &tmp_0[0];
  simulationData->mData->mOutputs.mN = 33;
  simulationData->mData->mOutputs.mX = &SIM0_B.STATE_1[0];
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  y = ((SIM0_M->Timing.clockTick0) * 0.2);
  time_0 = y;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  isHit = 0;
  simulationData->mData->mSampleHits.mN = 1;
  simulationData->mData->mSampleHits.mX = &isHit;
  simulationData->mData->mIsFundamentalSampleHit = true;
  diagnosticManager = (NeuDiagnosticManager *)SIM0_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  i = ne_simulator_method((NeslSimulator *)SIM0_DW.STATE_1_Simulator,
    NESL_SIM_OUTPUTS, simulationData, diagnosticManager);
  if (i != 0) {
    rtb_Logic_idx_1 = error_buffer_is_empty(rtmGetErrorStatus(SIM0_M));
    if (rtb_Logic_idx_1) {
      char *msg;
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(SIM0_M, msg);
    }
  }

  SIM0_Y.IMD_error_latched = rtb_Logic_a_idx_0;
  SIM0_Y.AMS_error_latched = rtb_Logic_idx_0;
  simulationData = (NeslSimulationData *)SIM0_DW.OUTPUT_1_0_SimData;
  time_1 = rtb_is_drive;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_1;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &SIM0_DW.OUTPUT_1_0_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &SIM0_DW.OUTPUT_1_0_Modes;
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
  tmp_1[0] = SIM0_B.INPUT_8_1_1[0];
  tmp_1[1] = SIM0_B.INPUT_8_1_1[1];
  tmp_1[2] = SIM0_B.INPUT_8_1_1[2];
  tmp_1[3] = SIM0_B.INPUT_8_1_1[3];
  tmp_2[1] = 4;
  tmp_1[4] = SIM0_B.INPUT_7_1_1[0];
  tmp_1[5] = SIM0_B.INPUT_7_1_1[1];
  tmp_1[6] = SIM0_B.INPUT_7_1_1[2];
  tmp_1[7] = SIM0_B.INPUT_7_1_1[3];
  tmp_2[2] = 8;
  tmp_1[8] = SIM0_B.INPUT_2_1_1[0];
  tmp_1[9] = SIM0_B.INPUT_2_1_1[1];
  tmp_1[10] = SIM0_B.INPUT_2_1_1[2];
  tmp_1[11] = SIM0_B.INPUT_2_1_1[3];
  tmp_2[3] = 12;
  tmp_1[12] = SIM0_B.INPUT_1_1_1[0];
  tmp_1[13] = SIM0_B.INPUT_1_1_1[1];
  tmp_1[14] = SIM0_B.INPUT_1_1_1[2];
  tmp_1[15] = SIM0_B.INPUT_1_1_1[3];
  tmp_2[4] = 16;
  tmp_1[16] = SIM0_B.INPUT_3_1_1[0];
  tmp_1[17] = SIM0_B.INPUT_3_1_1[1];
  tmp_1[18] = SIM0_B.INPUT_3_1_1[2];
  tmp_1[19] = SIM0_B.INPUT_3_1_1[3];
  tmp_2[5] = 20;
  tmp_1[20] = SIM0_B.INPUT_4_1_1[0];
  tmp_1[21] = SIM0_B.INPUT_4_1_1[1];
  tmp_1[22] = SIM0_B.INPUT_4_1_1[2];
  tmp_1[23] = SIM0_B.INPUT_4_1_1[3];
  tmp_2[6] = 24;
  tmp_1[24] = SIM0_B.INPUT_5_1_1[0];
  tmp_1[25] = SIM0_B.INPUT_5_1_1[1];
  tmp_1[26] = SIM0_B.INPUT_5_1_1[2];
  tmp_1[27] = SIM0_B.INPUT_5_1_1[3];
  tmp_2[7] = 28;
  tmp_1[28] = SIM0_B.INPUT_6_1_1[0];
  tmp_1[29] = SIM0_B.INPUT_6_1_1[1];
  tmp_1[30] = SIM0_B.INPUT_6_1_1[2];
  tmp_1[31] = SIM0_B.INPUT_6_1_1[3];
  tmp_2[8] = 32;
  memcpy(&tmp_1[32], &SIM0_B.STATE_1[0], 33U * sizeof(real_T));
  tmp_2[9] = 65;
  simulationData->mData->mInputValues.mN = 65;
  simulationData->mData->mInputValues.mX = &tmp_1[0];
  simulationData->mData->mInputOffsets.mN = 10;
  simulationData->mData->mInputOffsets.mX = &tmp_2[0];
  simulationData->mData->mOutputs.mN = 1;
  simulationData->mData->mOutputs.mX = &rtb_OUTPUT_1_0;
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  time_2 = y;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_2;
  isHit_0 = 0;
  simulationData->mData->mSampleHits.mN = 1;
  simulationData->mData->mSampleHits.mX = &isHit_0;
  simulationData->mData->mIsFundamentalSampleHit = true;
  diagnosticManager = (NeuDiagnosticManager *)SIM0_DW.OUTPUT_1_0_DiagMgr;
  diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  i = ne_simulator_method((NeslSimulator *)SIM0_DW.OUTPUT_1_0_Simulator,
    NESL_SIM_OUTPUTS, simulationData, diagnosticManager);
  if (i != 0) {
    rtb_Logic_idx_1 = error_buffer_is_empty(rtmGetErrorStatus(SIM0_M));
    if (rtb_Logic_idx_1) {
      char *msg_0;
      msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
      rtmSetErrorStatus(SIM0_M, msg_0);
    }
  }

  SIM0_Y.current = rtb_OUTPUT_1_0;
  simulationData = (NeslSimulationData *)SIM0_DW.OUTPUT_1_1_SimData;
  time_3 = rtb_is_drive;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_3;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &SIM0_DW.OUTPUT_1_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &SIM0_DW.OUTPUT_1_1_Modes;
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
  tmp_3[0] = SIM0_B.INPUT_8_1_1[0];
  tmp_3[1] = SIM0_B.INPUT_8_1_1[1];
  tmp_3[2] = SIM0_B.INPUT_8_1_1[2];
  tmp_3[3] = SIM0_B.INPUT_8_1_1[3];
  tmp_4[1] = 4;
  tmp_3[4] = SIM0_B.INPUT_7_1_1[0];
  tmp_3[5] = SIM0_B.INPUT_7_1_1[1];
  tmp_3[6] = SIM0_B.INPUT_7_1_1[2];
  tmp_3[7] = SIM0_B.INPUT_7_1_1[3];
  tmp_4[2] = 8;
  tmp_3[8] = SIM0_B.INPUT_2_1_1[0];
  tmp_3[9] = SIM0_B.INPUT_2_1_1[1];
  tmp_3[10] = SIM0_B.INPUT_2_1_1[2];
  tmp_3[11] = SIM0_B.INPUT_2_1_1[3];
  tmp_4[3] = 12;
  tmp_3[12] = SIM0_B.INPUT_1_1_1[0];
  tmp_3[13] = SIM0_B.INPUT_1_1_1[1];
  tmp_3[14] = SIM0_B.INPUT_1_1_1[2];
  tmp_3[15] = SIM0_B.INPUT_1_1_1[3];
  tmp_4[4] = 16;
  tmp_3[16] = SIM0_B.INPUT_3_1_1[0];
  tmp_3[17] = SIM0_B.INPUT_3_1_1[1];
  tmp_3[18] = SIM0_B.INPUT_3_1_1[2];
  tmp_3[19] = SIM0_B.INPUT_3_1_1[3];
  tmp_4[5] = 20;
  tmp_3[20] = SIM0_B.INPUT_4_1_1[0];
  tmp_3[21] = SIM0_B.INPUT_4_1_1[1];
  tmp_3[22] = SIM0_B.INPUT_4_1_1[2];
  tmp_3[23] = SIM0_B.INPUT_4_1_1[3];
  tmp_4[6] = 24;
  tmp_3[24] = SIM0_B.INPUT_5_1_1[0];
  tmp_3[25] = SIM0_B.INPUT_5_1_1[1];
  tmp_3[26] = SIM0_B.INPUT_5_1_1[2];
  tmp_3[27] = SIM0_B.INPUT_5_1_1[3];
  tmp_4[7] = 28;
  tmp_3[28] = SIM0_B.INPUT_6_1_1[0];
  tmp_3[29] = SIM0_B.INPUT_6_1_1[1];
  tmp_3[30] = SIM0_B.INPUT_6_1_1[2];
  tmp_3[31] = SIM0_B.INPUT_6_1_1[3];
  tmp_4[8] = 32;
  memcpy(&tmp_3[32], &SIM0_B.STATE_1[0], 33U * sizeof(real_T));
  tmp_4[9] = 65;
  simulationData->mData->mInputValues.mN = 65;
  simulationData->mData->mInputValues.mX = &tmp_3[0];
  simulationData->mData->mInputOffsets.mN = 10;
  simulationData->mData->mInputOffsets.mX = &tmp_4[0];
  simulationData->mData->mOutputs.mN = 1;
  simulationData->mData->mOutputs.mX = &rtb_is_charge;
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  time_4 = y;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_4;
  isHit_1 = 0;
  simulationData->mData->mSampleHits.mN = 1;
  simulationData->mData->mSampleHits.mX = &isHit_1;
  simulationData->mData->mIsFundamentalSampleHit = true;
  diagnosticManager = (NeuDiagnosticManager *)SIM0_DW.OUTPUT_1_1_DiagMgr;
  diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  i = ne_simulator_method((NeslSimulator *)SIM0_DW.OUTPUT_1_1_Simulator,
    NESL_SIM_OUTPUTS, simulationData, diagnosticManager);
  if (i != 0) {
    rtb_Logic_idx_1 = error_buffer_is_empty(rtmGetErrorStatus(SIM0_M));
    if (rtb_Logic_idx_1) {
      char *msg_1;
      msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
      rtmSetErrorStatus(SIM0_M, msg_1);
    }
  }

  SIM0_Y.vehicle_voltage = rtb_is_charge;
  simulationData = (NeslSimulationData *)SIM0_DW.OUTPUT_1_2_SimData;
  time_5 = rtb_is_drive;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_5;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &SIM0_DW.OUTPUT_1_2_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &SIM0_DW.OUTPUT_1_2_Modes;
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
  tmp_5[0] = SIM0_B.INPUT_8_1_1[0];
  tmp_5[1] = SIM0_B.INPUT_8_1_1[1];
  tmp_5[2] = SIM0_B.INPUT_8_1_1[2];
  tmp_5[3] = SIM0_B.INPUT_8_1_1[3];
  tmp_6[1] = 4;
  tmp_5[4] = SIM0_B.INPUT_7_1_1[0];
  tmp_5[5] = SIM0_B.INPUT_7_1_1[1];
  tmp_5[6] = SIM0_B.INPUT_7_1_1[2];
  tmp_5[7] = SIM0_B.INPUT_7_1_1[3];
  tmp_6[2] = 8;
  tmp_5[8] = SIM0_B.INPUT_2_1_1[0];
  tmp_5[9] = SIM0_B.INPUT_2_1_1[1];
  tmp_5[10] = SIM0_B.INPUT_2_1_1[2];
  tmp_5[11] = SIM0_B.INPUT_2_1_1[3];
  tmp_6[3] = 12;
  tmp_5[12] = SIM0_B.INPUT_1_1_1[0];
  tmp_5[13] = SIM0_B.INPUT_1_1_1[1];
  tmp_5[14] = SIM0_B.INPUT_1_1_1[2];
  tmp_5[15] = SIM0_B.INPUT_1_1_1[3];
  tmp_6[4] = 16;
  tmp_5[16] = SIM0_B.INPUT_3_1_1[0];
  tmp_5[17] = SIM0_B.INPUT_3_1_1[1];
  tmp_5[18] = SIM0_B.INPUT_3_1_1[2];
  tmp_5[19] = SIM0_B.INPUT_3_1_1[3];
  tmp_6[5] = 20;
  tmp_5[20] = SIM0_B.INPUT_4_1_1[0];
  tmp_5[21] = SIM0_B.INPUT_4_1_1[1];
  tmp_5[22] = SIM0_B.INPUT_4_1_1[2];
  tmp_5[23] = SIM0_B.INPUT_4_1_1[3];
  tmp_6[6] = 24;
  tmp_5[24] = SIM0_B.INPUT_5_1_1[0];
  tmp_5[25] = SIM0_B.INPUT_5_1_1[1];
  tmp_5[26] = SIM0_B.INPUT_5_1_1[2];
  tmp_5[27] = SIM0_B.INPUT_5_1_1[3];
  tmp_6[7] = 28;
  tmp_5[28] = SIM0_B.INPUT_6_1_1[0];
  tmp_5[29] = SIM0_B.INPUT_6_1_1[1];
  tmp_5[30] = SIM0_B.INPUT_6_1_1[2];
  tmp_5[31] = SIM0_B.INPUT_6_1_1[3];
  tmp_6[8] = 32;
  memcpy(&tmp_5[32], &SIM0_B.STATE_1[0], 33U * sizeof(real_T));
  tmp_6[9] = 65;
  simulationData->mData->mInputValues.mN = 65;
  simulationData->mData->mInputValues.mX = &tmp_5[0];
  simulationData->mData->mInputOffsets.mN = 10;
  simulationData->mData->mInputOffsets.mX = &tmp_6[0];
  simulationData->mData->mOutputs.mN = 1;
  simulationData->mData->mOutputs.mX = &rtb_is_charge;
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  time_6 = y;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_6;
  isHit_2 = 0;
  simulationData->mData->mSampleHits.mN = 1;
  simulationData->mData->mSampleHits.mX = &isHit_2;
  simulationData->mData->mIsFundamentalSampleHit = true;
  diagnosticManager = (NeuDiagnosticManager *)SIM0_DW.OUTPUT_1_2_DiagMgr;
  diagnosticTree_2 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  i = ne_simulator_method((NeslSimulator *)SIM0_DW.OUTPUT_1_2_Simulator,
    NESL_SIM_OUTPUTS, simulationData, diagnosticManager);
  if (i != 0) {
    rtb_Logic_idx_1 = error_buffer_is_empty(rtmGetErrorStatus(SIM0_M));
    if (rtb_Logic_idx_1) {
      char *msg_2;
      msg_2 = rtw_diagnostics_msg(diagnosticTree_2);
      rtmSetErrorStatus(SIM0_M, msg_2);
    }
  }

  SIM0_Y.accumulator_voltage = rtb_is_charge;
  SIM0_Y.SC_probe = rtb_Exp;
  memcpy(&SIM0_Y.cell_temperatures[0], &SIM0_P.cTmp[0], 60U * sizeof(real_T));
  SIM0_Y.IMD_ok = SIM0_P.IMD_ok;
  memcpy(&SIM0_DW.Memory15_PreviousInput[0], &rtb_Rpz[0], 126U * sizeof(real_T));
  memcpy(&SIM0_DW.Memory12_PreviousInput[0], &rtb_Rsz[0], 126U * sizeof(real_T));
  SIM0_DW.Memory20_PreviousInput = rtb_OUTPUT_1_0;
  SIM0_DW.Memory11_PreviousInput = rtb_Memory20;
  SIM0_DW.Memory9_PreviousInput = fabs(rtb_Memory20 + rtb_Add2);
  for (i = 0; i < 126; i++) {
    y = rtb_Memory21[i];
    if (rtb_Switch[i] > y) {
      SIM0_DW.Memory_PreviousInput[i] = y;
    } else {
      SIM0_DW.Memory_PreviousInput[i] = rtb_tauz[i];
    }

    SIM0_DW.Memory10_PreviousInput[i] = y;
    SIM0_DW.Memory19_PreviousInput[i] = SIM0_U.BalanceOut[i];
    SIM0_DW.Memory21_PreviousInput[i] = rtb_Rpz[i];
  }

  SIM0_DW.Memory6_PreviousInput = SIM0_U.charge;
  SIM0_DW.Memory7_PreviousInput = SIM0_U.drive;
  SIM0_DW.Memory16_PreviousInput = SIM0_U.EnableCharge;
  SIM0_DW.Memory17_PreviousInput = SIM0_U.VoltageLimit;
  SIM0_DW.Memory18_PreviousInput = SIM0_U.CurrentLimit;
  SIM0_DW.Memory1_PreviousInput = SIM0_U.AMS_error;
  SIM0_DW.Memory2_PreviousInput = SIM0_U.AMS_error_reset;
  SIM0_DW.Memory_PreviousInput_e = rtb_Logic_idx_0;
  SIM0_DW.Memory3_PreviousInput = SIM0_U.IMD_error;
  SIM0_DW.Memory4_PreviousInput = SIM0_U.IMD_error_reset;
  SIM0_DW.Memory_PreviousInput_m = rtb_Logic_a_idx_0;
  SIM0_DW.Memory5_PreviousInput = SIM0_U.SC;
  SIM0_DW.Delay3_DSTATE[0] = SIM0_DW.Delay3_DSTATE[1];
  SIM0_DW.Delay3_DSTATE[1] = SIM0_DW.Memory8_PreviousInput;
  SIM0_DW.Delay2_DSTATE[0] = SIM0_DW.Delay2_DSTATE[1];
  SIM0_DW.Delay2_DSTATE[1] = SIM0_DW.Memory13_PreviousInput;
  SIM0_DW.Memory22_PreviousInput = SIM0_U.drive_current;
  SIM0_DW.Delay1_DSTATE = SIM0_DW.Memory14_PreviousInput;
  simulationData = (NeslSimulationData *)SIM0_DW.STATE_1_SimData;
  time_7 = rtb_is_drive;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_7;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 17;
  simulationData->mData->mDiscStates.mX = &SIM0_DW.STATE_1_Discrete[0];
  simulationData->mData->mModeVector.mN = 16;
  simulationData->mData->mModeVector.mX = &SIM0_DW.STATE_1_Modes[0];
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
  tmp_8[0] = 0;
  tmp_7[0] = SIM0_B.INPUT_8_1_1[0];
  tmp_7[1] = SIM0_B.INPUT_8_1_1[1];
  tmp_7[2] = SIM0_B.INPUT_8_1_1[2];
  tmp_7[3] = SIM0_B.INPUT_8_1_1[3];
  tmp_8[1] = 4;
  tmp_7[4] = SIM0_B.INPUT_7_1_1[0];
  tmp_7[5] = SIM0_B.INPUT_7_1_1[1];
  tmp_7[6] = SIM0_B.INPUT_7_1_1[2];
  tmp_7[7] = SIM0_B.INPUT_7_1_1[3];
  tmp_8[2] = 8;
  tmp_7[8] = SIM0_B.INPUT_2_1_1[0];
  tmp_7[9] = SIM0_B.INPUT_2_1_1[1];
  tmp_7[10] = SIM0_B.INPUT_2_1_1[2];
  tmp_7[11] = SIM0_B.INPUT_2_1_1[3];
  tmp_8[3] = 12;
  tmp_7[12] = SIM0_B.INPUT_1_1_1[0];
  tmp_7[13] = SIM0_B.INPUT_1_1_1[1];
  tmp_7[14] = SIM0_B.INPUT_1_1_1[2];
  tmp_7[15] = SIM0_B.INPUT_1_1_1[3];
  tmp_8[4] = 16;
  tmp_7[16] = SIM0_B.INPUT_3_1_1[0];
  tmp_7[17] = SIM0_B.INPUT_3_1_1[1];
  tmp_7[18] = SIM0_B.INPUT_3_1_1[2];
  tmp_7[19] = SIM0_B.INPUT_3_1_1[3];
  tmp_8[5] = 20;
  tmp_7[20] = SIM0_B.INPUT_4_1_1[0];
  tmp_7[21] = SIM0_B.INPUT_4_1_1[1];
  tmp_7[22] = SIM0_B.INPUT_4_1_1[2];
  tmp_7[23] = SIM0_B.INPUT_4_1_1[3];
  tmp_8[6] = 24;
  tmp_7[24] = SIM0_B.INPUT_5_1_1[0];
  tmp_7[25] = SIM0_B.INPUT_5_1_1[1];
  tmp_7[26] = SIM0_B.INPUT_5_1_1[2];
  tmp_7[27] = SIM0_B.INPUT_5_1_1[3];
  tmp_8[7] = 28;
  tmp_7[28] = SIM0_B.INPUT_6_1_1[0];
  tmp_7[29] = SIM0_B.INPUT_6_1_1[1];
  tmp_7[30] = SIM0_B.INPUT_6_1_1[2];
  tmp_7[31] = SIM0_B.INPUT_6_1_1[3];
  tmp_8[8] = 32;
  simulationData->mData->mInputValues.mN = 32;
  simulationData->mData->mInputValues.mX = &tmp_7[0];
  simulationData->mData->mInputOffsets.mN = 9;
  simulationData->mData->mInputOffsets.mX = &tmp_8[0];
  diagnosticManager = (NeuDiagnosticManager *)SIM0_DW.STATE_1_DiagMgr;
  diagnosticTree_3 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  i = ne_simulator_method((NeslSimulator *)SIM0_DW.STATE_1_Simulator,
    NESL_SIM_UPDATE, simulationData, diagnosticManager);
  if (i != 0) {
    rtb_Logic_idx_1 = error_buffer_is_empty(rtmGetErrorStatus(SIM0_M));
    if (rtb_Logic_idx_1) {
      char *msg_3;
      msg_3 = rtw_diagnostics_msg(diagnosticTree_3);
      rtmSetErrorStatus(SIM0_M, msg_3);
    }
  }

  SIM0_DW.Memory13_PreviousInput = SIM0_U.EnableAirPlus;
  SIM0_DW.Memory14_PreviousInput = SIM0_U.EnablePrecharge;
  SIM0_DW.Memory8_PreviousInput = SIM0_U.EnableAirMinus;
  SIM0_M->Timing.clockTick0++;
}

void SIM0_initialize(void)
{
  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeModelParameters modelParameters_1;
    NeModelParameters modelParameters_2;
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    NeuDiagnosticTree *diagnosticTree_1;
    NeuDiagnosticTree *diagnosticTree_2;
    real_T tmp_2;
    int32_T i;
    boolean_T tmp_0;
    tmp = nesl_lease_simulator("SIM0/SIM/Solver Configuration_1", 0, 0);
    SIM0_DW.STATE_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(SIM0_DW.STATE_1_Simulator);
    if (tmp_0) {
      SIM0_627956e1_1_gateway();
      tmp = nesl_lease_simulator("SIM0/SIM/Solver Configuration_1", 0, 0);
      SIM0_DW.STATE_1_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    SIM0_DW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    SIM0_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
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
    modelParameters.mRTWModifiedTimeStamp = 5.71632576E+8;
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
    diagnosticManager = (NeuDiagnosticManager *)SIM0_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    i = nesl_initialize_simulator((NeslSimulator *)SIM0_DW.STATE_1_Simulator,
      &modelParameters, diagnosticManager);
    if (i != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(SIM0_M));
      if (tmp_0) {
        char *msg;
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(SIM0_M, msg);
      }
    }

    tmp = nesl_lease_simulator("SIM0/SIM/Solver Configuration_1", 1, 0);
    SIM0_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(SIM0_DW.OUTPUT_1_0_Simulator);
    if (tmp_0) {
      SIM0_627956e1_1_gateway();
      tmp = nesl_lease_simulator("SIM0/SIM/Solver Configuration_1", 1, 0);
      SIM0_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    SIM0_DW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    SIM0_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
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
    modelParameters_0.mRTWModifiedTimeStamp = 5.71632576E+8;
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
    diagnosticManager = (NeuDiagnosticManager *)SIM0_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    i = nesl_initialize_simulator((NeslSimulator *)SIM0_DW.OUTPUT_1_0_Simulator,
      &modelParameters_0, diagnosticManager);
    if (i != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(SIM0_M));
      if (tmp_0) {
        char *msg_0;
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(SIM0_M, msg_0);
      }
    }

    tmp = nesl_lease_simulator("SIM0/SIM/Solver Configuration_1", 1, 1);
    SIM0_DW.OUTPUT_1_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(SIM0_DW.OUTPUT_1_1_Simulator);
    if (tmp_0) {
      SIM0_627956e1_1_gateway();
      tmp = nesl_lease_simulator("SIM0/SIM/Solver Configuration_1", 1, 1);
      SIM0_DW.OUTPUT_1_1_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    SIM0_DW.OUTPUT_1_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    SIM0_DW.OUTPUT_1_1_DiagMgr = (void *)diagnosticManager;
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
    modelParameters_1.mRTWModifiedTimeStamp = 5.71632576E+8;
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
    diagnosticManager = (NeuDiagnosticManager *)SIM0_DW.OUTPUT_1_1_DiagMgr;
    diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    i = nesl_initialize_simulator((NeslSimulator *)SIM0_DW.OUTPUT_1_1_Simulator,
      &modelParameters_1, diagnosticManager);
    if (i != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(SIM0_M));
      if (tmp_0) {
        char *msg_1;
        msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
        rtmSetErrorStatus(SIM0_M, msg_1);
      }
    }

    tmp = nesl_lease_simulator("SIM0/SIM/Solver Configuration_1", 1, 2);
    SIM0_DW.OUTPUT_1_2_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(SIM0_DW.OUTPUT_1_2_Simulator);
    if (tmp_0) {
      SIM0_627956e1_1_gateway();
      tmp = nesl_lease_simulator("SIM0/SIM/Solver Configuration_1", 1, 2);
      SIM0_DW.OUTPUT_1_2_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    SIM0_DW.OUTPUT_1_2_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    SIM0_DW.OUTPUT_1_2_DiagMgr = (void *)diagnosticManager;
    modelParameters_2.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_2.mSolverTolerance = 0.001;
    modelParameters_2.mSolverAbsTol = 0.001;
    modelParameters_2.mSolverRelTol = 0.001;
    modelParameters_2.mVariableStepSolver = false;
    modelParameters_2.mIsUsingODEN = false;
    modelParameters_2.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_2.mFixedStepSize = 0.001;
    modelParameters_2.mStartTime = 0.0;
    modelParameters_2.mLoadInitialState = false;
    modelParameters_2.mUseSimState = false;
    modelParameters_2.mLinTrimCompile = false;
    modelParameters_2.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_2.mRTWModifiedTimeStamp = 5.71632576E+8;
    modelParameters_2.mZcDisabled = true;
    tmp_2 = 0.001;
    modelParameters_2.mSolverTolerance = tmp_2;
    tmp_2 = 0.2;
    modelParameters_2.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_2.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_2.mIsUsingODEN = tmp_0;
    modelParameters_2.mLoadInitialState = false;
    modelParameters_2.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)SIM0_DW.OUTPUT_1_2_DiagMgr;
    diagnosticTree_2 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    i = nesl_initialize_simulator((NeslSimulator *)SIM0_DW.OUTPUT_1_2_Simulator,
      &modelParameters_2, diagnosticManager);
    if (i != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(SIM0_M));
      if (tmp_0) {
        char *msg_2;
        msg_2 = rtw_diagnostics_msg(diagnosticTree_2);
        rtmSetErrorStatus(SIM0_M, msg_2);
      }
    }

    SIM0_DW.Memory20_PreviousInput = SIM0_P.Memory20_InitialCondition;
    SIM0_DW.Memory11_PreviousInput = SIM0_P.Memory11_InitialCondition;
    SIM0_DW.Memory9_PreviousInput = SIM0_P.Memory9_InitialCondition;
    for (i = 0; i < 126; i++) {
      SIM0_DW.Memory15_PreviousInput[i] = SIM0_P.Memory15_InitialCondition;
      SIM0_DW.Memory12_PreviousInput[i] = SIM0_P.Memory12_InitialCondition[i];
      SIM0_DW.Memory_PreviousInput[i] = SIM0_P.cQur[i];
      SIM0_DW.Memory10_PreviousInput[i] = SIM0_P.cCap[i];
      SIM0_DW.Memory19_PreviousInput[i] = SIM0_P.Memory19_InitialCondition;
      SIM0_DW.Memory21_PreviousInput[i] = SIM0_P.Memory21_InitialCondition;
    }

    SIM0_DW.Memory6_PreviousInput = SIM0_P.Memory6_InitialCondition;
    SIM0_DW.Memory7_PreviousInput = SIM0_P.Memory7_InitialCondition;
    SIM0_DW.Memory16_PreviousInput = SIM0_P.Memory16_InitialCondition;
    SIM0_DW.Memory17_PreviousInput = SIM0_P.Memory17_InitialCondition;
    SIM0_DW.Memory18_PreviousInput = SIM0_P.Memory18_InitialCondition;
    SIM0_DW.Memory1_PreviousInput = SIM0_P.Memory1_InitialCondition;
    SIM0_DW.Memory2_PreviousInput = SIM0_P.Memory2_InitialCondition;
    SIM0_DW.Memory_PreviousInput_e = SIM0_P.SRFlipFlop2_initial_condition;
    SIM0_DW.Memory3_PreviousInput = SIM0_P.Memory3_InitialCondition;
    SIM0_DW.Memory4_PreviousInput = SIM0_P.Memory4_InitialCondition;
    SIM0_DW.Memory_PreviousInput_m = SIM0_P.SRFlipFlop1_initial_condition;
    SIM0_DW.Memory5_PreviousInput = SIM0_P.Memory5_InitialCondition;
    SIM0_DW.Delay3_DSTATE[0] = SIM0_P.Delay3_InitialCondition;
    SIM0_DW.Delay2_DSTATE[0] = SIM0_P.Delay2_InitialCondition;
    SIM0_DW.Delay3_DSTATE[1] = SIM0_P.Delay3_InitialCondition;
    SIM0_DW.Delay2_DSTATE[1] = SIM0_P.Delay2_InitialCondition;
    SIM0_DW.Memory22_PreviousInput = SIM0_P.Memory22_InitialCondition;
    SIM0_DW.Delay1_DSTATE = SIM0_P.Delay1_InitialCondition;
    SIM0_DW.Memory13_PreviousInput = SIM0_P.Memory13_InitialCondition;
    SIM0_DW.Memory14_PreviousInput = SIM0_P.Memory14_InitialCondition;
    SIM0_DW.Memory8_PreviousInput = SIM0_P.Memory8_InitialCondition;
  }
}

void SIM0_terminate(void)
{
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)SIM0_DW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)SIM0_DW.STATE_1_SimData);
  nesl_erase_simulator("SIM0/SIM/Solver Configuration_1");
  nesl_destroy_registry();
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    SIM0_DW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)SIM0_DW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("SIM0/SIM/Solver Configuration_1");
  nesl_destroy_registry();
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    SIM0_DW.OUTPUT_1_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)SIM0_DW.OUTPUT_1_1_SimData);
  nesl_erase_simulator("SIM0/SIM/Solver Configuration_1");
  nesl_destroy_registry();
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    SIM0_DW.OUTPUT_1_2_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)SIM0_DW.OUTPUT_1_2_SimData);
  nesl_erase_simulator("SIM0/SIM/Solver Configuration_1");
  nesl_destroy_registry();
}
