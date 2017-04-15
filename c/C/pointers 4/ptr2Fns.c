#include<stdio.h> 
/*
Pointers to functions
------------------- 
C allows declaration of pointers that
 * can refer to functions 
 * can be dereferenced to invoke functions.
 
A pointer to function takes special 
declaration that corresponds to the 
signature of the function being 
referred. 
 
Study By Interpretation of EXAMPLE.
 
 */

void f1()
{
    printf("\n f1");
}

void f2(int x)
{
    int y;
    printf("\n f2");
    y = x*x;
    printf("\n Square of %d is %d ", x, y);
}

int f3(int a, int b)
{
    int ans;
    printf("\n f3");
    ans = a + b;
    return ans;
}

int main()
{
    int x;
  
    //declaration of pointers to functions
    void (*p1)();//pointer to any function that is void and takes no parameters
    void (*p2)(int);//pointer to any function that is void and takes 1 int parameter
    int (*p3)(int,int);//pointer to any function that takes 2 int parameters and return int value

    //referencing
    p1 = f1;
    p2 = f2;
    p3 = f3;
    
    //dereferencing
    p1();
    p2(10);
    x = p3(5,6);
    printf("\n Addition : %d ",x);
    return 0;
}//main
