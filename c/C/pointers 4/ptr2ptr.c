#include <stdio.h>
/*
Program to study :
  pointer to a pointer

refer : about pointers.txt
see : ptr2ptr.png
interpret the example
*/

int main()
{
    int i; // an int variable
    int *p; // an int pointer
    int **q; // an int pointer to a pointer
    
    i = 10; //assignment of a value
    p = &i; //referencing
    q = &p; //referencing
    
    //access by name
    printf("\n i : %d ", i);
    //access by dereference
    printf("\n i : %d ", *p);
    //access by double dereference
    printf("\n i : %d ", **q);
    
    return 0;
}
