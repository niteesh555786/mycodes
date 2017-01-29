#include <stdio.h>

//more about scanf and stdin

int main() 
{
    int a, b, c;
    printf("\n Enter first number ");
    scanf("%d", &a);
    printf("\n Enter second number ");
    fflush(stdin);//clear the input stream, so that prg ctrl blocks for next user input
    scanf("%d", &b);
    c = a+b;
    printf("\n %d + %d = %d", a,b,c);
    
    return 0;
}
