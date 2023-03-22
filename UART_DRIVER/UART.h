#ifndef UART_H_
#define UART_H_

#include "stdio.h"
#include "stdint.h"
#include "stm32f1xx.h"

#define USART1EN            (1U<<14)
#define GPIOAEN             (1U<<2)
#define AFIOEN              (1U<<0)

#define CR1_TE              (1U<<3)
#define CR1_RE              (1U<<2)
#define CR1_UE              (1U<<13)
#define SR_TXE              (1U<<7)
#define SR_RXNE             (1U<<5)
#define CR1_RXNEIE          (1U<<5)

#define SYS_FREQ            8000000
#define APB2_CLK            SYS_FREQ

#define BAUDRATE            115200

void Uart1Init(void);
void uart1_write(int ch);
char uart1_read(void);
void Uart1RxInterruptInit(void);

#endif
