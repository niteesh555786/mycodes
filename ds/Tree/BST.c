//Implementing : Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node * left;
    int data;
    struct node * right;
};
typedef struct node node;

struct stknode
{
    node * data;
    struct stknode * next;
};
typedef struct stknode stknode;


struct Stack
{
    stknode * top;//indicator
};
typedef struct Stack Stack;

//clears the garbage in the top of the Stack
void init(Stack *p)
{
    p->top = NULL;
}

//adds a value into the Stack
void push(Stack *p, node* val)
{
    stknode *n;
    n = (stknode*) malloc(sizeof(stknode));

    //init
    n->data = val;
    n->next = p->top;//new node on top of existing 
    p->top = n;//new node set as topmost node
    
}//push

int isEmpty(Stack *p)
{
    return p->top == NULL;
}

node* pop(Stack *p)
{
    stknode * n;
    node* val = NULL;
    
    if(! isEmpty(p))
    {
        n = p->top;//grab the top most node
        p->top = n->next;//reset the top to underlying node
        val = n->data;//fetch the node data
        free(n);//remove the node
    }
    
    return val;
}

node * createBST()
{
    node * root;
    node *n, *p;
    int flag;
    
    char ch;
    
    root = NULL;//important initialization
            
    do
    {
        //create a node
        n = (node*) malloc(sizeof(node));
        
        //initialize it
        printf("\n Enter data for node ");
        scanf("%d", &n->data);
        n->left = NULL;
        n->right = NULL;
        
        //connect
        if(root == NULL)
        {//first node
            root = n;
        }
        else
        {//successor node
            flag = 1;
            p = root;
        
            while(flag == 1)
            {
                if(n->data < p->data)
                {//left
                    if(p->left == NULL)
                    {//left of p is not occupied
                        p->left = n;//connect as left of p
                        flag = 0;
                    }
                    else
                    {//left of p is occupied
                        p = p->left;//traverse
                    }
                }
                else
                {//right
                    if(p->right == NULL)
                    {
                        p->right = n;//connect as right child
                        flag = 0;
                    }
                    else
                    {
                        p = p->right;//traverse
                    }
                }
            }//while
        }//else
        
        printf("\n Continue ? (y/n) ");
        fflush(stdin);
        scanf("%c", &ch);
    }while(ch == 'y' || ch == 'Y');
    
    return root;
}//create

//Also called as "Depth First Search"
void preorder(node * root)
{//movement in the order : DLR 

    node *p;
    Stack s;
    
    if(root == NULL)
        return;//terminate
    
    init(&s);
    
    p = root; //traversal begins with the root
    
    do //to traverse all nodes
    {
        while(p != NULL)
        {
            printf(" %d ", p->data);
            push(&s, p);
            p= p->left;
        }
        //p is NULL now, i.e. there was no left or no right
        //backtrack for right traversal
        p = pop(&s);
        
        p = p->right;
        
    }while(p != NULL || ! isEmpty(&s));//loop
    
}//preorder

void inorder(node * root)
{//movement in the order : LDR 

    node *p;
    Stack s; 
    
    if(root == NULL)
        return;//terminate
    
    init(&s);

    p = root;//traversal begins with the root
    
    do//to traverse all the nodes
    {
        while(p != NULL)
        {
            push(&s, p);
            p = p->left;
        }
        //p is NULL now, i.e. there was no left or no right
        //backtrack for data and right traversal
        p = pop(&s);
        
        printf(" %d ", p->data);
        
        p = p->right;
        
    }while(p != NULL || ! isEmpty(&s));
    
}

void postorder(node * root)
{//movement in the order : LRD 
    node *p;
    node * processed;
    Stack s;

    if(root == NULL)
        return;//terminate
    
    init(&s);
    p = root;//traversal begins with the root
    processed = NULL;
    
    do//to traverse all the nodes
    {
        while(p != NULL)
        {
            push(&s, p);
            p = p->left;
        }
        //p is NULL now, i.e. there was no left or no right
        //backtrack for right traversal and data 
        p = pop(&s);
        
        //test right
        if(p->right != NULL && p->right != processed)
        {
            push(&s, p);
            p = p->right;
        }
        else
        {//no right or processed right 
            printf(" %d ", p->data);
            processed = p;
            p = NULL; //to ensure backtracking
        }
        
    }while(p != NULL || ! isEmpty(&s));
    
}

void rPreorder(node * root)
{//DLR
    if(root != NULL)
    {
        printf(" %d ", root->data); //D
        rPreorder(root->left);//L
        rPreorder(root->right);//R
    }
}//rPreorder

