#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
using namespace std;
int graph[10][10],color[10], visit[10];
list <int> l1;
int n,m;
void topVisit(int u)
{
	visit[u] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (graph[u][i] != 0 and color[i] != 1 and visit[i] != 1)
		{
			topVisit(i);
		}
	}
	color[u] = 1;
	l1.push_front(u);
}
void topologicalSort ()
{
	for (int i = 1; i <= n; i++)
	{
		if (color[i] != 1)
		{
			topVisit(i);
		}
	}
}
int main()
{
	cin >> n >> m;
	int p,q;
	list<int>::iterator it;
	for (int i = 1; i <= m; i++)
	{
		cin >> p >> q;
		graph[p][q] = 1;
	}
	topologicalSort();
	for (it = l1.begin(); it != l1.end(); it++)
		cout << *it << " ";
	cout << "\n";

}
