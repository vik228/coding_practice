#include <iostream>
#include <cstdio>
using namespace std;
int merge (int N, int M, int i, int j)
{
	int t = 1 << 31;
	int p = 1 << (j + 1);
	int L = t | (~(p-1));
	int R = t | ((1 << i) - 1);
	int mask = L | R;
	M = M << i;
	return (M | N);
}
int main()
{
	int N, M, i, j;
	scanf ("%d%d%d%d",&N,&M,&i,&j);
	cout << merge (N, M, i, j) << "\n";
	int p = ~0;
	cout << p << "\n";
	cout << (p << (6)) << "\n";
}
