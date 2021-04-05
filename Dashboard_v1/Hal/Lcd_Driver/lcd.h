/*
 * lcd.h
 *
 *  Created on: Mar 20, 2021
 *      Author: bibom
 */

#ifndef LCD_H_
#define LCD_H_


typedef enum
{
	lcdState_idle,
	lcdState_writeData,
	lcdState_writeCommand,
	_lcdState_len_
}lcdState_t;

extern status_RT lcd_init(void);
extern status_RT lcd_writeString(const u8* const str);
extern status_RT lcd_clear(void);
extern status_RT Lcd_WriteChar(u8 Copy_u8Packet, lcdState_t Copy_u8Type);


#endif /* LCD_H_ */
