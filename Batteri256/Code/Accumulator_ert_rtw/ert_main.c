#include <stddef.h>
#include <stdio.h>
#include "Accumulator.h"

void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;
  if (OverrunFlag) {
    rtmSetErrorStatus(Accumulator_M, "Overrun");
    return;
  }

  OverrunFlag = true;
  Accumulator_step();
  OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
  (void)(argc);
  (void)(argv);
  Accumulator_initialize();
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(Accumulator_M) == (NULL)) {
  }

  Accumulator_terminate();
  return 0;
}
