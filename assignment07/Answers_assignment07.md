### A1. blinking LED with SysTick and msec delay function

a. executed as instructed ([main.c](https://github.com/khkim607/embsys310/blob/main/assignment07/main.c))

b. screen shot of vector table 

![Vector Table](https://github.com/khkim607/embsys310/blob/main/assignment07/A07_Q1_vector%20table.png)

c. #define SYS_CLOCK_HZ 4000u   <-- SysTick interrupt interval = 1 ms since 4000 is the 1 thousandth of 4 MHz default system clock. At every 4000 system clock, SysTick make an interrupt which decrease delay count equivalent to 1 millisecond.

d-e. implemedted in delay() function ([delay.c](https://github.com/khkim607/embsys310/blob/main/assignment07/delay.c))and the delay count controlled by SysTick_Handler() in main function ([main.c](https://github.com/khkim607/embsys310/blob/main/assignment07/main.c))

### A2. generated map file and answers ([SysTic_LED1.map](https://github.com/khkim607/embsys310/blob/main/assignment07/SysTic_LED1.map))

a. 532 bytes of readonly code/data memory (ROM)

b. 8,216 bytes of readwrite data memory (RAM)

c. main function using 0x70 size of ROM

d. stack memory using 0x2000 size of SRAM

### A3.  optimizing use of ROM and RAM

- remove unused variables

- properly sized stack memory based on estimated usage

- compact coding

- use macro for repeatedly used set of instructions
  
