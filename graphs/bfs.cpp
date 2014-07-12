#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int main()
{
	int graph[10][10],visited[10],n,m,p,q,v,visit[10];
	memset (graph,0,sizeof(graph));
	memset (visited, 0, sizeof(visited));
	memset (visit, 0, sizeof(visit));
	queue<int> q1;
	cout << "\nEnter the number of vertices\n";
	cin >> n;
	cout << "\nEnter the number of Edges\n";
	cin >> m;
	cout << "Edges\n";

	for (int i = 1; i <= m; i++)
	{
		cin >> p >> q;
		graph[p][q] = 1;
	}
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << graph[i][j] << "\t";
		}
		cout << "\n";
	}
	*/
	cout << "Enter the initial vertex\n";
	cin >> v;
	cout << "Visited vertices\n";
	q1.push(v);
	while (!q1.empty())
	{
		v = q1.front();
		cout << v << " ";
		q1.pop();
		if(visited[v] != 1)
			visited[v] = 1;
		//cout << "Printing neighbours of vertax " << v << "\n";
		for (int j = 1; j <= n; j++)
		{
			if (graph[v][j] != 0 and visited[j] != 1 and visit[j] != 1)
			{
				//cout << j << " ";
				q1.push(j);
				visit[j] = 1;
			}
		}
		//cout << "\n";
	}
	return 0;

}
