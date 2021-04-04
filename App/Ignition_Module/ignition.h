/*
 * ignition.h
 *
 *  Created on: Mar 21, 2021
 *      Author: Farid
 */

#ifndef APP_IGNTION_IGNITION_H_
#define APP_IGNTION_IGNITION_H_


#define IGNITION_u8OFF    (u8)0
#define IGNITION_u8ON     (u8)1

#define E_OK			  (u8)0
#define E_NOK			  (u8)1


extern u8 Ignition_u8GetIgntion(u8 * pu8_Status);
extern u8 Ignition_u8SetIgntion(u8 u8_Status);


#endif /* APP_IGNTION_IGNITION_H_ */
