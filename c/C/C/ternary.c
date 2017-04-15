#include <stdio.h>
//Ternary Operator  ?:
//Refer the note below.

int main() 
{
    int a, b, c;

    a = 25;
    b = 20;
    
    c = a > b ? a*a : b*b*b;
        
    printf("\n a : %d ", a);
    printf("\n b : %d ", b);
    printf("\n c : %d ", c);
    
    return 0;
}
/*
A ternary operator is an operator 
that acts on 3 operands. 
C supports one ternary operator ?:  
 
Its syntax is as follows: 
  condition ? expressionOnTrue : expressionOnFalse 
 
It evaluates the condition and 
results in a boolean. 
When the boolean value is true 
then it executes the expressionOnTrue 
and skips the expressionOnFalse. 

But when the boolean value is false 
then it executes the expressionOnFalse 
and skips the expressionOnTrue. 
*/