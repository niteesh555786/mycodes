//Program to demonstrate : 
//Inheritance of Data
//refer : inheritance.txt
//see : inheritData.png

#include <iostream>
using namespace std;

class A
{
protected :
    int x, y;
public:
    A();
    A(int,int);
    void display();
    ~A();
};

A::A()
{
    cout<<"\n A()";
    x = 10;
    y = 20;
}

A :: A(int q, int w)
{
    cout<<"\n A(int,int)";
    x = q;
    y = w;
}

void A :: display()
{
    cout<<"\n"<<x<<" "<<y;
}

A :: ~A()
{
    cout<<"\n ~A()";
}

class B : public A
{
    int z;
public:
    B();
    B(int,int);
    void display();
    ~B();
};

B :: B()  //:A()
{
    cout<<"\n B()";
    z = x + y;
}

B :: B(int q, int w) : A(q,w)
{
    cout<<"\n B(int,int)";
    z = x +y;
}

void B :: display()
{
    cout<<"\n"<<x<<" + "<<y<<" = "<<z; 
}

B :: ~B()
{
    cout<<"\n ~B()";
}

int main()
{
    B objB(7,8);
    objB.display();
   return 0;
}
