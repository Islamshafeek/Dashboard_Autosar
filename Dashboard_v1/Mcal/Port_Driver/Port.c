/*
File name: Port.c
Created on: Jan 18, 2021
Author: Rdwa Salah
 */
/***************************************************************************
File Description:
 * Implementation of the Functions of Port Driver
 * void Port_vidInit(void);
 * void SET_vidSetPinMode(u8 Copy_u8SwPinId,u8 Copy_u8SwPinMode);
 * void Port_vidSetPinDir(u8 Copy_u8SwPinId,u8 Copy_u8SwDir);
 ***************************************************************************/

#include "../../Lib/Std_Types.h"
#include "../../Lib/Bit_Math.h"
#include "../../Lib/ATmega32_Registers.h"
#include "../../Lib/Status.h"
#include "Port_int.h"
#include "Port_priv.h"
#include "Port_cfg.h"

/* ******************************************************************************************
 Function Description:
 * Function name: Port_vidIniT
 * Description: it is used to set the initial directions and initial values for the pins
 * Input Parameters:
 * 						-Not Applicable
 *Return:
 * 						-Not Applicable (void)
 *  Input/Output Parameter:
 * 						-Not Applicable
 * **************************************************************************************
 */
void Port_vidInit(void)
{
	//Pin 0 MODEs:
	// 1- Output_Low MODE
#if 	  PORT_u8PIN_0_INIT_MODE == PORT_u8OUTPUT_LOW

#undef 	PORT_u8PIN_0_DEF_VAL //--> PORTX
#define PORT_u8PIN_0_DEF_VAL	PORT_u8LOW

#undef	PORT_u8PIN_0_DEF_DIR //--> DDRx
#define PORT_u8PIN_0_DEF_DIR 	PORT_u8OUTPUT


	// 2- Output_High MODE
#elif 	  PORT_u8PIN_0_INIT_MODE == PORT_u8OUTPUT_HIGH

#undef 	PORT_u8PIN_0_DEF_VAL
#define PORT_u8PIN_0_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_0_DEF_DIR
#define PORT_u8PIN_0_DEF_DIR	PORT_u8OUTPUT


	// 3- Input_High MODE
#elif	  PORT_u8PIN_0_INIT_MODE == PORT_u8INPUT_HIGH_IMP

#undef 	PORT_u8PIN_0_DEF_VAL
#define PORT_u8PIN_0_DEF_VAL	PORT_u8LOW

#undef	PORT_u8PIN_0_DEF_DIR
#define PORT_u8PIN_0_DEF_DIR	PORT_u8INPUT


	// 4- Input_Low MODE
#elif 	  PORT_u8PIN_0_INIT_MODE == PORT_u8INPUT_PULL_UP

#undef 	PORT_u8PIN_0_DEF_VAL
#define PORT_u8PIN_0_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_0_DEF_DIR
#define PORT_u8PIN_0_DEF_DIR	PORT_u8INPUT


	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 0"
#endif	//End of Pin 0 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 1 MODEs:
	// 1- Output_Low MODE
#if 	  PORT_u8PIN_1_INIT_MODE == PORT_u8OUTPUT_LOW

#undef 	PORT_u8PIN_1_DEF_VAL
#define PORT_u8PIN_1_DEF_VAL	PORT_u8LOW

#undef	PORT_u8PIN_1_DEF_DIR
#define PORT_u8PIN_1_DEF_DIR	PORT_u8OUTPUT

	// 2- Output_High MODE
#elif	  PORT_u8PIN_1_INIT_MODE == PORT_u8OUTPUT_HIGH

#undef 	PORT_u8PIN_1_DEF_VAL
#define PORT_u8PIN_1_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_1_DEF_DIR
#define PORT_u8PIN_1_DEF_DIR	PORT_u8OUTPUT

	// 3- Input_High MODE
#elif 	  PORT_u8PIN_1_INIT_MODE == PORT_u8INPUT_HIGH_IMP

#undef 	PORT_u8PIN_1_DEF_VAL
#define PORT_u8PIN_1_DEF_VAL	PORT_u8LOW

#undef	PORT_u8PIN_1_DEF_DIR
#define PORT_u8PIN_1_DEF_DIR	PORT_u8INPUT

	// 4- Input_Low MODE
#elif 	  PORT_u8PIN_1_INIT_MODE == PORT_u8INPUT_PULL_UP

#undef 	PORT_u8PIN_1_DEF_VAL
#define PORT_u8PIN_1_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_1_DEF_DIR
#define PORT_u8PIN_1_DEF_DIR	PORT_u8INPUT

	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 1"
#endif //End of Pin 1 MODEs
	/* ------------------------------------------------------------------------- */

	//Pin 2 MODEs:
	// 1- Output_Low MODE
#if 	  PORT_u8PIN_2_INIT_MODE == PORT_u8OUTPUT_LOW

#undef 	PORT_u8PIN_2_DEF_VAL
#define PORT_u8PIN_2_DEF_VAL	PORT_u8LOW

#undef	PORT_u8PIN_2_DEF_DIR
#define PORT_u8PIN_2_DEF_DIR	PORT_u8OUTPUT

	// 2- Output_High MODE
#elif	  PORT_u8PIN_2_INIT_MODE == PORT_u8OUTPUT_HIGH

#undef 	PORT_u8PIN_2_DEF_VAL
#define PORT_u8PIN_2_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_2_DEF_DIR
#define PORT_u8PIN_2_DEF_DIR	PORT_u8OUTPUT


	// 3- Input_High MODE
#elif 	  PORT_u8PIN_2_INIT_MODE == PORT_u8INPUT_HIGH_IMP

#undef 	PORT_u8PIN_2_DEF_VAL
#define PORT_u8PIN_2_DEF_VAL	PORT_u8LOW

#undef	PORT_u8PIN_2_DEF_DIR
#define PORT_u8PIN_2_DEF_DIR	PORT_u8INPUT

	// 4- Input_Low MODE
#elif 	  PORT_u8PIN_2_INIT_MODE == PORT_u8INPUT_PULL_UP

#undef 	PORT_u8PIN_2_DEF_VAL
#define PORT_u8PIN_2_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_2_DEF_DIR
#define PORT_u8PIN_2_DEF_DIR	PORT_u8INPUT


	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 2"
#endif //End of Pin 2 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 3 MODEs:
	// 1- Output_Low MODE
#if 	  PORT_u8PIN_3_INIT_MODE == PORT_u8OUTPUT_LOW

#undef 	PORT_u8PIN_3_DEF_VAL
#define PORT_u8PIN_3_DEF_VAL	PORT_u8LOW

#undef	PORT_u8PIN_3_DEF_DIR
#define PORT_u8PIN_3_DEF_DIR	PORT_u8OUTPUT

	// 2- Output_High MODE
#elif	  PORT_u8PIN_3_INIT_MODE == PORT_u8OUTPUT_HIGH

#undef 	PORT_u8PIN_3_DEF_VAL
#define PORT_u8PIN_3_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_3_DEF_DIR
#define PORT_u8PIN_3_DEF_DIR	PORT_u8OUTPUT

	// 3- Input_High MODE
#elif 	  PORT_u8PIN_3_INIT_MODE == PORT_u8INPUT_HIGH_IMP

#undef 	PORT_u8PIN_3_DEF_VAL
#define PORT_u8PIN_3_DEF_VAL	PORT_u8LOW

#undef	PORT_u8PIN_3_DEF_DIR
#define PORT_u8PIN_3_DEF_DIR	PORT_u8INPUT

	// 4- Input_Low MODE
#elif 	  PORT_u8PIN_3_INIT_MODE == PORT_u8INPUT_PULL_UP

#undef 	PORT_u8PIN_3_DEF_VAL
#define PORT_u8PIN_3_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_3_DEF_DIR
#define PORT_u8PIN_3_DEF_DIR	PORT_u8INPUT


	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 3"
#endif //End of Pin 3 MODEs
	/* ------------------------------------------------------------------------- */
	//Pin 4 MODEs:
	// 1- Output_Low MODE
#if 	  PORT_u8PIN_4_INIT_MODE == PORT_u8OUTPUT_LOW

#undef 	PORT_u8PIN_4_DEF_VAL
#define PORT_u8PIN_4_DEF_VAL	PORT_u8LOW

#undef	PORT_u8PIN_4_DEF_DIR
#define PORT_u8PIN_4_DEF_DIR	PORT_u8OUTPUT


	// 2- Output_High MODE
#elif	  PORT_u8PIN_4_INIT_MODE == PORT_u8OUTPUT_HIGH

#undef 	PORT_u8PIN_4_DEF_VAL
#define PORT_u8PIN_4_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_4_DEF_DIR
#define PORT_u8PIN_4_DEF_DIR	PORT_u8OUTPUT


	// 3- Input_High MODE
#elif 	  PORT_u8PIN_4_INIT_MODE == PORT_u8INPUT_HIGH_IMP

#undef 	PORT_u8PIN_4_DEF_VAL
#define PORT_u8PIN_4_DEF_VAL	PORT_u8LOW

#undef	PORT_u8PIN_4_DEF_DIR
#define PORT_u8PIN_4_DEF_DIR	PORT_u8INPUT

	// 4- Input_Low MODE
#elif 	  PORT_u8PIN_4_INIT_MODE == PORT_u8INPUT_PULL_UP

#undef 	PORT_u8PIN_4_DEF_VAL
#define PORT_u8PIN_4_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_4_DEF_DIR
#define PORT_u8PIN_4_DEF_DIR	PORT_u8INPUT

	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 4"
#endif //End of Pin 4 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 5 MODEs:
	// 1- Output_Low MODE
#if 	  PORT_u8PIN_5_INIT_MODE == PORT_u8OUTPUT_LOW

#undef 	PORT_u8PIN_5_DEF_VAL
#define PORT_u8PIN_5_DEF_VAL	PORT_u8LOW

#undef	PORT_u8PIN_5_DEF_DIR
#define PORT_u8PIN_5_DEF_DIR	PORT_u8OUTPUT

	// 2- Output_High MODE
#elif	  PORT_u8PIN_5_INIT_MODE == PORT_u8OUTPUT_HIGH

#undef 	PORT_u8PIN_5_DEF_VAL
#define PORT_u8PIN_5_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_5_DEF_DIR
#define PORT_u8PIN_5_DEF_DIR	PORT_u8OUTPUT

	// 3- Input_High MODE
#elif 	  PORT_u8PIN_5_INIT_MODE == PORT_u8INPUT_HIGH_IMP

#undef 	PORT_u8PIN_5_DEF_VAL
#define PORT_u8PIN_5_DEF_VAL	PORT_u8LOW

#undef	PORT_u8PIN_5_DEF_DIR
#define PORT_u8PIN_5_DEF_DIR	PORT_u8INPUT

	// 4- Input_Low MODE
#elif 	  PORT_u8PIN_5_INIT_MODE == PORT_u8INPUT_PULL_UP

#undef 	PORT_u8PIN_5_DEF_VAL
#define PORT_u8PIN_5_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_5_DEF_DIR
#define PORT_u8PIN_5_DEF_DIR	PORT_u8INPUT

	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 5"
#endif //End of Pin 5 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 6 MODEs:
	// 1- Output_Low MODE
#if 	  PORT_u8PIN_6_INIT_MODE == PORT_u8OUTPUT_LOW

#undef 	PORT_u8PIN_6_DEF_VAL
#define PORT_u8PIN_6_DEF_VAL	PORT_u8LOW


#undef	PORT_u8PIN_6_DEF_DIR
#define PORT_u8PIN_6_DEF_DIR	PORT_u8OUTPUT


	// 2- Output_High MODE
#elif	  PORT_u8PIN_6_INIT_MODE == PORT_u8OUTPUT_HIGH

#undef 	PORT_u8PIN_6_DEF_VAL
#define PORT_u8PIN_6_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_6_DEF_DIR
#define PORT_u8PIN_6_DEF_DIR	PORT_u8OUTPUT


	// 3- Input_High MODE
#elif 	  PORT_u8PIN_6_INIT_MODE == PORT_u8INPUT_HIGH_IMP

#undef 	PORT_u8PIN_6_DEF_VAL
#define PORT_u8PIN_6_DEF_VAL	PORT_u8LOW

#undef	PORT_u8PIN_6_DEF_DIR
#define PORT_u8PIN_6_DEF_DIR	PORT_u8INPUT


	// 4- Input_Low MODE
#elif 	  PORT_u8PIN_6_INIT_MODE == PORT_u8INPUT_PULL_UP

#undef 	PORT_u8PIN_6_DEF_VAL
#define PORT_u8PIN_6_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_6_DEF_DIR
#define PORT_u8PIN_6_DEF_DIR	PORT_u8INPUT

	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 6"
#endif //End of Pin 6 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 7 MODEs:
	// 1- Output_Low MODE
#if 	  PORT_u8PIN_7_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_7_DEF_DIR
#undef 	PORT_u8PIN_7_DEF_VAL
#define PORT_u8PIN_7_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_7_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	  PORT_u8PIN_7_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_7_DEF_DIR
#undef 	PORT_u8PIN_7_DEF_VAL
#define PORT_u8PIN_7_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_7_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	  PORT_u8PIN_7_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_7_DEF_DIR
#undef 	PORT_u8PIN_7_DEF_VAL
#define PORT_u8PIN_7_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_7_DEF_VAL	PORT_u8HIGH

	// 4- Input_Low MODE
#elif 	  PORT_u8PIN_7_INIT_MODE == PORT_u8INPUT_PULL_UP

#undef 	PORT_u8PIN_7_DEF_VAL
#define PORT_u8PIN_7_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_7_DEF_DIR
#define PORT_u8PIN_7_DEF_DIR	PORT_u8INPUT

	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 7"
#endif //End of Pin 7 MODEs
	/* ------------------------------------------------------------------------- */
	//Pin 8 MODEs:
	// 1- Output_Low MODE
#if 	  PORT_u8PIN_8_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_8_DEF_DIR
#undef 	PORT_u8PIN_8_DEF_VAL
#define PORT_u8PIN_8_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_8_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	  PORT_u8PIN_8_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_8_DEF_DIR
#undef 	PORT_u8PIN_8_DEF_VAL
#define PORT_u8PIN_8_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_8_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	  PORT_u8PIN_8_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_8_DEF_DIR
#undef 	PORT_u8PIN_8_DEF_VAL
#define PORT_u8PIN_8_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_8_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	  PORT_u8PIN_8_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_8_DEF_VAL
	#define PORT_u8PIN_8_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_8_DEF_DIR
	#define PORT_u8PIN_8_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 8"
#endif //End of Pin 8 MODEs
	/* ------------------------------------------------------------------------- */
	//Pin 9 MODEs:
	// 1- Output_Low MODE
#if 	  PORT_u8PIN_9_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_9_DEF_DIR
#undef 	PORT_u8PIN_9_DEF_VAL
#define PORT_u8PIN_9_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_9_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	  PORT_u8PIN_9_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_9_DEF_DIR
#undef 	PORT_u8PIN_9_DEF_VAL
#define PORT_u8PIN_9_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_9_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	  PORT_u8PIN_9_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_9_DEF_DIR
#undef 	PORT_u8PIN_9_DEF_VAL
#define PORT_u8PIN_9_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_9_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	  PORT_u8PIN_9_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef 	PORT_u8PIN_9_DEF_VAL
#define PORT_u8PIN_9_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_9_DEF_DIR
#define PORT_u8PIN_9_DEF_DIR	PORT_u8INPUT

	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 9"
#endif //End of Pin 9 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 10 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_10_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_10_DEF_DIR
#undef 	PORT_u8PIN_10_DEF_VAL
#define PORT_u8PIN_10_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_10_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	 PORT_u8PIN_10_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_10_DEF_DIR
#undef 	PORT_u8PIN_10_DEF_VAL
#define PORT_u8PIN_10_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_10_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_10_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_10_DEF_DIR
#undef 	PORT_u8PIN_10_DEF_VAL
#define PORT_u8PIN_10_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_10_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_10_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_10_DEF_VAL
	#define PORT_u8PIN_10_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_10_DEF_DIR
	#define PORT_u8PIN_10_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 10"
#endif //End of Pin 10 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 11 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_11_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_11_DEF_DIR
#undef 	PORT_u8PIN_11_DEF_VAL
#define PORT_u8PIN_11_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_11_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	 PORT_u8PIN_11_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_11_DEF_DIR
#undef 	PORT_u8PIN_11_DEF_VAL
#define PORT_u8PIN_11_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_11_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_11_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_11_DEF_DIR
#undef 	PORT_u8PIN_11_DEF_VAL
#define PORT_u8PIN_11_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_11_DEF_VAL	PORT_u8lOW
	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_11_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef 	PORT_u8PIN_11_DEF_VAL
#define PORT_u8PIN_11_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_11_DEF_DIR
#define PORT_u8PIN_11_DEF_DIR	PORT_u8INPUT

	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 11"
#endif //End of Pin 11 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 12 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_12_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_12_DEF_DIR
#undef 	PORT_u8PIN_12_DEF_VAL
#define PORT_u8PIN_12_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_12_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	 PORT_u8PIN_12_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_12_DEF_DIR
#undef 	PORT_u8PIN_12_DEF_VAL
#define PORT_u8PIN_12_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_12_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_12_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_12_DEF_DIR
#undef 	PORT_u8PIN_12_DEF_VAL
#define PORT_u8PIN_12_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_12_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_12_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_12_DEF_VAL
	#define PORT_u8PIN_12_DEF_VAL	PORT_u8HIGH
	#undef	PORT_u8PIN_12_DEF_DIR
	#define PORT_u8PIN_12_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 12"
#endif //End of Pin 12 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 13 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_13_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_13_DEF_DIR
#undef 	PORT_u8PIN_13_DEF_VAL
#define PORT_u8PIN_13_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_13_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	 PORT_u8PIN_13_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_13_DEF_DIR
#undef 	PORT_u8PIN_13_DEF_VAL
#define PORT_u8PIN_13_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_13_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_13_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_13_DEF_DIR
#undef 	PORT_u8PIN_13_DEF_VAL
#define PORT_u8PIN_13_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_13_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_13_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_13_DEF_VAL
	#define PORT_u8PIN_13_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_13_DEF_DIR
	#define PORT_u8PIN_13_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 13"
#endif //End of Pin 13 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 14 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_14_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_14_DEF_DIR
#undef 	PORT_u8PIN_14_DEF_VAL
#define PORT_u8PIN_14_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_14_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	 PORT_u8PIN_14_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_14_DEF_DIR
#undef 	PORT_u8PIN_14_DEF_VAL
#define PORT_u8PIN_14_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_14_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_14_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_14_DEF_DIR
#undef 	PORT_u8PIN_14_DEF_VAL
#define PORT_u8PIN_14_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_14_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_14_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_14_DEF_VAL
	#define PORT_u8PIN_14_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_14_DEF_DIR
	#define PORT_u8PIN_14_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 14"
#endif //End of Pin 14 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 15 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_15_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_15_DEF_DIR
#undef 	PORT_u8PIN_15_DEF_VAL
#define PORT_u8PIN_15_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_15_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	 PORT_u8PIN_15_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_15_DEF_DIR
#undef 	PORT_u8PIN_15_DEF_VAL
#define PORT_u8PIN_15_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_15_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_15_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_15_DEF_DIR
#undef 	PORT_u8PIN_15_DEF_VAL
#define PORT_u8PIN_15_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_15_DEF_VAL	PORT_u8HIGH

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_15_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_15_DEF_VAL
	#define PORT_u8PIN_15_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_15_DEF_DIR
	#define PORT_u8PIN_15_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 15"
#endif //End of Pin 15 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 16 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_16_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_16_DEF_DIR
#undef 	PORT_u8PIN_16_DEF_VAL
#define PORT_u8PIN_16_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_16_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	 PORT_u8PIN_16_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_16_DEF_DIR
#undef 	PORT_u8PIN_16_DEF_VAL
#define PORT_u8PIN_16_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_16_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_16_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_16_DEF_DIR
#undef 	PORT_u8PIN_16_DEF_VAL
#define PORT_u8PIN_16_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_16_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_16_INIT_MODE == PORT_u8INPUT_PULL_UP
#undef 	PORT_u8PIN_16_DEF_VAL
#define PORT_u8PIN_16_DEF_VAL	PORT_u8HIGH

#undef	PORT_u8PIN_16_DEF_DIR
#define PORT_u8PIN_16_DEF_DIR	PORT_u8INPUT

	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 16"
#endif //End of Pin 16 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 17 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_17_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_17_DEF_DIR
#undef 	PORT_u8PIN_17_DEF_VAL
#define PORT_u8PIN_17_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_17_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	 PORT_u8PIN_17_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_17_DEF_DIR
#undef 	PORT_u8PIN_17_DEF_VAL
#define PORT_u8PIN_17_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_17_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_17_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_17_DEF_DIR
#undef 	PORT_u8PIN_17_DEF_VAL
#define PORT_u8PIN_17_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_17_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_17_INIT_MODE == PORT_u8INPUT_PULL_UP

	#undef 	PORT_u8PIN_17_DEF_VAL
	#define PORT_u8PIN_17_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_17_DEF_DIR
	#define PORT_u8PIN_17_DEF_DIR	PORT_u8INPUT	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 17"
#endif //End of Pin 17 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 18 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_18_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_18_DEF_DIR
#undef 	PORT_u8PIN_18_DEF_VAL
#define PORT_u8PIN_18_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_18_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	 PORT_u8PIN_18_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_18_DEF_DIR
#undef 	PORT_u8PIN_18_DEF_VAL
#define PORT_u8PIN_18_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_18_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_18_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_18_DEF_DIR
#undef 	PORT_u8PIN_18_DEF_VAL
#define PORT_u8PIN_18_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_18_DEF_VAL	PORT_u8HIGH

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_18_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_18_DEF_VAL
	#define PORT_u8PIN_18_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_18_DEF_DIR
	#define PORT_u8PIN_18_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 18"
#endif //End of Pin 18 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 19 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_19_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_19_DEF_DIR
#undef 	PORT_u8PIN_19_DEF_VAL
#define PORT_u8PIN_19_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_19_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	 PORT_u8PIN_19_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_19_DEF_DIR
#undef 	PORT_u8PIN_19_DEF_VAL
#define PORT_u8PIN_19_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_19_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_19_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_19_DEF_DIR
#undef 	PORT_u8PIN_19_DEF_VAL
#define PORT_u8PIN_19_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_19_DEF_VAL	PORT_u8lOW

	// 4- Input_Low MODE
#elif 	  PORT_u8PIN_19_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_19_DEF_VAL
	#define PORT_u8PIN_19_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_19_DEF_DIR
	#define PORT_u8PIN_19_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 19"
#endif //End of Pin 19 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 20 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_20_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_20_DEF_DIR
#undef 	PORT_u8PIN_20_DEF_VAL
#define PORT_u8PIN_20_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_20_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	 PORT_u8PIN_20_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_20_DEF_DIR
#undef 	PORT_u8PIN_20_DEF_VAL
#define PORT_u8PIN_20_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_20_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_20_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_20_DEF_DIR
#undef 	PORT_u8PIN_20_DEF_VAL
#define PORT_u8PIN_20_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_20_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_20_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_20_DEF_VAL
	#define PORT_u8PIN_20_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_20_DEF_DIR
	#define PORT_u8PIN_20_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 20"
#endif //End of Pin 20 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 21 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_21_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_21_DEF_DIR
#undef 	PORT_u8PIN_21_DEF_VAL
#define PORT_u8PIN_21_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_21_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	 PORT_u8PIN_21_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_21_DEF_DIR
#undef 	PORT_u8PIN_21_DEF_VAL
#define PORT_u8PIN_21_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_21_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_21_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_21_DEF_DIR
#undef 	PORT_u8PIN_21_DEF_VAL
#define PORT_u8PIN_21_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_21_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_21_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_21_DEF_VAL
	#define PORT_u8PIN_21_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_21_DEF_DIR
	#define PORT_u8PIN_21_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 21"
#endif //End of Pin 21 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 22 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_22_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_22_DEF_DIR
#undef 	PORT_u8PIN_22_DEF_VAL
#define PORT_u8PIN_22_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_22_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	 PORT_u8PIN_22_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_22_DEF_DIR
#undef 	PORT_u8PIN_22_DEF_VAL
#define PORT_u8PIN_22_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_22_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_22_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_22_DEF_DIR
#undef 	PORT_u8PIN_22_DEF_VAL
#define PORT_u8PIN_22_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_22_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_22_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_22_DEF_VAL
	#define PORT_u8PIN_22_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_22_DEF_DIR
	#define PORT_u8PIN_22_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 22"
#endif //End of Pin 22 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 23 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_23_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_23_DEF_DIR
#undef 	PORT_u8PIN_23_DEF_VAL
#define PORT_u8PIN_23_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_23_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	 PORT_u8PIN_23_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_23_DEF_DIR
#undef 	PORT_u8PIN_23_DEF_VAL
#define PORT_u8PIN_23_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_23_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_23_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_23_DEF_DIR
#undef 	PORT_u8PIN_23_DEF_VAL
#define PORT_u8PIN_23_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_23_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_23_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_23_DEF_VAL
	#define PORT_u8PIN_23_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_23_DEF_DIR
	#define PORT_u8PIN_23_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 23"
#endif //End of Pin 23 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 24 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_24_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_24_DEF_DIR
#undef 	PORT_u8PIN_24_DEF_VAL
#define PORT_u8PIN_24_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_24_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	 PORT_u8PIN_24_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_24_DEF_DIR
#undef 	PORT_u8PIN_24_DEF_VAL
#define PORT_u8PIN_24_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_24_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_24_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_24_DEF_DIR
#undef 	PORT_u8PIN_24_DEF_VAL
#define PORT_u8PIN_24_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_24_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_24_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_24_DEF_VAL
	#define PORT_u8PIN_24_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_24_DEF_DIR
	#define PORT_u8PIN_24_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 24"
#endif //End of Pin 24 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 25 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_25_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_25_DEF_DIR
#undef 	PORT_u8PIN_25_DEF_VAL
#define PORT_u8PIN_25_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_25_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif	 PORT_u8PIN_25_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_25_DEF_DIR
#undef 	PORT_u8PIN_25_DEF_VAL
#define PORT_u8PIN_25_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_25_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_25_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_25_DEF_DIR
#undef 	PORT_u8PIN_25_DEF_VAL
#define PORT_u8PIN_25_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_25_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_25_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_25_DEF_VAL
	#define PORT_u8PIN_25_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_25_DEF_DIR
	#define PORT_u8PIN_25_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 25"
#endif //End of Pin 25 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 26 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_26_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_26_DEF_DIR
#undef 	PORT_u8PIN_26_DEF_VAL
#define PORT_u8PIN_26_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_26_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif 	 PORT_u8PIN_26_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_26_DEF_DIR
#undef 	PORT_u8PIN_26_DEF_VAL
#define PORT_u8PIN_26_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_26_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_26_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_26_DEF_DIR
#undef 	PORT_u8PIN_26_DEF_VAL
#define PORT_u8PIN_26_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_26_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_26_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_26_DEF_VAL
	#define PORT_u8PIN_26_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_26_DEF_DIR
	#define PORT_u8PIN_26_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 26"
#endif //End of Pin 26 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 27 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_27_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_27_DEF_DIR
#undef 	PORT_u8PIN_27_DEF_VAL
#define PORT_u8PIN_27_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_27_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif 	 PORT_u8PIN_27_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_27_DEF_DIR
#undef 	PORT_u8PIN_27_DEF_VAL
#define PORT_u8PIN_27_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_27_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_27_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_27_DEF_DIR
#undef 	PORT_u8PIN_27_DEF_VAL
#define PORT_u8PIN_27_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_27_DEF_VAL	PORT_u8HIGH

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_27_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_27_DEF_VAL
	#define PORT_u8PIN_27_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_27_DEF_DIR
	#define PORT_u8PIN_27_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 27"
#endif //End of Pin 27 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 28 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_28_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_28_DEF_DIR
#undef 	PORT_u8PIN_28_DEF_VAL
#define PORT_u8PIN_28_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_28_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif 	 PORT_u8PIN_28_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_28_DEF_DIR
#undef 	PORT_u8PIN_28_DEF_VAL
#define PORT_u8PIN_28_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_28_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_28_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_28_DEF_DIR
#undef 	PORT_u8PIN_28_DEF_VAL
#define PORT_u8PIN_28_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_28_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_28_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_28_DEF_VAL
	#define PORT_u8PIN_28_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_28_DEF_DIR
	#define PORT_u8PIN_28_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 28"
#endif //End of Pin 28 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 29 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_29_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_29_DEF_DIR
#undef 	PORT_u8PIN_29_DEF_VAL
#define PORT_u8PIN_29_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_29_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif 	 PORT_u8PIN_29_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_29_DEF_DIR
#undef 	PORT_u8PIN_29_DEF_VAL
#define PORT_u8PIN_29_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_29_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_29_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_29_DEF_DIR
#undef 	PORT_u8PIN_29_DEF_VAL
#define PORT_u8PIN_29_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_29_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_29_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_29_DEF_VAL
	#define PORT_u8PIN_29_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_29_DEF_DIR
	#define PORT_u8PIN_29_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 29"
#endif //End of Pin 29 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 30 MODEs:
	// 1- Output_Low MODE
#if		PORT_u8PIN_30_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_30_DEF_DIR
#undef	PORT_u8PIN_30_DEF_VAL
#define PORT_u8PIN_30_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_30_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif 	 PORT_u8PIN_30_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_30_DEF_DIR
#undef PORT_u8PIN_30_DEF_VAL
#define PORT_u8PIN_30_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_30_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_30_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef	PORT_u8PIN_30_DEF_DIR
#undef PORT_u8PIN_30_DEF_VAL
#define PORT_u8PIN_30_DEF_DIR	PORT_u8INPUT
#define PORT_u8PIN_30_DEF_VAL	PORT_u8LOW

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_30_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_30_DEF_VAL
	#define PORT_u8PIN_30_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_30_DEF_DIR
	#define PORT_u8PIN_30_DEF_DIR	PORT_u8INPUT
	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 30"
#endif //End of Pin 30 MODEs

	/* ------------------------------------------------------------------------- */
	//Pin 31 MODEs:
	// 1- Output_Low MODE
#if 	 PORT_u8PIN_31_INIT_MODE == PORT_u8OUTPUT_LOW
#undef	PORT_u8PIN_31_DEF_DIR
#undef PORT_u8PIN_31_DEF_VAL
#define PORT_u8PIN_31_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_31_DEF_VAL	PORT_u8LOW

	// 2- Output_High MODE
#elif 	 PORT_u8PIN_31_INIT_MODE == PORT_u8OUTPUT_HIGH
#undef	PORT_u8PIN_31_DEF_DIR
#undef PORT_u8PIN_31_DEF_VAL
#define PORT_u8PIN_31_DEF_DIR	PORT_u8OUTPUT
#define PORT_u8PIN_31_DEF_VAL	PORT_u8HIGH

	// 3- Input_High MODE
#elif 	 PORT_u8PIN_31_INIT_MODE == PORT_u8INPUT_HIGH_IMP

#undef PORT_u8PIN_31_DEF_VAL
#define PORT_u8PIN_31_DEF_VAL	PORT_u8LOW

#undef	PORT_u8PIN_31_DEF_DIR
#define PORT_u8PIN_31_DEF_DIR	PORT_u8INPUT

	// 4- Input_Low MODE
#elif 	 PORT_u8PIN_31_INIT_MODE == PORT_u8INPUT_PULL_UP
	#undef 	PORT_u8PIN_31_DEF_VAL
	#define PORT_u8PIN_31_DEF_VAL	PORT_u8HIGH

	#undef	PORT_u8PIN_31_DEF_DIR
	#define PORT_u8PIN_31_DEF_DIR	PORT_u8INPUT


	// Set the default Direction and Value.
#else
#warning "Warning: Wrong Configuration for Pin 31 "
#endif //End of Pin 31 MODEs
	/* Assign the ports with the required values */
	_PORTA = CONC(PORT_u8PIN_7_DEF_VAL ,PORT_u8PIN_6_DEF_VAL ,PORT_u8PIN_5_DEF_VAL ,PORT_u8PIN_4_DEF_VAL ,PORT_u8PIN_3_DEF_VAL ,PORT_u8PIN_2_DEF_VAL ,PORT_u8PIN_1_DEF_VAL,PORT_u8PIN_0_DEF_VAL);
	_PORTB = CONC(PORT_u8PIN_15_DEF_VAL,PORT_u8PIN_14_DEF_VAL,PORT_u8PIN_13_DEF_VAL,PORT_u8PIN_12_DEF_VAL,PORT_u8PIN_11_DEF_VAL,PORT_u8PIN_10_DEF_VAL,PORT_u8PIN_9_DEF_VAL,PORT_u8PIN_8_DEF_VAL);
	_PORTC = CONC(PORT_u8PIN_23_DEF_VAL,PORT_u8PIN_22_DEF_VAL,PORT_u8PIN_21_DEF_VAL,PORT_u8PIN_20_DEF_VAL,PORT_u8PIN_19_DEF_VAL,PORT_u8PIN_18_DEF_VAL,PORT_u8PIN_17_DEF_VAL,PORT_u8PIN_16_DEF_VAL);
	_PORTD = CONC(PORT_u8PIN_31_DEF_VAL,PORT_u8PIN_30_DEF_VAL,PORT_u8PIN_29_DEF_VAL,PORT_u8PIN_28_DEF_VAL,PORT_u8PIN_27_DEF_VAL,PORT_u8PIN_26_DEF_VAL,PORT_u8PIN_25_DEF_VAL,PORT_u8PIN_24_DEF_VAL);

	/* Assign the ports with the required directions */
	_DDRA = CONC(PORT_u8PIN_7_DEF_DIR,PORT_u8PIN_6_DEF_DIR,PORT_u8PIN_5_DEF_DIR,PORT_u8PIN_4_DEF_DIR,PORT_u8PIN_3_DEF_DIR,PORT_u8PIN_2_DEF_DIR,PORT_u8PIN_1_DEF_DIR,PORT_u8PIN_0_DEF_DIR);
	_DDRB = CONC(PORT_u8PIN_15_DEF_DIR,PORT_u8PIN_14_DEF_DIR,PORT_u8PIN_13_DEF_DIR,PORT_u8PIN_12_DEF_DIR,PORT_u8PIN_11_DEF_DIR,PORT_u8PIN_10_DEF_DIR,PORT_u8PIN_9_DEF_DIR,PORT_u8PIN_8_DEF_DIR);
	_DDRC = CONC(PORT_u8PIN_23_DEF_DIR,PORT_u8PIN_22_DEF_DIR,PORT_u8PIN_21_DEF_DIR,PORT_u8PIN_20_DEF_DIR,PORT_u8PIN_19_DEF_DIR,PORT_u8PIN_18_DEF_DIR,PORT_u8PIN_17_DEF_DIR,PORT_u8PIN_16_DEF_DIR);
	_DDRD = CONC(PORT_u8PIN_31_DEF_DIR,PORT_u8PIN_30_DEF_DIR,PORT_u8PIN_29_DEF_DIR,PORT_u8PIN_28_DEF_DIR,PORT_u8PIN_27_DEF_DIR,PORT_u8PIN_26_DEF_DIR,PORT_u8PIN_25_DEF_DIR,PORT_u8PIN_24_DEF_DIR);
}

