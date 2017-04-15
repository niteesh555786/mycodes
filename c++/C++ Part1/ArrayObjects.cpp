//Program to demonstrate : Arrays Of class type
//Read the note below
//See : ArrayObjects.png

#include <iostream>
#include<string.h>

using namespace std;

class Myclass
{
public:
    int x, y; //member variables

    Myclass() //default constructor
    {
        cout<<"\n Myclass()";
        x = 10;//default values
        y = 20;//default values
    }
    
    Myclass(int q, int w)//parameterized constructor
    {
        cout<<"\n Myclass(parameterized)";
        x = q; //parameter value
        y = w; //parameter value
    }
    
    void display()
    {
        cout<<"\n"<<x<<" "<<y;
    }
    
};


int main()
{
    //array of class type
    //Myclass arr[3];
    Myclass arr[3] = {Myclass(), Myclass(11,22)}; //for the missing initializer calls, default initializer would be used
    
    
    int i;
    for(i =0; i< 3; i++)
        arr[i].display();
}

/*
 C++ allows declaration of an
 array of class type.
 Declaration syntax, memory allocation, 
 usage, ... for an array of class type
 is similar to an array of primary type.
 
 Elements of the array would be objects
 of the class.
 
 Known that as object is created, constructor 
 gets executed, so for an array of class type
 system invokes the default constructor per
 element (object).
 
 Inorder to get a parameterized 
 constructor executed for the elements
 (objects) of the array, an array 
 initializer may be provided. 
 (See the code).
 
 FYI
 Prefer arrays of class type 
 over individual objects because
 array would support application
 of many algorithms (search, sort, ...).
 */