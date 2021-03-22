/*
 * Timer_int.h
 *
 *  Created on: Mar 19, 2021
 *      Author: Rdwa Salah
 */

#ifndef TIMER_INT_H_
#define TIMER_INT_H_

typedef void (* CallBackFunc) (void);

#define NoClkSource			0
#define ClkPre_1			1
#define ClkPre_8			2
#define ClkPre_64			3
#define ClkPre_256			4
#define ClkPre_1024			5

#define NULL 			    			0
/****************************************************************************************/
#define CLEAR_CLK_SRC_BITS             0b11111000
#define NO_CLOCK_SOURCE                0b00000000
#define PRESCALER_1		               0b00000001
#define PRESCALER_8 	               0b00000010
#define PRESCALER_64 	               0b00000011
#define PRESCALER_256 	               0b00000100
#define PRESCALER_1024	               0b00000101
/****************************************************************************************/
#define CLEAR_MODE_BITS			       0b10000111
#define NORMAL_MODE				       0b00000000
#define CTC_MODE				       0b01000000
#define FAST_PWM_MODE			       0b01001000
#define PHASE_CORRECT_PWM_MODE 	       0b00001000
/****************************************************************************************/

/****************************************************************************************/

extern u8 TIMER_vidInit(void);
extern u8 TIMER_u8EnableNotification(void);
extern u8 TIMER_u8DisableNotification(void);
extern u8 TIMER_u8StartTimer(u8 Clock);
extern u8 TIMER_u8SetCallBack_OVF( void(*ptr)(void) );
extern u8 TIMER_vidLoadTimer(u8 Copy_u8Value);

extern u8 TIMER_u8SetCallBack_COMP( void(*ptr)(void) );
/****************************************************************************************/

#endif /* TIMER_INT_H_ */
