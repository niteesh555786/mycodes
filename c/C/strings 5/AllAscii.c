#include <stdio.h>
#include <string.h>

/*
ASCII values are standard and
unique numeric codes used by a 
system to represent its character 
set (alphabets, numbers, symbols, ...) 

8 bit ASCII character set uses
ASCII values in range 0-255 
   
Popular ASCII values :
 * A - Z : 65 - 90 
 * a - z  : 97 - 122
 * 0 - 9  : 48 - 57
 * space  : 32
 
   
Printing ASCII VALUES and corresponding characters
*/

int main()
{
    int i;
    for(i =0; i< 256; i++)
    {
        printf(" [ %d %c] ", i, (char)i);
    }
    return 0;
}
