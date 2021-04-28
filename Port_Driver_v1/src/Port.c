/*
 * Port.c
 *
 *  Created on: Apr 22, 2021
 *      Author: Islam
 */

#include <stdint.h>
#include <stddef.h>
#include "diag/Trace.h"
#include "Std_Types.h"
#include "Bits.h"
#include "Bit_Math.h"
#include "RT_Debug.h"
#include "stm32f407_Registers.h"
#include "Port_Lcfg.h"
#include "Port_cfg.h"
#include "Port.h"


/*****************************************Ragisters Addresses*************************************************************/

// BaseAdrress of GPIOA Peripheral*****************************************************
#define 	GPIOA								   ((void *)0x40020000)

// BaseAdrress of GPIOB Peripheral*****************************************************
#define 	GPIOB								   ((void *)0x40020400)

// BaseAdrress of GPIOC Peripheral*****************************************************
#define 	GPIOC						           ((void *)0x40020800)

// BaseAdrress of GPIOD Peripheral*****************************************************
#define 	GPIOD						           ((void *)0x40020C00)

// BaseAdrress of GPIOE Peripheral*****************************************************
#define 	GPIOE					 	           ((void *)0x40021000)

// BaseAdrress of GPIOH Peripheral*****************************************************
#define 	GPIOH						           ((void *)0x40021C00)


//**************************************Registers Masks****************************************************/

//	Input Mode Mask *******************************************************************
#define 	GPIO_MODE_INPUT						    BIT_CLR   //0x00

//	Output Mode Mask ******************************************************************
#define 	GPIO_MODE_OUTPUT					    BIT_0    //0x01

//	AF Mode Mask **********************************************************************
#define 	GPIO_MODE_AF						    BIT_1    //0x02

//	Analog Mode Mask ******************************************************************
#define 	GPIO_MODE_ANALOG					    (BIT_0 | BIT_1)    //0x03


//	Push-Pull OType Mask *************************************************************
#define 	GPIO_OTYPE_PUSH_PULL					BIT_CLR      //0x00

//	Open Drain OType Mask ************************************************************
#define 	GPIO_OTYPE_OPEN_DRAIN				    BIT_0      			//0x01

// Low_speed OSPEED Mask***************************************************************
#define		GPIO_OSPEED_LOW_SPEED			 	    BIT_CLR      		//0x00

// Medium_speed OSPEED Mask************************************************************
#define		GPIO_OSPEED_MEDIUM_SPEED				BIT_0       		//0x01

// High_speed OSPEED Mask**************************************************************
#define		GPIO_OSPEED_HIGH_SPEED				    BIT_1      			//0x02

// Veryhigh_speed OSPEED Mask**********************************************************
#define		GPIO_OSPEED_VERY_HIGH_SPEED			    (BIT_0 | BIT_1)       //0x03


// Floating PUPD Mask******************************************************************
#define		GPIO_PUPD_FLOATING					    BIT_CLR           	//0x00

// PullUp PUPD Mask********************************************************************
#define		GPIO_PUPD_PULL_UP					    BIT_0           	 //0x01

// PullDown PUPD Mask******************************************************************
#define		GPIO_PUPD_PULL_DOWN					    BIT_1             	//0x02


//**************************************Registers Clear Masks****************************************************/

// Clear Mask for MODE Register**************************************************
#define 	GPIO_MODE_CLR	 				(uint32_t)(BIT_0 | BIT_1)

//	Clear Mask for OTYPE Register************************************************
#define 	GPIO_OTYPE_CLR					((uint32_t)BIT_0)

// Clear Mask for OSPEDD Register************************************************
#define 	GPIO_OSPEED_CLR	 				(uint32_t)(BIT_0 | BIT_1)

// Clear Mask for PUPD Register***************************************************
#define		GPIO_PUPD_CLR					(uint32_t)(BIT_0 | BIT_1)

// Clear Mask for AF Registers***************************************************
#define		GPIO_AF_CLR						(uint32_t)(BIT_0 | BIT_1 | BIT_2 | BIT_3)





