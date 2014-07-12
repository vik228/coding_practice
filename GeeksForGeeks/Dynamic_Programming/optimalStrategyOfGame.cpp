#include <iostream>
#include <cstdio>
using namespace std;
int input[100];
int table[100][100];
int optimalStrategyOfGame (int n)
{
	for (int i = 0; i < n; i++)
	{
		table[i][i] = input[i];
	}
	for (int gap = 1; gap < n; ++gap)
	{
		for (int i = 0, j = gap; j < n; i++, j++)
		{
			if (j == i + 1)
				table[i][j] = max (input[i], input[j]);
			else
			{
				int v1 = input[i] + min (table[i+2][j], table[i+1][j-1]);
				int v2 = input[j] + min (table[i+1][j-1], table[i][j-2]);
				table[i][j] = max (v1, v2);
			}
		}
	}
	return table[0][n-1];
}
int main()
{
	int n;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
		scanf ("%d",&input[i]);
	cout << optimalStrategyOfGame (n) << "\n";
	return 0;
}
