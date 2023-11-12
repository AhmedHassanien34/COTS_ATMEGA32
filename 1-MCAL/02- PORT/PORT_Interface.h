/**************************************************************************************/
/********************			Author: Ahmed Mohamed			***********************/
/********************			Layer: MCAL			 			***********************/
/********************			Component: PORT 			    ***********************/
/********************			Version: 1.00		 			***********************/
/********************			Date: 16-12-2022	 			***********************/
/**************************************************************************************/

#ifndef PORT_INTERFACE_H_
#define PORT_INTERFACE_H_

//for output Configuration
#define LOW  0
#define HIGH 1

//for choose output or input
#define OUTPUT 1
#define INPUT  0

//for input Configuration
#define PULLUP 1
#define NORMAL 0

void PORT_VoidInit(void);

#endif /* PORT_INTERFACE_H_ */
