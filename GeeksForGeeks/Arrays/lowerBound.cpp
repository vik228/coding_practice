#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector <int> v1;
int lower_bound (int ele, int lo, int hi)
{
	while (lo < hi)
	{
		cout << lo << " " << hi <<"\n"; 
		int mid = lo + (hi - lo)/2;
		cout << mid << "\n";
		cout << v1[mid] << "\n";
		if (v1[mid] < ele)
		{
			cout << "hii\n";
			lo = mid + 1;
		}
		else if (v1[mid] > ele)
			hi = mid;
	}
	return lo;
}
int main()
{
	int n;
	scanf ("%d",&n);
	vector <int> v1;
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf ("%d",&val);
		v1.push_back (val);
	}
	cout << v1[2] << "\n";
	int ele;
	cin >> ele;
	cout << lower_bound (ele, 0, n-1) << "\n";
}
