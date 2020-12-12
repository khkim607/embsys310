#include <stdint.h>
#include "delay.h"
//#include "stm32f401xe.h"    // CMSIS - Device Specific File
#include "system_stm32l4xx.h"
#include "stm32l475xx.h"

// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class

#if 0
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x00)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define ORD14   (1<<14)
#define ORD5    (1<<5)
#endif

typedef struct {
    uint8_t temp;
    uint16_t wind;
} Sensor;

typedef struct {
    uint16_t amp;
    uint16_t vol;
} Electricity;

typedef struct {
    uint16_t x;
    uint16_t y;
    uint16_t z;
} Dimension;

#if 0   // Uniintialized
int16_t x;
uint32_t y;
int16_t siteArray[16];
Sensor s1;
Electricity e1;
#endif  // Uniintialized

#if 1   // Initialized
int16_t x = 100;
uint32_t y = 0x34343434;
int16_t siteArray[16] = {1, 3, 5, 7,9}; // Missing elements will be iniatialized to zero.

Sensor s1 = {
    0x96,
    0x30
};

Electricity e1 = {
    0x10,
    0x250
};
#endif  // Initialized

#if 0
Sensor* s2;
int16_t antArray[10];
Sensor s2;
Electricity e2;
#endif

#if 1
Sensor* s2 = &s1;
int16_t antArray[] = {2, 4, 6, 8}; // Missing elements will be iniatialized to zero.
Electricity e2 = {
    10,
    250
};
#endif

volatile int counter=0;

/*---------Definition for SysTick interrupt usage-----------------------------*/
// #define SYS_CLOCK_HZ 4000000u   // Default clock after startup
                                // Section 3.11 in STM32L475 datasheet DS10969
#define SYS_CLOCK_HZ 4000u      // SysTick interrupt interval = 1 ms        
                                // 4*10^6/1*10^3 = 4*10^3
uint32_t MilliSecond;           // variable for delay() loop equuivalent of 1 ms length

void SysTick_Initialize(void);


void main(void)
{     

    s1.temp = 48;
    s1.wind = 12;
    
    e1.amp = 3;
    e1.vol = 120;
    
    s2 = &s1;
    s2->temp = 65;
    (*s2).wind = 45;
    
    for(int i=0; i < sizeof(antArray)/sizeof(antArray[0]); i++)
    {
        antArray[i] = 'a' + i;
    }
    
    

#if 0
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    RCC_AHB2ENR |= 0x3;
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    GPIOB_MODER &= 0xDFFFFFFF;
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    GPIOA_MODER &= 0xFFFFF7FF;

    while(1)
    {
        GPIOB_ODR |= ORD14;
        delay(100000);

        GPIOB_ODR &= ~ORD14;
        delay(100000);
    }
#endif
    
#if 1
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // RCC Base Address: 0x40021000
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral  
    // RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN; // FOR LED2 in GPIOB
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; // FOR LED1 in GPIOA //SET BIT[0] TO 1
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x00
    // Set bit[29:28] to 0x01  so --> 0x20000000 // To enable PB14 as output
    // GPIOB->MODER &= ~GPIO_MODER_MODE14_1; // FOR LED2 AT GPIOB PORT 14
    // GPIOB->MODER |= GPIO_MODER_MODE14_0; // FOR LED2 AT GPIOB PORT 14

    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOa Base Address: 0x48000000
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x00000400 // To enable PB14 as output
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x14
    // Set bit[14] to 1 --> 0x4000; // Turn LED ON
    // Set bit[14] to 0 --> 0x0; // Turn LED OFF

    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOA Base Address: 0x48000000
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x0; // Turn LED OFF
    
    SysTick_Initialize();

#if 0    
    while(1)
    {
        // GPIOB->ODR |= GPIO_ODR_OD14;
        GPIOA->ODR |= GPIO_ODR_OD5;
        delay(100000);
        
        // GPIOB->ODR &= ~GPIO_ODR_OD14;
        GPIOA->ODR &= ~GPIO_ODR_OD5;
        delay(100000);
    }
#endif
    
#if 1
        while(1)
    {
        GPIOA->ODR ^= GPIO_ODR_OD5;     // toggle LED1 of PA5
        delay(1000);    // delay function call
    }
#endif // toggle LED1 PA5
    
#endif
}

void SysTick_Initialize(void)
{
    SysTick->LOAD = SYS_CLOCK_HZ - 1;       // 0xE000E014 - Counts down to 0.
    SysTick->VAL = 0x0;                     // 0xE000E018 - Clears initial value
    SysTick->CTRL = 0x7;                    // 0xE000E010 - Enable interrupts
}
// direct control of LED control from SysTick 
#if 0
void SysTick_Handler(void)
{
    __disable_irq();
    GPIOB->ODR ^= GPIO_ODR_OD14;
    __enable_irq();
}
#endif

// SysTick handler decrease MilliSecond at every 1 msec
#if 1
void SysTick_Handler(void)
{
    if (MilliSecond !=0)
    {
        __disable_irq();
        MilliSecond--;
        __enable_irq();
    }
}
#endif