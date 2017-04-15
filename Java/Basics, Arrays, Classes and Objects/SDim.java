//Study of Single Dimensional Array

class SDim
{
 //execution
 public static void main(String args[])
 {
   //Single dimensional array :
   // in C :- int arr[4];
   // in Java :-
   int arr[] = new int[4];

   //Assign 
   int i;

   //traditional iteration
   for(i =0; i< arr.length; i++)
     arr[i] = i+ 10;

  //Exercise
   int q[];
   q = arr; //another reference to the same array

   //Display
   System.out.println();//skip a line
   //iteration using for each loop
   for(int temp : q)
     System.out.print(temp + " ");
       
 }//main
}//SDim


/*
In Java, an array is a fixed sized set
of homogenous values.
It is dynamically allocated using the 
operator "new".
Its allocation takes following syntax :
datatype refName[] = new datatype[arraySize];
Example :
   int arr[] = new int[4];

In the above statement 
  arr is declared as a reference to a
  single dimensional int array.

  new int[4] allocates a single dimensional
  int array in heap segment of RAM.
  The array has clear allocation (garbage free).

  It would be usable through a reference. 

FYI
------
Java allows declaration of array references
in two ways.
* datatype refName[];
* datatype []refName;

Examples :
  int arr[];
  int []arr;

The difference can be understood by the example ahead.
* int arr[], a, b;
The above statement declares arr as int array reference and a and b as int variables.
* int []arr, a, b;
The above statement declares arr, a and b as int array references.

*/