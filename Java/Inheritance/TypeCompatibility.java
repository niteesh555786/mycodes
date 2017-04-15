//Program to study 
//1) Type Compatibility
//2) Late Binding
//3) Upcasting and Downcasting

//refer : Inheritance.txt
//see : TypeCompatibility.png

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
 //override
 void f2(/* B this */) //B object back in B reference : Downcast
 {
  System.out.println("B f2() starts");
  f3();//extended code
  System.out.println("B f2() ends");

 }

 //extended code
 void f3()
 {
  System.out.println("B f3()"); 
 }

}//B

class TypeCompatibility
{
 void test(A refA )
 {
  System.out.println("---------------");
  refA.f1();
  refA.f2();//dynamic method dispatch or run time bound or late bound
  System.out.println("---------------");
 }

 public static void main(String args[])
 {
  A ref1 = new A(); //object of A
  B ref2 = new B(); //object of B

  TypeCompatibility tc = new TypeCompatibility();
  tc.test(ref1);
  tc.test(ref2);// B object in A reference : Upcast

 }//main
}//TypeCompatibility