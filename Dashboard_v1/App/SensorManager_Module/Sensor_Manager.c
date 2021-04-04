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
#include "Sensor_Manager.h"


static void SensorManager_vidGetSensorRead(void);
static void SensorManager_vidGetTempRead(void);



static u8 KeyPad_Read ;
static u8 Temp_Read ;

void SensorManager_vidInit(void){

	SwTimer_register_cbf(50,SwTimerMode_periodic,SensorManager_vidGetSensorRead);

	SwTimer_register_cbf(500,SwTimerMode_periodic,SensorManager_vidGetTempRead);

}




static void SensorManager_vidGetSensorRead(void){

	keypad_getKey(&KeyPad_Read);

	switch (KeyPad_Read){
	case SPEED_PLUS_ONE:


		break;
	case SPEED_MINUS_ONE:


		break;
	case IGNITION_ON:

		break;
	case SPEED_PLUS_TEN:

		break;
	case SPEED_MINUS_TEN:

		break;
	case IGNITION_OFF:

		break;
	case RIGHT_DOOR_OPEN:

		break;
	case LEFT_DOOR_OPEN:

		break;
	case SPEED_BREAK:

		break;
	}


}

static void SensorManager_vidGetTempRead(void){

	Temp_hal_u8GetEngineTemp(&Temp_Read);

}
