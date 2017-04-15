#include<iostream>
using namespace std;

/*
 IO Manipulators
----------------- 
 IO Manipulators are special functions
 that group various data fetching and 
 rendering methods, flags, etc provided
 by C++.
 IO Manipulators are used so that 
 the developer can :
 1) define a standard data fetching and rendering code across the application.
 2) keep input, logic and rendering code separate.
 
 IO Manipulators are special functions
 because :
 * Their return type and parameters are preset. 
 * They can be used along with IO operations.
 
 Output Manipulator 
 ------------------ 
 ostream& <anyName>(ostream & r)
 {
   output formatting
   return r;   
 }
 
 Input Manipulator 
 ----------------- 
 istream& <anyName>( istream & r)
 {
   input handling
   return r;   
 }
 
 */

//Output Manipulator
ostream & style1 (ostream &o)
{
    o<<"\n";
    //o.fill('.');
    o.width(20);
    o.unsetf(ios::right);
    o.setf(ios::left);
    return o;
}

ostream & style2(ostream & o)
{
    //o.fill('-');
    o.width(15);
    o.unsetf(ios::left);
    o.setf(ios::right);
    return o;
}

istream& cleanStream(istream &i)
{
    if(i.fail())
        i.clear();
    i.ignore(1000, '\n');
    return i;
}

ostream& style3 (ostream & o)
{
    o.unsetf(ios::dec);//unset the decimal form of outputting numbers
    o.setf(ios::hex | ios::uppercase);//output numbers in uppercase hex form
    //o.setf(ios::oct);//output numbers in octal form
    return o;
}

ostream& style4 (ostream & o)
{
    o.setf(ios::showpos);//prefix a + sign to positive numbers
    o.setf(ios::scientific);//output number as 1.05 e+03
    return o;
}

int main()
{
    int age= 0;
    char name[20];
    float percentage= 0;
    
    do
    {
        cout<<style1<<"Enter Age ";
        cin>>age>>cleanStream;
    }while(age == 0);

    cout<<style1<<"Enter Name ";
    //cin.ignore(100, '\n');
    cin.get(name, 19, '\n');//fetch max 19 characters or until '\n' whichever encountered first
    
    do
    {
        cout<<style1<<"Enter Percentage";
        cin>>percentage>>cleanStream;
    }while(percentage == 0);
    
    
    cout<<style1<<"Name "<<style2<<name;
    cout<<style1<<"Age "<<style2<<style3<<age;
    cout<<style1<<"Percentage "<<style2<<style4<<percentage;
    return 0;
}

/*
    int ch;
    do
    {
        cout<<"\n Enter value : ";
        cin>>ch;
        if(cin.fail())
        {//true, if data fetch failed
            cin.clear();//reset all the error bits
            cin.ignore(1000, '\n');//skip 1000 bytes or until '\n' is found 
        }
        
        
        //some code possible here
    }while(ch != 4);

 */
