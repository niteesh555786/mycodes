#include <stdio.h>
/*
 Program to demonstrate :
 functions

 Refer : about functions.txt
 See : functions.png
 */

void f()
{
    printf("1");
    printf("2");
    printf("3");
}

int main() //signature (prototype)
{//body (definition)
    printf("A");
    printf("B");
    f();//call to f()
    printf("C");
    printf("D");
    printf("E");
    return 0;
}

