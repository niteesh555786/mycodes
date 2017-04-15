//Program to implement : 
//Operator Overloading

#include <iostream>
using namespace std;

class Time
{
private :
    int h,m,s;
public:
    Time();
    Time(int,int,int);
    void display();
    
    //operator functions
    Time operator +(Time &r);
    Time operator -(Time &r);
    Time operator +(int q);
    int operator ==(Time &r);
    int operator [](int q);
    Time operator ++(int q);//postfix
    Time operator ++();//prefix
    Time& operator =(int q);
    Time * operator ->();
    int operator()(Time &r);
    void operator()(int a, int b , int c);
    
    //friend operator functions
    friend Time  operator +(int q, Time &r);
    friend ostream& operator <<(ostream &o, Time &r);
    friend istream& operator >>(istream &in, Time &r);

    //type conversion 
    operator int();
    operator double();
    
};

Time :: Time()
{
    h = m = s = 0;
}

Time :: Time(int q, int w, int e)
{
    h = q;
    m = w;
    s = e;
}

void Time :: display()
{
    cout<<"\n"<<h<<":"<<m<<":"<<s;
}

Time Time :: operator +(Time &r)
{
    Time temp;
    temp.h = h + r.h;       
    temp.m = m + r.m;
    temp.s = s + r.s;
    
    return temp;//addition
}

Time  Time :: operator -(Time &r)
{
    Time temp;
    temp.h = h - r.h;
    temp.m = m - r.m;
    temp.s = s - r.s;
    
    return temp;//subtraction
}

Time Time :: operator + (int q)
{
    Time temp;
    temp.h = h  + q;
    temp.m = m  + q;
    temp.s = s  + q;
    
    return temp;//addition
}

int Time :: operator ==(Time &r)
{
    if(h == r.h && m == r.m && s == r.s)
        return 1;//true
    else
        return 0;//false
}

Time  operator +(int q, Time &r)
{
    Time temp;
    temp.h = q + r.h;
    temp.m = q + r.m;
    temp.s = q + r.s;
    
    return temp;
}

int Time :: operator [](int q)
{
    if(q == 0)
        return h;
    else if(q == 1)
        return m;
    else if(q == 2)
        return s;
    else
    {
        cout<<"\n Index Out Of Range (0-2) ";
        return -1;
    }
}

Time Time :: operator ++(int q)//postfix
{
    q = q; //to avoid warning of no use
    
    //create a copy
    Time temp;
    temp.h = h;
    temp.m = m;
    temp.s = s;
    
    //increment
    h++;
    m++;
    s++;
    
    //return the old values
    return temp;
}

Time Time :: operator ++()//prefix
{
    //increment
    h++;
    m++;
    s++;
    
    //create a copy
    Time temp;
    temp.h = h;
    temp.m = m;
    temp.s = s;
    
    //return the incremented values
    return temp;
}


Time& Time :: operator =(int q)
{
    h = q;
    m = q;
    s = q;
    
    //return the caller object
    return *this;
}

ostream& operator <<(ostream &o, Time &r)
{
    o<<"\n"<<r.h<<":"<<r.m<<":"<<r.s;
    return o; //for cascading support
}

istream& operator >>(istream &in, Time &r)
{
    cout<<"\n Enter Hours ";
    in>>r.h;
    cout<<"\n Enter Minutes ";
    in>>r.m;
    cout<<"\n Enter Seconds ";
    in>>r.s;
    return in;
}

Time * Time :: operator ->()
{
    h++;//some action
    return this;//address of object of current class
}

//t1(1,2,3)
void Time :: operator()(int a, int b , int c)
{
    h = a;
    m = b;
    s = c;
}

//t1(t2)
int Time :: operator()(Time &r)
{
    if(h == r.h && m == r.m && s == r.s)
        return 1;
    else
        return 0;
}

Time :: operator int()
{
    int x;
    x = h * 60 * 60;
    x += m *60;
    x += s;
    return x;
}

Time :: operator double()
{
    double d;
    d = h;
    d += m/60.0;
    d += s/(60.0 * 60.0);
    return d;
}

int main()
{
    Time t1(10,20,30);
    Time t2(1,2,3);
    Time t3;
    
    //t3 = t1 + t2;
    //t3 = t1 - t2;
    //t3 = t1 + 5;
    //t3 = 5+ t1;
    /*
    if(t1 == t2)
        cout<<"\n Objects are equal";
    else
        cout<<"\n Objects are not equal";
    */
    
    //cout<<"\n Hours : "<<t1[0];
    //cout<<"\n Minutes : "<<t1[1];
    //cout<<"\n Seconds : "<<t1[2];
    
    //t3 = t1++;//postfix
    //t1.display();
    //t3.display();
    
    //t3 = ++t2;//prefix
    //t2.display();
    //t3.display();
    
    
    //t3 = t1 = 5;
    
    //t1.display();
    //t2.display();
    //t3.display();
    
    //cin>>t1>>t2;
    //cout<<t1<<t2;
    
    //t1->display();
    /*
    t1(1,2,3);
    if(t1(t2))
        cout<<"\n t1 equals t2";
    else
        cout<<"\n t1 is not equal to t2";
    */ 
    
    int x;
    double y;
    x = t1;
    y = t1;
    
    cout<<t1;
    cout<<"\n seconds equivalent : "<<x;
    cout<<"\n hours equivalent : "<<y;
    
    return 0;
}


