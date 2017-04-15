#include <stdio.h>
/*
 Priority Check between
 Logical And and Logical Or.
 
 Conclusion : Logical And is More Prior than Logical Or
 */

int main() 
{
    int i, j, k;
    i = 1;
    j = 2;
    k = 3;
    //   F   &&   T   ||   T
    if(i == 0 && j > i || k < 10)
    {
        printf("\n Logical And is more prior than Logical Or");
    }
    else
    {
        printf("\n Logical Or is more prior than Logical And");
    }        
    return 0;
}
