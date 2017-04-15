#include <stdio.h>

//swap 2 numbers in 2 ways
//refer "swap in 2 ways.png"

int main() //program starts here
{
    int a, b, temp;
    
    //assign default values
    a = 10;
    b = 20;
    
    //print them
    printf("\n a : %d ",a );
    printf("\n b : %d ",b );
    
    //swap (interchange) a and b using third variable temp
    //temp = a;
    //a = b;
    //b = temp;
    
    //swap (interchange) a and b without using third variable c
    a = a + b;
    b = a - b;
    a = a - b;
   
    //print them
    printf("\n a : %d ",a );
    printf("\n b : %d ",b );
    
    return 0;
}//program ends here
