#include "ADC.h"

uint32_t ADC;

int main(void)
{
    PA4_ADC_INTERRUPT_INIT();
    Start_Conversion_Continous();
    while (1);
}

void ADC1_IRQHandler(void)
{
    if(ADC1->SR & SR_EOC)
    {
        ADC1->SR &= ~SR_EOC;
        ADC = ADC1->DR;
    }
}
