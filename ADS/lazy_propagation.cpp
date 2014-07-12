#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define MAX 10
#define MAXN 21
int A[MAX];
int M[MAXN];
void update (int n,int b, int e,int i, int j, int val)
{
	cout << "hiii\n";
	if (b>e || b>j || e<i )
		return;
	if (i <= b && j >= e)
	{
		M[n]+= (e-b+1)*val;
		return;
	}
	int mid = (b + e)/2;
	update (2*n,b,mid,i,j,val);
	update (2*n + 1, mid+1, e, i, j, val);
	M[n] = M[2*n] + M[2*n + 1];
}
int query (int n, int b, int e, int i, int j)
{
	if (i < b or j > e)
		return -1;
	if (i >= b and j  <= e)
		return M[n];
	int mid = (b + e)/2;
	int p1 = query (2*n, b, mid, i, j);
	int p2 = query (2*n + 1, mid + 1, e, i, j);
	if (p1 == -1)
		return M[n] = p2;
	if (p2 == -1)
		return M[n] = p1;
	return p1 + p2;

}
int main()
{
	int n,q;
	scanf ("%d%d",&n,&q);
	while (q--)
	{
		int qry, val1, val2;
		scanf ("%d%d%d",&qry,&val1,&val2);
		if (qry == 1)
		{
			for (int i = val1; i <= val2; i++)
				A[i]+= qry;
			update (1,0,n-1,val1,val2,qry);
			cout << "here\n";
			for (int i = 0; i <= 10; i++)
				cout << M[i] << " ";
			cout << "\n";
		}
		else
			cout << query (1,0,n-1,val1,val2);

	}
}
