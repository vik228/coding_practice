#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector <int> v1;
int binary_search (int e, int lo, int hi)
{
	//cout << hi << " "  << lo << "\n";
	if (hi < lo)
		return -1;
	int mid = (hi + lo)/2;
	if (e < v1[mid])
		binary_search (e, lo, mid-1);
	else if (e > v1[mid])
		binary_search (e, mid+1, hi);
	else if (e == v1[mid]) 
		return mid;
}
int main()
{
	int n;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf ("%d",&val);
		v1.push_back (val);
	}
	int ele;
	cin >> ele;
	cout << binary_search (ele, 0, n-1) << "\n";
}
