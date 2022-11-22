/*
 * UART_reg.h
 *
 *  Created on: Aug 25, 2019
 *      Author: Ahmed
 */

#ifndef UART_REG_H_
#define UART_REG_H_

#define UCSRA    (*(volatile uint8*)0x2B)
#define UCSRB    (*(volatile uint8*)0x2A)
#define UCSRC    (*(volatile uint8*)0x40)
#define UBRRH    (*(volatile uint8*)0x40)
#define UBRRL    (*(volatile uint8*)0x29)
#define UDR      (*(volatile uint8*)0x2C)

/* Register UCSRB */
#define RXEN   4
#define TXEN   3
#define UCSZ2  2

/* Register UCSRA  */
#define RXC    7
#define UDRE   5


#endif /* UART_REG_H_ */
