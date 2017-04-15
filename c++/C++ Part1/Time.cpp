//Program to demonstrate :
//classes and objects
//member variables and functions
//this pointer

#include <iostream>
using namespace std;

class Time //entity
{
public: //will discuss later
    
    //attributes of the entity 
    //member variables
    int h, m, s;
    
    //operations of the entity
    void setTime(/* const Time *this, */int a, int b, int c)
    {
        cout<<"\n in setTime this : "<<this;
        
        int h; //local variable that uses the same name as of the member variable, cause SHADOWING
        h = a;//shadowing
        this->h = a;//overcome
        m = b;//this->m = b;
        s = c;//this->s = c;
    }
    
    void displayTime()
    {
        cout<<"\n"<<h<<":"<<m<<":"<<s;
    }
};


int main()
{
    Time t; //object of class Time
    cout<<"\n in main &t : "<<&t;
    //Using the object
    t.setTime(1,2,3);//setTime(&t, 1, 2, 3);
    t.displayTime();//displayTime(&t);
    
    return 0;
}