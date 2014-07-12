#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
bool visited[10];
vector <int> graph[10];
bool dfs (int u)
{
	stack <int> s1;
	s1.push(u);
	while (!s1.empty())
	{
		int v = s1.top();
		if (visited[v])
			return true;
		visited[v] = true;
		s1.pop();
		for (int i = 0; i < graph[v].size(); i++)
		{
			int w = graph[v][i];
			if (visited[w])
				return true;
			else
			{
				//visited[w] = true;
				s1.push (w);
			}
		}
	}
	return false;
}
int main()
{
	int n_e, n_v;
	cin >> n_e >> n_v;
	for (int i = 0; i < n_e; i++)
	{
		int u, v;
		scanf ("%d%d",&u, &v);
		graph[u-1].push_back (v-1);
	}
	bool val = true;
	for (int i = 0; i < n_v; i++)
	{
		if (!visited[i])
		{
			if (dfs (i))
			{
				val = false;
				cout << "YES\n";
				break;
			}
		}
	}
	if (val)
		cout << "No\n";

}

