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
#include "../../Service/SwTimer/swTimer.h"
#include "../../Hal/KeyPad_Driver/keypad.h"
#include "../../Hal/KeyPad_Driver/keypad_cfg.h"
#include "../../Hal/TempHal_Driver/TempHal.h"
#include "../Door_Module/door.h"
#include "../Ignition_Module/ignition.h"
#include "../Speed_Module/speed.h"
#include "../Temp_Module/temp.h"
#include "Sensor_Manager.h"



static void SensorManager_vidGetSensorRead(void);
static void SensorManager_vidGetTempRead(void);



static u8 KeyPad_Read ;
static tempState_t Temp_Read ;

void SensorManager_vidInit(void)
{
	SwTimer_register_cbf(60,SwTimerMode_periodic,SensorManager_vidGetSensorRead);
	SwTimer_register_cbf(500,SwTimerMode_periodic,SensorManager_vidGetTempRead);
}




static void SensorManager_vidGetSensorRead(void){

	static u8 count ;
	static u8 count1 ;
	static u8 firstKey_firstPressed = 1;
	static u8 secondKey_firstPressed = 1;
	static u8 thirdKey_firstPressed = 1;
	static u8 forthKey_firstPressed = 1;
	static u8 fifthKey_firstPressed = 1;
	keypad_getKey(&KeyPad_Read);
	switch (KeyPad_Read){
	case SPEED_PLUS_ONE:
		if(firstKey_firstPressed == 1)
		{
			SPEED_u8SetSpeed(SPEED_u8INC_BY_ONE);
			firstKey_firstPressed = 0;
		}
		break;
	case SPEED_MINUS_ONE:
		if(secondKey_firstPressed == 1)
		{
			SPEED_u8SetSpeed(SPEED_u8DEC_BY_ONE);
			secondKey_firstPressed = 0;
		}
		break;
	case IGNITION_ON:
		count1++ ;
		if (count1 == 166){
			count1 = 0 ;
			Ignition_u8SetIgntion(IGNITION_u8ON);
		}
		//what happend if continously pressed!!

		break;
	case SPEED_PLUS_TEN:
		if(thirdKey_firstPressed == 1)
		{
			SPEED_u8SetSpeed(SPEED_u8INC_BY_TEN);
			thirdKey_firstPressed = 0;
		}
		break;
	case SPEED_MINUS_TEN:
		if(forthKey_firstPressed == 1)
		{
			SPEED_u8SetSpeed(SPEED_u8DEC_BY_TEN);
			forthKey_firstPressed = 0;
		}
		break;
	case IGNITION_OFF:
		count++ ;
		if (count == 166){
			count = 0 ;
			Ignition_u8SetIgntion(IGNITION_u8OFF);
		}
		//what happend if continously pressed!!
		break;
	case RIGHT_DOOR_OPEN:
		Door_u8SetDoorStatus(DOOR_u8RIGHTDOOR,DOOR_u8OPENED ) ;
		break;
	case LEFT_DOOR_OPEN:
		Door_u8SetDoorStatus(DOOR_u8LEFTDOOR,DOOR_u8OPENED ) ;
		break;
	case SPEED_BREAK:
		if(fifthKey_firstPressed == 1)
		{
			SPEED_u8SetSpeed(SPEED_u8BREAK);
			fifthKey_firstPressed = 0;
		}
		break;
	default:
		SPEED_u8SetSpeed(LCD_NO_KEY);
		Door_u8SetDoorStatus(DOOR_u8RIGHTDOOR,DOOR_u8CLOSED) ;
		Door_u8SetDoorStatus(DOOR_u8LEFTDOOR,DOOR_u8CLOSED ) ;
		firstKey_firstPressed = 1;
		secondKey_firstPressed = 1;
		thirdKey_firstPressed = 1;
		forthKey_firstPressed = 1;
		fifthKey_firstPressed = 1;
		break;
	}


}

static void SensorManager_vidGetTempRead(void){

	static u8 Timeout_counter  ;

	Temp_hal_u8GetEngineTemp(&Temp_Read.temp_val);

	if (Temp_Read.temp_val == 0 ){
		Timeout_counter++ ;
		if(Timeout_counter == TEMP_u8TIMEOUT_MS/TEMP_u8PERIODECTY_MS){

			Timeout_counter = 0 ;
			Temp_Read.time_state = time_out ;
			Temp_SetTemp(&Temp_Read);
		}
	}
	else {

		Timeout_counter = 0 ;
		Temp_Read.time_state = time_ok ;
		Temp_SetTemp(&Temp_Read);
	}




}
