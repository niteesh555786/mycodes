//Study of Ragged Array

class Ragged
{
 //execution
 public static void main(String args[])
 {
   //Declare a ragged array 
   int mat[][] = new int[3][ ];//observe that the last dimension is left unset

   //set the data arrays
   mat[0] = new int[2];
   mat[1] = new int[4];
   mat[2] = new int[3];
 
   //ragged array is ready for use

   int i, j;
   //Assign

   for(i =0; i< mat.length; i++)
   {
    for(j =0 ; j < mat[i].length; j++)
    {
      mat[i][j] = i+j+10;
    } 
   }//for(i...  

   //Display
   System.out.println(); //change the line
   for(int row[] : mat) //travserse the green array
   {
    System.out.println(); //change the line
    for(int col : row)//traversing the purple arrays rowwise
    {
      System.out.print(col + "  ");
    }
   } 

   //swap mat[1] and mat[2]
   int temp[];
   temp = mat[1];
   mat[1] = mat[2];
   mat[2] = temp;
  
   //Display Again

   System.out.println(); //change the line
   for(i =0; i< mat.length; i++)
   {
    System.out.println(); //change the line
    for(j =0 ; j < mat[i].length; j++)
    {
      System.out.print(mat[i][j] + "  " );
    } 
   }//for(i...  

 }//main
}//TDim

/*
A ragged array is ideally a two dimensional
array in which rows have varying number of
columns.

Java allows declaration of ragged array as
follows  :
1) Define a two (or n) dimensional array with value of last dimension unset.
2) Define arrays of varying sizes and associate them with the second last dimension.

Refer the diagram for visualization.
*/