/**************************************Mapping Between Registers Address and Port Idx******************************************/
Gpio_t * PortsAdd[PORT_PIN_NUMBER] = {

		(Gpio_t*)GPIOA ,
		(Gpio_t*)GPIOB,
		(Gpio_t*)GPIOC,
		(Gpio_t*)GPIOD,
		(Gpio_t*)GPIOE,
		(Gpio_t*)GPIOH

};




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
void Port_Init (const Port_ConfigType* ConfigPtr){

	if (ConfigPtr != NULL ){


		uint32_t Local_Reg			= 0 ;

		for ( uint8_t PortIdx = 0 ; PortIdx < PORT_PIN_NUMBER ; PortIdx++ ){

				if ( ConfigPtr[PortIdx].PinDirection  == PORT_PIN_OUT || ConfigPtr[PortIdx].PinDirection  == PORT_PIN_IN ||  ConfigPtr[PortIdx].PinDirection  == PORT_PIN_ANALOG ||  ConfigPtr[PortIdx].PinDirection  == PORT_PIN_AF  ){

					if(ConfigPtr[PortIdx].PinDirection  == GPIO_MODE_OUTPUT){

						if (ConfigPtr[PortIdx].PinLevelInitValue ==  PORT_PIN_LEVEL_HIGH){

							PortsAdd[PortIdx/16] -> BSRR =  1 << PortIdx%16 ;

						}
						else {

							PortsAdd[PortIdx/16] -> BSRR =  1 << ((PortIdx%16) + 16) ;
						}
					}

					Local_Reg		= PortsAdd[PortIdx/16] -> MODER ;
					Local_Reg	 	&= ~(GPIO_MODE_CLR << (PortIdx%16 << 1))  ;
					Local_Reg	 	|= (ConfigPtr[PortIdx].PinDirection << ((PortIdx%16) << 1)) ;
					PortsAdd[PortIdx/16] -> MODER =  Local_Reg ;
				}
				//					else{
				//						return RT_PARAM ;
				//					}

				if (ConfigPtr[PortIdx].PinDirection == PORT_PIN_OUT || ConfigPtr[PortIdx].PinDirection == PORT_PIN_AF){
					if( ConfigPtr[PortIdx].PinOType == PORT_PIN_OUTPUT_PUSH_PULL || ConfigPtr[PortIdx].PinOType == PORT_PIN_OUTPUT_OPEN_DRAIN){

						PortsAdd[PortIdx/16] ->OTYPER =  ConfigPtr[PortIdx].PinOType;
						Local_Reg		= PortsAdd[PortIdx/16] ->OTYPER ;
						Local_Reg	 	&= ~(GPIO_MODE_CLR << PortIdx%16 )  ;
						Local_Reg	 	|= (ConfigPtr[PortIdx].PinOType << (PortIdx%16) ) ;
						PortsAdd[PortIdx/16] -> OTYPER =  Local_Reg ;
					}
					//						else{
					//							return RT_PARAM ;
					//						}

					if ( ConfigPtr[PortIdx].PinSpeed == PORT_PIN_SPEED_LOW
							||  ConfigPtr[PortIdx].PinSpeed  == PORT_PIN_SPEED_MEDIUM
							||   ConfigPtr[PortIdx].PinSpeed  == PORT_PIN_SPEED_HIGH
							||   ConfigPtr[PortIdx].PinSpeed  == PORT_PIN_SPEED_V_HIGH ){

						Local_Reg		= PortsAdd[PortIdx/16] -> OSPEEDR  ;
						Local_Reg		&= ~(GPIO_OSPEED_CLR << (PortIdx%16 << 1))  ;
						Local_Reg 		|= (ConfigPtr[PortIdx].PinSpeed << ((PortIdx%16) << 1)) ;
						PortsAdd[PortIdx/16] -> OSPEEDR = Local_Reg ;
					}
					//						else{
					//							return RT_PARAM ;
					//						}
				}

				switch (ConfigPtr[PortIdx].PinDirection){
				case  PORT_PIN_ANALOG:
					Local_Reg		=  PortsAdd[PortIdx/16] -> PUPDR ;
					Local_Reg  	 	&= ~(GPIO_PUPD_CLR << (PortIdx%16 << 1))  ;
					Local_Reg   	|= ( PORT_PIN_INTERNAL_FLOATING << ((PortIdx%16) << 1)) ;
					PortsAdd[PortIdx/16] -> PUPDR	=  Local_Reg ;
					break;
				default :
					if (ConfigPtr[PortIdx].PinInternalPullUp == PORT_PIN_INTERNAL_FLOATING
							||  ConfigPtr[PortIdx].PinInternalPullUp == PORT_PIN_INTERNAL_PULL_UP
							||  ConfigPtr[PortIdx].PinInternalPullUp == PORT_PIN_INTERNAL_PULL_DOWN ){

						Local_Reg		=  PortsAdd[PortIdx/16] -> PUPDR ;
						Local_Reg  	 	&= ~(GPIO_PUPD_CLR << (PortIdx%16 << 1))  ;
						Local_Reg   	|= ( ConfigPtr[PortIdx].PinInternalPullUp << ((PortIdx%16) << 1)) ;
						PortsAdd[PortIdx/16] -> PUPDR	=  Local_Reg ;
					}
					//						ELSE{
					//							RETURN RT_PARAM ;
					//						}
					break;
				}

//				if (ConfigPtr[PortIdx].PinDirection == PORT_PIN_AF){
//					if (AF <= GPIO_AF15){
//
//						Local_Reg			  = Port -> AFR[PortIdx%16 >> 3] ;
//						Local_Reg 			  &= ~(GPIO_AF_CLR << (PortIdx%16 << 2)) ;
//						Local_Reg			  |= (AF << (PortIdx%16 << 2)) ;
//						Port -> AFR[PortIdx%16 >> 3] = Local_Reg ;
//					}
//					//						else{
//					//							return RT_PARAM ;
//					//						}
//				}
			}
			//				else
			//					return RT_PARAM ;
		}
		//			else
		//				return RT_PARAM ;
		//
		//			return RT_SUCCESS ;

	}







#if PORT_SET_PIN_DIRECTION_API == STD_ON
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
void Port_SetPinDirection (Port_PinType Pin,Port_PinDirectionType Direction){





}
#endif

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
void Port_RefreshPortDirection (void){





}



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
void Port_GetVersionInfo (Std_VersionInfoType* versioninfo){






}



#if PORT_SET_PIN_MODE_API == STD_ON
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
void Port_SetPinMode (Port_PinType Pin,Port_PinModeType Mode){






}
#endif
