/*
 * Temp_hal.h
 *
 *  Created on: Mar 21, 2021
 *      Author: Mohsen
 */

#ifndef TEMP_HAL_H_
#define TEMP_HAL_H_

u8 Temp_hal_u8Init (void);
u8 Temp_hal_u8SetEngineTemp(void);
u8 Temp_hal_u8GetEngineTemp (u8 * pu8_EngineTemp);

#endif /* TEMP_HAL_H_ */
