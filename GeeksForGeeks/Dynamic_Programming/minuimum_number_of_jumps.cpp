#include <iostream>
#include <cstdio>
#include <limits.h>
using namespace std;
int input[100];
int minJumps (int n)
{
	int* jumps = new int[n];
	if (input[0] == 0)
		return INT_MAX;
	jumps[0] = 0;
	for (int i = 1; i < n; i++)
	{
		jumps[i] = INT_MAX;
		for (int j = 0; j < i; j++)
		{
			if (input[j] >= i - j)
			{
				jumps[i] = min (jumps[i], jumps[j] + 1);
			}
		}
	}
	int ans = jumps[n-1];
	delete[] jumps;
	return ans;
}
int main()
{
	int n;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&input[i]);
	}
	cout << minJumps(n) << "\n";
	return 0;
}
