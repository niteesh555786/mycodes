//RTTI

#include <iostream>
#include <typeinfo>
using namespace std;

//refer About RTTI.txt
class A
{
public :
    virtual void fn();
};

void A :: fn()
{
    cout<<"\n A fn()";
}

class BBBB : public A
{
public:
    void fn();
};

void BBBB :: fn()
{
    cout<<"\n BBBB fn()";
}

class C : public A
{
public:
    void fn();
};

void C :: fn()
{
    cout<<"\n C fn()";
}

void determineType(A *ptrA)
{
    if( typeid(*ptrA) == typeid(A))
        cout<<"\n ptr refers to object of class A";
    else if(typeid(*ptrA) == typeid(BBBB))
        cout<<"\n ptr refers to object of class BBBB";
    else if(typeid(*ptrA) == typeid(C))
        cout<<"\n ptr refers to object of class C";
        
    
    //ptrA->fn();
}

void determineClassName(A *ptrA)
{
    cout<<"\n class name : "<<typeid(*ptrA).name();
}

void determineBuiltInTypes()
{
    int x = 10;
    char y = 'q';
    float z = 1.23F;
    
    cout<<"\n x is : "<< typeid(x).name();
    cout<<"\n y is : "<< typeid(y).name();
    cout<<"\n z is : "<< typeid(z).name();
}

int main()
{
    A objA;
    BBBB objB;
    C objC;
    
    determineType(&objA);
    determineType(&objB);
    determineType(&objC);
    
    determineClassName(&objA);
    determineClassName(&objB);
    determineClassName(&objC);
    
    determineBuiltInTypes();
    return 0;
}