/* ******************************************************************************************
 Function Description:
 * Function name:Port_vidSetPinMode
 * Description:function used to set the pin modes
 * 				there are four modes:
 * 						1- PORT_u8OUTPUT_LOW
						2- PORT_u8OUTPUT_HIGH
						3- PORT_u8INPUT_HIGH_IMP
						4- PORT_u8INPUT_PULL_UP
 * Input Parameters:
 *						1- Copy_u8SwPinId: in range {DIO_u8Pin_0, DIO_u8Pin_31}
 *						2- Copy_u8SwPinMODE:{
 *						PORT_u8OUTPUT_LOW  		-> 1
 *						PORT_u8OUTPUT_HIGH 		-> 2
 *						PORT_u8INPUT_HIGH_IMP	-> 3
 *						PORT_u8INPUT_PULL_UP}	-> 4
 * Return:
 * 						-Not Applicable (void)
 * Input/Output Parameter:
 * 						-Not Applicable
 * **************************************************************************************
 */
void Port_vidSetPinMode(u8 Copy_u8SwPinId,u8 Copy_u8SwPinMODE)
{
	u8 Loc_u8PortId;//variable for Port Id
	u8 Loc_u8PinId;//variable for Pin Id

	Loc_u8PortId = Copy_u8SwPinId / (u8)8;//To get the port id 0,1,2,3
	Loc_u8PinId =  Copy_u8SwPinId % (u8)8;//To get the pin id 0 ->> 31


	switch(Loc_u8PortId) //switch case on port and pins
	{
	case 0: // 0 = PORTA
		switch(Copy_u8SwPinMODE) //switch case on pin modes
		{
		case 1:
			/* In PORT_u8OUTPUT_LOW mode :
			 * 				Set the pin direction as OUTPUT
			 * 				Set the pin value as LOW
			 */
			CLR_BIT(_PORTA,Loc_u8PinId); //set the pin value in port A as LOW
			SET_BIT(_DDRA,Loc_u8PinId); //set the pin direction in port A as OUTPUT
			break;
		case 2:
			/* In PORT_u8OUTPUT_HIGH mode :
			 * 				Set the pin direction as OUTPUT
			 * 				Set the pin value as HIGH
			 */
			SET_BIT(_PORTA,Loc_u8PinId); //set the pin value in port A as LOW
			SET_BIT(_DDRA,Loc_u8PinId); //set the pin direction in port A as OUTPUT
			break;
		case 3:
			/* In PORT_u8INPUT_HIGH_IMP mode :
			 * 				Set the pin direction as INPUT
			 * 				Deactivate the pull up resistance
			 */
			CLR_BIT(_PORTA,Loc_u8PinId); //set the pin value in port A as LOW
			CLR_BIT(_DDRA,Loc_u8PinId); //set the pin direction in port A as INPUT
			break;
		case 4:
			/* In PORT_u8INPUT_PULL_UP mode :
			 * 				Set the pin direction as INPUT
			 * 				Activate the pull up resistance
			 */
			SET_BIT(_PORTA,Loc_u8PinId); //set the pin value in port A as LOW
			CLR_BIT(_DDRA,Loc_u8PinId); //set the pin direction in port A as INPUT
			break;
		default:
			//DO NOTHING
			break;
		} //end of the "switch case on pin modes"
		break;
		/*****************************************************/
		case 1: // 1 = PORTB
			switch(Copy_u8SwPinMODE) //switch case on pin modes
			{
			case 1:
				/* In PORT_u8OUTPUT_LOW mode :
				 * 				Set the pin direction as OUTPUT
				 * 				Set the pin value as LOW
				 */
				CLR_BIT(_PORTA,Loc_u8PinId); //set the pin value in port A as LOW
				SET_BIT(_DDRA,Loc_u8PinId); //set the pin direction in port A as OUTPUT
				break;
			case 2:
				/* In PORT_u8OUTPUT_HIGH mode :
				 * 				Set the pin direction as OUTPUT
				 * 				Set the pin value as HIGH
				 */
				SET_BIT(_PORTA,Loc_u8PinId); //set the pin value in port A as LOW
				SET_BIT(_DDRA,Loc_u8PinId); //set the pin direction in port A as OUTPUT
				break;
			case 3:
				/* In PORT_u8INPUT_HIGH_IMP mode :
				 * 				Set the pin direction as INPUT
				 * 				Deactivate the pull up resistance
				 */
				CLR_BIT(_PORTA,Loc_u8PinId); //set the pin value in port A as LOW
				CLR_BIT(_DDRA,Loc_u8PinId); //set the pin direction in port A as INPUT
				break;
			case 4:
				/* In PORT_u8INPUT_PULL_UP mode :
				 * 				Set the pin direction as INPUT
				 * 				Activate the pull up resistance
				 */
				SET_BIT(_PORTA,Loc_u8PinId); //set the pin value in port A as LOW
				CLR_BIT(_DDRA,Loc_u8PinId); //set the pin direction in port A as INPUT
				break;
			default:
				//DO NOTHING
				break;
			} //end of the "switch case on pin modes"
			break;
			/*****************************************************/
			case 2: // 2 = PORTC
				switch(Copy_u8SwPinMODE) //switch case on pin modes
				{
				case 1:
					/* In PORT_u8OUTPUT_LOW mode :
					 * 				Set the pin direction as OUTPUT
					 * 				Set the pin value as LOW
					 */
					CLR_BIT(_PORTA,Loc_u8PinId); //set the pin value in port A as LOW
					SET_BIT(_DDRA,Loc_u8PinId); //set the pin direction in port A as OUTPUT
					break;
				case 2:

					/* In PORT_u8OUTPUT_HIGH mode :
					 * 				Set the pin direction as OUTPUT
					 * 				Set the pin value as HIGH
					 */
					SET_BIT(_PORTA,Loc_u8PinId); //set the pin value in port A as LOW
					SET_BIT(_DDRA,Loc_u8PinId); //set the pin direction in port A as OUTPUT
					break;
				case 3:
					/* In PORT_u8INPUT_HIGH_IMP mode :
					 * 				Set the pin direction as INPUT
					 * 				Deactivate the pull up resistance
					 */
					CLR_BIT(_PORTA,Loc_u8PinId); //set the pin value in port A as LOW
					CLR_BIT(_DDRA,Loc_u8PinId); //set the pin direction in port A as INPUT
					break;
				case 4:
					/* In PORT_u8INPUT_PULL_UP mode :
					 * 				Set the pin direction as INPUT
					 * 				Activate the pull up resistance
					 */
					SET_BIT(_PORTA,Loc_u8PinId); //set the pin value in port A as LOW
					CLR_BIT(_DDRA,Loc_u8PinId); //set the pin direction in port A as INPUT
					break;
				default:
					//DO NOTHING
					break;
				} //end of the "switch case on pin modes"
				break;
				/*****************************************************/
				case 3: // 3 = PORTD
					switch(Copy_u8SwPinMODE) //switch case on pin modes
					{
					case 1:
						/* In PORT_u8OUTPUT_LOW mode :
						 * 				Set the pin direction as OUTPUT
						 * 				Set the pin value as LOW
						 */
						CLR_BIT(_PORTA,Loc_u8PinId); //set the pin value in port A as LOW
						SET_BIT(_DDRA,Loc_u8PinId); //set the pin direction in port A as OUTPUT
						break;
					case 2:
						/* In PORT_u8OUTPUT_HIGH mode :
						 * 				Set the pin direction as OUTPUT
						 * 				Set the pin value as HIGH
						 */
						SET_BIT(_PORTA,Loc_u8PinId); //set the pin value in port A as LOW
						SET_BIT(_DDRA,Loc_u8PinId); //set the pin direction in port A as OUTPUT
						break;
					case 3:
						/* In PORT_u8INPUT_HIGH_IMP mode :
						 * 				Set the pin direction as INPUT
						 * 				Deactivate the pull up resistance
						 */
						CLR_BIT(_PORTA,Loc_u8PinId); //set the pin value in port A as LOW
						CLR_BIT(_DDRA,Loc_u8PinId); //set the pin direction in port A as INPUT
						break;
					case 4:
						/* In PORT_u8INPUT_PULL_UP mode :
						 * 				Set the pin direction as INPUT
						 * 				Activate the pull up resistance
						 */
						SET_BIT(_PORTA,Loc_u8PinId); //set the pin value in port A as LOW
						CLR_BIT(_DDRA,Loc_u8PinId); //set the pin direction in port A as INPUT
						break;
					default:
						//DO NOTHING
						break;
					} //end of the "switch case on pin modes"
					break;
					default:
						//DO NOTHING
						break;
	} //end of the "switch case on port and pins"
}

