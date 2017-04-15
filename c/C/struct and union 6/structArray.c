#include<stdio.h>
//Implement : Array of Secondary Type, formed using a struct
//see about struct.txt
struct Student
{
    int rno;
    char name[20];
    float percentage;
};

typedef struct Student Student;

void scanArray(Student a[], int s)
{
    int i;
    
    for(i =0; i< s; i++)
    {
        printf("\n Enter data for Student ");
        printf("\n Rno : ");
        scanf("%d", &a[i].rno);
        printf("\n Name : ");
        fflush(stdin);
        scanf("%19s", a[i].name);
        printf("\n Percentage : ");
        scanf("%f", &a[i].percentage);
    }//for
}

void displayArray(Student a[], int s)
{
    int i;
    for(i =0; i< s; i++)
        printf("\n { %d %s %f } ", a[i].rno, a[i].name, a[i].percentage);
}
int main()
{
    //array of Student
    Student arr[3];
    
    //fetch data from user
    scanArray(arr, 3);
    //print it
    displayArray(arr, 3);
    return 0;
}
