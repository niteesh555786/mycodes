#include <stdio.h>
/*
Accept marks of 3 subjects
and generate a grade.

Revision of : Logical And and else if
*/

int main() 
{
    int m1, m2, m3;
    int avg;
    
    printf("\n Enter marks for 3 subjects ");
    scanf("%d%d%d", &m1, &m2, &m3);
    
    avg = (m1+m2+m3)/3;
    
    if(avg >=0 && avg <40)
    {
        printf("\n Result : FAIL");
    }
    else if(avg >=40 && avg < 60)
    {
        printf("\n Result : SECOND CLASS");
    }    
    else if(avg >=60 && avg <= 100)
    {
        printf("\n Result : FIRST CLASS");
    }
    else
    {
        printf("\n Result : INVALID");
    }
    return 0;
}
