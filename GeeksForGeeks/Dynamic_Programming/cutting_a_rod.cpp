#include <iostream>
#include <cstdio>
#include <cstring>
int prices[100];
using namespace std;
int cutRod (int n)
{
	int val[n+1];
	int val[0] = 0;
	int i, j;
	for (i = 1; i <= n; i++)
	{
		int max_val = INT_MIN;
		for (j = 0; j < i; j++)
		{
			max_val = max (max_val, price[j] + val[i-j-1]);
		}
		val[i] = max_val;
	}
	return val[n];
}
int main()
{
	int n;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&prices[i]);
	}
	cout << cutRod (n) << "\n";
}
