#include <stdio.h>
//demonstration of command line arguments 
//refer about command line arguments.txt 
//see commandLineArguments.png

int main(int argc, char **argv)
{
    int i;
    printf("\n Number of command line arguments : %d  ", argc);
    printf("\n command line arguments : ");
    for(i =0; i< argc; i++)
    {
        //printf("\n arg%d : %s", *(argv+i));
        printf("\n arg%d : %s", i, argv[i]);
    }
    return 0;
}
