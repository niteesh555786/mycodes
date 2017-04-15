//Program to read a file
import java.io.*;

class FRead1
{
 public static void main(String args[])
 {
  try
  {
   String fName = args[0];

   //opens the file for reading in binary mode (or raises FileNotFoundException)
   FileInputStream fin = new FileInputStream(fName);
 
   //read
   int n;
   byte arr[] = new byte[100];
   while((n = fin.read(arr)) != -1)
   {
    System.out.write(arr, 0,n);
   } 
   System.out.flush();

   //close 
   fin.close();
  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Usage : java FRead1 <fileName>");
  }
  catch(IOException ex)
  {
   System.out.println(ex);
  }
 
 }//main
}//FRead