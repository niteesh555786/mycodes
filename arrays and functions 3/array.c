#include <stdio.h>
/*
Program to demonstrate :
ARRAYS 
 
See about arrays.txt 
See arrays.png 
 */

int main() 
{
    int i;
    //declare an int array of 5 elements
    int arr[5];
    
    //scan values for the array
    printf("\n Enter 5 numbers ");
/*    
    scanf("%d", &arr[0]);
    scanf("%d", &arr[1]);
    scanf("%d", &arr[2]);
    scanf("%d", &arr[3]);
    scanf("%d", &arr[4]);
*/    
    for(i=0; i<5; i++)
      scanf("%d", &arr[i]);
    
    //display
    printf("\n");
    for(i =0; i<5; i++ )
        printf(" %d ", arr[i]);
    
    return 0;
}
