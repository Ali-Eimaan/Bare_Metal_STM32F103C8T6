#include "stdint.h"
#include "stm32f1xx.h"

#define UART1EN             (1U<<14)
#define GPIOAEN             (1U<<2)
#define AFIOEN              (1U<<0)

#define CR1_RE              (1U<<2)
#define CR1_UE              (1U<<13)
#define SR_RXNE             (1U<<5)

#define SYS_FREQ            16000000
#define APB2_CLK            SYS_FREQ

#define BAUDRATE            115200

char key;

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

    GPIOA->CRH &=~ (1U<<8); 
    GPIOA->CRH &=~ (1U<<9); 
    GPIOA->CRH |= (1U<<10);
    GPIOA->CRH &=~ (1U<<11);  

    AFIO->MAPR &=~ (1U<<2);

    uart_set_baudrate(USART1, APB2_CLK, BAUDRATE);

    UART1->CR1 = CR1_RE;
    UART1->CR1 |= CR1_UE
}

void uart1_read(void)
{
    while(!(UART1->SR & SR_RXNE)){};
    return UART1->DR;
}

int main()
{
    Uart1Init();
    while (1)
    {
        key = uart1_read();
    }
}
