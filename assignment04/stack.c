#include "stack.h"
#define STACK_SIZE 3

// Backing store
int StackStore[STACK_SIZE];


int* topPtr; //Pointer to stack element for adding and retrieving
                 // topPtr++ ; with addede element
                 // topPtr-- ; with retrieved element
    
// FIFO Queue is Empty if putPtr==getPtr;
// FIFO Queue is Full if putPtr+1 > Address of last element in the stack;

// LIFO Stack is Empty if topPtr==0;
// LIFO Stack is Full if topPtr==Address of the last element of the stack;

// Initialize internals of the stack
void stack_init(void)
{
    topPtr = 0;
    // getPtr = 0;
    for(int i=0; i<STACK_SIZE; i++)
    {
        StackStore[i] = 0;
    }
}

// Add data to stack
// If stack is full return error
// Otherwise return success
int stack_push(int data)
{
    if (topPtr == &StackStore[STACK_SIZE-1])
    {
        // stack is full
        return 1;
    }

    if (topPtr == 0)
    {
        topPtr = &StackStore[0];
    }
    else
    {
        topPtr++;
    }
    
    *topPtr = data;
    return 0;
}

// Get data from stack
// If stack is empty return error
// Otherwise return success
int stack_pop(int* data)
{   
    if (topPtr == 0)
    {
        // stack is empty
        return 1;
    }

    *data = *topPtr;
    
    if (topPtr == &StackStore[0])
    {
        topPtr = 0;
    }

    else
    {
        topPtr--;
    }
    
    return 0;
}
