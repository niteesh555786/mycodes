#include<stdio.h>
//implementing  recursion to calculate x raised to y
//see : rPower.png

int power(int x, int y)
{
    if(y != 0)
        return x * power(x , y-1);
    else
        return 1;
}

int main()
{
    int a, b, ans;
    a = 5; //scan
    b = 4; //scan
    
    ans = power(a,b);

    printf("\n ans : %d ", ans);
    return 0;
}
