#include<stdio.h>
/*
Implement : Pointers of Secondary Types formed using struct
see : structPointer.png
*/

struct Student
{
    int rno;
    char name[20];
    float percentage;
};

typedef struct Student Student;

int main()
{
    //variable of Student
    Student s= {1, "vikas", 66};

    //pointer of Student
    Student *p;
    
    //referencing
    p = &s;
    
    //dereference p to access s
    printf("\n { %d %s %f } ", (*p).rno, (*p).name, (*p).percentage);
    //or
    printf("\n { %d %s %f } ", p->rno, p->name, p->percentage);

    return 0;
}
