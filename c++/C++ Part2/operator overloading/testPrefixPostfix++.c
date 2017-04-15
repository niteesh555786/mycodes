//Program to test: 
//prefix and postfix usage of ++
#include <iostream>
using namespace std;

int main()
{
    int x ;
    int y;
    
    x = 10;
    y = x++; //increments x but returns the old value
    //y = ++x; //increments x and returns the incremented value
    
    cout<<"\n x : "<<x;
    cout<<"\n y : "<<y;
}
