#include <stdio.h>
/*
Program to study importance of
    Size and Datatype
         of Pointer   

refer : about pointers.txt
see the diagram
analyze the output of the program  
 
*/

int main()
{
    int *ip;
    double *dp;
    char *cp;
    
    printf("\n size of pointers");
    printf("\n ip : %d ", sizeof(ip));
    printf("\n dp : %d ", sizeof(dp));
    printf("\n cp : %d ", sizeof(cp));
    
    printf("\n\n amount of memory a pointer dereferences");
    printf("\n ip : %d ", sizeof(*ip));
    printf("\n dp : %d ", sizeof(*dp));
    printf("\n cp : %d ", sizeof(*cp));
    
    printf("\n\n pointer arithmetic (adding 3) ");
    printf("\n ip : %u  ip+3 : %u ", ip, ip+3);
    printf("\n dp : %u  dp+3 : %u ", dp, dp+3);
    printf("\n cp : %u  cp+3 : %u ", cp, cp+3);
    
    return 0;
}

