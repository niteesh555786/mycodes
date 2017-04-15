//Program to demonstrate :
//static and non static members of a class
//see : staticNonStatic.png
//read the note below

#include<iostream>
using namespace std;

class StatDemo
{
    int x; //non static 
    static int y;//static
public:
    StatDemo();
    StatDemo(int);
    void display(); //non static
    static void displayObjectCount();
    ~StatDemo();
};

//memory allocation for static member variable
int StatDemo :: y;

StatDemo:: StatDemo()
{
    cout<<"\n StatDemo()";
    x = 10; //this->x = 10;
    y++; //StatDemo::y++;
}

StatDemo:: StatDemo(int q)
{
    cout<<"\n StatDemo(int)";
    x = q; //this->x = q;
    y++; //StatDemo::y++;
}

void StatDemo :: display()
{
    cout<<"\n x : "<<x <<" "<< &x;
    cout<<"\n y : "<<y<<"  "<<&y;
}

void StatDemo :: displayObjectCount()
{
    cout<<"\n StatDemo :: displayObjectCount()";
    cout<<"\n Number of active objects : "<<y;
}
StatDemo :: ~StatDemo()
{
    cout<<"\n ~StatDemo()";
    y--;//StatDemo::y--;
}

void test()
{
    StatDemo o2(20);
    o2.display();
}

int main()
{
    StatDemo o1;
    o1.display();
    cout<<"\n----------";
    test();
    cout<<"\n----------";
    o1.display();
    //function called without any caller object
    StatDemo :: displayObjectCount();
            
    return 0;
}

/*
 Members (functions and variables) of 
 a class can be classified as :
 1) non static (default)
 2) static 
 
 non static member variables
-------------------------- 
 Member variables of a class are by default
 non static.
 A non static member variable is allocated as
 a member inside every object of the class.
 Its life is equal to the life of the object. 
 It is usable through the object.
 
 static member variables
------------------------- 
 Member variables of a class can be declared
 as static.
 A static member variable is allocated once for
 a class. It is not found as a member inside 
 any object of the class.
 Its life is equal to the life of the class. 
 It is usable through class reference.

 non static member functions
------------------------ 
 Member functions of the class are by default
 non static.
 A non static member function requires  
 an object for invocation.
 It can access all other members of the
 class.
 
 static member functions
---------------------- 
 Member functions of the class can be declared
 as static.
 A static member function doesn't require  
 any object for invocation.
 It can access only static members of the
 class.
 
 */