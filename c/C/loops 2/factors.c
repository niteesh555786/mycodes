#include <stdio.h>
/*
 Program to demonstrate
 while loop
 
 Example : Find factors of a number
 
 */

int main() 
{
    int i, n;
    printf("\n Enter the number, to find factors of ");
    scanf("%d", &n);
    
    printf("\n Factors of %d are : ", n);
    i = 1;//smallest factor
    while(i <= n) //n largest factor
    {
        if(n % i == 0)
        { // i is a factor
            printf(" %d ", i);
        }
        i++;//unit change
    }//while
    return 0;
}
