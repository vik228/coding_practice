#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 10010
#define MAX1 100010
pair <int, int> A[MAX1];
int parent[MAX];
struct sorted_edges
{
	int u1,v1,c1;
}s[MAX1];
bool comp (sorted_edges e1, sorted_edges e2 )
{
	return e1.c1 < e2.c1;
}
int find (int i)
{
	int j;
	for (j = i; parent[j] >= 0; j = parent[j]);
		return j;
}
void union1 (int i, int j)
{
	int root1 = find(i);
	int root2 = find(j);
	if (root1 != root2)
	{
		if (parent[root1] <= parent[root2])
		{
			parent[root1]+= parent[root2];
			parent[root2] = root1;
		}
		else
		{
			parent[root2]+= parent[root1];
			parent[root1] = root2;
		}
	}
}
int krushkal(int n_v,int n_e)
{
	int k = 0;
	for (int i = 1; i <= n_v; i++)
		parent[i] = -1;
	//sort (s, s+n_e,comp);
	int min_cost = 0;
	for (int i = 0;i < n_e; i++)
	{
		if (find(s[i].u1) != find(s[i].v1))
		{
			A[k].first = s[i].u1;
			A[k].second = s[i].v1;
			min_cost+= s[i].c1;
			union1(s[i].u1, s[i].v1);
		}
	}
	return min_cost;
}
int main()
{
	int n_v, n_e;
	scanf ("%d%d",&n_v, &n_e);
	int u,v,c;
	for (int i = 1; i <= n_e; i++)
	{
		scanf ("%d%d%d",&u,&v,&c);
		//graph[u][v] = c;
		s[i - 1].u1 = u;
		s[i - 1].v1 = v;
		s[i - 1].c1 = c;
	}
	sort (s,s+n_e,comp);
	int size;
	size = krushkal(n_v,n_e);
	printf ("%d\n", size);
	/*
	int min_cost = 0;
	for (int i = 0; i < size; i++)
	{
		cout << A[i].first << "->" << A[i].second << "\n";
	}
	*/

	return 0;

}

