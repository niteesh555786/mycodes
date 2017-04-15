//Program to file handling
//Read a file
//refer : about file handling.txt
//see : fileRead.png 

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    //open a file
    ifstream fin;
    fin.open("d:/a.txt"); //fin.open("d:/a.txt", ios::in);
    
    if(fin) //type converts into a boolean, becomes TRUE if file is opened otherwise FALSE
    {
        //perform read operation
        int x;
        while( (x = fin.get()) != -1)
            cout<<(char)x;
        
        
        
        //close the file
        fin.close();
    }
    else
    {
        cout<<"\n File Not Found, Or Read Permission Denied ";
    }
    return 0;
}
