//Program to demonstrate : 
//Object Creation
//See : Object Creation.txt
//Read : Object Creation.txt

#include <iostream>

using namespace std;

class Myclass
{
private:
    int x, y;
public:
    Myclass(int , int );
    void display();
    ~Myclass();
};

Myclass :: Myclass(int q = 10, int w = 20)//parameterized constructor with default values
{
    cout<<"\n Myclass(parameters)";
    x = q;//parameterized value
    y = w;//parameterized value
}

void Myclass :: display()
{
    cout<<"\n"<<x<<" "<<y<<" "<<this;
}

Myclass :: ~Myclass()
{
    cout<<"\n ~Myclass()";
}

int main()
{
    //Object creation
    Myclass m;//declaration
    Myclass *p;
    p = new Myclass(1,2);//allocation
    
    //usage
    m.display();
    p->display();
    
    //destruction
    //m : auto destroy as this function gets over
    delete p;//to deallocate the object
    
    return 0;
}