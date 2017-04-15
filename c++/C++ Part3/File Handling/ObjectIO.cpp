//Program to file handling
//Object IO
//refer : about file handling.txt

#include<iostream>
#include<fstream>
using namespace std;

class Student
{
private :
    int rno;
    char name[20];
    float percentage;
public:
    void getData();
    void display();
};

void Student :: getData()
{
    cout<<"\n Enter Roll no : ";
    cin>>rno;
    cout<<"\n Enter Name : ";
    cin>>name;
    cout<<"\n Enter Percentage : ";
    cin>>percentage;
}

void Student :: display()
{
    cout<<"\n Rno : "<<rno;
    cout<<"\n Name : "<<name;
    cout<<"\n Percentage : "<<percentage;
}

int main()
{
    //open the file for reading and writing in binary mode
    fstream fio;
    fio.open("d:/ObjectIO.txt", ios::in | ios::out | ios::trunc | ios::binary); //in : read, out : writing, trunc : erase all content on open, binary : binary mode
    
    //test open status
    if(fio)
    {
        Student s1, s2;
        s1.getData();
        
        //write the object
        //Initial address of object converted in char pointer form and size of object are passed as parameters to the write function
        fio.write((char*)&s1, sizeof(Student));
        
        //set the file read pointer to position : BOF	        
        fio.seekg(0, ios::beg);
        
        //read the object
        //Initial address of object converted in char pointer form and size of object are passed as parameters to the read function
        fio.read((char*)&s2, sizeof(Student));
        
        s1.display();
        s2.display();
        
        //close the file
        fio.close();
    }
    else
        cout<<"\n File Open Failed";
    return 0;
}
