class A
{
 void f1()
 {
  System.out.println("A f1()");
 }

 void f2()
 {
  System.out.println("A f2()");
 }
}//A

class B extends A
{
 //redefines an inherited method
 //i.e. overrides
 void f2()
 {
  System.out.println("B f2() starts");
  f3(); //connect with the extended code
  System.out.println("B f2() ends");
 }

 void f3()
 {
  System.out.println("B f3()");
 }
}

class InheritCode
{
 //execution
 public static void main(String args[])
 {
  B objB = new B();
  objB.f1();//inherited code
  objB.f2();//overridden code
 }//main
}//InheritCode