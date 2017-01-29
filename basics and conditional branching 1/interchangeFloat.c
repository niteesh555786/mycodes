#include <stdio.h>
/*
 Program to interchange the 
 floating point value with 
 decimal value of a number.
 
 
 program may be affected
 by the precision of float
 */

int main() 
{
    float no;
    int i, j;
    printf("\n Enter a number ");
    scanf("%f", &no);//737.501
    
    //get its int equivalent
    i = no; //737
    
    //get its floating point values
    j = (no - i) * 1000; //501

    //interchange 
    no = j  + i /1000.0;

    //result
    printf("\n no : %f ", no);
    return 0;
}
