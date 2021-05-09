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


/******************************************************Port_PinType / Port_Pin Numbers**********************************************/

#define 	PORT_A_PIN_0          0x00   //Sympolic name
#define 	PORT_A_PIN_1          0x01
#define 	PORT_A_PIN_2          0x02
#define 	PORT_A_PIN_3          0x03
#define 	PORT_A_PIN_4          0x04
#define 	PORT_A_PIN_5          0x05
#define 	PORT_A_PIN_6          0x06
#define 	PORT_A_PIN_7          0x07
#define 	PORT_A_PIN_8          0x08
#define 	PORT_A_PIN_9          0x09
#define 	PORT_A_PIN_10         0x0A
#define 	PORT_A_PIN_11         0x0B
#define 	PORT_A_PIN_12         0x0C
#define 	PORT_A_PIN_13         0x0D
#define 	PORT_A_PIN_14         0x0E
#define 	PORT_A_PIN_15         0x0F
#define 	PORT_B_PIN_0          0x10
#define 	PORT_B_PIN_1          0x11
#define 	PORT_B_PIN_2          0x12
#define 	PORT_B_PIN_3          0x13
#define 	PORT_B_PIN_4          0x14
#define 	PORT_B_PIN_5          0x15
#define 	PORT_B_PIN_6          0x16
#define 	PORT_B_PIN_7          0x17
#define 	PORT_B_PIN_8          0x18
#define 	PORT_B_PIN_9          0x19
#define 	PORT_B_PIN_10         0x1A
#define 	PORT_B_PIN_11         0x1B
#define 	PORT_B_PIN_12         0x1C
#define 	PORT_B_PIN_13         0x1D
#define 	PORT_B_PIN_14         0x1E
#define 	PORT_B_PIN_15         0x1F
#define 	PORT_C_PIN_0          0x20
#define 	PORT_C_PIN_1          0x21
#define 	PORT_C_PIN_2          0x22
#define 	PORT_C_PIN_3          0x23
#define 	PORT_C_PIN_4          0x24
#define 	PORT_C_PIN_5          0x25
#define 	PORT_C_PIN_6          0x26
#define 	PORT_C_PIN_7          0x27
#define 	PORT_C_PIN_8          0x28
#define 	PORT_C_PIN_9          0x29
#define 	PORT_C_PIN_10         0x2A
#define 	PORT_C_PIN_11         0x2B
#define 	PORT_C_PIN_12         0x2C
#define 	PORT_C_PIN_13         0x2D
#define 	PORT_C_PIN_14         0x2E
#define 	PORT_C_PIN_15         0x2F
#define 	PORT_D_PIN_0          0x30
#define 	PORT_D_PIN_1          0x31
#define 	PORT_D_PIN_2          0x32
#define 	PORT_D_PIN_3          0x33
#define 	PORT_D_PIN_4          0x34
#define 	PORT_D_PIN_5          0x35
#define 	PORT_D_PIN_6          0x36
#define 	PORT_D_PIN_7          0x37
#define 	PORT_D_PIN_8          0x38
#define 	PORT_D_PIN_9          0x39
#define 	PORT_D_PIN_10         0x3A
#define 	PORT_D_PIN_11         0x3B
#define 	PORT_D_PIN_12         0x3C
#define 	PORT_D_PIN_13         0x3D
#define 	PORT_D_PIN_14         0x3E
#define 	PORT_D_PIN_15         0x3F
#define 	PORT_E_PIN_0          0x40
#define 	PORT_E_PIN_1          0x41
#define 	PORT_E_PIN_2          0x42
#define 	PORT_E_PIN_3          0x43
#define 	PORT_E_PIN_4          0x44
#define 	PORT_E_PIN_5          0x45
#define 	PORT_E_PIN_6          0x46
#define 	PORT_E_PIN_7          0x47
#define 	PORT_E_PIN_8          0x48
#define 	PORT_E_PIN_9          0x49
#define 	PORT_E_PIN_10         0x4A
#define 	PORT_E_PIN_11         0x4B
#define 	PORT_E_PIN_12         0x4C
#define 	PORT_E_PIN_13         0x4D
#define 	PORT_E_PIN_14         0x4E
#define 	PORT_E_PIN_15         0x4F
#define 	PORT_H_PIN_0          0x50
#define 	PORT_H_PIN_1          0x51

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

	uint8_t	PinMode ;										//AF_Register
	uint8_t	PinDirection;  									// ModeRegister
	uint8_t	PinLevelInitValue;
	uint8_t PinInternalPullUp ;								// PUPD_Register
	uint8_t PinSpeed ;										//Speed_Register
	uint8_t PinOType ;										// Open_Drain - Push Pull
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
void Port_SetPinDirection (uint8_t Pin,Port_PinDirectionType Direction);



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
void Port_SetPinMode (uint8_t Pin,PortPinInitialMode Mode);



#endif /* PORT_H_ */
