#include <stdio.h>
/*
 Program to reverse a number
 */

int main() 
{
    int no,ld,ans;
    
    printf("\n Enter a number ");
    scanf("%d", &no);
    
    printf("\n No : %d ", no);    
    ans = 0; //important
    while(no > 0)
    {
        ld = no % 10; //fetch the last digit
        ans = ans * 10 + ld;//concatenate it to the ans
        no = no/10;//eliminate the last digit
    }//while

    //no is zero and ans is its reverse
    //assign ans to no
    no = ans;
        
    printf("\n Reversed No : %d ", no);
    return 0;
}
