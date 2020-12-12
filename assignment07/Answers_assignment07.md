### A1. blinking LED with SysTick and msec delay function

a. executed as instructed ([main.c](https://github.com/khkim607/embsys310/blob/main/assignment07/main.c))

b. screen shot of vector table 
(![Vector Table](https://github.com/khkim607/embsys310/blob/main/assignment07/A07_Q1_vector table.png)

c. #define SYS_CLOCK_HZ 4000u   <-- SysTick interrupt interval = 1 ms since 4000 is the 1 thousandth of 4 MHz default system clock. At every 4000 system clock, SysTick make an interrupt which decrease delay count equivalent to 1 millisecond.

d-e. implemedted in delay() function ([delay.c](https://github.com/khkim607/embsys310/blob/main/assignment07/delay.c))and the delay count controlled by SysTick_Handler() in main function ([main.c](https://github.com/khkim607/embsys310/blob/main/assignment07/main.c))

### A2. generated map file and answers ([SysTic_LED1.map](https://github.com/khkim607/embsys310/blob/main/assignment07/SysTic_LED1.map))

a. 

  
