#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f1xx.h"

#define PIN0MODE0                           (1U<<0)
#define PIN0MODE1                           (1U<<1)
#define PIN0CNF0                            (1U<<2)
#define PIN0CNF1                            (1U<<3)

#define PIN1MODE0                           (1U<<4)
#define PIN1MODE1                           (1U<<5)
#define PIN1CNF0                            (1U<<6)
#define PIN1CNF1                            (1U<<7)

#define PIN2MODE0                           (1U<<8)
#define PIN2MODE1                           (1U<<9)
#define PIN2CNF0                            (1U<<10)
#define PIN2CNF1                            (1U<<11)

#define PIN3MODE0                           (1U<<12)
#define PIN3MODE1                           (1U<<13)
#define PIN3CNF0                            (1U<<14)
#define PIN3CNF1                            (1U<<15)

#define PIN4MODE0                           (1U<<16)
#define PIN4MODE1                           (1U<<17)
#define PIN4CNF0                            (1U<<18)
#define PIN4CNF1                            (1U<<19)

#define PIN5MODE0                           (1U<<20)
#define PIN5MODE1                           (1U<<21)
#define PIN5CNF0                            (1U<<22)
#define PIN5CNF1                            (1U<<23)

#define PIN6MODE0                           (1U<<24)
#define PIN6MODE1                           (1U<<25)
#define PIN6CNF0                            (1U<<26)
#define PIN6CNF1                            (1U<<27)

#define PIN7MODE0                           (1U<<28)
#define PIN7MODE1                           (1U<<29)
#define PIN7CNF0                            (1U<<30)
#define PIN7CNF1                            (1U<<31)

#define PIN8MODE0                           (1U<<0)
#define PIN8MODE1                           (1U<<1)
#define PIN8CNF0                            (1U<<2)
#define PIN8CNF1                            (1U<<3)

#define PIN9MODE0                           (1U<<4)
#define PIN9MODE1                           (1U<<5)
#define PIN9CNF0                            (1U<<6)
#define PIN9CNF1                            (1U<<7)

#define PIN10MODE0                          (1U<<8)
#define PIN10MODE1                          (1U<<9)
#define PIN10CNF0                           (1U<<10)
#define PIN10CNF1                           (1U<<11)

#define PIN11MODE0                          (1U<<12)
#define PIN11MODE1                          (1U<<13)
#define PIN11CNF0                           (1U<<14)
#define PIN11CNF1                           (1U<<15)

#define PIN12MODE0                          (1U<<16)
#define PIN12MODE1                          (1U<<17)
#define PIN12CNF0                           (1U<<18)
#define PIN12CNF1                           (1U<<19)

#define PIN13MODE0                          (1U<<20)
#define PIN13MODE1                          (1U<<21)
#define PIN13CNF0                           (1U<<22)
#define PIN13CNF1                           (1U<<23)

#define PIN14MODE0                          (1U<<24)
#define PIN14MODE1                          (1U<<25)
#define PIN14CNF0                           (1U<<26)
#define PIN14CNF1                           (1U<<27)

#define PIN15MODE0                          (1U<<28)
#define PIN15MODE1                          (1U<<29)
#define PIN15CNF0                           (1U<<30)
#define PIN15CNF1                           (1U<<31)

#define PIN0IDR                             (1U<<0)
#define PIN1IDR                             (1U<<1)
#define PIN2IDR                             (1U<<2)
#define PIN3IDR                             (1U<<3)
#define PIN4IDR                             (1U<<4)
#define PIN5IDR                             (1U<<5)
#define PIN6IDR                             (1U<<6)
#define PIN7IDR                             (1U<<7)
#define PIN8IDR                             (1U<<8)
#define PIN9IDR                             (1U<<9)
#define PIN10IDR                            (1U<<10)
#define PIN11IDR                            (1U<<11)
#define PIN12IDR                            (1U<<12)
#define PIN13IDR                            (1U<<13)
#define PIN14IDR                            (1U<<14)
#define PIN15IDR                            (1U<<15)

#define PIN0ODR                             (1U<<0)
#define PIN1ODR                             (1U<<1)
#define PIN2ODR                             (1U<<2)
#define PIN3ODR                             (1U<<3)
#define PIN4ODR                             (1U<<4)
#define PIN5ODR                             (1U<<5)
#define PIN6ODR                             (1U<<6)
#define PIN7ODR                             (1U<<7)
#define PIN8ODR                             (1U<<8)
#define PIN9ODR                             (1U<<9)
#define PIN10ODR                            (1U<<10)
#define PIN11ODR                            (1U<<11)
#define PIN12ODR                            (1U<<12)
#define PIN13ODR                            (1U<<13)
#define PIN14ODR                            (1U<<14)
#define PIN15ODR                            (1U<<15)

