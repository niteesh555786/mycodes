//Program to demonstrate 
//1) Exception Propagation
//2) Nested try blocks

//refer : ExceptionHandling.txt
//see : ExceptionHandling.png
//see : NestedTry.png

class EDemo2
{
 int a,b,c;

 void set(String arr[]) throws NumberFormatException, ArrayIndexOutOfBoundsException
 {
   a = Integer.parseInt(arr[0]);
   b = Integer.parseInt(arr[1]);
   c = 0;
 }

 void process() throws ArithmeticException
 {
   c = a/b;
 }

 void display()
 {
   System.out.println(a + "/" + b + " = " + c);
 }
 
 public static void main(String args[])
 { 
  System.out.println("Program Starts");
   
  try
  {
   EDemo2 ed = new EDemo2();
   try
   {
     ed.set(args);
   }
   catch(ArrayIndexOutOfBoundsException ex)
   {
     ed.a = 10;
     ed.b = 2;
   }

   ed.process();
   ed.display();
  }
  catch(NumberFormatException ex)
  {
   System.out.println("Invalid Input");
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
}//EDemo2
