class Quickr
{
 Product arr[];
 int position;
 Quickr()
 {
  position = -1;
  arr = new Product[5]; //may be use a linked list here
  //recollect that array elements are refernces
 }

 void sort()
 {
  Product temp;
  int i, j;
  for(i = position ; i>0; i--)
  {
   for(j =0 ; j< position; j++)
   {
    if(arr[j].getProductPrice() > arr[j+1].getProductPrice())
    {
     temp = arr[j];
     arr[j] = arr[j+1];
     arr[j+1] = temp;
    }
   }
  }
 }
 void registerProduct(Product p)
 {
   if(position < arr.length -1)
   {
     position++;
     arr[position] = p;     
   } 
   else
    System.out.println("Overflow");
 }

 void publishProducts()
 {
  int i;
  for(i =0 ; i<= position; i++)
  {
   System.out.println("============");
   System.out.println("*" + arr[i].getProductName() + "*");
   System.out.println("State : " + arr[i].getProductState());
   System.out.println("Price : " + arr[i].getProductPrice());

   System.out.println("============");

  }

 }//publishProduct 

}

interface Product
{
 String getProductName();
 String getProductState();
 int getProductPrice();
}

class Scooter implements Product
{
 String name;
 Scooter(String n)
 {
  name = n;
 }

 //many Scooter functions

 public String getProductName()
 {
  return name;
 }

 public String getProductState()
 {
  return "Good Condition";
 }

 public int getProductPrice()
 {
  return 20000; //may be logically generated
 }
}

class Laptop implements Product
{
 //many Laptop functions

 public String getProductName()
 {
  return "Samsung i5";
 }

 public String getProductState()
 {
  return "New Condition";
 }

 public int getProductPrice()
 {
  return 35000; //may be logically generated
 }
}

class Mobile implements Product
{
 //many Mobile functions

 public String getProductName()
 {
  return "Sony Xperia";
 }

 public String getProductState()
 {
  return "Old Condition";
 }

 public int getProductPrice()
 {
  return 1000; //may be logically generated
 }
}

 //....

class InterfaceApplication
{
 public static void main(String args[])
 {
  Quickr q = new Quickr();
  Scooter s1 = new Scooter("Activa");
  Scooter s2 = new Scooter("Scooty");
  Laptop l = new Laptop();
  Mobile m = new Mobile();

  q.registerProduct(s1);
  q.registerProduct(s2);
  q.registerProduct(l);
  q.registerProduct(m);

  q.publishProducts();
  q.sort();
  q.publishProducts();

 }
}