#define PIN0BS                              (1U<<0)
#define PIN1BS                              (1U<<1)
#define PIN2BS                              (1U<<2)
#define PIN3BS                              (1U<<3)
#define PIN4BS                              (1U<<4)
#define PIN5BS                              (1U<<5)
#define PIN6BS                              (1U<<6)
#define PIN7BS                              (1U<<7)
#define PIN8BS                              (1U<<8)
#define PIN9BS                              (1U<<9)
#define PIN10BS                             (1U<<10)
#define PIN11BS                             (1U<<11)
#define PIN12BS                             (1U<<12)
#define PIN13BS                             (1U<<13)
#define PIN14BS                             (1U<<14)
#define PIN15BS                             (1U<<15)

#define PIN0BR                              (1U<<16)
#define PIN1BR                              (1U<<17)
#define PIN2BR                              (1U<<18)
#define PIN3BR                              (1U<<19)
#define PIN4BR                              (1U<<20)
#define PIN5BR                              (1U<<21)
#define PIN6BR                              (1U<<22)
#define PIN7BR                              (1U<<23)
#define PIN8BR                              (1U<<24)
#define PIN9BR                              (1U<<25)
#define PIN10BR                             (1U<<26)
#define PIN11BR                             (1U<<27)
#define PIN12BR                             (1U<<28)
#define PIN13BR                             (1U<<29)
#define PIN14BR                             (1U<<30)
#define PIN15BR                             (1U<<31)

#define PIN0BRR                             (1U<<0)
#define PIN1BRR                             (1U<<1)
#define PIN2BRR                             (1U<<2)
#define PIN3BRR                             (1U<<3)
#define PIN4BRR                             (1U<<4)
#define PIN5BRR                             (1U<<5)
#define PIN6BRR                             (1U<<6)
#define PIN7BRR                             (1U<<7)
#define PIN8BRR                             (1U<<8)
#define PIN9BRR                             (1U<<9)
#define PIN10BRR                            (1U<<10)
#define PIN11BRR                            (1U<<11)
#define PIN12BRR                            (1U<<12)
#define PIN13BRR                            (1U<<13)
#define PIN14BRR                            (1U<<14)
#define PIN15BRR                            (1U<<15)

#define PIN0LCK                             (1U<<0)
#define PIN1LCK                             (1U<<1)
#define PIN2LCK                             (1U<<2)
#define PIN3LCK                             (1U<<3)
#define PIN4LCK                             (1U<<4)
#define PIN5LCK                             (1U<<5)
#define PIN6LCK                             (1U<<6)
#define PIN7LCK                             (1U<<7)
#define PIN8LCK                             (1U<<8)
#define PIN9LCK                             (1U<<9)
#define PIN10LCK                            (1U<<10)
#define PIN11LCK                            (1U<<11)
#define PIN12LCK                            (1U<<12)
#define PIN13LCK                            (1U<<13)
#define PIN14LCK                            (1U<<14)
#define PIN15LCK                            (1U<<15)
#define PINSLCKK                            (1U<<16)

#define AFIOPIN0                            (1U<<0)
#define AFIOPIN1                            (1U<<1)
#define AFIOPIN2                            (1U<<2)
#define AFIOPIN3                            (1U<<3)
#define AFIOPORT0                           (1U<<4)
#define AFIOPORT1                           (1U<<5)
#define AFIOPORT2                           (1U<<6)
#define AFIOEVOE                            (1U<<7)

#define SPI1REMAP                           (1U<<0)
#define I2C1REMAP                           (1U<<1)
#define USART1REMAP                         (1U<<2)
#define USART2REMAP                         (1U<<3)
#define USART3REMAP0                        (1U<<4)
#define USART3REMAP1                        (1U<<5)
#define TIM1REMAP0                          (1U<<6)
#define TIM1REMAP1                          (1U<<7)
#define TIM2REMAP0                          (1U<<8)
#define TIM2REMAP1                          (1U<<9)
#define TIM3REMAP0                          (1U<<10)
#define TIM3REMAP1                          (1U<<11)
#define TIM4REMAP                           (1U<<12)
#define CANREMAP0                           (1U<<13)
#define CANREMAP1                           (1U<<14)
#define PDO1REMAP                           (1U<<15)
#define TIM5CH4REMAP                        (1U<<16)
#define ADC1ETRGINJREMAP                    (1U<<17)
#define ADC1ETRGREGREMAP                    (1U<<18)
#define ADC2ETRGINJREMAP                    (1U<<19)
#define ADC2ETRGREGREMAP                    (1U<<20)
#define SWJCFG0                             (1U<<24)
#define SWJCFG1                             (1U<<25)
#define SWJCFG2                             (1U<<26)

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