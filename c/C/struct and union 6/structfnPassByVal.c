#include<stdio.h>
/*
Implement : Passing variables of secondary type, formed using a struct as parameters to function 

When a variable of Secondary Type, 
formed using a struct as is passed 
as a parameter to a function then it
is passed by value.
 
*/

struct Student
{
    int rno;
    char name[20];
    float percentage;
};

typedef struct Student Student;

void f(Student q)
{
    printf("\n { %d %s %f } ", q.rno, q.name, q.percentage);
    q.percentage = 100;
    printf("\n { %d %s %f } ", q.rno, q.name, q.percentage);
}

int main()
{
    //variable of Student
    Student s= {1, "vikas", 66};
    //print it
    printf("\n { %d %s %f } ", s.rno, s.name, s.percentage);
    printf("\n --------------");
    //pass it as a parameter to a function
    f(s);
    printf("\n --------------");
    printf("\n { %d %s %f } ", s.rno, s.name, s.percentage);
    
    return 0;
}
