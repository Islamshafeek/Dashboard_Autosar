/*
 * keypad_cfg.c
 *
 *  Created on: Mar 21, 2021
 *      Author: bibom
 */
#include "../../Lib/Std_Types.h"
#include "../../Lib/Bit_Math.h"
#include "../../Lib/ATmega32_Registers.h"
#include "../../Lib/Status.h"
#include "../../Mcal/Dio_Driver/Dio_int.h"
#include "keypad_cfg.h"

const u8 keypadkeysCfg[4][4] = {
		[ROW_1] = {
				[COL_1] = SPEED_PLUS_ONE,
				[COL_2] = SPEED_MINUS_ONE,
				[COL_3] = IGNITION_ON,
				[COL_4] = 'A'
		},
		[ROW_2] = {
				[COL_1] = SPEED_PLUS_TEN,
				[COL_2] = SPEED_MINUS_TEN,
				[COL_3] = IGNITION_OFF,
				[COL_4] = 'B'
		},
		[ROW_3] = {
				[COL_1] = RIGHT_DOOR_OPEN,
				[COL_2] = LEFT_DOOR_OPEN,
				[COL_3] = SPEED_BREAK,
				[COL_4] = 'C'
		},
		[ROW_4] = {
				[COL_1] = '*',
				[COL_2] = '0',
				[COL_3] = '#',
				[COL_4] = 'D'
		}
};

const u8 keypadCfg[8] = {
		DIO_u8PIN_8,
		DIO_u8PIN_9,
		DIO_u8PIN_10,
		DIO_u8PIN_11,
		DIO_u8PIN_12,
		DIO_u8PIN_13,
		DIO_u8PIN_14,
		DIO_u8PIN_15
};
