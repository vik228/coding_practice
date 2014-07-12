#include <iostream>
#include <cstdio>
#include "List.h"
void getLoopNode (List& l1)
{
	Node *p, *q;
	p = q = l1.getHead();
	p = p->getNext();
	p = p->getNext();
	int t = 3;
	while (t--)
	{
		q = q->getNext();
	}
	//cout << p->get() << " " << q->get() << "\n";
	Node* lp;
	int i = 2, j = 3;
	bool flag = false;
	while (p != q)
	{
		p = p->getNext();
		i++;
		int a = 2;
		while (a--)
		{
			q = q->getNext();
			j += 1;
		}
	}
	p = l1.getHead();
	p = p->getNext();
	if (p == q)
		cout << p->get() << "\n";
	while (q != p)
	{
		p = p->getNext();
		q = q->getNext();
	}
	cout << p->get() << "\n";
}
int main()
{
	int N;
	scanf ("%d",&N);
	List l1;
	for (int i = 0; i < N; i++)
	{
		int val;
		scanf ("%d",&val);
		l1.add (val);
	}
	int pos;
	scanf ("%d",&pos);
	l1.setLastNext (pos);
	Node* p1 = l1.getCurrentNode();
	p1 = p1->getNext();
	cout << p1->get() << "\n";
	getLoopNode (l1);
	return 0;
}
