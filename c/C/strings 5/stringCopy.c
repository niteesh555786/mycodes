#include <stdio.h>
#include <string.h>

/*
 Implementing : String Copy
*/

void scopy(char trgt[], char src[])
{
    int x;
    x = 0;
    while(src[x] != '\0')
    {
        trgt[x] = src[x];
        x++;
    }
    //trgt string is not assigned '\0' marker
    trgt[x] = '\0'; //mark EOS
}

int main()
{
    char str1[20], str2[20];
    
    printf("\n Enter a string ");
    scanf("%19s", str1);
    
    //ready function to copy a string
    //strcpy(str2,str1);
    scopy(str2, str1);
    
    printf("\n str1 : %s ", str1);
    printf("\n str2 : %s ", str2);
    
    return 0;
}
