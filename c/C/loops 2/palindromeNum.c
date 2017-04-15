#include <stdio.h>
/*
 Program to check whether a
 number is a palindrome number
 or not.
 */

int main() 
{
    int no,ld,ans;
    int backup;
    
    printf("\n Enter a number ");
    scanf("%d", &no);
    
    backup = no;

    ans = 0; //important
    while(no > 0)
    {
        ld = no % 10; //fetch the last digit
        ans = ans * 10 + ld;//concatenate it to the ans
        no = no/10;//eliminate the last digit
    }//while
    
    no = backup; //restore the number
    
    //ans is reverse of the number

    if(no == ans)
        printf("\n %d is a palindrome number ", no);
    else
        printf("\n %d is not a palindrome number ", no);
        
        
    return 0;
}
