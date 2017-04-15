#include <stdio.h>
/*
Program to demonstrate
loop control statements
 * break
 * continue

break : terminates the loop 
continue : skips the current loop cycle and makes the loop resume with next
 
TIP : break and continue 
must be enclosed in a condition. 
 
 */

int main() 
{
    int i;
    
    /*
    //case 1: print nos from 1 to 5
    for(i =1 ;i< 10; i++)
    {
        if(i == 6)
            break;
        printf("\n %d ", i);
    }//for
    */
/*    
    //case 2: print nos from 1 to 5
    i = 1;
    while(i< 10)
    {
        printf("\n %d ", i);
        i++;
        if(i == 6)
            break;
    }//while
*/
/*    
    //case 3: print nos from 1 to 6
    i = 1;
    do
    {
        printf("\n %d ", i);
        if(i == 6)
            break;
        i++;
    }while(i< 10);
*/
/*    
    //case 4 : print numbers from 1-4 and 6-10
    for(i =1; i< 11; i++)
    {
        if(i == 5 )
            continue;
        printf("\n %d ", i);
    }//for
*/
/*    
    //case 5 : print numbers from 1-4 and 6-10
    i = 1;
    while(i < 11)
    {
        if(i == 5 )
        {
            i++;//to avoid an infinite loop
            continue;
        }
        printf("\n %d ", i);
        i++;
    }//while
*/
    i = 1;
    do
    {
        if(i == 5 )
        {
            i++;
            continue;
        }
        printf("\n %d ", i);
        i++;
    }while(i < 11);//while
    return 0;
}
