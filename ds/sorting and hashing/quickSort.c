//Quick Sort

#include<stdio.h>
#define SIZE 30

void scanArray(int arr[], int n)
{
    int i;
    printf("\n Enter %d values ", n);
    for(i =0 ;i< n; i++)
        scanf("%d", &arr[i]);
}

void displayArray(int arr[], int n)
{
    int i;
    printf("\n");
    for(i =0 ;i< n; i++)
        printf(" %d ", arr[i]);

}

void quickSort(int arr[], int x, int y)
{
    int i, j;
    int key;
    int temp;
    
    if(x < y) //lower boundary < upper boundary
    {
      i = x;    
      j = y;
      key = arr[x];
     
      while(i < j)//lower boundary and upper boundary have not crossed
      {
        while(key >= arr[i] && i < y)
            i++;
        while(key < arr[j] && j > x)
            j--;

        //check whether i and j have crossed
        if(i < j)
        {//swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
      }//while
      
      //i and j have crossed
      //j is the final position of key in sorted array
      temp = arr[x]; //key
      arr[x] = arr[j];
      arr[j] = temp;
      
      //and j is the pivot point for next key
      quickSort(arr,x, j-1);
      quickSort(arr,j+1, y);
    }//if
}//quickSort
    
int main()
{
    int arr[SIZE];
    int n;
    
    printf("\n Enter the preferred size of array ");
    scanf("%d", &n);
    if(n > SIZE)
        n = SIZE;
    
    scanArray(arr, n);
    displayArray(arr, n);
    quickSort(arr, 0,n-1);
    displayArray(arr, n);
    
    return 0;
}