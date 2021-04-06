/*
 * main.c
 *
 *  Created on: Mar 20, 2021
 *      Author: bibom
 */


#include "../../Lib/STD_TYPES.h"
#include "../../Lib/BIT_MATH.h"
#include "../../Lib/Status.h"
#include "../../Lib/BIT_Mask.h"
#include "../../Lib/ATmega32_Registers.h"
#include "../../Service/swTimer.h"
#include "../../Hal/Lcd_Driver/lcd.h"
#include "../../Hal/KeyPad_Driver/keypad.h"
#include "../../Hal/Led_Module/Led_int.h"
#include "../../Hal/TempHal_Driver/TempHal.h"
#include "../../Mcal/Port_Driver/Port_int.h"
#include "../Door_Module/door.h"
#include "../Ignition_Module/ignition.h"
#include "../Speed_Module/speed.h"
#include "../Temp_Module/temp.h"
#include "../SensorManager_Module/Sensor_Manager.h"


static void DashboardManager_vidLcdDisplay(void);
static void DashboardManager_vidDisplaySpeed(void);
static void DashboardManager_vidDisplayTemp(void);
static void DashboardManager_vidDisplayDoor(void);

static void itoa (u8 Copy_u8Value,u8 *Copy_pu8Arr);

static u8 str[10] ;
static u8 str2[10] ;

//void check()
//{
//	u8 data;
//	UART_u8GetData(&data);
//	if(data == 'y')
//	{
//		LED_vidTurnOn(LED_enuID_0);
//	}
//}

int main(void)
{
	_SREG.Bits.Bit7 = 1;
	Port_vidInit();
	SwTimer_init();
	lcd_init();
	keypad_init();
	Temp_hal_u8Init();
//	UART_u8Init();
//	UART_vidSetCallBack(check);
	SensorManager_vidInit();

	while(1)
	{

		DashboardManager_vidLcdDisplay();

	}
	return 0;
}


static void DashboardManager_vidLcdDisplay(void){

	static u8 IgnitionState = IGNITION_u8OFF ;

	Ignition_u8GetIgntion(&IgnitionState);
	if (IgnitionState == IGNITION_u8ON ){
		DashboardManager_vidDisplaySpeed();
		DashboardManager_vidDisplayDoor();
		DashboardManager_vidDisplayTemp();
	}
	else{

		while(lcd_clear()!=RT_PENDING);
	}

}
static void DashboardManager_vidDisplaySpeed(void){

	static u8 Speed = 5 ;
	SPEED_u8GetSpeed(&Speed);
	while(Lcd_GoTo(RowNo_1,ColNo_1)!=RT_PENDING);
	while(lcd_writeString((const u8*)"S ") != RT_PENDING);
	if (Speed <= 180){
		itoa (Speed,(u8*)&str);
		if (Speed < 100 && Speed >= 10 ){
			while(lcd_writeString((const u8*)"0") != RT_PENDING);
		}
		else if (Speed < 10){
			while(lcd_writeString((const u8*)"00") != RT_PENDING);
		}
		while(lcd_writeString((const u8*)&str) != RT_PENDING);
	}
	else {
		while(Lcd_GoTo(RowNo_1,ColNo_3)!=RT_PENDING);
		while(lcd_writeString((const u8*)"   ") != RT_PENDING);
	}
	if (Speed > 150){
		while(lcd_writeString((const u8*)" H") != RT_PENDING);
		LED_vidTurnOn(LED_enuID_1);
	}
	else {
		while(Lcd_GoTo(RowNo_1,ColNo_7)!=RT_PENDING);
		while(lcd_writeString((const u8*)" ") != RT_PENDING);
		LED_vidTurnOff(LED_enuID_1);
	}



}

