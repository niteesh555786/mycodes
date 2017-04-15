package p2;

import p1.Base;
public class NonDerived1
{
 Base b;
 public NonDerived1()
 {
  System.out.println("p2 NonDerived1 NonDerived1()");
  b = new Base();

  //b.i++;
  //b.j++;
  //b.k++;
  b.l++;
 }

 public void display()
 {
  System.out.println("p2 NonDerived1 display() ");
  System.out.println("b.i : not accessible");
  System.out.println("b.j : not accessible" );
  System.out.println("b.k : not accessible");
  System.out.println("b.l : " + b.l);
  System.out.println("==============");
  b.display();
 }//display
}//NonDerived1