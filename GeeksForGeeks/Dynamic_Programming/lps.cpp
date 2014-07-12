#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int lps (string s1)
{
	int n = s1.length();
	int i, j, cl;
	int L[n][n];
	for (i = 0; i < n; i++)
		L[i][i] = 1;
	for (cl = 2; cl <= n; cl++)
	{
		for (i = 0; i < n-cl+1; i++)
		{
			j = i + cl - 1;
			if (s1[i] == s1[j] and cl == 2)
				L[i][j] = 2;
			else if (s1[i] == s1[j])
				L[i][j] = L[i+1][j-1] + 2;
			else
				L[i][j] = max (L[i][j-1], L[i+1][j]);
		}
	}
	return L[0][n-1];

}
int main()
{
	string s;
	cin >> s;
	cout << lps (s) << "\n";
	return 0;

}
