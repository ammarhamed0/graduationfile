/*
 * UART.c
 *
 * Created: 10/28/2020 8:47:16 PM
 *  Author: 20100
 */ 

#include "UART.H"
#include "DIO.h"

void UART_Init(void)
{
	uint8 UBRR_Val = 0;
	DIO_SetPinDir(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);
	DIO_SetPinDir(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
	UCSRC |= 0X86;
	
	UBRR_Val =((8000000) / (16 *9600)-1);
	UBRRL = UBRR_Val;
}

void UART_TX(uint8 data)
{
	UDR =data;
	
	while(GET_BIT(UCSRA,5) == 0);
}

void UART_TxString(uint8* str)
{
	uint8 i=0;
	while(str[i] != '\0')
	{
		UART_TX(str[i]);
		i++;
	}
}

uint8 UART_RX(void)
{
	uint8 data=0;
	while(GET_BIT(UCSRA,7) == 0);
	data=UDR;
	
	return data; 
}