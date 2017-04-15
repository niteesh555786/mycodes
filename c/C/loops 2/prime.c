#include <stdio.h>
/*
Program to check whether
a given number is a prime
number or not 
 */

int main() 
{
    int no, i;
    int half;
    int x;//state indicator
    
    printf("\n Enter a number ");
    scanf("%d", &no);//25
    
    //set the flag (state indicator) as per choice
    x = 1;
    
    //check for factors in range
    //2 to no/2
    half = no/2 ;
    
    for(i =2; i <= half; i++)
    {
        if(no % i == 0)
        {//i is a factor of no
            x = 0;//change the flag (state indicator)
            break;//stop the loop
        }//if
    }//for
    
    //check the flag (state indicator)
    if(x == 1)
        printf("\n %d is a prime number ", no);
    else
        printf("\n %d is not a prime number ", no);

    return 0;
}
