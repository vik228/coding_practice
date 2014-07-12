#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void init(int node, int b, int e, int M[], int A[], int N)
{
	if (b == e)
		M[node] = b;
	else
	{
		int mid = (b+e)/2;
		init (2*node, b, mid, M, A, N);
		init (2*node + 1, mid + 1, e, M, A, N);
		if (A[M[2*node]] < A[M[2*node + 1]])
			M[node] = M[2*node];
		else
			M[node] = M[2*node + 1];
	}
}
int query(int node, int b, int e, int M[], int A[], int i, int j)
{
	if (i < b or j > e)
		return -1;
	if (i >= b and j <= e)
		return M[node];
	int mid = (b+e)/2;
	int p1 = query (2*node, b, mid, M, A, i, j);
	int p2 = query (2*node + 1, mid + 1, e, M, A, i, j);
	if (p1  == -1)
		return M[node] = p2;
	if (p2 == -1)
		return M[node] = p1;
	if (A[p1] <= A[p2])
		return M[node] = p1;
	return M[node] = p2;
}
int main()
{
	int A[10] = {2,3,4,1,6,7,8,9,1,7};
	int M[21];
	memset (M, -1, sizeof(M));
	init (1,0,9,M,A,10);
	/*
	for (int i = 0; i < 21; i++)
		cout << M[i] << " ";
	*/
	cout << A[query (1,0,9,M,A,0,4)];
	cout << "\n";
	return 0;



}
