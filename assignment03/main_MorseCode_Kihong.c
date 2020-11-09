// LED1 out for Morse code transmission of FIRST NAME "KIHONG"
#if 1

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x48000000

// #define OFFSET 0x01

#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*) (GPIOA_BASE + 0x14)))
#define ORD5 (1 << 5) // bit 5 is set to 1; PA5 for LED1

volatile int counter = 0;
// define Morse code of each letter of First Name;
// each dot and dash set to 1 and space set to 0
#define L_K 0x1D7
#define L_I 0x5
#define L_H 0x55
#define L_O 0x777
#define L_N 0x1D
#define L_G 0x1DD

#define SPC_L 0x0

// Location of 1st bit of binary sequence of each letter in Morse code
#define LOC_K 0x100
#define LOC_I 0x4
#define LOC_H 0x40
#define LOC_O 0x400
#define LOC_N 0x10
#define LOC_G 0x100

#define LEN_K 0x9
#define LEN_I 0x3
#define LEN_H 0x7
#define LEN_O 0xB
#define LEN_N 0x5
#define LEN_G 0x9

#define LEN_Space 0x3

#define LED_COUNTER 0x20000

unsigned int FN_Kihong[6] = {L_K, L_I, L_H, L_O, L_N, L_G};
unsigned int LEN_FN_Kihong[6] = {LEN_K, LEN_I, LEN_H, LEN_O, LEN_N, LEN_G};
unsigned int LOC_FN_Kihong[6] = {LOC_K, LOC_I, LOC_H, LOC_O, LOC_N, LOC_G};
volatile int letter_count = 0;
volatile int len_letter_count = 0;
volatile int loc_letter_count = 0;
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
      unsigned int a = 0;
      unsigned int b = 0;
      unsigned int c = 0;
      unsigned int d = 0;
      for (letter_count = 0; letter_count <6; letter_count++) {
          a = FN_Kihong[letter_count];
          b = LEN_FN_Kihong[letter_count];
          c = LOC_FN_Kihong[letter_count];
          
          while (b > 0) 
          {
              d = a & c;
              if (d > 0) {
                  GPIOA_ODR = 0x0020; //GPIOA_ODR
                  while (counter < LED_COUNTER)
                      {
                          counter++;
                      }
              }
              else {
                  GPIOA_ODR = 0x0000; //GPIOA_ODR  
                  while (counter < LED_COUNTER)
                      {
                          counter++;
                      }
              }
              counter = 0;
              c >>= 1;
              b--;
          } 
          GPIOA_ODR = 0x0000; //GPIOA_ODR  
          while (counter < LED_COUNTER*10)
                      {
                          counter++;
                      }
          counter = 0;
          
      }
              
  }
}
#endif