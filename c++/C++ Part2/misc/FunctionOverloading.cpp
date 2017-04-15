/*
Function Overloading
-----------------------
Function overloading is defining multiple
functions with the same name and different 
set of parameters.

Functions take the same name because they
perform the same task.
Multiple functions are defined because the
task is performed in multiple ways (methods).
Parameter to the functions are different
is an indicator of different inputs.

Example :
  pay(cash) {....}
  pay(cheque) { ... }
  pay(card) { ...... }

Function overloading is implementing OOP
concept POLYMORPHISM.
POLYMORPHISM suggests defintion of 
muliple methods to perform a task, whenever
possible.

*/

//Program to demonstrate : 
//Function Overloading

#include <iostream>
using namespace std;

class Complex
{
    int r, i;
public:
    Complex();
    Complex(int a, int b);
    void display();
    friend void addition(Complex c1, Complex c2);
};

Complex :: Complex()
{
    r = i= 0;
}
Complex :: Complex(int a, int b)
{
    r = a;
    i = b;
}

void Complex :: display()
{
    cout<<r<<"+i"<<i<<"\n";
}

//here operation addition is overloaded to
//act of numbers and complex numbers.

void addition(int q, int w)
{
    int result;
    result = q +w;
    cout<<"\n Addition : "<<result;
}

void addition(Complex c1, Complex c2)
{
    Complex result;
    result.r = c1.r  + c2.r;
    result.i = c1.i  + c2.i;
    cout<<"\n Addition : ";
    result.display();
}

int main()
{
    Complex a(10, 4);
    Complex b(7, 2);
    addition(10, 3);
    addition(a, b);
    return 0;
}