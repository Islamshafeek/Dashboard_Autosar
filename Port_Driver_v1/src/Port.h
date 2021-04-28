/*
 * Port.h
 *
 *  Created on: Apr 22, 2021
 *      Author: Islam
 */

#ifndef PORT_H_
#define PORT_H_


/**Shall cover all available port pins. The type should be chosen
for the specific MCU platform (best performance)
shall be used for the symbolic name of a Port Pin.*/
typedef uint8_t    Port_PinType;

/** As several port pin modes shall be configurable on one pin,
the range shall be determined by the implementation.
 Different port pin modes */
typedef uint8_t    Port_PinModeType;



typedef enum{

	PORT_A_PIN_0  = 0x00    ,  //Sympolic name
	PORT_A_PIN_1    ,
	PORT_A_PIN_2    ,
	PORT_A_PIN_3    ,
	PORT_A_PIN_4    ,
	PORT_A_PIN_5    ,
	PORT_A_PIN_6    ,
	PORT_A_PIN_7    ,
	PORT_A_PIN_8    ,
	PORT_A_PIN_9    ,
	PORT_A_PIN_10   ,
	PORT_A_PIN_11   ,
	PORT_A_PIN_12   ,
	PORT_A_PIN_13   ,
	PORT_A_PIN_14   ,
	PORT_A_PIN_15   ,
	PORT_B_PIN_0    ,
	PORT_B_PIN_1    ,
	PORT_B_PIN_2    ,
	PORT_B_PIN_3    ,
	PORT_B_PIN_4    ,
	PORT_B_PIN_5    ,
	PORT_B_PIN_6    ,
	PORT_B_PIN_7    ,
	PORT_B_PIN_8    ,
	PORT_B_PIN_9    ,
	PORT_B_PIN_10   ,
	PORT_B_PIN_11   ,
	PORT_B_PIN_12   ,
	PORT_B_PIN_13   ,
	PORT_B_PIN_14   ,
	PORT_B_PIN_15   ,
	PORT_C_PIN_0    ,
	PORT_C_PIN_1    ,
	PORT_C_PIN_2    ,
	PORT_C_PIN_3    ,
	PORT_C_PIN_4    ,
	PORT_C_PIN_5    ,
	PORT_C_PIN_6    ,
	PORT_C_PIN_7    ,
	PORT_C_PIN_8    ,
	PORT_C_PIN_9    ,
	PORT_C_PIN_10   ,
	PORT_C_PIN_11   ,
	PORT_C_PIN_12   ,
	PORT_C_PIN_13   ,
	PORT_C_PIN_14   ,
	PORT_C_PIN_15   ,
	PORT_D_PIN_0    ,
	PORT_D_PIN_1    ,
	PORT_D_PIN_2    ,
	PORT_D_PIN_3    ,
	PORT_D_PIN_4    ,
	PORT_D_PIN_5    ,
	PORT_D_PIN_6    ,
	PORT_D_PIN_7    ,
	PORT_D_PIN_8    ,
	PORT_D_PIN_9    ,
	PORT_D_PIN_10   ,
	PORT_D_PIN_11   ,
	PORT_D_PIN_12   ,
	PORT_D_PIN_13   ,
	PORT_D_PIN_14   ,
	PORT_D_PIN_15   ,
	PORT_E_PIN_0    ,
	PORT_E_PIN_1    ,
	PORT_E_PIN_2    ,
	PORT_E_PIN_3    ,
	PORT_E_PIN_4    ,
	PORT_E_PIN_5    ,
	PORT_E_PIN_6    ,
	PORT_E_PIN_7    ,
	PORT_E_PIN_8    ,
	PORT_E_PIN_9    ,
	PORT_E_PIN_10   ,
	PORT_E_PIN_11   ,
	PORT_E_PIN_12   ,
	PORT_E_PIN_13   ,
	PORT_E_PIN_14   ,
	PORT_E_PIN_15   ,
	PORT_H_PIN_0    ,
	PORT_H_PIN_1

}Port_PinType_t;    	   // For all Ports ?????


