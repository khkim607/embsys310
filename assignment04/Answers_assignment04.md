A1. bitBanding LED1 demo
- the following screen capture file shows difference between blinking LED1 w/ and w/o bitBanding technique
a) 
b)

![bitBanding for LED1 Blinking](https://github.com/khkim607/embsys310/blob/main/assignment04/Assignment04_Ans01_bitBanding_LED1.png)


A2. function call with 5 arguments demo

a) It passes the values of five arguments by moving their values onto four registers of R0-R3 and one memory space addressed by stackpointer respectively.

b) Extra code is _*STR.W R8, [SP]*_ which is secureing another memory space for additional, 5th, argument which can not be handled by all scrtch registers of R0-R3

c) Extra code is _*LDR R5, [SP, #0x8]*_ which is retriving value of _5th_ argument passed by using stack memory.

d) Initial values of five arguments are initially srored in R4-R8 registers, then moved to R0-R3 and one stack memory space for function call operation. R4 and R5 registers are used for temporary space for moving valeus between registers.

![functionCall with % arguments](https://github.com/khkim607/embsys310/blob/main/assignment04/Assignment04_Ans02_functionCall.png)

A3. 
