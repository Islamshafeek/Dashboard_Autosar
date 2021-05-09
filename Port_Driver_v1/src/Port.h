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
//typedef uint8_t    Port_PinType;

/** As several port pin modes shall be configurable on one pin,
the range shall be determined by the implementation.
 Different port pin modes */
//typedef uint8_t    Port_PinModeType;


/***************************************Det Errors Type***********************************************/
typedef enum{

	PORT_E_PARAM_PIN			   = 0x0A	,
	PORT_E_DIRECTION_UNCHANGEABLE   ,
	PORT_E_INIT_FAILED              ,
	PORT_E_PARAM_INVALID_MODE       ,
	PORT_E_MODE_UNCHANGEABLE        ,
	PORT_E_UNINIT                   ,
	PORT_E_PARAM_POINTER

}Det_errors;  // -> Det.h   Preffered to be #define


/******************************************************Port_Pin Numbers**********************************************/
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

}Port_PinType;    	   // For all Ports ?????


typedef enum{

	PORT_AF0 ,		// AF0:  (system)
	PORT_AF1 ,		// AF1:  (TIM1/TIM2)
	PORT_AF2 ,		// AF2:  (TIM3..5)
	PORT_AF3 ,		// AF3:  (TIM8..11)
	PORT_AF4 ,		// AF4:  (I2C1..3)
	PORT_AF5 ,		// AF5:  (SPI1/SPI2)
	PORT_AF6 ,		// AF6:  (SPI3)
	PORT_AF7 ,		// AF7:  (USART1..3)
	PORT_AF8 ,		// AF8:  (USART4..6)
	PORT_AF9 ,		// AF9:  (CAN1/CAN2, TIM12..14)
	PORT_AF10 ,		// AF10: (OTG_FS, OTG_HS)
	PORT_AF11 ,		// AF11: (ETH)
	PORT_AF12 ,		// AF12: (FSMC, SDIO, OTG_HS(1))
	PORT_AF13 ,		// AF13: (DCMI)
	PORT_AF14 ,
	PORT_AF15		// AF15: (EVENTOUT)

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
void Port_SetPinMode (Port_PinType Pin,PortPinInitialMode Mode);



#endif /* PORT_H_ */
