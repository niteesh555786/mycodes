//Program to demonstrate : Constructor, Constructor Overloading
//Read the note below
//See : Person.png

#include <iostream>
#include<string.h>

using namespace std;

class Person
{
public://will discuss later
    char name[20];
    char gender;
    int age;

    Person() //default constructor
    {
        cout<<"\n Person()";
        strcpy(name, "baby");//default value
        age = 0;//default value
        gender = 'f';//default value
    }
    
    Person(char nm[], int a, char g) //parameterized constructor
    {
        cout<<"\n Person(parameters)";
        strcpy(name, nm);//parameterized value
        age = a;//parameterized value
        gender = g;//parameterized value
    }
    
    void display()
    {
        cout<<"\n name : "<<name;
        cout<<"\n gender : "<<gender;
        cout<<"\n age : "<<age;
    }
};

int main()
{
    cout<<"\n ==============";
    Person p; //object of the class
    cout<<"\n ==============";
    Person p1("vikas", 5 , 'm');
    cout<<"\n ==============";
    p.display();
    p1.display();
    return 0;
}


/*
Object of a class, by default contains 
garbage values in its member variables.

It is desired to initialze the member 
variables of the object to some default
or specific values, on creation.

For this purpose C++ supports definition
of a special member function called as 
"Constructor".

A constructor is a special member 
function of the class.
It has the same name as of the class.
It has no return type specification.
It is auto invoked by the system as
object of the class is created.
Its purpose is to initialize the object.


C++ supports definition of multiple
constructors for a class with different 
set of parameters.
Doing so is termed as "Constructor Overloading" 
 
Constructor Overloading is implementation 
of OOP concept polymorphism, as it allows 
object initialization in multiple ways. 
One way : without data 
Another way : with data 
 
*/