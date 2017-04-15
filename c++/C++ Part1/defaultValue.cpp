//Program to demonstrate : Default Values To Arguments
//Read the note below

#include <iostream>

using namespace std;

void add(int a, int b , int c=0, int d= 0)
{
    int sum;
    sum = a+b+c+d;
    cout<<"\n Addition : "<<sum;
}

int main()
{
    add(1,2);
    add(1,2,3);
    add(1,2,3,4);
}

/*
 C++ supports application of default
 values to formal parameters of a function
 or a constructor.
 
 When a function or a constructor
 assigns default values to its formal
 parameters then it could be invoked 
 with less number of actual parameters.
 
 When the number of actual parameters
 is less, then for the missing actual
 parameters the formal parameters
 would take the default values.
 
 When sufficient actual parameters are 
 are passed then the formal parameters
 take the value of the actual parameters.
 
 Rule :
 If a formal parameter is assigned
 a default value then all the parameters
 that follow it, must also be assigned
 default values.
 
 FYI :
 The default value must be such
 that on use it should not have adverse
 affect on the result of the process.
 */