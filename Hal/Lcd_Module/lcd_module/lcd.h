/*
 * lcd.h
 *
 *  Created on: Mar 20, 2021
 *      Author: bibom
 */

#ifndef LCD_H_
#define LCD_H_

status_t lcd_init(void);
extern status_t lcd_writeString(const u8* const str);
extern status_t lcd_clear(void);

#endif /* LCD_H_ */
