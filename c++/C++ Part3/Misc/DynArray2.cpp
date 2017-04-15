//Program to demonstrate
//Deep Copy
//Copy Constructor

#include<iostream>

using namespace std;

class DynArray
{
    //data members
    int *p;//a pointer
    int s;//a variable
    
public:
    DynArray(int q);//parameterized constructor
    DynArray(DynArray &ref);//copy constructor
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

DynArray :: DynArray(DynArray &ref)
{//this refers to the new object being created
 //ref refers to the existing object that is to be copied    
    
    s = ref.s; //copy s
    //p = ref.p;//shallow copy
    p = new int[s];//do not copy p, instead allocated memory for p
    
    //next copy the data of the external resource
    int i;
    for(i =0 ; i< s; i++)
        p[i] = ref.p[i];
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
 Copy Constructor
 ------------------
 Copy Constructor is a special constructor
 of the class.
 It takes only one parameter and that must
 be an object of the same class received by 
 reference.
 
 It is designed for a purpose of
 cloning an object.
 i.e. forming a new object as a 
 duplicate (copy) of an existing object.
 
 It may be called as per choice.
 But it is also auto invoked by the
 system when copy of object is to
 be created (as in pass by value).
 
 Deep Copy
 ----------- 
 Consider an object that uses a pointer,
 as a member variable, to refer to some
 external resource (file, dynamic array, ...).
 
 When an object is passed as a parameter
 to a function then by default it is passed 
 by value.
 i.e. the formal parameter object is a copy
 of the actual parameter object.
 
 The copy is made by the copy constructor 
 of the class that implements deep copy
 method.
 
 Deep Copy method involves duplicating the
 external resources referred by the object.
 */
