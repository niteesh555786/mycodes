/*
Study of arrays of secondary type.

Java allows creation of arrays of primary
and secondary types.

Syntax :
 datatype arrRef[] = new dataType[size]

Examples
 int arr[] = new int[4];
 Student team[] = new Student[11];

For an array of primary type, the array
elements are equivalent to variables of
the primary type.

And for an array of secondary type, the
array elements are equivalent to references
of the secondary type.

The elements are null by default and hence
the array is unusable.
As a next step, objects equivalent to the
number of elements should be created and
associated with the array.

Then the array can be utilized.

FYI
------
When an array of objects is created then
the possibility of application of alogorithms
on arrays, opens up.


*/

class CArray
{
 int x, y;

 CArray()//default constructor
 {
  System.out.println("CArray()");
  x = 1;//preset value
  y = 2;//preset value
 }

 CArray(int q, int w)//parameterized constructor
 {
  System.out.println("CArray(int, int)");
  x = q;//parameter value
  y = w;//parameter value
 }

 void display()
 {
  System.out.println(x + "  " + y);
 }

 //execution
 public static void main(String args[])
 {
 //An array of secondary type
   CArray arr[] = new CArray[3];
   arr[0] = new CArray();
   arr[1] = new CArray(11,22);
   arr[2] = new CArray(5,6);

   int i;
   for(i =0 ; i< arr.length; i++)
    arr[i].display();
   

 }//main
}//CArray