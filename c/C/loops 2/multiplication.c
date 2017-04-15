#include <stdio.h>
/*
 Program to demonstrate
 while loop
 
 Example : Generate multiplication table of a number
 Refer : loops.txt
 See : multiplication.png 
 
 */

int main() 
{
    int i, ans, n;
    
    printf("\n Enter the number to generate the multiplication table ");
    scanf("%d", &n);
    
    i = 1;
    while(i <= 10)
    {
        ans = n * i;
        printf("\n %d * %d = %d ",n,i,ans);
        i++;
    }
    return 0;
}
