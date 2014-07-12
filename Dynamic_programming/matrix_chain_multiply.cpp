#include <iostream>
using namespace std;
#define INF 100000000
int dp[7][7];
int p[7];
int s[7][7];
void matrix_chain_order ()
{
	int n = 6;
	for (int i = 1; i <= n; i++)
		dp[i][i] = 0;
	for (int l = 2; l <= n; l++)
	{
		for (int i = 1; i <= n-l+1; i++)
		{
			int j = i + l - 1;
			dp[i][j] = INF;
			for (int k = i; k < j; k++)
			{
				int q = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
				if (q < dp[i][j])
				{
					dp[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}
void print_optimal_order (int i, int j)
{
	if (i == j)
	{
		cout << "A" << i;
	}
	else
	{
		cout << "(" ;
		print_optimal_order (i, s[i][j]);
		print_optimal_order (s[i][j] + 1, j);
		cout << ")";
	}
}
int main()
{
	cout << "Enter the dimentions of the matrices \n";
	for (int i = 0; i <= 6; i++)
	{
		cin >> p[i];
	}
	matrix_chain_order();
	print_optimal_order(1, 6);
	cout << "\n";
	return 0;
}
