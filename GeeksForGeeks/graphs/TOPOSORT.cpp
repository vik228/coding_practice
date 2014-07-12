#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
#define MAX 10010
set <int> graph[MAX];
vector <int> topoList;
int indeg[MAX];
bool processed[MAX];
set <int> Q;
void topological_sorting(int n)
{
	set <int>::iterator it;
	while (!Q.empty())
	{
		int N = *Q.begin();
		Q.erase (Q.begin());
		topoList.push_back (N);
		processed[N] = true;
		for (it = graph[N].begin(); it != graph[N].end(); it++)
		{
			int v = *it;
			indeg[v]--;
			if (indeg[v] == 0 and !processed[v])
				Q.insert(v);
		}

	}
}
int main()
{
	int n, m;
	scanf ("%d%d",&n,&m);
	int u, v;
	while (m--)
	{
		scanf ("%d%d",&u,&v);
		graph[u].insert(v);
		indeg[v]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (indeg[i] == 0)
			Q.insert (i);
	}
	if (Q.empty())
		printf ("Sandro fails.");
	else
	{
		topological_sorting (n);
		for (int i = 0; i < topoList.size(); i++)
			printf ("%d ", topoList[i]);
	}
	return 0;
}
