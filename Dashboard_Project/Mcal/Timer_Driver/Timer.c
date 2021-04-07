
/*
 * Timer.c
 *
 *  Created on: Mar 19, 2021
 *      Author: Rdwa Salah
 */


/***************************************************************************
 File Description:
 *
 *
 ***************************************************************************/

#include "../../Lib/Std_Types.h"
#include "../../Lib/Bit_Mask.h"
#include "../../Lib/Bit_Math.h"
#include "../../Lib/ATmega32_Registers.h"
#include "../../Lib/Status.h"
#include <avr/interrupt.h>
#include "Timer_int.h"
#include "Timer_cfg.h"
#include "../Dio_Driver/Dio_int.h"

void ( * Cbf_ptr_OVF)  (void) = {NULL}; //initialize the pointers to Null
void ( * Cbf_ptr_COMP) (void) = {NULL}; //initialize the pointers to Null


/****************************************************************************************/
u8 TIMER_vidInit(void)
{
	//Bit 6, 3 – WGM01:0: Waveform Generation Mode in TCCR0
	_TCCR0 &= CLEAR_MODE_BITS;
#if 	TIMER_MODE == TIMER_NORMAL_MODE
	_TCCR0 &= (BIT3_CLEAR & BIT6_CLEAR);

#elif	TIMER_MODE == TIMER_CTC_MODE
	_TCCR0 |= CTC_MODE;

#elif 	TIMER_MODE == TIMER_FAST_PWM_MODE
	_TCCR0 |= FAST_PWM_MODE;

#elif 	TIMER_MODE == TIMER_PHASE_CORRECT_PWM_MODE
	_TCCR0 |= PHASE_CORRECT_PWM_MODE;

#else
#warning "Warning: Wrong Mode Configuration "
#endif

	return RT_SUCCESS;
}
/****************************************************************************************/
u8 TIMER_u8EnableNotification(void)
{
	/*
	 * Overflow Interrupt Enable BIT0
	 */
	_TIMSK 	|= BIT0;
	return RT_SUCCESS;
}
/****************************************************************************************/
u8 TIMER_u8EnableCOMP_Int(void)
{
	/*
	 * Output Compare Match Interrupt Disable BIT1
	 */
	_TIMSK |= BIT1;
	return RT_SUCCESS;
}
/****************************************************************************************/
u8 TIMER_u8DisableNotification(void)
{
	/*
	 * Overflow Interrupt Disable BIT0
	 */
	_TIMSK &= BIT0_CLEAR;
	return RT_SUCCESS;
}
/****************************************************************************************/
u8 TIMER_u8DisableCOMP_Int(void)
{
	/*
	 * Output Compare Match Interrupt Disable BIT1
	 */
	_TIMSK &= BIT1_CLEAR;
	return RT_SUCCESS;
}
/****************************************************************************************/
u8 TIMER_u8StartTimer(u8 Clock)
{
	u8 Loc_u8Status=RT_SUCCESS;
	_TCCR0 &= CLEAR_CLK_SRC_BITS;
	switch(Clock)
	{
	case ClkPre_1:
		_TCCR0 |= PRESCALER_1;
		break;

	case ClkPre_8:
		_TCCR0 |= PRESCALER_8;
		break;

	case ClkPre_64:
		_TCCR0 |= PRESCALER_64;
		break;

	case ClkPre_256:
		_TCCR0 &= PRESCALER_256;
		break;

	case ClkPre_1024:
		_TCCR0 |= (BIT0 | BIT2);
		break;

	default:
		Loc_u8Status=RT_ERROR;
		break;
	}
	return Loc_u8Status;
}
/****************************************************************************************/
u8 TIMER_u8StopTimer(void)
{
	_TCCR0 &= CLEAR_MODE_BITS;
	_TCCR0 |= NO_CLOCK_SOURCE;
	return RT_SUCCESS;
}

/****************************************************************************************/
u8 TIMER_vidLoadTimer(u8 Copy_u8Value)
{
	/*
	 * counter for the number of overflows (31)
	 * value = 127
	 */
	_TCNT0 = Copy_u8Value;
	return RT_SUCCESS;
}
/****************************************************************************************/
u8 TIMER_u8SetCallBack_OVF(void(*ptr)(void))
{
	u8 Loc_u8Status = RT_SUCCESS;
	if(ptr != NULL)
	{
		Cbf_ptr_OVF =  ptr;
	}
	else
	{
		Loc_u8Status = RT_PARAM;
	}
	return Loc_u8Status;
}
/****************************************************************************************/
u8 TIMER_u8SetCallBack_COMP(void(*ptr)(void))
{
	u8 Loc_u8Status = RT_SUCCESS;
	if(ptr != NULL)
	{
		Cbf_ptr_COMP =  ptr;
	}
	else
	{
		Loc_u8Status = RT_PARAM;
	}
	return Loc_u8Status;
}
/****************************************************************************************/
ISR(TIMER0_OVF_vect)
{
	if( Cbf_ptr_OVF != NULL)
	{
		/* Calling the function */
		TIMER_vidLoadTimer(248);
		Cbf_ptr_OVF();
	}
	else
	{
		//Do Nothing
	}
}

/****************************************************************************************/
ISR(TIMER0_COMP_vect)
{
	if( Cbf_ptr_COMP != NULL)
	{
		/*  Calling the function */
		Cbf_ptr_COMP();
	}
	else
	{
		//Do Nothing
	}
}
/****************************************************************************************/


