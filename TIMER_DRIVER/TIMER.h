#ifndef TIMER_H_
#define TIMER_H_

#define TIM4EN              (1U<<2)
#define CR1_CEN             (1U<<0)
#define SR_UIF              (1U<<0)

void tim4_1hz_init(void);

#endif