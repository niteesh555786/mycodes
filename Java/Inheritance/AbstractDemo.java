abstract class A
{
 void f1()
 {
  System.out.println("A f1()");
 }
 
 abstract void f2();
}

class B extends A
{
 void f2()
 {
  System.out.println("B f2()");
 }
}

class C extends A
{
 void f2()
 {
  System.out.println("C f2()");
 }
}


class AbstractDemo
{
 void test(A ref)
 {
  System.out.println("--------------");
  ref.f1();
  ref.f2();//runtime bound
  System.out.println("--------------");
 }

 public static void main(String args[]) 
 {
  AbstractDemo ad = new AbstractDemo();

  B objB = new B();
  C objC = new C();

  ad.test(objB);
  ad.test(objC);

 }
}