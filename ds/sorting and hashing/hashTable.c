//Implementation of 
//1) Hash table using array. 
//2) Handle collisions using Linear probing and chaining without replacement.

#include<stdio.h>
#define SIZE 10

struct Student
{
    int rno;
    char name[20];
    float percentage;
};

typedef struct Student Student;

void initializeTable(Student table[])
{
    int i;
    for(i =0 ; i< SIZE; i++)
    {
        table[i].rno = -1;
        strcpy(table[i].name, "");
        table[i].percentage = 0; 
    }
}

int isFull(Student table[])
{
    int i;
    for(i =0; i< SIZE; i++)
    {
        if(table[i].rno == -1)
            return 0;//false
    }
    return 1; //true
}

int hash(int r)
{//mathematical function : modulo division method
    return r % SIZE ;
}

void addRecord(Student table[])
{
    if(! isFull(table))
    {
        Student temp;
        int  key;

        printf("\n Enter rno ");
        scanf("%d", &temp.rno);
        printf("\n enter name ");
        scanf("%19s", temp.name);
        printf("\n enter percentage ");
        scanf("%f", &temp.percentage);

        //generate key based in attribute rno
        key = hash(temp.rno);
        
        if(table[key].rno == -1)
        {
            //write record at position : key
            table[key] = temp;
        }
        else
        {//collision
         //apply linear probing to find a empty location  
            int i;
            for(i = (key+1) % SIZE; i != key; i = (i+1)%SIZE)
            {
                if(table[i].rno == -1)
                {//an empty record found, save it here
                    table[i] = temp;
                }
            }
        }
    }    
    else
        printf("\n table is full ");
}

void viewAll(Student table[])
{
    int i;
    for(i =0; i< SIZE; i++)
    {
        printf("\n %3d %20s %3.2f", table[i].rno, table[i].name, table[i].percentage);
    }
}

void search(Student table[])
{
    int r, key;
    
    printf("\n Enter rno to search ");
    scanf("%d", &r);
    
    key = hash(r);
    
    if(table[key].rno == r)
    {
        printf("\n %3d %20s %3.2f", table[key].rno, table[key].name, table[key].percentage);
    }
    else
    { 
        //actually
        //chain to search
        
        //linear probe to search
        int i, flag;
        
        flag =0 ;
        for(i = (key+1)%SIZE ; i != key; i = (i+1)%SIZE)
        {
            if(table[i].rno == r)
            {
               printf("\n %3d %20s %3.2f", table[i].rno, table[i].name, table[i].percentage);
               flag = 1;
               break;
            }
        }//for
        
        if(flag == 0)
            printf("\n Record with rno %d not found ", r);
    }//else
}//search

int main()
{
    Student table[SIZE];
    int ch;
    int flag = 1;
    
    initializeTable(table);
    
    do
    {
        printf("\n 1. Add Record ");
        printf("\n 2. Modify Record ");
        printf("\n 3. Delete Record ");
        printf("\n 4. Search Record ");
        printf("\n 5. View All Record ");
        printf("\n 6. Exit ");
        printf("\n Enter Choice ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1: //add record
                addRecord(table);
                break;
            case 2: //modify record
                break;
            case 3: //delete record
                break;
            case 4: //search record
                break;
            case 5: //view all records
                break;
            case 6: //exit
                flag = 0;
                break;
            default:
                printf("\n Wrong choice ");
                break;
        }//switch
    }while(flag == 1);
    
    return 0;
}

/*
A hash table is an array/file that
stores records based on their key 
values. 
 
A key value is calculated by applying 
a mathematical function on one of the 
records attributes. 
 
Next for storing or searching the record 
its key is used as an address. 
 
This process is termed as "hashing". 
 
Advantage of hashing is direct access. 
 
Challenge for hashing method
-------------------------- 
It must try to generate a unique
key per input attribute. 
 
In case it generates a duplicate 
key then two records tend to store 
at the same address. 
 
This event is termed as "collision". 
 
Collision is to be handled by some  
resolution technique. 
 
One of the collision resolution technique 
is "linear probing". 
  
 */