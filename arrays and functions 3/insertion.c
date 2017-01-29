#include <stdio.h>
/*
Program to implement: 
Insertion Sort

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

void insertion(int a[], int s)
{
    int i, j;
    int current;
    
    for(i = 1; i< s; i++)
    {
        current = a[i];//current value
        for(j = i-1; j>=0; j--)//compare back
        {
            if(current < a[j])
                a[j+1] = a[j];
            else
                break;//stop the loop
        }//for(j...
        a[j+1] = current; //insertion
    }//for(i...
}

int main()
{
    int arr[6];
    
    scanArray(arr,6);
    displayArray(arr,6);
    insertion(arr, 6);
    displayArray(arr,6);
    
    return 0;
}

