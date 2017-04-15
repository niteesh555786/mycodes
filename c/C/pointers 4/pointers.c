#include <stdio.h>
/*
 Program to demonstarte:
      Pointers 
 
 * refer about pointers.txt
 * see pointers.png
 */

int main()
{
    int x; //an int variable
    int *p;//an int pointer
    
    //write by name
    x = 10; 
    
    //write by address
    p = &x; //referencing
    *p = 99;//dereference the pointer for writing
   
    //read by name
    printf("\n %d ", x);

    return 0;
}

