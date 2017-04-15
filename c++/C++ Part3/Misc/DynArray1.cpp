//Program to demonstrate
//Shallow Copy

#include<iostream>

using namespace std;

class DynArray
{
    //data members
    int *p;//a pointer
    int s;//a variable
    
public:
    DynArray(int q);
    void set();
    void display();
    void increment();
    ~DynArray();
};

DynArray :: DynArray(int q = 5)
{
    s = q;
    p = new int[s];
    
    set();
}

void DynArray :: set()
{
    int i;
    cout<<"\n Enter "<<s<<" values ";
    
    for(i =0; i< s; i++)
        cin>>p[i];
}

void DynArray :: display()
{
    cout<<"\n p : "<<p;
    cout<<"\n";
    
    int i;
    for(i =0; i< s; i++)
        cout<<" "<<p[i];
}

void DynArray :: increment()
{
    int i;
    for(i =0 ; i< s; i++)
        p[i]++;
}

DynArray :: ~DynArray()
{
    cout<<"\n ~DynArray() ";
    delete p;
}

void test(DynArray d2)
{
    d2.display();
    d2.increment();
    d2.display();
}

int main()
{
    DynArray d1;
    d1.display();
    cout<<"\n---------------";
    test(d1);
    cout<<"\n---------------";
    d1.display();
    return 0;
}
/*
 Consider an object that uses a pointer,
 as a member variable, to refer to some
 external resource (file, dynamic array, ...).
 
 When an object is passed as a parameter
 to a function then by default it is passed 
 by value.
 i.e. the formal parameter object is a copy
 of the actual parameter object.
 
 The copy is made by the systems memory 
 copy method (also known as bit by bit copy
 method). It is a shallow copy method, by
 which only the object is duplicated but its
 external resources are not copied.
 
 Due to this the external resource gets
 shared between the original object and
 its copy. Ahead the use spoil the resource.
 Worst is the case when the destructor 
 called for the copy, deallocates the 
 external resource.
 
 On return the original object's pointer
 becomes a dangling pointer that refers 
 to a deallocated resource.
 Its use may cause segmentation faults
 or unexpected behaviors.
 
 Solution to shallow copy problem is
 to define a copy constructor for the
 class that would implement deep copy
 method.
 */
