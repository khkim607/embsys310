#include<assert.h>

int myIntArray[5] = {40, 41, 42, 43, 44};
int isLittleendianType(char* p);

int main()
{
    int result; // for assert check
    int myInt = 0x77778888;
    int* pInt = &myInt;
    *pInt = 0x41424344; //'ABCD' in character
    char* pChar = (char*)&myInt; // pickup 'D' for littleEdnian or 'A' for bigEndian
    
    result = isLittleendianType(pChar); //call for endian tpte
    // assert(1 == result); // Little Edian
    assert(2 == result);  // Big Endian
         
    return 0;
}

int isLittleendianType(char* p)
{
    if (*p == 'A')
    {
        return 2;
    }
    else if (*p == 'D')
    {
        return 1;
    }
    return 0;
}


