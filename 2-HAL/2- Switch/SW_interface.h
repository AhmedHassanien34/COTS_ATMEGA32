/*****************************************************************/
/***********		Author: Ahmed Mohamed 			**************/
/***********		Layer: HAL			 			**************/
/***********		Component: SW			 		**************/
/***********		Version: 1.00		 			**************/
/***********		Date: 17-12-2022	 			**************/
/*****************************************************************/

/* Preprocessor File Guard */
#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

typedef struct
{
	u8 Port;
	u8 Pin;
	u8 PullType;
}SW_t;

#define SW_u8PRESSED				1
#define SW_u8NOT_PRESSED			0

#define SW_u8PULL_UP				0
#define SW_u8PULL_DOWN				1

u8 SW_u8GetState(SW_t * SW, u8* Copy_pu8State);

#endif