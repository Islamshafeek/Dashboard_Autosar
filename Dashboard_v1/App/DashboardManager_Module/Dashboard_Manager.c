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
#include "../../Mcal/Port_Driver/Port_int.h"
#include "../Door_Module/door.h"
#include "../Ignition_Module/ignition.h"
#include "../Speed_Module/speed.h"
#include "../SensorManager_Module/Sensor_Manager.h"


static void DashboardManager_vidLcdDisplay(void);
static void DashboardManager_vidDisplaySpeed(void);
static void DashboardManager_vidDisplayTemp(void);
static void DashboardManager_vidDisplayDoor(void);
//static void DashboardManager_vidDisplayIgnition(void);
static void itoa (u8 Copy_u8Value,u8 *Copy_pu8Arr);

static u8 str[10] ;

int main(void)
{
	u8 key;
	_SREG.Bits.Bit7 = 1;
	Port_vidInit();
	SwTimer_init();
	lcd_init();
	keypad_init();
	Temp_hal_u8Init();
	SensorManager_vidInit();

	while(1)
	{

		DashboardManager_vidLcdDisplay();

		//		keypad_getKey(&key);
		//		if(key=='1')
		//		{
		//			while(lcd_clear()!=RT_PENDING);
		//			while(lcd_writeString((const u8*)"1") != RT_PENDING);
		//			do{
		//				keypad_getKey(&key);
		//			}while(key == '1');
		//		}
		//		else if(key=='2')
		//		{
		//			while(lcd_clear()!=RT_PENDING);
		//			while(lcd_writeString((const u8*)"2") != RT_PENDING);
		//			do{
		//				keypad_getKey(&key);
		//			}while(key == '2');
		//		}
		//		else if(key=='3')
		//		{
		//			while(lcd_clear()!=RT_PENDING);
		//			while(lcd_writeString((const u8*)"3") != RT_PENDING);
		//			do{
		//				keypad_getKey(&key);
		//			}while(key == '3');
		//		}
		//		else if(key=='4')
		//		{
		//			while(lcd_clear()!=RT_PENDING);
		//			while(lcd_writeString((const u8*)"4") != RT_PENDING);
		//			do{
		//				keypad_getKey(&key);
		//			}while(key == '4');
		//		}
		//		else if(key=='5')
		//		{
		//			while(lcd_clear()!=RT_PENDING);
		//			while(lcd_writeString((const u8*)"5") != RT_PENDING);
		//			do{
		//				keypad_getKey(&key);
		//			}while(key == '5');
		//		}
		//		else if(key=='6')
		//		{
		//			while(lcd_clear()!=RT_PENDING);
		//			while(lcd_writeString((const u8*)"6") != RT_PENDING);
		//			do{
		//				keypad_getKey(&key);
		//			}while(key == '6');
		//		}
		//		else if(key=='7')
		//		{
		//			while(lcd_clear()!=RT_PENDING);
		//			while(lcd_writeString((const u8*)"7") != RT_PENDING);
		//			do{
		//				keypad_getKey(&key);
		//			}while(key == '7');
		//		}
		//		else if(key=='8')
		//		{
		//			while(lcd_clear()!=RT_PENDING);
		//			while(lcd_writeString((const u8*)"8") != RT_PENDING);
		//			do{
		//				keypad_getKey(&key);
		//			}while(key == '8');
		//		}
		//		else if(key=='9')
		//		{
		//			while(lcd_clear()!=RT_PENDING);
		//			while(lcd_writeString((const u8*)"9") != RT_PENDING);
		//			do{
		//				keypad_getKey(&key);
		//			}while(key == '9');
		//		}
		//		else if(key == LCD_NO_KEY)
		//		{
		//			while(lcd_clear()!=RT_PENDING);
		//			while(lcd_writeString((const u8*)"no key") != RT_PENDING);
		//			do{
		//				keypad_getKey(&key);
		//			}while(key == LCD_NO_KEY);
		//		}
	}
	return 0;
}


static void DashboardManager_vidLcdDisplay(void){

	static u8 IgnitionState = 0 ;

	Ignition_u8GetIgntion(&IgnitionState);
	if (IgnitionState == IGNITION_u8ON ){
		DashboardManager_vidDisplaySpeed();
		DashboardManager_vidDisplayDoor();
		DashboardManager_vidDisplayTemp();
	}
	else{

		lcd_clear();
	}

}
static void DashboardManager_vidDisplaySpeed(void){

	static u8 Speed = 5 ;
	SPEED_u8GetSpeed(&Speed);
	while(lcd_clear()!=RT_PENDING);
	while(lcd_writeString((const u8*)"S ") != RT_PENDING);
	itoa (Speed,&str);
	if (Speed < 100){
		while(lcd_writeString((const u8*)"0") != RT_PENDING);
	}
	else if (Speed < 10){
		while(lcd_writeString((const u8*)"00") != RT_PENDING);
	}
	while(lcd_writeString((const u8*)&str) != RT_PENDING);

	if (Speed > 150){
		while(lcd_writeString((const u8*)"H") != RT_PENDING);
	}



}

static void DashboardManager_vidDisplayDoor(void){

	static u8 Door_state[2] = 0 ;
	Door_u8GetDoorStatus(DOOR_u8LEFTDOOR , &Door_state[0]);
	Door_u8GetDoorStatus(DOOR_u8RIGHTDOOR , &Door_state[1]);
	while(lcd_writeString((const u8*)" D        ") != RT_PENDING);
	if (Door_state[0] == DOOR_u8OPENED || Door_state[1] == DOOR_u8OPENED  ){
	while(lcd_writeString((const u8*)"O        ") != RT_PENDING);
	}
	else {
		while(lcd_writeString((const u8*)"C        ") != RT_PENDING);
	}


}

static void DashboardManager_vidDisplayTemp(void){


}
//static void DashboardManager_vidDisplayIgnition(void){
//
//
//
//}

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
