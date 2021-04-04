

#ifndef DIO_INT_H_
#define DIO_INT_H_
/******************************************************/
/*
 * These macros are used to: set pin directions
 *  These macros are used only in function: Dio_vidSetPinDir
 * for example:
 * 	set pin 0 direction as output ->> Dio_vidSetPinDir(DIO_u8PIN_0 , DIO_u8OUTPUT);
 */

#define DIO_u8OUTPUT 1
#define DIO_u8INPUT 0
/******************************************************/

/*
 * These macros are used to: set pin value
 *  These macros are used only in function: Dio_vidSetPinVal
 * for example:
 * Set pin 0 as High Dio_vidSetPinDir(DIO_u8PIN_0 , DIO_u8HIGH);
 */
#define DIO_u8HIGH 1
#define DIO_u8LOW 0
/******************************************************/

/*
 * These macros are used to: use the pins as SoftWare pins
 *  These macros are used in functions:
								 *  u8GetPinVal
								 *  Dio_vidSetPinVal
								 *  Dio_vidSetPinDir
 * for example:
 * Get the value of pin 0 ->> Dio_u8GetPinVal(DIO_u8PIN_0);
 */
#define DIO_u8PIN_0    0	//PA0
#define DIO_u8PIN_1    1    //PA1
#define DIO_u8PIN_2    2    //PA2
#define DIO_u8PIN_3    3    //PA3
#define DIO_u8PIN_4    4    //PA4
#define DIO_u8PIN_5    5    //PA5
#define DIO_u8PIN_6    6    //PA6
#define DIO_u8PIN_7    7    //PA7
#define DIO_u8PIN_8    8    //PB0
#define DIO_u8PIN_9    9    //PB1
#define DIO_u8PIN_10   10   //PB2
#define DIO_u8PIN_11   11   //PB3
#define DIO_u8PIN_12   12   //PB4
#define DIO_u8PIN_13   13   //PB5
#define DIO_u8PIN_14   14   //PB6
#define DIO_u8PIN_15   15   //PB7
#define DIO_u8PIN_16   16   //PC0
#define DIO_u8PIN_17   17   //PC1
#define DIO_u8PIN_18   18   //PC2
#define DIO_u8PIN_19   19   //PC3
#define DIO_u8PIN_20   20   //PC4
#define DIO_u8PIN_21   21   //PC5
#define DIO_u8PIN_22   22   //PC6
#define DIO_u8PIN_23   23   //PC7
#define DIO_u8PIN_24   24   //PD0
#define DIO_u8PIN_25   25   //PD1
#define DIO_u8PIN_26   26   //PD2
#define DIO_u8PIN_27   27   //PD3
#define DIO_u8PIN_28   28   //PD4
#define DIO_u8PIN_29   29   //PD5
#define DIO_u8PIN_30   30   //PD6
#define DIO_u8PIN_31   31   //PD7
/******************************************************/

/* ******************************************************************************************
 Function Description:
 * Function name: Dio_vidSetPinDir
 * Description: This function is used to change the SW pin direction
 * Input Parameters:
 * 					1- Copy_u8SwPinId : in range {DIO_u8Pin_0, DIO_u8Pin_31}
 * 					2- Copy_u8SwPinDir : in range {DIO_u8INPUT, DIO_u8OUTPUT}
 * Return:
 *					-Not applicable (void)
 *
 * Input/Output Parameter:
 *					-Not applicable
 * ******************************************************************************************
 */
void Dio_vidSetPinDir(u8 Copy_u8SwPinId, u8 Copy_u8SwPinDir);

/* ******************************************************************************************
 Function Description:
 * Function name: Dio_vidSetPinVal
 * Description: This function is used to change the SW pin value
 * Input Parameters:
 * 					1- Copy_u8SwPinId: in range {DIO_u8Pin_0, DIO_u8Pin_31}
 *  				2- Copy_u8SwPinVal:  in range {DIO_u8OUTPUT, DIO_u8INPUT}
 * Return:
 *					-Not applicable (void)
 * Input/Output Parameter:
 *					-Not applicable (void)
 * **************************************************************************************
 */
void Dio_vidSetPinVal(u8 Copy_u8SwPinId, u8 Copy_u8SwPinVal);

/* ******************************************************************************************
 Function Description:
 * Function name: Dio_u8GetPinVal
 * Description: This function is used to read the SW pin value
 * Input Parameters:
 * 					1- Copy_u8SwPinId: in range {DIO_u8Pin_0, DIO_u8Pin_31}
 * Return:
 *					1- 1 for DIO_u8HIGH
 *					2- 0 for DIO_u8LOW
 * Input/Output Parameter:
 *					-Not applicable (void)
 * **************************************************************************************
 */
u8 Dio_u8GetPinVal(u8 Copy_u8SwPinId);
/* ******************************************************************************************
 Function Description:
 * Function name: Dio_u8Dio_u8TogglePin
 * Description: This function is used to toggle the SW pin value
 * Input Parameters:
 * 					1- Copy_u8SwPinId: in range {DIO_u8Pin_0, DIO_u8Pin_31}
 * Return:
 **					-Not applicable (void)
 * Input/Output Parameter:
 *					-Not applicable
 * **************************************************************************************
 */
void Dio_u8TogglePin(u8 Copy_u8SwPinId);

#endif /* DIO_INT_H_ */
