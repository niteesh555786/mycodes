#include <stdio.h>

//unitIncrement
//refer unitIncrement.txt

int main() //program starts here
{
    int a, b, c;
    
    //assign default values
    a = 10;
    
//here ++ is applied as a post increment operator
//so it will act with least priority
//hence system will solve = first and ++ next
    
    b = a++; //b : 10 and a : 11

//here ++ is applied as a pre increment operator
//so it will act with highest priority
//hence system will solve ++ first and = next
    
    c = ++a;// c : 12 and a : 12
    
    //print them
    printf("\n a : %d ",a );//12
    printf("\n b : %d ",b );//10
    printf("\n c : %d ",c );//12
    
    return 0;
}//program ends here
