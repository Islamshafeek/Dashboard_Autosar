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


typedef struct {

Pin_ConfigType Pin[16] ;

}Port_ConfigType;



/************************************************************************************
* Service Name: xxx
* Service ID[hex]: xxx
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): xxx
* Parameters (out): xxx
* Return value: Std_ReturnType (E_OK - E_NOT_OK)
* Description:xxx
************************************************************************************/
void Port_SetPinDirection (Port_PinType Pin,Port_PinDirectionType Direction);


/************************************************************************************
* Service Name: xxx
* Service ID[hex]: xxx
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): xxx
* Parameters (out): xxx
* Return value: Std_ReturnType (E_OK - E_NOT_OK)
* Description:xxx
************************************************************************************/
void Port_Init (const Port_ConfigType* ConfigPtr);

/************************************************************************************
* Service Name: xxx
* Service ID[hex]: xxx
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): xxx
* Parameters (out): xxx
* Return value: Std_ReturnType (E_OK - E_NOT_OK)
* Description:xxx
************************************************************************************/

void Port_GetVersionInfo (Std_VersionInfoType* versioninfo);

/************************************************************************************
* Service Name: xxx
* Service ID[hex]: xxx
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): xxx
* Parameters (out): xxx
* Return value: Std_ReturnType (E_OK - E_NOT_OK)
* Description:xxx
************************************************************************************/

void Port_SetPinMode (Port_PinType Pin,Port_PinModeType Mode);



#endif /* PORT_H_ */
