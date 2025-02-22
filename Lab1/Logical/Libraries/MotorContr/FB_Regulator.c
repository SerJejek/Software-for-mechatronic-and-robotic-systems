
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorContr.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Regulator(struct FB_Regulator* inst)
{
    REAL a = inst->e * inst->k_p;
    REAL b = inst->e * inst->k_i * inst->dt;
    
    inst->integrator.in = b + inst->iyOld;
    FB_Integrator(&inst->integrator);
    if (a > inst->max_abs_value || a < -inst->max_abs_value) {
        if (a > 0) a = inst->max_abs_value;
        else a = -inst->max_abs_value;
    }
	
    a += inst->integrator.out;
    if (a < inst->max_abs_value && a > -inst->max_abs_value)
        inst->u = a;
    else
    {
        if (a > 0) inst->u = inst->max_abs_value;
        else inst ->u = -inst->max_abs_value;
    }
	
    inst->iyOld = inst->u - a;
}
