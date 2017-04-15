#include <stdio.h>
#include <string.h>

/*
 Implementing : String Concatenation
*/

int slen(char s[])
{
    int i;
    i =0;
    while(s[i] != '\0')
        i++;
    
    return i;
}


void scat(char s1[], char s2[])
{//concatenate s2 to s1
    int x, y;
    x = 0; 
    y = slen(s1);
    
    while(s2[x] != '\0')
    {
        s1[y] = s2[x];
        x++;
        y++;
    }
    //mark EOS for s1
    s1[y] = '\0';
    
}

int main()
{
    char str1[20], str2[20];
    
    printf("\n Enter a string ");
    scanf("%19s", str1);
    printf("\n Enter another string ");
    fflush(stdin);
    scanf("%19s", str2);

    printf("\n str1 : %s ", str1);
    printf("\n str2 : %s ", str2);
    
    //ready function to concatenate string
    //ensure that str1 has room to accomodate str2
    //strcat(str1,str2);
    scat(str1, str2);
    
    printf("\n str1 : %s ", str1);
    printf("\n str2 : %s ", str2);
    
    return 0;
}
