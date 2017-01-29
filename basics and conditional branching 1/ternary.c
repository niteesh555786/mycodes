#include <stdio.h>

/*
ternary operator
 
A ternary operator acts on 3 operands. 
C provides a ternary operator  ?: 
It is treated as a shorthand for conditional evaluation (like if). 
 
Syntax: 
 variable = condition ? exprOnTrue : exprOnFalse;  
 
 Refer the example.
 */

int main() 
{
    int i, j, k;
    
    printf("\n Enter 2 numbers ");
    scanf("%d%d", &i, &j);
    
    k = i > j ? i*i : j*j*j;//resolve the condition, on true assign square of i to k, on false assign cube of j to k
    
    printf("\n i : %d ", i);
    printf("\n j : %d ", j);
    printf("\n k : %d ", k);
    return 0;
}
