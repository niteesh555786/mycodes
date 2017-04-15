#include <stdio.h>
/*
Implementing String Operations  
    Basic String Handling
  
Refer about string.txt
See the diagram 
*/

int main()
{
    //declare a string
    char str[20];
    
    //fetch data from keyboard and put in the string
    printf("\n Enter a string ");
    scanf("%19s", str);
    
    //display the string on the monitor
    printf("\n String is : %s ", str);
    
    return 0;
}
