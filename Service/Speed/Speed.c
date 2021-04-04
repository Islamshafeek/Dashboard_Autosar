/*
 * Speed.c
 *
 *  Created on: Apr 4, 2021
 *      Author: Esraa Abdelnaby
 */
#include "../Lib/Std_Types.h"
#include "Speed.h"
#include "../Lib/Error_codes.h"
#include "Sensor_Manager.h"

static u8 u8Speed;
u8 Speed_u8SpeedGetter()
{
	return u8Speed;
}
u8 Speed_u8SpeedSetter(u8 Copy_u8SpeedSet)
{
	u8 Loc_u8State = RT_ERROR;
	switch(Copy_u8SpeedSet)
	{
	case SPEED_PLUS_ONE  :
		if((u8Speed+1) <= 180 && (u8Speed+1) < 256)
		{
			u8Speed++;
			Loc_u8State = RT_SUCCESS;
		}
		else
		{
			Loc_u8State = RT_ERROR;
		}
		break;

	case SPEED_MINUS_ONE :
		if((u8Speed-1) >= 0)
		{
			u8Speed--;
			Loc_u8State = RT_SUCCESS;
		}
		else
		{
			Loc_u8State = RT_ERROR;
		}
		break;

	case IGNITION_ON     :
		u8Speed = 0;
		Loc_u8State = RT_SUCCESS;
		break;

	case SPEED_PLUS_TEN  :
		if((u8Speed+10) <= 180 && (u8Speed+10) < 256)
		{
			u8Speed+=10;
			Loc_u8State = RT_SUCCESS;
		}
		else
		{
			Loc_u8State = RT_ERROR;
		}
		break;

	case SPEED_MINIS_TEN :
		if((u8Speed-10) >=0)
		{
			u8Speed-=10;
			Loc_u8State = RT_SUCCESS;
		}
		else
		{
			Loc_u8State = RT_ERROR;
		}
		break;

	case IGNITION_OFF    :
		u8Speed = 0;
		Loc_u8State = RT_SUCCESS;
		break;

	case RIGHT_DOOR_OPEN :
		Loc_u8State = RT_PARAM;
		break;

	case LEFT_DOOR_OPEN  :
		Loc_u8State = RT_PARAM;
		break;

	case SPEED_BREAK     :
		break;

	default              :
		Loc_u8State = RT_PARAM;
	}

	return Loc_u8State;
}
