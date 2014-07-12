struct node
{
	int data;
	node* next;
};
node *p;
node* createList (int n, node* head)
{
	if (head == NULL)
	{
		head = new node;
		p = head;
		p->data = n;
		p->next = NULL;
	}
	else
	{
		node *q;
		q = new node;
		q->data = n;
		q->next = NULL;
		p->next = q;
		p = p->next;
	}
	return head;
}
void showList (node* head)
{
	node *p;
	p = head;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n";
}
void removeNode (node* head, int pos)
{
	node* p;
	p = head;
	int i = 0;
	while (i < pos-1)
	{
		i++;
		p = p->next;
	}
	node *q;
	//cout <<"node before " << i << "\n";
	q = p->next;
	p->next = q->next;
	delete q;
}
