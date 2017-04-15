#include<stdio.h>
#include<string.h>
//Object i/o on files

typedef struct 
{
 int rno;
 char name[20];
 float per; 
} Student;


int main()
{
    char fname[20] = "d:\\a.txt";
    char openMode[5] = "wb+";
    FILE *fp; //hold the references to the file streams
    
    Student s1= {10, "vikas kumar", 66};
    Student s2;
 
    //open the file
    fp = fopen(fname, openMode);
    
    if(fp != NULL) //test open status
    {
        //write an object
        fwrite(&s1, sizeof(Student), 1, fp);//write into fp 1 block of given size available at given location
        
        //rewind
        rewind(fp);
        
        //read back the object
        fread(&s2, sizeof(Student), 1, fp);//read from fp 1 block of given size and update the object available at given location
        
        //close the file
        fclose(fp);
        
        printf("\n s1 : {%d %s %f }", s1.rno, s1.name, s1.per);
        printf("\n s2 : {%d %s %f }", s2.rno, s2.name, s2.per);
    }
    else
        printf("\n File Open Failed");
    return 0;
}
