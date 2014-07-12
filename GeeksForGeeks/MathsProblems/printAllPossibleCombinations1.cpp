#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector <int> input;
void printAllCombinations (int n, int s, int t, int r, int data[], int idx)
{
	if (idx == r)
	{
		for (int i = 0; i < r; i++)
		{
			cout << data[i];
		}
		cout << "\n";
	}
	if (s >= n)
		return;
	data[idx] = input[s];
	printAllCombinations (n, s+1, t, r, data, idx+1);
	printAllCombinations (n, s+1, t, r, data, idx);
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		input.push_back (val);
	}
	int r;
	cin >> r;
	int data[r];
	memset (data, 0, sizeof (data));
	printAllCombinations (n, 0, n-1, r,data, 0);
}