/*
C++ supports application of a limited
set of operators on objects of secondary 
datatypes. 
To list :
 1) = (Assignment)
 2) new (Dynamic Memory Allocation)
 3) delete (Dynamic Memory Deallocation)
 4) sizeof (Fetch the size of the object)
 5) & (Referencing)
 6) * or -> (Dereferencing the pointer)
 7) . (Member Access)
 
For the rest of the operators, usage 
on objects of secondary datatypes 
is illegal (not supported). 
 
But, C++ provides an option to define 
a special function that would have the 
logic of operator action on the objects 
of secondary datatype. 
Doing so is termed as Operator Overloading. 
 
After operator overloading, the usage 
of the operator is allowed on the objects
of the secondary datatype.
 
------------------------------------ 
Operator Overloading 

Operator Overloading is defining
operator functions that provide 
the logic of operator action on the
objects of secondary datatypes.
 
------------------------------------ 
Learn by case study 

----------------------------   
Case 1:  t1 + t2 
  
Here operator + is applied on two 
Time objects. 
C++ system would treat :
t1 as the caller object  
+ as the operator function  
t2 as the parameter to the function  
 
The function returns a Time object
that can be used as a result of
addition.    
----------------------------   
Case 2:  t1 - t2 
  
Here operator - is applied on two 
Time objects. 
C++ system would treat :
t1 as the caller object  
- as the operator function  
t2 as the parameter to the function  
 
The function returns a Time object
that can be used as a result of
subtraction.    
----------------------------   
Case 3:  t1 + 5
  
Here operator + is applied on one 
Time object and one int. 
C++ system would treat :
t1 as the caller object  
+ as the operator function  
5 as the parameter to the function  
 
The function returns a Time object
that can be used as a result of
addition.    
----------------------------   
Case 4:  5 + t1
  
Here operator + is applied on one 
int and one Time object. 

For the expression
5 tends to be the caller object  
+ the operator function  
t1 as the parameter to the function  
 
But 5 being an int cannot act as  
a caller object for a function of
class Time.  

So the conclusion :- 
For the expression : 5 + t1 
a valid caller object is not available.  
Hence it must be implemented as  
a non member friend function.       

In this scenario, C++ system would treat :
+ as the non member function being called  
5 as the first parameter
t1 as the second parameter   
 
The function returns a Time object
that can be used as a result of
addition.    
 
----------------------------   
Case 5:  t1 == t2
  
Here operator == is applied on two
Time objects. 
C++ system would treat :
t1 as the caller object  
== as the operator function  
t2 as the parameter to the function  
 
The function returns a boolean (int)
that can be used as a result of
comparison.    
----------------------------   
Case 6:  t1[0] 
  
Here operator [] is applied on one
Time object and one in t. 
C++ system would treat :
t1 as the caller object  
[] as the operator function  
0 as the parameter to the function  
 
The function return a value of choice.    
 
FYI : 
 Operator []  cannot be overloaded as
 a non member function. (System restriction).  
----------------------------   
Case 7 and Case 8 :  t1++ and ++t1
 
In both the cases operator ++ is acting
on one Time object. 
 
The prefix usage would update the 
Time object and return the incremented
Time. 
The postfix usage would update the 
Time object but return the old Time. 

Hence it is essential to overload the   
two usages separately.
     
For the two cases : 
 t1 is the caller object
 ++ is the operator function
 There are no parameters as the operator is unary.
 
On overloading it is identified that 
the two functions take the same signature.
And it is illegal to have multiple functions
for a class  with same signature.
 
This problem was identified by the 
developers of C++.
They introduced a "compiler fix" for 
the problem. 

The solution is to provide an int 
formal parameter to the postfix 
version of the overload. 
 
No value (int) to be passed as an  
actual parameter. 
Compiler would handle the call.  
----------------------------   
Case 9:  t1 = 5 
  
Here operator = is applied on one
Time object and one int. 
C++ system would treat :
t1 as the caller object  
= as the operator function  
5 as the parameter to the function  
 
The function return a Time object 
for cascading support.
 
Example : t2 = t1 = 5; 
FYI : 
 Operator = cannot be overloaded as
 a non member function. (System restriction).  
 
-------------------------------------------   
Case 10:  refer OperatorOverloadingNewDelete.cpp
 
-------------------------------------------   
Case 11:  cout<<t1;
 
Here operator << is applied on cout and
one Time object. 
System doesnt support outputting objects 
of secondary types using the operator <<. 
So we would overload it. 
 
For the above statement 
cout is an object of class ostream 
<< is a function defined in this program (not in ostream class)
t1 is an object of class Time, defined in this program 
 
cout, being an object of ostream, 
can act as a caller object only for 
the functions and variables that  
belong to class ostream. 
 
In other words cout cannot act as 
a caller object for functions defined 
outside ostream class. 
 
Concluding that for the above statement 
a valid caller object is not available. 
Hence the operator function to be 
overloaded as a non member friend
function. 
 
In that case for the statement  
<< : operator function being called
cout : first parameter 
t1 : second parameter 
 
operator function to return ostream  
object cout by reference so that 
cascaded usage is supported.   
-------------------------------------------   
Case 12:  cin>>t1
 
Here operator >> is applied on cin and
one Time object. 
System doesn't support inputting objects 
of secondary types using the operator >>.
So we would overload it. 
 
For the above statement 
cin is an object of class istream 
>> is a function defined in this program (not in istream class)
t1 is an object of class Time, defined in this program 
 
cin, being an object of istream, 
can act as a caller object only for 
the functions and variables that  
belong to class istream. 
 
In other words cin cannot act as 
a caller object for functions defined 
outside istream class. 
 
Concluding that for the above statement 
a valid caller object is not available. 
Hence the operator function to be 
overloaded as a non member friend
function. 
 
In that case for the statement  
>> : operator function being called
cin : first parameter 
t1 : second parameter 
 
operator function to return istream  
object cin by reference so that 
cascaded usage is supported.    
-------------------------------------------   
Case 13:  t1->display()
 
Here infix dereferencing operator -> 
is applied on one Time object and a
member of Time class. 
 
It is important to know : 
1) Operator -> is acting on object of the class and not on a pointer. 
2) Operator -> is a unary operator.
3) Operator -> must return address of Time object (current class) 
 
Q) What would the operator -> do?
A) Any action of choice on caller object.
 
Q) What is the role of display() or any other member there? 
A) Its there because in origin the operator ->  
requires a member on its RHS. 
 
Q) Will display() or any other member there be processed? 
A) YES. For its processing the operator -> is
returning address of the object of current class. 
 
Conclusion : For the statement t1->display()
two action would be taken : 
 1) execution of operator ->()
 2) execution of display() (member there)

FYI : Operator -> can only be overloaded
as a member function. 
-------------------------------------------   
Case 14:  t1(params)
 
Here operator () is acting on one Time
object and an arbitrary set of parameters. 
 
For the call : 
 t1 is the caller object
 () is the operator function being called
 parameters : arbitrary set 
 
 Operator function can return a value of choice.
  
 Learn by 2 cases.
 
 FYI : Operator () can only be overloaded
 as a member function.

-------------------------------------------   
Case 15:  x = t1
 
Here operator = is acting on one int 
and one Time object. 
 
It is important to know:
 * System allows usage of = on primary and secondary types both.
 * Operator = requires both the operands to be of same type or compatible. 
 * Operator = can only be overloaded as a member function.
 
 For the above case x is an int and operator =
 belongs to class Time.
 i.e. A valid caller object is not available.
 Recollect that : Operator = can only be overloaded as a member function.
 So the above call cannot be resolved using Operator Overloading.
 
 One solution to this case is "Type Conversion".
 
 Type conversion is defining special conversion
 functions that act on objects of secondary type
 and return a value of primary type.
 
 Type conversion functions take following syntax :

   operator <primary type>()
   {
     convert the caller object into a 
     value of  primary type.
     return that value.
   }
 
 Learn by 2 examples. 
 */  

