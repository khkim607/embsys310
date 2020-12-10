/*******************************************************************************
File name       : swapPointersAsm.s
Description     : Assembly language function for swap Pointers
*******************************************************************************/   

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.
    
    PUBLIC swapPointersAsm       // Exports symbols to other modules
                        // Making swapPointersAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : swapPointersAsm
Description     : Calls C code to print a string; 
                  computes the division by 2 of its input argument
C Prototype     : void swapPointersAsm(val1, val2)
                : Where val1 and val2 are pointers to be swapped 
Parameters      : R0, R1: pointers of integer xPtr, yPtr
Return value    : 
*******************************************************************************/  
  
swapPointersAsm
    
    // Just for TeraTerm display of values before swap
    PUSH {R0,R1,LR}     // save the input argument and return address
    LDR R0,[R1]         // load address of pointer of value of R1(second) into R0    
    BL  PrintString     // call PrintString to print the string    
    POP {R0,R1,LR}      // Restore R0 , R1 and LR
    
    // swap routine
    LDRB R2, [R0]       // load the pointer of the first argument into R2 
    LDRB R3, [R1]       // load the pointer of the second argument into R3
    STRB R3, [R0]       // store the pointer of second argument into the first pointer's address
    STRB R2, [R1]       // store the pointer of first argument into second pointer's address
    
    // Just for TeraTerm display of values after swap
    PUSH {R0,R1,LR}     // save the input argument and return address
    LDR R0,[R0]         // load address of pointer of value of R0(Second) into R0 
    BL  PrintString     // call PrintString to print the string  
    POP {R0,R1,LR}      // Restore R0 , R1 and LR

    BX LR               // return (with function result in R0)
    
    END
