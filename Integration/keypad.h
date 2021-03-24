/*
 * keypad.h
 *
 *  Created on: Mar 21, 2021
 *      Author: bibom
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define LCD_NO_KEY	(0xFF)

status_RT keypad_init(void);

status_RT keypad_getKey(u8* key);



#endif /* KEYPAD_H_ */
