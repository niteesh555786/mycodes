#include<stdio.h>
//implementing recursion to print a string in reverse

void revPrint(char *s, int indx, int len)
{
    if(indx < len)
    {
        revPrint(s, indx+1, len);
        printf("%c", *(s+indx) );
    }
}

int main()
{
    revPrint("computer", 0, 8);
    return 0;
}
