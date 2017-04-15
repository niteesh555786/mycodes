//Program to implement :
//Stack Using Array

#include <iostream>
#define SIZE 5
using namespace std;

class Stack
{
    int data[SIZE];
    int top;
    
public:
    Stack();
    int isFull();
    int isEmpty();
    void push(int);
    int pop();
    void display();
};

Stack :: Stack()
{
    top = -1;
}

int Stack :: isFull()
{
    if(top == SIZE -1)
        return 1; //true
    else
        return 0;//false
}

int Stack :: isEmpty()
{
    if(top == -1)
        return 1; //true
    else
        return 0;//false
}

void Stack :: push(int val)
{
    if(! isFull())
    {
        top++;
        data[top ] = val;
    }
    else
        cout<<"\n Stack Overflow";
}

int Stack :: pop()
{
    int val = 0;
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

void Stack :: display()
{
    int i;
    for(i = top ; i>=0; i--)
        cout<<"\n"<<data[i];
}

void menu()
{
    Stack s;
    int val;
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
    menu();
    return 0;
}

