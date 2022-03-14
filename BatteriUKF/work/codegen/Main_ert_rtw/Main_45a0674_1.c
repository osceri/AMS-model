/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Main/Solver Configuration1'.
 */

#include "ne_std.h"
#include "pm_default_allocator.h"
#include "ne_dae_fwd.h"
#include "ne_profiler_fwd.h"
#include "ne_dae_construct.h"
#include "nesl_la.h"
#include "Main_45a0674_1.h"
#include "Main_45a0674_1_ds.h"

void Main_45a0674_1_dae( NeDae **dae, const NeModelParameters *modelParams,
  const NeSolverParameters *solverParams)
{
  PmAllocator *ne_allocator;
  const McLinearAlgebraFactory *linear_algebra_ptr =
    (solverParams->mLinearAlgebra == NE_FULL_LA) ?
    get_rtw_linear_algebra() :
    ((solverParams->mLinearAlgebra == NE_SPARSE_LA) ?
     mc_get_csparse_linear_algebra() :
     get_auto_linear_algebra());
  ne_allocator = pm_default_allocator();
  ne_dae_create( dae,
                Main_45a0674_1_dae_ds( ne_allocator ),
                NULL,
                FALSE,
                false,
                NULL,
                *solverParams,
                *modelParams,
                linear_algebra_ptr,
                NULL,
                NULL,
                NULL,
                ne_allocator);
}
