#include <stdio.h>
/*
Program to implement: 
Selection Sort

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

void selection(int a[], int s)
{
    int i, j, min;//indices
    int temp;//swapping
    
    for(i = 0; i< s-1; i++)
    {
        min = i;//assumed minimum
        for(j = i+1; j<s; j++)//compare ahead
        {
            if(a[j] < a[min])
                min = j;
        }//for(j...

        if(i != min)//assumed and actual min differ, so swap
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }//if
    }//for(i...
}//selection

int main()
{
    int arr[6];
    
    scanArray(arr,6);
    displayArray(arr,6);
    selection(arr, 6);
    displayArray(arr,6);
    
    return 0;
}
