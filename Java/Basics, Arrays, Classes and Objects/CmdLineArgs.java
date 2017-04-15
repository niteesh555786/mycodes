/*
Study of Command Line Arguments.

Command line arguments are parameters
passed from DOS/Linux shell to the Java 
application.

System fetches the passed command line
arguments and forms a String array of the
same.

Next reference to the array is passed as a
parameter to main method of the Java application.

The main method's signature is preset to 
receive the String array reference.
Code in main can utilize the array content
through the reference.

FYI
------
In case when no command line arguments 
are passed then the String array that
main receives is for size zero.
*/

class CmdLineArgs
{
 //execution
 public static void main(String args[])
 {
   System.out.println("Number of command line arguments : " + args.length);
   System.out.println("Arguments :- ");

   for(String temp : args)  
     System.out.println(temp);

 }//main
}//CmdLineArgs