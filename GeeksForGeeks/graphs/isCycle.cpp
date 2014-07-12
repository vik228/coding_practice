#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int parent[10];
pair <int, int> G[10];
int find (int i)
{
	int j;
	for (j = i; parent[j] >= 0; j = parent[j]);
	return j ;
}
void union1 (int i, int j)
{
	int root_i = find (i);
	int root_j = find (j);
	if (root_i != root_j)
	{
		if (parent[root_i] <= parent[root_j])
		{
			parent[root_j] = root_i;
			parent[root_i]+= parent[root_j];
		}
		else
		{
			parent[root_i] = root_j;
			parent[root_j]+= parent[root_i];

		}
	}
}
bool isCycle (int n)
{
	cout << "Yhn to aaya\n";
	cout << find(G[0].first) << "\n";
	for (int i = 0; i < n; i++)
	{
		if (find(G[i].first) == find (G[i].second))
			return true;
		union1 (G[i].first, G[i].second);
	}
	return false;
}
int main ()
{
	memset (parent, -1, sizeof (parent));
	int n;
	cout << "Enter the number of edges\n ";
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf ("%d%d",&G[i].first, &G[i].second);
	//cout << "hii\n";
	if (isCycle (n))
		cout << "Yes there is a cycle \n";
	else
		cout << "No, the given graph has no cycle \n";
	return 0;

}
