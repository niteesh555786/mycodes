//General Java Program
//Refer : Streams.rtf, Streams.png, Saving and Executing Java Program
//See : SaveCompileExecJavaPrg.png

class General
{
 //an entry point into the program
 public static void main(String args[])
 {
   int i;
   for(i =0 ; i< 10; i++)
   {
    if(i % 2 == 0)
    {
      //use the "out" channel to transfer data from application to the monitor
      System.out.println("Hello Java");
    }
    else
    {
      //use the "err" channel to transfer data from application to the monitor
      System.err.println("Hello Student");
    }
  }//for
 }//main
}//General

