#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector <int> input;
void printAllCombinations (int start, int end, int idx, int r, int data[])
{
	if (idx == r)
	{
		for (int i = 0; i < r; i++)
		{
			cout << data[i];
		}
		cout << "\n";
		return;
	}
	for (int j = start; (j <= end and (end-j+1) >= r-idx); j++)
	{
		data[idx] = input[j];
		printAllCombinations (j+1, end, idx+1, r, data);
	}
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
	printAllCombinations (0, n-1, 0, r, data);
}
