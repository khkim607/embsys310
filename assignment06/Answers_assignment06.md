### A1. blinking LED1 using CMSIS data structure

a-e. all answers are implemented in _**[main_blinking_LED1_CMSIS.c](https://github.com/khkim607/embsys310/blob/main/assignment06/main_blinking_LED1_CMSIS.c)**_ file 


### A2. implement blinking LED1 in assembly code

a-c. implemented as instructed within _**[main_Control_LED1_Assembly.c](https://github.com/khkim607/embsys310/blob/main/assignment06/main_Control_LED1_Assembly.c)**_ file

d. implemented in _**[user_led.s](https://github.com/khkim607/embsys310/blob/main/assignment06/user_led.s)**_ file in assembly

e. implemented in _**[delay.s](https://github.com/khkim607/embsys310/blob/main/assignment06/delay.s)**_ file in assembly

f-g. implemented as instructed

### A3. (Bonus) implement enable_rcc to set RCC AHB2 peripheral clock enable register

- implemented as instructed except using MOVW & MOVT instructions. Instead **LDR R1, =BYTE_OFFSET** is used. This instruction seems working, but, is there any special reason you suggested to use **MOVW & MOVT** instructions?

- implemented in _**[rcc_ctrl.s](https://github.com/khkim607/embsys310/blob/main/assignment06/rcc_ctrl.s)**_ file in assembly


