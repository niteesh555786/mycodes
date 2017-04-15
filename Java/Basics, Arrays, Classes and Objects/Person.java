//Study of Object Creation Process
//refer : ObjectCreationProcess.txt
//see : ObjectCreationProcess.png

class Person
{
 //data members
 int age;
 String name = "Baby"; //gets transfered into the first non static initializer block

 //non static initializer block 
 {
  System.out.println("In NSIB1");
  age = 0;
 }

 Person() //default constructor
 {
   System.out.println("Person()");
   name = "ANIL";//preset data
   age = 10;//preset data
 }

 Person(String n , int a) //Parameterized Constructor
 {
   System.out.println("Person(String, int)");
   name = n;//parameter data
   age = a;//parameter data
 }

 //method
 void Person()
 {
  System.out.println("Java allows methods to have the same name as of the class");
 } 

 void display()
 {
  System.out.println("Name : " + name);
  System.out.println("Age : " + age);
 }

 //execution
 public static void main(String args[])
 {
  System.out.println("=================");
  Person p = new Person();
  System.out.println("=================");
  Person p1 = new Person("Manoj", 15);
  System.out.println("=================");

  p.display();
  p1.display();  
  p.Person();//gets mapped with method named Person
 }

//non static initializer block 
 {
  System.out.println("In NSIB2 " );
 }
 
}