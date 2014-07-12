#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define NIL -1
bool visited[10];
bool ap[10];
vector <int> graph[10];
int low[10];
int disc[10];
int parent[10];
int time1 = 0;
void articulation_points (int u)
{
	int children = 0;
	disc[u] = low[u] = ++time1;
	visited[u] = true;
	for (int i = 0; i < graph[u].size(); i++)
	{
		int v = graph[u][i];
		if (!visited[v])
		{
			children++;
			parent[v] = u;
			articulation_points (v);
			low[u] = min (low[u], low[v]);
			if (parent[u] == -1 and children > 1)
				ap[u] = true;
			if (parent[u] != NIL and low[v] >= disc[u])
				ap[u] = true;


		}
		else if (v != parent[u])
			low[u] = min (low[u], disc[v]);
	}
}
int main ()
{
	int n_v, n_e;
	cin >> n_v >> n_e;
	int u, v;
	for (int i = 0; i < n_v; i++)
	{
		scanf ("%d%d",&u,&v);
		graph[u].push_back (v);
		graph[v].push_back (u);
	}
	memset (parent, -1, sizeof (parent));
	articulation_points (0);
	for (int i = 0; i < n_v; i++)
	{
		if (ap[i])
			cout << i << " ";
	}
	cout << "\n";
	return 0;
}
