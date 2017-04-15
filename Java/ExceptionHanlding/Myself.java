//A custom exception
class MyException extends Exception
{
  String message;
  MyException(String s)
  {
    message= s;
  }
  
  void display()
  {
   System.out.println("Err : " + message);
  }
}

class Myself
{
 String name;
 int age;

 Myself(String n, int a)  throws MyException
 {
  setName(n);
  setAge(a);
 }

 void setName(String n)
 {//more work here
   name = n;
 }

 void setAge(int a) throws MyException
 {
   if(a >=0 && a <=100)
     age = a;
   else
   {//a case of logically wrong age
    //causes the member age to remain unset
    //next operation that uses the member age may face critical errors
    //raise an exception : "Invalid Age"
    MyException me = new MyException( "Invalid Age " + a);
    throw me;    
   }
 }

 void display()
 {
  System.out.println("Name : "  + name);
  System.out.println("Age : "  + age);

 }

 public static void main(String args[])
 {
  try
  {
    String n = args[0];
    int a = Integer.parseInt(args[1]);

    Myself m = new Myself(n,a);
    m.display();
  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
    System.out.println("Usage : java Myself <name> <age>");
  }
  catch(NumberFormatException ex)
  {
    System.out.println("Usage : java Myself <name> <age>");
  }
  catch(MyException ex)
  {
   ex.display();
  }
 }//main
}//Myself