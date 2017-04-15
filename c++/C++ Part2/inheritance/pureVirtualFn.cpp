//Program to study : 
//Pure Virtual Functions
//Abstract Class
//refer : inheritance.txt
//see : pureVirtualFn.png

#include <iostream>
using namespace std;

class A
{//abstract class
public:
    void f1();
    //pure virtual function
    virtual void f2() = 0;
};

void A :: f1()
{
    cout<<"\n A f1()";
}

//inheritance
class B : public A
{
public:
    void f2();
};

void B :: f2()
{
    cout<<"\n B f2()";
}


int main()
{
    B objB;
    objB.f1();
    objB.f2();
    return 0;
}
