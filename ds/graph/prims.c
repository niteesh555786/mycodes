//Implementation of a Graph using adjacency matrix
//Generating a Minimum Spanning Tree Using PRIMS Algorithm
//refer : about prims.txt
//see : prims.png

#include<stdio.h>
#define SIZE 30

struct Graph
{
    int vertices[SIZE];//vertices
    int adjMat[SIZE][SIZE];//edges
    int n;//no of vertices
};
typedef struct Graph Graph;

struct MST
{
    int from;
    int to;
    int weight;
};
typedef struct MST MST;


void create(Graph *p)
{
    char ch;
    int x, i, j;
    
    p->n = 0;//initialization
    
    printf("\n Creating Vertices ");
    do
    {
        printf("\n Enter data for a vertex ");
        scanf("%d", &x);
        p->vertices[p->n] = x;//add a vertex at position
        p->n++;//gain a position
        
        //cycle
        printf("\n Add more vertices (y/n) ? ");
        fflush(stdin);
        scanf("%c", &ch);
    }while((ch == 'y' || ch == 'Y') && p->n < SIZE);
    
    printf("\n Creating Edges ");
    for(i =0; i< p->n; i++)
    {
        p->adjMat[i][i] = 0;//0 distance with ownself
        for(j = i+1; j < p->n; j++)
        {
            printf("\n Is there an edge between %d and %d (y/n) ", p->vertices[i], p->vertices[j]);
            fflush(stdin);
            scanf("%c", &ch);
    
            if(ch == 'y' ||ch == 'Y')
            {//edge exists
                printf("\n Enter the distance ");
                scanf("%d", &x);
                p->adjMat[i][j] = x;
                p->adjMat[j][i] = x;//bidirectional
            }
            else
            {//edge doesnt exists
                p->adjMat[i][j] = 999;
                p->adjMat[j][i] = 999;
            }
        }//for(j ...
    }//for(i ...   

}//create

void prims(Graph *p)
{
    int i, j, k, l;
    int flag;
    int startValue, current;
    int visited[SIZE], vindx;
    int min, from , to;
    
    
    MST mst[SIZE];
    int mindx = 0;
    
    printf("\n Enter a start vertex for generating MST Using PRIMS : ");
    scanf("%d", &startValue);

    //authenticate the start value
    flag = 0;
    for(i =0 ; i< p->n; i++)
    {
        if(p->vertices[i] == startValue)
        {
            flag = 1;
            current = i;
            break;
        }
    }//for
    
    if(flag == 0)
    {
        printf("\n Invalid start vertex");
        printf("\n Prims Algo. terminates");
        return;
    }
    
    //prims starts with current as root
    vindx = 0;
    visited[vindx] = current;//root of  the tree
    vindx++;
    
    for(i =1; i< p->n ; i++) //for all the vertices not in tree
    {
        min = 999;
        for(j = 0; j < vindx; j++)//for all nodes that are in tree
        {
            current = visited[j];
            
            for(k =0; k < p->n; k++) //all outdegrees of current
            {
                if(p->adjMat[current][k] !=0 && p->adjMat[current][k] != 999)
                {
                    //check for the edge being unvisited
                    
                    flag = 0;
                    for(l=0 ; l< vindx; l++)
                    {
                        if(visited[l] == k)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    
                    if(flag == 0)
                    {
                        //a weighted and unvisited edge found between current and k
                        if(p->adjMat[current][k] < min)
                        {//record
                            from = current;
                            to = k;
                            min = p->adjMat[current][k];
                        }//edge has smallest weight
                    }//edge is unvisited
                }//edge exists
            }//for(k
        }//for(j

        //transfer into the tree
        mst[mindx].from = p->vertices[from];
        mst[mindx].to = p->vertices[to];
        mst[mindx].weight = min;
        mindx++;
        
        visited[vindx] = to; 
        vindx++;
    }//for(i
    
    //output
    printf("\n MST generated using PRIMS ");
    for(i =0 ; i < mindx; i++)
        printf("\n (%d) ----%d----(%d) ", mst[i].from, mst[i].weight, mst[i].to);
    
}//prims

int main()
{
    Graph g;
    create(&g);
    prims(&g);
    return 0;
}
