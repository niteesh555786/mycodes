void bfs(node * root)
{
	Queue q;
	node * p;

	initq(&q);
	p = root;
	addq(&q,p);

	while(p != NULL)
	{
		printf(" %d  ", p->data);
		if(p->left != NULL)
			addq(&q, p->left);
		if(p->right != NULL)
			addq(&q, p->right);

		p = delq(&q);
		if(p == root)//separator
		{
			printf("\n");
			p = delq(&q);
			if(p != NULL)
				addq(&q,root);
		}
	}
}
