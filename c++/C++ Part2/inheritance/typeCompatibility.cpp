//Program to demonstrate : 
//Type Compatibility by Inheritance
//Runtime Binding
//refer : inheritance.txt
//see : typeCompatibility.png

#include <iostream>
using namespace std;

class A
{
public:
    void f1();
    virtual void f2();
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
    cout<<"\n B f2() starts";
    f3();
    cout<<"\n B f2() ends";
}
void B :: f3()
{
    cout<<"\n B f3()";
}


void test(A * ptrA)
{
    cout<<"\n ----------";
    ptrA->f1();//inherited code
    ptrA->f2();//overridden code (runtime bound)
    //ptrA->f3();//extended code cannot be accessed
    cout<<"\n ----------";
}

int main()
{
    A objA;
    B objB;
    
    test(&objA);
    test(&objB);
    
   return 0;
}

