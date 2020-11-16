// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class

#if 1
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

// #define GPIOB_BASE 0x48000400
#define GPIOA_BASE 0x48000000

// #define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x00)))
// #define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*) (GPIOA_BASE + 0x14)))

volatile int counter=0;
//int counter=0;

// #define ORD14 (1<<14) // bit 14 is set to 1; PB14 for LED2
#define ORD5 (1 << 5) // bit 5 is set to 1; PA5 for LED1
// #define ORD5 0x20 //(1 << 5) // bit 5 is set to 1; PA5 for LED1

void main(void)
{
    // RCC Base Address: 0x40021000
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral
    // RCC_AHB2ENR = RCC_AHB2ENR | 0x2; // Enable clock for GPIOB
    // RCC_AHB2ENR = RCC_AHB2ENR | 0x1; // Enable clock for GPIOA
    
    // Bit-banding method: for PA5 LED1
    *((unsigned int*) ((0x42000000) + (0x2104C * 32) + (0*4))) = 0x1;
    // Bit-banding method: for PB14 LED2
    // *((unsigned int*) ((0x42000000) + (0x2104C * 32) + (1*4))) = 0x1;

    
    
    // GPIOB Base Address: 0x48000400
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PB14 as output
    // GPIOB_Moder = 0xFFFF FEBF; // GPIOB port mode register reset value
    // GPIOB_MODER &= 0xDFFFFFFF;
    
    // GPIOA_MODER = 0xABFFF7FF; // GPIOA port mode register reset value
    GPIOA_MODER &= 0xFFFFF7FF; // set GPIOA port to output; bit[11:10] to 0x01


    // GPIOB Base Address: 0x48000400
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[14] to 1 --> 0x4000; // Turn LED ON
    // Set bit[14] to 0 --> 0x0; // Turn LED OFF

    while(1)
    {
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }

        // GPIOB_ODR |= ORD14;
        GPIOA_ODR |= ORD5;
            
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }

        // GPIOB_ODR &= ~ORD14;
        GPIOA_ODR &= ~ORD5;
    }
}
#endif