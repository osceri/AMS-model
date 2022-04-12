#include <stddef.h>
#include <stdio.h>
#include "SIM0.h"

void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;
  if (OverrunFlag) {
    rtmSetErrorStatus(SIM0_M, "Overrun");
    return;
  }

  OverrunFlag = true;
  SIM0_step();
  OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
  (void)(argc);
  (void)(argv);
  SIM0_initialize();
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(SIM0_M) == (NULL)) {
  }

  SIM0_terminate();
  return 0;
}
