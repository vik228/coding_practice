#include <iostream>
#include <cstdio>
using namespace std;
int coin[100][100];
int s[100];
int ret_num_ways (int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		coin[0][i] = 1;
	}
	for (int i = 1; i < n+1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x = (i - s[j] >= 0) ? coin[i-s[j]][j] : 0;
			int y = (j >= 1) ? coin[i][j-1] : 0;
			coin[i][j] = x + y;
		}
	}
	return coin[n][m-1];
}
int main()
{
	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf ("%d",&s[i]);
	cout << ret_num_ways(m, n) << "\n";
	return 0;
	
}
