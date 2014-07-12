#include <cstdio>
#include <map>
#include "List.h"
void removeDuplicates (List& l1)
{
	map <int, bool> m1;
	l1.start();
	while (l1.next())
	{
		if (!m1[l1.get()])
		{
			m1[l1.get()] = true;
		}
		else
		{
			l1.remove();
		}
	}
}
int main()
{
	List l1;
	int n;
	scanf ("%d",&n);
	int val;
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&val);
		l1.add (val);
	}
	traverse(l1);
	removeDuplicates (l1);
	traverse (l1);

	return 0;
}

			
