#include "Accumulator.h"
#include "Accumulator_private.h"

DW_Accumulator_T Accumulator_DW;
ExtU_Accumulator_T Accumulator_U;
ExtY_Accumulator_T Accumulator_Y;
static RT_MODEL_Accumulator_T Accumulator_M_;
RT_MODEL_Accumulator_T *const Accumulator_M = &Accumulator_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

void Accumulator_step(void)
{
  real_T rtb_Rsz[126];
  real_T rtb_Switch[126];
  real_T a;
  real_T rtb_Divide;
  real_T rtb_Product1;
  real_T rtb_Rsz_m;
  real_T rtb_tauz;
  int32_T i;
  rtb_Product1 = Accumulator_P.Ts_sim * Accumulator_U.Current;
  for (i = 0; i < 126; i++) {
    rtb_Divide = Accumulator_DW.Memory_PreviousInput[i] /
      Accumulator_DW.Memory2_PreviousInput[i];
    rtb_Rsz_m = look1_binlxpw(rtb_Divide, Accumulator_P.soc, Accumulator_P.Rs,
      12U);
    rtb_tauz = look1_binlxpw(rtb_Divide, Accumulator_P.soc, Accumulator_P.tau,
      12U);
    a = rtb_Rsz_m * rtb_tauz;
    rtb_Rsz_m = (rtb_Rsz_m + look1_binlxpw(rtb_Divide, Accumulator_P.soc,
      Accumulator_P.Rp, 12U)) * Accumulator_P.Ts_sim;
    rtb_Rsz_m = (((2.0 * a + rtb_Rsz_m) * Accumulator_U.Current + (rtb_Rsz_m -
      2.0 * a) * Accumulator_DW.Memory3_PreviousInput) - (Accumulator_P.Ts_sim -
      2.0 * rtb_tauz) * Accumulator_DW.Memory4_PreviousInput[i]) / (2.0 *
      rtb_tauz + Accumulator_P.Ts_sim);
    rtb_tauz = rtb_Rsz_m + look1_binlxpw(rtb_Divide, Accumulator_P.soc,
      Accumulator_P.ocv, 12U);
    Accumulator_Y.Voltages[i] = rtb_tauz;
    Accumulator_Y.SOCs[i] = rtb_Divide;
    Accumulator_Y.Capacities[i] = Accumulator_DW.Memory2_PreviousInput[i];
    rtb_Rsz[i] = rtb_Rsz_m;
    rtb_Switch[i] = (rtb_Product1 + Accumulator_DW.Memory_PreviousInput[i]) -
      rtb_tauz / Accumulator_P.R_short * Accumulator_U.Balances[i];
  }

  rtb_Product1 = exp(Accumulator_P.Cap_det / (Accumulator_P.C_r * 3600.0) *
                     Accumulator_DW.Memory1_PreviousInput);
  Accumulator_DW.Memory3_PreviousInput = Accumulator_U.Current;
  for (i = 0; i < 126; i++) {
    rtb_tauz = rtb_Switch[i];
    rtb_Divide = Accumulator_DW.Memory2_PreviousInput[i] * rtb_Product1;
    Accumulator_DW.Memory4_PreviousInput[i] = rtb_Rsz[i];
    if (rtb_tauz > rtb_Divide) {
      Accumulator_DW.Memory_PreviousInput[i] = rtb_Divide;
    } else if (rtb_tauz < Accumulator_P.Constant1_Value) {
      Accumulator_DW.Memory_PreviousInput[i] = Accumulator_P.Constant1_Value;
    } else {
      Accumulator_DW.Memory_PreviousInput[i] = rtb_tauz;
    }

    Accumulator_DW.Memory2_PreviousInput[i] = rtb_Divide;
  }

  Accumulator_DW.Memory1_PreviousInput = fabs(Accumulator_U.Current +
    Accumulator_DW.Memory1_PreviousInput);
  rt_UpdateTXYLogVars(Accumulator_M->rtwLogInfo,
                      (&Accumulator_M->Timing.taskTime0));

  {
    if ((rtmGetTFinal(Accumulator_M)!=-1) &&
        !((rtmGetTFinal(Accumulator_M)-Accumulator_M->Timing.taskTime0) >
          Accumulator_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Accumulator_M, "Simulation finished");
    }
  }

  if (!(++Accumulator_M->Timing.clockTick0)) {
    ++Accumulator_M->Timing.clockTickH0;
  }

  Accumulator_M->Timing.taskTime0 = Accumulator_M->Timing.clockTick0 *
    Accumulator_M->Timing.stepSize0 + Accumulator_M->Timing.clockTickH0 *
    Accumulator_M->Timing.stepSize0 * 4294967296.0;
}

void Accumulator_initialize(void)
{
  rt_InitInfAndNaN(sizeof(real_T));
  (void) memset((void *)Accumulator_M, 0,
                sizeof(RT_MODEL_Accumulator_T));
  rtmSetTFinal(Accumulator_M, 9000.0);
  Accumulator_M->Timing.stepSize0 = 0.2;

  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Accumulator_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  {
    rtliSetLogXSignalInfo(Accumulator_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Accumulator_M->rtwLogInfo, (NULL));
    rtliSetLogT(Accumulator_M->rtwLogInfo, "tout");
    rtliSetLogX(Accumulator_M->rtwLogInfo, "");
    rtliSetLogXFinal(Accumulator_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Accumulator_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Accumulator_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Accumulator_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Accumulator_M->rtwLogInfo, 1);
    rtliSetLogY(Accumulator_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Accumulator_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Accumulator_M->rtwLogInfo, (NULL));
  }

  (void) memset((void *)&Accumulator_DW, 0,
                sizeof(DW_Accumulator_T));
  (void)memset(&Accumulator_U, 0, sizeof(ExtU_Accumulator_T));
  (void) memset((void *)&Accumulator_Y, 0,
                sizeof(ExtY_Accumulator_T));
  rt_StartDataLoggingWithStartTime(Accumulator_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Accumulator_M), Accumulator_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Accumulator_M)));
  Accumulator_DW.Memory3_PreviousInput = Accumulator_P.Memory3_InitialCondition;
  memcpy(&Accumulator_DW.Memory4_PreviousInput[0],
         &Accumulator_P.Memory4_InitialCondition[0], 126U * sizeof(real_T));
  memcpy(&Accumulator_DW.Memory_PreviousInput[0], &Accumulator_P.cQur[0], 126U *
         sizeof(real_T));
  memcpy(&Accumulator_DW.Memory2_PreviousInput[0], &Accumulator_P.cCap[0], 126U *
         sizeof(real_T));
  Accumulator_DW.Memory1_PreviousInput = Accumulator_P.Memory1_InitialCondition;
}

void Accumulator_terminate(void)
{
}
