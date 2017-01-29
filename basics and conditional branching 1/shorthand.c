#include <stdio.h>

/*
shorthand operators
------------------- 
 
C supports following set of shorthand operators :  
 +=, -=, *=, /=, %=, &=, ^=, |=, <<=, >>=  
They expand as :
  x+=y :  x = x+y
  x-=y :  x = x-y
  ...
Refer the example.
 */

int main() 
{
    int i, j, k;
    
    printf("\n Enter 2 numbers ");
    scanf("%d%d", &i, &j);
    
    //say i is 5 and j is 6
    //i +=j;//i = 11, j = 6, k = garbage
    k = i +=j;//i = 11, j = 6, k = 11
    
    printf("\n i : %d ", i);
    printf("\n j : %d ", j);
    printf("\n k : %d ", k);
    return 0;
}
