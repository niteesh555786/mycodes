#include <stdio.h>
/*
Program to implement: 
Bubble Sort   

*/

void scanArray(int a[], int s)//formal parameter a is a reference to actual parameter arr; formal parameter s is a copy of actual parameter 5
{
    int i;
    printf("\n Enter %d numbers ", s);
    for(i =0; i< s; i++)
    {
        scanf("%d", &a[i]);
    }
}

void displayArray(int a[], int s)
{
    int i;
    printf("\n");
    for(i =0 ; i< s; i++)
    {
        printf(" %d ", a[i]);
    }
}

//version : ascending order 
void bubble(int a[], int s)
{
    int i, j;//indices and loop control
    int temp; //swap
    
    for(i=s-1; i>0; i--)//5,4,3,2,1
    {
        for(j=0; j<i; j++)//(0,1,2,3,4,5), (0,1,2,3,4), (0,1,2,3), (0,1,2), (0,1)
        {
            if(a[j] > a[j+1])
            {//swap
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }//if
        }//for(j ...    
    }//for(i ...
}

int main()
{
    int arr[6];
    scanArray(arr,6);
    displayArray(arr,6);
    bubble(arr, 6);
    displayArray(arr,6);
    
    return 0;
}
