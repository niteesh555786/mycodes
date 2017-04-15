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

void f(Student *p)//formal parameter is a pointer of type Student
{
    printf("\n { %d %s %f } ", p->rno, p->name, p->percentage);
    p->percentage = 100;
    printf("\n { %d %s %f } ", p->rno, p->name, p->percentage);
}

int main()
{
    Student s= {1, "vikas", 66};

    printf("\n { %d %s %f } ", s.rno, s.name, s.percentage);
    printf("\n-----------");
    f(&s);//pass by reference
    printf("\n-----------");
    printf("\n { %d %s %f } ", s.rno, s.name, s.percentage);

    return 0;
}
