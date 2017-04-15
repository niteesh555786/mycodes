class MyThreads extends Thread
{
 int flag;
 MyThreads(int x)
 {
  flag = x;
  start();
 }

 //override to assign tasks to custom threads
 public void run()
 {

   if(flag == 1)
    fx1();
   else if(flag == 2)
    fx2();

 }

 void fx1()
 {
  int i;
  for(i =0 ; i< 500; i++)
    System.out.print("1");  

 }

 void fx2()
 {
  int i;
  for(i =0 ; i< 500; i++)
    System.out.print("2");  

 }



 //tasks that are to be executed by main
 public static void main(String args[])
 {
  MyThreads m1 = new MyThreads(1);//create a thread
  MyThreads m2 = new MyThreads(2);//create a thread
  
  System.out.println("Active Thread Count : " + Thread.activeCount());

  int i;
  for(i =0 ; i< 500; i++)
    System.out.print("M");
 }
}