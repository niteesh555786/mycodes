#include <iostream>
using namespace std;

//A general C++ Program
//Refer : Streams.txt and Streams.png

int main() 
{
    int i;
    for(i =0 ; i< 10; i++)//loop
    {
        if(i % 2 == 0) //conditional branching
            cout<<"\n Hello Students"; //using stdout to print data
        else
            cerr<<"\n Hello C++";//using stderr to print data
    }
    
    return 0;
}

