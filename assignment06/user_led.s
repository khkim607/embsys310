/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

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
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

GPIOA_BASE  EQU 0x48000000
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x20

control_user_led1

    PUSH {R0, R1, LR}   // save register values into stack
    MOV R2, R0          // load LED_On/_OFF control onto R2
    CMP R2, #1          // compare with #1(LED_ON)
    BEQ.N a_led_on      // go to a_led_on if the value equal to 1 (LED_ON)
                        // otherwise execute following LED_OFF instructions
    
    LDR R2, =GPIOA_BASE         // Load GPIOA_BASE address into R2
    ADD R2, #GPIOA_ODR          // Add GPIOA_ODR offset address to BASE address
    LDR R0, [R2]                // load registor value of GPIOA_ODR address into R0
    BICS.W R0, R0, #GPIOA_BIT_5 // set LED_ON by bit clear: for turning off LED1
    STR	R0, [R2]        // execute PA5 LED_OFF storing register value into GPIOA_ODR register address
    POP {R0, R1, LR} 	// restore register values from stack        
    
    MOV R0, R1          // load delay value into register R0 
    
    PUSH {LR}           // save LR address
    BL delay            // branch to delay function
    POP {LR}            // restore LR value
    BX LR               // back to caller function
	
a_led_on        //    (GPIOA_ODR |= ORD5; turn on led1)
    LDR	R2, =GPIOA_BASE         // Load GPIOA_BASE address into R2
    ADD R2, #GPIOA_ODR          // Add GPIOA_ODR offset address to BASE address
    LDR R0, [R2]                // load registor value of GPIOA_ODR address into R0
    ORRS.W R0, R0, #GPIOA_BIT_5 // set LED_ON by bit set: for turning on LED1
    STR	R0, [R2]        // execute PA5 LED_OFF storing register value into GPIOA_ODR register address        
    POP {R0, R1, LR} 	// restore register values from stack 
    
    MOV R0, R1          // load delay value into register R0 
    
    PUSH {LR}           // save LR address
    BL delay            // branch to delay function
    POP {LR}            // restore LR value
    BX LR               // back to caller function
    
    END
