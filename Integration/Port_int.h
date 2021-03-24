/*
 * 	 File name: Port_int.h
 *  Created on: Jan 18, 2021
 *      Author: Rdwa Salah
 */

/***************************************************************************
 * File Description:
 * it is a file for Prototypes of the function for the pins
 * The function :
			 * void Port_vidInit();
			 * Port_vidSetPinMode(u8 Copy_u8SwPinId,u8 Copy_u8SwPinMode);
			 * void Port_vidSetPinDir(u8 Copy_u8SwPinId,u8 Copy_u8SwDir);
***************************************************************************/

#ifndef PORT_INT_H_
#define PORT_INT_H_

/* Macros for Pin Mode */
#define PORT_u8OUTPUT_LOW			1
#define PORT_u8OUTPUT_HIGH			2
#define PORT_u8INPUT_HIGH_IMP		3
#define PORT_u8INPUT_PULL_UP		4
/*****************************************************/

/*Hardware pins  ~ Software pins */
/*
#define PORT_u8PIN_1	8		//PB0
#define PORT_u8PIN_2	9       //PB1
#define PORT_u8PIN_3	10      //PB2
#define PORT_u8PIN_4   	11      //PB3
#define PORT_u8PIN_5   	12      //PB4
#define PORT_u8PIN_6   	13      //PB5
#define PORT_u8PIN_7   	14      //PB6
#define PORT_u8PIN_8   	15      //PB7

#define PORT_u8PIN_14   23      //PD0
#define PORT_u8PIN_15   24      //PD1
#define PORT_u8PIN_16   25      //PD2
#define PORT_u8PIN_17   26      //PD3
#define PORT_u8PIN_18   27      //PD4
#define PORT_u8PIN_19   28      //PD5
#define PORT_u8PIN_20   29      //PD6
#define PORT_u8PIN_21   30      //PD7

#define PORT_u8PIN_22   16		//PC0
#define PORT_u8PIN_23   17      //PC1
#define PORT_u8PIN_24   18      //PC2
#define PORT_u8PIN_25   19      //PC3
#define PORT_u8PIN_26   20      //PC4
#define PORT_u8PIN_27   21      //PC5
#define PORT_u8PIN_28   22      //PC6
#define PORT_u8PIN_29   23      //PC7

#define PORT_u8PIN_33   7       //PA7
#define PORT_u8PIN_34   6	    //PA6
#define PORT_u8PIN_35   5       //PA5
#define PORT_u8PIN_36   4       //PA4
#define PORT_u8PIN_37   3       //PA3
#define PORT_u8PIN_38   2       //PA2
#define PORT_u8PIN_39   1	    //PA1
#define PORT_u8PIN_40   0    	//PA0
*/

//Software pins
/*****************************************************/
#define PORT_u8PIN_0	0      //PA0
#define PORT_u8PIN_1	1      //PA1
#define PORT_u8PIN_2	2      //PA2
#define PORT_u8PIN_3    3      //PA3
#define PORT_u8PIN_4    4      //PA4
#define PORT_u8PIN_5    5      //PA5
#define PORT_u8PIN_6    6      //PA6
#define PORT_u8PIN_7    7      //PA7
#define PORT_u8PIN_8    8      //PB0
#define PORT_u8PIN_9    9      //PB1
#define PORT_u8PIN_10   10     //PB2
#define PORT_u8PIN_11   11     //PB3
#define PORT_u8PIN_12   12     //PB4
#define PORT_u8PIN_13   13     //PB5
#define PORT_u8PIN_14   14     //PB6
#define PORT_u8PIN_15   15     //PB7
#define PORT_u8PIN_16   16     //PC0
#define PORT_u8PIN_17   17     //PC1
#define PORT_u8PIN_18   18     //PC2
#define PORT_u8PIN_19   19     //PC3
#define PORT_u8PIN_20   20     //PC4
#define PORT_u8PIN_21   21     //PC5
#define PORT_u8PIN_22   22     //PC6
#define PORT_u8PIN_23   23     //PC7
#define PORT_u8PIN_24   24     //PD0
#define PORT_u8PIN_25   25     //PD1
#define PORT_u8PIN_26   26     //PD2
#define PORT_u8PIN_27   27     //PD3
#define PORT_u8PIN_28   28     //PD4
#define PORT_u8PIN_29   29     //PD5
#define PORT_u8PIN_30   30     //PD6
#define PORT_u8PIN_31   31     //PD7
/*****************************************************/

/* Prototypes of the function in port driver */
/*****************************************************/
void Port_vidInit(void);
void Port_vidSetPinMode(u8 Copy_u8SwPinId,u8 Copy_u8SwPinMode);
void Port_vidSetPinDir(u8 Copy_u8SwPinId,u8 Copy_u8SwDir);
/*****************************************************/

#endif /* PORT_INT_H_ */
