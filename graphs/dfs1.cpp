#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main()
{
	int graph[10][10],n,m,visited[10],visit[10],v;
	memset (graph, 0, sizeof(graph));
	memset (visited, 0, sizeof(visited));
	memset (visit, 0, sizeof(visit));
	stack<int> s1;
	cin >> n;
	cin >> m;
	int p,q;
	for (int k = 1; k <= m; k++)
	{
		cin >> p >> q;
		graph[p][q] = 1;
	}
	cin >> v;
	s1.push(v);
	cout << "Visited Vertices \n";
	while (!s1.empty())
	{
		v = s1.top();
		cout << v << " ";
		s1.pop();
		if (visited[v] == 0)
			visited[v] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (graph[v][j] != 0 and visited[j] != 1 and visit[j] != 1)
			{
				s1.push(j);
				visit[j] = 1;
			}
		}

	}
	return 0;
}
