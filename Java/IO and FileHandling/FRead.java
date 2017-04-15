//Program to read a file
import java.io.*;

class FRead
{
 public static void main(String args[])
 {
  try
  {
   String fName = args[0];

   //opens the file for reading in binary mode (or raises FileNotFoundException)
   FileInputStream fin = new FileInputStream(fName);
 
   //read
   int x;
   while((x = fin.read()) != -1)
   {
    System.out.write(x);
   } 
   System.out.flush();

   //close 
   fin.close();
  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Usage : java FRead <fileName>");
  }
  catch(IOException ex)
  {
   System.out.println(ex);
  }
 
 }//main
}//FRead