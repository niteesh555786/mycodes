class TSleep implements Runnable
{
 Thread t;

 TSleep()
 {
   t = new Thread(this);//a custom thread
   t.start();//activatation  
 }

 //interface method
 public void run()
 {
  int i;
  for(i =1 ; i< 11; i++)
  {
   System.out.println(i + " "+ System.currentTimeMillis());
   try
   {
     Thread.sleep(1000);//milliseconds
   }
   catch(InterruptedException ex)
   {} 
  }
 }//run

 public static void main(String args[])
 {
  TSleep ts = new TSleep();

 }//main
}//MyThreadAgain
