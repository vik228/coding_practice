#include <iostream>
#include <cstdio>
int dp[100][100];
int A[100][100];
using namespace std;
int main ()
{
	int N,M;
	cout << "Enter the rows and coloumns \n";
	cin >> N >> M;
	cout << "\n Enter the number of apples in each row\n";
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			dp[i][j] = A[i][j] + max (dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << dp[N][M] << "\n";
	return 0;
}
