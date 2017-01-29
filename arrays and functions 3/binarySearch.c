#include <stdio.h>
/*
Program to implement: 
Binary Search

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

//version : ascending order 
void bubble(int a[], int s)
{
    int i, j;//indices and loop control
    int temp; //swap
    
    for(i=s-1; i>0; i--)//5,4,3,2,1
    {
        for(j=0; j<i; j++)//(0,1,2,3,4,5), (0,1,2,3,4), (0,1,2,3), (0,1,2), (0,1)
        {
            if(a[j] > a[j+1])
            {//swap
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }//if
        }//for(j ...    
    }//for(i ...
}

int binarySearch(int a[], int s, int val)
{
    int x,y;//array boundaries
    int mid;
    
    x = 0; //lower boundary
    y = s-1;//upper boundary
    
    while(x <= y)
    {
        mid = (x+y)/2;
        
        //compare
        if(val == a[mid])
        {//match found
            return mid;//position (index)
        }
        else if(val < a[mid])
        {//look at LHS
            y = mid-1;
        }
        else if(val > a[mid])
        {//look at RHS
            x = mid +1;
        }
    }//while
    
    return -1; //not found
}//binarySearch

int main()
{
    int arr[7];
    int val, pos;
    
    scanArray(arr,7);
    displayArray(arr,7);
    //sort the array for binary search
    bubble(arr, 7);
    displayArray(arr,7);
    
    printf("\n Enter the value to search ");
    scanf("%d", &val);
    
    pos = binarySearch(arr, 7, val);
    if(pos != -1)
        printf("\n %d found at index %d ", val , pos);
    else
        printf("\n %d not found ", val);
    return 0;
}