void rInorder(node * root)
{//LDR
    if(root != NULL)
    {
        rInorder(root->left);//L
        printf(" %d ", root->data); //D
        rInorder(root->right);//R
    }
}//rInorder

void rPostorder(node * root)
{//LRD
    if(root != NULL)
    {
        rPostorder(root->left);//L
        rPostorder(root->right);//R
        printf(" %d ", root->data); //D
    }
}//rPostorder
//Binary Search
node * search(node * root, int val)
{
    node *p;
    p = root;//comparison begins from root
    while(p != NULL)
    {
        if(val == p->data )
        {//found
            return p;//location of node where data matched
        }
        else if(val < p->data)
        {//lesser values on left
            p = p->left;
        }
        else if(val > p->data)
        {//greater values on right
            p = p->right;
        }
    }//while
    return NULL; //not found
}

//Search Parent
node * searchParent(node * root, int val)
{
    node *p, *q;
    p = root;//comparison begin from root
    q = NULL;
    
    while(p != NULL)
    {
        if(val == p->data)
        {//found
            return q;//location of parent node 
        }
        else if(val < p->data)
        {//lesser values on left
            q = p;
            p = p->left;
        }
        else if(val > p->data)
        {//greater values on right
            q = p;
            p = p->right;
        }
    }//while
    return NULL; //not found
}


node * deleteNode(node * root)
{
    int val;
    node * parent;
    node * child;
    node * temp;
    node * inorderS;
    
    printf("\n Enter the value of node to be deleted ");
    scanf("%d", &val);
    
    parent = searchParent(root, val);
    
    if(parent == NULL)
    {//case 1: val not found
        if(val != root->data)
        {
            printf("\n %d not found in BST ", val);
        }
        //case 2 : val is root
        else if(val == root->data)
        { //root node to be deleted
            if(root->left == NULL && root->right == NULL)
            {//root is leaf 
                free(root);
                return NULL;// tree not created indicator
            }    
            else if(root->left ==NULL && root->right != NULL)
            {//root has right child
                temp = root;
                root = root->right;
                free(temp);
            }
            else if(root->left !=NULL && root->right == NULL)
            {//root has left child
                temp = root;
                root = root->left;
                free(temp);
            }
            else if(root->left != NULL && root->right != NULL)
            {   //root has both the childs : Inorder successor will take its place
                //take one right
                inorderS = root->right;
                
                //max left
                temp = NULL;
                while(inorderS->left != NULL)
                {
                    temp = inorderS;
                    inorderS = inorderS->left;
                }
                
                if(temp == NULL)
                {//direct right is the inorder successor
                    //take care of left child of child
                    inorderS->left = root->left;
                    
                    //take care of root
                    temp = root;
                    root = inorderS;
                    //delete root
                    free(temp);
                }
                else
                {//inorder successor is one right and max left
                    //take care of inorderS->right
                    temp->left = inorderS->right;

                    //take care of childs of child
                    inorderS->left = child->left;
                    inorderS->right = child->right;

                    //take care of root
                    temp = root;
                    root = inorderS;
                    //delete root
                    free(temp);
                }
            }
        }
    }
    else if(parent != NULL)
    {
        if(parent->left != NULL)
        {
            if(parent->left->data == val)
            {
                child = parent->left;
                if(child->left == NULL && child->right == NULL)
                {//child is a leaf node
                    parent->left = NULL;
                    free(child);
                }    
                else if(child->left == NULL && child->right != NULL)
                {//child has right child
                    parent->left = child->right;
                    free(child);
                }
                else if(child->left != NULL && child->right == NULL)
                {//child has left child
                    parent->left = child->left;
                    free(child);
                }
                else if(child->left != NULL && child ->right != NULL)
                {//child has both the childs : Inorder successor will take its place
                    //take one right
                    inorderS = child->right;

                    //max left
                    temp = NULL;
                    while(inorderS->left != NULL)
                    {
                        temp = inorderS;
                        inorderS = inorderS->left;
                    }

                    if(temp == NULL)
                    {//direct right is the inorder successor
                        //take care of left child of child
                        inorderS->left = child->left;

                        //take care of parent of child
                        parent->left = inorderS;
                        //delete child
                        free(child);
                    }
                    else
                    {//inorder successor is one right and max left
                        //take care of inorderS->right
                        temp->left = inorderS->right;

                        //take care of childs of child
                        inorderS->left = child->left;
                        inorderS->right = child->right;

                        //take care of parent of child
                        parent->left = inorderS;
                        //delete child
                        free(child);
                    }

                }
            }
        }
        else if(parent->right != NULL)
        {
            if(parent->right->data == val)
            {
                child = parent->right;
                if(child->left == NULL && child->right == NULL)
                {//child is a leaf node
                    free(child);
                    parent->right = NULL;
                }
                else if(child->left == NULL && child->right != NULL)
                {//child has right child
                    parent->right = child->right;
                    free(child);
                }
                else if(child->left != NULL && child->right == NULL)
                {//child has left child
                    parent->right = child->left;
                    free(child);
                }
                else if(child->left != NULL && child ->right != NULL)
                {//child has both the childs : Inorder successor will take its place
                    //take one right
                    inorderS = child->right;

                    //max left
                    temp = NULL;
                    while(inorderS->left != NULL)
                    {
                        temp = inorderS;
                        inorderS = inorderS->left;
                    }

                    if(temp == NULL)
                    {//direct right is the inorder successor
                        //take care of left child of child
                        inorderS->left = child->left;

                        //take care of parent of child
                        parent->right = inorderS;

                        //delete child
                        free(child);
                    }
                    else
                    {//inorder successor is one right and max left
                        //take care of inorderS->right
                        temp->left = inorderS->right;

                        //take care of childs of child
                        inorderS->left = child->left;
                        inorderS->right = child->right;

                        //take care of parent of child
                        parent->right = inorderS;
                        //delete child
                        free(child);
                    }
                }
            }
        }
    }
    return root; 

}//deleteNode

