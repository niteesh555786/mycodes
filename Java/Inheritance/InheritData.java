class A
{
 int x,y;

 
 {//non static initializer block
  System.out.println("NSIB A ");
 }

 A()
 {
  System.out.println("A()");
  x = 10;
  y = 20;
 }

 A(int m, int n)
 {
  System.out.println("A(int,int)");
  x = m;
  y = n;
 }

}//A

class B extends A
{
 int z;
 
 {//non static initializer block
  System.out.println("NSIB B ");
 }

 B()
 {
  //super(); //to invoke A()
  System.out.println("B()");
  z = x+ y;
 }

 B(int p, int q, int r)
 {
  super(p,q); //A(int,int);
  System.out.println("B(int,int,int)");
  z = r;
 }

 void display()
 {
  System.out.println("x : " + x);//super.x
  System.out.println("y : " + y);//super.y
  System.out.println("z : " + z);//this.z
 }

}//B

class InheritData
{
 public static void main(String args[])
 {
  //B objB = new B() ; //object of sub class (Inheritance of Data)
  B objB = new B(1,2,3) ; //object of sub class (Inheritance of Data)

  objB.display();
 }
}