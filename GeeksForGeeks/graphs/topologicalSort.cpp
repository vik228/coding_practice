#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
bool visited[10];
vector <int> graph[10];
stack <int> s1;
bool rec_stack[10];
bool topologicalSort (int v)
{
	//cout << v << "\n";
	if (visited[v] == false)
	{
		visited[v] = true;
		rec_stack[v] = true;
		for (int i = 0; i < graph[v].size(); i++)
		{
			cout << v << " " << i << "\n";
			int w = graph[v][i];
			cout << w << "\n";
			if (!visited[w] and !topologicalSort (w))
				return false;
			else if (rec_stack[w])
				return false;
		}
	}
	s1.push (v);
	rec_stack[v] = false;
	return true;
}
int main()
{
	int n_e, n_v;
	cin >> n_v >> n_e;
	int u, v;
	for (int i = 0; i < n_e; i++)
	{
		scanf ("%d %d",&u,&v);
		graph[u].push_back (v);
	}
	bool possible = true;
	for (int i = 1; i <= n_v; i++)
	{
		if (!visited[i])
		{
			if (!topologicalSort (i))
			{
				possible = false;
				break;
			}
		}
	}
	if (!possible)
		cout << "NO\n";
	else
	{
		cout << "hiii\n";
		while (!s1.empty())
		{
			cout << s1.top() << " ";
			s1.pop();
		}
		cout << "\n";
	}
	return 0;

}
