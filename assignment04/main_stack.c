#include<assert.h>
#include"stack.h"

int main()
{
    int result1;
    int result2;
    int testInt;
    
    // *******************************************************************
    // Test1: Retrieve item from an empty stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testInt = 100;
    stack_init();
    
    // Act:
    result1 = stack_pop(&testInt);
      
    // Assert:
    assert(1 == result1);
    assert(100 == testInt);
    
    
    // *******************************************************************
    // Test2: Successfully retrieve an item from the stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    result2 = 42;
    testInt = 100;
    stack_init();
    
    // Act:
    result1 = stack_push(30);
    result2 = stack_pop(&testInt);
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert(30 == testInt);
    
    
    // *******************************************************************
    // Test3: Fill stack, then get all items.
    // *******************************************************************
    // Arrange:
    testInt = 100;
    stack_init();
    
    // Act:
    stack_push(30);
    stack_push(40);
    stack_push(50);                                    
    
    // Assert:
    assert(0 == stack_pop(&testInt));
    assert(50 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(40 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(30 == testInt);

    
    // *******************************************************************
    // Test4: Fill stack, then put one more item, should fail
    // *******************************************************************
    // Arrange:
    testInt = 100;
    stack_init();
    
    // Act:
    stack_push(30);
    stack_push(40);
    stack_push(50);
    
    // Assert:
    assert(1 == stack_push(60));

    assert(0 == stack_pop(&testInt));
    assert(50 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(40 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(30 == testInt);



    // ***********************************************************************
    // Test5: Fill stack, retrieve one item, then add item, then retieve all
    // ***********************************************************************
    // Arrange:
    testInt = 100;
    stack_init();
    
    // Act:
    stack_push(30);
    stack_push(40);
    stack_push(50);
    
    // Assert:
    assert(0 == stack_pop(&testInt));
    assert(50 == testInt);

    assert(0 == stack_push(60));

    assert(0 == stack_pop(&testInt));
    assert(60 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(40 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(30 == testInt);

    // ***********************************************************************
    // Test6: Fill queue and retrieve all items. Do it twice in a row.
    // ***********************************************************************
    // Arrange:
    testInt = 100;
    stack_init();
    
    // Act:
    stack_push(30);
    stack_push(40);
    stack_push(50);
    
    // Assert:
    assert(0 == stack_pop(&testInt));
    assert(50 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(40 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(30 == testInt);

    assert(0 == stack_push(60));
    assert(0 == stack_push(70));
    assert(0 == stack_push(80));
    
    assert(1 == stack_push(100));

    assert(0 == stack_pop(&testInt));
    assert(80 == testInt);
   
    assert(0 == stack_pop(&testInt));
    assert(70 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(60 == testInt);

    return 0;
}
