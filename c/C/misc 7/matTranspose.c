#include<stdio.h>
//demonstrate : matrix transpose

void printMat(int (*p)[3], int r, int c)//formal parameter m, is a reference to any int matrix that has 3 cols
{
    int i, j;
    printf("\n");
    for(i =0; i<  r; i++)//rows
    {
        printf("\n");
        for(j =0; j< c; j++)//cols
        {
            printf("%5d", *(*(p+i)+j) );
        }//for(j
    }//for(i
}

void transpose(int m[][3], int s)
{
    int i, j; //indices
    int temp; //swapping
    
    //processing upper triangular part 
    for(i =0; i< s; i++)
    {
        for(j = i+1; j< s; j++) 
        {
            temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

int main()
{
    int mat[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    printMat(mat, 3, 3);
    
    transpose(mat, 3); //a square matrix
    
    printMat(mat, 3, 3);
    return 0;
}
