#include "TIMER.h"

int timestamp = 0;

int main(void)
{
    tim4_PB8_output_compare();
    tim1_PA8_input_capture();
    while (1)
    {
        while(!(TIM1->SR & SR_CCI1F));
        timestamp = TIM1->CCR1;
    }
}