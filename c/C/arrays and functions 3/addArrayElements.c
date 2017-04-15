#include <stdio.h>
/*
Program to demonstrate : 
 * pass by value
 * pass by reference
 * function return value
   
Example : Add Array Elements 
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

int addArray(int a[], int s)
{
    int tot, i;
    tot = 0;
    
    for(i =0 ; i< s; i++)
        tot = tot + a[i];
    
    return tot;
}

int main()
{
    int arr[5];
    int sum;
    scanArray(arr,5);
    displayArray(arr,5);
    sum = addArray(arr, 5);
    printf("\n Sum : %d ", sum);
    return 0;
}
