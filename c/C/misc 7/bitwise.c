#include <stdio.h>
/*
Program to demonstrate: 
  Bitwise Operations

 * Refer about bitwise.txt
 * See bitwise.png
*/

//simulator
void decimal2Binary(unsigned int x)
{
    int bits[32] = {0}; //all elements set to value ZERO
    int i;

    printf("\n %u : " , x);
    i = 31; //@last element 
    while(x > 0)
    {
        bits[i] = x%2;//remainder in bits[i]
        x = x /2;
        i--;//move left
    }//while
    
    //print rightwards
    for(i =0; i< 32; i++)
        printf("%d", bits[i]);
}

int main()
{
    int a,b,c;
    
    //a = 17;
    //b = 2;
    //c = a << b;
    //c = a >> b;
    //c = ~a;
    //decimal2Binary(a);
    //decimal2Binary(c);
    
    a = 17;
    b = 19;
    //c = a & b;
    //c = a | b;
    c = a ^ b;
    decimal2Binary(a);
    decimal2Binary(b);
    decimal2Binary(c);
    
    return 0;
}
