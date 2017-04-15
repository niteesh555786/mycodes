#include<stdio.h>
#include<string.h>
//String i/o on files

int main()
{
    char fname[20] = "d:\\a.txt";
    char openMode[5] = "ab+";
    FILE *fp; //hold the references to the file streams
    
    char str[100], ch;
    
    //open the file
    fp = fopen(fname, openMode);
    
    if(fp != NULL) //test open status
    {
        printf("\n Enter string ");
        do
        {
            //fetch a string
            fflush(stdin);
            fgets(str, 100, stdin);
            //write into the file
            fputs(str, fp);
                    
            printf("\n Write more strings ? ");
            fflush(stdin);
            scanf("%c", &ch);
        }while(ch == 'y' || ch == 'Y');

        //reset the file pointer at BOF for reading back
        //rewind(fp);
        //fseek(stream, offset, whence) //POSITION THE FILE POINTER FOR THE GIVEN STREAM AT GIVEN OFFSET WRT WHENCE (SEEK_SET(bof) , SEEK_CUR(current pos) , SEEK_END (eof))
        fseek(fp, 0, SEEK_SET);
        
        while(fgets(str, 100, fp) != NULL)
        {
            fputs(str, stdout);
        }
        //close the file
        fclose(fp);
        
    }
    else
        printf("\n File Open Failed");
    return 0;
}
