#include "rtwtypes.h"
#include "sort_iw8mDS81.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "merge_SqkScL3b.h"

void sort_iw8mDS81(real_T x[126], int32_T idx[126])
{
  real_T xwork[126];
  real_T x4[4];
  int32_T iwork[126];
  int32_T i;
  int32_T i1;
  int32_T i2;
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
  ib = -1;
  for (i = 0; i < 126; i++) {
    if (rtIsNaN(x[i])) {
      idx[125 - nNaNs] = i + 1;
      xwork[125 - nNaNs] = x[i];
      nNaNs++;
    } else {
      ib++;
      idx4[ib] = (int8_T)(i + 1);
      x4[ib] = x[i];
      if (ib + 1 == 4) {
        real_T tmp;
        real_T tmp_0;
        int32_T i3;
        int32_T i4;
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
        ib = -1;
      }
    }
  }

  if (ib + 1 > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    switch (ib + 1) {
     case 1:
      perm[0] = 1;
      break;

     case 2:
      if (x4[0] >= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
      break;

     default:
      if (x4[0] >= x4[1]) {
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
      break;
    }

    for (i = 0; i <= ib; i++) {
      i1 = perm[i] - 1;
      i2 = ((i - nNaNs) - ib) + 125;
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
    memset(&iwork[0], 0, 126U * sizeof(int32_T));
    ib = (126 - nNaNs) >> 2;
    i = 4;
    while (ib > 1) {
      if ((ib & 1U) != 0U) {
        ib--;
        i1 = i * ib;
        i2 = 126 - (nNaNs + i1);
        if (i2 > i) {
          merge_SqkScL3b(idx, x, i1, i, i2 - i, iwork, xwork);
        }
      }

      i1 = i << 1;
      ib >>= 1;
      for (i2 = 0; i2 < ib; i2++) {
        merge_SqkScL3b(idx, x, i2 * i1, i, i, iwork, xwork);
      }

      i = i1;
    }

    if (126 - nNaNs > i) {
      merge_SqkScL3b(idx, x, 0, i, 126 - (nNaNs + i), iwork, xwork);
    }
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
