#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector <int> graph[10];
int low[10];
int disc[10];
int parent[10];
bool visited[10];
int time1 = 0;
void bridge (int u)
{
	visited[u] = true;
	disc[u] = low[u] = ++time1;
	for (int i = 0; i < graph[u].size(); i++)
	{
		int v = graph[u][i];
		parent[v] = u;
		if (!visited[v])
		{
			bridge (v);
			low[u] = min (low[u], low[v]);
			if (low[v] > disc[u])
				cout << u << " " << v << endl;
		}
		else if (v != parent[u])
			low[u] = min (disc[v], low[u]);
	}
}
int main()
{
	int n_e, n_v;
	scanf ("%d%d",&n_v,&n_e);
	int u, v;
	for (int i = 0; i < n_e; i++)
	{
		scanf ("%d%d",&u, &v);
		graph[u].push_back (v);
		graph[v].push_back (u);
	}
	for (int i = 0; i < n_v; i++)
	{
		if (!visited[i])
			bridge (i);
	}
}
