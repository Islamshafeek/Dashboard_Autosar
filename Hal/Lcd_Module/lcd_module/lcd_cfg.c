/*
 * lcd_cfg.c
 *
 *  Created on: Mar 20, 2021
 *      Author: bibom
 */


#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"

//replace this with right dio include
#include "dio.h"
//-----------------------------------

#include "lcd_cfg.h"

/*Lcd pins configuration, please configure each element with the correct dio pin no.*/
const u8 lcdCfg[PIN_NUM] = {
		[RS] = DIO_u8PIN_0,
		[EN] = DIO_u8PIN_1,
		[D7] = DIO_u8PIN_2,
		[D6] = DIO_u8PIN_3,
		[D5] = DIO_u8PIN_4,
		[D4] = DIO_u8PIN_5,
		[D3] = DIO_u8PIN_6,
		[D2] = DIO_u8PIN_7,
		[D1] = DIO_u8PIN_8,
		[D0] = DIO_u8PIN_9
};
