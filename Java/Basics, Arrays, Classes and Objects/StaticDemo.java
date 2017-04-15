//Study of static
//refer : static.txt
//see : StaticDemo.png
//see : Class Intialization.png

class Another
{
 static
 {
  System.out.println("SIB of Another");
 }

 Another()
 {
  System.out.println("Another()");
 }
}//Another

class StaticDemo
{
 int x; //non static data member
 static int y; // static data member
 
 StaticDemo()
 {
  System.out.println("StaticDemo()");
  x = 10;
 }

 StaticDemo(int q)
 {
  System.out.println("StaticDemo(int)");
  x = q;
 }

 //non static initializer block
 {
  //this auto runs per object created
  //this can be a place to initialize the non static data members
 }

 static
 {
  System.out.println("SIB of StaticDemo");
  y = 100;//StaticDemo.y = 100;
 } 

 void display() //non static method
 {
  System.out.println("x : " + x);//this.x
  System.out.println("y : " + y);//StaticDemo.y
 } 

 static void Sdisplay() //static method
 {
  //System.out.println("x : " + x);//this.x
  System.out.println("y : " + y);//StaticDemo.y
 } 
 //execution
 public static void main(String args[])
 {
  System.out.println("in main of StaticDemo");

  System.out.println("-------------------");
  Another a1 = new Another();
  System.out.println("-------------------");
  Another a2 = new Another();
  System.out.println("-------------------");

  StaticDemo s1 = new StaticDemo(11);
  StaticDemo s2 = new StaticDemo(5);

  s1.display();//11, 100
  s2.display();//5 , 100

  StaticDemo.Sdisplay();
 }
 
}