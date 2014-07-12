#include <iostream>
#include <cstdio>
#include "List.h"
Node *p, *q;
int i, j;
bool isPalin (Node* n1)
{
	p = p->getNext();
	q = q->getNext();
	if (q == NULL or q->getNext() == NULL)
	{
		if (q == NULL)
		{
			return true;
		}
		else 
		{
			bool val = (n1->get() == p->get());
			p = p->getNext();
			return val;
		}
	}
	q = q->getNext();
	i++;
	j += 2; 
	bool p1 = isPalin (n1->getNext());
	bool val = (p1 and (n1->get() == p->get()));
	p = p->getNext();
	return (p1 and val);
}
int main()
{
	int N;
	scanf ("%d",&N);
	List l1;
	for (int k1 = 0; k1 < N; k1++)
	{
		int val;
		scanf ("%d",&val);
		l1.add (val);
	}
	p = q = l1.getHead();
	i = j = 1;
	if (isPalin (l1.getHead()))
		cout << "Yes " << "\n";
	return 0;
}
