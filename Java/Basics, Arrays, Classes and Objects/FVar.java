/*
Java allows declaration of 
* Variables
* Methods
* Classes
as "final".

final variables
----------------
final variables are variables that can be
assigned once.
Then they can be used as read only.
i.e. they cannot be modified after one
assignment.

Known that Java allows variables to be
* local 
* member
Both types of variables can be made final.
(meaning of final remains same).

A final local variable is 
* declared.
* assigned a value.
* used as read only. 


A final member variable is 
* declared.
* assigned a value either through a initializer block or a constructor (not both and not through any method).
* used as read only.

*/


class FVar
{
 final int x;
 int y;

 {
  //x = 10;//remove this otherwise, the initialization by the constructors would be reinitialization i.e. illegal.
 }

 FVar()
 {
  System.out.println("FVar()");
  x = 1;
  y = 2;
 }

 FVar(int q, int w)
 {
  System.out.println("FVar(int,int)");
  x = q;
  y = w;
 } 

 void increment()
 {
  //x++;//error because final variable cannot be modified
  y++;
 }

 void display()
 {
  System.out.println(x + "  " + y);
 }

 //execution
 public static void main(String args[])
 {
  FVar obj1 = new FVar();
  FVar obj2 = new FVar(11,22);

  obj1.increment();
  obj2.increment();
 
  obj1.display();
  obj2.display();

  final int q;
  q = 10;
  //q++;//error as final variable cannot be reassigned
  System.out.println("q : " + q);
 }
}