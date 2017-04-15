class MyThreadAgain implements Runnable
{
 Thread t;

 MyThreadAgain()
 {
   t = new Thread(this);//a custom thread
   t.start();//activatation  
 }

 //interface method
 public void run()
 {
  int i;
  for(i =0 ; i< 500; i++)
   System.out.print("T"); 
 }//run

 public static void main(String args[])
 {
  MyThreadAgain mta = new MyThreadAgain();

  int i;
  for(i =0 ; i< 500; i++)
   System.out.print("M"); 
    
 }//main
}//MyThreadAgain

/*
class Thread implements Runnable
{
  Runnable ref;

  Thread()
  {
   ref = this;
   ...
  }

  Thread(Runnable x)
  {
    ref = x;
    ...
  }

  void start()
  {
   ... Thread activation logic ...
   ref.run();
  }
  public void run()
  {}
}

*/