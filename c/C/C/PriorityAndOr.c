#include <stdio.h>
//Priority Check : && and ||
//See : Combining Conditions.png

int main() 
{
    int a, b, c;
    a = 10;
    b = 5;
    c = 20;
    //    F         T           T
    if(a < b && b == 5 || c < 100)
    {
        printf("\n Priority of && is more than that of || ");
    }
    else
    {
        printf("\n Priority of || is more than that of && ");
    }        
    
    return 0;
}
