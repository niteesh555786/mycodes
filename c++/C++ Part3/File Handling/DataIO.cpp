//Program to file handling
//Data IO
//refer : about file handling.txt
//see : DataIO.png
//see : fstream.png

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    //open the file for reading and writing in binary mode
    fstream fio;
    fio.open("d:/DataIO.txt", ios::in | ios::out | ios::trunc | ios::binary); //in : read, out : writing, trunc : erase all content on open, binary : binary mode
    
    //test open status
    if(fio)
    {
        char c1, c2;
        int i1, i2;
        float f1, f2;
        
        c1 = 'q';
        i1 = 10;
        f1 = 3.14;
        
        //write the above values into the file using the insertion operator
        fio<<c1<<"\n";
        fio<<i1<<"\n";
        fio<<f1<<"\n";

        //here we are appending \n after every value to avoid merging of data
        
        //read back
        //ensure that file read (get) pointer is at BOF
        fio.seekg(0, ios::beg);
        
        fio>>c2;
        fio>>i2;
        fio>>f2;
        
        cout<<"\n c1 : "<<c1;
        cout<<"\n c2 : "<<c2;
        cout<<"\n i1 : "<<i1;
        cout<<"\n i2 : "<<i2;
        cout<<"\n f1 : "<<f1;
        cout<<"\n f2 : "<<f2;
        
        //close the file
        fio.close();
    }
    else
        cout<<"\n File Open Failed";
    return 0;
}

