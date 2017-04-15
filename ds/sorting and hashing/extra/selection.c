/*
Implement Selection Sort
*/

#include<stdio.h>

void scanArray(int a[], int s)
{
    int i;
    printf("\n Enter %d numbers ", s);
    for(i =0 ; i< s; i++)
      scanf("%d", &a[i]);
    
}

void printArray(int a[], int s)
{
    int i;
    printf("\n");
    for(i =0 ; i< s; i++)
        printf(" %d ", a[i]);
}

void selectionSort(int a[], int s)
{
  int i, j, min;  
  int temp ;
  
  for(i=0; i < s-1; i++)
  {
      min = i ;//assumed minimum
      for(j=i+1; j < s; j++)
      {
          if(a[j] < a[min])
          {
              min = j; //selection
          }
      }//for(j ...
      
      if(i != min) //are actual and assumed min different
      {//swap
          temp = a[min];
          a[min] = a[i];
          a[i] = temp;
      }
  }//for(i ...
}


int main()
{
    int arr[6];
    
    scanArray(arr, 6);
    printArray(arr, 6);
    selectionSort(arr,6);
    printArray(arr, 6);

    return 0;
}

