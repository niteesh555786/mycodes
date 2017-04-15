#include <stdio.h>
//Priority Check
//See prioity.png

int main() 
{
    int a, b, c;
    
    a = 10;
    b = 5;
    //c = (a+b) % 2 * 3;// priority (), *, %
    //c = -a - b;// negation - , subtraction -
    c = a > b + 10;// +, >
    
    printf("\n c : %d", c);
    return 0;
}
