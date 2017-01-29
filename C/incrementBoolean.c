#include <stdio.h>
//Increment and Boolean 

int main() 
{
    int a = 1;
    if(a--)
        printf("\n Hello %d ", a);
    else
        printf("\n Hi %d ", a);

    return 0;
}
/*
 For the statement : if(a--)
 System has to evaluate : condition, decrement.
 Order of evaluation will be : condition (a as boolean) and then decrement because it is a post decrement
 * a as boolean is 1 is TRUE
 * decrement a to make it 0
  
 Condition evaluation being TRUE makes the system execute
 the code associated with "if".
 So the output : Hello 0
 */