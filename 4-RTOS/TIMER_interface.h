/*****************************************************************/
/***********		Author: Ahmed Mohamed 			**************/
/***********		Layer: RTOS STACK			 	**************/
/***********		Component: RTOS					**************/
/***********		Version: 1.00		 			**************/
/***********		Date: 17-12-2022	 			**************/
/*****************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER0_voidInit(void);
u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));

#endif
