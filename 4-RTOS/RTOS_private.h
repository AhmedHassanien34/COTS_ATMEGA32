/*****************************************************************/
/***********		Author: Ahmed Mohamed 			**************/
/***********		Layer: RTOS STACK			 	**************/
/***********		Component: RTOS					**************/
/***********		Version: 1.00		 			**************/
/***********		Date: 17-12-2022	 			**************/
/*****************************************************************/


#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_


typedef struct
{
	u16 Periodicity;
	void (*TaskFunc)(void);
	u8 State;
	u8 FirstDelay;
}Task_t;

static void Schedular(void);

#define TASK_SUSPENDED		0
#define TASK_RESUMED		1


#endif
