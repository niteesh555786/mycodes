#include<stdio.h>
//to read a file : byte by byte

int main()
{
    char fname[20] = "d:\\a.txt";
    char openMode[5] = "r";
    FILE * fp; //hold the reference to the file stream
    int data; 
    
    //open the file
    fp = fopen(fname, openMode);
    
    if(fp != NULL) //test open status
    {
        //read the enitre file
        while((data = fgetc(fp)) != -1)
          printf("%c", data);
        
        //close the file
        fclose(fp);
    }
    else
        printf("\n File Open Failed");
    return 0;
}
