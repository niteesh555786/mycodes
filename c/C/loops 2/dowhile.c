#include <stdio.h>
/*
Program to demonstrate
do while loop
*/

int main() 
{
    int x;
    //case I : Demo of many executions of loop statements
    /*
    x = 1;//initialization
    do
    {
        printf("\n %d ", x);
        x++;//reinitialization
    }while(x < 11);//condition
    */
    //case II : Demo of one execution of loop statements
    /*    
    x = 100;//initialization
    do
    {
        printf("\n %d ", x);
        x++;//reinitialization
    }while(x < 11);//condition
    */
    //case III : Ensure that user input is a positive value
    
    do
    {
        printf("\n Enter a positive number ");
        scanf("%d", &x);
    }while(x < 0);
    
    printf("\n You Entered : %d ", x);
    
    return 0;
}
