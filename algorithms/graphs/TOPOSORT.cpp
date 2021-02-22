#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int visited[10000], graph[10000][10000];
int n,m;
pair <int, int> fd[10000];
int time1 = 0;
void dfs(int u)
{
	visited[u] = 1;
	fd[u].first = ++time1;
	for (int i = 0; i < n; i++)
	{
		if (graph[u][i] != 0 and visited[i] == 0)
			dfs(i);
	}
	fd[u].second = ++time1;
	//fd[u].second = u;
}

int main()
{
	for (int i = 0; i < 10000; i++)
	{
		for (int j = 0; j < 10000; j++)
		{
			graph[i][j] = 0;
		}
	}
	scanf ("%d%d",&n,&m);
	int x,y;
	for (int i = 0; i < m; i++)
	{
		scanf ("%d%d",&x,&y);
		graph[x][y] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
			dfs(i);
	}
	//sort (fd,fd + n);
	for (int i = 0; i < n; i++)
		cout << fd[i].first << "->" << fd[i].second << "\n";
	return 0;
}
