/*
 * UART.h
 *
 *  Created on: Mar 11, 2021
 *      Author: Mohsen
 */

#ifndef UART_INT_H_
#define UART_INT_H_

typedef void( * App_pfNotify) (void);// should this be added here?

u8 UART_u8Init(void);
u8  UART_u8GetData(u8 * Copy_pu8RecData);
u8 UART_vidSetCallBack(App_pfNotify ptrToFunction);
#endif /* UART_INT_H_ */
