#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector <int> G[100];
bool visited[100];
bool bfs (int source, int destination)
{
	queue <int> q;
	q.push (source);
	visited[source] = true;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		if (v == destination)
			return true;
		for (int i = 0; i < G[v].size(); i++)
		{
			int w = G[v][i];
			if (!visited[w])
			{
				visited[w] = true;
				q.push (w);
			}
		}
	}
	return false;

}
int main()
{
	int n_v, n_e;
	scanf ("%d%d",&n_v,&n_e);
	int u, v;
	for (int i = 0; i < n_e; i++)
	{
		scanf ("%d%d",&u,&v);
		G[u].push_back (v);
		G[v].push_back (u);
	}
	int src, dest;
	scanf ("%d%d",&src, &dest);
	if (bfs (src,dest))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
