/*
 * Timer_cfg.h
 *
 *  Created on: Mar 19, 2021
 *      Author: Rdwa Salah
 */

#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

					/************** MODE CONFIGURATION ************/
/****************************************************************************************/
#define TIMER_NORMAL_MODE				        0
#define TIMER_CTC_MODE					        1
#define TIMER_FAST_PWM_MODE				        2
#define TIMER_PHASE_CORRECT_PWM_MODE	        3
/****************************************************************************************/
#define TIMER_MODE						TIMER_NORMAL_MODE
/****************************************************************************************/


					/************** CLOCK CONFIGURATION ************/
/****************************************************************************************/
 #define TIMER_NO_CLOCK_SOURCE			        0
 #define TIMER_PRESCALER_1	                    1
 #define TIMER_PRESCALER_8	                    2
 #define TIMER_PRESCALER_64				        3
 #define TIMER_PRESCALER_256			        4
 #define TIMER_PRESCALER_1024			        5
#define  TIMER_EXT_FAILING				        6
#define  TIMER_EXT_RAISING				        7
/****************************************************************************************/
#define TIMER_CLOCK_SELECT				TIMER_PRESCALER_8
/****************************************************************************************/

					/******** COMPARE OUTPUT MODE CONFIGURATION ********/
/* IF TIMER_MODE ==  TIMER_CTC_MODE */
#if TIMER_MODE ==  TIMER_CTC_MODE
	#define TOGGLE_COMPARE						(u8)0b00000001
	#define CLEAR_OC0_ON_COMPARE				(u8)0b00000010
	#define SET_OC0_ON_COMPARE					(u8)0b00000011
#endif

/* IF TIMER_MODE ==  TIMER_FAST_PWM_MODE */
#if TIMER_MODE ==  TIMER_FAST_PWM_MODE
	#define CLEAR_OC0_ON_COMPARE				(u8)0b00000010
	#define SET_OC0_ON_COMPARE					(u8)0b00000011
#endif

/* IF TIMER_MODE ==  TIMER_PHASE_CORRECT_PWM_MODE */
#if TIMER_MODE ==  TIMER_PHASE_CORRECT_PWM_MODE
	#define CLEAR_OC0_ON_COMPARE_UP_COUNT	 	(u8)0b00000010
	#define SET_OC0_ON_COMPARE_UP_COUNT			(u8)0b00000011
#endif
/****************************************************************************************/


#endif /* TIMER_CFG_H_ */
