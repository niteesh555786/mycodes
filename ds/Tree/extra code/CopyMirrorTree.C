	node * mirror(node * root)
	{
		node *root1, *p, *p1, *n;
		Stack s, s1;
		char flag = 'r';
		root1 = NULL;

		if(root == NULL)
			return NULL;

		p = root;
		init(&s);
		init(&s1);

		do
		{
			while(p != NULL)
			{

				n =(node*)malloc(sizeof(node));
				n->data  = p->data;
				n->left = NULL;
				n->right = NULL;


				if(root1 == NULL)
				{
					root1 = n;
					p1 = n;
				}
				else if(flag == 'r')
				{
					p1->right= n;
					p1= n;
				}
				else if(flag == 'l')
				{
					p1->left= n;
					p1= n;

				}

				push(&s1, p1);
				push(&s, p);
				p = p->left;
				flag = 'r';

			}
			p1 = pop(&s1);
			p = pop(&s);

			p = p->right;
			if(p != NULL)//right child exists
			{
				flag = 'l';
			}


		}while(p != NULL || ! isempty(&s));
		return root1;


	}


	node * copy(node * root)
	{
		node *root1 , *p, *p1, *n;
		Stack s, s1;
		char flag = 'l';

		root1 = NULL;
		if(root == NULL)
			return NULL;

		p = root;
		init(&s);
		init(&s1);

		do
		{
			while(p != NULL)
			{

				n =(node*)malloc(sizeof(node));
				n->data  = p->data;
				n->left = NULL;
				n->right = NULL;


				if(root1 == NULL)
				{
					root1 = n;
					p1 = n;
				}
				else if(flag == 'r')
				{
					p1->right= n;
					p1= n;
				}
				else if(flag == 'l')
				{
					p1->left= n;
					p1= n;

				}

				push(&s1, p1);
				push(&s, p);
				p = p->left;
				flag = 'l';

			}
			p1 = pop(&s1);
			p = pop(&s);

			p = p->right;
			if(p != NULL)//right child exists
			{
				flag = 'r';
			}


		}while(p != NULL || ! isempty(&s));
		return root1;


	}