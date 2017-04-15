//Program to implement : 
//Overloading operators : new and delete
//see : life of an object.png
//see : Object Creation.png
//Read the note below

#include <iostream>
#include <stdlib.h>

using namespace std;

class Myclass
{
private :
    int x, y;
public:
    Myclass();
    Myclass(int,int);
    void display();
    void increment();
    ~Myclass();

    //operators
    void operator delete(void *p);
    void * operator new(size_t s);

};

Myclass :: Myclass()
{
    cout<<"\n Myclass()";
    x = 10;
    y = 20;
}

Myclass :: Myclass(int q, int w)
{
    cout<<"\n Myclass(int,int)";
    x = q;
    y = w;
}

void Myclass :: display()
{
    cout<<"\n"<<x<<" "<<y;
}

void Myclass :: increment()
{
    x++;
    y++;
}

Myclass :: ~Myclass()
{
    cout<<"\n ~Myclass()";
}

void * Myclass :: operator new(size_t s)
{
    cout<<"\n in new of Myclass";
    void *p = malloc(s);
    //do something extra here
    return p;
}

void Myclass :: operator delete(void *p)
{
    cout<<"\n in delete of Myclass";
    //do something extra here
    free(p);
}

int main()
{
    Myclass *p;
    p = new Myclass();
    
    p->display();
    p->increment();
    p->display();
    
    delete p;
        

}

/*
 C++ system supports usage of 
 operators new and delete on primary
 and secondary types.
 
 Still there is a support for overloading
 the operators new and delete.
 
 If to be overloaded then the operators
 would take following signatures.
 
 void * operator new(size_t s);
 void operator delete(void *p);
 
 
 */