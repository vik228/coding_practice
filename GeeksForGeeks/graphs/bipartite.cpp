#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
vector < int > G[10];
bool visited[10];
int color[10];
bool isBipartite (int u)
{
	queue < int > Q;
	Q.push(u);
	color[u] = 0;
	//visited[u] = true;
	while (!Q.empty())
	{
		//cout << "stuck \n";
		int v = Q.front();
		visited[v] = true;
		Q.pop();
		for (int i = 0; i < G[v].size(); i++)
		{
			int w = G[v][i];
			if (color[v] == color[w])
				return false;
			if (!visited[w])
			{
				Q.push (w);
				visited[w] = true;
				color[w] = (color[v] + 1)%2;
			}
		}


	}
	return true;

}
int main()
{
	memset (color, -1, sizeof (color));
	int n, n_e;
	cout << "Enter the number of nodes \n";
	cin >> n;
	cout << "Enter the number of edges \n";
	cin >> n_e;
	int u, v;
	for (int i = 0; i < n_e; i++)
	{
		scanf ("%d%d",&u, &v);
		G[u - 1].push_back (v - 1);
		G[v - 1].push_back (u - 1);

	}
	//cout << "hiii\n";
	bool val = true;
	for (int i = 1; i <= n; i++)
	{
		cout << "stuck \n";
		if (!visited[i])
		{
			cout << "calling \n";
			if (!isBipartite (i))
			{
				val = false;
				break;
			}
		}
	}
	if (!val)
		cout << "NO \n";
	else 
		cout << "YES\n";
	return 0;

}
