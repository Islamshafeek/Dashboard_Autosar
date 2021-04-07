/*
 * temp.h
 *
 *  Created on: Mar 21, 2021
 *      Author: Farid
 */

#ifndef APP_TEMP_TEMP_H_
#define APP_TEMP_TEMP_H_


typedef enum {
	time_ok,
	time_out
}timeState_e;

typedef struct {
	u8 temp_val ;
	timeState_e time_state ;
}tempState_t;


u8 Temp_GetTemp(tempState_t* pstr_temp);
u8 Temp_SetTemp(tempState_t* pstr_temp);

#endif /* APP_TEMP_TEMP_H_ */
