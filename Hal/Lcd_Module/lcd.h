/*
 * lcd.h
 *
 *  Created on: Mar 20, 2021
 *      Author: bibom
 */

#ifndef LCD_H_
#define LCD_H_

status_RT lcd_init(void);
extern status_RT lcd_writeString(const u8* const str);
extern status_RT lcd_clear(void);

#endif /* LCD_H_ */
