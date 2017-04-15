#include <stdio.h>

//program to demonstarte 
//use of scanf

//refer streams.txt
//see scanf.png
int main() 
{
    int no, sqr;
    
    printf("\n Enter a number ");
    scanf("%d", &no);//%d tells scanf to fetch a decimal value and &no gives the memory location of the variable
    sqr = no * no;
    printf("\n Square of %d is %d", no, sqr);
    
    return 0;
}
