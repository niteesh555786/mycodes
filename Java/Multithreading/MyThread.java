class MyThread extends Thread
{
 //override to assign tasks to custom threads
 public void run()
 {
  int i;
  for(i =0 ; i< 500; i++)
    System.out.print("R");  
 }

 //tasks that are to be executed by main
 public static void main(String args[])
 {
  MyThread mt = new MyThread();//create a thread
  mt.start(); //activate it
  System.out.println("Active Thread Count : " + Thread.activeCount());

  int i;
  for(i =0 ; i< 500; i++)
    System.out.print("M");
 }
}