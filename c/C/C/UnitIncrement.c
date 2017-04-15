//Demonstration of : ++
#include<stdio.h>//include in this program, all predefined functions of the header file stdio.h

int main()
{
    int a, b, c;
    a = 10;
    printf("\n a : %d ", a);//10
    ++a;
    printf("\n a : %d ", a);//11
    a++;
    printf("\n a : %d ", a);//12
    
    //a is 12
    b = 10;
    //c = a++ * b;
    c= ++a *b;
    
    printf("\n a : %d ", a);
    printf("\n b : %d ", b);
    printf("\n c : %d ", c);
    
    return 0;
}