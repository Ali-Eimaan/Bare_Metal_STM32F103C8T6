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
#define CR3_DMAT            (1U<<7)

#define SYS_FREQ            8000000
#define APB2_CLK            SYS_FREQ

#define DMA1ENR             (1U<<0)
#define DMA1IFCR            ((1U<<12) | (1U<<13) | (1U<<14) | (1U<<15))
#define DMA1CREN            (1U<<0)
#define DMA1MINC            (1U<<7)
#define DMA1TCIE            (1U<<1)
#define DMA1TCIF            (1U<<13)

#define BAUDRATE            115200

void Uart1Init(void);
void uart1_write(int ch);
char uart1_read(void);
void Uart1RxInterruptInit(void);
void DMA1_Channel4_INIT(uint32_t src, uint32_t des, uint32_t len);

#endif
