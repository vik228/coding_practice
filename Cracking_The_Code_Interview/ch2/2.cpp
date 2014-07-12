#include <cstdio>
#include "List.h"
using namespace std;
int find_kth_from_the_last (List& l1, int k)
{
	Node* head;
	head = l1.getHead();
	Node *p, *q;
	p = q = head;
	for (int i = 0; i < k-1; i++)
	{
		q = q->getNext();
	}
	while (q->getNext() != NULL)
	{
		p = p->getNext();
		q = q->getNext();
	}
	return p->get();
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
	int k;
	scanf ("%d",&k);
	cout << find_kth_from_the_last (l1, k) << "\n";
	return 0;
}

