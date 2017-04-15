#include <stdio.h>
#include <string.h>

/*
 Implementing : String Comparison
*/

int scompare(char *s1, char *s2)
{
    int i, x;
    i = 0;
    while( *(s1+i) != '\0' || *(s2+i) != '\0')
    {
        x = *(s1+i) - *(s2 +i);
        if(x != 0)
            return x;
        
        i++; //compare the next element
    }//while
    
    return 0; //equal string
}
/*
int scompare(char s1[], char s2[])
{
    int i, x;
    i = 0;
    while(s1[i] != '\0' || s2[i] != '\0')
    {
        x = s1[i] - s2[i];
        if(x != 0)
            return x;
        
        i++; //compare the next element
    }//while
    
    return 0; //equal string
}
*/ 

int main()
{
    char str1[20], str2[20];
    int diff;
    
    printf("\n Enter first string ");
    scanf("%19s", str1);

    printf("\n Enter second string ");
    fflush(stdin);
    scanf("%19s", str2);
    
    //ready function to compare two strings
    //diff = strcmp(str1, str2);
    diff = scompare(str1, str2);
    
    if(diff > 0)
        printf("\n %s > %s ", str1, str2);
    else if(diff < 0)
        printf("\n %s > %s ", str2, str1);
    else if(diff == 0)
        printf("\n %s == %s ", str1, str2);
    return 0;
}
