/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Subsystem/Subsystem/Solver Configuration1'.
 */

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#include "nesl_rtw.h"
#include "Subsystem_8f6c35c5_1.h"
#include "Subsystem_8f6c35c5_1_gateway.h"

void Subsystem_8f6c35c5_1_gateway(void)
{
  NeModelParameters modelparams = { (NeSolverType) 2, 0.001, 0, 0, 0.2, 0, 0, 0,
    0, (SscLoggingSetting) 1, 571272480, };

  NeSolverParameters solverparams = { 0, 0, 1, 0, 0, 0.001, 1e-06, 1e-09, 0, 0,
    100, 0, 1, 0, 1e-09, 1, (NeLocalSolverChoice) 0, 0.2, 1, 3, 2, 0, 2,
    (NeLinearAlgebraChoice) 0, (NeEquationFormulationChoice) 0, 1024, 1, 0.001,
    (NePartitionStorageMethod) 0, 1024, (NePartitionMethod) 1, };

  const NeOutputParameters* outputparameters = NULL;
  NeDae* dae;
  size_t numOutputs = 0;
  int rtpDaes[1] = { 0 };

  {
    static const NeOutputParameters outputparameters_init[] = { { 0, 0, }, { 0,
        1, }, };

    outputparameters = outputparameters_init;
    numOutputs = sizeof(outputparameters_init)/sizeof(outputparameters_init[0]);
  }

  Subsystem_8f6c35c5_1_dae(&dae,
    &modelparams,
    &solverparams);
  nesl_register_simulator_group("Subsystem/Subsystem/Solver Configuration1_1",
    1,
    &dae,
    &solverparams,
    &modelparams,
    numOutputs,
    outputparameters,
    1,
    rtpDaes);
}
