#include <stddef.h>
#include <stdio.h>
#include "CSE.h"

void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;
  if (OverrunFlag) {
    rtmSetErrorStatus(CSE_M, "Overrun");
    return;
  }

  OverrunFlag = true;
  CSE_step();
  OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
  (void)(argc);
  (void)(argv);
  CSE_initialize();
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(CSE_M) == (NULL)) {
  }

  CSE_terminate();
  return 0;
}
