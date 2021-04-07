/*
 * tmep.c
 *
 *  Created on: Mar 21, 2021
 *      Author: Farid
 */

#include "../../Lib/STD_TYPES.h"
#include "../../Lib/Status.h"
#include "../../Hal/TempHal_Driver/TempHal.h"
#include "temp.h"


static tempState_t Temp_u8currentTemp ;

u8 Temp_GetTemp(tempState_t* pstr_temp)
{
	u8 err_status = RT_SUCCESS ;

	if(pstr_temp)
	{
		pstr_temp ->temp_val    = Temp_u8currentTemp.temp_val      ;
		pstr_temp ->time_state = Temp_u8currentTemp.time_state ;
	}
	else
	{
		err_status = RT_PARAM ;
	}
	return err_status ;
}
u8 Temp_SetTemp(tempState_t* pstr_temp)
{
	u8 err_status = RT_SUCCESS ;

	if(pstr_temp)
	{
		Temp_u8currentTemp.temp_val = pstr_temp ->temp_val ;
		Temp_u8currentTemp.time_state= pstr_temp ->time_state ;
	}
	else
	{
		err_status = RT_PARAM ;
	}
	return err_status ;

}
