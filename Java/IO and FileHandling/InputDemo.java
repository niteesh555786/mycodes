//Demonstration of methods of class InputStream
 
import java.io.*;

class InputDemo
{
 public static void main(String args[])
 {
  try
  {
   int x;
   System.out.println("Enter a string ");
   do
   {
    x = System.in.read();
    System.out.write(x);
   }while(System.in.available() > 2); //recall that last 2 bytes are of enter pressed
   System.out.flush();

  //clear the input stream 
  System.in.skip(System.in.available());

   System.out.println("\nEnter another string ");
   byte arr[] = new byte[100];
   int n;
 
   n = System.in.read(arr);
   System.out.write(arr, 0, n-2);
   System.out.flush();
   //or convert the byte array into a String
   String s = new String(arr, 0, n-2);
   System.out.println("\n"+ s);
  }
  catch(IOException ex)
  {
   System.out.println(ex);
  }
 }
}//InputDemo

//FYI : escape seq characater : \a is not supported
//FYI : char array cannot be outputted directly using %s
