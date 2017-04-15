#include<stdio.h>
//to copy a file : byte by byte
//execution using command line arguments

int main(int argc, char **argv )
{
    char sopenMode[5] = "rb";
    char topenMode[5] = "wb";
    
    FILE *sfp, *tfp; //hold the references to the file streams
    int data; 
    
    if(argc != 3)
    {
        printf("\n Wrong number of arguments ");
        return 1; 
    }
    //open the files
    sfp = fopen(argv[1], sopenMode);
    tfp = fopen(argv[2], topenMode);
    
    if(sfp != NULL && tfp != NULL) //test open status
    {
        //copy the file
        while((data = fgetc(sfp)) != -1)
          fputc(data, tfp);
        
        //close the files
        fclose(sfp);
        fclose(tfp);
        
        printf("\n File Copied");
    }
    else
        printf("\n File Copy Failed");
    return 0;
}
