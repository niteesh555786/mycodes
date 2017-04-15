//Merge Sort

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

void mergeSort(int arr[], int s)
{
    int arr1[SIZE], arr2[SIZE];
    int s1, s2;
    int i, j, k;
    int temp;
    
    if(s%2 == 0)
        s1 = s2 = s/2;
    else
    {
        s1 = s/2;
        s2 = s - s1;
    }
    
    //copy s1 elements of arr into arr1
    for(i =0; i< s1; i++)
        arr1[i] = arr[i];
    
    //copy remaining s2 elements of arr into arr2
    for(i =0; i< s2; i++)
        arr2[i] = arr[i + s1];
    
    if(s1 > 2)
        mergeSort(arr1, s1);
    else if(s1 == 2)
    {
        if(arr1[0] > arr1[1])
        {//swap
            temp = arr1[0];
            arr1[0] = arr1[1];
            arr1[1] = temp;
        }
    }

    if(s2 > 2)
        mergeSort(arr2, s2);
    else if(s2 == 2)
    {
        if(arr2[0] > arr2[1])
        {//swap
            temp = arr2[0];
            arr2[0] = arr2[1];
            arr2[1] = temp;
        }
    }
    
    //merge
    i =0; //arr1
    j =0;//arr2
    k =0;//arr
    
    while(i < s1 && j < s2)
    {
        if(arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }//while
    
    //remaining elements in arr1
    while(i < s1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    //remaining elements in arr2
    while(j < s2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
    
}//mergeSort
    
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
    mergeSort(arr, n);
    displayArray(arr, n);
    
    return 0;
}