#include <iostream>
#include <cstdio>
using namespace std;
#define INF 1e9
struct node 
{
	int offt;
	int cmax;
}tree[5000];
void update (int n, int b, int e, int i, int j, int val)
{
	if (b > e or i > j or b > j or e < i)
		return;
	if (b >= i and e <= j)
	{
		tree[n].offt += val;
		tree[n].cmax += val;
		return;
	}
	int mid = (b+e)/2;
	update (2*n,b,mid,i,j,val);
	update (2*n + 1,mid + 1,e,i,j,val);
	tree[n].cmax = max (tree[2*n].cmax, tree[2*n + 1].cmax) + tree[n].offt;
}
int query (int n, int b, int e, int i, int j, int offt)
{
	if (b > e or i > j or b > j or e < i)
		return 0;
	if (b>=i && e<=j)
	  return tree[n].cmax + offt;
	offt += tree[n].offt;
	return max ( query(n*2 , b , (b+e)/2 , i , j, offt) , query(n*2+1 , (b+e)/2 + 1 , e , i , j, offt) );
}
int main()
{
	int tc,x,a,b,v;
	cin >> tc;
	while (tc--)
	{
		cin >> x >> a >> b;
		if (x == 0)
		{
			cin >> v;
			update (1,0,999,a,b,v);
			/*
			for (int i = 0; i < 9; i++)
				cout << tree[i].offt << "->" << tree[i].cmax << "\n";
			*/
		}
		else
			cout << query (1,0,999,a,b,0) << "\n";
	}
}
