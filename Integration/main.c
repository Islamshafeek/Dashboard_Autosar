/*
 * main.c
 *
 *  Created on: Mar 20, 2021
 *      Author: bibom
 */


#include "Std_Types.h"
#include "Bit_Math.h"
#include "Bit_Mask.h"
#include "status.h"
#include "Dio_int.h"
#include "swTimer.h"
#include "lcd.h"
#include "keypad.h"
#include "Port_int.h"
#include "ATmega32_Registers.h"
#define F_CPU 8000000
#include <util/delay.h>

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
			while(lcd_writeString("1") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '1');
		}
		else if(key=='2')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString("2") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '2');
		}
		else if(key=='3')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString("3") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '3');
		}
		else if(key=='4')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString("4") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '4');
		}
		else if(key=='5')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString("5") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '5');
		}
		else if(key=='6')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString("6") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '6');
		}
		else if(key=='7')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString("7") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '7');
		}
		else if(key=='8')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString("8") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '8');
		}
		else if(key=='9')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString("9") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '9');
		}
		else if(key=='*')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString("*") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '*');
		}
		else if(key=='0')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString("0") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '0');
		}
		else if(key=='#')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString("#") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == '#');
		}
		else if(key=='A')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString("A") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == 'A');
		}
		else if(key=='B')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString("B") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == 'B');
		}
		else if(key=='C')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString("C") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == 'C');
		}
		else if(key=='D')
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString("D") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == 'D');
		}
		else if(key == LCD_NO_KEY)
		{
			while(lcd_clear()!=RT_PENDING);
			while(lcd_writeString("no key") != RT_PENDING);
			do{
				keypad_getKey(&key);
			}while(key == LCD_NO_KEY);
		}
	}
	return 0;
}
