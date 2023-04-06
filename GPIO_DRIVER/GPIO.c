#include "GPIO.h"

void SetPinMode(GPIO_TypeDef *GPIOx, PINS_Type Pin, CNF_Type Cnf, Modes_Type Mode)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    if (Pin > PIN7)
    {
        GPIOx->CRH |= (Mode<<(4*Pin));
        GPIOx->CRH |= (Cnf<<(2+(4*Pin)));
    }
    else
    {
        GPIOx->CRL |= (Mode<<(4*(Pin-7)));
        GPIOx->CRL |= (Cnf<<(2+(4*(Pin-7))));
    }
}

void LockPin(GPIO_TypeDef *GPIOx, PINS_Type Pin, uint32_t LockState)
{
    GPIOx->LCKR |= Pin;
    GPIOx->LCKR = GPIO_LCKR_LCKK;
    GPIOx->LCKR = (1U<<Pin);
    GPIOx->LCKR = GPIO_LCKR_LCKK;
    LockState = GPIOx->LCKR;
    LockState = (GPIOx->LCKR & GPIO_LCKR_LCKK);
}

void WritePin(GPIO_TypeDef *GPIOx, PINS_Type Pin, PinState_Type State)
{
    if (State == LOW)
        GPIOx->BSRR |= Pin;
    else
        GPIOx->BSRR |= (Pin + 16);
}

PinState_Type ReadPin(GPIO_TypeDef *GPIOx, PINS_Type Pin)
{
    return (GPIOx->IDR & Pin);
}

void TogglePin(GPIO_TypeDef *GPIOx, PINS_Type Pin)
{
    GPIOx->ODR ^= Pin;
}

void ResetPin(GPIO_TypeDef *GPIOx, PINS_Type Pin)
{
    GPIOx->BRR |= Pin;
}

void GPIO_Remap(PERIPHERERALS_Type Periphererals, REMAP_Type Remap)
{
    RCC->APB1ENR |= RCC_APB2ENR_AFIOEN;
    AFIO->MAPR |= (Remap<<Periphererals);
}

void EXTI_Init(PINS_Type Pin, PORTS_Type Port)
{
    RCC->APB1ENR |= RCC_APB2ENR_AFIOEN;
    if (Pin < 4)
    {
        AFIO->EXTICR[0] |= Port<<(Pin*4);
        if (Pin == 0)
            NVIC_EnableIRQ(EXTI0_IRQn);
        else if (Pin == 1)
            NVIC_EnableIRQ(EXTI1_IRQn);
        else if (Pin == 2)
            NVIC_EnableIRQ(EXTI2_IRQn);
        else if (Pin == 3)
            NVIC_EnableIRQ(EXTI3_IRQn);
    }
    else if (Pin > 3 && Pin < 8)
    {
        AFIO->EXTICR[1] |= Port<<((Pin-4)*4);
        if (Pin == 4)
            NVIC_EnableIRQ(EXTI4_IRQn);
        else
            NVIC_EnableIRQ(EXTI9_5_IRQn);
    }
    else if (Pin > 7 && Pin < 12)
    {
        AFIO->EXTICR[2] |= Port<<((Pin-8)*4);
        if (Pin > 10)
            NVIC_EnableIRQ(EXTI9_5_IRQn);
        else
            NVIC_EnableIRQ(EXTI15_10_IRQn);
    }
    else
    {
        AFIO->EXTICR[3] |= Port<<((Pin-12)*4);
        NVIC_EnableIRQ(EXTI15_10_IRQn);
    }
}