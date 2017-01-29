#include <stdio.h>

//demonstration of else if
//compare 2 numbers and 
//print the greatest

//refer : conditional branching.txt
//see : else if.png


int main() 
{
    int no1, no2;
    printf("\n Enter first number ");
    scanf("%d", &no1);//10
    printf("\n Enter second number ");
    fflush(stdin);//clear the input stream
    scanf("%d", &no2);//19
    
    if(no1 == no2)
    {
        printf("\n %d == %d", no1, no2);
    }
    else if(no1 > no2)
    {
        printf("\n %d > %d ", no1, no2);
    }
    else
    {
        printf("\n %d > %d ", no2, no1);
    }

    return 0;
}
