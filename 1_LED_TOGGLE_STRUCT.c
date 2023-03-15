#include "stdint.h"

#define PERIPH_BASE             (0x40000000UL)

#define APB2_OFFSET             (0x00010000UL)
#define APB2_BASE               (PERIPH_BASE + APB2_OFFSET)

#define AHB_OFFSET              (0x00018000UL)
#define AHB_BASE                (PERIPH_BASE + AHB_OFFSET)

#define GPIOC_OFFSET            (0x00001000UL)
#define GPIOC_BASE              (APB2_BASE + GPIOC_OFFSET)

#define RCC_OFFSET              (0x00009000UL)
#define RCC_BASE                (AHB_BASE + RCC_OFFSET)

#define GPIOCEN                 (1U<<4)
#define PIN13                   (1U<<13)

#define __IO                    volatile

typedef struct
{
    __IO uint32_t MODER[2];
    __IO uint32_t IDR;
    __IO uint32_t ODR;
    __IO uint32_t BSRR;
    __IO uint32_t BRR;
    __IO uint32_t LCKR;
}GPIO_TypeDef;

typedef struct
{
    __IO uint32_t CR;
    __IO uint32_t CFGR;
    __IO uint32_t CIR;
    __IO uint32_t APB2RSTR;
    __IO uint32_t APB1RSTR;
    __IO uint32_t AHBENR;
    __IO uint32_t APB2ENR;
    __IO uint32_t APB1ENR;
    __IO uint32_t BDCR;
    __IO uint32_t CSR;
    __IO uint32_t AHBRSTR;
    __IO uint32_t CFGR2;
}RCC_TypeDef;

#define RCC                     ((RCC_TypeDef*) RCC_BASE)
#define GPIOC                   ((GPIO_TypeDef*) GPIOC_BASE)

int main(void)
{
    RCC->APB2ENR |= GPIOCEN;

    GPIOC->MODER[1] |= (1U<<20);
    GPIOC->MODER[1] |= (1U<<21);
    GPIOC->MODER[1] &=~ (1U<<22);
    GPIOC->MODER[1] &=~ (1U<<23);

    while(1)
    {
        GPIOC->ODR ^= PIN13;
        for (int i = 0; i < 1000000; i++){}
    }
}