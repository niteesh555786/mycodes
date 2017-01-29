#include <stdio.h>
/*
 Program to test :
 PASS BY VALUE

 */

void swap(int q, int w)
{
    int temp;
    temp = q;
    q = w;
    w = temp;
}

int main()
{
    int x, y;
    x = 10;
    y = 20;
    printf("\n %d  %d ", x, y);
    swap(x, y);
    printf("\n %d  %d ", x, y);
    return 0;
}

