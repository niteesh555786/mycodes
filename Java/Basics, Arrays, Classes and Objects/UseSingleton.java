//Implementation of Singleton Class

class Ston
{
 //non static member variables
 int x, y;

 //static member variable
 private static Ston ref;

 //static initializer block
 static
 {
    ref = null;
 }

 //constructor
 private Ston() 
 {
  System.out.println("Ston()");
  x = 1;
  y = 2;  
 }

 //non static methods 
 void increment()
 {
  x++;
  y++;
 }

 void display()
 {
  System.out.println(x + " " + y);
 }

 //static member method
 static Ston getObject()
 {
  System.out.println("=========");
  if(ref == null)
   ref = new Ston();
  System.out.println("=========");
  return ref;
 } 
}//Ston

class UseSingleton
{
 //execution
 public static void main(String args[])
 {
  Ston s1,s2;

  //recall that static methods are invoked without any object
  s1 = Ston.getObject();
  s2 = Ston.getObject();  

  s1.increment();
  s1.display();
  s2.display();

  if(s1 == s2) //reference comparison
   System.out.println("Both references refer to the same object");
  else
   System.out.println("References refer to different objects");

 }
}