#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int A[10];
void countingSort (int n, int exp)
{
	cout << "hii\n";
	int count[10] = {0};
	//memset (count, 0, sizeof (count));
	for (int i = 0; i < n; i++)
	{
		count[(A[i]/exp)%10]  += 1;
	}
	//cout << "Working fine\n";
	for (int i = 0; i < n; i++)
		count[i] = count[i] + count[i-1];
	int out[n];
	memset (out, 0, sizeof (out));
	//cout << n << "\n";
	for (int i = 0; i < n; i++)
	{
		//cout << "hiii\n";
		//cout << i << "\n";
		if (i >= 8)
			break;
		out[ count[ ( A[i]/exp ) % 10 ] - 1 ] = A[i];
		count[(A[i]/exp)%10] -= 1;
	}
	//cout << "hii\n";
	for (int i = 0; i < n; i++)
	{
		if (i >= 8)
			break;
		//cout << i << "\n";
		A[i] = out[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (i >= 8)
			break;
		cout << A[i] << " ";
	}
	cout << "\n";
}
int getMax (int n)
{
	int max1 = A[0];
	for (int i = 1; i < n; i++)
	{
		max1 = max (A[i], max1);
	}
	return max1;
}
void radixSort (int n)
{
	int m = getMax (n);
	for (int exp = 1; m/exp > 0; exp *= 10)
		countingSort (n, exp);
}
int main()
{
	int n;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&A[i]);
	}
	radixSort (n);
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << "\n";
	return 0;

}
