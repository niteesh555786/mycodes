//Program to file handling
//String IO
//refer : about file handling.txt

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    //open the file for reading and writing in binary mode
    fstream fio;
    fio.open("d:/StringIO.txt", ios::in | ios::out | ios::trunc | ios::binary); //in : read, out : writing, trunc : erase all content on open, binary : binary mode
    
    //test open status
    if(fio)
    {
        char ch;
        char str1[100];
        char str2[100];
        
        do
        {
            cout<<"\n Enter a string : ";
            //fetch a string of 99 bytes or until '\n' is encountered, store it in str1
            cin.getline(str1, 100, '\n');
            
            //file write
            fio<<str1<<"\n";
            
            //cycle
            cout<<"\n Write More Strings (y/n) ";
            cin>>ch;
            //clear from stdin, next 1000 bytes or until '\n' 
            cin.ignore(1000, '\n');
            
        }while(ch == 'y' || ch == 'Y');
        
        //read back
        //position the read pointer to BOF
        fio.seekg(0, ios::beg);

        while(fio.getline(str2, 100, '\n') != NULL )
        {
            cout<<str2<<"\n";
        }
        
        //close the file
        fio.close();
    }
    else
        cout<<"\n File Open Failed";
    return 0;
}

