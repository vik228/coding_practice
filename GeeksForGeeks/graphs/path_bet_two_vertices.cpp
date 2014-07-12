#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000
bool visited[MAX];
vector <int> graph[MAX];
bool isPath (int i, int j)
{
	queue<int> Q;
	Q.push(i);
	while (!Q.empty())
	{
		int v = Q.front();
		if (v == j)
			return true;
		Q.pop();
		visited[v] = true;
		for (int k = 0; k < graph[v].size(); k++)
		{
			int w = graph[v][k];
			if (!visited[w])
			{
				visited[w] = true;
				Q.push (w);
			}
		}
	}
	return false;
}
int main()
{
	int n_v, n_e;
	scanf ("%d%d",&n_v,&n_e);
	for (int i = 0; i < n_e; i++)
	{
		int u,v;
		scanf ("%d%d",&u,&v);
		graph[u].push_back (v);
		//graph[v].push_back (u);

	}
	int v1, v2;
	scanf ("%d %d",&v1, &v2);
	if (isPath(v1, v2))
		cout << "YES\n";
	else
		cout << "No\n";


}
