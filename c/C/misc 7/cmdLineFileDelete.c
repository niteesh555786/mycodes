#include<stdio.h>
//to delete a file 
//demonstarte using command line arguments

int main(int argc, char **argv )
{
    int x;
    if(argc != 2)
    {
        printf("\n wrong number of arguemnts ");
        return 1;
    }
    //remove comes from stdio.h
    //it deletes the given file
    x = remove(argv[1]);
    if(x == 0)
        printf("\n %s deleted ", argv[1]);
    else
        printf("\n Cannot delete %s ", argv[1]);
    return 0;
}
