#include<stdio.h>
#include<string.h>
/*
struct Demo
Refer about struct.txt
See the diagrams : structDemo.png and datatypes.png 
*/

//define a custom secondary datatype
//termed as "Employee"
struct Employee
{
    int id;
    char name[20];
    char job[20];
    float salary;
};

int main()
{
    //create variables of the custom secondary datatype : Employee
    struct Employee e;
    struct Employee e1;
    
    //test its size
    printf("\n size of e : %d", sizeof(e));
    
    //test its storage
    e.id = 1;
    strcpy(e.name, "vikas");
    strcpy(e.job, "manager");
    e.salary = 10000;
    
    //copy test
    e1 = e;
    
    //output
    printf("\n e { %d, %s, %s, %f } ", e.id, e.name, e.job, e.salary);
    printf("\n e1 { %d, %s, %s, %f } ", e1.id, e1.name, e1.job, e1.salary);
    return 0;
}