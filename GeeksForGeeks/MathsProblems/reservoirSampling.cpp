#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	vector <int> v1;
	vector <int> reservior;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		v1.push_back (val);
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		reservior.push_back (v1[i]);
	}
	srand (time(NULL));
	for (int i = k; i < n; i++)
	{
		int j = rand()%i;
		if (j < k)
			reservior[j] = v1[i];
	}
	for (int i = 0; i < reservior.size(); i++)
		cout << reservior[i] << "\n";
	return 0;
}
