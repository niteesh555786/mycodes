#include <stdio.h>
/*
Program to demonstrate : 
Array as parameters to function. 

Refer : about functions.txt
See : arrayFnParam.png 
 */

void f(int a[])//formal parameter is declared as an array reference
{
    printf("\n a : %x", a);//o/p a in hex form
    printf("\n size of a : %d ", sizeof(a));
    a[1] = 99;
    
}
int main()
{
    int i;
    int arr[3] = {11,22,33};
    printf("\n arr : %x", arr);//o/p arr in hex form
    printf("\n size of arr : %d ", sizeof(arr));
    printf("\n");
    for(i =0; i< 3; i++)
        printf(" %d ", arr[i]);
        
    f(arr);//call to f() with arr as actual parameter

    printf("\n");
    for(i =0; i< 3; i++)
        printf(" %d ", arr[i]);
    
    return 0;
}
