#include <iostream>
#include <cstdio>
using namespace std;
int input[100];
bool isSum[100][100];
bool isSubsetSum (int n, int sum)
{
	for (int i = 0; i <= n; i++)
		isSum[i][0] = true;
	for (int i = 1; i <= sum; i++)
		isSum[0][i] = false;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			isSum[i][j] = isSum[i-1][j];
			if (input[i-1] <= j)
			{
				isSum[i][j] = (isSum[i][j] or isSum[i-1][j - input[i-1]]);
			}
		}
	}
	return isSum[n][sum];
}
int main()
{
	int n, sum;
	scanf ("%d%d",&n,&sum);
	for (int i = 0; i < n; i++)
		scanf ("%d",&input[i]);
	if (isSubsetSum(n, sum))
		cout << "YES\n";
	else
		cout << "NO\n";
}
