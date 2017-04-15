class AddNumbers
{
 static double getNumber()
 {
  try
  {
   byte arr[] = new byte[20];
   System.in.skip(System.in.available());
   int n = System.in.read(arr);
   String temp = new String(arr, 0, n-2);
   return Double.parseDouble(temp);
  } 
  catch(Exception ex)
  {
    return 0;
  }
 }//getNumber

 public static void main(String args[])
 {
  double n1,n2, ans;
  System.out.println("Enter a number ");
  n1 = getNumber();
  System.out.println("Enter another number ");
  n2 = getNumber();
  
  ans = n1 + n2;
  System.out.println(n1 + " + " + n2 + " = " + ans);
 }//main
}//AddNumbers