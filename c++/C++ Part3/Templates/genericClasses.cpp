//Program to implement :
//Template Stack Using Array

#include <iostream>
#define SIZE 5
using namespace std;

template <class X> class Stack
{
//member variables of a template class 
//may be generic or non generic in type
    
    X data[SIZE];//generic data member
    int top;//non generic data member
    
public:
//every function of template class 
//must be a template function    
    Stack();
    int isFull();
    int isEmpty();
    void push(X);
    X pop();
    void display();
};

template <class X>  Stack<X> :: Stack()
{
    top = -1;
}

template<class X> int Stack<X> :: isFull()
{
    if(top == SIZE -1)
        return 1; //true
    else
        return 0;//false
}

template <class X> int Stack<X> :: isEmpty()
{
    if(top == -1)
        return 1; //true
    else
        return 0;//false
}

template <class X> void Stack<X> :: push(X val)
{
    if(! isFull())
    {
        top++;
        data[top ] = val;
    }
    else
        cout<<"\n Stack Overflow";
}

template <class X> X Stack<X> :: pop()
{
    X val = 0;
    if(! isEmpty())
    {
        val = data[top];
        data[top] = 0; //optional
        top--;
    }
    else
        cout<<"\n Stack Underflow";
    
    return val;
}

template <class X >void Stack<X> :: display()
{
    int i;
    for(i = top ; i>=0; i--)
        cout<<"\n"<<data[i];
}

template <class X> void menu(X dummy)
{
    dummy = dummy;
    //Stack <int>s1;
    //Stack <double> s2;
    //Stack <Student> s3;
    
    Stack <X> s; //object of generic class
    X val;
    int ch;
    
    do
    {
        cout<<"\n 1. push";
        cout<<"\n 2. pop";
        cout<<"\n 3. display";
        cout<<"\n 4. exit";
        cout<<"\n enter choice ";
        cin>>ch;
        
        switch(ch)
        {
            case 1:
                cout<<"\n enter val to push ";
                cin>>val;
                s.push(val);
                break;
            case 2:
                val = s.pop();
                cout<<"\n"<<val<<" removed ";
                break;
            case 3:
                s.display();
                break;
            case 4:
                break;
            default:
                cout<<"\n wrong choice ";
                break;                
        }
        
    }while(ch != 4);
}

int main()
{
    int a;
    char b;
    double c;
    int ch;
    
    cout<<"\n 1. int stack ";
    cout<<"\n 2. char stack ";
    cout<<"\n 3. double stack ";
    cout<<"\n enter choice ";
    cin>> ch;
    
    if(ch == 1)
        menu(a);
    else if(ch == 2)
        menu(b);
    else if(ch == 3)
        menu(c);
    else
        cout<<"\n Wrong choice ";
    
    return 0;
}

