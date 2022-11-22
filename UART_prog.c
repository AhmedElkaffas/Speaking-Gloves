/*
 * UART_prog.c
 *
 *  Created on: Aug 25, 2019
 *      Author: Ahmed
 */
#include "LIB/STD_Types.h"
#include "UART_int.h"
#include "UART_reg.h"
#include "LIB/Bit_Op.h"

void UART_vidInit(void)
{
	/* Set RX , TX and Error Flags to Zero*/
	/* Set U2X to Zero */
	UCSRA = 0;

	/* Transmission Enable */
	Set_Bit(UCSRB,TXEN);
	/* Set UCSZ2 to select 8-bit Data */
	Clear_Bit(UCSRB,UCSZ2);

	/* Set bit URSEL to enable Write on UCSRC */
	/* Clear bit UMSEL to set Async mode */
	/* Clear bits UPM1:0 to select no Parity */
	/* Clear USBS bi to select 1-Stop bit */
	/*Set UCSZ1 and UCSZ0 to one to select 8-bit data*/
	UCSRC = 0b10000110;

	/* Set baud rate to 9600 at 12M */
	UBRRH = 0;
	UBRRL = 77;
}

void UART_vidSendChar(uint8 u8DataSend)
{
	/* Wait till TX buffer is Empty */
	while(Get_Bit(UCSRA,UDRE) == 0);
	/* Set Data Register with Data to send */
	UDR = u8DataSend;
}

