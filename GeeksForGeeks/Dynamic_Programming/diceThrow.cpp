#include <iostream>
#include <cstdio>
using namespace std;
int dp[100][100];
int diceThrow (int n, int sum, int m)
{
	for (int i = 1; (i <= sum and i <= m); i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			for (int k = 1; (k <= m and k < j); k++)
			{
				dp[i][j] += dp[i-1][j-k];
			}
		}
	}
	return dp[n][sum];
}
int main()
{
	cout << diceThrow (4, 2, 1) << "\n";
	cout << diceThrow (2, 2, 3) << "\n";
	return 0;
}
