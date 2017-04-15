//Thread Yield

class TYield implements Runnable
{
 Thread t;

 TYield()
 {
  t = new Thread(this);//instantiate
  t.start();//activate
 }

 public void run()
 {
  int i;
  for(i =0 ; i< 20; i++)
  {
   System.out.print("T");
   Thread.yield();//request to giveup the remaining portion of this time quantum so that next thread that is in queue gets execution (coopertive multitasking)
  }
 }

 public static void main(String args[])
 {
  TYield ty = new TYield();

  int i;
  for(i =0 ; i< 20; i++)
  {
   System.out.print("M");
   Thread.yield();
  }
 }//main
}//TYield 
