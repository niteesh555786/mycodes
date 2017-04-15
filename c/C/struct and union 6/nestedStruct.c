#include<stdio.h>
/*
Implement : Nested structs
see : nestedStruct.png
*/

struct Address
{
    int plotNo;
    char locality[20];
    char city[20];
};
typedef struct Address Address;

struct Person
{
    char name[20];
    int age;
    Address adrs; //nesting
};

typedef struct Person Person;

int main()
{
    Person p;
    //Person p= { "vikas", 40, {112, "Vishrantwadi", "Pune" } };
    
    //size
    //printf("\n size of p : %d ", sizeof(p));
    
    //scan
    fflush(stdin);
    printf("\n Enter Name : ");
    scanf("%19s", p.name);
    printf("\n Enter Age : ");
    scanf("%d", &p.age);
    printf("\n Enter Address : ");
    printf("\n Enter PlotNo : ");
    scanf("%d", &p.adrs.plotNo);
    fflush(stdin);
    printf("\n Enter Locality : ");
    scanf("%19s", p.adrs.locality);
    fflush(stdin);
    printf("\n Enter City : ");
    scanf("%19s", p.adrs.city);
    
    //display
    printf("\n { %s %d { %d %s %s}}", p.name, p.age, p.adrs.plotNo, p.adrs.locality, p.adrs.city);
    return 0;
}
