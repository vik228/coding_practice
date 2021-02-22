#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int time1;
int graph[10][10],color[10],pred[10],f[10],d[10],visit[10];
int n,m;
void dfsVisit(int);
void dfs ()
{
	time1 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (color[i] != 1)
			dfsVisit(i);
	}
}
void dfsVisit(int u)
{
	visit[u] = 1;
	d[u] = ++time1;
	for (int i = 1; i <= n; i++)
	{
		if (graph[u][i] != 0 and color[i] != 1 and visit[i] != 1)
		{
			pred[i] = u;
			dfsVisit(i);
		}
	}
	color[u] = 1;
	f[u] = ++time1;
}
int main()
{
	memset (graph, 0, sizeof(graph));
	memset (color, 0, sizeof (color));
	memset (pred, 0, sizeof (pred));
	memset (f, 0, sizeof (f));
	memset (d, 0, sizeof (d));
	memset (visit, 0, sizeof (visit));
	scanf ("%d%d",&n,&m);
	int p,q;
	for (int k = 1; k <= m; k++)
	{
		scanf ("%d%d",&p,&q);
		graph[p][q] = 1;
	}
	dfs();
	for (int i = 1; i <= n; i++)
	{
		cout << d[i] << "->" << f[i] << "\n";


	}
	return 0;

}
