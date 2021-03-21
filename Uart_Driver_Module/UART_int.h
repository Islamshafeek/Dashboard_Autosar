/*
 * UART.h
 *
 *  Created on: Mar 11, 2021
 *      Author: Mohsen
 */

#ifndef UART_INT_H_
#define UART_INT_H_

typedef void( * App_pfNotify) (void);// should this be added here?

uint8_t UART_u8Init(void);
uint8_t UART_u8ReceiveData(uint8_t * Copy_pu8RecData);
uint8_t UART_vidSetCallBack(App_pfNotify ptrToFunction);
#endif /* UART_INT_H_ */
