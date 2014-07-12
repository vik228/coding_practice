#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int input[100];
bool findPartition (int n, int sum)
{
	int p[n+1][sum/2+1];
	for (int i = 0; i <= n; i++)
	{
		p[i][0] = true;
	}
	for (int i = 0; i <= sum/2; i++)
		p[0][i] = false;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum/2; j++)
		{
			if (j >= input[i-1])
				p[i][j] = (p[i-1][j] or p[i-1][j-input[i-1]]);
			else
				p[i][j] = p[i-1][j];
		}
	}
	return p[n][sum/2];
}
int main ()
{
	int n;
	scanf ("%d",&n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&input[i]);
		sum += input[i];
	}
	if (sum % 2 == 1)
		cout << "No\n";
	else if (findPartition (n, sum/2))
		cout << "Yes\n";
	else
		cout << "NO\n";
	return 0;
	
}
