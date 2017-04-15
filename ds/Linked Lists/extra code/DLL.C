#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*
A doubly linked list is a linear data structure.
Elements (nodes) of a doubly linked list are 
connected in such away that every node stores 
address of its predessor and successor.

*/

struct node
{
	struct node * prev;//to point to predessor
	int data; //to hold data
	struct node * next; //to point to successor
};
typedef struct node node;

node * create()
{
	node *h, *n, *p;
	char ch;
	h = NULL;

	do
	{
		//memory allocation
		n = (node*) malloc(sizeof(node));

		//initialization
		printf("\n enter data for node ");
		scanf("%d", &n->data);
		n->prev = NULL;
		n->next = NULL;

		//connection
		if(h == NULL)
		{
			h = n;
			p = n;
		}
		else
		{
			p->next = n;
			n->prev = p;
			p = n;
		}


		printf("\n continue ? ");
		fflush(stdin);
		scanf("%c", &ch);
	}while(ch == 'y');

	return h;
}

void disp(node * h)
{
	node * p;
	printf("\n");

	for(p = h; p!= NULL; p = p->next)
	{
		printf("  %d", p->data);
	}

}

void revdisp(node * h)
{
	node * p;
	printf("\n");

	//position p at last node
	p = h;
	while(p->next != NULL)
	{
		p = p->next;
	}

	//move rev and disp all nodes
	while(p != NULL)
	{
		printf("  %d", p->data);
		p = p->prev;//dont forget
	}

}
void main()
{
	node *head;
	clrscr();
	head = create();
	disp(head);
	revdisp(head);

}