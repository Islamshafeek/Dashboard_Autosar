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

typedef enum{
	RowNo_1,
	RowNo_2,
	_RowNo_len_
}RowNo_e;

typedef enum{
	ColNo_1		,
	ColNo_2     ,
	ColNo_3     ,
	ColNo_4     ,
	ColNo_5     ,
	ColNo_6     ,
	ColNo_7     ,
	ColNo_8     ,
	ColNo_9     ,
	ColNo_10    ,
	ColNo_11    ,
	ColNo_12    ,
	ColNo_13    ,
	ColNo_14    ,
	ColNo_15    ,
	ColNo_16    ,
	_ColNo_len_
}ColNo_e;

extern status_RT lcd_init(void);
extern status_RT lcd_writeString(const u8* const str);
extern status_RT lcd_clear(void);
extern status_RT Lcd_WriteChar(u8 Copy_u8Packet, lcdState_t Copy_u8Type);
extern status_RT Lcd_GoTo(RowNo_e RowNo, ColNo_e ColNo);

#endif /* LCD_H_ */
