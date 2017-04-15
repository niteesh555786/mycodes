#include <stdio.h>
/*
Program to demonstrate : 
return. 

Refer : about functions.txt
See : fnReturn.png 
 */

int calSquare(int q)//formal parameter is declared as an array reference
{
    int result;
    result = q*q;
    return result;
}

int main()
{
    int no, sqr;
    
    printf("\n Enter a number ");
    scanf("%d", &no);
    sqr = calSquare(no);//It is optional to receive the returned value.
    printf("\n Square of %d is %d", no, sqr);
    return 0;
}
