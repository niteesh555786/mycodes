#include<iostream>
#include<fstream>
using namespace std;

//Exception Handling

/*
Create a class named Television 
that has data members 
   model number 
   screen size 
   price.
	
Member functions
   overloaded insertion operator
   overloaded extraction operator.
	
If more than four digits are entered for the model number
If the screen size is smaller than 12 or greater than 70 
If the price is negative or over $5000 

Then throw an integer.

Write a main() function that 
1) instantiates a television object
2) allows user to enter data 
3) displays the data members.

If an exception is caught ,
replace all the data member 
values with zero values.

*/

class Television 
{
private:
    int model_number;
    int screen_size; 
    int price;
public:
    friend istream& operator >>(istream &in, Television &r);
    friend ostream& operator << (ostream &o, Television &r);
    void clearALL();
};
void Television :: clearALL()
{
    model_number = 0;
    screen_size = 0;
    price = 0;
}

istream& operator >>(istream &in, Television &r)
{
    cout<<"\n Enter Model Number ";
    in>>r.model_number;
    if(r.model_number > 9999)
    {//logical issue
        throw 1;//raise an exception
    }

    cout<<"\n Enter Screen Size ";
    in>>r.screen_size;
    if(r.screen_size < 12 || r.screen_size > 70)
    {//logical issue
        throw 2;//raise an exception
    }
    
    cout<<"\n Enter Price ";
    in>>r.price;
    if(r.price <0 || r.price > 5000)
    {//logical issue
        throw 3; //raise an exception
    }
    return in;
}

ostream& operator << (ostream &o, Television &r)
{
    o<<"\n Model Number : "<<r.model_number;
    o<<"\n Screen Size : "<<r.screen_size;
    o<<"\n Price : "<<r.price;
    return o;
}

int main()
{
    Television tv;
    try
    {
        cin>>tv;
    }
    catch(int errCode)
    {
        switch(errCode)
        {
            case 1:
                cerr<<"\n Invalid Model Number ";
                break;
            case 2:
                cerr<<"\n Invalid Screen Size ";
                break;
            case 3:
                cerr<<"\n Invalid Price ";
                break;
        }//switch
        tv.clearALL();
    }//catch
    
    cout<<tv;
    return 0;
}