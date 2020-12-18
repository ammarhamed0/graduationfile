/*
 * slave.c
 *
 * Created: 12/15/2020 12:20:35 AM
 * Author : 20100
 */ 

#include <avr/io.h>
#include "SPI.h"
#include "LED1.h"
#include "LED.h"

int main(void)
{
	uint8 data ,REC=0;
	LED1_Init();
	LED0_Init();
	SPI_Slave_Init();
	while (1)
	{
		REC=SPI_TranSiver(data);
		if(REC ==1)
		{
			LED0_Toggle();
			REC=0;
		}
		else if (REC ==2)
		{
			Toggle_LED1();
			REC=0;	
		}
	}
	
}

