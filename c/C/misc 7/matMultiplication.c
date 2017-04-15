#include<stdio.h>
//declare a 2 matrices
//scan data for them
//multiply them

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


void multiplyMat(int m1[][3], int r1, int c1, int m2[][3], int r2, int c2, int m3[][3])
{
    int i, j, k ;
    int sum;
    for(i =0; i<  r1; i++)//rows of m1
    {
        for(j =0; j< c2; j++)//cols of m2
        {
            sum =0 ;
            for(k = 0; k < c1; k++ )//col of m1 and rows of m2
            {
              sum = sum + m1[i][k] *m2[k][j];
            }
            m3[i][j] = sum;
        }//for(j
    }//for(i
}


int main()
{
    //declare 3 matrices
    int mat1[2][3];
    int mat2[3][3];
    int mat3[2][3];

    printf("\n Scanning matrix 1");
    scanMat(mat1, 2, 3);
    printf("\n Scanning matrix 2");
    scanMat(mat2, 3, 3);
    
    multiplyMat(mat1, 2, 3, mat2, 3, 3, mat3);
    
    printMat(mat1, 2, 3);
    printMat(mat2, 3, 3);
    printMat(mat3, 2, 3);

    return 0;
}
