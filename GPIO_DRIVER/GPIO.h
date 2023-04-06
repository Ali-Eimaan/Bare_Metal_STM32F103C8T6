#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f1xx.h"

typedef enum PORTS_Type
{
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF,
    PORTG
}

typedef enum PERIPHERERALS_Type
{
    SPI1,
    I2C1,
    USART1,
    USART2,
    USART3,
    TIM1 = 6,
    TIM2 = 8,
    TIM3 = 10,
    TIM4 = 12,
    CAN,
    PD01 = 15,
    TIM5CH4,
    ADC1ETRGINJ,
    ADC1ETRGREG,
    ADC2ETRGINJ,
    ADC2ETRGREG,
    SWJCFG = 24
}

typedef enum REMAP_Type
{
    NoRemap,
    PartialRemap,
    PartialRemap1,
    FullRemap
}

typedef enum PINS_Type
{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15
}

typedef enum PinState_Type
{
    LOW,
    HIGH
}

typedef enum CNF_Type
{
    AnalogInput,
    FloatingInput,
    Input_Pullup_PullDown,

    GeneralPurposePushPull = 0,
    GeneralPurposeOpenDrain,
    AlternateFunctionPushPull,
    AlternateFunctionOpenDrain
}

typedef enum Modes_Type
{
    InputMode,
    OutputMode10MHz,
    OutputMode2MHz,
    OutputMode50MHz
}

PinState ReadPin(GPIO_TypeDef *GPIOx, PINS Pin);
void ResetPin(GPIO_TypeDef *GPIOx, PINS Pin)
void TogglePin(GPIO_TypeDef *GPIOx, PINS Pin);
void SetPinMode(GPIO_TypeDef *GPIOx, PINS Pin, CNF Cnf, Modes Mode);
void WritePin(GPIO_TypeDef *GPIOx, PINS Pin, PinState State);
void LockPin(GPIO_TypeDef *GPIOx, PINS Pin, uint8_t LockState);
void GPIO_Remap(PERIPHERERALS Periphererals, REMAP_Type Remap);
void EXTI_Init(PINS_Type Pin, PORTS_Type Port);

#endif