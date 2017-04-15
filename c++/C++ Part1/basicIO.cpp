//studying : basic i/o 
//see : streams.png
//refer : streams.txt

#include <iostream>
using namespace std;

int main()
{
 int x, sqr;
 cout<<"\n enter a number ";
 cin >> x;
 sqr = x*x;
/*
 cout<<"\n Square of ";
 cout<<x;
 cout<<" is ";
 cout<<sqr;
*/
//cascade the operator <<
 cout<<"\n Square of " <<x <<" is "<<sqr;

 return 0;
}

/*
By including iostream we get definitions of
predefined global object cin, cout and cerr.

cin is an object of class istream.
cin is set to refer to stdin.
The class defines operator >> (extraction)
to fetch data from stdin and transfer
it into associated variable.
Example :
 cin >> x;
It (operator >>) can access the variable because 
it catches the variable as a formal parameter
reference.

cout and cerr are objects of class ostream.
cout is set to refer to stdout.
cerr is set to refer to stderr.
The class defines operator << (insertion)
to fetch data from associated variable 
and transfer it into corresponding stream.

Example :
 cout <<x;
 cout <<"hello";
 cerr <<"all";

*/