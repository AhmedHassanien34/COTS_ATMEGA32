/*****************************************************************/
/***********		Author: Ahmed Mohamed 			**************/
/***********		Layer: HAL			 			**************/
/***********		Component: CLCD			 		**************/
/***********		Version: 1.00		 			**************/
/***********		Date: 17-12-2022	 			**************/
/*****************************************************************/


/*Preprocessor file guard*/
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define NULL					0

#define CLCD_u8NUMBER0			0
#define CLCD_u8NUMBER1			1
#define CLCD_u8NUMBER2			2
#define CLCD_u8NUMBER3			3
#define CLCD_u8NUMBER4			4
#define CLCD_u8NUMBER5			5
#define CLCD_u8NUMBER6			6
#define CLCD_u8NUMBER7			7
#define CLCD_u8NUMBER8			8
#define CLCD_u8NUMBER9			9

// initiate LCD (must be called before using LCD functions)
void CLCD_voidInit(void);

// send command to LCD
void CLCD_voidSendCommand(u8 copy_u8Command);

// print character On LCD
void CLCD_voidSendCharacter(u8 copy_u8Character);

// Send string to LCD (input argument is a pointer to the beginning of the string)
void CLCD_voidSendString(const char* Copy_pcString);

// Control the position of the printed characters
void CLCD_voidGoToXY(u8 Copy_u8XPos , u8 Copy_u8YPos);

// Draw special character
void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern , u8 Copy_u8PatternNumber , u8 Copy_u8XPos , u8 Copy_u8YPos);

// Write number
void CLCD_voidSendNumber(u32 Copy_u32Number);


// LCD_voidWriteNum Overflow
#if num > 4294967295
#error "Error: Integer Overflow"
#endif

#endif /* LCD_INTERFACE_H_ */

