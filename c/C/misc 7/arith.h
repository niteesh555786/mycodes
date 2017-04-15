#ifndef INCLUDEONCE 
#define INCLUDEONCE 1
int q = 99; //a global variable

int add(int a, int b)
{
  int ans;
  ans = a+b;		
  return ans;
}

int subtract(int a, int b)
{
  int ans;
  ans = a-b;		
  return ans;
}

int multiply(int a, int b)
{
  int ans;
  ans = a*b;		
  return ans;
}

int divide(int a, int b)
{
  int ans;
  ans = a/b;		
  return ans;
}

#endif