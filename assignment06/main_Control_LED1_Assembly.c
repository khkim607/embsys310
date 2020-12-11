#include <stdint.h>

// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class

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

#define LED_ON 1
#define LED_OFF 0
#define DELAY_DURATION 100000

#define PORTA 0x1
#define PORTB 0x2

void delay(uint32_t iteration); // delay() function
void control_user_led1(uint8_t state, uint32_t duration);       //control_user_led1() function
void enable_rcc(uint32_t port); // enable_rcc() function

int value = 100000;

// delay() function in C; not used in delay.s function
#if 0
void delay(int value); // Prototype
void delay(int value) {
      volatile int counter=0;
        while (counter < value)
        {
          counter++;
        }
}
#endif

void main(void)
{    
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // RCC Base Address: 0x40021000
    // Address offset: 0x4C
    // Set bit[1] to 1 to enable clock to PortB
    // Set bit[0] to 1 to enable clock to PortA
    // 1. Enable clock to Peripheral
    
    // RCC_AHB2ENR |= 0x1; // RCC AHB2 peripheral clock enable
    enable_rcc(PORTA); // calling RCC AHB2 peripheral clock enable function in assembly
    
    // <TODO> Replace above statement with function call below
    // enable_rcc(0);
  
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOA Base Address: 0x48000000
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable PA5 as output
    // Note: GPIOA_MODER reset value = 0xABFFFFFF
    //       So will only need to clear bit 11
    GPIOA_MODER &= 0xFFFFF7FF;

    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOA Base Address: 0x48000000
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x0; // Turn LED OFF
#if 1     
    while(1)
    {
        control_user_led1(LED_ON, DELAY_DURATION);      // turn on led1 and delay, all in assebly
        control_user_led1(LED_OFF, DELAY_DURATION);     // turn off led1 and delay, all in assembly
    }
#endif
    
#if 0
        while(1)
    {
  
        delay(value);   // call delay() function in assembly
        GPIOA_ODR |= ORD5;
            
        delay(value); //call delay function in assembly
        GPIOA_ODR &= ~ORD5;
    }
#endif
    
}
