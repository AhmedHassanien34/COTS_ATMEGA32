/**************************************************************************************/
/********************			Author: Ahmed Mohamed			***********************/
/********************			Layer: MCAL			 			***********************/
/********************			Component: EXTI				    ***********************/
/********************			Version: 1.00		 			***********************/
/********************			Date: 16-12-2022	 			***********************/
/**************************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define INT0			0
#define INT1			1
#define INT2			2

void EXTI_voidInt0Init(void);

void EXTI_voidInt1Init(void);

void EXTI_voidInt2Init(void);

/*  Description:  A function to set the required sense control of INT0 using postbuild configuration
 * 	Input:	Copy_u8Sense , options are: 1-  LOW_LEVEL
 * 	                                    2-  ON_CHANGE
 * 	                                    3-  FALLING_EDGE
 * 	                                    4- RISING_EDGE
 * 	 output: Error status with type u8
 * 	*/
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense);

u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense);

u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense);

u8 EXTI_u8IntEnable(u8 Copy_u8Int);

u8 EXTI_u8IntDisable(u8 Copy_u8Int);

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void));
u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void));
u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void));

#endif