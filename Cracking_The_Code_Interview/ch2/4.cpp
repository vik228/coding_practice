#include <iostream>
#include <cstdio>
#include "List.h"
using namespace std;
void seperateList (List& l1, int x)
{
	List l2, l3;
	l1.start();
	while (l1.next())
	{
		if (l1.get() > x)
		{
			l3.add (l1.get());
		}
		else
			l2.add (l1.get());
	}
	traverse (l3);
	traverse (l2);

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
	int x;
	scanf ("%d",&x);
	seperateList (l1, x);
	return 0;
}
