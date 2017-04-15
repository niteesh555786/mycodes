#include <iostream>

using namespace std;
//Program to demonstrate :
//Pointers of Secondary Types (class)

//refer : pointerToObject.txt
//see : pointerToObject.png

class Myclass
{
private:
    int x, y;
public:
    Myclass(int , int );
    void display();
    void increment();
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

void Myclass :: increment()
{
    x++;
    y++;
}

int main()
{
    Myclass m(1,2);//object of class type
    Myclass *p;//pointer of class type

    //referencing
    p = &m;

    //dereferencing
    p->display(); //caller object of display is the one address of which is stored in p
    p->increment();//caller object of increment is the one address of which is stored in p

    m.display();
    return 0;
}

