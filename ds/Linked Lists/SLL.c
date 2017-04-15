//Operations on : SLL
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};
typedef struct node node;

//create a linked list
node * create()
{
    char ch;
    node * head, *n, *linker;
    int x;
    
    head = NULL;//imp initialization
    
    do
    {
        //create a node
        n = (node*) malloc(sizeof(node));
        if(n != NULL) //node created
        {
            //initialize
            printf("\n Enter data for node ");
            scanf("%d", &x);
            n->data= x;
            n->next = NULL;

            //connect
            if(head == NULL) 
            {//as first node
                head = n;
                linker = n;
            }
            else
            {//as successor node
                linker->next = n;
                linker = n;
            }
        }
        else
            printf("\n node creation failed ");
        //cycle
        printf("\n Continue ? ");
        fflush(stdin);
        scanf("%c", &ch);
    }while(ch == 'y' || ch == 'Y');
    //return
    return head;
}//create


void display(node *h)
{
    node *p; //for traversal
    if(h != NULL)
    {
        printf("\n");
        p = h;
        
        while(p != NULL)
        {
            printf(" %d ", p->data); //process
            p = p->next;//traversal
        }
        
    }
    else
        printf("\n Empty List");
  
}

int count(node *h)
{
    int cnt = 0;
    node *p; //for traversal
    if(h != NULL)
    {
        p = h;
        while(p != NULL)
        {
            cnt++;
            p = p->next;//traversal
        }
    }
    return cnt;
}

void reverseDisplay(node *h)
{
    node *p;
    int tot, i, j;
    
    if(h != NULL)
    {
        printf("\n");
        tot = count(h);

        for(i =1; i<=tot ; i++)//all nodes
        {
            p = h;
            for(j = 0; j< tot-i; j++)
            {
                p =p->next;
            }
            printf(" %d ", p->data);
        }//for(i..
        
    }
    else
        printf("\n Empty List");
}//reverseDisplay

node * insert(node * h)
{
    int tot, pos, x, i;
    node *n, *o, *p;
    tot = count(h);
    printf("\n Enter position of new node ");
    scanf("%d", &pos);

    //validate the position
    if(pos < 1 || pos > tot +1)
    {
        printf("\n Invalid Position For List of size : %d ", tot);
    }
    else
    {//we have a valid position for the node

     //create a node
        n = (node*) malloc(sizeof(node));   
     //initialize it 
        printf("\n Enter data for new node ");
        scanf("%d", &x);
        n->data = x;
        n->next = NULL;
     //connect
        
        if(pos == 1)//new node will be the head node
        {
            n->next = h; //connect with existing head
            h = n;//set as new head
        }
        else//rest of the positions (intermediate and tail)
        {
            p = h;
            for(i = 1; i< pos; i++)
            {
                o = p;
                p =p->next;
            }
            //now o is at node : pos -1
            //and p is at node : pos or is NULL
            o->next = n;
            n->next = p;
        }
    }//else
    return h;
}//insert


node * deleteNode(node * h)
{
    int tot, pos,  i;
    node *o, *p;

    tot = count(h);
    printf("\n Enter position of node to be deleted ");
    scanf("%d", &pos);

    //validate the position
    if(pos < 1 || pos > tot)
    {
        printf("\n Invalid Position For List of size : %d ", tot);
    }
    else
    {//we have a valid position for the node
        if(pos == 1)//head node to be deleted
        {
            p = h;//shadow
            h = h->next;//let next node be the head
            //clear the old head node
            free(p);
        }
        else//rest of the positions (intermediate and tail)
        {
            p = h;
            for(i = 1; i< pos; i++)
            {
                o = p;
                p =p->next;
            }
            //now o is at node : pos -1
            //and p is at node : pos 
            o->next = p->next;
            free(p);
        }
    }//else
    return h;
}//delete

node * reverseList(node *h)
{
    node *p, *q, *r;
    
    if(h == NULL)
        return h;
    
    p = h;
    q = NULL;
    r = NULL;
    
    while(p != NULL)
    {
        q = p;//q is shadow to p
        p = p->next;//preserve rest of the list
        q->next = r;//reversal
        r = q;//r is shadow to q
    }//while
    
    return q;//new head node
}

node * search(node *h, int val)
{//sequential search, as the data structure is sequential in design

    node *p;
    
    if(h == NULL)
        return NULL; //not found
    
    p = h; //begin from the first node
    while(p != NULL) //go upto the end of the list
    {
        if(p->data == val) //comparison
        {//found a match
            return p;//address of node where data matches
        }
        p = p->next; //sequential movement
    }//while
    
    return NULL;//not found
}

node * freeList(node * h)
{
    node *p;
    if(h == NULL)
        return NULL;
    
    while(h != NULL)
    {
        p = h;
        h = h->next;
        free(p);
                
    }
    return h;
}

int main() 
{
    int x, ch;
    node * head= NULL;
    node * p;
    
    do
    {
        printf("\n 1. Create Linked List  ");
        printf("\n 2. Display Linked List  ");
        printf("\n 3. Reverse Display Linked List  ");
        printf("\n 4. Insert a node in the Linked List  ");
        printf("\n 5. Delete a node from the Linked List  ");
        printf("\n 6. Search a value in the Linked List  ");
        printf("\n 7. Reverse the Linked List  ");
        printf("\n 8. Count the nodes in Linked List  ");
        printf("\n 9. Exit ");
        
        printf("\n Enter choice ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1://create
                head = create();
                break;
            case 2://display
                display(head);
                break;
            case 3://reverse display
                reverseDisplay(head);
                break;
            case 4://insert
                head = insert(head);
                break;
            case 5://delete node
                head = deleteNode(head);
                break;
            case 6: //search
                printf("\n Enter value to search ");
                scanf("%d", &x);
                p = search(head, x);
                if(p != NULL)
                    printf("\n %d found @ address %x ", x, p);
                else
                    printf("\n %d not found ");
                break;
            case 7://reverse
                head = reverseList(head);
                break;
            case 8://count
                x = count(head);
                printf("\n Number of nodes in linked list : %d ", x);
                break;
            case 9:
                head = freeList(head);
                break;
        }
    }while(ch != 9);
    
    return 0;
}

