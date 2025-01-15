
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_StateMachine(struct FB_StateMachine* inst)
{
    if (!inst->enable) {
        inst->command = CMD_SHUTDOWN;
    }
    else {
        switch(inst->state & 0x6f)
        {
            case STATE_DISABLED:
                inst->command = CMD_SHUTDOWN;
                break;
            
            case STATE_SWITCH_ON:
                inst->command = CMD_SWITCH_ON;
                break;
            
            case STATE_READY:
                inst->command = CMD_ENABLED;
                break;
        }
    }
}
