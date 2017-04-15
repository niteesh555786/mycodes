//Shortest path between a source and destination of a graph
//Using : Edsgar Dijkstra Algorithm

#include<stdio.h>
#define SIZE 20

struct Graph
{
    int vertices[SIZE];
    int adjMat[SIZE][SIZE];
};
typedef struct Graph Graph;

int create(Graph *pg)
{
    int i, j;
    int n = 0;
    char ch;
    
    printf("\n creating vertices ");
    do
    {
        printf("\n enter data for a vertex ");
        scanf("%d", &pg->vertices[n]);
        n++;
        
        printf("\n create more vertices ");
        fflush(stdin);
        scanf("%c", &ch);
    }while(ch == 'y' && n < SIZE);

    printf("\n creating edges ");
    
    for(i =0; i< n; i++)
    {
        pg->adjMat[i][i]= 999;//no self loop
        for(j =i+1; j< n; j++)
        {
            printf("\n Is there an edge between %d and %d ", pg->vertices[i] , pg->vertices[j]);
            fflush(stdin);
            scanf("%c", &ch);
            if(ch == 'y')
            {//edge exists
                printf("\n enter the distance between %d and %d ", pg->vertices[i] , pg->vertices[j] );
                scanf("%d", &pg->adjMat[i][j]);
                pg->adjMat[j][i] = pg->adjMat[i][j];//bidirectional
            }
            else
            {//edge doesnt exist
                pg->adjMat[i][j] = 999;//no edge
                pg->adjMat[j][i] = 999;//no edge
            }
            
        
        }//for(j ...
    }//for(i...
    
    return n; //number of vertices
}//create

void display(Graph *pg, int n)
{
  int i, j;
  
  printf("\n");
  for(i =0; i< n; i++)
  {
    printf("\n %d    ", pg->vertices[i]);
    for(j =0; j< n; j++)
    {
        printf("%5d", pg->adjMat[i][j]);
    }//for(j...
  }//for(i...
    
}//display

int search(int arr[], int n, int val)
{//sequential search
    
    int i;
    for(i =0; i< n; i++)
    {
        if(arr[i] == val)
            return i;
    }//for
    return -1;
}

int dijstras(Graph *pg, int n)
{
    int src, trgt;
    int srcI, trgtI;
    int distance[SIZE], visited[SIZE];
    int i, current, next;
    int smallestDist, currentDist, newDist;
    
    printf("\n enter value of source vertex ");
    scanf("%d" , &src);
    srcI = search(pg->vertices, n, src);
    if(srcI == -1)
    {
        printf("\n Invalid Source ");
        return -1; //terminate the fn
    }
    
    printf("\n enter value of target vertex ");
    scanf("%d" , &trgt);
    trgtI = search(pg->vertices, n, trgt);
    if(trgtI == -1)
    {
        printf("\n Invalid Source ");
        return -1;//terminate the fn
    }

    //initializations
    for(i =0; i< n; i++)
    {
        distance[i] = 999;//infinite distance
        visited[i] = 0;//not visited
    }
    
    distance[srcI] = 0;//distance from itself
    visited[srcI] = 1; //true
    
    current = srcI;
    while(current != trgtI) 
    {
        currentDist = distance[current];
        //calculate distance        
        for(i =0; i< n; i++)
        {
            if(visited[i] == 0)
            {
                newDist = currentDist + pg->adjMat[current][i];
                if(newDist < distance[i])
                {
                    distance[i]  = newDist;
                }
            }
        }//for(i..
        
        //smallest distance from any of the vertices in tree
        smallestDist = 999;

        for(i =0; i< n; i++)
        {
            if(visited[i] == 0)
            {
                if(distance[i] < smallestDist)
                {
                    smallestDist = distance[i];
                    next = i;
                }
            }
        }//for(i..
        current = next;
        visited[next]  = 1;
    }//while
    
    return distance[trgtI];
}

int main()
{
    Graph g;
    int n , short_dist;
    n = create(&g);
    display(&g, n);
    
    short_dist = dijstras(&g, n);
    printf("\n Shortest Distance : %d ", short_dist);

    return 0;  
}