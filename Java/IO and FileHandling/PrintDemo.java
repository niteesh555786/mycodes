//Demonstration of methods of class PrintStream
 
import java.io.*;
import java.util.Arrays;

class PrintDemo
{
 public static void main(String args[])
 {
 try
 {
   int x = 65;
   System.out.write(x); //output A
   System.out.flush();

   byte arr[] = {65,66,67,68,69,70};
   System.out.println();
   System.out.write(arr);
   System.out.flush();

   System.out.println();
   System.out.write(arr, 2, 3);
   System.out.flush();

   System.out.println();
   x = 13;
   String str = "Hello";
   char str1[] = {'a', 'l', 'l'};

   System.out.printf("\n %d %o %x ", x,x,x);   
   System.out.printf("\n %s %s ", str, Arrays.toString(str1));   


  }
  catch(IOException ex)
  {
   System.out.println(ex);
  }
 }
}//PrintDemo

//FYI : escape seq characater : \a is not supported
//FYI : char array cannot be outputted directly using %s
