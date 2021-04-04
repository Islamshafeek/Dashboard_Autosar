/*
 * keypad_cfg.h
 *
 *  Created on: Mar 21, 2021
 *      Author: bibom
 */

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


typedef struct{
	u64 pinNum;		//GPIO_PIN_0 to GPIO_PIN_15
	u64 port;		//GPIO_PORTA to GPIO_PORTI
}keypadCfg_t;

#define ROW_1	(0)
#define ROW_2	(1)
#define ROW_3	(2)
#define ROW_4	(3)

#define COL_1	(0)
#define COL_2	(1)
#define COL_3	(2)
#define COL_4	(3)

#define ROW_1_COL_1		(0 )
#define ROW_1_COL_2		(1 )
#define ROW_1_COL_3		(2 )
#define ROW_1_COL_4		(3 )

#define ROW_2_COL_1		(4 )
#define ROW_2_COL_2		(5 )
#define ROW_2_COL_3		(6 )
#define ROW_2_COL_4		(7 )

#define ROW_3_COL_1		(8 )
#define ROW_3_COL_2		(9 )
#define ROW_3_COL_3		(10)
#define ROW_3_COL_4		(11)

#define ROW_4_COL_1		(12)
#define ROW_4_COL_2		(13)
#define ROW_4_COL_3		(14)
#define ROW_4_COL_4		(15)


#define SPEED_PLUS_ONE		'1'
#define SPEED_MINUS_ONE     '2'
#define IGNITION_ON         '3'
#define SPEED_PLUS_TEN      '4'
#define SPEED_MINUS_TEN     '5'
#define IGNITION_OFF        '6'
#define RIGHT_DOOR_OPEN     '7'
#define LEFT_DOOR_OPEN      '8'
#define SPEED_BREAK         '9'

extern const u8 keypadCfg[8];
extern const u8 keypadkeysCfg[4][4];

#endif /* KEYPAD_CFG_H_ */
