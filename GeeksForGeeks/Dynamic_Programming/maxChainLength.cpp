#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
pair <int, int> p1[100];
int mcl[100];
int maxChainLength(int n)
{
	for (int i = 0; i < n; i++)
	{
		mcl[i] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((p1[j].second < p1[j].first) and (mcl[i] < mcl[j] + 1))
				mcl[i] = mcl[j] + 1;
		}
	}
	int val = 0;
	for (int i = 0; i < n; i++)
	{
		val = max (val, mcl[i]);
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
	cout << maxChainLength(n) << "\n";
	return 0;
}
