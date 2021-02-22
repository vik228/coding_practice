#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int W,n;
	cout << "Enter the maximum weight\n";
	cin >> W >> n;
	int v[n],w[n];
	int V[n + 1][W+1],keep[n + 1][W + 1];
	for (int i = 0; i < n+1; i++)
	{
		for (int j = 0; j < W+1; j++)
		{
			V[i][j] = 0;
			keep[i][j] = 0;
		}
	}
	cout << "\nEnter the individual weights of the items and their values\n";
	for (int i = 0; i < n; i++)
	{
		cin >> w[i] >> v[i];
	}
	for (int i = 0; i < n+1; i++)
		V[i][0] = 0;
	for (int i = 0; i < W + 1; i++)
		V[0][i] = 0;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < W + 1; j++)
		{
			if (w[i - 1] > j)
			{
				V[i][j] = V[i - 1][j];
				keep[i][j] = 1;
			}
			else
			{
				V[i][j] = max(V[i - 1][j], v[i - 1] + V[i - 1][j - w[i - 1]]);
				keep[i][j] = 0;
			}
		}
	}
	int k = W;
	int val_used = 0;
	for (int i = n; i >= 0; i--)
	{
		if (keep[i][k] == 1)
		{
			cout << i << "\n";
			k = k - w[i];

		}


	}
	for (int i = 0; i < n + 1; i++)
	{
		cout << "\n";
		for (int j = 0; j < W + 1; j++)
		{
			cout << V[i][j] << "\t";
		}
	}
	cout << "\n";
	cout << "The maximum Weight You can choose is\n";
	cout << V[n][W];
	return 0;


}
