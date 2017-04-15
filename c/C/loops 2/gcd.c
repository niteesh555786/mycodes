#include <stdio.h>
/*
 Program to demonstrate
 while loop
 
 Example : Find factors of a number
 
 */

int main() 
{
    int n1, n2;
    int i;
    printf("\n Enter 2 numbers ");
    scanf("%d%d", &n1, &n2);

//find the smaller of 2 numbers
//and use it as initializer    
    if(n1 < n2)
        i = n1;
    else
        i = n2;

    while(i >= 1)//condition
    {
        if(n1%i==0 && n2%i==0)
        {
            printf("\n GCD : %d ", i);
            //terminate the loop
            break;
        }//if
        
        i--;//unit decrement
    }//while
    return 0;
}
