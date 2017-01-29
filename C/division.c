//Demonstration of : division
#include<stdio.h>//include in this program, all predefined functions of the header file stdio.h

int main() //program starts here
{
    int q, r;
    q = 19 / 8; //quotient
    r = 19 % 8;//remainder
    
    printf("\n 19 / 8 : %d ", q);
    printf("\n 19 %% 8 : %d ", r); //%% to output %
    
    return 0;//execution completed successfully
}//program ends here