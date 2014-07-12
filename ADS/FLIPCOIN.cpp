#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 100000
#define MAXN 262150
int tree[MAXN];
void update (int n, int b, int e, int i, int j, int val)
{
	if (j < b or i > e)
		return;
	if (b >= i and e <= j)
	{
		tree[n] = (tree[n] + (e-b+1)*val)%2;
		return;
	}
	int mid = (b+e)/2;
	update (2*n, b, mid, i, j,1);
	update (2*n+1, mid+1, e, i, j,1);
	tree[n] = (tree[2*n] + tree[2*n+1])%2;
}
int query (int n, int b, int e, int i, int j)
{
	if (j < b or i > e)
		return -1;
	if (b >= i and e <= j)
	{
		return tree[n];
	}
	int mid = (b + e)/2;
	int p1 = query (2*n, b, mid, i, j);
	int p2 = query (2*n + 1, mid+1, e, i, j);
	if (p1 == -1)
		return tree[n] = p2;
	if (p2 == -1)
		return tree[n] = p1;
	return p1 + p2;
	
}
int main()
{
	int N, Q;
	scanf ("%d%d",&N,&Q);
	while (Q--)
	{
		int q,A,B;
		scanf ("%d%d%d",&q,&A,&B);
		if (q == 0)
		{
			update (1,0,N-1,A,B,1);
		}
		else
		{
			printf ("%d\n",query (1,0,N-1,A,B));
		}

	}
	return 0;
}
