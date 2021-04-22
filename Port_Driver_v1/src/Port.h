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


/** is a type for defining
the direction of a Port Pin.*/
typedef enum {
	PORT_PIN_IN = 0x00,
	PORT_PIN_OUT,
}Port_PinDirectionType;


/** Type of the external data structure containing the initialization data for this module. */
typedef struct {
	uint8_t	PinMode ;
	uint8_t	PinDirection;
	uint8_t	PinLevelInitValue;
}Pin_ConfigType;


typedef enum {
	PORT_PIN_LEVEL_HIGH,
	PORT_PIN_LEVEL_LOW
}PortPinLevelValue;


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

}EcucEnumerationParamDef;

EcucEnumerationParamDef PortPinMode;
EcucEnumerationParamDef PortPinInitialMode;


typedef struct {

	Pin_ConfigType Pin[16] ;

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
void Port_SetPinMode (Port_PinType Pin,Port_PinModeType Mode);



#endif /* PORT_H_ */
