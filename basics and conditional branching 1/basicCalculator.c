#include <stdio.h>
/*
 Basic Arithmetic Calculator
 
 Demonstration of switch selection statement. 
 refer switch.txt
 */

int main() 
{
    float n1, n2, ans;
    int ch;
    
    printf("\n Enter 2 numbers ");
    scanf("%f%f", &n1, &n2);
    
    //menu 
    printf("\n 1. Addition ");
    printf("\n 2. Subtraction ");
    printf("\n 3. Multiplication ");
    printf("\n 4. Division ");
    printf("\n Enter Choice ");
    scanf("%d", &ch);
    
    switch(ch)
    {
        case 1: //when ch == 1
            ans = n1+n2;
            printf("\n %10.2f + %.2f = %.2f ", n1, n2, ans);
            break;//to terminate the switch
        case 4: //when ch == 4
            ans = n1/n2;
            printf("\n %.2f / %.2f = %.2f ", n1, n2, ans);
            break;//to terminate the switch
            
        case 2://when ch == 2
            ans = n1-n2;
            printf("\n %.2f - %.2f = %.2f ", n1, n2, ans);
            break;//to terminate the switch

        default : //when ch != (1||2||3||4)
            printf("\n Invalid Choice ");
            break;
        case  5-2://when ch == 3
            ans = n1*n2;
            printf("\n %.2f * %.2f = %.2f ", n1, n2, ans);
            break;//to terminate the switch

    }//switch
    
    return 0;
}
