/*
 * lcd_cfg.h
 *
 *  Created on: Mar 20, 2021
 *      Author: bibom
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define	LCD_MODE_8BIT		(0)
#define	LCD_MODE_4BIT		(1)

#define LCD_MODE			LCD_MODE_8BIT

#if LCD_MODE == LCD_MODE_8BIT
#define PIN_NUM		(10)
#elif  LCD_MODE == LCD_MODE_4BIT
#define PIN_NUM		(6)
#endif

#define RS 	(0)
#define EN	(1)
#define D7	(2)
#define D6	(3)
#define D5	(4)
#define D4	(5)
#if LCD_MODE == LCD_MODE_8BIT
#define D3	(6)
#define D2	(7)
#define D1	(8)
#define D0	(9)
#endif


#endif /* LCD_CFG_H_ */
