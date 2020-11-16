### A1. bitBanding LED1 demo (main_bitBanding.c)
- the following screen capture file shows difference between blinking LED1 w/ and w/o bitBanding technique
a) 
 - MOVS R0, #1
 - LDR.N R1, [PC, #0x4c]
 - STR R0, [R1]
b)
 - LDR.N R0, [PC, #0x50]
 - LDR R1, [R0]
 - ORRS.W R1, R1, #1
 - STR R1, [R0]

![bitBanding for LED1 Blinking](https://github.com/khkim607/embsys310/blob/main/assignment04/Assignment04_Ans01_bitBanding_LED1.png)


### A2. function call with 5 arguments demo (main_functionCall.c)

a) It passes the values of five arguments by moving their values onto four registers of **R0-R3** and one memory space addressed by stackpointer respectively.

b) Extra code is _**STR.W R8, [SP]**_ which is secureing another memory space for additional, **5th**, argument which can not be handled by all scrtch registers of **R0-R3**

c) Extra code is _**LDR R5, [SP, #0x8]**_ which is retriving value of **5th** argument passed by using stack memory.

d) 
 - Initial values of five arguments are initially srored in **R4-R8** registers, then moved to **R0-R3 and one stack memory space** for function call operation. 
 - **R4** and **R5** registers are used for temporary space for moving valeus between registers.

![functionCall with % arguments](https://github.com/khkim607/embsys310/blob/main/assignment04/Assignment04_Ans02_functionCall.png)

### A3. stack (LIFO) data structure (main_stack.c, stack.c, stack.h)

a) instaead of two pointers used in queue structure, _**getPtr/putPtr**_, stack structure only needed one pointer of _**topPtr**_ which indicates the address of last value of data.
1. #define STACK_SIZE 3
2. int StackStore[STACK_SIZE];
3. void stack_init(void);
4. int stack_push(int data);
5. int stack_pop(int* data);
6. logic implemented in _**stack_pop**_ function
7. logic implemented in _**stack_push**_ function

b) implemented in _**main.c**_
1.     // Test1: Retrieve item from an empty stack
2.     // Test2: Successfully retrieve an item from the stack
3.     // Test3: Fill stack, then get all items.
4.     // Test4: Fill stack, then put one more item, should fail
5.     // Test5: Fill stack, retrieve one item, then add item, then retieve all
6.     // Test6: Fill queue and retrieve all items. Do it twice in a row.

c) attached files of _**stack.h**_ and _**stack.c**_

### A4. Bonus: Little-/Big-endian problem demo (main_endian.c)
a/b) check the status of "little" or "big" endian setting by comparing the value of "char" read from "int" variable.
 - *pInt = 0x41424344; //'ABCD' in character
 - char* pChar = (char*)&myInt; // pickup 'D' for littleEdnian or 'A' for bigEndian
 - validity is checked by assert function


