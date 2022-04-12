/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'SIM0/SIM/Solver Configuration'.
 */

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#include "nesl_rtw.h"
#include "SIM0_627956e1_1.h"
#include "SIM0_627956e1_1_gateway.h"

void SIM0_627956e1_1_gateway(void)
{
  NeModelParameters modelparams = { (NeSolverType) 0, 0.001, 0.001, 0.001, 0, 0,
    (NeModifyAbsTol) 0, 0.001, 0, 0, 0, 0, (SscLoggingSetting) 0, 571632576, 1,
  };

  NeSolverParameters solverparams = { 0, 0, 1, 0, 0, 0.001, 0.001, 1e-09, 0, 0,
    100, 0, 1, (NeIndexReductionMethod) 1, 0, 1e-09, 1, (NeLocalSolverChoice) 0,
    0.2, 1, 3, 2, 0, 2, (NeLinearAlgebraChoice) 0, 0,
    (NeEquationFormulationChoice) 0, 1024, 1, 0.001, (NePartitionStorageMethod)
    0, 1024, (NePartitionMethod) 0, };

  const NeOutputParameters* outputparameters = NULL;
  NeDae* dae;
  size_t numOutputs = 0;
  int* rtpDaes = NULL;
  int* rtwLogDaes = NULL;

  {
    static const NeOutputParameters outputparameters_init[] = { { 0, 0, }, { 0,
        1, }, { 0, 2, }, };

    outputparameters = outputparameters_init;
    numOutputs = sizeof(outputparameters_init)/sizeof(outputparameters_init[0]);
  }

  SIM0_627956e1_1_dae(&dae,
                      &modelparams,
                      &solverparams);
  nesl_register_simulator_group("SIM0/SIM/Solver Configuration_1",
    1,
    &dae,
    &solverparams,
    &modelparams,
    numOutputs,
    outputparameters,
    0,
    rtpDaes,
    0,
    rtwLogDaes);
}
