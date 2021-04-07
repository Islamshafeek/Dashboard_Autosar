/*
 * Temp_hal.c
 *
 *  Created on: Mar 21, 2021
 *      Author: Mohsen
 */

/* Important Notes :>>
 *          1) 
 *          2)
 *
 */ 

#include "../../Lib/Std_Types.h"
#include "../../Lib/Bit_Math.h"
#include "../../Lib/ATmega32_Registers.h"
#include "../../Lib/Status.h"
#include "../../Mcal/Uart_Driver/UART_int.h"

static u32 atoi(u8 * Copy_u8KeyIn);

static u8 TempHal_requiredData = 0;
static void Temp_hal_u8SetEngineTemp(void);

/* This function is responsible for initializing down modules
 * used to get the engine temperature, which is the UART module
 * in our case.*/
u8 Temp_hal_u8Init (void){
	u8 fun_state = RT_SUCCESS;
	UART_u8Init();
	UART_vidSetCallBack(&Temp_hal_u8SetEngineTemp);
	return fun_state;
}


/* this function is used to get the data from
 * Index 0 -> 34rat
 * Index 1 -> a7ad
 * */
static void Temp_hal_u8SetEngineTemp(void){

	static u8 Loc_u8UartTempoData[4];
	static u8 Loc_u8TurnIdx = 0;

	if (Loc_u8TurnIdx == 0){// then you are sending the 34rat digit
		UART_u8GetData(&Loc_u8UartTempoData[0]);
		Loc_u8TurnIdx++;
	}else if (Loc_u8TurnIdx == 1){// then you are getting the a7ad digit
		Loc_u8TurnIdx++; // reset the index of this function
		UART_u8GetData(&Loc_u8UartTempoData[1]);

	}else{// then you are getting the a7ad digit
		Loc_u8TurnIdx=0; // reset the index of this function

		UART_u8GetData(&Loc_u8UartTempoData[2]);
		Loc_u8UartTempoData[3] = '\0';

		TempHal_requiredData =(u8) atoi(Loc_u8UartTempoData); // turn the array of characters into an integer global
	}
}


/* This function is used as a getter. It is used by Sensor_manager
 * to get the engine temperature*/
u8 Temp_hal_u8GetEngineTemp (u8 * pu8_EngineTemp){
	u8 fun_state = RT_SUCCESS;
	*pu8_EngineTemp = TempHal_requiredData;
	TempHal_requiredData = 0 ;
	return fun_state;
}


static u32 atoi(u8 * Copy_u8KeyIn){
	u32 Loc_u8ConcateNum = 0 ;
	u32 Loc_u8TempStore;
	u8 Loc_u8LoopIterator;
	// get the first element in the array, minus it by ‘0’
	// check if the number is in range {0-9}
	//----
	//Add to the total result
	//repeat till you get the end of the array (null character)
	for(Loc_u8LoopIterator = 0; Copy_u8KeyIn[Loc_u8LoopIterator ]!= '\0' ; Loc_u8LoopIterator++){
		Loc_u8TempStore = Copy_u8KeyIn[Loc_u8LoopIterator ] - '0';
		// error checking in case user inserted digit > 9
		Loc_u8ConcateNum += Loc_u8TempStore ;
		Loc_u8ConcateNum *= 10;
	}
	Loc_u8ConcateNum /= 10; // to erase the last *10 operation
	return 	Loc_u8ConcateNum;
}

