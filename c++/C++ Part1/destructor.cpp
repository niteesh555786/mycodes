//Program to demonstrate : Destructor
//Read the note below
//See : life of an object.png

#include <iostream>

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
    
    void increment()
    {
        x++;
        y++;
    }
    
    ~Myclass()
    {
        cout<<"\n ~Myclass()";
    }
};

void fx()
{
    Myclass m2; //here object is declared as a local member of the function, so its life would be the scope of the function.
    m2.display();
    m2.increment();
    m2.display();
}

int main()
{
    Myclass m1(1,2); //life of this object would be the scope of main function
    cout<<"\n-----------";
    fx();
    cout<<"\n-----------";
    m1.increment();
    m1.display();
    return 0;
}
/*
 A destructor is a special member
 function of the class.
 It takes the same name as of class and is preceeded by a ~
 It has no return type specification.
 It is always parameterless. Hence it cannot be overloaded.
 
 It is auto invoked by the system as 
 life of the object gets over.
 
 It frees up (deallocates) the object level resources.
 */