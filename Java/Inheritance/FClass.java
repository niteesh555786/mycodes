/*
Java allows definition of final
classes.
A final class is a class that cannot
be inherited.
*/

final class A
{
 void fx()
 {
  System.out.println("final class cannot be inherited");
 }
}//A

class B //extends A
{}

class FClass
{
 public static void main(String args[])
 {
  A objA = new A();
  objA.fx();
 }
}