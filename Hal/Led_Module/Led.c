/*
 * LED.c
 *
 *  Created on: Jan 20, 2021
 *      Author: Esraa Abdelnaby
 */
#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Maths.h"
#include "../Lib/ATmega32_Registers.h"
#include "../DIO_Driver_v2/Dio_int.h"
#include "Led_cfg.h"
#include "Led_int.h"

void LED_vidTurnOn(LED_enuLEDId Copy_enuLEDId)
{

	switch(Copy_enuLEDId)
	{
	case LED_enuID_0:
		Dio_u8SetPinVal(LED_0_enuPin , DIO_u8HIGH);
		break;
	case LED_enuID_1:
		Dio_u8SetPinVal(LED_1_enuPin , DIO_u8HIGH);
		break;
	case LED_enuID_2:
		Dio_u8SetPinVal(LED_2_enuPin , DIO_u8HIGH);
		break;
	case LED_enuID_3:
		Dio_u8SetPinVal(LED_3_enuPin , DIO_u8HIGH);
		break;
	case LED_enuID_4:
		Dio_u8SetPinVal(LED_4_enuPin , DIO_u8HIGH);
		break;
	case LED_enuID_5:
		Dio_u8SetPinVal(LED_5_enuPin , DIO_u8HIGH);
		break;
	case LED_enuID_6:
		Dio_u8SetPinVal(LED_6_enuPin , DIO_u8HIGH);
		break;
	case LED_enuID_7:
		Dio_u8SetPinVal(LED_7_enuPin , DIO_u8HIGH);
		break;
	case LED_enuID_8:
		Dio_u8SetPinVal(LED_8_enuPin , DIO_u8HIGH);
		break;
	case LED_enuID_9:
		Dio_u8SetPinVal(LED_9_enuPin , DIO_u8HIGH);
		break;
	default :
		break;
	}
}

void LED_vidTurnOff(LED_enuLEDId Copy_enuLEDId)
{
	switch(Copy_enuLEDId)
		{
		case LED_enuID_0:
			Dio_u8SetPinVal(LED_0_enuPin , DIO_u8LOW);
			break;
		case LED_enuID_1:
			Dio_u8SetPinVal(LED_1_enuPin , DIO_u8LOW);
			break;
		case LED_enuID_2:
			Dio_u8SetPinVal(LED_2_enuPin , DIO_u8LOW);
			break;
		case LED_enuID_3:
			Dio_u8SetPinVal(LED_3_enuPin , DIO_u8LOW);
			break;
		case LED_enuID_4:
			Dio_u8SetPinVal(LED_4_enuPin , DIO_u8LOW);
			break;
		case LED_enuID_5:
			Dio_u8SetPinVal(LED_5_enuPin , DIO_u8LOW);
			break;
		case LED_enuID_6:
			Dio_u8SetPinVal(LED_6_enuPin , DIO_u8LOW);
			break;
		case LED_enuID_7:
			Dio_u8SetPinVal(LED_7_enuPin , DIO_u8LOW);
			break;
		case LED_enuID_8:
			Dio_u8SetPinVal(LED_8_enuPin , DIO_u8LOW);
			break;
		case LED_enuID_9:
			Dio_u8SetPinVal(LED_9_enuPin , DIO_u8LOW);
			break;
		default :
			break;
		}
}


void LED_vidToggle(LED_enuLEDId Copy_enuLEDId)
{
	switch(Copy_enuLEDId)
		{
		case LED_enuID_0:
			Dio_u8TglPinVal(LED_0_enuPin);
			break;
		case LED_enuID_1:
			Dio_u8TglPinVal(LED_1_enuPin);
			break;
		case LED_enuID_2:
			Dio_u8TglPinVal(LED_2_enuPin);
			break;
		case LED_enuID_3:
			Dio_u8TglPinVal(LED_3_enuPin);
			break;
		case LED_enuID_4:
			Dio_u8TglPinVal(LED_4_enuPin);
			break;
		case LED_enuID_5:
			Dio_u8TglPinVal(LED_5_enuPin);
			break;
		case LED_enuID_6:
			Dio_u8TglPinVal(LED_6_enuPin);
			break;
		case LED_enuID_7:
			Dio_u8TglPinVal(LED_7_enuPin);
			break;
		case LED_enuID_8:
			Dio_u8TglPinVal(LED_8_enuPin);
			break;
		case LED_enuID_9:
			Dio_u8TglPinVal(LED_9_enuPin);
			break;
		default :
			break;
		}
}
