#include "CBR.h"
#include "rtwtypes.h"
#include "CBR_private.h"
#include "rt_nonfinite.h"
#include <string.h>
#include "sort_iw8mDS81.h"
#include "look1_binlxpw.h"

#define CBR_IN_CB_state_               ((uint8_T)1U)
#define CBR_IN_CC_state_               ((uint8_T)2U)
#define CBR_IN_CV_state_               ((uint8_T)3U)
#define CBR_IN_Entry_                  ((uint8_T)4U)

DW_CBR_T CBR_DW;
ExtU_CBR_T CBR_U;
ExtY_CBR_T CBR_Y;
static RT_MODEL_CBR_T CBR_M_;
RT_MODEL_CBR_T *const CBR_M = &CBR_M_;
void CBR_MATLABFunction1(const real_T rtu_u[126], real_T *rty_y)
{
  real_T y;
  int32_T k;
  y = rtu_u[0];
  for (k = 0; k < 125; k++) {
    y += rtu_u[k + 1];
  }

  *rty_y = y / 126.0;
}

void CBR_step(void)
{
  real_T rtb_ocvz[126];
  real_T a;
  real_T rtb_y;
  real_T rtb_y_e;
  real_T rtb_y_f;
  real_T rtb_y_k;
  real_T t;
  int32_T iidx[126];
  int32_T idx;
  int32_T k;
  CBR_Y.Current = CBR_DW.Memory_PreviousInput;
  for (idx = 0; idx < 126; idx++) {
    CBR_Y.Balances[idx] = CBR_DW.Memory1_PreviousInput[idx];
    rtb_ocvz[idx] = look1_binlxpw(CBR_U.SOCs[idx], CBR_P.soc, CBR_P.ocv, 12U);
  }

  if (!rtIsNaN(CBR_U.Voltages[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 127)) {
      if (!rtIsNaN(CBR_U.Voltages[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    rtb_y_k = CBR_U.Voltages[0];
  } else {
    rtb_y_k = CBR_U.Voltages[idx - 1];
    while (idx + 1 <= 126) {
      if (rtb_y_k < CBR_U.Voltages[idx]) {
        rtb_y_k = CBR_U.Voltages[idx];
      }

      idx++;
    }
  }

  rtb_y = 0.0;
  rtb_y_e = CBR_U.Voltages[0];
  for (idx = 0; idx < 125; idx++) {
    rtb_y_e += CBR_U.Voltages[idx + 1];
  }

  rtb_y_e /= 126.0;
  for (k = 0; k < 126; k++) {
    t = CBR_U.Voltages[k] - rtb_y_e;
    rtb_y += t * t;
  }

  real_T rtb_Rsz1;
  rtb_y /= 125.0;
  CBR_MATLABFunction1(rtb_ocvz, &rtb_y_e);
  rtb_y_e = CBR_P.U_sought - rtb_y_e;
  CBR_MATLABFunction1(CBR_U.SOCs, &rtb_y_f);
  rtb_Rsz1 = look1_binlxpw(rtb_y_f, CBR_P.soc, CBR_P.Rs, 12U);
  t = look1_binlxpw(rtb_y_f, CBR_P.soc, CBR_P.tau, 12U);
  a = rtb_Rsz1 * t;
  rtb_y_f = (rtb_Rsz1 + look1_binlxpw(rtb_y_f, CBR_P.soc, CBR_P.Rp, 12U)) *
    CBR_P.Ts;
  t = (((2.0 * t + CBR_P.Ts) * rtb_y_e + (CBR_P.Ts - 2.0 * t) *
        CBR_DW.Memory5_PreviousInput) - (rtb_y_f - 2.0 * a) *
       CBR_DW.Memory6_PreviousInput) / (2.0 * a + rtb_y_f);
  if (CBR_DW.is_active_c5_CBR == 0U) {
    CBR_DW.is_active_c5_CBR = 1U;
    CBR_DW.is_c5_CBR = CBR_IN_Entry_;
    rtb_y_k = 0.0;
    rtb_y = 0.0;
    a = 0.0;
  } else {
    switch (CBR_DW.is_c5_CBR) {
     case CBR_IN_CB_state_:
      if (rtb_y < CBR_P.U_tol) {
        CBR_DW.is_c5_CBR = CBR_IN_Entry_;
        rtb_y_k = 0.0;
        rtb_y = 0.0;
        a = 0.0;
      } else if (rtb_y_k < CBR_P.U_sought - CBR_P.U_CC) {
        CBR_DW.is_c5_CBR = CBR_IN_CC_state_;
        rtb_y_k = 1.0;
        rtb_y = 0.0;
        a = 0.0;
      } else {
        rtb_y_k = 0.0;
        rtb_y = 0.0;
        a = 1.0;
      }
      break;

     case CBR_IN_CC_state_:
      if (rtb_y_k > CBR_P.U_sought - CBR_P.U_CC) {
        CBR_DW.is_c5_CBR = CBR_IN_CV_state_;
        rtb_y_k = 0.0;
        rtb_y = 1.0;
        a = 0.0;
      } else {
        rtb_y_k = 1.0;
        rtb_y = 0.0;
        a = 0.0;
      }
      break;

     case CBR_IN_CV_state_:
      if (t * t < CBR_P.I_CV * CBR_P.I_CV) {
        CBR_DW.is_c5_CBR = CBR_IN_CB_state_;
        rtb_y_k = 0.0;
        rtb_y = 0.0;
        a = 1.0;
      } else {
        rtb_y_k = 0.0;
        rtb_y = 1.0;
        a = 0.0;
      }
      break;

     default:
      if (rtb_y_k < CBR_P.U_sought - CBR_P.U_CC) {
        CBR_DW.is_c5_CBR = CBR_IN_CC_state_;
        rtb_y_k = 1.0;
        rtb_y = 0.0;
        a = 0.0;
      } else if (rtb_y > CBR_P.U_tol) {
        CBR_DW.is_c5_CBR = CBR_IN_CB_state_;
        rtb_y_k = 0.0;
        rtb_y = 0.0;
        a = 1.0;
      } else {
        rtb_y_k = 0.0;
        rtb_y = 0.0;
        a = 0.0;
      }
      break;
    }
  }

  for (idx = 0; idx < 126; idx++) {
    CBR_DW.Memory1_PreviousInput[idx] = CBR_U.Voltages[idx] * 0.0;
  }

  if (a != 0.0) {
    memcpy(&rtb_ocvz[0], &CBR_U.Voltages[0], 126U * sizeof(real_T));
    sort_iw8mDS81(rtb_ocvz, iidx);
    for (idx = 0; idx < 126; idx++) {
      rtb_ocvz[idx] = iidx[idx];
    }

    for (k = 0; k < 36; k++) {
      CBR_DW.Memory1_PreviousInput[(int32_T)rtb_ocvz[k] - 1] = 1.0;
    }
  }

  CBR_DW.Memory_PreviousInput = rtb_y_k * CBR_P.C_r + rtb_y * t;
  CBR_DW.Memory6_PreviousInput = t;
  CBR_DW.Memory5_PreviousInput = rtb_y_e;
}

void CBR_initialize(void)
{
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    CBR_DW.Memory_PreviousInput = CBR_P.Memory_InitialCondition;
    for (i = 0; i < 126; i++) {
      CBR_DW.Memory1_PreviousInput[i] = CBR_P.Memory1_InitialCondition;
    }

    CBR_DW.Memory6_PreviousInput = CBR_P.Memory6_InitialCondition;
    CBR_DW.Memory5_PreviousInput = CBR_P.Memory5_InitialCondition;
  }
}

void CBR_terminate(void)
{
}
