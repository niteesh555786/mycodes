/*
create a 3rd list by merging first and
second sorted lists
The third list should be auto sorted.

*/

node * appendNode(node * h, int val)
{
	node *n, *p;
	n = (node *)malloc(sizeof(node));

	n->data = val;
	n->next = NULL;

	if(h == NULL)
	{
		h = n;
	}
	else
	{ //set p at last node
		p = h;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = n;
	}
	return h;
}


node * merge(node *h1, node *h2)
{
	node *h3, *t1, *t2;

	t1 = h1;
	t2 = h2;

	h3 = NULL;

	while(t1 != NULL && t2 != NULL)
	{
		if(t1->data <= t2->data)//merge t1->data
		{
			h3 = appendNode(h3, t1->data);
			t1 = t1->next;
		}
		else//merge t2->data
		{
			h3 = appendNode(h3, t2->data);
			t2 = t2->next;
		}
	}

	//for remaining nodes
	while(t1 != NULL)
	{
		h3 = appendNode(h3, t1->data);
		t1 = t1->next;
	}

	while(t2 != NULL)
	{
		h3 = appendNode(h3, t2->data);
		t2 = t2->next;
	}
	return h3;
}

