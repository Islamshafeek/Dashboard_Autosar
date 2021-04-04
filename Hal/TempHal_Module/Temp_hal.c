/*
 * Temp_hal.c
 *
 *  Created on: Mar 21, 2021
 *      Author: Mohsen
 */

/* Important Notes :>>
 *          1) 
 *          2)
 *
 */ 
#include "stdint.h"
#include "stderror.h"
#include "../Lib/Bit_Math.h"
#include "UART_int.h"


/* This variable will hold the value of Engine temperature.
 * This variable will be set by another module “UART” and will
 * be read by Sensor_manager module using a getter function.*/
static uint8_t Temp_hal_su8EngineTemp;



/* This function is responsible for initializing down modules
 * used to get the engine temperature, which is the UART module
 * in our case.*/
uint8_t Temp_hal_u8Init (void){
	UART_vidInit();
	return E_OK;
}



/* This function is used to set the static global variable “Temp_hal_su8EngineTemp”.
 * It calls the UART API used to receive data from UART Rx.
 * “Temp_hal_su8EngineTemp” would be updated periodically by the value received from UART Rx buffer.
 * This function address is passed to the UART module using the function “UART_u8SetCallBack”;
 * that is in order to be executed whenever a UART Rx interrupt is fired.
 * */
uint8_t Temp_hal_u8SetEngineTemp(void){
	UART_u8ReceiveData(&Temp_hal_su8EngineTemp);
	return E_OK;
}



/* This function is used as a getter. It is used by Sensor_manager
 * to get the engine temperature*/
uint8_t Temp_hal_u8GetEngineTemp (uint8_t * pu8_EngineTemp){
	*pu8_EngineTemp = Temp_hal_su8EngineTemp;
	return E_OK;
}



