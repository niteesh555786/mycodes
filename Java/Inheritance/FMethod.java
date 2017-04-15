/*
Java allows definition of final
methods.
A final method is a method that 
cannot be overridden.
*/

class A
{
 final void fx()
 {
  System.out.println("final method cannot be overridden");
 }
}//A

class B extends A
{
 /*void fx()
 {
  System.out.println("B fx()");
 }*/
}

class FMethod
{
 public static void main(String args[])
 {
  B objB = new B();
  objB.fx();//inherited method
 }
}