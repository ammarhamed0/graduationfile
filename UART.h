/*
 * UART.h
 *
 * Created: 10/28/2020 8:47:40 PM
 *  Author: 20100
 */ 


#ifndef UART_H_
#define UART_H_
#include "ATMEGA32_Regs (1).h"
#include "STD.h"

void UART_Init(void);
void UART_TX(uint8 data);
void UART_TxString(uint8* str);
uint8 UART_RX(void);


#endif /* UART_H_ */