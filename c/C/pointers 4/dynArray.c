#include <stdio.h>
#include <stdlib.h>

/*
Program to study :
Dynamic Memory Management

refer : dynMemMgmt.txt
see the diagram
interpret the example
*/

int * allocateIntArray(int units)
{
    int totalSize;
    int *p; 
    totalSize = units * sizeof(int);
    //p = (int*) malloc(totalSize);
    p = (int*) calloc(units, sizeof(int));
    return p; //starting address of the dynamic array or is NULL
}

void scanArr( int *p, int size)
{
    int i;
    printf("\n Enter %d values ", size);
    for(i=0; i< size; i++)
    {
        scanf("%d", p+i);
        //scanf("%d", &p[i]);
    }
}

void displayArr( int *p, int size)
{
    int i;
    printf("\n");
    for(i=0; i< size; i++)
        printf(" %d ", *(p+i));
}

int expandAndAdd(int *p, int size)
{
    //add the elements of array
    int i;
    int tot = 0;
    int newSize;
    for(i = 0; i< size; i++)
        tot = tot + *(p+i);
    
    //expand the dynamic array to store the addition as well
    newSize = (size +1) * sizeof(int);
    p= (int*) realloc(p, newSize);
    
    //assign addition to the expanded memory
    *(p+size) = tot;
    return (size +1);
}   

int main()
{
    int x;
    int *dynArr;
    printf("\n Enter Size of Array ");
    scanf("%d", &x);
    dynArr = allocateIntArray(x);
    
    if(dynArr != NULL)
    {
        //scan
        //scanArr(dynArr, x);
        //print
        displayArr(dynArr, x);
        //process
        x = expandAndAdd(dynArr, x);
        //print
        displayArr(dynArr, x);
        //deallocate
        free(dynArr);
        
        //After deallocation dynArr should not be used
        //even though it reflects the address it referred to.
        //Because that address is now released (deallocated)
        //and the pointer reflecting it is a "dangling pointer".
        //If it is dereferenced then it will cause
        //illegal memory access (segmentation fault).
    }
    else
        printf("\n Memory Allocation Failed");
    
    return 0;
}
