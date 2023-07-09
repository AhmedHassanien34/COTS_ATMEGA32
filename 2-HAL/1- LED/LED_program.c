/*****************************************************************/
/***********		Author: Ahmed Mohamed 			**************/
/***********		Layer: HAL			 			**************/
/***********		Component: LED			 		**************/
/***********		Version: 1.00		 			**************/
/***********		Date: 17-12-2022	 			**************/
/*****************************************************************/

#include "LED_interface.h"
#include "DIO_interface.h"


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

u8 LED_u8TurnOn(LED_t * LED)
{
	u8 Local_u8ErrorState = 0;
	if((LED -> ConnType) == LED_u8SOURSE)
	{
		DIO_u8SetPinDirection(LED -> Port , LED -> Pin , DIO_u8PIN_HIGH);
	}
	else if((LED -> ConnType) == LED_u8SINK)
	{
		DIO_u8SetPinDirection(LED -> Port , LED -> Pin , DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

u8 LED_u8TurnOff(LED_t * LED)
{
	u8 Local_u8ErrorState = 0;

	if((LED -> ConnType) == LED_u8SOURSE)
	{
		DIO_u8SetPinDirection(LED -> Port , LED -> Pin , DIO_u8PIN_LOW);
	}
	else if((LED -> ConnType) == LED_u8SINK)
	{
		DIO_u8SetPinDirection(LED -> Port , LED -> Pin , DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

