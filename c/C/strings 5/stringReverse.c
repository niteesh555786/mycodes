#include <stdio.h>
#include <string.h>

/*
Implementing String Operations  
    String Reverse

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

void srev(char s[])
{
    int i, j;
    char temp; //for swapping
    
    i =0 ; //left boundary
    j = slen(s) -1; //right boundary

    while(i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        
        //reset the boundaries
        i++;
        j--;
    }//while
    
}

int main()
{
    char str[20];
    
    printf("\n Enter a string ");
    scanf("%19s", str);

    printf("\n String : %s ", str);

    //ready function to reverse the string
    //strrev(str);
    srev(str);

    printf("\n String : %s ", str);
    
    return 0;
}
