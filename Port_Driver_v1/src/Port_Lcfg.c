/*
 * Port_Lcfg.c
 *
 *  Created on: Apr 22, 2021
 *      Author: Islam
 */

#include <stdint.h>
#include <stddef.h>
#include "diag/Trace.h"
#include "Bits.h"
#include "Bit_Math.h"
#include "Std_Types.h"
#include "RT_Debug.h"
#include "stm32f407_Registers.h"
#include "Port.h"
#include "Port_Lcfg.h"
#include "Port_cfg.h"




//s	Pin_ConfigType Pin[16*6] ;



const Port_ConfigType Port_Config[PORT_PIN_NUMBER] = {

	[PORT_A_PIN_0] =
				{.PinMode = PORT_PIN_MODE_DIO ,
						.PinDirection = PORT_PIN_OUT , //PORT_PIN_OUT
						.PinLevelInitValue = PORT_PIN_LEVEL_HIGH ,
						.PinInternalPullUp = PORT_PIN_INTERNAL_PULL_UP,
						.PinSpeed  = PORT_PIN_SPEED_V_HIGH,		//Speed_Register
						.PinOType  = PORT_PIN_OUTPUT_PUSH_PULL ,
						.PinDirectionChangeableDuringRuntime = STD_ON ,
						.PortModeChangeableDuringRuntime  = STD_ON
				},

	[PORT_A_PIN_1] =
				{.PinMode = PORT_PIN_MODE_DIO ,
						.PinDirection = PORT_PIN_OUT ,
						.PinLevelInitValue = PORT_PIN_LEVEL_LOW ,
						.PinInternalPullUp = PORT_PIN_INTERNAL_PULL_DOWN ,
						.PinSpeed  = PORT_PIN_SPEED_V_HIGH,		//Speed_Register
						.PinOType  = PORT_PIN_OUTPUT_PUSH_PULL ,
						.PinDirectionChangeableDuringRuntime = STD_ON ,
						.PortModeChangeableDuringRuntime  = STD_ON
				},

	[PORT_A_PIN_2] =
				{.PinMode = PORT_PIN_MODE_DIO ,
						.PinDirection = PORT_PIN_OUT ,
						.PinLevelInitValue = PORT_PIN_LEVEL_HIGH ,
						.PinInternalPullUp = PORT_PIN_INTERNAL_PULL_UP ,
						.PinSpeed  = PORT_PIN_SPEED_V_HIGH,		//Speed_Register
						.PinOType  = PORT_PIN_OUTPUT_PUSH_PULL ,
						.PinDirectionChangeableDuringRuntime = STD_ON ,
						.PortModeChangeableDuringRuntime  = STD_ON

				},
	[PORT_A_PIN_3] =
				{.PinMode = PORT_PIN_MODE_DIO ,
						.PinDirection = PORT_PIN_OUT ,
						.PinLevelInitValue = PORT_PIN_LEVEL_LOW ,
						.PinInternalPullUp = PORT_PIN_INTERNAL_PULL_DOWN,
						.PinSpeed  = PORT_PIN_SPEED_V_HIGH,		//Speed_Register
						.PinOType  = PORT_PIN_OUTPUT_PUSH_PULL ,
						.PinDirectionChangeableDuringRuntime = STD_ON ,
						.PortModeChangeableDuringRuntime  = STD_ON
				}

};
