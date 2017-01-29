#include <stdio.h>
/*
Program to implement: 
Sequential Search   

refer : sequential search.txt 
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

int seqSearch(int a[], int s, int x)
{
 int i;   
 for(i =0 ; i < s; i++)
 {
  if(x == a[i]) //compare for equality
  { //match found
   return i;//index of element that matches	
  }
 }//for
 
 //conclude match is not found
 return -1;//value indicating not found
}

int main()
{
    int arr[6];
    int pos, x;
    scanArray(arr,6);
    displayArray(arr,6);

    printf("\n Enter the value to search ");
    scanf("%d", &x);
    
    pos = seqSearch(arr, 6, x);
    if(pos != -1)
        printf("\n %d found at index %d", x, pos);
    else
        printf("\n %d not found", x);
    return 0;
}
