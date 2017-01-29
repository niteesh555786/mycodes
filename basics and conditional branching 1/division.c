#include <stdio.h>

//Study of division opeator
//refer division.txt
//refer division.png

int main() 
{
    int a, b, q, r;
    
    //assign default values
    a = 15;
    b = 7;
    q = a / b;//quotient of division
    r = a % b;//remainder of division
    
    //print them
    printf("\n %d / %d : %d  ",a,b,q );//15 / 7 : 2
    printf("\n %d %% %d : %d ",a,b,r );//15 % 7 : 1

    return 0;
}
