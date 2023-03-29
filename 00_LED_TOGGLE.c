#define PERIPH_BASE             (0x40000000UL)

#define APB2_OFFSET             (0x00010000UL)
#define APB2_BASE               (PERIPH_BASE + APB2_OFFSET)

#define AHB_OFFSET              (0x00018000UL)
#define AHB_BASE                (PERIPH_BASE + AHB_OFFSET)

#define GPIOC_OFFSET            (0x00001000UL)
#define GPIOC_BASE              (APB2_BASE + GPIOC_OFFSET)

#define RCC_OFFSET              (0x00009000UL)
#define RCC_BASE                (AHB_BASE + RCC_OFFSET)

#define APB2ENR_OFFSET          (0x18UL)
#define RCC_APB2ENR             (*(volatile unsigned int *)(RCC_BASE + APB2ENR_OFFSET))

#define MODER_OFFSET            (0x04UL)
#define GPIOC_MODER             (*(volatile unsigned int *)(GPIOC_BASE + MODER_OFFSET))

#define ODR_OFFSET              (0x0C)
#define GPIOC_ODR               (*(volatile unsigned int *)(GPIOC_BASE + ODR_OFFSET))

#define GPIOCEN                 (1U<<4)
#define PIN13                   (1U<<13)

int main(void)
{
    RCC_APB2ENR |= GPIOCEN;

    GPIOC_MODER |= (1U<<20);
    GPIOC_MODER |= (1U<<21);
    GPIOC_MODER &= ~(1U<<22);
    GPIOC_MODER &= ~(1U<<23);

    while(1)
    {
        GPIOC_ODR ^= PIN13;
        for (int i = 0; i < 1000000; i++);
    }
}