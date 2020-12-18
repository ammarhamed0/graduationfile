/*
 * MASTER.c
 *
 * Created: 12/15/2020 12:12:36 AM
 * Author : 20100
 */ 

#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#include "SPI.h"
#include "UART.h"

int main(void)
{	uint8 trans_data=0 ,rec_data;
	
	SPI_Master_Init();
	SPI_Master_Init_Trans();
	UART_Init();
	
	_delay_ms(1000);
	while (1)
	{
		trans_data=UART_RX();
		if(trans_data)
		{
			rec_data = SPI_TranSiver(trans_data);
			trans_data=0;
		}
		_delay_ms(1000); 
	}
}
