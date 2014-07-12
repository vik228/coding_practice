#include <iostream>
#include <cstdio>
int a[100];
using namespace std;
void comb (int n, int r, int idx, int d[], int i)
{
	if (idx == r)
	{
		for (int j = 0; j < r; j++)
			cout << d[j] <<  " ";
			cout << "\n";
		return;
	}
	if (i >= n)
		return;
	d[idx] = a[i];
	comb (n, r, idx+1, d, i+1);
	comb (n, r, idx, d, i+1);
}
int main ()
{
	int n, r;
	scanf ("%d%d",&n,&r);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&a[i]);
	}
	int data[4] = {0};
	comb (n, r, 0, data, 0);
	return 0;
}
