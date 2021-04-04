/*
 * UART.c
 *
 *  Created on: Mar 11, 2021
 *      Author: Mohsen
 */

#include <avr/interrupt.h>
#include "../../Lib/Std_Types.h"
#include "../../Lib/Bit_Math.h"
#include "../../Lib/ATmega32_Registers.h"
#include "../../Lib/Status.h"
#include "UART_int.h"
#include "UART_Pcfg.h"

//Add pf -> AppNotify pointerToFunction;
App_pfNotify Module_pfNotify;

/******************************************************
 * Function name: UART_vidInit
 * Description: -> Initialize Uart by setting configurations of each register.
 * 				-> Enabling Interrupts in case Interrupt mode is used
 * Input:  void
 * Output: void
 ******************************************************/
u8 UART_u8Init(void){
	u8 Loc_u8UCSRCRegValue = 0;

	/* before enabling the Rx and Tx*/
	_UCSRA.Bits.Bit1 = 0; //U2X
	_UCSRA.Bits.Bit1 = 0; //MPCM

	/* enabling the Rx and Tx*/
	_UCSRB.Bits.Bit4=1; //RxEN
	_UCSRB.Bits.Bit3=1; //TxEN

	/* setting character size */
	_UCSRB.Bits.Bit2 = 0; //UCSZ2 ,, data size 8 bits

	SET_BIT(Loc_u8UCSRCRegValue,7);
	CLR_BIT(Loc_u8UCSRCRegValue,6);
	CLR_BIT(Loc_u8UCSRCRegValue,5);
	CLR_BIT(Loc_u8UCSRCRegValue,4);

	CLR_BIT(Loc_u8UCSRCRegValue,3);
	SET_BIT(Loc_u8UCSRCRegValue,2);
	SET_BIT(Loc_u8UCSRCRegValue,1);
	CLR_BIT(Loc_u8UCSRCRegValue,0);
	_UCSRC.u8RegData = Loc_u8UCSRCRegValue;

	_UBRRH.u8RegData = 0; // to write in UBRRH not in UCSRC, we need to put MSB = 0
	_UBRRL.u8RegData = 51;

#if UART_u8RxMODE == UART_u8INTERRUPT_BASED
	_UCSRB.Bits.Bit7 = 1; //enable Rx interrupt (peripheral)
#endif
	return RT_SUCCESS;
}



/******************************************************
 * Function name: Uart_u8ReceiveData
 * Description: this function is set to receive 1 byte of data over Uart.
 * Input: void
 * Output: u16 -> data received.
 ******************************************************/
u8  UART_u8ReceiveData(u8 * Copy_pu8RecData){
#if UART_u8RxMODE == UART_u8POLLING_BASED
	while(_UCSRA.Bits.Bit7 == 0);//RXE polling check
#endif
	//you dont need to check by #if if you're interrupt based
	*Copy_pu8RecData = _UDR.u8RegData;
	return RT_SUCCESS;
}



ISR(USART_RXC_vect){
	Module_pfNotify();
}

u8 UART_vidSetCallBack(App_pfNotify pointerToFunction){
	Module_pfNotify  = pointerToFunction;
	return RT_SUCCESS;
}
