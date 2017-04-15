//Study of Two Dimensional Array

class TDim
{
 //execution
 public static void main(String args[])
 {
   //Declare a two dimensional array 
   //in C : int mat[3][4];
   //in Java :
   int mat[][] = new int[3][4];
 
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
Java allows declaration of multiple dimensional
arrays.
Being arrays, they store homogenous content.
The difference between a single and a multi
dimensional array is : 
1) Memory layout.
2) Applications.
Ideally an array be used as a linear container.
And a 2 dimensional array as a matrix like container
to be used by entities like : ChessBoard, TicTacToeBoard, ...

To declare a 2 dimensional array :
  datatype refName[][] = new datatype[SizeX][SizeY];
Example :
  int mat[][] = new int[3][4];

For the above statement :
  mat is a reference to a 2 dimensional
  array.

  new int[3][4] allocates a 2 dimensional
  array in heap segment.
  (Refer the diagram).

*/