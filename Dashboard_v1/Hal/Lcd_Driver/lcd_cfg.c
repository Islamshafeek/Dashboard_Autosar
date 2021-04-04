/*
 * lcd_cfg.c
 *
 *  Created on: Mar 20, 2021
 *      Author: bibom
 */


#include "../../Lib/Std_Types.h"
#include "../../Lib/Bit_Math.h"
#include "../../Lib/Status.h"

//replace this with right dio include
#include "../../Mcal/Dio_Driver/Dio_int.h"
//-----------------------------------

#include "lcd_cfg.h"

/*Lcd pins configuration, please configure each element with the correct dio pin no.*/
const u8 lcdCfg[PIN_NUM] = {
		[RS] = DIO_u8PIN_16,
		[EN] = DIO_u8PIN_17,
		[D7] = DIO_u8PIN_31,
		[D6] = DIO_u8PIN_30,
		[D5] = DIO_u8PIN_29,
		[D4] = DIO_u8PIN_28,
		[D3] = DIO_u8PIN_27,
		[D2] = DIO_u8PIN_26,
		[D1] = DIO_u8PIN_25,
		[D0] = DIO_u8PIN_24
};
