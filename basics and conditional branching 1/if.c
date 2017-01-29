#include <stdio.h>

//Study of if statement
//Study of single and double precision values

//refer conditional branching.txt
//refer conditional branching.png
//refer the comments in code

int main() 
{
    float f;//store floating point values with single precision (some tolerance)
    double d;//store floating point values with double precision 
    
    f = 1.2345;//stores with some tolerance
    d = 1.2345;//stores 1.2345
    
    /*
// == compares the two sides for equality and returns a boolean
//case 1 : variable of low precision and constant of high precision
 * 
    if(f == 1.2345)//1.2345 is a high precision constant (double)
    {//to execute when condition associated with if is true
        printf("\n A");
    }
    else
    {//to execute when condition associated with if is false
        printf("\n B");
    }
  
//case 2 : variable and constant both of low precision
    if(f == 1.2345F) //1.2345F is a low precision constant (float)
    {
        printf("\n A");
    }
    else
    {
        printf("\n B");
    }    

//case 3 : variable of high precision and constant of low precision
    if(d == 1.2345F) //1.2345F is a low precision constant (float)
    {
        printf("\n A");
    }
    else
    {
        printf("\n B");
    }    

//case 4 : variable and constant both of high precision 
    if(d == 1.2345) //1.2345 is a high precision constant (double)
    {
        printf("\n A");
    }
    else
    {
        printf("\n B");
    }    
*/
//case 5 : variables of low and high high precision 
    if(f == d) 
    {
        printf("\n A");
    }
    else
    {
        printf("\n B");
    }    
    
    return 0;
}