node * insertNode(node * root)
{
    node *n, *p;
    int flag;
    
    //create a node
    n = (node*) malloc(sizeof(node));
        
    //initialize it
    printf("\n Enter data for node ");
    scanf("%d", &n->data);
    n->left = NULL;
    n->right = NULL;
        
    //connect
    if(root == NULL)
    {//first node
        root = n;
    }
    else
    {//successor node
        flag = 1;
        p = root;

        while(flag == 1)
        {
            if(n->data < p->data)
            {//left
                if(p->left == NULL)
                {//left of p is not occupied
                    p->left = n;//connect as left of p
                    flag = 0;
                }
                else
                {//left of p is occupied
                    p = p->left;//traverse
                }
            }
            else
            {//right
                if(p->right == NULL)
                {
                    p->right = n;//connect as right child
                    flag = 0;
                }
                else
                {
                    p = p->right;//traverse
                }
            }
        }//while
    }//else
    
    return root;
}//insertNode


int main()
{
    int ch,x , flag;
    node * root, *temp;
    root = NULL;

    flag = 1;
    do
    {
        printf("\n 1. create BST");
        printf("\n 2. Preorder Recursive");
        printf("\n 3. Inorder Recursive");
        printf("\n 4. Postorder Recursive");
        printf("\n 5. Preorder NonRecursive");
        printf("\n 6. Inorder NonRecursive");
        printf("\n 7. Postorder NonRecursive");
        printf("\n 8. Search");
        printf("\n 9. Delete Node");
        printf("\n 10. Insert Node");
        printf("\n 11. Exit");
        printf("\n Enter Choice ");
        scanf("%d", &ch);
    
        switch(ch)
        {
            case 1:
                root = createBST();
                printf("\n Tree Created");
                break;
            case 2:
                printf("\n Recursive PreOrder : ");
                rPreorder(root);
                break;
            case 3:
                printf("\n Recursive InOrder : ");
                rInorder(root);
                break;
            case 4:
                printf("\n Recursive PostOrder : ");
                rPostorder(root);
                break;
            case 5:
                printf("\n NonRecursive PreOrder : ");
                preorder(root);
                break;
            case 6:
                printf("\n NonRecursive InOrder : ");
                inorder(root);
                break;
            case 7:
                printf("\n NonRecursive PostOrder : ");
                postorder(root);               
                break;
            case 8:
                printf("\n Enter value to search in BST ");
                scanf("%d", &x);
                temp = search(root, x);
                if(temp != NULL)
                    printf("\n %d found ", x);
                else
                    printf("\n %d not found ", x);
                break;
                
            case 9:
                root = deleteNode(root);
                
                break;
            case 10:
                root = insertNode(root);
                break;
            case 11://exit
                flag = 0;
                break;
            default:
                printf("\n Wrong Choice ");
                break;
        }
        
    }while(flag != 0);
 
    
    return 0;
}//main

