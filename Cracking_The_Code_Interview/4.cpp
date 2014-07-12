#include <iostream>
#include <cstdio>
using namespace std;
#include "list.h"
void swap (node* head, int i, int j)
{
	int k1 = 0;
	int k2 = 0;
	node *p, *q;
	p = q = head;
	while (k1 < i)
	{
		k1++;
		p = p->next;
	}
	while (k2 < j)
	{
		k2++;
		q = q->next;
	}
	int temp = p->data;
	p->data = q->data;
	q->data = temp;
}
int findPos (node* head, int x)
{
	node *p, *q;
	p = head;
	int i = 0;
	while (p->next != NULL)
	{
		if (p->data == x)
			return i;
		i++;
		p = p->next;
	}
	return -1;
}
void partition (node* head, int x)
{
	int pos = findPos (head, x);
	if (pos == -1)
	{
		printf ("Element not found\n");
		return;
	}
	swap (head, 0, pos);
	node *p, *q;
	p = q = head;
	q = p->next;
	int val = p->data;
	int i = 0, j = 1;
	while (q->next != NULL)
	{
		if (q->data < val)
		{
			p = p->next;
			i++;
			swap (head, i, j);
		}
		j++;
		q = q->next;
	}
	swap (head, 0, i);
}
int main()
{
	int n;
	scanf ("%d",&n);
	node* head = NULL;
	while (n--)
	{
		int val;
		scanf ("%d",&val);
		head = createList (val, head);
	}
	int x;
	scanf ("%d",&x);
	partition (head, x);
	showList (head);
}
