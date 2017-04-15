//Implementation of a Graph using adjacency list
//Finding Shortest distance between two vertices Using Dijkstra Algorithm
//refer : about dijkstra.txt 
//see : dijkstra.png

#include<stdio.h>
#include<stdlib.h>
#define SIZE 30

//forward declaration of struct eNode
struct eNode;

struct vNode
{
    struct vNode * nextV;
    int val;
    struct eNode * headE;
};
typedef struct vNode vNode;

struct eNode
{
    vNode * vTo;
    int weight;
    struct eNode * nextE;
};
typedef struct eNode eNode;

struct Graph
{
    vNode * head;
    int n;
};
typedef struct Graph Graph;

void create(Graph * gp)
{
    char ch;
    vNode  *n, *p;
    vNode *v1,*v2;
    int x;
    eNode * e1, *e2, *ep;
    
    gp->head = NULL;
    gp->n = 0;
    
    printf("\n Creating vertices ");
    do
    {
        //vertex create
        n = (vNode *) malloc(sizeof(vNode));
        
        //initialize
        printf("\n Enter the data for vertex ");
        scanf("%d", &n->val);
        n->nextV = NULL;
        n->headE = NULL;
        
        //connect
        if(gp->head == NULL)
        {//first node
            gp->head = n;
            p = n;
            gp->n++;
        }
        else
        {//rest of the nodes
            p->nextV = n;
            p = n;
            gp->n++;
        }
        //cycle
        printf("\n Create more vertices (y/n) ");
        fflush(stdin);
        scanf("%c", &ch);
    }while(ch == 'y' || ch == 'Y');
    
    printf("\n Creating edges ");
    
    for(v1 = gp->head; v1 != NULL; v1 = v1->nextV)
    {
        for(v2 = v1->nextV; v2 != NULL; v2 = v2->nextV)
        {
            printf("\n Is there an edge between %d and %d (y/n) ", v1->val, v2->val);
            fflush(stdin);
            scanf("%c", &ch);
            
            if(ch == 'y' || ch == 'Y')
            {
                //create an edge between v1 and v2
                e1 = (eNode *) malloc(sizeof(eNode));
                
                //initialize the edge
                printf("\n Enter weight ");
                scanf("%d", &x);
                
                e1->vTo = v2;
                e1->weight = x;
                e1->nextE = NULL;
                
                if(v1->headE == NULL)
                {
                    v1->headE = e1;
                }
                else
                {
                    ep = v1->headE;
                    while(ep->nextE != NULL)
                        ep = ep->nextE;
                    
                    ep->nextE = e1;
                }
                
                //create an edge between v2 and v1
                e2 = (eNode *) malloc(sizeof(eNode));
                e2->vTo = v1;
                e2->weight = x;
                e2->nextE = NULL;
                
                if(v2->headE == NULL)
                {
                    v2->headE = e2;
                }
                else
                {
                    ep = v2->headE;
                    while(ep->nextE != NULL)
                        ep = ep->nextE;
                    
                    ep->nextE = e2;
                }
            }//if(ch == 'y'
        }//for(v2
    }//for(v1
    
}


int getIndexOfVertex(Graph *g, int val)
{
    vNode * p;
    int indx = 0;
    
    p = g->head;
    while(p != NULL)
    {
        if(p->val == val)
            return indx;
        p = p->nextV;
        indx++;
    }
    return -1;//not found
}


int distanceBetween(Graph * g, int current, int i)
{
    int x;
    vNode *p1, *p2;
    eNode *q;
    
    p1 = g->head;
    for(x =0 ; x< current; x++)
        p1 = p1->nextV;
    
    p2 = g->head;
    for(x = 0; x < i ; x++)
        p2 = p2->nextV;
    
    for(q = p1->headE; q != NULL; q = q->nextE)
    {
        if(q->vTo == p2)
            return q->weight;
    }
    
    return 999;
}

void dijkstras(Graph *g)
{
    int i,j,k;
    int srcVertex, trgtVertex;
    int srcI, trgtI;
    int current;
    int currentDistance, newDistance, smallestDistance;
    int visited[SIZE], distance[SIZE];
    
    printf("\n Enter source vertex ");
    scanf("%d", &srcVertex);
    
    printf("\n Enter target vertex ");
    scanf("%d", &trgtVertex);
    
    //validate srcVertex and trgtVertex
    
    srcI = getIndexOfVertex(g, srcVertex);
    if(srcI == -1)
    {
        printf("\n Invalid Source Vertex ");
        return;
    }
    
    trgtI = getIndexOfVertex(g, trgtVertex);
    if(trgtI == -1)
    {
        printf("\n Invalid Target Vertex ");
        return;
    }

    //initialize the visited and distance vectors
    for(i =0; i< g->n; i++)
    {
        visited[i] = 0; //unvisited 
        distance[i] = 999;//infinite
    }

    current = srcI;
    distance[current] = 0; //0 distance away from source
    visited[current] = 1;//source is not to be visited again
    
    while(current != trgtI)
    {
        currentDistance = distance[current];
        
        //calculate new distance for all unvisited neighbors of current
        for(i =0 ; i< g->n; i++)
        {
            if(visited[i] == 0)//unvisited neighbor
            {
              newDistance = currentDistance + distanceBetween(g, current, i);  
              if(newDistance < distance[i])
              {
                  distance[i] = newDistance;
              }
            }//if
        }//for(i
        
        //select next current as the unvisited node with minimum distance
        smallestDistance = 999;
        for(i =0; i< g->n; i++)
        {
            if(visited[i] == 0)
            {
                if(distance[i] < smallestDistance)
                {
                    smallestDistance = distance[i];
                    current = i;
                }
            }
        }//for
        
        //mark the next current as visited
        visited[current] = 1;
    }//while
    
    printf("\n Shortest Distance Between %d and %d is %d ", srcVertex, trgtVertex,  distance[trgtI]);
}

int main()
{
    Graph g;
    create(&g);
    dijkstras(&g);
   
    return 0;
}