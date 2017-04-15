//Study of Daemon and Non Daemon Threads

class DNDThreads extends Thread
{
 DNDThreads(String nm)
 {
   setName(nm);//set as the name of the thread
   if(nm.equals("B"))
    setDaemon(true); //set the thread as a daemon thread
   start();  
 }

 public void run()
 {
  String temp = getName(); //fetch the name of the thread
  if(temp.equals("A"))
    fx1();
  else if(temp.equals("B"))
    fx2();
   
 }//run

 void fx1()
 {
  System.out.println("fx1 starts");

  int i;
  for(i =0 ; i < 1000; i++)
   System.out.print("1");

  System.out.println("fx1 ends");
 }

 void fx2()
 {
  System.out.println("fx2 starts");

  int i;
  for(i =0 ; i < 2000; i++)
   System.out.print("2");

  System.out.println("fx2 ends");
 }

 public static void main(String args[])
 {
  System.out.println("main starts");

  DNDThreads t1 = new DNDThreads("A");
  DNDThreads t2 = new DNDThreads("B");

  int i;
  for(i =0 ; i < 500; i++)
   System.out.print("M");

  System.out.println("main ends");
 }
}