/*****************************************************************/
/***********		Author: Ahmed Mohamed 			**************/
/***********		Layer: MCAL			 			**************/
/***********		Component: UART			 		**************/
/***********		Version: 2.00		 			**************/
/***********		Date: 29-1-2023		 			**************/
/*****************************************************************/
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_register.h"
#include "UART_config.h"


void UART_voidInit(void)
{	

/********************************************************** UBRR ***************************************/
	u16 Local_u16UBRRValue ;
	Local_u16UBRRValue = UART_BAUD_RATE_UBRR;
	UBRRL=(u8)Local_u16UBRRValue;
	UBRRH=(u8)(Local_u16UBRRValue>>8);
/************************************* UCSRA *******************************************************/
    #if     UART_SPEED == UART_NORMAL_SPEED
	        CLR_BIT(UCSRA,UCSRA_U2X);
    #elif   UART_SPEED == UART_DOUBLE_SPEED
	        SET_BIT(UCSRA,UCSRA_U2X);
    #endif

    #if     UART_PROCESSOR_COMMUNICATION == UART_SINGLE_CYCLE_PRICESSOR
            CLR_BIT(UCSRA,UCSRA_MPCM);
    #elif   UART_PROCESSOR_COMMUNICATION == UART_MULTI_PRICESSOR
            SET_BIT(UCSRA,UCSRA_MPCM);
    #endif
/**************************************** UCSRB ****************************************************/
    #if     UART_RX_INTERRUPR == UART_RX_DISABLE_INTERRUPR
            CLR_BIT(UCSRB,UCSRB_RXCIE);
    #elif   UART_RX_INTERRUPR == UART_RX_ENABLE_INTERRUPR
            SET_BIT(UCSRB,UCSRB_RXCIEREG);
    #endif

    #if     UART_RX_INTERRUPR == UART_RX_DISABLE_INTERRUPR
            CLR_BIT(UCSRB,UCSRB_RXCIE);
    #elif   UART_RX_INTERRUPR == UART_RX_ENABLE_INTERRUPR
            SET_BIT(UCSRB,UCSRB_RXCIE);
    #endif


    #if     UART_TX_INTERRUPR == UART_TX_DISABLE_INTERRUPR
            CLR_BIT(UCSRB,UCSRB_TXCIE);
    #elif   UART_TX_INTERRUPR == UART_TX_ENABLE_INTERRUPR
            SET_BIT(UCSRB,UCSRB_TXCIE);
    #endif

    #if     UART_UDRE_EMPTY_INTEREGRRUPR == UART_UDRE_EMPTY_DISABLE_INTERRUPR
            CLR_BIT(UCSRB,UCSRB_UDRIE);
    #elif   UART_UDRE_EMPTY_INTERRUPR == UART_UDRE_EMPTY_ENABLE_INTERRUPR
            SET_BIT(UCSRB,UCSRB_UDRIEREG);
    #endif


    SET_BIT(UCSRB,UCSRB_TXEN);
    SET_BIT(UCSRB,UCSRB_RXEN);
 /********************************************** UCSRC **********************************************/
    u8 Local_u8UCSRCValue= 0b10000000;
    #if     UART_MODE_SELECT == UART_ASYNCHRONOUS_OPERATION
            CLR_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);
    #elif   UART_MODE_SELECT == UART_SYNCHRONOUS_OPERATION
            SET_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);
    #endif

    #if     UART_PARITY_MODE == UART_DISABLE_PARITY
            CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
            CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
    #elif   UART_PARITY_MODE == UART_ENABLE_EVEN_PARITY
            SET_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
            CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
    #elif   UART_PARITY_MODE == UART_ENABLE_ODD_PARITY
            SET_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
            SET_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
    #endif


    #if     UART_STOPREG_SELECT == UART_1REG_STOP_SELECT
            CLR_BIT(Local_u8UCSRCValue,UCSRC_USBS);
    #elif   UART_STOPREG_SELECT == UART_2REG_STOP_SELECT
            SET_BIT(Local_u8UCSRCValue,UCSRC_USBS);
    #endif


    #if     UART_CHARACTER_SIZE == UART_5REG_CHARACTER_SIZE
            CLR_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
            CLR_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
            CLR_BIT(UCSRB,UCSRB_UCSZ2REG);
    #elif   UART_CHARACTER_SIZE == UART_6REG_CHARACTER_SIZE
            SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
            CLR_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
            CLR_BIT(UCSRB,UCSRB_UCSZ2REG);
    #elif   UART_CHARACTER_SIZE == UART_7REG_CHARACTER_SIZE
            CLR_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
            SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
            CLR_BIT(UCSRB,UCSRB_UCSZ2REG);
    #elif   UART_CHARACTER_SIZE == UART_8REG_CHARACTER_SIZE
            SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
            SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
            CLR_BIT(UCSRB,UCSRB_UCSZ2REG);
    #elif   UART_CHARACTER_SIZE == UART_9REG_CHARACTER_SIZE
            SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
            SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
            SET_BIT(UCSRB,UCSRB_UCSZ2REG);
    #endif
    UCSRC=Local_u8UCSRCValue;
}
void UART_voidSendChar(u8 Copy_u8Char)
{
    while((0==GET_BIT(UCSRA,UCSRA_UDRE)));
    UDR = Copy_u8Char;
}
void UART_voidSendString(u8  *Copy_pu8String)
{
	for(u8 Local_u8Counter=0; Copy_pu8String[Local_u8Counter] != '\0' ; Local_u8Counter++)
	{
		  UART_voidSendChar(Copy_pu8String[Local_u8Counter]);
		  _delay_ms(1);
	}

}
u8 UART_u8GetCharBlocking(void)
{
	 u8 Local_u8Char;
	 u16 Counter;
	 while((0==GET_BIT(UCSRA,UCSRA_RXC)));
	 Local_u8Char=UDR;
     return Local_u8Char;
}
u8 UART_u8GetCharNonBlocking(void)
{
	 u8 Local_u8Char;
	 u16 Local_u16Counter;
	 while((Local_u16Counter<2000)&&(0==GET_BIT(UCSRA,UCSRA_RXC)))
	 {
		 Local_u16Counter++;
	 }
	 Local_u8Char=UDR;
     return Local_u8Char;
}
