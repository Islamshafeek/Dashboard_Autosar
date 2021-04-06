/*
 * Sensor_Manager.c
 *
 *  Created on: Apr 4, 2021
 *      Author: Islam
 */

#include "../../Lib/Std_Types.h"
#include "../../Lib/Bit_Math.h"
#include "../../Lib/ATmega32_Registers.h"
#include "../../Lib/Status.h"
#include "../../Mcal/Dio_Driver/Dio_int.h"
#include "../../Service/swTimer.h"
#include "../../Hal/KeyPad_Driver/keypad.h"
#include "../../Hal/KeyPad_Driver/keypad_cfg.h"
#include "../../Hal/TempHal_Driver/Temp_hal.h"
#include "../Door_Module/door.h"
#include "../Ignition_Module/ignition.h"
#include "../Speed_Module/speed.h"
#include "Sensor_Manager.h"


static void SensorManager_vidGetSensorRead(void);
static void SensorManager_vidGetTempRead(void);



static u8 KeyPad_Read ;
static u8 Temp_Read ;

void SensorManager_vidInit(void){

	SwTimer_register_cbf(60,SwTimerMode_periodic,SensorManager_vidGetSensorRead);

	SwTimer_register_cbf(500,SwTimerMode_periodic,SensorManager_vidGetTempRead);

}




static void SensorManager_vidGetSensorRead(void){

	static u8 count ;
	keypad_getKey(&KeyPad_Read);

	switch (KeyPad_Read){
	case SPEED_PLUS_ONE:
		SPEED_u8SetSpeed(SPEED_u8INC_BY_ONE);

		break;
	case SPEED_MINUS_ONE:

		SPEED_u8SetSpeed(SPEED_u8DEC_BY_ONE);
		break;
	case IGNITION_ON:
		count++ ;
		if (count == 200){
			count = 0 ;
			Ignition_u8SetIgntion(IGNITION_u8ON);
		}
		//what happend if continously pressed!!

		break;
	case SPEED_PLUS_TEN:
		SPEED_u8SetSpeed(SPEED_u8INC_BY_TEN);
		break;
	case SPEED_MINUS_TEN:
		SPEED_u8SetSpeed(SPEED_u8DEC_BY_TEN);
		break;
	case IGNITION_OFF:
			Ignition_u8SetIgntion(IGNITION_u8OFF);
			count++ ;
			if (count == 200){
				count = 0 ;
				Ignition_u8SetIgntion(IGNITION_u8OFF);
			}
			//what happend if continously pressed!!
		break;
	case RIGHT_DOOR_OPEN:
		Door_u8SetDoorStatus(DOOR_u8OPENED ,DOOR_u8RIGHTDOOR) ;
		break;
	case LEFT_DOOR_OPEN:
		Door_u8SetDoorStatus(DOOR_u8OPENED ,DOOR_u8LEFTDOOR) ;
		break;
	case SPEED_BREAK:
		SPEED_u8SetSpeed(SPEED_u8BREAK);
		break;
	default:
		SPEED_u8SetSpeed(LCD_NO_KEY);
		Door_u8SetDoorStatus(DOOR_u8CLOSED ,DOOR_u8RIGHTDOOR) ;
		Door_u8SetDoorStatus(DOOR_u8CLOSED ,DOOR_u8LEFTDOOR) ;
		break;
	}


}

static void SensorManager_vidGetTempRead(void){

	static u8 Timeout_counter  ;

	Temp_hal_u8GetEngineTemp(&Temp_Read);
	if (Temp_Read == 0 ){
		Timeout_counter++ ;
	}

	if(Timeout_counter == TEMP_u8TIMEOUT_MS/TEMP_u8PERIODECTY_MS){



	}


}
