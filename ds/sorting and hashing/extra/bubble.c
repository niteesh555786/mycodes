/*
Implement Bubble Sort
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


void bubbleSort(int a[], int s)
{
    int i, j;//loop counter + array element index
    int temp; //swap
    
    for(i = s-1; i> 0; i--)
    {
        for(j =0 ; j< i; j++)
        {
            if(a[j] > a[j+1])// two adjacent elements are compared
            {//swap
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }//if
        }//for(j...
    }//for(i...
}

int main()
{
    int arr[6];
    
    scanArray(arr, 6);
    printArray(arr, 6);
    bubbleSort(arr,6);
    printArray(arr, 6);

    return 0;
}

