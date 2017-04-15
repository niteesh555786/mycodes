#include<stdio.h>
//to copy a file : byte by byte

int main()
{
    char sfname[20], tfname[20];
    
    char sopenMode[5] = "rb";
    char topenMode[5] = "wb";
    
    FILE *sfp, *tfp; //hold the references to the file streams
    int data; 
    
    printf("\n Enter source file name ");
    scanf("%19s", sfname);
    fflush(stdin);
    printf("\n Enter target file name ");
    scanf("%19s", tfname);
    
    //open the files
    sfp = fopen(sfname, sopenMode);
    tfp = fopen(tfname, topenMode);
    
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
