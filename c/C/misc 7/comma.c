#include<stdio.h> 
/*
 comma 
--------
 comma (,) has 2 uses in C.
 1) Separator
 2) Operator 
 
 It acts as a separator when used in
 declarations, function and macro parameters,
 in enums, etc.
 
 When used along with expressions, it
 acts as an operator.
 It clubs multiple expressions together. 
 It makes the system solve every expression
 and return the value of last expression.
 
 The expressions resolve in left to
 right sequence.
  
 Comma as an operator has the least priority. 

 */
int main()
{
    //syntax error 
    //int x = 10, 20, 30;
    //because the above is a declaration statement
    //where comma must act as a separator but
    //it is made to act as an operator. 
    
    int x,y,z; //comma acts as separator
    x = 10,20,30;//comma acts as operator
    printf("\n x : %d ", x);//x is 10 because = is more prior than ,
    
    x = (10,20,30);
    printf("\n x : %d ", x);//x is 30 because , returns the value of last expression
    
    y = 10;
    z = 15;
    x =(y++,++z,y+z);
    
    printf("\n x : %d ", x);
    printf("\n y : %d ", y);
    printf("\n z : %d ", z);
            
    
    return 0;
}//main
