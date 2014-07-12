#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
#define MAX 10010
bool p[MAX][MAX];
int c[MAX][MAX];
int MinPalPartition (string s)
{
	int n = s.length();
	for (int i = 0; i < s.length(); i++)
	{
		p[i][i] = true;
		c[i][i] = 0;
	}
	for (int L = 2; L <= s.length(); L++)
	{
		for (int i = 0; i < n-L+1; i++)
		{
			int j = i + L - 1;
			if (L == 2)
				p[i][j] = (s[i] == s[j]);
			else
			{
				p[i][j] = ((s[i] == s[j]) and (p[i+1][j-1]));
			}
			if (p[i][j] == true)
				c[i][j] = 0;
			else
			{
				c[i][j] = INT_MAX;
				for (int k = i; k <= j-1; k++)
					c[i][j] = min (c[i][j], c[i][k] + c[k+1][j] + 1);
			}
		}

	}
	return c[0][n-1];
}
int main()
{
	string s1;
	cin >> s1;
	cout << s1.length() << "\n";
	cout << MinPalPartition (s1) << "\n";
}
