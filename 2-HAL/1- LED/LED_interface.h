/*****************************************************************/
/***********		Author: Ahmed Mohamed 			**************/
/***********		Layer: HAL			 			**************/
/***********		Component: LED			 		**************/
/***********		Version: 1.00		 			**************/
/***********		Date: 17-12-2022	 			**************/
/*****************************************************************/

/* Preprocessor file guard */
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "STD_TYPES.h"

typedef struct
{
	u8 Port;
	u8 Pin;
	u8 ConnType;
}LED_t;

#define LED_u8SOURSE				0
#define LED_u8SINK					1

u8 LED_u8TurnOn (LED_t * LED);
u8 LED_u8TurnOff(LED_t * LED);

#endif
