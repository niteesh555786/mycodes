#include <stdio.h>
/*
Program to study :
    void pointer   

refer : about void.txt
see : voidPointers.png
  
*/

int main()
{
    int i = 10;
    double d = 1.23456;
    char c = 'z';
    
    void *p;//a generic pointer
    
    p = &i;//refers to an int
    printf("\n i : %d ", *(int*)p);
    
    p = &d;//refers to a double
    printf("\n d : %f ", *(double*)p);
    
    p = &c;//refers to a char
    printf("\n c : %c ", *(char*)p);
            
    return 0;
}

