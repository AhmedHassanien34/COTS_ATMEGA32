/*****************************************************************/
/***********		Author: Ahmed Mohamed 			**************/
/***********		Layer: MCAL			 			**************/
/***********		Component: UART			 		**************/
/***********		Version: 2.00		 			**************/
/***********		Date: 29-1-2023		 			**************/
/*****************************************************************/

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit(void);
void UART_voidSendChar(u8 Copy_u8Char);
u8 UART_u8GetCharBlocking(void);
u8 UART_u8GetCharNonBlocking(void);
void UART_voidSendString(u8  *Copy_pu8String);



#endif