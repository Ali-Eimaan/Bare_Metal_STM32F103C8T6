#include "stdio.h"
#include "stdint.h"
#include "stm32f1xx.h"

#define UART1EN             (1U<<14)
#define GPIOAEN             (1U<<2)
#define AFIOEN              (1U<<0)

#define CR1_TE              (1U<<3)
#define CR1_UE              (1U<<13)
#define SR_TXE              (1U<<7)

#define SYS_FREQ            16000000
#define APB2_CLK            SYS_FREQ

#define BAUDRATE            115200

static uint16_t compute_baud_rate(uint32_t PeriphClk, uint32_t BaudRate)
{
    return ((PeriphClk + (BaudRate/2U))/BaudRate);
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
    USARTx->BRR = compute_baud_rate(PeriphClk, BaudRate);
}

void Uart1Init(void)
{
    RCC->APB2ENR |= GPIOAEN;
    RCC->APB2ENR |= AFIOEN;

    GPIOA->CR[1] |= (1U<<4); 
    GPIOA->CR[1] |= (1U<<5); 
    GPIOA->CR[1] |= (1U<<7);
    GPIOA->CR[1] &=~ (1U<<6);  

    AFIO->MAPR &=~ (1U<<2);

    uart_set_baudrate(USART1, APB2_CLK, BAUDRATE);

    UART1->CR1 = CR1_TE;
    UART1->CR1 |= CR1_UE
}

void uart1_write(int ch)
{
    while(!(UART1->SR & SR_TXE)){};
    UART1->DR = (ch & 0xFF);
}

int __io_putchar(int ch)
{
    uart1_write(ch);
    return ch;
}

int main()
{
    Uart1Init();
    printf("Hello From Bluepill...............\n\r");
    while (1){}
}