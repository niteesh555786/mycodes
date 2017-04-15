//Stack Using Linked List
#include <stdio.h>
#include <stdlib.h>

//Because it is a linked list so define a node
struct node
{
    int data;
    struct node * next;
};
typedef struct node node;


struct Stack
{
    node * top;//indicator
};
typedef struct Stack Stack;

//clears the garbage in the top of the Stack
void init(Stack *p)
{
    p->top = NULL;
}

//adds a value into the Stack
void push(Stack *p, int val)
{
//linked list stores its data in nodes
//create a node
    node *n;
    n = (node*) malloc(sizeof(node));

    if(n != NULL)//isFull Check
    {
    //init the node    
        n->data = val;
        n->next = p->top;//new node on top of existing 
        p->top = n;//new node set as topmost node
    }
    else
        printf("\n Stack Overflow");
}//push

int isEmpty(Stack *p)
{
    return p->top == NULL;
}

void display(Stack *p)
{
    node *n;
    if(! isEmpty(p))
    {
        n = p->top;
        while(n != NULL)
        {   
            printf("\n %d ", n->data);
            n = n->next;
        }
        
    }
    else
        printf("\n Stack is Empty");
}

int pop(Stack *p)
{
    node * n;
    int val = 0;
    //data is in nodes
    //to remove data means to remove a node
    //data is removed from the top
    
    if(! isEmpty(p))
    {
        n = p->top;//grab the top most node
        p->top = n->next;//reset the top to underlying node
        val = n->data;//fetch the node data
        free(n);//remove the node
    }
    else
        printf("\n Stack Underflow");
    return val;
}

int peek(Stack *p)
{
    if(! isEmpty(p))
        return p->top->data;
    else
    {
        printf("\n Stack Underflow");
        return 0;
    }
}//peek


int main()
{
    int x, ch, flag;
    Stack s;

    init(&s);
    flag = 1;
    do
    {

        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Peek");
        printf("\n 4. Display");
        printf("\n 5. Exit ");
        printf("\n Enter Choice  ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: //push
                printf("\n Enter a value to push in Stack ");
                scanf("%d", &x);
                push(&s, x);
                break;

            case 2: //pop
                x = pop(&s);
                printf("\n %d removed from Stack ",x);
                break;
            case 3: //peek
                x = peek(&s);
                printf("\n %d is at top of Stack ",x);
                break;
            case 4: //display
                display(&s);
                break;
            case 5:
                flag = 0;
                break;
            default :
                printf("\n Invalid Choice ");
                break;
        }

    }while(flag == 1);


    return 0;
}

