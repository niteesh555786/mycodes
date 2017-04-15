#include <stdio.h>

//demonstration of : ++ and int as boolean

int main() 
{
    int i;
    i =0;
    /*
     In the statement if(i++)
     system has to 
      a) evaluate ++
      b) conclude as a boolean result  
     
     But ++ being a postfix operator
     take the least priority hence is
     solve later.
     i.e. system to conclude with
     current value of i as a boolean
     and then evaluate ++.
     */
    
    if(i++)
    {
        printf("\n HI %d", i);
    }
    else
    {
        printf("\n BYE %d", i);
    }
    
    return 0;
}
