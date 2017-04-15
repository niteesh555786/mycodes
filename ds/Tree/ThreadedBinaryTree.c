//Binary Threaded Tree

#include<stdio.h>
#include<stdlib.h>
#define SIZE 30

struct node
{
    struct node * left;
    char lThread;
    int data;
    struct node * right;
    char rThread;
};

typedef struct node node;

node * createHead()
{
    node * n;
    
    //create
    n = (node*) malloc(sizeof(node));
    
    //initialize
    n->data = 999;//LARGE VALUE
    n->left = n;
    n->lThread = 'y';
    n->right = n;
    n->rThread = 'y';
    
    return n;
}

node * createTBT()
{
    node * head;
    node *n;
    node *p;
    int flag;
    char ch;
    
	    
    head = createHead();
    
    do
    {
        //create a node
        n = (node*) malloc(sizeof(node));
        
        //scan data for it
        printf("\n enter data for node ");
        scanf("%d", &n->data);
        
        //connect
        if(head->left == head)
        {//connect as root

            //set the left of n
            n->left = head->left;
            n->lThread = 'y';
            
            //connect head and n
            head->left = n;
            head->lThread = 'n';
            
            //set the right of n;
            n->right = head->right;
            n->rThread = 'y';
        }
        else
        {//connect as successor

            p = head->left;//root
            flag = 1; //loop control
            
            while(flag == 1)
            {
                printf("\n l : connect to left of %d ", p->data);
                printf("\n r : connect to right of %d ", p->data);
                printf("\n enter choice ");
                fflush(stdin);
                scanf("%c", &ch);
                
                if(ch == 'l' || ch == 'L')
                {//left

                    if(p->lThread == 'y')
                    {//no child on left, connect
        
                        //set the left of n
                        n->left = p->left;
                        n->lThread = 'y';
                        
                        //connect p and n
                        p->left = n;
                        p->lThread = 'n';
                        
                        //set the right of n
                        n->right = p;
                        n->rThread = 'y';
                                
                        flag = 0;
                        
                    }
                    else//traverse
                        p = p->left;
                }
                else if(ch == 'r' || ch == 'R')
                {//right

                    if(p->rThread == 'y')
                    {//no child on right, connect
                    
                        //set the right of n
                        n->right = p->right;
                        n->rThread = 'y';
                        
                        //connect p and n
                        p->right = n;
                        p->rThread = 'n';
                        
                        //set the left of n
                        n->left = p;
                        n->lThread = 'y';
                        
                        flag = 0;
                    }
                    else //traverse
                        p = p->right;
                    
                }
            }//while
        }//else
        
        //cycle
        printf("\n add more nodes (y/n) ? ");
        fflush(stdin);
        scanf("%c", &ch);
    }while(ch == 'y' || ch == 'Y');
    
    return head;
}

void inOrder(node * head)
{//LDR
    node * p;
    int flag;
    
    if(head == NULL )
    {
        printf("\n Tree is not created ");
        return;
    }
    
    p = head->left; //root
    flag = 0;
    
    do //to visit all the node
    {
        while(p->lThread == 'n' && flag == 0)
        {//p has left child
            p = p->left;
        }
        
        //data
        printf(" %d ", p->data);
        
        //right
        if(p->rThread == 'n')
        {//right is a child
            flag = 0;
            p = p->right;   
        }
        else
        {//right is a thread
            flag = 1;
            p = p->right;
        }
    }while(p != head);//loop
}

void preOrder(node * head)
{//DLR
    node * p;
    int flag;
    
    if(head == NULL)
    {
        printf("\n Tree is not created ");
        return;
    }
    
    p = head->left; //root
    flag = 0;
    
    do //to visit all the node
    {
        while(p->lThread == 'n' && flag == 0)
        {
            printf(" %d ", p->data); //D
            p = p->left;//L
        }
        
        if(flag == 0)
        {
            printf(" %d ", p->data); //D
        }
        
        if(p->rThread == 'n')
        {//right is a child
            flag = 0;
            p = p->right;
        }
        else
        {
            flag = 1;
            p = p->right;
        }
    }while(p != head);//loop

}

int isProcessed(node * arr[], int s, node * p)
{//sequential search
    
    int i;
    for(i =0; i< s; i++)
    {
        if(arr[i] == p)
            return 1;//found, hence isProcessed TRUE
    }//for
    return 0; //not found, hence isProcessed FALSE
}

void postOrder(node * head)
{//LRD
    node * p;
    node * processed[SIZE];
    int indx = 0;
    
    if(head == NULL)
    {
        printf("\n Tree is not created ");
        return;
    }
    
    p = head->left; //root
    
    do//to visit all the node
    {
        while(p->lThread == 'n' && ! isProcessed(processed, indx, p->left))
        {//p has left child that is not processed
            p = p->left; //L
        }
        
        if(p->rThread == 'y' || isProcessed(processed, indx, p->right))
        {//p has not right child or processed right child
        
            //data
            printf(" %d ", p->data);
            processed[indx] =p;
            indx++;
            
            //follow a thread or a child
            do
            {
               p = p->right;
            }while(isProcessed(processed, indx, p));
        }
        else
        {// p has a right child
            p = p->right;
        }
    }while( ! isProcessed(processed, indx, head->left) );//loop
}



int main()
{
    node * head;
    head = createTBT();
    
    printf("\n Preorder : ");
    preOrder(head);
    
    printf("\n Inorder : ");
    inOrder(head);
    
    printf("\n Postorder : ");
    postOrder(head);
    return 0;
}
