#include <stdio.h>
/*
 Program to demonstrate :
 PASS BY VALUE

 Refer : about functions.txt
 */

void f(int q)//q is declared as a formal parameter
{
    printf("\n in f, q : %d ", q);
    q++;
    printf("\n in f, q : %d ", q);
}

int main()
{
    int x;//local variable
    x = 10;
    printf("\n in main, x : %d ", x);
    f(x);//call to f with x as actual parameter
    printf("\n in main, x : %d ", x);
    return 0;
}

