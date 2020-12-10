### A1. swapping of two pointers

a. Explain what the “main” function does in order to setup the input arguments prior to calling the swap_pointer() function?
   
**-->**  store the address of the pointers of variables  x and y on the stack with new variables name xPtr and yPtr, then swap the values of the new variables of xPtr and yPtr by passing the address of xPtr and yPtr as arguments of swap function by storing them in R0 and R1 respectively.
   
b. What are the values in R0 & R1 when swap_pointer() is called?

**-->** values of R0/R1 are addresses of the pointers of variables x and y, xP and yP, i.e, the addresses or variables storing the addresses of the variables x and y

c. screen shot of swapped pointers

**-->** actual values of x and y are unchanged, but the values of new pointers xPtr and xPtr (pointers of variables x and y)are swapped.  

![Swapped pointers](https://github.com/khkim607/embsys310/blob/main/assignment05/Capture_of_screen_shot_of_swapped_pointer_example.PNG)


### A2.  implementing function of division by 2 in assembly (divASM.s)

a-e.  main function has codes for Q2 - Q4 commemted and separated by #if/#endif directives

f. screen shot of TeraTerm is as follows

![Swapped pointers](https://github.com/khkim607/embsys310/blob/main/assignment05/Capture_of_screen_shot_of_swapped_pointer_example.PNG)

### A3.  implementing function of swapping two character arguments in assembly (swapCharASM.s) 

a-b. implemented in main function and swapCharASM.s


### A4.  implementing function of swapping pointers of two arguments in assembly (swapPointersASM.s) 

a-b. implemented in main function and swapPointersASM.s

c. screen shot of TeraTerm is as follows

![Swapped pointers](https://github.com/khkim607/embsys310/blob/main/assignment05/Capture_of_screen_shot_of_swapped_pointer_example.PNG)


