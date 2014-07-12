#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int lcs[10][10];
int LCS (string s1, string s2)
{
	int m = s1.length();
	int n = s2.length();
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s1[i-1] == s2[j-1])
			{
				lcs[i][j] = 1 + lcs[i-1][j-1];
			}
			else
				lcs[i][j] = max (lcs[i-1][j], lcs[i][j-1]);
		}
	}
	return lcs[m][n];
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << LCS (s1, s2) << "\n";
	for (int i = 0; i <= s1.length(); i++)
	{
		for (int j = 0; j <= s2.length(); j++)
		{
			cout << lcs[i][j] << " ";
		}
		cout << "\n";
	}
	//cout << LCS (s1, s2) << "\n";
	return 0;
}
