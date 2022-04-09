#include "CSE.h"
#include "CSE_private.h"
#include "UTMeanCovSqrt_Cre0pFhD.h"
#include "UTMeanCovSqrt_XXn7ctVv.h"
#include "look1_binlxpw.h"
#include "qr_EmoCK6PM.h"
#include "qr_GmaocXY1.h"
#include "rotate_YgpoDwi7.h"
#include "rt_hypotd_snf.h"
#include "svd_NBhHrtzf.h"
#include "trisolve_xiqzX6vu.h"
#include "xnrm2_hoYimUM0.h"

DW_CSE_T CSE_DW;
ExtU_CSE_T CSE_U;
ExtY_CSE_T CSE_Y;
static RT_MODEL_CSE_T CSE_M_;
RT_MODEL_CSE_T *const CSE_M = &CSE_M_;
static void UKFCorrectorAdditive_getPredict(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy);
void CSE_S_x(const real_T rtu_x[3], real_T rty_x_next[3])
{
  real_T rtb_Divide;
  real_T tmp;
  rtb_Divide = rtu_x[1] / rtu_x[2];
  tmp = exp(-CSE_P.Ts / look1_binlxpw(rtb_Divide, CSE_P.soc, CSE_P.tau, 12U));
  rty_x_next[0] = (1.0 - tmp) * CSE_U.u * look1_binlxpw(rtb_Divide, CSE_P.soc,
    CSE_P.Rp, 12U) + tmp * rtu_x[0];
  rty_x_next[1] = CSE_U.u * CSE_P.Ts + rtu_x[1];
  rty_x_next[2] = rtu_x[2];
}

void CSE_M_x(const real_T rtu_x[3], real_T *rty_y)
{
  real_T rtb_Divide;
  rtb_Divide = rtu_x[1] / rtu_x[2];
  *rty_y = (CSE_U.u * look1_binlxpw(rtb_Divide, CSE_P.soc, CSE_P.Rs, 12U) +
            look1_binlxpw(rtb_Divide, CSE_P.soc, CSE_P.ocv, 12U)) + rtu_x[0];
}

static void UKFCorrectorAdditive_getPredict(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy)
{
  real_T X2[18];
  real_T Y2[6];
  real_T X2_0[3];
  real_T Wcov[2];
  real_T Wmean[2];
  real_T Wcov_0;
  real_T c;
  real_T c_tmp;
  real_T tempY;
  int32_T X2_tmp;
  int32_T knt;
  c_tmp = alpha * alpha;
  c = c_tmp * (kappa + 3.0);
  Wmean[0] = 1.0 - 3.0 / c;
  Wmean[1] = 1.0 / (2.0 * c);
  Wcov[0] = ((1.0 - c_tmp) + beta) + Wmean[0];
  Wcov[1] = Wmean[1];
  if (Wmean[0] != 0.0) {
    *Sy = Wmean[0];
    c_tmp = Wmean[0];
    Wmean[0] /= Wmean[0];
    Wcov[0] /= *Sy;
    Wcov_0 = Wmean[1];
    Wmean[1] /= c_tmp;
    Wcov[1] = Wcov_0 / *Sy;
  } else {
    *Sy = 1.0;
  }

  c = sqrt(c);
  for (knt = 0; knt < 9; knt++) {
    c_tmp = c * S[knt];
    X2[knt] = c_tmp;
    X2[knt + 9] = -c_tmp;
  }

  for (knt = 0; knt < 6; knt++) {
    X2[3 * knt] += X1[0];
    X2_tmp = 3 * knt + 1;
    X2[X2_tmp] += X1[1];
    X2_tmp = 3 * knt + 2;
    X2[X2_tmp] += X1[2];
  }

  for (knt = 0; knt < 6; knt++) {
    for (X2_tmp = 0; X2_tmp < 3; X2_tmp++) {
      X2_0[X2_tmp] = X2[X2_tmp + 3 * knt];
    }

    CSE_M_x(X2_0, &tempY);
    Y2[knt] = tempY;
  }

  for (X2_tmp = 0; X2_tmp < 3; X2_tmp++) {
    X2_0[X2_tmp] = X1[X2_tmp];
  }

  CSE_M_x(X2_0, &tempY);
  UTMeanCovSqrt_Cre0pFhD(Wmean, Wcov, *Sy, tempY, Y2, X1, X2, Ymean, &c, Pxy);
  Wmean[0] = c;
  Wmean[1] = Rs;
  *Sy = c;
  tempY = xnrm2_hoYimUM0(1, Wmean, 2);
  if (tempY != 0.0) {
    tempY = rt_hypotd_snf(c, tempY);
    if (c >= 0.0) {
      tempY = -tempY;
    }

    if (fabs(tempY) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        Wmean[1] *= 9.9792015476736E+291;
        tempY *= 9.9792015476736E+291;
        *Sy *= 9.9792015476736E+291;
      } while (!(fabs(tempY) >= 1.0020841800044864E-292));

      tempY = rt_hypotd_snf(*Sy, xnrm2_hoYimUM0(1, Wmean, 2));
      if (*Sy >= 0.0) {
        tempY = -tempY;
      }

      for (X2_tmp = 0; X2_tmp <= knt; X2_tmp++) {
        tempY *= 1.0020841800044864E-292;
      }

      *Sy = tempY;
    } else {
      *Sy = tempY;
    }
  }
}

