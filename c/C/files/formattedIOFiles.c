#include<stdio.h>
#include<string.h>

//formatted i/o on files

int main()
{
    char fname[20] = "d:\\a.txt";
    char openMode[5] = "wb+";
    FILE *fp; //hold the references to the file streams
    
    int i1, i2;
    float f1, f2;
    char s1[20], s2[20];
    
    //open the file
    fp = fopen(fname, openMode);
    
    if(fp != NULL) //test open status
    {
        i1 = 10;
        f1 = 1.23;
        strcpy(s1, "computer");

        //write data into fp
        fprintf(fp, "%d %f %s", i1, f1, s1);
        
        //reset the file pointer at BOF
        rewind(fp);

        //read data from fp
        fscanf(fp, "%d %f %s", &i2, &f2, s2);

        //close the file
        fclose(fp);
        
        printf("\n %d %d ", i1, i2);
        printf("\n %f %f ", f1, f2);
        printf("\n %s %s ", s1, s2);
        
    }
    else
        printf("\n File Open Failed");
    return 0;
}
