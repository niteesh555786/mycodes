#include <stdio.h>
/*
Program to study : pointer to array  
see : ptr2arr.png
*/

int main()
{
    int arr[5] = {10,20,30,40,50};
    int *p;
    int i;
    
    //Assign address of first element of array to a pointer
    //p = &arr[0];
    p = arr;//same as above
    
    printf("\n");
    for(i =0; i< 5; i++)
    {
        //1) apply pointer arithmetic to traverse the array
        //printf(" %d ", *(p+i));
        
        //2) as a+b and b+a mean the same, so :
        //printf(" %d ", *(i+p));
        
        //3) as p = arr, so replace occurrences of p with arr
        //printf(" %d ", *(arr+i));
        
        //4) also will work
        //printf(" %d ", *(i+arr));
        
        //5) common usage
        //printf(" %d ", arr[i]);
        
        //6) as p = arr, so replace occurrences of arr with p
        //printf(" %d ", p[i]);
        
        //7) 1) and 6) produce the same result 
        //    hence p[i] == *(p+i) and arr[i] == *(arr+i)
        //    also *(p+i) == *(i+p)
        //    therefore  p[i] == i[p]
        //printf(" %d ", i[p]);
        
        //8 Also :
        printf(" %d ", i[arr]);
    }
    return 0;
}


/*
Conclusion : Array name and 
pointer to first element of array
can be used interchangeably.   

But the array name constantly 
refers to the first element of  
the array. 
Whereas pointer being a variable
can be made to refer to some 
other location. 
 
i.e.  arr = someOtherAddress is illegal
      p = someOtherAddress is legal 
*/

