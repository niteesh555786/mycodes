#include <stdio.h>
/*
Program to reverse an array
*/

int main() 
{
    int i, x, y;
    int arr[6], temp;
    
    //scan values for the array
    printf("\n Enter 6 numbers ");
    for(i=0; i<6; i++)
      scanf("%d", &arr[i]);
    
    //display
    printf("\n");
    for(i =0; i<6; i++ )
        printf(" %d ", arr[i]);
 
    //reverse
    x = 0;//left boundary
    y = 5 ;//right boundary
    while(x < y)
    {
        //interchange the values
        temp = arr[x];//10
        arr[x] = arr[y];
        arr[y] = temp;
        
        //reinitialization
        x++;
        y--;
    }//while
    
    //display
    printf("\n");
    for(i =0; i<6; i++ )
        printf(" %d ", arr[i]);

    return 0;
}
