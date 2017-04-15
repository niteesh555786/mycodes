//Program to study : 
//multi level inheritance
//refer : inheritance.txt
//see : multilevelInheritance1.png
//see : multilevelInheritance2.png

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

//inheritance
class B : public A
{
protected :
    int y;
public:
    B();
    void display();//virtual by inheritance
    virtual void fx();//to enable run time binding
    ~B();
};

B :: B()
{
    cout<<"\n B()";
    y = x + x;
}

void B :: display()
{
    cout<<"\n x : " << x;
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

//multi level inheritance
class C : public B
{
protected :
    int z;
public:
    C();
    void display();
    void fx();
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
