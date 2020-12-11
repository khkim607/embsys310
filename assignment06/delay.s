/*******************************************************************************
File name       : delay.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    PUBLIC delay         // Exports symbols to other modules

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
Function Name   : delay
Description     : loops until input value reaches initial set value, then exits

C Prototype     : void delay(uint8_t duration)
                : Where duration indicates the total number of loops.
Parameters      : R0: uint8_t duration
Return value    : None
*******************************************************************************/  
  
delay
    PUSH {LR}   // save return address
    
    SUB SP, SP, #0x4    // increment stack memory: need a memory space for temporsry value of delay counter
    
    MOVS R1, #0	        // initialigze counter value
    STR R1, [SP]        // store counter value t stack memory
    
a_compare       // routine for compare delay counter and initial set value
    LDR R1, [SP]        // load delay counter value to R1
    CMP R1, R0	        // compare delay counter and initial set value
    BGE.N a_exit        // if counter value reaches to initial set value go to a_exit
    
a_increase      // routine for increase counter value  
    LDR R1, [SP]	// load current value of counter from stack memory
    ADDS R1, R1, #1     // increase the value of counter
    STR R1, [SP]	// store the increased value of counter in the stack
    B.N a_compare	// branch to compare routine
    
a_exit          // return to caller function
    ADD SP, SP, #0x4    // decrement stack memory before return
    POP {LR}            // load LR with saved address
    BX LR               // branch to the LR address

    END
