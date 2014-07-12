#include <iostream>
#include <cstdio>
using namespace std;
//int G[10][10];
int d[10], pred[10];
#define INF 1000000000
struct graph
{
	int u, v, c;
}G[10];
void relax (int u, int v, int c)
{
	if ((d[u] + c) < d[v])
	{
		d[v] = d[u] + c;
		pred[v] = u;
	}
}
void bellman_ford (int s, int n_v, int n_e)
{
	for (int i = 1;  i < n_v; i++)
	{
		d[i] = INF;
		pred[i] = -1;
	}
	d[s] = 0;
	for (int i = 1; i <= n_v-1; i++)
	{
		for (int i = 0; i < n_e; i++)
		{
			int u = G[i].u;
			int v = G[i].v;
			int c = G[i].c;
			relax (u, v, c);
		}
		for (int k = 0; k < n_v; k++)
			cout << d[k] << " ";
		cout << "\n";
	}
}
int main()
{
	int n, e;
	cout << "Enter the number of vertices \n";
	cin >> n;
	cout << "Enter the number of edges \n";
	cin >> e;
	int u, v,c;
	for (int i = 0; i < e; i++)
	{
		cin >> G[i].u >> G[i].v >> G[i].c;
	}
	bellman_ford (0, n, e);
	for (int i = 0; i < n; i++)
		cout << d[i] << "\n";
	//cout << bellman_ford (n);
	return 0;
}
