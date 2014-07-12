#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
int a[10];
int b[10];
bool areIdentical (int n, int i1, int i2, int min1, int max1)
{
	int idx1, idx2;
	for (idx1 = i1; idx1 < n; idx1++)
	{
		if (a[idx1] > min1 and a[idx1] < max1)
			break;
	}
	for (idx2 = i2; idx2 < n; idx2++)
	{
		if (b[idx2] > min1 and b[idx2] < max1)
			break;
	}
	if (idx1 == n and idx2 == n)
		return true;
	if ((idx1 == n)^(idx2 == n) or a[idx1] != b[idx2])
		return false;
	return ((areIdentical(n, idx1+1, idx2+1, min1, a[idx1])) and (areIdentical (n, idx1+1, idx2+1, a[idx2], max1)));
}
int main()
{
	int n;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
		scanf ("%d",&a[i]);
	for (int j = 0; j < n; j++)
		scanf ("%d",&b[j]);
	if (areIdentical (n, 0, 0, INT_MIN, INT_MAX))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
