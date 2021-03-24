/* Dio_Driver v2 using SWPins 0 ->> 31 */

#include "Std_Types.h"
#include "Bit_Math.h"
#include "ATmega32_Registers.h"
/*****************************************************/
#include "Dio_int.h"
/*****************************************************/

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
void Dio_vidSetPinVal(u8 Copy_u8SwPinId, u8 Copy_u8SwPinVal)
{
	u8 Loc_u8PortId; //Local u8 Port Id
	u8 Loc_u8PinId;	//Local u8 Pin Id

	Loc_u8PortId = Copy_u8SwPinId / 8; //To get the port id, 0,1,2,3
	Loc_u8PinId =  Copy_u8SwPinId % 8; //To get the pin id, 0 ->> 31

	//DIO_u8HIGH = 1 and DIO_u8LOW = 0
	switch(Loc_u8PortId)
	{
	case 0: // 0 = __PORTA
		if(Copy_u8SwPinVal == DIO_u8HIGH)
		{
			SET_BIT(_PORTA,Loc_u8PinId); //set the pin in port A with High value
		}
		else
		{
			CLR_BIT(_PORTA,Loc_u8PinId); //set the pin in port A with Low value
		}
		break;
	case 1: // 1 = _PORTB
		if(Copy_u8SwPinVal == DIO_u8HIGH)
		{
			SET_BIT(_PORTB,Loc_u8PinId); //set the pin in port A with High value
		}
		else
		{
			CLR_BIT(_PORTB,Loc_u8PinId); //set the pin in port A with Low value
		}
		break;
	case 2: // 2 = _PORTC
		if(Copy_u8SwPinVal == DIO_u8HIGH)
		{
			SET_BIT(_PORTC,Loc_u8PinId); //set the pin in port A with High value
		}
		else
		{
			CLR_BIT(_PORTC,Loc_u8PinId); //set the pin in port A with Low value
		}
		break;
	case 3: // 3 = __PORTD
		if(Copy_u8SwPinVal == DIO_u8HIGH)
		{
			SET_BIT(_PORTD,Loc_u8PinId); //set the pin in port A with High value
		}
		else
		{
			CLR_BIT(_PORTD,Loc_u8PinId); //set the pin in port A with Low value
		}
		break;
	default:
		break;
	}
}

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
u8 Dio_u8GetPinVal(u8 Copy_u8SwPinId)
{
	u8 Loc_u8returnVal;

	u8 Loc_u8PortId; //Local u8 Port Id
	u8 Loc_u8PinId;	//Local u8 Pin Id

	Loc_u8PortId = Copy_u8SwPinId / 8; //To get the port id, 0,1,2,3
	Loc_u8PinId =  Copy_u8SwPinId % 8; //To get the pin id, 0 ->> 31

	//DIO_u8HIGH = 1 and DIO_u8LOW = 0
	switch(Loc_u8PortId)
	{
	case 0: // 0 = _PORTA

		Loc_u8returnVal = GET_BIT(_PINA,Loc_u8PinId); //read the pin value
		break;
	case 1: // 1 = _PORTB

		Loc_u8returnVal = GET_BIT(_PINB,Loc_u8PinId); //read the pin value
		break;
	case 2: // 2 = _PORTC

		Loc_u8returnVal = GET_BIT(_PINC,Loc_u8PinId); //read the pin value
		break;
	case 3: // 3 = _PORTD
		//read the required pin value in portD and assign it's value
		Loc_u8returnVal = GET_BIT(_PIND,Loc_u8PinId);
		break;
	default:
		break;
	}

	return Loc_u8returnVal;
}

void Dio_u8TogglePin(u8 Copy_u8SwPinId)
{
	u8 Loc_u8PortId; //Local u8 Port Id
	u8 Loc_u8PinId;	//Local u8 Pin Id

	Loc_u8PortId = Copy_u8SwPinId / 8; //To get the port id, 0,1,2,3
	Loc_u8PinId =  Copy_u8SwPinId % 8; //To get the pin id, 0 ->> 31

	switch(Loc_u8PortId)
	{
	case 0: // 0 = _PORTA
		//Toggle the required pin in portA
		TGL_BIT(_PORTA,Loc_u8PinId);
		break;

	case 1: // 1 = _PORTB
		//Toggle the required pin in portB
		TGL_BIT(_PORTB,Loc_u8PinId);
		break;

	case 2: // 2 = _PORTC
		//Toggle the required pin in portC
		TGL_BIT(_PORTC,Loc_u8PinId);
		break;

	case 3: // 3 = _PORTD
		//Toggle the required pin in portD
		TGL_BIT(_PORTD,Loc_u8PinId);
		break;

	default:
		break;
	}
}

