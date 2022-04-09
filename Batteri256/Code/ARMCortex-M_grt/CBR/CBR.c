#include "CBR.h"
#include "CBR_private.h"

#define CBR_IN_CB_state_               ((uint8_T)1U)
#define CBR_IN_CC_state_               ((uint8_T)2U)
#define CBR_IN_CV_state_               ((uint8_T)3U)
#define CBR_IN_Entry_                  ((uint8_T)4U)
#define CBR_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

B_CBR_T CBR_B;
DW_CBR_T CBR_DW;
ExtU_CBR_T CBR_U;
ExtY_CBR_T CBR_Y;
static RT_MODEL_CBR_T CBR_M_;
RT_MODEL_CBR_T *const CBR_M = &CBR_M_;
static void CBR_merge(int32_T idx[126], real_T x[126], int32_T offset, int32_T
                      np, int32_T nq, int32_T iwork[126], real_T xwork[126]);
static void CBR_merge_block(int32_T idx[126], real_T x[126], int32_T offset,
  int32_T n, int32_T preSortLevel, int32_T iwork[126], real_T xwork[126]);
static void CBR_sort(real_T x[126], int32_T idx[126]);
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

void CBR_MATLABFunction1(const real_T rtu_u[126], B_MATLABFunction1_CBR_T
  *localB)
{
  real_T y;
  int32_T k;
  y = rtu_u[0];
  for (k = 0; k < 125; k++) {
    y += rtu_u[k + 1];
  }

  localB->y = y / 126.0;
}

