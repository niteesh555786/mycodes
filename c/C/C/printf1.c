//Declaring a variable
//Assigning a value to it
//Printing it

#include<stdio.h>//include in this program, all predefined functions of the header file stdio.h

int main() //program starts here
{
    int a; //declare a variable
    a = 12; //assign a value to it
    printf("\n a : %d", a);//output value of variable a in decimal form (%d)
    printf("\n a : %x", a);//output value of variable a in hexadecimal form (lowercase) (%x)
    printf("\n a : %X", a);//output value of variable a in hexadecimal form (uppercase) (%X)
    printf("\n a : %o", a);//output value of variable a in octal form  (%o)
    
    return 0;//execution completed successfully
}//program ends here