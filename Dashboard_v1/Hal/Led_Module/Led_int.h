/*
 * LED_int.h
 *
 *  Created on: Jan 20, 2021
 *      Author: Esraa Abdelnaby
 */

#ifndef LED_INT_H_
#define LED_INT_H_

typedef enum {
	LED_enuID_0 ,
	LED_enuID_1 ,
	LED_enuID_2 ,
	LED_enuID_3 ,
	LED_enuID_4 ,
	LED_enuID_5 ,
	LED_enuID_6 ,
	LED_enuID_7 ,
	LED_enuID_8 ,
	LED_enuID_9
}LED_enuLEDId;

void LED_vidTurnOn(LED_enuLEDId Copy_enuLEDId);

void LED_vidTurnOff(LED_enuLEDId Copy_enuLEDId);

void LED_vidToggle(LED_enuLEDId Copy_enuLEDId);

#endif /* LED_INT_H_ */
