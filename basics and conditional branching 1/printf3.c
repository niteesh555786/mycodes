#include <stdio.h>

//demonstrating use of printf
//to print data stored in variable

//printf("formatCharacter", variableName);

int main() //program starts here
{
    //define an int variable
    //datatype variableName;
    int x; 
    
    //assign 26 to it
    x = 26;// = fetches data from RHS and puts into a variable on LHS
    
    //print x
    printf("\n %d ", x);// %d : prints value of an int in decimal form
    printf("\n %x ", x);// %x : prints value of an int in hexadecimal (lower case) form
    printf("\n %X ", x);// %X : prints value of an int in hexadecimal (upper case) form
    printf("\n %o ", x);// %o : prints value of an int in octal form
    printf("\n %i ", x);// %i : prints value of an int in integer form
    return 0;
}//program ends here

//about format characters, to be added