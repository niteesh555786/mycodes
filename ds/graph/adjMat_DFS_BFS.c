//Implementation of a Graph using adjacency matrix
//Performing DFS and BFS traversals

#include<stdio.h>
#define SIZE 30

struct Stack
{
    int data[SIZE];
    int top;
};
typedef struct Stack Stack;

//set the Stack object to an initialized state
void initS(Stack *p)
{
    p->top = -1;
}

int isEmptyS(Stack *p)
{
    return p->top == -1;
}

int isFullS(Stack *p)
{
    return p->top == SIZE -1;
}

void push(Stack *p , int val)
{
    if( ! isFullS(p))
    {//push
        p->top++;//gain a position
        p->data[p->top] = val;//add the value at position
    }
    
}

int pop(Stack *p)
{
    int val= 0;
    
    if(! isEmptyS(p))
    {//pop
       val = p->data[p->top];//fetch the value at position 
       p->data[p->top] = 0;//logical deletion
       p->top--;//lose a position
    }
    
    return val;
}

struct Queue
{
    int data[SIZE];
    int r;//to add values at
    int f;//to remove value from
};
typedef struct Queue Queue;

int initQ(Queue *p)
{
    p->r = -1;
    p->f = -1;
}

int isEmptyQ(Queue *p)
{
    return p->f == p->r;
}

int isFullQ(Queue *p)
{
    return p->r == SIZE -1;
}

void addQ(Queue *p, int val)
{
    if(! isFullQ(p))
    {//add
        p->r++;//gain a add position
        p->data[p->r] = val;//add a value
    }
    
}

int delQ(Queue *p)
{
    int val = 0;
    
    if(! isEmptyQ(p))
    {
        p->f++;//gain a remove position
        val = p->data[p->f];//fetch the value
        p->data[p->f]= 0;//logical deletion
    }
    
    return val;
}

struct Graph
{
    int vertices[SIZE];//vertices
    int adjMat[SIZE][SIZE];//edges
    int n;//no of vertices
};
typedef struct Graph Graph;


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
        p->adjMat[i][i] = 0;//no self loop
        for(j = i+1; j < p->n; j++)
        {
            printf("\n Is there an edge between %d and %d (y/n) ", p->vertices[i], p->vertices[j]);
            fflush(stdin);
            scanf("%c", &ch);
    
            if(ch == 'y' ||ch == 'Y')
            {//edge exists
                p->adjMat[i][j] = 1;
                p->adjMat[j][i] = 1;//bidirectional
            }
            else
            {//edge doesnt exists
                p->adjMat[i][j] = 0;
                p->adjMat[j][i] = 0;
            }
        }//for(j ...
    }//for(i ...   

}//create

void dfs(Graph *p)//Depth First Search
{
    int i,j,k;
    int startVal;
    int current;
    int flag;
    int visited[SIZE];
    int vindx;
    Stack s;
    initS(&s);
    
    printf("\n Enter the vertex value to start DFS from ");
    scanf("%d", &startVal);
    
    //validate the input
    flag = 0;
    for(i =0 ; i <p->n; i++)
    {
        if(p->vertices[i] == startVal)
        {//valid start point
            flag = 1;
            current = i;
            break;
        }
    }//for
    
    if(flag == 0)
    {
        printf("\n Invalid Start Value ");
        printf("\n DFS terminates");
        return;
    }
    
    //start DFS with current as root
    vindx = 0;
    visited[vindx] = current;
    vindx++;

    printf("\n DFS : ");
    
    for(i =0; i< p->n; i++)//for every vertex
    {
        printf(" %d ", p->vertices[current] );
        
        //out degrees of current
        for(j =0 ; j< p->n; j++)
        {
            if(p->adjMat[current][j] != 0)
            {//edge found with j
             //check for edge j being not visited
            
                flag = 0;
                for(k =0; k < vindx; k++)
                {
                    if(visited[k] == j)
                    {
                        flag = 1;
                        break;
                    }
                }
                
                if(flag == 0)
                {//unvisited edge current and j
                    push(&s, j);//push the edge
                    visited[vindx] = j;//mark as visited
                    vindx++;
                }
            }//edge found
            
        }//for(j ..
        current = pop(&s); 
    }//for(i
    
}//DFS

void bfs(Graph *p)//Breadth First Search
{
    int i,j,k;
    int startVal;
    int current;
    int flag;
    int visited[SIZE];
    int vindx;
    Queue q;
    initQ(&q);
    
    printf("\n Enter the vertex value to start DFS from ");
    scanf("%d", &startVal);
    
    //validate the input
    flag = 0;
    for(i =0 ; i <p->n; i++)
    {
        if(p->vertices[i] == startVal)
        {//valid start point
            flag = 1;
            current = i;
            break;
        }
    }//for
    
    if(flag == 0)
    {
        printf("\n Invalid Start Value ");
        printf("\n BFS terminates");
        return;
    }
    
    //start BFS with current as root
    vindx = 0;
    visited[vindx] = current;
    vindx++;

    printf("\n BFS : ");
    
    for(i =0; i< p->n; i++)//for every vertex
    {
        printf(" %d ", p->vertices[current] );
        
        //out degrees of current
        for(j =0 ; j< p->n; j++)
        {
            if(p->adjMat[current][j] != 0)
            {//edge found with j
             //check for edge j being not visited
            
                flag = 0;
                for(k =0; k < vindx; k++)
                {
                    if(visited[k] == j)
                    {
                        flag = 1;
                        break;
                    }
                }
                
                if(flag == 0)
                {//unvisited edge current and j
                    addQ(&q, j);//addQ the edge
                    visited[vindx] = j;//mark as visited
                    vindx++;
                }
            }//edge found
            
        }//for(j ..
        current = delQ(&q); 
    }//for(i
    
}//BFS



int main()
{
    Graph g;
    create(&g);
    dfs(&g);
    bfs(&g);
    
    return 0;
}
