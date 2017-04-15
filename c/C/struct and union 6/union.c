#include<stdio.h>
/*
Implement : Union

A union is a combination of heterogenous data.
It is used to define custom secondary 
datatypes in C.
 
In this sense it is similar to a struct. 
Syntax and usage wise also it is similar to a struct.
 
But following are the essential differences: 
1) Members of a struct variable are
allocated individual memory space.  
Where as members of a union variable 
share a common memory space. 
 
2) All members of a struct variable 
can store data at a time.
Where as only one member of a 
union variable can store data at a time. 
 
3) Size of a struct variable is the 
sum of sizes of its members. 
Where as the size of a union variable 
is equal to the size of largest sized member. 
 
Tip:  
Use union if memory space is to 
be shared across its members.
 
see : struct-union.png
interpret the code and output
*/
struct SDemo
{
    int a;
    char b[20];
    float c;
};
typedef struct SDemo SDemo;

union UDemo
{
    int a;
    char b[20];
    float c;
};
typedef union UDemo UDemo;

int main()
{
    SDemo s;
    UDemo u;
    
    //memory test
    printf("\n ----------");
    printf("\n &s.a :  %u ", &s.a);
    printf("\n &s.b :  %u ", s.b);
    printf("\n &s.c :  %u ", &s.c);
    printf("\n");
    printf("\n &u.a :  %u ", &u.a);
    printf("\n &u.b :  %u ", u.b);
    printf("\n &u.c :  %u ", &u.c);
    
    //storage test
    printf("\n ----------");
    s.a = 10;
    strcpy(s.b, "computer");
    s.c = 1.24;
    
    u.a = 10;
    strcpy(u.b, "computer");
    u.c = 1.24;
    
    printf("\n s.a : %d ", s.a);
    printf("\n s.b : %s ", s.b);
    printf("\n s.c : %f ", s.c);
    
    printf("\n u.a : %d ", u.a);
    printf("\n u.b : %s ", u.b);
    printf("\n u.c : %f ", u.c);
    
    //size test
    printf("\n ----------");
    printf("\n size of s : %d ", sizeof(s));
    printf("\n size of u : %d ", sizeof(u));
    printf("\n ----------");    
    return 0;
}
