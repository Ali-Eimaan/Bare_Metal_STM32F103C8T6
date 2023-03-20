#include "TIMER.h"

void tim4_1hz_init(void)
{
    RCC->APB1ENR |= TIM4EN;
    TIM4->PSC = 800 - 1;
    TIM4->ARR = 10000 - 1;
    TIM4->CNT = 0;
    TIM4->CR1 = CR1_CEN;
}