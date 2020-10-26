**A1.**

a) 2147483647 -> -2147483648

b) R1 = 0x7fffffff -> 0x80000000

c) N=0, V=0 --> N=1, V=1. N=1 means negative value after calculation and V=1 means overflow condition reached after calculation. 0x7fffffff is the maximum integer value possible. Increasing by 1 results in overflow condition since the output value of two positive values is negative. 

**A2.** 

a) -1 -> 0

b) N=0, V=0, --> N=0, V=0. 0xffffffff is -1 in decimal. increasing by 1 results in 0. The N register remains 0 since the result is not negative. The V register remains 0 since the  register set to 1 if the sign of results changes when either two positive numbers are added or two negative values are subtracted from each other. 

**A3.**

a) 2147483647 -> 2147483648

b) N=0, N=0, -> N=1, V=1, The N register value set to 1 since the number after increase by 1 is 2147483648 (0x80000000) is negative number (when inperpreted in signed integer).  The overflow flag V is set to 1 since addition of two positive number resulted in negative value (when interpreted in signed integer)

**A4.** 

a)4294967295 -> 0 -> 1

b) N=0, V=0 --> N=0, V=0 --> N=0, V=0. N register remains 0 since the results show the positive valued. V register also remains 0 since the results of addition of two positive values remains positive

**A5.**

a) Its a global variable which can be accessed from main {} funtion AND other functions.

b) No. The variable "counter" is not a "Local" anymore.

c)In "watch" window

d) 0x20000000

**A6.**

a) 4

b) 
- at the first line, compiler assigned address of 0x20000000 to global variable "counter" which is initialized to "0".
- at the third line, a pointer at address of 0x20000000 for local integer variable is assigned,
- for the next 3 lines, the value at the address of p_int, 0x20000000, increases by 1 for each line. the value becomes 3
- at next line, the value of variable which was 3 increased by 1 to become 4.

**A7.** 

a) 0x20000000

b) SRAM (0x20000000 if the starting address of ARM Cortex-M4 processor)

c) 4
