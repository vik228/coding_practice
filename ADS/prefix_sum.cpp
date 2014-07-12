#include <iostream>
#include <cstdio>
using namespace std;
int input[50];
struct tree_node
{
	int total_sum, prefix_sum;
}tree[150];
void init (int node, int b, int e)
{
	//cout << "hiii\n";
	if (b == e)
	{
		tree[node].total_sum = tree[node].prefix_sum = input[b];
		return;
	}
	int mid = (b + e)/2;
	init (2*node, b, mid);
	init (2*node + 1, mid + 1, e);
	tree[node].total_sum = tree[2*node].total_sum + tree[2*node+1].total_sum;
	tree[node].prefix_sum = max (tree[2*node].prefix_sum, (tree[2*node].total_sum + tree[2*node + 1].prefix_sum));
}
void query (tree_node &ret_val, int node, int b, int e, int i, int j)
{
	cout << b << ":" << i << ";" << e << ":" << j << "\n";
	if (i == b and j == e)
	{
		cout << "returning \n";
		ret_val = tree[node];
		return;
	}
	int mid = (b + e)/2;
	if (j <= mid)
		query (ret_val, 2*node, b, mid, i, mid);
	else if (i > mid)
		query (ret_val, 2*node + 1, mid + 1, e, mid + 1, j);
	else
	{
		tree_node left, right;
		query (left, 2*node, b, mid, i, mid);
		query (right, 2*node + 1, mid + 1, e, mid + 1, j);
		ret_val.total_sum = left.total_sum + right.total_sum;
		ret_val.prefix_sum = max (left.prefix_sum, (left.total_sum + right.prefix_sum)); 
	}
}
int main()
{
	int n;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d", &input[i]);
	}
	init (1, 0, n-1);
	int q;
	cin >> q;
	int i, j;
	while (q--)
	{
		tree_node n1;
		scanf ("%d%d",&i, &j);
		query (n1,1, 0, n-1, i, j);
		cout << n1.prefix_sum << "\n";
	}
	return 0;
		

}
