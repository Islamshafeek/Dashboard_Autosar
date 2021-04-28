/*
 * Std_Types.h
 *
 *  Created on: Apr 22, 2021
 *      Author: Islam
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_

//typedef Std_VersionInfoType ;

#define STD_ON	    0x01
#define STD_OFF	    0x00


typedef struct
{
 uint16_t vendorID;
 uint16_t moduleID;
 uint8_t  instanceID;
 uint8_t sw_major_version;
 uint8_t sw_minor_version;
 uint8_t sw_patch_version;

}Std_VersionInfoType;


#define STD_ACTIVE 0x01 /* Logical state active */
#define STD_IDLE 0x00 /* Logical state idle */


#define E_OK            	0x00U		     /* Function Return OK */
#define E_NOT_OK        	0x01U	    	 /* Function Return NOT OK */


#endif /* LIB_STD_TYPES_H_ */
