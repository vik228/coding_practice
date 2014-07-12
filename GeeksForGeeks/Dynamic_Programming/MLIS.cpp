#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits.h>
using namespace std;
int input[100];
int max_lis (int n)
{
	int ans[n];
	ans[0] = input[0];
	int max_sum = 0;
	for (int i = 1; i < n; i++)
	{
		ans[i] = INT_MIN;
		for (int j = 0; j < i; j++)
		{
			if (input[j] <= input[i])
			{
				ans[i] = max (ans[i], ans[j] + input[i]);
				max_sum = max (ans[i], max_sum);
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return max_sum;
}
int main()
{
	int n;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&input[i]);
	}
	printf ("%d\n", max_lis (n));
	return 0;
}
