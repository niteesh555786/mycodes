//Thread Priority

class TPriority implements Runnable
{
 Thread t;

 TPriority(int p)
 {
  t = new Thread(this);//instantiate
  t.setPriority(p);
  t.start();//activate
 }

 public void run()
 {
  int i;
  for(i =0 ; i< 1000; i++)
   System.out.print("T");

 }///run

 public static void main(String args[])
 {
  TPriority tp = new TPriority(10);//most

  //get a reference to main thread 
  Thread m = Thread.currentThread();
  m.setPriority(1);//least

  int i;
  for(i =0 ; i< 1000; i++)
   System.out.print("M");

 }//main
}//TPriority 
