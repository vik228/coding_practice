#include <iostream>
#include <cstdio>
using namespace std;
int graph[10][10];
bool reach[10][10];
void transitive_closure (int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			reach[i][j] = graph[i][j];
		}
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					reach[i][j] = reach[i][j] or (reach[i][k] and reach[k][j]);
				}
			}
		}
	}
}
int main()
{
	int n;
	scanf ("%d",&n);
	int u, v;
	for (int i = 1; i <= n; i++)
	{
		scanf ("%d%d",&u,&v);
		graph[u][v] = 1;
	}
	transitive_closure (n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << reach[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
