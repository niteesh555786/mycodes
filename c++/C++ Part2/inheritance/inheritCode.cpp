//Program to demonstrate : 
//Inheritance of code
//refer : inheritance.txt
//see : inheritCode.png

#include <iostream>
using namespace std;

class A
{
public:
    void f1();
    void f2();
};

void A :: f1()
{
    cout<<"\n A f1()";
}

void A :: f2()
{
    cout<<"\n A f2()";
}

class B : public A
{
public:
    void f2();
    void f3();
    
};

void B :: f2()
{
    cout<<"\n B f2()";
}
void B :: f3()
{
    cout<<"\n B f3()";
}

int main()
{
   B objB; 
   objB.f1();//inherited code
   objB.f2();//overridden code
   objB.f3();//extended code
   
   return 0;
}