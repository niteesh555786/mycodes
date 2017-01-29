#include <stdio.h>
/*
Program to demonstrate : 
 * pass by value
 * pass by reference
 * function return value
   
Example : Find minimum value of Array 
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

int findMinimum(int a[], int s)
{
 int i, x;
 x = a[0];//assumed minimum
 for(i = 1; i< s; i++)//compare with rest
 {
  if(a[i] < x)
  {//a[i] is less than x
   x = a[i];
  }
 }//for
 return x;
}

int main()
{
    int arr[5];
    int min;
    scanArray(arr,5);
    displayArray(arr,5);
    min = findMinimum(arr, 5);
    printf("\n Minimum : %d ", min);
    return 0;
}
