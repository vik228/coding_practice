#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits.h>
using namespace std;
int input[100];
int longest_bitonic_sequence (int n)
{
	int lis[n];
	int lds[n];
	lis[0] = 1;
	for (int i = 1; i < n; i++)
	{
		lis[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (input[i] >= input[j])
			{
				lis[i] = max (lis[i], 1 + lis[j]);
			}
		}
	}
	lds[n-1] = 1;
	for (int i = n-2; i >= 0; i--)
	{
		lds[i] = 1;
		for (int j = n-1; j > i; j--)
		{
			if (input[i] >= input[j])
			{
				lds[i] = max (lds[i], 1 + lds[j]);
			}
		}
	}
	int max1 = lds[0] + lis[0] - 1;
	for (int i = 1; i < n; i++)
	{
		int val = lds[i] + lis[i] - 1;
		max1 = max (max1, val);
	}
	for (int i = 0; i < n; i++)
		cout << lds[i] << " ";
	cout << "\n";
	for (int i = 0; i < n; i++)
		cout << lis[i] << " ";
	cout << "\n";
	return max1;

}
int main()
{
	int n;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&input[i]);	
	}
	printf ("%d\n",longest_bitonic_sequence (n));
	return 0;
}
