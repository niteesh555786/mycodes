/*
Implement Insertion Sort
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

void insertionSort(int a[], int s)
{
    int i, j ; //loop control and array indices
    int current;//element to be sorted
    
    for(i = 1; i < s; i++)
    {
        current = a[i];//value to be inserted at correct position
        //for backward comparison
        for(j = i-1; j >= 0; j--)
        {
            if(current < a[j])
            {
                a[j+1] = a[j];
            }
            else
            {
                break;
            }
        }//for(j 
        //insertion
        a[j+1] = current;
        
    }//for(i
    
}

int main()
{
    int arr[7];
    
    scanArray(arr, 7);
    printArray(arr, 7);
    insertionSort(arr,7); 
    printArray(arr, 7);
            
    return 0;
}
        

