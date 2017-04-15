//Program to study : 
//multiple inheritance
//refer : inheritance.txt
//see : multipleInheritance1.png
//see : multipleInheritance2.png

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

class B
{
protected :
    int y;
public:
    B();
    virtual void display();//to enable run time binding
    virtual void fx();//to enable run time binding
    virtual ~B();
};

B :: B()
{
    cout<<"\n B()";
    y = 20;
}

void B :: display()
{
    cout<<"\n y : " << y;
}

void B :: fx()
{
    cout<<"\n B fx()";
}

B :: ~B()
{
    cout<<"\n ~B()";
}

//multiple inheritance
//class C : public A, public B
class C : public B, public A
{
protected :
    int z;
public:
    C();
    void display(); //override to A::display() as well as to B::display()
    void fx();//override to B::fx()
    ~C();
};

C :: C()
{
    cout<<"\n C()";
    z = x + y;
}

void C:: display()
{
    cout<<"\n "<<x<<" + "<<y<<" = "<<z;
}

void C :: fx()
{
    cout<<"\n C fx()";
}

C :: ~C()
{
    cout<<"\n ~C()";
}

void test1(A *ptrA)
{//type compatibility proved
    ptrA->display();//run time bound
}

void test2(B *ptrB)
{//type compatibility proved
    ptrB->display();//run time bound
    ptrB->fx();//run time bound
}

int main()
{
    C objC;
    cout<<"\n ---------";
    test1(&objC);
    cout<<"\n ---------";
    test2(&objC);
    cout<<"\n ---------";
    return 0;
}
