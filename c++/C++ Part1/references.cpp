//demonstrating : references

#include <iostream>
using namespace std;

void fn1(int q)
{
 cout<<"\n in fn1, q : "<<q<<"  "<<&q; 
 q++;
 cout<<"\n in fn1, q : "<<q<<"  "<<&q; 
}

void fn2(int &r)
{
 cout<<"\n in fn2, r : "<<r<<"  "<<&r; 
 r++;
 cout<<"\n in fn2, r : "<<r<<"  "<<&r;
}

int main()
{
 int x;
 x = 10;
 cout<<"\n in main, x : "<<x <<"  "<<&x; 
 fn1(x);//pass by value
 cout<<"\n in main, x : "<<x <<"  "<<&x;
 
 //parameter reference
 fn2(x);//pass by reference
 cout<<"\n in main, x : "<<x <<"  "<<&x;
 
 //stand alone references
 int &sar= x; //must be initialized while declaration
 cout<<"\n in main, sar : "<<sar <<"  "<<&sar; 
 sar = 100;
 cout<<"\n in main, x : "<<x <<"  "<<&x;
 
 ostream &vout = cout;
 vout<<"\n Hello References";
 
 return 0;
}