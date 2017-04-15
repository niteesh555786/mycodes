package p1;

public class NonDerived
{
 Base b;
 public NonDerived()
 {
  System.out.println("p1 NonDerived NonDerived()");
  b = new Base();

  //b.i++;
  b.j++;
  b.k++;
  b.l++;
 }

 public void display()
 {
  System.out.println("p1 NonDerived display() ");
  System.out.println("b.i : not accessible");
  System.out.println("b.j : " + b.j);
  System.out.println("b.k : " + b.k);
  System.out.println("b.l : " + b.l);
  System.out.println("==============");
  b.display();
 }//display
}//NonDerived