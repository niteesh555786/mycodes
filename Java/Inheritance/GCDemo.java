/*
Life of an object and Garbage Collection
---------------------------------------
Java allows creation of objects using the
operator new.
The objects are allocated in heap segment
of RAM and are accessible (usable) through
a reference.
As reference to an object gets dropped
the object becomes unusable.

Ideally reference gets dropped due to 
* Its life getting over
* Overwriting

Java's grabage collection mechanism
is a method of :
1) Scanning the heap segment to detect unreferenced objects.
2) Invokation of finalize method on the objects.
3) Deallocation of the objects.

This mechanism executes in background
in a periodic manner or can be explicitly
invoked by code.

FYI
-----
The background thread that does the garbage
collection is a high priority thread and it
named as "finalizer".

About finalize
----------------
In Java, every class inherits the Object class. 

The Object class defines the finalize method.

Due to inheritance it (finalize) becomes 
available in all the classes of Java application.

It gets invoked while garbage collection.

It can be used for resource cleanup. In that
case the class must override it.
For overriding it takes the following signature :
      protected void finalize() 
*/

class Myclass //extends Object
{
 String name;
 int arr[];

 Myclass(String n, int s)
 {
   System.out.println("Myclass(String, int)");
   name = n;
   arr = new int[s];
 }

 void display()
 {
  System.out.println(name +" has array of size : "+ arr.length);
 }

 //override to execute when object would be garbage collected
 protected void finalize()
 {
  System.out.println(Thread.currentThread());
  System.out.println("In finalize for object : "+ name);
  
 }
}

class GCDemo
{
 public static void main(String args[])
 {
  Myclass m1 = new Myclass("A", 1000);
  Myclass m2 = new Myclass("B", 100);
  Myclass m3 = new Myclass("C", 10000);

  m1.display();
  m2.display();
  m3.display();

  m1 = null;
  m3 = m2;
  
  System.out.println("--------------");
  System.gc();//request garbage collection
  
  //delay
  try
  {
   Thread.sleep( 2 * 1000);//2 seconds
  }
  catch(InterruptedException ex)
  {}
  System.out.println("--------------");

 }//main
}//GCDEMO