/*
 * ignition.c
 *
 *  Created on: Mar 21, 2021
 *      Author: Farid
 */

#include "../../Lib/STD_TYPES.h"
#include "../../Lib/BIT_MATH.h"
#include "../../Lib/Status.h"
#include "ignition_cfg.h"
#include "ignition.h"
#include "avr/io.h"


#define NULL		(void *)0

static u8 Ignition_u8Status = 0 ;


u8 Ignition_u8GetIgntion(u8 * pu8_Status)
{
	u8 Local_u8ErrState = RT_SUCCESS ;

	if(pu8_Status ==NULL)
	{
		Local_u8ErrState = RT_ERROR ;
	}
	else
	{
		* pu8_Status = Ignition_u8Status ;
	}

	return Local_u8ErrState ;

}
u8 Ignition_u8SetIgntion(u8 u8Status_Copy)
{

	u8 Local_u8ErrState = RT_SUCCESS ;

	if(u8Status_Copy >= IGNITION_u8ON)
	{
		Ignition_u8Status  = u8Status_Copy  ;
	}

	return Local_u8ErrState ;

}