/* ******************************************************************************************
 Function Description:
 * Function name: Port_vidSetPinDir
 * Description: it used to set the direction of the pins
 * Input Parameters:
 *						1- Copy_u8SwPinId: in range {PORT_u8PIN_0_INIT_MODE,PORT_u8PIN_31_INIT_MODE}
 *						2- Copy_u8SwDir: in range {PORT_u8OUTPUT, PORT_u8INPUT}
 *Return:
 * 						-Not Applicable (void)
 *  Input/Output Parameter:
 * 						-Not Applicable
 * **************************************************************************************
 */
void Port_vidSetPinDir(u8 Copy_u8SwPinId,u8 Copy_u8SwPinDir)
{
	u8 Loc_u8PortId;//variable for Port Id
	u8 Loc_u8PinId;//variable for Pin Id

	Loc_u8PortId = Copy_u8SwPinId / (u8)8;//To get the port id 0,1,2,3
	Loc_u8PinId =  Copy_u8SwPinId % (u8)8;//To get the pin id 0 ->> 31

	switch(Loc_u8PortId)
	{
	case 0: // 0 = PORTA
		if(Copy_u8SwPinDir == PORT_u8OUTPUT)
		{
			SET_BIT(_DDRA,Loc_u8PinId); //set the pin in port A as Output
		}
		else
		{
			CLR_BIT(_DDRA,Loc_u8PinId); //set the pin in port A as Input
		}
		break;
	case 1: // 1 = PORTB
		if(Copy_u8SwPinDir == PORT_u8OUTPUT)
		{
			SET_BIT(_DDRB,Loc_u8PinId); //set the pin in port B as Output
		}
		else
		{
			CLR_BIT(_DDRB,Loc_u8PinId); //set the pin in port A as Input
		}
		break;
	case 2: // 2 = PORTC
		if(Copy_u8SwPinDir == PORT_u8OUTPUT)
		{
			SET_BIT(_DDRC,Loc_u8PinId); //set the pin in port A as Output
		}
		else
		{
			CLR_BIT(_DDRC,Loc_u8PinId); //set the pin in port A as Input
		}
		break;
	case 3: // 3 = PORTD
		if(Copy_u8SwPinDir == PORT_u8OUTPUT)
		{
			SET_BIT(_DDRD,Loc_u8PinId); //set the pin in port A as Output
		}
		else
		{
			CLR_BIT(_DDRD,Loc_u8PinId); //set the pin in port A as Input
		}
		break;
	default:
		break;
	}
}
