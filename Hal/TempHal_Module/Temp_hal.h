/*
 * Temp_hal.h
 *
 *  Created on: Mar 21, 2021
 *      Author: Mohsen
 */

#ifndef TEMP_HAL_H_
#define TEMP_HAL_H_

uint8_t Temp_hal_u8Init (void);
uint8_t Temp_hal_u8SetEngineTemp(void);
uint8_t Temp_hal_u8GetEngineTemp (uint8_t * pu8_EngineTemp);

#endif /* TEMP_HAL_H_ */
