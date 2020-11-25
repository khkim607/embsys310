### A1. swapping of teo pointers

a. Explain what the “main” function does in order to setup the input arguments prior to calling the swap_pointer() function?
   
**-->**  store the address of pointers of variavle  x and y on the stack with new variables name xPtr and yPtr, then passes the address of xPtr and yPtr as arguments of  swap function by storing them in R0 and R1 respectively.
   
b. What are the values in R0 & R1 when swap_pointer() is called?

**-->** values of R0/R1 are addresses of the pointers of variables x and y, xP and yP, i.e, the addresses or variables storing the addresses of the variables x and y
