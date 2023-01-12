/**************************************************************************************/
/********************			Author: Ahmed Mohamed			***********************/
/********************			Layer: LIB			 			***********************/
/********************			Component: STD_TYPES.h			***********************/
/********************			Version: 1.00		 			***********************/
/********************			Date: 16-12-2022	 			***********************/
/**************************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char		 u8;
typedef signed char			 s8;
typedef unsigned short		 u16;
typedef signed short		 s16;
typedef unsigned long		 u32;
typedef signed long			 s32;
typedef unsigned long long   u64;
typedef signed long long     s64;
typedef float				 f32;
typedef double				 f64;

#define TRUE 	 	 (u8)0x01
#define FALSE	 	 (u8)0x00
#define NULL  		 ((void*)0)

#endif /* STD_TYPES_H_ */