#include<stdio.h> 
#include<arith.h>
#include<arith.h>//multi includes ignored by the compiler due to use of conditional compilation directives

/*
Demonstration of : Storage Class Specifiers  
//see : division of main memory.png (in pointers)
//refer :  about storage class specifiers.txt
*/

void f()
{
    int a = 10; //local variable (storage class : auto)
    static int b=10;//local variable (storage class : static)
    
    printf("\n a : %d and b : %d ", a, b);
    a++;
    b++;
}//life of "a" gets over, but "b" remains


int main()
{
    register int i; //local declaration (storage class : register)
    int res;//local declaration (storage class : auto)
    extern int q;//tag to the external resource (storage class : extern)
    
    
    for(i =1; i<10000; i++)
    {
        //some use of i 
        //...
        //i declared as register because of its frequent use, which must be made fast.
    }
    //life and usability test
    //storage class test
    f();
    f();
    f();
    
    printf("\n q : %d , &q : %x ", q, &q);
    printf("\n &res :  %x ", &res);
    
    res = add(1, 2);
    printf("\n 1 + 2 : %d ", res);
    res = subtract(1, 2);
    printf("\n 1 - 2 : %d ", res);
    res = multiply(1, 2);
    printf("\n 1 * 2 : %d ", res);
    res = divide(1, 2);
    printf("\n 1 / 2 : %d ", res);
    return 0;
}//main
