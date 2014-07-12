#include <iostream>
#include <cstdio>
#include "List.h"
List add (List& l1, List& l2)
{
	int carry = 0;
	List l3;
	l1.start();
	l2.start();
	for (int i = 0; (l2.next() and l1.next() and i < l1.length()); i++)
	{
		int val = (l1.get() + l2.get())%10 + carry;
		carry = (l1.get() + l2.get())/10;
		l3.add (val);
	}
	return l3;
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
	int n2;
	scanf ("%d",&n2);
	for (int i = 0; i < n2; i++)
	{
		int val;
		scanf ("%d",&val);
		l2.add (val);
	}
	if (l1.length() < l2.length())
	{
		while (l1.length() < l2.length())
		{
			l1.add (0);
		}
	}
	else
	{
		while (l2.length() < l1.length())
		{
			l2.add (0);
		}
	}
	traverse (l1);
	traverse (l2);
	List l3 = add (l1, l2);
	traverse (l3);
}
