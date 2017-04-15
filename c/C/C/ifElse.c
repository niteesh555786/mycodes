#include <stdio.h>

//1) Implement Conditional Branching
// Refer : conditional branching.txt
// See : if-else.png

//2) Using comparison operator : ==
// == is a comparison operator.
//It compares the two operands for equality.
//When found equal, it returns TRUE
//Otherwise it returns FALSE

//3) Understanding float and double values
//A float variable stores values with some tolerance.
//Constant value 1.2345 acts as a double.
//Constant value 1.2345F acts as a float.
//A double variable stores values with double precision.

int main() 
{
    float f;
    double d;
    
    f = 1.2345;//stores with tolerance
    d = 1.2345;//stores with double precision

//case 1:    
    if(f == 1.2345)//comparison between a float variable and a double constant
    {
        printf("\n A");
    }
    else
    {//false, because precision difference is observed.
        printf("\n B");
    }
    
//case 2:
    if(d == 1.2345)//comparison between a double variable and a double constant
    {//true, because both are same and stored with double precision
        printf("\n A");
    }
    else
    {
        printf("\n B");
    }

//case 3:    
    if(f == 1.2345F)//comparison between a float variable and a float constant
    {//true, as both operands are of single precision, hence tolerance is allowed.
        printf("\n A");
    }
    else
    {
        printf("\n B");
    }

//case 4:    
    if(f == d)//comparison between a float variable and a double value
    {
        printf("\n A");
    }
    else
    {//false as difference between single and double precision is observed.
        printf("\n B");
    }
    
    return 0;
}
