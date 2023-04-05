#include "GPIO.h"

void SetPinMode(GPIO_TypeDef *GPIOx, PINS Pin, CNF Cnf, Modes Mode)
{
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

void LockPin(GPIO_TypeDef *GPIOx, PINS Pin, uint32_t LockState)
{
    GPIOx->LCKR |= Pin;
    GPIOx->LCKR = PINSLCKK;
    GPIOx->LCKR = (1U<<Pin);
    GPIOx->LCKR = PINSLCKK;
    LockState = GPIOx->LCKR;
    LockState = (GPIOx->LCKR & PINSLCKK);
}

void WritePin(GPIO_TypeDef *GPIOx, PINS Pin, PinState State)
{
    if (State == LOW)
        GPIOx->BSRR |= Pin;
    else
        GPIOx->BSRR |= (Pin + 16);
}

PinState ReadPin(GPIO_TypeDef *GPIOx, PINS Pin)
{
    return (GPIOx->IDR & Pin);
}

void TogglePin(GPIO_TypeDef *GPIOx, PINS Pin)
{
    GPIOx->ODR ^= Pin;
}

void ResetPin(GPIO_TypeDef *GPIOx, PINS Pin)
{
    GPIOx->BRR |= Pin;
}