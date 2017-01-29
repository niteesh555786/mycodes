#include<stdio.h>
//implementing recursion to find factorial of a number

/*
 Analysis
 5! = 5 * 4 * 3 * 2 * 1
 4! = 4 * 3 * 2 * 1 
 Hence
 5! = 5 * 4!
 In generalized form:
 n! = n * (n-1)!
 Also known that :
 0! = 1
 */

int factorial(int n)
{
    //return n == 0 ? 1 : n * factorial(n-1);
    
    if(n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

int main()
{
    int a, ans;
    a = 5; //scan
    
    ans = factorial(a);
    printf("\n %d! : %d ",a, ans);
    
    return 0;
}
