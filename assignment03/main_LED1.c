
// For LED1 practice demo with bit operation with GPIOA, PA5 pin
#if 1

// #define ODR14 (1<<14)
#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x48000000

// #define OFFSET 0x01

#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*) (GPIOA_BASE + 0x14)))

#define ORD5 (1 << 5) // bit 5 is set to 1; PA5 for LED1


volatile int counter = 0;
int main()
{
    
  // *((unsigned int*)0x4002104C) = 0x2; //RCC_AHB2ENR: Enable clock to GPIOB
  RCC_AHB2ENR |= 0x1; //RCC_AHB2ENR: Enable clock to GPIOA
  //  counter = RCC_BASE + OFFSET;
  // GPIOB Base address: 0x48000400
    // GPIOA_MODER = 0xABFFF7FF;
    GPIOA_MODER &= 0xFFFFF7FF; // GPIOA_MODER: set GPIOA to output; clear bit 11

  
  while (1)
  {
      counter = 0;
      while (counter < 10000)
      {
          counter++;
      }
  //GPIOA_ODR = 0x0020; //GPIOA_ODR
  GPIOA_ODR |= ORD5; //GPIOA_ODR; set only bit 5 to 1
  
  counter = 0;
      while (counter < 10000)
      {
          counter++;
      }
  GPIOA_ODR &= ~ORD5;
  }
}
#endif

// For LED1 toggling with XOR bitwise operation with GPIOA, PA5 pin
#if 0

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x48000000

// #define OFFSET 0x01

#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*) (GPIOA_BASE + 0x14)))
#define ORD5 (1 << 5) // bit 5 is set to 1; PA5 for LED1

volatile int counter = 0;

int main()
{
    // *((unsigned int*)0x4002104C) = 0x2; //RCC_AHB2ENR: Enable clock to GPIOB
    RCC_AHB2ENR |= 0x1; //RCC_AHB2ENR: Enable clock to GPIOA
    //  counter = RCC_BASE + OFFSET;
    // GPIOB Base address: 0x48000400
    // GPIOA_MODER = 0xABFFF7FF;
    GPIOA_MODER &= 0xFFFFF7FF; // GPIOA_MODER: set GPIOA to output; clear bit 11

  
  while (1)
  {
      //GPIOA_ODR = 0x0020; //GPIOA_ODR
      GPIOA_ODR ^= ORD5; //GPIOA_ODR; bitwise XOR operation fro toggle PA5 output   
      
      counter = 0;
      while (counter < 10000)
      {
          counter++;
      }
  }
}
#endif
