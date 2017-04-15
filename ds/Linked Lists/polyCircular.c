//Polynomial Operations Using Circular Linked List
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    float c;//data
    int e;//data
    struct node * next;//link
};
typedef struct node node;

node * getLastNode(node * h)//utility function
{
    node *p;
    p = h;
    while(p->next != h)
        p = p->next;
    return p;
}

node * insertNode(node *h, float c, int e)
{
    node *n, *p, *q, *last;
    
    if(c == 0)
        return h;//terminate the operation
    
    //create a node (a term)
    n = (node*) malloc(sizeof(node));
    
    //initialize the node (term)
    n->c = c;
    n->e = e;
    n->next = NULL; //temporary initialization

    //connection
    if(h == NULL)
    {//first node
        h = n;
        h->next = h;//make it circular
    }
    else
    {
        int flag = 0;
        p = h;
        do
        {
            if(n->e > p->e)//new node exponent is greater than the current node exponent
            {//new node to be inserted before the current node
                if(p == h)
                {//n will be the new head node
                    last = getLastNode(h);
                    n->next = h;//connect
                    h = n; //set n as head node
                    last->next = h;//make it circular again
                    
                    flag = 1;//connection made
                    break;
                }
                else
                {//n is some intermediate node
                    q->next = n;
                    n->next = p;
                    
                    flag =1 ;
                    break;
                }
            }
            else if(n->e == p->e)//new node exponent is equal to the current node exponent
            {//merge the node
                p->c += n->c;
                free(n);
                if(p->c == 0)
                {//even p has to be deleted
                    if( p == h)
                    {
                        if(h->next == h)
                        {//only one node in the list and that too about to be deleted
                            free(h);
                            h = NULL;
                        }
                        else
                        {
                            last = getLastNode(h);
                            h = h->next; //set next node as new head
                            last->next = h;//set next of last node to refer to new head
                            free(p);
                        }
                    }
                    else
                    {//an intermediate or tail node to be deleted
                        q->next = p->next; //connection reset
                        free(p);
                    }
                }
                
                flag = 1;
                break;
            }
            else
            {//traverse
                q = p;//shadow pointer
                p = p->next;
            }
        }while(p != h);
      
        if(flag == 0)
        {//connection not done yet
         //new node exponent is smallest
         //connect as tail
            q->next = n;//connect as tail
            n->next = h;//make it circular
        }
    }//else
    return h;
}  


node * create()
{
    node * h;
    int ch;
    float c;
    int e;
    
    h = NULL;//important initialization
    do
    {
        printf("\n Enter coeff : ");
        scanf("%f", &c);
        printf("\n Enter exponent : ");
        scanf("%d", &e);
        
        h = insertNode(h, c, e);
        
        printf("\n Add more nodes (1 is yes) ");
        scanf("%d", &ch);
        
    }while(ch == 1);
    return h;
}
  
void display(node *h)
{
    node *p;
    printf("\n");
    
    p = h;//begin with the head
    
    do
    {
        if(p != h && p->c > 0)
            printf(" + ");
        
        printf(" %.2fx^%d", p->c, p->e);
        p = p->next;
        
    }while(p != h);//stop at head node
    
}//display

int count(node *h)
{
    int cnt = 0;
    node *p;
    
    if(h == NULL)
        return 0;
    
    
    p = h;//begin with the head
    do
    {
        cnt++;
        p = p->next;
    }while(p != h);//stop at head node
    
    return cnt;
}//count


node * multiply(node *h1, node *h2)
{
    node *h3;
    node *i, *j;
    float c;
    int e;
    
    h3 = NULL;//important initialization
    
    if(h1 == NULL || h2 == NULL)
        return h3;
    
    i = h1;
    do
    {//terms of h1
        j = h2;
        do
        {//terms of h2
            c = i->c * j->c;
            e = i->e + j->e;
            
            h3 = insertNode(h3, c, e);
            j = j->next;
        }while(j != h2);
        
        i  = i->next;
    }while(i != h1);
    return h3;
}

node* add(node * h1, node *h2)
{
    node *h3;
    node *i, *j;
    float c;
    int e;
 
    //loop control
    int s1, s2;
    int pos1, pos2;
    
    h3 = NULL;
    i = h1;
    j = h2;
    
    s1 = count(h1);
    s2 = count(h2);
    pos1 = 0;
    pos2 = 0;
    
    while(pos1 <s1 && pos2 < s2)
    {
        if(i->e > j->e )
        {//select i to go into result
            c = i->c;
            e = i->e;
            i = i->next; //traverse
            pos1++;
        }
        else if(j->e > i->e )
        {//select j to go into result
            c = j->c;
            e = j->e;
            j = j->next; //traverse
            pos2++;
        }
        else if(i->e == j->e )
        {//select addition of i and j to go into result
            c = i->c + j->c;
            e = i->e;
            i = i->next; //traverse
            j = j->next; //traverse
            pos1++;
            pos2++;
        }
        
        h3 = insertNode(h3, c,e);
    }
    //there may be terms remaining in h1 or in h2
    
    while(pos1 < s1)
    {//remaining terms of i
        c = i->c;
        e = i->e;
        i = i->next;
        pos1++;
        h3 = insertNode(h3,c, e);
    }
    
    while(pos2 < s2)
    {//remaining terms of j
        c = j->c;
        e = j->e;
        j = j->next;
        pos2++;
        h3 = insertNode(h3,c, e);
    }
    
    return h3;
}//add

float eval(node * h)
{
    float ans;
    float x;
    node *p;
    
    ans = 0;
    printf("\n Enter the value of x ");
    scanf("%f", &x);
   
    if(h == NULL)
        return ans;
    
    p = h;
    do
    {
        ans = ans + p->c * pow(x, p->e);
        p = p->next;
        
    }while(p != h);
    return ans;
}


int main()
{
    node * p1, *p2, *p3;
    float ans;
    
    printf("\n Create first polynomial ");
    p1 = create();
    
    printf("\n Create second polynomial ");
    p2 = create();

    display(p1);
    display(p2);

    p3 = multiply(p1,p2);
    printf("\n Multiplication ");
    display(p3);
    ans = eval(p3);
    printf("\n Evaluation : %f  ", ans);
    
    p3 = add(p1,p2);
    printf("\n Addition ");
    display(p3);
    ans = eval(p3);
    printf("\n Evaluation : %f  ", ans);
    
    return 0;
}

