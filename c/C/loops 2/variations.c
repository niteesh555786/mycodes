#include <stdio.h>
/*
Program to demonstrate
variations in loop usage.
*/

int main() 
{
    int x;
/*    
    x = 10;
    while(x--)//Order of evaluation : evaluate x as boolean, decrement x
        printf("\n %d", x); //9,8,....,0
    printf("\n ----");
    printf("\n %d", x);//-1         
*/            
/*    
    x = 1;
    while(x < 11)
        printf("\n %d", x++);//order of execution : print curr val of x, increment x //1,2,...,10
    printf("\n ----");
    printf("\n %d", x);//11
*/
/*   
    x = 1;
    while(x < 11)
        printf("\n %d", ++x);//order of execution : increment x, print val of x //2,3,...,11
    printf("\n ----");
    printf("\n %d", x);//11
*/    
/*    
    x = 10;
    while(--x);// ; makes it a DO-NOTHING (WITHOUT A BODY) loop, Decrements x first and then evaluates x as boolean
        printf("\n %d", x);//ZERO
*/
/*    
    x = 10;
    while(x--);// ; makes it a DO-NOTHING (WITHOUT A BODY) loop, first evaluates x as boolean and then decrements x 
        printf("\n %d", x);//-1
*/
  for(x=10; x--; printf("\n %d",x));//ANOTHER DO NOTHING LOOP prints 9-0     
        
//... will add more         
    return 0;
}
