#include <stdio.h>

//unitIncrement
//refer unitIncrement1.png

int main() //program starts here
{
    int a, b, c;
    
    //assign default values
    a = 10;
    b = 20;
    c = a++ * ++b;
    
    //print them
    printf("\n a : %d ",a );//11
    printf("\n b : %d ",b );//21
    printf("\n c : %d ",c );//210
    
    return 0;
}//program ends here
