/*****************************************************************/
/***********		Author: Ahmed Mohamed 			**************/
/***********		Layer: HAL			 			**************/
/***********		Component: Stepper_Motor		**************/
/***********		Version: 1.00		 			**************/
/***********		Date: 17-12-2022	 			**************/
/*****************************************************************/


#ifndef STM_INTERFACE_H_
#define STM_INTERFACE_H_

void STM_u8CWDefault(void);
void STM_u8CCWDefault(void);

void STM_voidCWByAngle(f32 Copy_f32Angle);
void STM_voidCCWByAngle(f32 Copy_f32Angle);



#endif