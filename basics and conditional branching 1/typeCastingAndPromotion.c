#include <stdio.h>
/*
Type Casting and Promotion
------------------------ 

 In C, an expression with
 operands of same datatype
 result in a value of that
 corresponding type only. 
 
 Type Casting is explicit
 temporary conversion of 
 value of one datatype into
 another compatible datatype.
 
 
 Type Promotion is automatic
 conversion of result of an
 expression into a higher precision
 type when the expression 
 uses operands of lower and higher
 precision types both.
 */

int main() 
{
    int i, j;
    float ans;
    i = 10;
    j = 4;
    //TYPE CASTING
    //ans = (float)i/j; // temporary conversion of i into a float value
    ans = i/(float)j; // temporary conversion of j into a float value
    
    //TYPE PROMOTIONS
    //ans = 1.0 * (i/j);//Solving Sequence : ( / ) and then *. Division results in int value which is multiplied with a float
    //ans = 1.0 * i/j;//Solving Sequence : * and then /. Multiplication results in float value (type promotion) which is divided by an int resulting in a float
    printf("\n ans : %f ", ans);
    return 0;
}