static void CBR_merge(int32_T idx[126], real_T x[126], int32_T offset, int32_T
                      np, int32_T nq, int32_T iwork[126], real_T xwork[126])
{
  int32_T exitg1;
  int32_T iout;
  int32_T n;
  int32_T n_tmp;
  int32_T q;
  if ((np != 0) && (nq != 0)) {
    n_tmp = np + nq;
    for (q = 0; q < n_tmp; q++) {
      iout = offset + q;
      iwork[q] = idx[iout];
      xwork[q] = x[iout];
    }

    n = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[n] >= xwork[q]) {
        idx[iout] = iwork[n];
        x[iout] = xwork[n];
        if (n + 1 < np) {
          n++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - n;
          while (n + 1 <= np) {
            iout = (q + n) + 1;
            idx[iout] = iwork[n];
            x[iout] = xwork[n];
            n++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void CBR_merge_block(int32_T idx[126], real_T x[126], int32_T offset,
  int32_T n, int32_T preSortLevel, int32_T iwork[126], real_T xwork[126])
{
  int32_T bLen;
  int32_T nPairs;
  int32_T nTail;
  int32_T tailOffset;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1U) != 0U) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        CBR_merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      CBR_merge(idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    CBR_merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

static void CBR_sort(real_T x[126], int32_T idx[126])
{
  real_T xwork[126];
  real_T x4[4];
  real_T tmp;
  real_T tmp_0;
  int32_T iwork[126];
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T ib;
  int32_T nNaNs;
  int8_T idx4[4];
  int8_T perm[4];
  x4[0] = 0.0;
  idx4[0] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  memset(&idx[0], 0, 126U * sizeof(int32_T));
  memset(&xwork[0], 0, 126U * sizeof(real_T));
  nNaNs = 0;
  ib = 0;
  for (i = 0; i < 126; i++) {
    if (rtIsNaN(x[i])) {
      idx[125 - nNaNs] = i + 1;
      xwork[125 - nNaNs] = x[i];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = (int8_T)(i + 1);
      x4[ib - 1] = x[i];
      if (ib == 4) {
        ib = i - nNaNs;
        if (x4[0] >= x4[1]) {
          i1 = 1;
          i2 = 2;
        } else {
          i1 = 2;
          i2 = 1;
        }

        if (x4[2] >= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        tmp = x4[i1 - 1];
        tmp_0 = x4[i3 - 1];
        if (tmp >= tmp_0) {
          tmp = x4[i2 - 1];
          if (tmp >= tmp_0) {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i2;
            perm[2] = (int8_T)i3;
            perm[3] = (int8_T)i4;
          } else if (tmp >= x4[i4 - 1]) {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i3;
            perm[2] = (int8_T)i2;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i3;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)i2;
          }
        } else {
          tmp_0 = x4[i4 - 1];
          if (tmp >= tmp_0) {
            if (x4[i2 - 1] >= tmp_0) {
              perm[0] = (int8_T)i3;
              perm[1] = (int8_T)i1;
              perm[2] = (int8_T)i2;
              perm[3] = (int8_T)i4;
            } else {
              perm[0] = (int8_T)i3;
              perm[1] = (int8_T)i1;
              perm[2] = (int8_T)i4;
              perm[3] = (int8_T)i2;
            }
          } else {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)i4;
            perm[2] = (int8_T)i1;
            perm[3] = (int8_T)i2;
          }
        }

        idx[ib - 3] = idx4[perm[0] - 1];
        idx[ib - 2] = idx4[perm[1] - 1];
        idx[ib - 1] = idx4[perm[2] - 1];
        idx[ib] = idx4[perm[3] - 1];
        x[ib - 3] = x4[perm[0] - 1];
        x[ib - 2] = x4[perm[1] - 1];
        x[ib - 1] = x4[perm[2] - 1];
        x[ib] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }

  if (ib > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] >= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] >= x4[1]) {
      if (x4[1] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    for (i = 0; i < ib; i++) {
      i1 = perm[i] - 1;
      i2 = ((i - nNaNs) - ib) + 126;
      idx[i2] = idx4[i1];
      x[i2] = x4[i1];
    }
  }

  i = (nNaNs >> 1) + 126;
  for (ib = 126; ib - 126 <= i - 127; ib++) {
    i2 = ib - nNaNs;
    i1 = idx[i2];
    idx[i2] = idx[251 - ib];
    idx[251 - ib] = i1;
    x[i2] = xwork[251 - ib];
    x[251 - ib] = xwork[i2];
  }

  if ((nNaNs & 1U) != 0U) {
    ib = i - nNaNs;
    x[ib] = xwork[ib];
  }

  memset(&iwork[0], 0, 126U * sizeof(int32_T));
  if (126 - nNaNs > 1) {
    CBR_merge_block(idx, x, 0, 126 - nNaNs, 2, iwork, xwork);
  }

  if ((nNaNs > 0) && (126 - nNaNs > 0)) {
    for (i = 0; i < nNaNs; i++) {
      ib = (i - nNaNs) + 126;
      xwork[i] = x[ib];
      iwork[i] = idx[ib];
    }

    for (i = 125 - nNaNs; i + 1 > 0; i--) {
      ib = nNaNs + i;
      x[ib] = x[i];
      idx[ib] = idx[i];
    }

    for (i = 0; i < nNaNs; i++) {
      x[i] = xwork[i];
      idx[i] = iwork[i];
    }
  }
}

void CBR_step(void)
{
  real_T rtb_ocvz[126];
  real_T x[126];
  real_T a;
  real_T rtb_Rsz1;
  real_T rtb_tauz1;
  real_T rtb_y;
  real_T t;
  real_T xbar;
  int32_T iidx[126];
  int32_T i;
  int32_T idx;
  boolean_T exitg1;
  CBR_Y.Current = CBR_DW.Memory_PreviousInput;
  memcpy(&CBR_Y.Balances[0], &CBR_DW.Memory1_PreviousInput[0], 126U * sizeof
         (real_T));
  xbar = CBR_U.Voltages[0];
  for (i = 0; i < 125; i++) {
    xbar += CBR_U.Voltages[i + 1];
  }

  xbar /= 126.0;
  rtb_y = 0.0;
  for (i = 0; i < 126; i++) {
    t = CBR_U.Voltages[i] - xbar;
    rtb_y += t * t;
  }

  rtb_y /= 125.0;
  if (!rtIsNaN(CBR_U.Voltages[0])) {
    idx = 1;
  } else {
    idx = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 127)) {
      if (!rtIsNaN(CBR_U.Voltages[i - 1])) {
        idx = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (idx == 0) {
    t = CBR_U.Voltages[0];
  } else {
    t = CBR_U.Voltages[idx - 1];
    while (idx + 1 < 127) {
      if (t < CBR_U.Voltages[idx]) {
        t = CBR_U.Voltages[idx];
      }

      idx++;
    }
  }

  for (i = 0; i < 126; i++) {
    rtb_ocvz[i] = look1_binlxpw(CBR_U.SOCs[i], CBR_P.soc, CBR_P.ocv, 12U);
  }

  CBR_MATLABFunction1(rtb_ocvz, &CBR_B.sf_MATLABFunction3);
  xbar = CBR_P.U_sought - CBR_B.sf_MATLABFunction3.y;
  CBR_MATLABFunction1(CBR_U.SOCs, &CBR_B.sf_MATLABFunction1);
  rtb_Rsz1 = look1_binlxpw(CBR_B.sf_MATLABFunction1.y, CBR_P.soc, CBR_P.Rs, 12U);
  rtb_tauz1 = look1_binlxpw(CBR_B.sf_MATLABFunction1.y, CBR_P.soc, CBR_P.tau,
    12U);
  a = rtb_Rsz1 * rtb_tauz1;
  rtb_Rsz1 = CBR_P.Ts * (rtb_Rsz1 + look1_binlxpw(CBR_B.sf_MATLABFunction1.y,
    CBR_P.soc, CBR_P.Rp, 12U));
  rtb_tauz1 = (((2.0 * rtb_tauz1 + CBR_P.Ts) * xbar + (CBR_P.Ts - 2.0 *
    rtb_tauz1) * CBR_DW.Memory5_PreviousInput) - (rtb_Rsz1 - 2.0 * a) *
               CBR_DW.Memory6_PreviousInput) / (rtb_Rsz1 + 2.0 * a);
  if (CBR_DW.is_active_c5_CBR == 0U) {
    CBR_DW.is_active_c5_CBR = 1U;
    CBR_DW.is_c5_CBR = CBR_IN_Entry_;
    rtb_y = 0.0;
    t = 0.0;
    a = 0.0;
  } else {
    switch (CBR_DW.is_c5_CBR) {
     case CBR_IN_CB_state_:
      if (rtb_y < CBR_P.U_tol) {
        CBR_DW.is_c5_CBR = CBR_IN_Entry_;
        rtb_y = 0.0;
        t = 0.0;
        a = 0.0;
      } else if (t < CBR_P.U_sought - CBR_P.U_CC) {
        CBR_DW.is_c5_CBR = CBR_IN_CC_state_;
        rtb_y = 1.0;
        t = 0.0;
        a = 0.0;
      } else {
        rtb_y = 0.0;
        t = 0.0;
        a = 1.0;
      }
      break;

     case CBR_IN_CC_state_:
      if (t > CBR_P.U_sought - CBR_P.U_CC) {
        CBR_DW.is_c5_CBR = CBR_IN_CV_state_;
        rtb_y = 0.0;
        t = 1.0;
        a = 0.0;
      } else {
        rtb_y = 1.0;
        t = 0.0;
        a = 0.0;
      }
      break;

     case CBR_IN_CV_state_:
      if (rtb_tauz1 * rtb_tauz1 < CBR_P.I_CV * CBR_P.I_CV) {
        CBR_DW.is_c5_CBR = CBR_IN_CB_state_;
        rtb_y = 0.0;
        t = 0.0;
        a = 1.0;
      } else {
        rtb_y = 0.0;
        t = 1.0;
        a = 0.0;
      }
      break;

     default:
      if (t < CBR_P.U_sought - CBR_P.U_CC) {
        CBR_DW.is_c5_CBR = CBR_IN_CC_state_;
        rtb_y = 1.0;
        t = 0.0;
        a = 0.0;
      } else {
        rtb_y = 0.0;
        t = 0.0;
        a = 0.0;
      }
      break;
    }
  }

  for (i = 0; i < 126; i++) {
    rtb_ocvz[i] = CBR_U.Voltages[i] * 0.0;
  }

  if (a != 0.0) {
    memcpy(&x[0], &CBR_U.Voltages[0], 126U * sizeof(real_T));
    CBR_sort(x, iidx);
    for (i = 0; i < 126; i++) {
      x[i] = iidx[i];
    }

    for (i = 0; i < 36; i++) {
      rtb_ocvz[(int32_T)x[i] - 1] = 1.0;
    }
  }

  CBR_DW.Memory_PreviousInput = rtb_y * CBR_P.C_r + t * rtb_tauz1;
  memcpy(&CBR_DW.Memory1_PreviousInput[0], &rtb_ocvz[0], 126U * sizeof(real_T));
  CBR_DW.Memory6_PreviousInput = rtb_tauz1;
  CBR_DW.Memory5_PreviousInput = xbar;
  rt_UpdateTXYLogVars(CBR_M->rtwLogInfo, (&CBR_M->Timing.taskTime0));

  {
    if ((rtmGetTFinal(CBR_M)!=-1) &&
        !((rtmGetTFinal(CBR_M)-CBR_M->Timing.taskTime0) >
          CBR_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(CBR_M, "Simulation finished");
    }
  }

  if (!(++CBR_M->Timing.clockTick0)) {
    ++CBR_M->Timing.clockTickH0;
  }

  CBR_M->Timing.taskTime0 = CBR_M->Timing.clockTick0 * CBR_M->Timing.stepSize0 +
    CBR_M->Timing.clockTickH0 * CBR_M->Timing.stepSize0 * 4294967296.0;
}

void CBR_initialize(void)
{
  rt_InitInfAndNaN(sizeof(real_T));
  (void) memset((void *)CBR_M, 0,
                sizeof(RT_MODEL_CBR_T));
  rtmSetTFinal(CBR_M, 9000.0);
  CBR_M->Timing.stepSize0 = 180.0;

  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    CBR_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  {
    rtliSetLogXSignalInfo(CBR_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(CBR_M->rtwLogInfo, (NULL));
    rtliSetLogT(CBR_M->rtwLogInfo, "tout");
    rtliSetLogX(CBR_M->rtwLogInfo, "");
    rtliSetLogXFinal(CBR_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(CBR_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(CBR_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(CBR_M->rtwLogInfo, 0);
    rtliSetLogDecimation(CBR_M->rtwLogInfo, 1);
    rtliSetLogY(CBR_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(CBR_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(CBR_M->rtwLogInfo, (NULL));
  }

  (void) memset(((void *) &CBR_B), 0,
                sizeof(B_CBR_T));
  (void) memset((void *)&CBR_DW, 0,
                sizeof(DW_CBR_T));
  (void)memset(&CBR_U, 0, sizeof(ExtU_CBR_T));
  (void) memset((void *)&CBR_Y, 0,
                sizeof(ExtY_CBR_T));
  rt_StartDataLoggingWithStartTime(CBR_M->rtwLogInfo, 0.0, rtmGetTFinal(CBR_M),
    CBR_M->Timing.stepSize0, (&rtmGetErrorStatus(CBR_M)));

  {
    int32_T i;
    CBR_DW.Memory_PreviousInput = CBR_P.Memory_InitialCondition;
    for (i = 0; i < 126; i++) {
      CBR_DW.Memory1_PreviousInput[i] = CBR_P.Memory1_InitialCondition;
    }

    CBR_DW.Memory6_PreviousInput = CBR_P.Memory6_InitialCondition;
    CBR_DW.Memory5_PreviousInput = CBR_P.Memory5_InitialCondition;
    CBR_DW.is_active_c5_CBR = 0U;
    CBR_DW.is_c5_CBR = CBR_IN_NO_ACTIVE_CHILD;
  }
}

void CBR_terminate(void)
{
}
