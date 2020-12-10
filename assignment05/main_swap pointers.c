// ************** Aiisgnment05_Q1 - Swap Pointers************** //
#if 1

// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class

#include "delay.h"

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x00)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))


#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

//volatile int counter=0;
int counter=0;

#define ORD14   (1<<14)
#define ORD5    (1<<5)

// swap pointers pointing values
void swap(int** x, int** y);

// swap function in C
#if 1
void swap(int** x, int** y)
{   
   int* tempPtr = *x;
   *x = *y;
   *y = tempPtr;
}
#endif

int main(void)
{
    int x = 100000;
    int y = 50000;
    int* xPtr = &x;     // pointer to the address of variable x
    int* yPtr = &y;     // pointer to the address of variable y
    
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    RCC_AHB2ENR |= 0x3;
  
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    GPIOB_MODER &= 0xDFFFFFFF;
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    GPIOA_MODER &= 0xFFFFF7FF;

    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    while(1)
    {
        swap(&xPtr,  &yPtr);  // swap pointers function call in C
    //    swapPointersAsm(&xPtr, &yPtr);

        GPIOB_ODR |= ORD14;
        delay(*xPtr);

        GPIOB_ODR &= ~ORD14;
        delay(*yPtr);
    }
}
#endif
