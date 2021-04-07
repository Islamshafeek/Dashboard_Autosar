/*
 * door.h
 *
 *  Created on: Mar 21, 2021
 *      Author: Farid
 */

#ifndef APP_DOOR_DOOR_H_
#define APP_DOOR_DOOR_H_


#define DOOR_u8LEFTDOOR   		(u8)0
#define DOOR_u8RIGHTDOOR  		(u8)1

#define DOOR_u8CLOSED           (u8)0
#define DOOR_u8OPENED           (u8)1

extern u8 Door_u8SetDoorStatus(u8 u8Statues_Copy , u8 u8Door_Copy) ;
extern u8 Door_u8GetDoorStatus(u8 u8Door_Copy    , u8 * pu8_status);

#endif /* APP_DOOR_DOOR_H_ */
