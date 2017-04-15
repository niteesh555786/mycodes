#include<stdio.h>
//declare a matrix with preset data
//and print it.

void printMat(int m[][3], int r, int c)//formal parameter m, is a reference to any int matrix that has 3 cols
{
    int i, j;
    for(i =0; i<  r; i++)//rows
    {
        printf("\n");
        for(j =0; j< c; j++)//cols
        {
            printf("%5d", m[i][j]);
        }//for(j
    }//for(i
}

int main()
{
    //declare a matrix with preset data (using matrix initializer)
    int mat[2][3] = { {10,20,30} ,{11,22,33} };

    //other declarations
    //int i, j;
    
    //print it
    /*
    for(i =0; i<  2; i++)//rows
    {
        printf("\n");
        for(j =0; j< 3; j++)//cols
        {
            printf("%5d", mat[i][j]);
        }//for(j
    }//for(i
    */
    printMat(mat, 2, 3);//passing matrix as actual parameter to a function, by reference
    return 0;
}
