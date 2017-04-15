//Java Program to demonstrate
//Controlling threads to sequentially
//access a Shared Resource

class Server //extends Object
{
 String data;

 synchronized void display(String s)
 {
  int i;
  data = s;
  for(i =0 ; i < 10; i++)
  {
   System.out.println();
   System.out.print("[");
   System.out.print(" ");
   System.out.print(data.toUpperCase());
   System.out.print(" ");
   System.out.print("]");
   System.out.println();
    
  }//for
 }//display

 synchronized void print(String s)
 {
  int i;
  data = s;
  for(i =0 ; i < 10; i++)
  {
   System.out.println();
   System.out.print("{");
   System.out.print(" ");
   System.out.print(data.toLowerCase());
   System.out.print(" ");
   System.out.print("}" );
   System.out.println();
    
  }//for
 }//print

}//Server


class Client extends Thread
{
 Server svr;
 String str;

 Client(Server svr, String str)
 {
   this.svr = svr;
   this.str = str; 
   start();//activate the thread
 }

 public void run()
 {//execeutes concurrently
  if(str.equalsIgnoreCase("Hello"))
   svr.print(str);
  else
   svr.display(str);
 }
}

class Sync
{
 public static void main(String args[])
 {
  Server svr = new Server();
  Client c1 = new Client(svr, "Hello");
  Client c2 = new Client(svr, "Critical");
  Client c3 = new Client(svr, "Sections");

 }
}