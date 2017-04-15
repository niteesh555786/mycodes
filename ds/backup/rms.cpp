#include<iostream>
#include<fstream>
using namespace std;

//program to implement : Record Management System
//see the code and comments

//forward declaration of class RMS
class RMS; 

class Student
{
private:
    int rno;
    char name[20];
    float percentage;
public:
    void set();
    void display();
    friend class RMS;
//declaring a class as friend
//allows all of its functions to
//access private/protected/public
//members of the current class.

};

void Student :: set()
{
    cout<<"\n Enter rno : ";
    cin>>rno;
    cout<<"\n Enter name : ";
    cin>>name;
    cout<<"\n Enter percentage : ";
    cin>>percentage;
}//set

void Student :: display()
{
    cout<<"\n "<<rno<<"  "<<name<<"  "<<percentage;
}


class RMS
{
private:
    char fileName[30];
public:
    RMS(char[]);
    void addRecord();
    void deleteRecord();
    void modifyRecord();
    void searchRecord();
    void viewAllRecords();
    
};//RMS


RMS :: RMS(char fname[])
{
    strcpy(fileName, fname);
}

void RMS :: addRecord()
{//appends a new record into the file

    ofstream fout;
    fout.open(fileName, ios::app | ios::binary);//opens the file for append if it exists, otherwise creates it and allows append
    
    //test file open state
    if(fout)
    {
        Student s;
        s.set();
        //write s (object) into the file
        //write is a memory copy method
        //it reads the memory of the object
        //and transfers the same into the file.
        fout.write((char*)&s, sizeof(s));
        
        //close the file
        fout.close();
        cout<<"\n Record Added";
    }
    else
        cout<<"\n Add Record Failed";
    
}

void RMS :: deleteRecord()
{
    //open the file for reading
    ifstream fin;
    fin.open(fileName, ios::in|ios::binary);
    
    //test open state
    if(fin)
    {
        //open a temporary file for writing
        ofstream fout;
        fout.open("d:\\temp.txt", ios::out|ios::trunc|ios::binary);//file will be created or overwritten. ios::trunc ensures the file to be set to zero length (truncated), if it exists.
        
        int r;
        int flag =0 ;
        Student s;
        
        cout<<"\n Enter the rno of record to be deleted : ";
        cin>>r;
        
        //delete
        while( fin.read((char*)&s, sizeof(s)) != NULL)
        {
            if(s.rno != r)
            {//transfer to temporary file
                fout.write((char*)&s, sizeof(s));
            }
            else
            {//discard and set the flag
                flag = 1;
            }
        }//while
        
        //close the files
        fin.close();
        fout.close();

        //conclude
        if(flag == 1)
        {//record to be deleted was found and discarded
            remove(fileName);
            rename("d:\\temp.txt", fileName);
            cout<<"\n Record Found And Deleted";
        }   
        else
        {//record to be deleted was not found
            remove("d:\\temp.txt");
            cout<<"\n Record Not Found ";        
        }
    }
    else
        cout<<"\n Delete Record Failed";

}

void RMS :: modifyRecord()
{
    //fstream is a child class of ifstream and ofstream
    //hence it provides features of both
    //i.e. it is a class that can be used for i/o (read/write) operations on file.
    fstream fio;
    fio.open(fileName, ios::in|ios::out|ios::binary);//file will be opened for i/o in binary mode, will not be created/overwritten
    
    if(fio)
    {
        int flag= 0;
        int r, x;
        Student s;
        
        cout<<"\n Enter the rno of the record to be modified : ";
        cin>>r;

        while(fio.read((char*)&s, sizeof(s)) != NULL)
        {
            if(s.rno == r)
            {//this is the record to be modified
                s.display();
                s.set();
                //position the put pointer at the beginning of the record to be overwritten
                x = fio.tellg(); //current position of get pointer
                x = x - sizeof(s);//one record back
                fio.seekp(x, ios::beg);
                fio.write((char*)&s, sizeof(s));
                flag = 1;
                break;
            }//if
        }//while
        //close the file
        fio.close();
        
        if(flag == 1)
            cout<<"\n Record Found and Modified";
        else
            cout<<"\n Record Not Found";
    }
    else
        cout<<"\n Modify Record Failed";

}

void RMS :: searchRecord()
{//sequential search
    
    ifstream fin;
    fin.open(fileName, ios::in|ios::binary);
    
    if(fin)
    {
        int r;
        int flag = 0;
        Student s;
        
        cout<<"\n Enter rno of record to be searched ";
        cin>>r;
        
        while( fin.read((char*)&s, sizeof(s)) != NULL)
        {
            if(s.rno == r)
            {//match
                s.display();
                flag = 1;
                break;
            }//if
        }//while
        
        //close the file
        fin.close();
        
        if(flag == 0)
            cout<<"\n Rno : "<<r<<" not found";
    }
    
    else
        cout<<"\n Search Record Failed";
}

void RMS :: viewAllRecords()
{
    //open the file for reading
    ifstream fin;
    fin.open(fileName, ios::in|ios::binary);
    
    //test open state
    if(fin)
    {
        Student s;
        //file read (get) pointer is by default at 0 offset from BOF
        
        //read given number of bytes from the file
        //and transfers the same into the object.
        //its a memory copy method

        //read returns NULL as it encounters EOF
        while( fin.read((char*)&s, sizeof(s)) != NULL)
        {
            s.display();
        }
        
        //close the file
        fin.close();
    
    }
    else
        cout<<"\n View Records Failed";
}

int main()
{
    char fname[] = "d:\\studentRMS.txt";
    RMS rms(fname);
    
    int ch, flag;
    flag = 1;
    do
    {
        cout<<"\n 1. Add Record";
        cout<<"\n 2. Modify Record";
        cout<<"\n 3. Delete Record";
        cout<<"\n 4. Search Record";
        cout<<"\n 5. ViewAll Records";
        cout<<"\n 6. Exit";
        cout<<"\n Enter Choice ";
        cin>>ch;

        switch(ch)
        {
            case 1: //add record
                rms.addRecord();
                break;
            case 2://modify record
                rms.modifyRecord();
                break;
            case 3: //delete record
                rms.deleteRecord();
                break;
            case 4://search record
                rms.searchRecord();
                break;
            case 5: //view all records
                rms.viewAllRecords();
                break;
            case 6://exit
                flag = 0;
                break;
            default:
                cout<<"\n Wrong Choice";
        }//switch
    }while(flag == 1);
    
    return 0;
}