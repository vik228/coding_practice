#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> input, freq;
int myRand (int n)
{
	srand (time (NULL));
	vector <int> cum_freq;
	cum_freq.push_back (freq[0]);
	for (int i = 1; i < freq.size(); i++)
	{
		cum_freq.push_back (freq[i] + cum_freq[i-1]);
	}
	int r = rand ()%(cum_freq[n-1]+1);
	int idx = upper_bound (cum_freq.begin(), cum_freq.end(), r) - cum_freq.begin();
	return input[idx];
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
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		freq.push_back (val);
	}
	cout << myRand (n) << "\n";
	return 0;

}
