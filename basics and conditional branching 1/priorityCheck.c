#include <stdio.h>
//priority check
//refer : priority.png

int main() 
{
    int i, j, k;
    i = 5;
    j = 20;
    
    //k = 10 * i > j;// solving sequence :  * , >
    //k = i < j > 0;//solving sequence : < , >
    k = -i - j; //- associated with i is negation (is solved first) and the - between i and j is subtraction (is solved next)
    printf("\n i : %d ", i);
    printf("\n j : %d ", j);
    printf("\n k : %d ", k);
    return 0;
}
