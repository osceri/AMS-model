#include <stddef.h>
#include <stdio.h>
#include "Charger.h"

void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;
  if (OverrunFlag) {
    rtmSetErrorStatus(Charger_M, "Overrun");
    return;
  }

  OverrunFlag = true;
  Charger_step();
  OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
  (void)(argc);
  (void)(argv);
  Charger_initialize();
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(Charger_M) == (NULL)) {
  }

  Charger_terminate();
  return 0;
}
