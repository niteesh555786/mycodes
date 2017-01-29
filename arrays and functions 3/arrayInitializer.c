#include <stdio.h>
/*
Array Initializer 
----------------
An array initializer is used 
to assign some default values 
to an array, while declaration. 
 
See numerous cases: 
 */

int main()
{
    int i;
    //int arr[5];//initializer not used, array elements contain garbage values
    //int arr[5] = {10,20,30,40,50};//initializer used, it assigns values 10,20,30,40 and 50 to array elements 0,1,2,3,4 respectively
    //int arr[5]= {10,20,30};//initializer used, it assigns values 10,20,30 to elements 0,1 and respectively. Remaining elements are set to zero value.
    //int arr[5] = {};//initializer used with no values, sets all elements to zero value.
    int arr[5] = {11,22,33,44,55,66};//initializer used with excess values, results in either an error or a warning. If warning then assigns values 11,22,33,44 and 55 to array elements 0,1,2,3 and 4 respectively and value 66 is ignored.
    
    printf("\n");
    for(i =0; i< 5; i++)
        printf(" %d ", arr[i]);
    return 0;
}
