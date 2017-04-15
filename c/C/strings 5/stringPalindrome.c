#include <stdio.h>

/*
Implementing String Operations  
   String Palindrome Check

See the diagram 
*/

int slen(char s[])
{
    int x;
    x =0 ;
    while(s[x] != '\0')
    {
        x++;
    }
    return x;
    
}

int palindrome(char s[])
{
    int i, j;
    
    i =0 ; //left boundary
    j = slen(s) -1; //right boundary

    while(i < j)
    {
        if(s[i] != s[j])
            return 0; //false
        
        //continue
        i++;
        j--;
    }//while
    
    //all matched
    return 1;//true
}

int main()
{
    char str[20];
    int flag;
    
    printf("\n Enter a string ");
    scanf("%19s", str);

    flag = palindrome(str);
    if(flag == 1)
        printf("\n %s is a palindrome ", str);
    else
        printf("\n %s is not a palindrome ", str);
    
    return 0;
}
