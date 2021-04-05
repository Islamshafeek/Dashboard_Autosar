/*
 * speed.h
 *
 *  Created on: Mar 21, 2021
 *      Author: Farid
 */

#ifndef APP_SPEED_SPEED_H_
#define APP_SPEED_SPEED_H_

#define SPEED_u8INC_BY_ONE		(u8)0
#define SPEED_u8DEC_BY_ONE      (u8)1
#define SPEED_u8DEC_BY_TEN      (u8)2
#define SPEED_u8INC_BY_TEN      (u8)3
#define SPEED_u8BREAK           (u8)4

extern u8 SPEED_u8SetSpeed(u8 u8Speed_Copy);
extern u8 SPEED_u8GetSpeed(u8 * pu8Speed);


#define E_OK              (u8)0
#define E_NOK			  (u8)1


#endif /* APP_SPEED_SPEED_H_ */
