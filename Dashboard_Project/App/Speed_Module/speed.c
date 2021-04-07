/*
 * speed.c
 *
 *  Created on: Mar 21, 2021
 *      Author: Farid
 */

#include "../../Lib/STD_TYPES.h"
#include "../../Lib/Status.h"
#include "../../Lib/BIT_MATH.h"
#include "speed.h"

#define NULL     (void*)0

static u8 Speed_u8SpeedKm = 5;

u8 SPEED_u8SetSpeed(u8 u8Speed_Copy)
{
	u8 u8Local_ErrState = RT_SUCCESS ;

	switch(u8Speed_Copy)
	{
	case SPEED_u8INC_BY_ONE :
		if(Speed_u8SpeedKm <= 180)
		{
			Speed_u8SpeedKm++ ;
		}
		break;
	case SPEED_u8DEC_BY_ONE :
		if(Speed_u8SpeedKm > 0)
		{
			Speed_u8SpeedKm-- ;
		}
		break;
	case SPEED_u8INC_BY_TEN :
		if(Speed_u8SpeedKm <= 180)
		{
			Speed_u8SpeedKm += 10 ;
		}
//		else
//		{
//			Speed_u8SpeedKm = 180 ;
//		}
		break;

	case SPEED_u8DEC_BY_TEN :
		if(Speed_u8SpeedKm > 10)
		{
			Speed_u8SpeedKm -=10 ;
		}
		else
		{
			Speed_u8SpeedKm = 0 ;
		}
		break;
	case SPEED_u8BREAK :
		Speed_u8SpeedKm = 0;
		break;
	case SPEED_INITIAL :
		Speed_u8SpeedKm = 5;
		break;
	default:
		u8Local_ErrState = RT_PARAM ;

	}
	return u8Local_ErrState ;
}
u8 SPEED_u8GetSpeed(u8 * pu8Speed)
{
	u8 u8Local_ErrState = RT_SUCCESS ;
	if(pu8Speed == NULL)
	{
		u8Local_ErrState = RT_PARAM ;
	}
	else
	{
		*pu8Speed = Speed_u8SpeedKm ;
	}

	return u8Local_ErrState ;


}
