//Study of Thread Join

class TJoin extends Thread
{
 TJoin()
 {
   start();  
 }

 public void run()
 {
  System.out.println("run starts");

  int i;
  for(i =0 ; i < 1000; i++)
   System.out.print("1");

  System.out.println("run ends");
 }

 public static void main(String args[])
 {
  System.out.println("main starts");

  TJoin tj = new TJoin();

  int i;
  for(i =0 ; i < 1000; i++)
  {
   System.out.print("M");
   if(i == 500)
   {
     try
     {
      System.out.println("Before Join : " + tj.isAlive());
      tj.join();
      System.out.println("After Join : " + tj.isAlive());
      
     }
     catch(InterruptedException ex)
     {}
   }
 
  }
  System.out.println("main ends");
 }

}//TJoin