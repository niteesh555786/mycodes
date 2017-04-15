//Program to demonstrate : Default Values To Arguments
//Read the note below

#include <iostream>

using namespace std;

class Demo
{
public: //will discuss later
    int a, b;
    
    Demo();
    void display();
    void increment();
    ~Demo();
};

Demo :: Demo()
{
    cout<<"\n Demo()";
    a = 10;
    b = 20;
}
void Demo :: display()
{
    cout<<"\n"<<a<<" "<<b;
}

void Demo :: increment()
{
    a++;
    b++;
}


Demo :: ~Demo()
{
    cout<<"\n ~Demo()";
}

int main()
{
    Demo d;
    d.display();
    d.increment();
    d.display();
}
/*
 In C++, a class contains declarations of
 member variables , member functions, 
 constructors, destructor, ... 
 
 The member variables get defined as 
 object of the class is created.
 
 The constructors, destructor, member 
 functions must be defined outside the 
 class.
 
 Known that C++ supports definition of 
 non member functions also.
 Non member functions are function that 
 belong to the program.
 
 If a member function is defined outside
 a class then it may appear to be a non
 member function.
 
 To distinguish between a non member function
 and a member function that is defined outside
 the class, the signature of the member function
 is modified as follows :
 
 returnType className :: functioName(parameters)
 {} 
 
 Here :: is the Scope Resolution operator
 which specifies that the function is not a
 non member function but belongs to ( a 
 member of ) specified class.
 */