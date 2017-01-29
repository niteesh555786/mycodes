#include <stdio.h>

//demonstrating use of printf
//to control cursor movement

int main() //program starts here
{
    printf("Hello C");        
    printf("\n");
    printf("Hello");        
    printf("\t");
    printf("Students");        
    printf("\r");
    printf("h");
    printf("\b");
    printf("H");
    printf("\n");
    printf("\"printf\" is 100%% \'good\'\a\a\a\a");
    printf("\n \\\\ prints \\");
            
    return 0;
}//program ends here

/*
One must use escape sequence characters 
in double quotes to make printf control 
cursor movement. 
 
\n : Moves the cursor to beginning of a new line  
\t : Moves the cursor to the right by one tab width.
\r : Moves the cursor to the beginning of current line.
\b : Moves the cursor to the left by one position (character).
\a : Play an alert sound 
\" : To print "
\' : To print '
\\ : To print \      
%% : To print % 
 */
