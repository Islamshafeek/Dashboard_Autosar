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


#include "Std_Types.h"
#include "lib/RT_Debug.h"
#include "lib/stm32f407_Registers.h"
#include "Port.h"
#include "Port_Lcfg.h"


const Port_ConfigType Port_Config[PORT_NUMBER] = {

[PORTA] = {
		.Pin[0] = {.PinMode = PORT_PIN_MODE_DIO ,
				   .PinDirection = PORT_PIN_OUT , //PORT_PIN_OUT
				   .PinLevelInitValue = PORT_PIN_LEVEL_HIGH
					},

		.Pin[1] = {.PinMode = PORT_PIN_MODE_DIO ,
				   .PinDirection = PORT_PIN_OUT ,
				   .PinLevelInitValue = PORT_PIN_LEVEL_LOW
					},

		.Pin[2] = {.PinMode = PORT_PIN_MODE_DIO ,
				   .PinDirection = PORT_PIN_OUT ,
				   .PinLevelInitValue = PORT_PIN_LEVEL_HIGH
					},
		.Pin[3] = {.PinMode = PORT_PIN_MODE_DIO ,
				   .PinDirection = PORT_PIN_OUT ,
				   .PinLevelInitValue = PORT_PIN_LEVEL_LOW
					},
},



};
