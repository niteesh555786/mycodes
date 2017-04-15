#include <stdio.h>

/*
 toggle case
 demonstrate using command line arguements 
*/

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

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("\n Wrong number of arguments ");
        return 1;
    }
    printf("\n String : %s ", argv[1]);
    toggleCase(argv[1]);
    printf("\n String : %s ", argv[1]);
    
    return 0;
}
