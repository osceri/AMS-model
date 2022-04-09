/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem.c
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.699
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Thu Apr  7 22:48:14 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Subsystem.h"
#include "Subsystem_private.h"

/* Block signals (default storage) */
B rtB;

/* Block states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Subsystem_step(void)
{
  NeParameterBundle expl_temp;
  NeslSimulationData *simulationData_tmp_tmp;
  NeuDiagnosticManager *diag;
  NeuDiagnosticTree *diagTree;
  NeuDiagnosticTree *diagnosticTree;
  NeuDiagnosticTree *diagnosticTree_0;
  NeuDiagnosticTree *diagnosticTree_1;
  NeuDiagnosticTree *diagnosticTree_2;
  char *msg;
  char *msg_0;
  char *msg_1;
  char *msg_2;
  char *msg_3;
  real_T tmp_3[20];
  real_T tmp_5[20];
  real_T tmp_0[4];
  real_T tmp_7[4];
  real_T rtb_OUTPUT_1_1[2];
  real_T rtb_OUTPUT_1_0;
  real_T time;
  real_T time_0;
  real_T time_1;
  real_T time_2;
  real_T time_tmp;
  real_T tmp;
  int32_T tmp_2;
  int_T tmp_4[3];
  int_T tmp_6[3];
  int_T tmp_1[2];
  int_T tmp_8[2];
  boolean_T ok;

  /* SimscapeInputBlock: '<S11>/INPUT_1_1_1' incorporates:
   *  Inport: '<Root>/Current Draw'
   */
  rtB.INPUT_1_1_1[0] = rtU.CurrentDraw;
  rtB.INPUT_1_1_1[1] = 0.0;
  rtB.INPUT_1_1_1[2] = 0.0;
  rtDW.INPUT_1_1_1_Discrete[0] = (rtB.INPUT_1_1_1[0] !=
    rtDW.INPUT_1_1_1_Discrete[1]);
  rtDW.INPUT_1_1_1_Discrete[1] = rtB.INPUT_1_1_1[0];
  rtB.INPUT_1_1_1[0] = rtDW.INPUT_1_1_1_Discrete[1];
  rtB.INPUT_1_1_1[3] = rtDW.INPUT_1_1_1_Discrete[0];

  /* SimscapeRtp: '<S6>/RTP_1' incorporates:
   *  Constant: '<S1>/Subsystem_around_RTP_D21D83FF_stateOfCharge'
   */
  if (rtDW.RTP_1_SetParametersNeeded) {
    tmp = 0.5;
    diag = rtw_create_diagnostics();
    diagTree = neu_diagnostic_manager_get_initial_tree(diag);
    expl_temp.mRealParameters.mN = 1;
    expl_temp.mRealParameters.mX = &tmp;
    expl_temp.mLogicalParameters.mN = 0;
    expl_temp.mLogicalParameters.mX = NULL;
    expl_temp.mIntegerParameters.mN = 0;
    expl_temp.mIntegerParameters.mX = NULL;
    expl_temp.mIndexParameters.mN = 0;
    expl_temp.mIndexParameters.mX = NULL;
    ok = nesl_rtp_manager_set_rtps((NeslRtpManager *)rtDW.RTP_1_RtpManager,
      ((rtM->Timing.clockTick0) * 0.2), expl_temp, diag);
    if (!ok) {
      ok = error_buffer_is_empty(((void*) 0));
      if (ok) {
        msg = rtw_diagnostics_msg(diagTree);
        ((void) 0);
      }
    }
  }

  rtDW.RTP_1_SetParametersNeeded = false;

  /* End of SimscapeRtp: '<S6>/RTP_1' */

  /* SimscapeExecutionBlock: '<S11>/STATE_1' incorporates:
   *  SimscapeExecutionBlock: '<S11>/OUTPUT_1_0'
   *  SimscapeExecutionBlock: '<S11>/OUTPUT_1_1'
   */
  simulationData_tmp_tmp = (NeslSimulationData *)rtDW.STATE_1_SimData;
  time_tmp = ((rtM->Timing.clockTick0) * 0.2);
  time = time_tmp;
  simulationData_tmp_tmp->mData->mTime.mN = 1;
  simulationData_tmp_tmp->mData->mTime.mX = &time;
  simulationData_tmp_tmp->mData->mContStates.mN = 0;
  simulationData_tmp_tmp->mData->mContStates.mX = NULL;
  simulationData_tmp_tmp->mData->mDiscStates.mN = 10;
  simulationData_tmp_tmp->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete[0];
  simulationData_tmp_tmp->mData->mModeVector.mN = 6;
  simulationData_tmp_tmp->mData->mModeVector.mX = &rtDW.STATE_1_Modes[0];
  ok = false;
  simulationData_tmp_tmp->mData->mFoundZcEvents = ok;
  simulationData_tmp_tmp->mData->mIsMajorTimeStep = true;
  ok = false;
  simulationData_tmp_tmp->mData->mIsSolverAssertCheck = ok;
  simulationData_tmp_tmp->mData->mIsSolverCheckingCIC = false;
  simulationData_tmp_tmp->mData->mIsComputingJacobian = false;
  simulationData_tmp_tmp->mData->mIsEvaluatingF0 = false;
  simulationData_tmp_tmp->mData->mIsSolverRequestingReset = false;
  simulationData_tmp_tmp->mData->mIsOkayToUpdateMode = true;
  tmp_1[0] = 0;
  tmp_0[0] = rtB.INPUT_1_1_1[0];
  tmp_0[1] = rtB.INPUT_1_1_1[1];
  tmp_0[2] = rtB.INPUT_1_1_1[2];
  tmp_0[3] = rtB.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  simulationData_tmp_tmp->mData->mInputValues.mN = 4;
  simulationData_tmp_tmp->mData->mInputValues.mX = &tmp_0[0];
  simulationData_tmp_tmp->mData->mInputOffsets.mN = 2;
  simulationData_tmp_tmp->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData_tmp_tmp->mData->mOutputs.mN = 16;
  simulationData_tmp_tmp->mData->mOutputs.mX = &rtB.STATE_1[0];
  simulationData_tmp_tmp->mData->mSampleHits.mN = 0;
  simulationData_tmp_tmp->mData->mSampleHits.mX = NULL;
  ok = 1;
  simulationData_tmp_tmp->mData->mIsFundamentalSampleHit = ok;
  simulationData_tmp_tmp->mData->mTolerances.mN = 0;
  simulationData_tmp_tmp->mData->mTolerances.mX = NULL;
  simulationData_tmp_tmp->mData->mCstateHasChanged = false;
  diag = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diag);
  tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
    NESL_SIM_OUTPUTS, simulationData_tmp_tmp, diag);
  if (tmp_2 != 0) {
    ok = error_buffer_is_empty(((void*) 0));
    if (ok) {
      msg_0 = rtw_diagnostics_msg(diagnosticTree);
      ((void) 0);
    }
  }

  /* End of SimscapeExecutionBlock: '<S11>/STATE_1' */

  /* SimscapeExecutionBlock: '<S11>/OUTPUT_1_1' */
  simulationData_tmp_tmp = (NeslSimulationData *)rtDW.OUTPUT_1_1_SimData;
  time_0 = time_tmp;
  simulationData_tmp_tmp->mData->mTime.mN = 1;
  simulationData_tmp_tmp->mData->mTime.mX = &time_0;
  simulationData_tmp_tmp->mData->mContStates.mN = 0;
  simulationData_tmp_tmp->mData->mContStates.mX = NULL;
  simulationData_tmp_tmp->mData->mDiscStates.mN = 0;
  simulationData_tmp_tmp->mData->mDiscStates.mX = &rtDW.OUTPUT_1_1_Discrete;
  simulationData_tmp_tmp->mData->mModeVector.mN = 0;
  simulationData_tmp_tmp->mData->mModeVector.mX = &rtDW.OUTPUT_1_1_Modes;
  ok = false;
  simulationData_tmp_tmp->mData->mFoundZcEvents = ok;
  simulationData_tmp_tmp->mData->mIsMajorTimeStep = true;
  ok = false;
  simulationData_tmp_tmp->mData->mIsSolverAssertCheck = ok;
  simulationData_tmp_tmp->mData->mIsSolverCheckingCIC = false;
  simulationData_tmp_tmp->mData->mIsComputingJacobian = false;
  simulationData_tmp_tmp->mData->mIsEvaluatingF0 = false;
  simulationData_tmp_tmp->mData->mIsSolverRequestingReset = false;
  simulationData_tmp_tmp->mData->mIsOkayToUpdateMode = true;
  tmp_4[0] = 0;
  tmp_3[0] = rtB.INPUT_1_1_1[0];
  tmp_3[1] = rtB.INPUT_1_1_1[1];
  tmp_3[2] = rtB.INPUT_1_1_1[2];
  tmp_3[3] = rtB.INPUT_1_1_1[3];
  tmp_4[1] = 4;
  memcpy(&tmp_3[4], &rtB.STATE_1[0], sizeof(real_T) << 4U);
  tmp_4[2] = 20;
  simulationData_tmp_tmp->mData->mInputValues.mN = 20;
  simulationData_tmp_tmp->mData->mInputValues.mX = &tmp_3[0];
  simulationData_tmp_tmp->mData->mInputOffsets.mN = 3;
  simulationData_tmp_tmp->mData->mInputOffsets.mX = &tmp_4[0];
  simulationData_tmp_tmp->mData->mOutputs.mN = 2;
  simulationData_tmp_tmp->mData->mOutputs.mX = &rtb_OUTPUT_1_1[0];
  simulationData_tmp_tmp->mData->mSampleHits.mN = 0;
  simulationData_tmp_tmp->mData->mSampleHits.mX = NULL;
  ok = 1;
  simulationData_tmp_tmp->mData->mIsFundamentalSampleHit = ok;
  simulationData_tmp_tmp->mData->mTolerances.mN = 0;
  simulationData_tmp_tmp->mData->mTolerances.mX = NULL;
  simulationData_tmp_tmp->mData->mCstateHasChanged = false;
  diag = (NeuDiagnosticManager *)rtDW.OUTPUT_1_1_DiagMgr;
  diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diag);
  tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.OUTPUT_1_1_Simulator,
    NESL_SIM_OUTPUTS, simulationData_tmp_tmp, diag);
  if (tmp_2 != 0) {
    ok = error_buffer_is_empty(((void*) 0));
    if (ok) {
      msg_1 = rtw_diagnostics_msg(diagnosticTree_0);
      ((void) 0);
    }
  }

  /* Outport: '<Root>/Voltage' */
  rtY.Voltage = rtb_OUTPUT_1_1[1];

  /* Outport: '<Root>/Current' */
  rtY.Current = rtb_OUTPUT_1_1[0];

  /* SimscapeExecutionBlock: '<S11>/OUTPUT_1_0' */
  simulationData_tmp_tmp = (NeslSimulationData *)rtDW.OUTPUT_1_0_SimData;
  time_1 = time_tmp;
  simulationData_tmp_tmp->mData->mTime.mN = 1;
  simulationData_tmp_tmp->mData->mTime.mX = &time_1;
  simulationData_tmp_tmp->mData->mContStates.mN = 0;
  simulationData_tmp_tmp->mData->mContStates.mX = NULL;
  simulationData_tmp_tmp->mData->mDiscStates.mN = 0;
  simulationData_tmp_tmp->mData->mDiscStates.mX = &rtDW.OUTPUT_1_0_Discrete;
  simulationData_tmp_tmp->mData->mModeVector.mN = 0;
  simulationData_tmp_tmp->mData->mModeVector.mX = &rtDW.OUTPUT_1_0_Modes;
  ok = false;
  simulationData_tmp_tmp->mData->mFoundZcEvents = ok;
  simulationData_tmp_tmp->mData->mIsMajorTimeStep = true;
  ok = false;
  simulationData_tmp_tmp->mData->mIsSolverAssertCheck = ok;
  simulationData_tmp_tmp->mData->mIsSolverCheckingCIC = false;
  simulationData_tmp_tmp->mData->mIsComputingJacobian = false;
  simulationData_tmp_tmp->mData->mIsEvaluatingF0 = false;
  simulationData_tmp_tmp->mData->mIsSolverRequestingReset = false;
  simulationData_tmp_tmp->mData->mIsOkayToUpdateMode = true;
  tmp_6[0] = 0;
  tmp_5[0] = rtB.INPUT_1_1_1[0];
  tmp_5[1] = rtB.INPUT_1_1_1[1];
  tmp_5[2] = rtB.INPUT_1_1_1[2];
  tmp_5[3] = rtB.INPUT_1_1_1[3];
  tmp_6[1] = 4;
  memcpy(&tmp_5[4], &rtB.STATE_1[0], sizeof(real_T) << 4U);
  tmp_6[2] = 20;
  simulationData_tmp_tmp->mData->mInputValues.mN = 20;
  simulationData_tmp_tmp->mData->mInputValues.mX = &tmp_5[0];
  simulationData_tmp_tmp->mData->mInputOffsets.mN = 3;
  simulationData_tmp_tmp->mData->mInputOffsets.mX = &tmp_6[0];
  simulationData_tmp_tmp->mData->mOutputs.mN = 1;
  simulationData_tmp_tmp->mData->mOutputs.mX = &rtb_OUTPUT_1_0;
  simulationData_tmp_tmp->mData->mSampleHits.mN = 0;
  simulationData_tmp_tmp->mData->mSampleHits.mX = NULL;
  ok = 1;
  simulationData_tmp_tmp->mData->mIsFundamentalSampleHit = ok;
  simulationData_tmp_tmp->mData->mTolerances.mN = 0;
  simulationData_tmp_tmp->mData->mTolerances.mX = NULL;
  simulationData_tmp_tmp->mData->mCstateHasChanged = false;
  diag = (NeuDiagnosticManager *)rtDW.OUTPUT_1_0_DiagMgr;
  diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diag);
  tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.OUTPUT_1_0_Simulator,
    NESL_SIM_OUTPUTS, simulationData_tmp_tmp, diag);
  if (tmp_2 != 0) {
    ok = error_buffer_is_empty(((void*) 0));
    if (ok) {
      msg_2 = rtw_diagnostics_msg(diagnosticTree_1);
      ((void) 0);
    }
  }

  /* Outport: '<Root>/SOC' */
  rtY.SOC = rtb_OUTPUT_1_0;

  /* Update for SimscapeExecutionBlock: '<S11>/STATE_1' */
  simulationData_tmp_tmp = (NeslSimulationData *)rtDW.STATE_1_SimData;
  time_2 = time_tmp;
  simulationData_tmp_tmp->mData->mTime.mN = 1;
  simulationData_tmp_tmp->mData->mTime.mX = &time_2;
  simulationData_tmp_tmp->mData->mContStates.mN = 0;
  simulationData_tmp_tmp->mData->mContStates.mX = NULL;
  simulationData_tmp_tmp->mData->mDiscStates.mN = 10;
  simulationData_tmp_tmp->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete[0];
  simulationData_tmp_tmp->mData->mModeVector.mN = 6;
  simulationData_tmp_tmp->mData->mModeVector.mX = &rtDW.STATE_1_Modes[0];
  ok = false;
  simulationData_tmp_tmp->mData->mFoundZcEvents = ok;
  simulationData_tmp_tmp->mData->mIsMajorTimeStep = true;
  ok = false;
  simulationData_tmp_tmp->mData->mIsSolverAssertCheck = ok;
  simulationData_tmp_tmp->mData->mIsSolverCheckingCIC = false;
  simulationData_tmp_tmp->mData->mIsComputingJacobian = false;
  simulationData_tmp_tmp->mData->mIsEvaluatingF0 = false;
  simulationData_tmp_tmp->mData->mIsSolverRequestingReset = false;
  simulationData_tmp_tmp->mData->mIsOkayToUpdateMode = true;
  tmp_8[0] = 0;
  tmp_7[0] = rtB.INPUT_1_1_1[0];
  tmp_7[1] = rtB.INPUT_1_1_1[1];
  tmp_7[2] = rtB.INPUT_1_1_1[2];
  tmp_7[3] = rtB.INPUT_1_1_1[3];
  tmp_8[1] = 4;
  simulationData_tmp_tmp->mData->mInputValues.mN = 4;
  simulationData_tmp_tmp->mData->mInputValues.mX = &tmp_7[0];
  simulationData_tmp_tmp->mData->mInputOffsets.mN = 2;
  simulationData_tmp_tmp->mData->mInputOffsets.mX = &tmp_8[0];
  diag = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
  diagnosticTree_2 = neu_diagnostic_manager_get_initial_tree(diag);
  tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
    NESL_SIM_UPDATE, simulationData_tmp_tmp, diag);
  if (tmp_2 != 0) {
    ok = error_buffer_is_empty(((void*) 0));
    if (ok) {
      msg_3 = rtw_diagnostics_msg(diagnosticTree_2);
      ((void) 0);
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  rtM->Timing.clockTick0++;
}

/* Model initialize function */
void Subsystem_initialize(void)
{
  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeModelParameters modelParameters_1;
    NeslRtpManager *manager;
    NeslRtpManager *manager_0;
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp_0;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    NeuDiagnosticTree *diagnosticTree_1;
    char *msg;
    char *msg_0;
    char *msg_1;
    real_T tmp_2;
    int32_T tmp_3;
    boolean_T tmp;

    /* Start for SimscapeRtp: '<S6>/RTP_1' */
    manager_0 = nesl_lease_rtp_manager(
      "Subsystem/Subsystem/Solver Configuration1_1", 0);
    manager = manager_0;
    tmp = pointer_is_null(manager_0);
    if (tmp) {
      Subsystem_8f6c35c5_1_gateway();
      manager = nesl_lease_rtp_manager(
        "Subsystem/Subsystem/Solver Configuration1_1", 0);
    }

    rtDW.RTP_1_RtpManager = (void *)manager;
    rtDW.RTP_1_SetParametersNeeded = true;

    /* End of Start for SimscapeRtp: '<S6>/RTP_1' */

    /* Start for SimscapeExecutionBlock: '<S11>/STATE_1' */
    tmp_0 = nesl_lease_simulator("Subsystem/Subsystem/Solver Configuration1_1",
      0, 0);
    rtDW.STATE_1_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(rtDW.STATE_1_Simulator);
    if (tmp) {
      Subsystem_8f6c35c5_1_gateway();
      tmp_0 = nesl_lease_simulator("Subsystem/Subsystem/Solver Configuration1_1",
        0, 0);
      rtDW.STATE_1_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    rtDW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    rtDW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DISCRETE;
    modelParameters.mSolverTolerance = 0.001;
    modelParameters.mVariableStepSolver = false;
    modelParameters.mIsUsingODEN = false;
    modelParameters.mFixedStepSize = 0.2;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_ALL;
    modelParameters.mRTWModifiedTimeStamp = 5.7127248E+8;
    tmp_2 = 0.001;
    modelParameters.mSolverTolerance = tmp_2;
    tmp_2 = 0.2;
    modelParameters.mFixedStepSize = tmp_2;
    tmp = false;
    modelParameters.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters.mIsUsingODEN = tmp;
    modelParameters.mLoadInitialState = false;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)rtDW.STATE_1_Simulator,
      &modelParameters, diagnosticManager);
    if (tmp_3 != 0) {
      tmp = error_buffer_is_empty(((void*) 0));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        ((void) 0);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S11>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S11>/OUTPUT_1_1' */
    tmp_0 = nesl_lease_simulator("Subsystem/Subsystem/Solver Configuration1_1",
      1, 1);
    rtDW.OUTPUT_1_1_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(rtDW.OUTPUT_1_1_Simulator);
    if (tmp) {
      Subsystem_8f6c35c5_1_gateway();
      tmp_0 = nesl_lease_simulator("Subsystem/Subsystem/Solver Configuration1_1",
        1, 1);
      rtDW.OUTPUT_1_1_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    rtDW.OUTPUT_1_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    rtDW.OUTPUT_1_1_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DISCRETE;
    modelParameters_0.mSolverTolerance = 0.001;
    modelParameters_0.mVariableStepSolver = false;
    modelParameters_0.mIsUsingODEN = false;
    modelParameters_0.mFixedStepSize = 0.2;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_ALL;
    modelParameters_0.mRTWModifiedTimeStamp = 5.7127248E+8;
    tmp_2 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_2;
    tmp_2 = 0.2;
    modelParameters_0.mFixedStepSize = tmp_2;
    tmp = false;
    modelParameters_0.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters_0.mIsUsingODEN = tmp;
    modelParameters_0.mLoadInitialState = false;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.OUTPUT_1_1_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)rtDW.OUTPUT_1_1_Simulator,
      &modelParameters_0, diagnosticManager);
    if (tmp_3 != 0) {
      tmp = error_buffer_is_empty(((void*) 0));
      if (tmp) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        ((void) 0);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S11>/OUTPUT_1_1' */

    /* Start for SimscapeExecutionBlock: '<S11>/OUTPUT_1_0' */
    tmp_0 = nesl_lease_simulator("Subsystem/Subsystem/Solver Configuration1_1",
      1, 0);
    rtDW.OUTPUT_1_0_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(rtDW.OUTPUT_1_0_Simulator);
    if (tmp) {
      Subsystem_8f6c35c5_1_gateway();
      tmp_0 = nesl_lease_simulator("Subsystem/Subsystem/Solver Configuration1_1",
        1, 0);
      rtDW.OUTPUT_1_0_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    rtDW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    rtDW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_1.mSolverType = NE_SOLVER_TYPE_DISCRETE;
    modelParameters_1.mSolverTolerance = 0.001;
    modelParameters_1.mVariableStepSolver = false;
    modelParameters_1.mIsUsingODEN = false;
    modelParameters_1.mFixedStepSize = 0.2;
    modelParameters_1.mStartTime = 0.0;
    modelParameters_1.mLoadInitialState = false;
    modelParameters_1.mUseSimState = false;
    modelParameters_1.mLinTrimCompile = false;
    modelParameters_1.mLoggingMode = SSC_LOGGING_ALL;
    modelParameters_1.mRTWModifiedTimeStamp = 5.7127248E+8;
    tmp_2 = 0.001;
    modelParameters_1.mSolverTolerance = tmp_2;
    tmp_2 = 0.2;
    modelParameters_1.mFixedStepSize = tmp_2;
    tmp = false;
    modelParameters_1.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters_1.mIsUsingODEN = tmp;
    modelParameters_1.mLoadInitialState = false;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)rtDW.OUTPUT_1_0_Simulator,
      &modelParameters_1, diagnosticManager);
    if (tmp_3 != 0) {
      tmp = error_buffer_is_empty(((void*) 0));
      if (tmp) {
        msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
        ((void) 0);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S11>/OUTPUT_1_0' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
