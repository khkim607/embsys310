#include <stdint.h>
#include "delay.h"
#include "system_stm32l4xx.h"
#include "stm32l475xx.h"

// LD1 --> PA5 -- Homework


volatile int counter=0;

void main(void)
{     

    
#if 1
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // RCC Base Address: 0x40021000
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral  

    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; // FOR LED1 in GPIOA //SET BIT[0] TO 1
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOa Base Address: 0x48000000
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x00000400 // To enable PA5 as output
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1; // FOR LED1 AT GPIOA PORT 5
    GPIOA->MODER |= GPIO_MODER_MODE5_0; // FOR LED1 AT GPIOA PORT 5
    
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOA Base Address: 0x48000000
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x0; // Turn LED OFF
    
    while(1)
    {
        GPIOA->ODR |= GPIO_ODR_OD5;
        delay(100000);
        
        GPIOA->ODR &= ~GPIO_ODR_OD5;
        delay(100000);
    }    
#endif
}
