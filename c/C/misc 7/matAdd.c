#include<stdio.h>
//declare a 2 matrices
//scan data for them
//add them

void scanMat(int m[][3], int r, int c)//formal parameter m, is a reference to any int matrix that has 3 cols
{
    int i, j;
    for(i =0; i<  r; i++)//rows
    {
        for(j =0; j< c; j++)//cols
        {
            printf("\n Enter data for mat[%d][%d] ", i, j);
            scanf("%d", &m[i][j]);
        }//for(j
    }//for(i
}//scanMat

void printMat(int m[][3], int r, int c)//formal parameter m, is a reference to any int matrix that has 3 cols
{
    int i, j;
    printf("\n");
    for(i =0; i<  r; i++)//rows
    {
        printf("\n");
        for(j =0; j< c; j++)//cols
        {
            printf("%5d", m[i][j]);
        }//for(j
    }//for(i
}


void addMat(int m1[][3], int m2[][3], int m3[][3], int r, int c)
{
    int i, j;
    for(i =0; i<  r; i++)//rows
    {
        for(j =0; j< c; j++)//cols
        {
            m3[i][j] = m1[i][j] + m2[i][j];
        }//for(j
    }//for(i
}


int main()
{
    //declare 3 matrices
    int mat1[2][3];
    int mat2[2][3];
    int mat3[2][3];

    printf("\n Scanning matrix 1");
    scanMat(mat1, 2, 3);
    printf("\n Scanning matrix 2");
    scanMat(mat2, 2, 3);
    
    addMat(mat1, mat2, mat3, 2,3);
    
    printMat(mat1, 2, 3);
    printMat(mat2, 2, 3);
    printMat(mat3, 2, 3);

    return 0;
}
