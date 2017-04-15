#include<stdio.h>
#include<string.h>
/*
 typedef statement
------------------- 
typedef statement is used to 
assign an alternate name to 
an existing datatype. 
 
syntax 
------- 
 typedef existingDatatype alternateName;
 
After typedef the datatype can
be used by both of its names. 
 
See the example: 
 */
typedef int integer;

struct Demo
{
    integer a;
    float b;
};

typedef struct Demo Demo;

int main()
{
    int i = 10; //an int variable
    integer j= 20; //an int variable
    
    Demo d = {1, 1.23};//a Demo variable assigned a value along with declaration
    
    printf("\n i : %d ", i);
    printf("\n j : %d ", j);
    printf("\n d : { %d , %f } ", d.a, d.b);
    
    return 0;
}
