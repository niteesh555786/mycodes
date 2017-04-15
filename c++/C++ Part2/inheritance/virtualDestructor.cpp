//Program to study : 
//virtual destructor
//refer : inheritance.txt
//see : virtualDestructor.png

#include <iostream>
using namespace std;

class A
{
protected :
    int x;
public:
    A();
    virtual void display();
    virtual ~A();
};

A :: A()
{
    cout<<"\n A()";
    x = 10;
}

void A :: display()
{
    cout<<"\n x : "<<x;
}

A :: ~A()
{
    cout<<"\n ~A()";
}

class B : public A
{
protected :
    int y;
public:
    B();
    void display();
    ~B();
};

B :: B()
{
    cout<<"\n B()";
    y = x*x;
}

void B :: display()
{
    cout<<"\n Square of "<<x<<" is "<<y;
}

B :: ~B()
{
    cout<<"\n ~B()";
}

void test()
{
    A * ptrA = new B(); //object is created using new then it must explicitly dropped using delete
    ptrA->display();
    delete ptrA;//destroy the object
}

int main()
{
    cout<<"\n ---- Testing Destructor Execution -----";
    test();
    cout<<"\n ----------------------------------";
    cout<<"\n When object of derived class is destructed ";
    cout<<"\n Then destructors of the derived and the ";
    cout<<"\n base class, both get executed.";
    
    return 0;
}
