#include <cstdio>
#include <iostream>
#include "List.h"
using namespace std;
int deleteMiddle (Node* n1)
{
	Node* p1;
	p1 = n1->getNext();
	n1->set(p1->get());
	n1->setNext(p1->getNext());
	delete (p1);
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
	traverse (l1);
	Node* head = l1.getHead ();
	Node *p, *q;
	p = q = head;
	//cout << p->get() << " " << q->get() << "\n";
	while (q->getNext () != NULL)
	{
		p = p->getNext();
		q = q->getNext();
		q = q->getNext();
	}
	cout << p->get() << "\n";
	deleteMiddle (p);
	traverse (l1);
	return 0;
}
