//Program to demonstrate : 
//namespaces
//refer : about namespaces.txt
//see : namespaces.png

#include<iostream>
using namespace std;

int x = 100;

namespace My
{
    int x = 1000;
    
    void fx()
    {
        cout<<"\n My fx()";
    }
    
    namespace NestedMy
    {
        int x = 10000;
    }
}

void fx()
{
    cout<<"\n global fx()";
}

int main()
{
    int x = 100000;
    cout<<"\n local x : "<<x;
    cout<<"\n Global x : "<<::x;
    cout<<"\n My x : "<<My::x;
    cout<<"\n My NestedMy x : "<<My::NestedMy::x;
    
    fx();// ::fx();//global fx()
    My::fx();//My fx();
    return 0;
}