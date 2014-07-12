#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
pair <int, int> p1[100];
int mcl(int n)
{
	int lis[n+1];
	for (int i = 0; i < n; i++)
	{
		lis[i] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i-1; j++)
		{
			if ((p1[i].first > p1[j].second) and (lis[i] < lis[j] + 1) )
			{
				lis[i] = lis[j] + 1;
			}
		}
	}
	int val = MIN_INT;
	for (int i = 0; i < n; i++)
	{
		val = max (val, lis[i]);
	}
	return val;
}
int main()
{
	int n;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d%d",&p1[i].first, &p1[i].second);
	}
	sort (p1, p1+n);
	cout << mcl (n) << "\n";
}
