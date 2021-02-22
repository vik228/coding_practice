#include <iostream>
#include <cmath>
#define INF 1000000
using namespace std;
int main()
{
	int k;
	cin >> k;
	int coins[k + 1];
	int n;
	cin >> n;
	int dp[k + 1][n + 1];
	for (int i = 1; i <= k; i++)
		cin >> coins[i];
	for (int i = 1; i <= k; i++)
	{
		dp[i][0] = 0;
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == 1 and j < coins[i])
				dp[i][j] = INF;
			else if (i == 1)
				dp[i][j] = 1 + dp[i][j - coins[i]];
			
			else if (j < coins[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = min (dp[i - 1][j], 1 + dp[i][j - coins[i]]);

		}
	}
	int k = W;
	int min_money = 0;
	for (int i = N; i >= 1; i--)
	{
		if (keep[i][k] == 1)
		{
			min_money += w[i];
			k = k - w[i];
		}
	}
	cout << dp[k][n] << ":" << min_money << "\n";
	return 0;
}
