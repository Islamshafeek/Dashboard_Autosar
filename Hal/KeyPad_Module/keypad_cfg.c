/*
 * keypad_cfg.c
 *
 *  Created on: Mar 21, 2021
 *      Author: bibom
 */
#include "Std_Types.h"
#include "Bit_Mask.h"
#include "status.h"
#include "swTimer.h"
#include "keypad_cfg.h"
#include "Dio_int.h"

const u8 keypadkeysCfg[4][4] = {
		[ROW_1] = {
				[COL_1] = '1',
				[COL_2] = '2',
				[COL_3] = '3',
				[COL_4] = 'A'
		},
		[ROW_2] = {
				[COL_1] = '4',
				[COL_2] = '5',
				[COL_3] = '6',
				[COL_4] = 'B'
		},
		[ROW_3] = {
				[COL_1] = '7',
				[COL_2] = '8',
				[COL_3] = '9',
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
