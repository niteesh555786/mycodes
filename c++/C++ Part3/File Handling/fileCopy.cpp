//Program to file handling
//Copy a file
//refer : about file handling.txt
//see : fileCopy.png

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    char src[20], trgt[20];
    
    cout<<"\n Enter source file name : ";
    cin>>src;
    cout<<"\n Enter target file name : ";
    cin>>trgt;


    //open the source file for reading in binary mode
    ifstream fin;
    fin.open(src, ios::in | ios::binary); //file must exist and have read permission
    
    //open the target file for writing in binary mode
    ofstream fout;
    fout.open(trgt, ios::out | ios::binary);//file would be created or overwritten
    
    //test open status
    if(fin && fout)
    {
        int x;
        while((x = fin.get()) != -1)
            fout.put(x);
        
        //close the files
        fin.close();
        fout.close();
        
        //message
        cout<<"\n FILE COPIED";
    }
    else
        cout<<"\n File Copy Failed";
    return 0;
}

