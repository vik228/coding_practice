#include <iostream>
#include <cstdio>
using namespace std;
int dp[100][100];
int cost[100][100];
int min1(int a, int b, int c)
{
	int d = min (a, b);
	int e = min (b, c);
	return min (d,e);
}
int find_min_path (int m, int n)
{
	dp[0][0] = cost[0][0];
	for (int i = 1; i <= n; i++)
		dp[0][i] = dp[0][i-1] + cost[0][i];
	for (int i = 1; i <= m; i++)
		dp[i][0] = dp[i-1][0] + cost[i][0];
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = min1 (dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + cost[i][j];
		}
	}
	return dp[m][n];
		
}
int main()
{
	int m, n;
	scanf ("%d%d",&m,&n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf ("%d",&cost[i][j]);
		}
	}
	cout << find_min_path (m, n) << "\n";
	return 0;
}