typedef enum{

	PORT_PIN_MODE_ADC,
	PORT_PIN_MODE_CAN,
	PORT_PIN_MODE_DIO,
	PORT_PIN_MODE_DIO_GPT,
	PORT_PIN_MODE_DIO_WDG,
	PORT_PIN_MODE_FLEXRAY,
	PORT_PIN_MODE_ICU,
	PORT_PIN_MODE_LIN,
	PORT_PIN_MODE_MEM,
	PORT_PIN_MODE_PWM,
	PORT_PIN_MODE_SPI,

}PortPinInitialMode;

//EcucEnumerationParamDef PortPinMode;
//EcucEnumerationParamDef PortPinInitialMode;

/** is a type for defining
the direction of a Port Pin.*/
typedef enum {

	PORT_PIN_IN ,
	PORT_PIN_OUT,
	PORT_PIN_ANALOG,
	PORT_PIN_AF

}Port_PinDirectionType;

typedef enum {

	PORT_PIN_LEVEL_LOW,
	PORT_PIN_LEVEL_HIGH

}PortPinLevelValue;

typedef enum {

	PORT_PIN_INTERNAL_FLOATING,
	PORT_PIN_INTERNAL_PULL_UP ,
	PORT_PIN_INTERNAL_PULL_DOWN

}PortPinInternalPullUp;

typedef enum{
 PORT_PIN_OUTPUT_PUSH_PULL    =   0x00,
 PORT_PIN_OUTPUT_OPEN_DRAIN
}PortPinOType;

typedef enum {
PORT_PIN_SPEED_LOW            =  0x00,
PORT_PIN_SPEED_MEDIUM         ,
PORT_PIN_SPEED_HIGH           ,
PORT_PIN_SPEED_V_HIGH
}PortPinOSpeed;


/** Type of the external data structure containing the initialization data for this module. */
typedef struct {

	uint8_t	PinMode ;			//AF_Register
	uint8_t	PinDirection;  		// ModeRegister
	uint8_t	PinLevelInitValue;
	uint8_t PinInternalPullUp ;	// PUPD_Register
	uint8_t PinSpeed ;			//Speed_Register
	uint8_t PinOType ;			// Open_Drain - Push Pull
	uint8_t PinDirectionChangeableDuringRuntime;
	uint8_t PortModeChangeableDuringRuntime;

}Port_ConfigType;

typedef struct {
	uint32_t Gpio_Mode 		;
	uint32_t Gpio_OType 	;
	uint32_t Gpio_OSpeed 	;
	uint32_t Gpio_PUPD 		;
	uint32_t Gpio_AF 		;
	void * Gpio_Port 		;
	uint32_t Gpio_PinNum 	;
}Pincfg_t;

//typedef struct {
//
//	Pin_ConfigType Pin[16] ;
//
//}Port_ConfigType;



/************************************************************************************
 * Service Name: Port_Init
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr ,,,:>> Pointer to configuration set.
 * Parameters (out): None
 * Return value: None
 * Description: Initializes the Port Driver module.
 ************************************************************************************/
void Port_Init (const Port_ConfigType* ConfigPtr);




/************************************************************************************
 * Service Name: Port_SetPinDirection
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in):
 * 					- Pin       ,,,:>> Port Pin ID number
 * 					- Direction ,,,:>>> Port Pin Direction
 * Parameters (out): None
 * Return value: None
 * Description: Sets the port pin direction
 ************************************************************************************/
void Port_SetPinDirection (Port_PinType Pin,Port_PinDirectionType Direction);



/************************************************************************************
 * Service Name: Port_RefreshPortDirection
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Refreshes port direction.
 ************************************************************************************/
void Port_RefreshPortDirection (void);



/************************************************************************************
 * Service Name: Port_GetVersionInfo
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (out): versioninfo ,,,:>>>Pointer to where to store the version information of this module.
 * Return value: None
 * Description: Returns the version information of this module.
 ************************************************************************************/
void Port_GetVersionInfo (Std_VersionInfoType* versioninfo);




/************************************************************************************
 * Service Name: Port_SetPinMode
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Sets the port pin mode
 ************************************************************************************/
void Port_SetPinMode (Port_PinType Pin,Port_PinModeType Mode);



#endif /* PORT_H_ */
