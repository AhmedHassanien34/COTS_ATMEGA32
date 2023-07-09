/**************************************************************************************/
/********************			Author: Ahmed Mohamed			***********************/
/********************			Layer: HAL			 			***********************/
/********************			Component: Ultrasonic 		    ***********************/
/********************			Version: 1.00		 			***********************/
/********************			Date: 16-12-2022	 			***********************/
/**************************************************************************************/

#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"

#include "ULTRASONIC_interface.h"
#include "ULTRASONIC_config.h"
#include "ULTRASONIC_private.h"

u8 ULTRASONIC_u8EdgeCounter = 0;
u16 ULTRASONIC_u16TimeON = 0;

void ULTRASONIC_voidEdgeProcessing(void)
{
	ULTRASONIC_u8EdgeCounter++;
	if(ULTRASONIC_u8EdgeCounter == 1)
	{
		TIMER_voidClearTimer1Value();
		TIMER_voidTimer1ICUSetTriggerEdge(TIMER1_ICU_FALLING_EDGY_TYPE_MODE);
	}
	else if(ULTRASONIC_u8EdgeCounter == 2)
	{
		ULTRASONIC_u16TimeON = TIMER_voidTimer1ICUGetInputCaptureValue();
		TIMER_voidClearTimer1Value();
		ULTRASONIC_u8EdgeCounter=0;
		TIMER_voidTimer1ICUSetTriggerEdge(TIMER1_ICU_RISING_EDGY_TYPE_MODE);
	}
}

void ULTRASONIC_voidInit(void)
{
	GIE_voidEnable();
	TIMER_voidTimer1ICUInit();
	TIMER_voidTimer1ICUSetCallBack(&ULTRASONIC_voidEdgeProcessing);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN6,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinValue(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,DIO_u8PIN_LOW);
}
void ULTRASONIC_voidTrigger(void)
{
	DIO_u8SetPinValue(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,DIO_u8PIN_HIGH);
	_delay_us(15);
	DIO_u8SetPinValue(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,DIO_u8PIN_LOW);
}
u16 ULTRASONIC_u16GetDistance(void)
{
	u16 Local_u16Distance;

		 ULTRASONIC_voidTrigger();
		 /* HC-SR-04 */
		 /* Sound velocity = 340.00 m/s = 34000 cm/s
		  * The distance of Object (in cm) = (340000∗Time)/2 = 17000 * Time
		  * Prescaler F_CPU/8 for timer frequency.
		  * The timer gets incremented after 1 us time elapse.
		  * Distance (cm)= 17000 x (TIMER value) x 1 x 10^-6 cm
	      * Distance (cm)= (TIMER value) / 58 cm
	      * */
	     Local_u16Distance=(ULTRASONIC_u16TimeON/(58)+1); /* Calculating Distance In cm */

	return Local_u16Distance;
}

