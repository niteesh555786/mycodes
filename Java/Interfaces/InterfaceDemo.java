interface I1
{
 //a final variable 
 int SIZE = 10; 

 //an abstract method
 void a_fx1();
 
 //a default method
 default void d_fx()
 {
  System.out.println("I1 d_fx()");
 }

 //a static method
 static void s_fx()
 {
  System.out.println("I1 s_fx()");
 }
}//I1


interface I2
{
 void a_fx2();
}


interface I3 extends I1, I2
{
 void a_fx3();
}

class UseI implements I3
{
 public void a_fx1()
 {
  System.out.println("a_fx1 of UseI");
 }
 
 public void a_fx2()
 {
  System.out.println("a_fx2 of UseI");
 }

 public void a_fx3()
 {
  System.out.println("a_fx3 of UseI");
 }
/*
 public void d_fx()
 {
  System.out.println("d_fx of UseI");
 }
*/
}

class InterfaceDemo
{
 public static void main(String args[])
 {
  I3 ref = new UseI();
  ref.a_fx1();
  ref.a_fx2();
  ref.a_fx3();
  ref.d_fx();
  I1.s_fx();
 }
}