/*
 Return By Value
-----------------
When a function returns a local variable
or a local object then system has to  
 1) Create a copy of the local variable 
    or the object being returned. 
 2) Destroy the local variable or the object
    because it has the life equal to scope of 
    the function and function is getting over.
 3) Transfer the value (copy) of the variable
    or the object that was returned. 
 4) Receive the same at the point of call. 
 5) Destroy the copy.
 
 Examples : case 1, case 2, case 3, case 4, case 7 and 8. 
   
 Return By Reference 
-----------------
When a function returns a non-local 
variable or an object then system can  
 1) Transfer the variable or the object 
 itself as it is non local i.e. not subject
 to deallocation as function gets over.
 2) Receive the same at the point of call
 
 For this the return type of the function 
 must be updated to reflect "return by reference".
 
 Example : case 9, case 11, case 12
 

*/

/*
Operator Overloading Restrictions
--------------------------------
There are some restrictions that apply 
to operator overloading. 

* New operators cannot be defined using operator overloading.
* Precedence/Associativity of an operator cannot be altered. 
* Number of operands that an operator takes cannot be changed,
  except for the operator().
* Operator functions cannot have default arguments,
  except for the operator().
* These operators cannot be overloaded :-
  . :: .* ?
* There are some restrictions that apply to 
  friend operator functions. 
  You cannot overload the 
  = () [] –> operators 
  by using a non member function.

*/
