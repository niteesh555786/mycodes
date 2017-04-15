#include<stdio.h>
//implementing recursion to find greater of n numbers

/*
 Analysis
 grt(5) = 5thVal compare grt(4)
 grt(4) = 4thVal compare grt(3)
 grt(3) = 3rdVal compare grt(2)
 grt(2) = 2ndVal compare grt(1)
 grt(1) = 1stVal 
 
 */

int greater(int n)
{
    int x, y;
    printf("\n Enter a number ");
    scanf("%d", &x);
    
    if(n == 1)
        return x;
    else
    {
        y = greater(n-1);

        if(x > y)
            return x;
        else 
            return y;
    }
}

int main()
{
    int n, ans;
    printf("\n How many numbers to compare : ");
    scanf("%d", &n);
    
    ans = greater(n);
    printf("\n greatest : %d ",ans);
    
    return 0;
}
