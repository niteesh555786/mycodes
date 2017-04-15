#include <stdio.h>
#include <string.h>

/*
Implementing String Operations  
    String Length

See the diagram 
*/

int slen(char s[])
{
    int i;
    i =0 ;
    while(s[i] != '\0')
    {
        i++;
    }
    return i;
    
}

int main()
{
    char str[20];
    int x;
    
    printf("\n Enter a string ");
    scanf("%19s", str);
    
    //ready function to get the length of the string
    //x = strlen(str);
    x = slen(str);
    
    printf("\n String : %s ", str);
    printf("\n Length : %d ", x);
    
    return 0;
}
