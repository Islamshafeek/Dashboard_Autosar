/*
 * Port_Lcfg.c
 *
 *  Created on: Apr 22, 2021
 *      Author: Islam
 */

#include <stdint.h>
#include <stddef.h>
#include "diag/Trace.h"
#include "lib/Bits.h"
#include "lib/Bit_Math.h"
#include "lib/RT_Debug.h"
#include "lib/stm32f407_Registers.h"
#include "Port.h"
#include "Port_Lcfg.h"


const Port_ConfigType Port_Config[PORT_NUMBER] = {

[PORTA] = {
		.Pin[0] = {.PinMode = 1 ,
				   .PinDirectio = 1 ,
				   .PinLevelInitValue = 0
					},

		.Pin[1] = {.PinMode = 1 ,
				   .PinDirectio = 1 ,
				   .PinLevelInitValue = 0
					},

		.Pin[2] = {.PinMode = 1 ,
				   .PinDirectio = 1 ,
				   .PinLevelInitValue = 0
					},
		.Pin[3] = {.PinMode = 1 ,
				   .PinDirectio = 1 ,
				   .PinLevelInitValue = 0
					},
},



};
