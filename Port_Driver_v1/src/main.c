/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
*/
// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "Std_Types.h"
#include "Bits.h"
#include "Bit_Math.h"
#include "RT_Debug.h"
#include "Port.h"
#include "Rcc_int.h"


// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

extern const Port_ConfigType Port_Config[4] ;

int main(int argc, char* argv[])
{
	debug_status(Rcc_AHB1_PeriClockStatus( RCC_AHB1_PERI_CLOCK_GPIOA,RCC_PERI_CLOCK_ENABLE));

	Port_Init((Port_ConfigType*)&Port_Config);

	Port_SetPinDirection(PORT_A_PIN_2,PORT_PIN_IN);

	Port_RefreshPortDirection();

//	Port_SetPinMode(PORT_A_PIN_2,PORT_AF7);

	// Infinite loop
	while (1)
	{

	}
	// Infinite loop, never return.
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
