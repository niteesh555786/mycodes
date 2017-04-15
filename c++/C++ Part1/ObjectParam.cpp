//Program to demonstrate : 
//Object as parameter to function
//read : ObjectParam.txt

#include <iostream>

using namespace std;

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

void test1(Myclass obj) // test1 receives object of Myclass as a formal parameter
{
    obj.display();
    
    obj.increment();
    obj.display();
}

void test2(Myclass *p) // test2 receives address object of Myclass as a formal parameter
{
    //for these calls caller object is the one address of which is stored in p
    p->display();
    p->increment();
    p->display();
}

int main()
{
    Myclass m(1,2);
    m.display();
    cout<<"\n-------";
    test1(m);//call to test1 with object 'm' as actual parameter
    cout<<"\n-------";
    m.display();
    cout<<"\n=======";
    test2(&m);//call to test2 with address of object 'm' as actual parameter
    cout<<"\n=======";
    m.display();
    return 0;
}