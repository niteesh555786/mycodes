//Program to demonstrate: 
//hybrid inheritance
//Ambiguity due to the design (rhombus, diamond)
//2 Resolutions

//refer : inheritance.txt
//see : hybrid.png

#include <iostream>
using namespace std;

class A
{
protected :
    int i;
public:
    A();
    A(int);
    void display();
    ~A();
};

A:: A()
{
    cout<<"\n A()";
    i  = 10;
}

A:: A(int q)
{
    cout<<"\n A(int)";
    i  = q;
}

void A :: display()
{
    cout<<"\n i : "<<i;
}

A :: ~A()
{
    cout<<"\n ~A()";
}

//inheritance
class B : public A
{
protected:
    int j;
public:
    B();
    B(int,int);
    void display();
    ~B();
};

B :: B()
{
    cout<<"\n B()";
    j = 20;
}

B :: B(int q, int w) : A(q)
{
    cout<<"\n B(int,int)";
    j = w;
}

void B :: display()
{
    cout<<"\n"<<i<<" "<<j;
}

B :: ~B()
{
    cout<<"\n ~B()";
}

//inheritance
class C : public A
{
protected:
    int k;
public:
    C();
    C(int,int);
    void display();
    ~C();
};

C :: C()
{
    cout<<"\n C()";
    k = 30;
}

C :: C(int q, int w) : A(q)
{
    cout<<"\n C(int,int)";
    k = w;
}

void C :: display()
{
    cout<<"\n"<<i<<" "<<k;
}

C :: ~C()
{
    cout<<"\n ~C()";
}

//hybrid inheritance
class D : public B , public C
{
protected:
    int l;
public:
    D();
    D(int,int,int,int);
    void display();
    ~D();
};

D :: D()
{
    cout<<"\n D()";
    l = B::i+j + C::i+k;
}

D:: D(int q, int w, int e ,int r) : B(q,w), C(e,r)
{
    cout<<"\n D(int,int,int,int)";
    l = B::i+j + C::i+k;
}

//override to remove the ambiguity in calls to display
//note that there are two definitions of display inherited
//from two different parents.

void D :: display()
{
    cout<<"\n "<<B::i<<" + "<<j<<" + "<<C::i<<" + "<<k<<" = "<<l;
}

D :: ~D()
{
    cout<<"\n ~D()";
}

int main()
{
    D objD(1,2,3,4);
    objD.display();
    return 0;
}

