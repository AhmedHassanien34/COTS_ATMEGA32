/**************************************************************************************/
/********************			Author: Ahmed Mohamed			***********************/
/********************			Layer: HAL			 			***********************/
/********************			Component: Ultrasonic 		    ***********************/
/********************			Version: 1.00		 			***********************/
/********************			Date: 16-12-2022	 			***********************/
/**************************************************************************************/

#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_


void ULTRASONIC_voidEdgeProcessing(void);

void ULTRASONIC_voidInit(void);

void ULTRASONIC_voidTrigger(void);

u16 ULTRASONIC_u16GetDistance(void);



#endif
