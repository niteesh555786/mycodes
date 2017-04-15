#include <stdio.h>

/*
 Case Convertor
 Interpret the code and comment
 See the diagram 
*/

void upperCase(char s[])
{
    int i;
    i =0 ;
    while(s[i] != '\0')
    {
        if(s[i] >= 97 && s[i] <= 122) //i.e. s[i] is an alphabet in lower case 
        {
            s[i] = s[i] - 32; //change to uppercase
        }//if
        i++;
    }//while
    
}//upperCase

void lowerCase(char s[])
{
    int i;
    i =0 ;
    while(s[i] != '\0')
    {
        if(s[i] >= 65 && s[i] <= 90) //i.e. s[i] is an alphabet in upper case 
        {
            s[i] = s[i] + 32; //change to lowercase
        }//if
        i++;
    }//while

}

void toggleCase(char s[])
{
    int i;
    i =0 ;
    while(s[i] != '\0')
    {
        if(s[i] >= 65 && s[i] <= 90) //i.e. s[i] is an alphabet in upper case 
        {
            s[i] = s[i] + 32; //change to lowercase
        }//if
        else if(s[i] >= 97 && s[i] <= 122) //i.e. s[i] is an alphabet in lower case 
        {
            s[i] = s[i] - 32; //change to uppercase
        }//if

        i++;
    }//while
}

int main()
{
    char str[20];
    int flag = 1;
    int ch;
    
    do
    {
        printf("\n 1. Convert to UPPERCASE ");
        printf("\n 2. Convert to lowercase ");
        printf("\n 3. Convert to toggleCASE ");
        printf("\n 4. Exit ");
        printf("\n Enter Choice : ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1://UPPERCASE
                printf("\n Enter a string to convert to uppercase : ");
                fflush(stdin);
                scanf("%19s", str);
                printf("\n String : %s ", str);
                upperCase(str);
                printf("\n String : %s ", str);
                break;
            case 2://lowercase
                printf("\n Enter a string to convert to lowercase : ");
                fflush(stdin);
                scanf("%19s", str);
                printf("\n String : %s ", str);
                lowerCase(str);
                printf("\n String : %s ", str);
                break;
            case 3://toggleCASE
                printf("\n Enter a string to convert to togglecase : ");
                fflush(stdin);
                scanf("%19s", str);
                printf("\n String : %s ", str);
                toggleCase(str);
                printf("\n String : %s ", str);
                break;
            case 4://exit
                flag =0 ;
                break;
            default:// wrong input
                printf("\n Wrong Choice ");
                break;
        }//switch
        
    }while(flag == 1);
    
    return 0;
}
