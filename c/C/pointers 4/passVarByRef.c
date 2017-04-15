#include <stdio.h>
//Use of pointer to achieve
//Pass By Reference 
//for variables

void f(int *q)//formal parameter q gets the address of actual parameter
{
    printf("\n in f, *q : %d", *q);
    *q = 99;
    printf("\n in f, *q : %d", *q);
}

int main()
{
    int x;
    x = 10;
    printf("\n in main, x : %d ", x);
    f(&x);//call to f with address of x as actual parameter
    printf("\n in main, x : %d ", x);
    return 0;
}

