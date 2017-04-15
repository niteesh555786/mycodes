//Program to implement : 
//Pure Virtual Functions
//Abstract Class
//refer : inheritance.txt , pureVirtualFn.txt
//see : PaintShape.png

#include <iostream>
using namespace std;

class Shape
{//abstract
protected :
    float d1;
public:
    Shape();
    Shape(float);
    virtual void display();
    virtual float area() = 0;
};

Shape :: Shape()
{
    d1 = 10;
}

Shape :: Shape(float q)
{
    d1 = q;
}

void Shape :: display()
{
    cout<<"\n Dim : "<<d1;
}

class Rect : public Shape
{
    float d2;
public:
    Rect();
    Rect(float, float);
    void display();
    float area();
};

Rect :: Rect()
{
    d2 = 20;
}

Rect :: Rect(float a, float b) : Shape(a)
{
    d2 = b;
}

void Rect :: display()
{
    cout<<"\n Dim1 : "<<d1;
    cout<<"\n Dim2 : "<<d2;            
}

float Rect :: area()
{
    return d1 * d2;
}


class Circle : public Shape
{
public:
    Circle();
    Circle(float);
    float area();
};

Circle :: Circle()
{//Shape() would do the init.
}
Circle :: Circle(float a) : Shape(a)
{//Shape() would do the init.
}

float Circle :: area()
{
    return 3.14 * d1 * d1;
}

class Painter
{
public:
    void quote(Shape * p);
};

void Painter :: quote(Shape  * p)
{
    float baseRate = 10;
    float taxes = 4; //percent
    float a  = p->area();
    float total = baseRate * a;
    total = total + (total * taxes /100);
    
    cout<<"\n----Quote----";
    cout<<"\n Dimensions : " ;
    p->display();
    cout<<"\n Area : "<<a;
    cout<<"\n Quote Amount : "<<total;
    cout<<"\n------------";
}

int main()
{
    Rect r(20, 15);
    Circle c(10);
    
    Painter p;
    p.quote(&r);
    p.quote(&c);
    return 0;
}