void CSE_step(void)
{
  real_T X2state[18];
  real_T Y2[18];
  real_T Ss[9];
  real_T U_0[9];
  real_T rtb_P_h[9];
  real_T C[3];
  real_T K[3];
  real_T U[3];
  real_T s[3];
  real_T tempY[3];
  real_T xNew[3];
  real_T absxk;
  real_T residual;
  real_T scale;
  real_T t;
  real_T temp;
  int32_T aoffset;
  int32_T b_j;
  int32_T coffset;
  int32_T iAcol;
  boolean_T errorCondition;
  static const real_T Wmean[2] = { 1.0, -0.1736111111111111 };

  static const real_T Wcov[2] = { 0.87666666666666659, -0.1736111111111111 };

  int32_T exitg1;
  boolean_T exitg2;
  boolean_T guard1 = false;
  if (CSE_P.Enable1_Value) {
    xNew[0] = CSE_DW.x[0];
    xNew[1] = CSE_DW.x[1];
    xNew[2] = CSE_DW.x[2];
    residual = CSE_U.y;
    temp = CSE_P.R1_Value;
    memcpy(&Ss[0], &CSE_DW.P[0], 9U * sizeof(real_T));
    for (iAcol = 0; iAcol < 3; iAcol++) {
      U[iAcol] = CSE_DW.x[iAcol];
    }

    CSE_M_x(U, &scale);
    UKFCorrectorAdditive_getPredict(temp, xNew, Ss, 0.2, 2.0, 0.0, &absxk, U,
      &scale);
    residual -= absxk;
    C[0] = U[0];
    C[1] = U[1];
    C[2] = U[2];
    trisolve_xiqzX6vu(scale, C);
    K[0] = C[0];
    K[1] = C[1];
    K[2] = C[2];
    trisolve_xiqzX6vu(scale, K);
    U[0] = K[0] * scale;
    U[1] = K[1] * scale;
    U[2] = K[2] * scale;
    for (b_j = 0; b_j < 3; b_j++) {
      rtb_P_h[3 * b_j] = Ss[b_j];
      rtb_P_h[3 * b_j + 1] = Ss[b_j + 3];
      rtb_P_h[3 * b_j + 2] = Ss[b_j + 6];
    }

    for (b_j = 0; b_j < 2; b_j++) {
      rtb_P_h[b_j + 1] = 0.0;
    }

    rtb_P_h[5] = 0.0;
    errorCondition = false;
    if ((rtb_P_h[0] == 0.0) || (rtb_P_h[4] == 0.0) || (rtb_P_h[8] == 0.0)) {
      errorCondition = true;
    }

    guard1 = false;
    if (errorCondition) {
      guard1 = true;
    } else {
      C[2] = U[2];
      C[0] = U[0] / rtb_P_h[0];
      C[1] = (U[1] - C[0] * rtb_P_h[3]) / rtb_P_h[4];
      temp = U[2];
      for (b_j = 0; b_j < 2; b_j++) {
        temp -= rtb_P_h[b_j + 6] * C[b_j];
      }

      C[2] = temp / rtb_P_h[8];
      scale = 3.3121686421112381E-170;
      absxk = fabs(C[0]);
      if (absxk > scale) {
        t = scale / absxk;
        temp = 0.0 * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        temp = t * t;
      }

      absxk = fabs(C[1]);
      if (absxk > scale) {
        t = scale / absxk;
        temp = temp * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        temp += t * t;
      }

      absxk = fabs(C[2]);
      if (absxk > scale) {
        t = scale / absxk;
        temp = temp * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        temp += t * t;
      }

      temp = scale * sqrt(temp);
      if (temp >= 1.0) {
        guard1 = true;
      } else {
        rotate_YgpoDwi7(sqrt(1.0 - temp * temp), C[2], &U[2], &s[2], &temp);
        C[2] = 0.0;
        rotate_YgpoDwi7(temp, C[1], &U[1], &s[1], &temp);
        C[1] = 0.0;
        rotate_YgpoDwi7(temp, C[0], &U[0], &s[0], &temp);
        C[0] = 0.0;
        for (iAcol = 0; iAcol + 1 > 0; iAcol--) {
          temp = s[iAcol] * rtb_P_h[iAcol];
          rtb_P_h[iAcol] = U[iAcol] * rtb_P_h[iAcol] - s[iAcol] * C[0];
          C[0] = U[iAcol] * C[0] + temp;
        }

        for (iAcol = 1; iAcol + 1 > 0; iAcol--) {
          temp = rtb_P_h[iAcol + 3];
          rtb_P_h[iAcol + 3] = temp * U[iAcol] - s[iAcol] * C[1];
          C[1] = U[iAcol] * C[1] + temp * s[iAcol];
        }

        for (iAcol = 2; iAcol + 1 > 0; iAcol--) {
          temp = rtb_P_h[iAcol + 6];
          rtb_P_h[iAcol + 6] = temp * U[iAcol] - s[iAcol] * C[2];
          C[2] = U[iAcol] * C[2] + temp * s[iAcol];
        }
      }
    }

    if (guard1) {
      for (b_j = 0; b_j < 3; b_j++) {
        for (iAcol = 0; iAcol < 3; iAcol++) {
          coffset = b_j + 3 * iAcol;
          Ss[coffset] = 0.0;
          Ss[coffset] += rtb_P_h[3 * b_j] * rtb_P_h[3 * iAcol];
          Ss[coffset] += rtb_P_h[3 * b_j + 1] * rtb_P_h[3 * iAcol + 1];
          Ss[coffset] += rtb_P_h[3 * b_j + 2] * rtb_P_h[3 * iAcol + 2];
          U_0[iAcol + 3 * b_j] = U[iAcol] * U[b_j];
        }
      }

      errorCondition = true;
      for (b_j = 0; b_j < 9; b_j++) {
        temp = Ss[b_j] - U_0[b_j];
        if (errorCondition && ((!rtIsInf(temp)) && (!rtIsNaN(temp)))) {
        } else {
          errorCondition = false;
        }

        rtb_P_h[b_j] = temp;
      }

      if (errorCondition) {
        svd_NBhHrtzf(rtb_P_h, Ss, s, U_0);
      } else {
        s[0] = (rtNaN);
        s[1] = (rtNaN);
        s[2] = (rtNaN);
        for (b_j = 0; b_j < 9; b_j++) {
          U_0[b_j] = (rtNaN);
        }
      }

      memset(&Ss[0], 0, 9U * sizeof(real_T));
      Ss[0] = s[0];
      Ss[4] = s[1];
      Ss[8] = s[2];
      for (b_j = 0; b_j < 9; b_j++) {
        Ss[b_j] = sqrt(Ss[b_j]);
      }

      for (b_j = 0; b_j < 3; b_j++) {
        for (iAcol = 0; iAcol < 3; iAcol++) {
          coffset = b_j + 3 * iAcol;
          rtb_P_h[coffset] = 0.0;
          rtb_P_h[coffset] += Ss[3 * b_j] * U_0[iAcol];
          rtb_P_h[coffset] += Ss[3 * b_j + 1] * U_0[iAcol + 3];
          rtb_P_h[coffset] += Ss[3 * b_j + 2] * U_0[iAcol + 6];
        }
      }

      errorCondition = true;
      b_j = 0;
      exitg2 = false;
      while ((!exitg2) && (b_j < 3)) {
        iAcol = b_j + 1;
        do {
          exitg1 = 0;
          if (iAcol + 1 < 4) {
            if (!(rtb_P_h[3 * b_j + iAcol] == 0.0)) {
              errorCondition = false;
              exitg1 = 1;
            } else {
              iAcol++;
            }
          } else {
            b_j++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      if (!errorCondition) {
        memcpy(&U_0[0], &rtb_P_h[0], 9U * sizeof(real_T));
        qr_EmoCK6PM(U_0, Ss, rtb_P_h);
      }
    }

    for (b_j = 0; b_j < 3; b_j++) {
      CSE_DW.P[3 * b_j] = rtb_P_h[b_j];
      CSE_DW.P[3 * b_j + 1] = rtb_P_h[b_j + 3];
      CSE_DW.P[3 * b_j + 2] = rtb_P_h[b_j + 6];
      CSE_DW.x[b_j] = K[b_j] * residual + xNew[b_j];
    }
  }

  CSE_Y.soc = CSE_DW.x[1] / CSE_DW.x[2];
  CSE_Y.C = CSE_DW.x[2];
  memcpy(&Ss[0], &CSE_DW.P[0], 9U * sizeof(real_T));
  xNew[0] = CSE_DW.x[0];
  xNew[1] = CSE_DW.x[1];
  xNew[2] = CSE_DW.x[2];
  for (iAcol = 0; iAcol < 3; iAcol++) {
    U[iAcol] = CSE_DW.x[iAcol];
  }

  CSE_S_x(U, tempY);
  for (b_j = 0; b_j < 9; b_j++) {
    residual = 0.34641016151377552 * Ss[b_j];
    X2state[b_j] = residual;
    X2state[b_j + 9] = -residual;
    Ss[b_j] = residual;
  }

  for (b_j = 0; b_j < 6; b_j++) {
    X2state[3 * b_j] += xNew[0];
    iAcol = 3 * b_j + 1;
    X2state[iAcol] += xNew[1];
    iAcol = 3 * b_j + 2;
    X2state[iAcol] += xNew[2];
  }

  for (b_j = 0; b_j < 6; b_j++) {
    for (iAcol = 0; iAcol < 3; iAcol++) {
      s[iAcol] = X2state[iAcol + 3 * b_j];
    }

    CSE_S_x(s, tempY);
    Y2[3 * b_j] = tempY[0];
    Y2[3 * b_j + 1] = tempY[1];
    Y2[3 * b_j + 2] = tempY[2];
  }

  for (iAcol = 0; iAcol < 3; iAcol++) {
    s[iAcol] = xNew[iAcol];
  }

  CSE_S_x(s, tempY);
  UTMeanCovSqrt_XXn7ctVv(Wmean, Wcov, -23.999999999999996, tempY, Y2, xNew,
    X2state, CSE_DW.x, Ss, rtb_P_h);
  memset(&rtb_P_h[0], 0, 9U * sizeof(real_T));
  rtb_P_h[0] = 1.0;
  rtb_P_h[4] = 1.0;
  rtb_P_h[8] = 1.0;
  for (iAcol = 0; iAcol < 3; iAcol++) {
    coffset = iAcol * 3;
    for (b_j = 0; b_j < 3; b_j++) {
      aoffset = b_j * 3;
      U_0[coffset + b_j] = (Ss[aoffset + 1] * (real_T)(int8_T)rtb_P_h[iAcol + 3]
                            + Ss[aoffset] * (real_T)(int8_T)rtb_P_h[iAcol]) +
        Ss[aoffset + 2] * (real_T)(int8_T)rtb_P_h[iAcol + 6];
    }
  }

  for (b_j = 0; b_j < 3; b_j++) {
    Y2[6 * b_j] = U_0[3 * b_j];
    Y2[6 * b_j + 3] = CSE_P.Q_Value[b_j];
    Y2[6 * b_j + 1] = U_0[3 * b_j + 1];
    Y2[6 * b_j + 4] = CSE_P.Q_Value[b_j + 3];
    Y2[6 * b_j + 2] = U_0[3 * b_j + 2];
    Y2[6 * b_j + 5] = CSE_P.Q_Value[b_j + 6];
  }

  qr_GmaocXY1(Y2, X2state, rtb_P_h);
  for (b_j = 0; b_j < 3; b_j++) {
    CSE_DW.P[3 * b_j] = rtb_P_h[b_j];
    CSE_DW.P[3 * b_j + 1] = rtb_P_h[b_j + 3];
    CSE_DW.P[3 * b_j + 2] = rtb_P_h[b_j + 6];
  }

  rt_UpdateTXYLogVars(CSE_M->rtwLogInfo, (&CSE_M->Timing.taskTime0));

  {
    if ((rtmGetTFinal(CSE_M)!=-1) &&
        !((rtmGetTFinal(CSE_M)-CSE_M->Timing.taskTime0) >
          CSE_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(CSE_M, "Simulation finished");
    }
  }

  if (!(++CSE_M->Timing.clockTick0)) {
    ++CSE_M->Timing.clockTickH0;
  }

  CSE_M->Timing.taskTime0 = CSE_M->Timing.clockTick0 * CSE_M->Timing.stepSize0 +
    CSE_M->Timing.clockTickH0 * CSE_M->Timing.stepSize0 * 4294967296.0;
}

void CSE_initialize(void)
{
  rt_InitInfAndNaN(sizeof(real_T));
  (void) memset((void *)CSE_M, 0,
                sizeof(RT_MODEL_CSE_T));
  rtmSetTFinal(CSE_M, 9000.0);
  CSE_M->Timing.stepSize0 = 0.2;

  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    CSE_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  {
    rtliSetLogXSignalInfo(CSE_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(CSE_M->rtwLogInfo, (NULL));
    rtliSetLogT(CSE_M->rtwLogInfo, "tout");
    rtliSetLogX(CSE_M->rtwLogInfo, "");
    rtliSetLogXFinal(CSE_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(CSE_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(CSE_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(CSE_M->rtwLogInfo, 0);
    rtliSetLogDecimation(CSE_M->rtwLogInfo, 1);
    rtliSetLogY(CSE_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(CSE_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(CSE_M->rtwLogInfo, (NULL));
  }

  (void) memset((void *)&CSE_DW, 0,
                sizeof(DW_CSE_T));
  (void)memset(&CSE_U, 0, sizeof(ExtU_CSE_T));
  (void) memset((void *)&CSE_Y, 0,
                sizeof(ExtY_CSE_T));
  rt_StartDataLoggingWithStartTime(CSE_M->rtwLogInfo, 0.0, rtmGetTFinal(CSE_M),
    CSE_M->Timing.stepSize0, (&rtmGetErrorStatus(CSE_M)));
  memcpy(&CSE_DW.P[0], &CSE_P.DataStoreMemoryP_InitialValue[0], 9U * sizeof
         (real_T));
  CSE_DW.x[0] = CSE_P.DataStoreMemoryx_InitialValue[0];
  CSE_DW.x[1] = CSE_P.DataStoreMemoryx_InitialValue[1];
  CSE_DW.x[2] = CSE_P.DataStoreMemoryx_InitialValue[2];
}

void CSE_terminate(void)
{
}
