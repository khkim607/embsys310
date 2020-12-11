### A1. swapping of two pointers ([main_swap pointers.c](https://github.com/khkim607/embsys310/blob/main/assignment05/main_swap%20pointers.c))

a. Explain what the “main” function does in order to setup the input arguments prior to calling the swap_pointer() function?
   
**-->**  store the address of the pointers of variables  x and y on the stack with new variables name xPtr and yPtr, then swap the values of the new variables of xPtr and yPtr by passing the address of xPtr and yPtr as arguments of swap function by storing them in R0 and R1 respectively.
   
b. What are the values in R0 & R1 when swap_pointer() is called?

**-->** values of R0/R1 are addresses of the pointers of variables x and y, xP and yP, i.e, the addresses or variables storing the addresses of the variables x and y

c. screen shot of swapped pointers

**-->** actual values of x and y are unchanged, but the values of new pointers xPtr and xPtr (pointers of variables x and y)are swapped.  

![Swapped pointers](https://github.com/khkim607/embsys310/blob/main/assignment05/Capture_of_screen_shot_of_swapped_pointer_example.PNG)


### A2.  implementing function of division by 2 in assembly (([main_Asm.c](https://github.com/khkim607/embsys310/blob/main/assignment05/main_Asm.c) and divASM.s)

a-e.  main function has codes for Q2 - Q4 commemted and separated by #if/#endif directives

f. screen shot of TeraTerm is as follows

![Swapped pointers](https://github.com/khkim607/embsys310/blob/main/assignment05/A05_Q2_Div2_Screenshot.PNG)

### A3.  implementing function of swapping two character arguments in assembly (main_Asm.c and swapCharASM.s) 

a-b. implemented in main function and swapCharASM.s. Main function has codes for Q2 - Q4 commemted and separated by #if/#endif directives.


### A4.  (Bonus) implementing function of swapping pointers of two arguments in assembly (main_Asm.c and swapPointersASM.s) 

a-b. implemented in main function and swapPointersASM.s. Main function has codes for Q2 - Q4 commemted and separated by #if/#endif directives.

c. screen shots of **TeraTerm** and **IAR_Watch** window are as follows

- TeraTerm screen shot shows the changes of **xPtr** and **yPtr**, pointers of variable **x** and **y**, respectively, before and after swapPointerAsm function. IAR watch window shows the variables **x** and **y** and their address are not changed, but the pointer values are swapped. 

![Swapped pointers](https://github.com/khkim607/embsys310/blob/main/assignment05/A05_Q4_swapPointersASM_TeraTerm.png)

![Swapped pointers](https://github.com/khkim607/embsys310/blob/main/assignment05/A05_Q4_swapPointersASM_IAR_Watch.png)



