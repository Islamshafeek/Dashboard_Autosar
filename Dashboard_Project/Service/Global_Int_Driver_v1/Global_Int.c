/*
 * Global_Int.c
 *
 *  Created on: Mar 5, 2021
 *      Author: micro
 */

#include "../../Lib/Std_Types.h"
#include "../../Lib/Bit_Math.h"
#include "../../Lib/Status.h"
#include "../../Lib/ATmega32_Registers.h"

void Global_Int_vidEnable(void){

	_SREG.Bits.Bit7 = STD_u8TRUE;

}


void Global_Int_vidDisable(void){

	_SREG.Bits.Bit7 = STD_u8FALSE;

}
