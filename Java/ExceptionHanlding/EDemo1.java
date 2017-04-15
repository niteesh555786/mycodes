//Program to demonstrate 
//Exception Handling
//refer : ExceptionHandling.txt
//see : ExceptionHandling.png

class EDemo1
{
 public static void main(String args[])
 { 
  System.out.println("Program Starts");

  try
  {
   int a, b, c;
   a = Integer.parseInt(args[0]);
   b = Integer.parseInt(args[1]);
   c = a/b;
   System.out.println(a + "/" + b + " = " + c);
  
  }
  catch(NumberFormatException ex)
  {
   System.out.println("Invalid Input");
  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Insufficient Input");
  }
  catch(ArithmeticException ex)
  {
   System.out.println("INFINITY");
  }
  finally
  {
   System.out.println("FINALLY");
  }
  System.out.println("Program Ends"); 
 }//main
}//EDemo1


/*
Interger.ParseInt()

ParseInt() is a static method of class Integer.
It takes a string as input, converts the string
into an int and returns the int.
But if conversion fails then it raises NumberFormatException

*/