static void DashboardManager_vidDisplayDoor(void){

	static u8 Door_state[2] ;
	Door_u8GetDoorStatus(DOOR_u8LEFTDOOR , &Door_state[0]);
	Door_u8GetDoorStatus(DOOR_u8RIGHTDOOR , &Door_state[1]);
	while(Lcd_GoTo(RowNo_1,ColNo_16) != RT_PENDING);
	while(lcd_writeString((const u8*)"D") != RT_PENDING);
	if (Door_state[0] == DOOR_u8OPENED || Door_state[1] == DOOR_u8OPENED  ){
		while(Lcd_GoTo(RowNo_2,ColNo_16) != RT_PENDING);
		while(lcd_writeString((const u8*)"O") != RT_PENDING);
		LED_vidTurnOn(LED_enuID_0);
	}
	else {
		while(Lcd_GoTo(RowNo_2,ColNo_16) != RT_PENDING);
		while(lcd_writeString((const u8*)"C") != RT_PENDING);
		LED_vidTurnOff(LED_enuID_0);

	}


}

static void DashboardManager_vidDisplayTemp(void){

	static tempState_t Temp ;

	Temp_GetTemp(&Temp);
	while(Lcd_GoTo(RowNo_2,ColNo_1)!=RT_PENDING);
	while(lcd_writeString((const u8*)"T ") != RT_PENDING);
	if ( Temp.temp_val < 70 && Temp.time_state == time_ok){
		itoa (Temp.temp_val,(u8*)&str2);
		if (Temp.temp_val < 10  ){
			while(lcd_writeString((const u8*)"0") != RT_PENDING);
		}
		while(lcd_writeString((const u8*)&str2) != RT_PENDING);
		while(lcd_writeString((const u8*)"     ") != RT_PENDING);
		LED_vidTurnOff(LED_enuID_2);

	}
	else if(Temp.temp_val >= 70 && Temp.temp_val <= 99 && Temp.time_state == time_ok) {
		itoa (Temp.temp_val,(u8*)&str2);
		if (Temp.temp_val < 10  ){
			while(lcd_writeString((const u8*)"0") != RT_PENDING);
		}
		while(lcd_writeString((const u8*)&str2) != RT_PENDING);
		while(lcd_writeString((const u8*)"  H") != RT_PENDING);
		LED_vidTurnOn(LED_enuID_2);
	}

	else if(Temp.temp_val > 99) {

		while(Lcd_GoTo(RowNo_2,ColNo_3)!=RT_PENDING);
		while(lcd_writeString((const u8*)"    H") != RT_PENDING);
		LED_vidTurnOn(LED_enuID_2);
	}
	else {

		while(Lcd_GoTo(RowNo_2,ColNo_3)!=RT_PENDING);
		while(lcd_writeString((const u8*)"     ") != RT_PENDING);
		LED_vidTurnOn(LED_enuID_2);

	}


}



/* Public Function: itoa												   *
 * Description: This function is used to change the sw PORT port value
 * Input parameters:
 * 					- Copy_u8SwPortId	:	in range { DIO_u8PORT_0 ->  DIO_u8PORT_3 }
 * 					- Copy_u8SwPortVal	:	in range { 0x00         ->  0xFF         }
 * Return:
 * 					- Not applicable (void)
 *
 * Input/Output Parameter:
 * 					- Not Applicable
 *
 **************************************************************************************/
static void itoa (u8 Copy_u8Value,u8 *Copy_pu8Arr){

	u8 Loc_u8NumLoopIdx=0;
	u8 Loc_u8Digit=0;
	u8 Loc_u8ReverseArr[4];
	s8 Loc_u8ReverseCounter = 0 ;
	u8 Loc_u8Counter = 0 ;

	do{
		/*Get the digit to be inserted in the array  */
		Loc_u8Digit = '0' + Copy_u8Value % 10;
		Loc_u8ReverseArr[Loc_u8NumLoopIdx] = Loc_u8Digit;

		/*move to the next digit */
		Copy_u8Value /= 10;
		Loc_u8NumLoopIdx++;

	}while (Copy_u8Value != 0);

	Loc_u8ReverseCounter = Loc_u8NumLoopIdx-1 ;

	for (Loc_u8Counter = 0 ; Loc_u8Counter < Loc_u8NumLoopIdx ; Loc_u8Counter++){

		Copy_pu8Arr[Loc_u8Counter] = Loc_u8ReverseArr[Loc_u8ReverseCounter] ;
		Loc_u8ReverseCounter-- ;
	}

	Copy_pu8Arr[Loc_u8Counter] = '\0';
}
