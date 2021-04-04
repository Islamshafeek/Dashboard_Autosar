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
#include "../../Service/swTimer.h"
#include "../../Hal/Lcd_Driver/lcd.h"
#include "../../Hal/KeyPad_Driver/keypad.h"
#include "../../Mcal/Port_Driver/Port_int.h"
#include "../../Lib/ATmega32_Registers.h"
#include "../Door_Module/door.h"
#include "../Ignition_Module/ignition.h"



int main(void)
{
	u8 key;
	Port_vidInit();
	SwTimer_init();
	_SREG.Bits.Bit7 = 1;
	lcd_init();
	keypad_init();

	while(1)
	{
		keypad_getKey(&key);
		if(key=='1')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString((const u8*)"1") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '1');
		}
		else if(key=='2')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString((const u8*)"2") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '2');
		}
		else if(key=='3')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString((const u8*)"3") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '3');
		}
		else if(key=='4')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString((const u8*)"4") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '4');
		}
		else if(key=='5')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString((const u8*)"5") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '5');
		}
		else if(key=='6')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString((const u8*)"6") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '6');
		}
		else if(key=='7')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString((const u8*)"7") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '7');
		}
		else if(key=='8')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString((const u8*)"8") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '8');
		}
		else if(key=='9')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString((const u8*)"9") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '9');
		}
		else if(key == LCD_NO_KEY)
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString((const u8*)"no key") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == LCD_NO_KEY);
		}
	}
	return 0;
}
