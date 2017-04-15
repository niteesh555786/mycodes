//Program to copy a file
import java.io.*;

class FCopy1
{
 public static void main(String args[])
 {
  try
  {
   String fName1 = args[0];
   String fName2 = args[1];

   //opens the file for reading in binary mode (or raises FileNotFoundException)
   FileInputStream fin = new FileInputStream(fName1);

   //creates or overwrites and opens the file for writing in binary mode (or raises IOException)
   FileOutputStream fout = new FileOutputStream(fName2);
 
   //copy
   byte arr[]= new byte[1024];
   int n;
   while((n = fin.read(arr)) != -1)
   {
    fout.write(arr, 0, n);
   } 
   fout.flush();

   //close 
   fin.close();
   fout.close();

   System.out.println("File Copied");
  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Usage : java FCopy1 <sourceFileName> <targetFileName>");
  }
  catch(IOException ex)
  {
   System.out.println(ex);
  }
 
 }//main
}//FCopy1