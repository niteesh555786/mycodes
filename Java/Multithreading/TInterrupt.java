class TInterrupt implements Runnable
{
 Thread t;

 TInterrupt()
 {
  t = new Thread(this);
  t.start();
 }

//case 1: Interrupt used to bring a thread out of sleep
/*
 public void run()
 {
  int i;
  for(i =0; i < 100; i++)
  {
   System.out.print("T");
   if(i == 30)
   {
    try
    {
      System.out.print("\n About to enter sleep \n");
      Thread.sleep(10000);//10 seconds     
      System.out.print("\n Out of sleep \n");
    }
    catch(InterruptedException ex)
    {
      System.out.print("\n Y dont you let me sleep \n");
    }
   }//if
  }//for  
 }//run
*/

//case 2: Interrupt used to signal termination (doesnt cause termination)
 public void run()
 {
  int i;
  for(i =0; i < 2000; i++)
  {
   System.out.print("T");
   //if(t.isInterrupted())
   //  System.out.print("i");

   if(Thread.interrupted())
     System.out.print("i");

  }//for  
 }//run

 public static void main(String args[])
 {
  TInterrupt ti = new TInterrupt();
    
  int i;
  for(i =0 ; i< 200; i++)
   System.out.print("M");

  ti.t.interrupt(); //send an interrupt to thread ti.t
  System.out.print("\n main ends \n");
  
 }//main
}//TInterrupt