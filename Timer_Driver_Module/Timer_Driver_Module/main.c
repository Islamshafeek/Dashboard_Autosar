
/*
 * main.c
 *
 *  Created on: Mar 19, 2021
 *      Author: Rdwa Salah
 */


/***************************************************************************
 File Description:
 *
 *
 ***************************************************************************/


#include "Lib/Std_Types.h"
#include "Lib/Bit_Math.h"
#include "Lib/ATmega32_Registers.h"
#include "Lib/Bit_Mask.h"
#include "Timer_priv.h"
#include "Timer_int.h"
#include "Port_Driver2/Port_int.h"
#include "Led_Driver/Led_int.h"

/* Test for NORMAL mode*/
void func(void);
static u16 counter = 0 ;
int main(void)
{
	//Led_vidTurnOn(LED_u8ID_1);
	Port_vidInit();
	TIMER_vidInit();
	TIMER_vidLoadTimer(248);
	TIMER_u8SetCallBack_OVF(func);
	_SREG.Bits.Bit7 = 1;
	TIMER_u8EnableNotification();
	TIMER_u8StartTimer(ClkPre_1024);

	Led_vidTurnOff(LED_u8ID_1);

	while(1)
	{

	}
}

void func (void)
{
	counter++;
	if ( counter == 40)
	{
		TIMER_vidLoadTimer(248);
		counter = 0 ;
		TIMER_u8StartTimer(ClkPre_1024);
		Led_vidToggleLed(LED_u8ID_2);
	}
}

