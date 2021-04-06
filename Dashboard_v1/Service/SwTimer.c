/*
 * SwTimer.c
 *
 *  Created on: Mar 12, 2021
 *      Author: Esraa Abdelnaby
 */

#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"
#include "../Lib/Status.h"
#include "../Mcal/Timer_Driver/Timer_int.h"
#include "../Mcal/Dio_Driver/Dio_int.h"
#include "SwTimer.h"

static u32 NextFree;
static cbfList_t cbfList[CBF_MAX];

u8 SwTimer_register_cbf(u32 time_ms,SwTimerMode_t mode,SwTimerCbf_t cbf)
{
	u8 state = RT_ERROR;
	if(NextFree < CBF_MAX)
	{
		cbfList[NextFree].timerMs = time_ms;
		cbfList[NextFree].mode = mode;
		cbfList[NextFree].reload = time_ms;
		cbfList[NextFree].func = cbf;
		NextFree++;
		state = RT_SUCCESS;
	}
	return state;
}

static void SwTimer_Unregister(u32 idx)
{
	for(;idx < NextFree-1;idx++){
		cbfList[idx] = cbfList[idx + 1];
	}
	NextFree--;
}

static void Scheduler(void)
{
	u32 idx;
	for(idx=0;idx<NextFree;idx++)
	{
		if(cbfList[idx].timerMs == 0)
		{
			(cbfList[idx].func)();
			if(cbfList[idx].mode == SwTimerMode_once)
			{
				/* if the function is called once, remove it*/
				SwTimer_Unregister(idx);
				if(idx != 0) idx--;
			}
			else{
				cbfList[idx].timerMs=cbfList[idx].reload;
			}
		}
		cbfList[idx].timerMs--;
	}

}
void SwTimer_init(void)
{
	TIMER_vidInit();
	TIMER_vidLoadTimer(248);
	TIMER_u8SetCallBack_OVF( Scheduler );
	TIMER_u8EnableNotification();
	TIMER_u8StartTimer(ClkPre_1024);
}
