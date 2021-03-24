/*
 * door.c
 *
 *  Created on: Mar 21, 2021
 *      Author: Farid
 */

#include "../Lib/STD_TYPES.h"
#include "door.h"
#define DOORS_u8DOOR_NUMBER         (u8)2
#define NULL						(void *)0

u8 DOOR_u8arrDoorStatus [DOORS_u8DOOR_NUMBER];

u8 Door_u8SetDoorStatus( u8 u8Door_Copy,u8 u8Statues_Copy)
{
	u8 Local_errState = E_OK ;

	if(u8Statues_Copy > DOOR_u8OPENED || u8Door_Copy > DOOR_u8RIGHTDOOR )
	{
		Local_errState = E_NOK ;
	}
	else
	{
		DOOR_u8arrDoorStatus[u8Door_Copy] = u8Statues_Copy ;
	}
	return Local_errState ;
}
u8 Door_u8GetDoorStatus(u8 u8Door_Copy , u8 * pu8_status)
{
	u8 Local_errState = E_OK ;

	if(pu8_status == NULL || u8Door_Copy > DOOR_u8RIGHTDOOR )
	{
		Local_errState = E_NOK ;
	}
	else
	{
		*pu8_status = DOOR_u8arrDoorStatus[u8Door_Copy] ;
	}
	return Local_errState ;

}
