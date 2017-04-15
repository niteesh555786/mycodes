#include<stdio.h> 
/*
  goto statement

C supports definition of labels (named locations in a program)
and use of goto statement to make the program control jump 
to the associated label. 

TIP 
 Use of goto statement to control program flow
 must not be promoted. It is kind of backward 
 compatibility feature that languages before C
 used.
 */

int main()
{    
    int i= 1;
    while(i) //value of i converts to a boolean and control loop cycles
    {
        printf("\n %d ", i);
        i++;
        if(i == 11)
            goto PRGEND;
    }

PRGEND: //label
    //some code possible here 
    printf("\n BYE");
    return 0;
}//main
