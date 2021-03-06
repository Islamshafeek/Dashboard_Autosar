/*
 * keypad.c
 *
 *  Created on: Mar 21, 2021
 *      Author: bibom
 */

#include "../../Lib/Std_Types.h"
#include "../../Lib/Bit_Math.h"
#include "../../Lib/ATmega32_Registers.h"
#include "../../Lib/Status.h"
#include "../../Mcal/Dio_Driver/Dio_int.h"
#include "../../Service/SwTimer/swTimer.h"
#include "keypad.h"
#include "keypad_cfg.h"
#include "../Lcd_Driver/Lcd.h"

static u8 isReady = 0;
static u8 pressedKey = LCD_NO_KEY;


typedef enum{
	keyState_pressed,
	keyState_notPressed,
	_keyState_len_
}keyState_t;

typedef struct{
	keyState_t cur;
	keyState_t prev;
	u8 count;
}debounce_t;

static debounce_t keysDebounceCount[4][4];
static void keypad_handler(void);
static u8 NO_KEY_count = 0;


status_RT keypad_init(void)
{
	status_RT status = RT_SUCCESS;

	for(u8 i=0;i<4;i++)
	{
		Dio_vidSetPinVal(keypadCfg[i],DIO_u8HIGH);
		keysDebounceCount[i][0].prev = keyState_notPressed;
		keysDebounceCount[i][1].prev = keyState_notPressed;
		keysDebounceCount[i][2].prev = keyState_notPressed;
		keysDebounceCount[i][3].prev = keyState_notPressed;
	}
	if(status == RT_SUCCESS)
	{
		status = SwTimer_register_cbf(10,SwTimerMode_periodic,keypad_handler);
		if(status == RT_SUCCESS)
		{
			isReady = 1;
		}
	}
	return status;
}


static void keypad_handler(void)
{
	if(isReady)
	{
		u8 colsVal = 0;
		u8 ind;
		for(ind=0;ind<4;ind++)
		{
			colsVal = 0;
			Dio_vidSetPinVal(keypadCfg[0],DIO_u8HIGH);
			Dio_vidSetPinVal(keypadCfg[1],DIO_u8HIGH);
			Dio_vidSetPinVal(keypadCfg[2],DIO_u8HIGH);
			Dio_vidSetPinVal(keypadCfg[3],DIO_u8HIGH);

			Dio_vidSetPinVal(keypadCfg[(ind+0)%4],DIO_u8LOW);
			Dio_vidSetPinVal(keypadCfg[(ind+1)%4],DIO_u8HIGH);
			Dio_vidSetPinVal(keypadCfg[(ind+2)%4],DIO_u8HIGH);
			Dio_vidSetPinVal(keypadCfg[(ind+3)%4],DIO_u8HIGH);

			colsVal |= Dio_u8GetPinVal(keypadCfg[COL_1 + 4]) << 0;
			colsVal |= Dio_u8GetPinVal(keypadCfg[COL_2 + 4]) << 1;
			colsVal |= Dio_u8GetPinVal(keypadCfg[COL_3 + 4]) << 2;
			colsVal |= Dio_u8GetPinVal(keypadCfg[COL_4 + 4]) << 3;

			if(colsVal != 0x0F)
			{
				switch(colsVal)
				{
				case 0x0E:
					keysDebounceCount[ind][0].cur = keyState_pressed;
					if(keysDebounceCount[ind][0].cur == keysDebounceCount[ind][0].prev)
					{
						keysDebounceCount[ind][0].count++;
						if(keysDebounceCount[ind][0].count == 5)
						{
							pressedKey = keypadkeysCfg[ind][0];
							keysDebounceCount[ind][0].count = 0;
						}
					}
					else
					{
						keysDebounceCount[ind][0].count = 0;
					}
					keysDebounceCount[ind][0].prev = keysDebounceCount[ind][0].cur;
					keysDebounceCount[ind][1].cur = keyState_notPressed;
					keysDebounceCount[ind][2].cur = keyState_notPressed;
					keysDebounceCount[ind][3].cur = keyState_notPressed;
					break;
				case 0x0D:
					keysDebounceCount[ind][1].cur = keyState_pressed;
					if(keysDebounceCount[ind][1].cur == keysDebounceCount[ind][1].prev)
					{
						keysDebounceCount[ind][1].count++;
						if(keysDebounceCount[ind][1].count == 5)
						{
							pressedKey = keypadkeysCfg[ind][1];
							keysDebounceCount[ind][1].count = 0;
						}
					}
					else
					{
						keysDebounceCount[ind][1].count = 0;
					}
					keysDebounceCount[ind][1].prev = keysDebounceCount[ind][1].cur;
					keysDebounceCount[ind][0].cur = keyState_notPressed;
					keysDebounceCount[ind][2].cur = keyState_notPressed;
					keysDebounceCount[ind][3].cur = keyState_notPressed;
					break;
				case 0x0B:
					keysDebounceCount[ind][2].cur = keyState_pressed;
					if(keysDebounceCount[ind][2].cur == keysDebounceCount[ind][2].prev)
					{
						keysDebounceCount[ind][2].count++;
						if(keysDebounceCount[ind][2].count == 5)
						{
							pressedKey = keypadkeysCfg[ind][2];
							keysDebounceCount[ind][2].count = 0;
						}
					}
					else
					{
						keysDebounceCount[ind][2].count = 0;
					}
					keysDebounceCount[ind][2].prev = keysDebounceCount[ind][2].cur;
					keysDebounceCount[ind][1].cur = keyState_notPressed;
					keysDebounceCount[ind][0].cur = keyState_notPressed;
					keysDebounceCount[ind][3].cur = keyState_notPressed;
					break;
				case 0x07:
					keysDebounceCount[ind][3].cur = keyState_pressed;
					if(keysDebounceCount[ind][3].cur == keysDebounceCount[ind][3].prev)
					{
						keysDebounceCount[ind][3].count++;
						if(keysDebounceCount[ind][3].count == 5)
						{
							pressedKey = keypadkeysCfg[ind][3];
							keysDebounceCount[ind][3].count = 0;
						}
					}
					else
					{
						keysDebounceCount[ind][3].count = 0;
					}
					keysDebounceCount[ind][3].prev = keysDebounceCount[ind][3].cur;
					keysDebounceCount[ind][1].cur = keyState_notPressed;
					keysDebounceCount[ind][2].cur = keyState_notPressed;
					keysDebounceCount[ind][0].cur = keyState_notPressed;
					break;
				}
				break;
			}
		}
		if(ind == 4)
		{
			NO_KEY_count++;
			if(NO_KEY_count == 5)
			{
				NO_KEY_count = 0;
				pressedKey = LCD_NO_KEY;
			}
		}
		Dio_vidSetPinVal(keypadCfg[0],DIO_u8HIGH);
					Dio_vidSetPinVal(keypadCfg[1],DIO_u8HIGH);
					Dio_vidSetPinVal(keypadCfg[2],DIO_u8HIGH);
					Dio_vidSetPinVal(keypadCfg[3],DIO_u8HIGH);
	}
}


status_RT	keypad_getKey(u8* Key)
{
	status_RT status = RT_SUCCESS;
	if(isReady)
	{
		*Key = pressedKey;
	}
	else
	{
		status = RT_ERROR;
	}
	return status;
}
