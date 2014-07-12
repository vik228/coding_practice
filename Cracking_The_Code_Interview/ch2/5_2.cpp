#include <cstdio>
#include <iostream>
#include "List.h"
int carry = 0;
List l3;
void add (Node* n1, Node* n2)
{
	if (n1->getNext() == NULL or n2->getNext() == NULL)
	{
		int val = (n1->get() + n2->get() + carry);
		//cout << val%10 << " ";
		l3.add (val%10);
		carry = val/10;
		return;
	}
	add (n1->getNext(), n2->getNext());
	int val = (n1->get() + n2->get() + carry);
	//cout << val%10 << " ";
	addNodes (val%10, 0, l3);
	l3.incr_size();
	carry = val/10;
}
int main()
{
	int N;
	scanf ("%d",&N);
	List l1, l2;
	for (int i = 0; i < N; i++)
	{
		int val;
		scanf ("%d",&val);
		l1.add (val);
	}
	int n1; 
	scanf ("%d",&n1);
	for (int i = 0; i < n1; i++)
	{
		int val;
		scanf ("%d",&val);
		l2.add (val);
	}
	if (l1.length() < l2.length())
	{
		int k = l2.length() - l1.length();
		while (k--)
		{
			addNodes (0, 0, l1);
			l1.incr_size();
		}
	}
	else
	{
		int k = l1.length() - l2.length();
		while (k--)
		{
			addNodes (0, 0, l2);
			l2.incr_size ();
		}
	}
	traverse (l1);
	traverse (l2);
	cout << "+" << "\n";
	Node* l1_head = l1.getHead();
	Node* l2_head = l2.getHead();
	add (l1_head, l2_head);
	traverse (l3);
	return 0;

}
