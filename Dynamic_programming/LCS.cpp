#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[100][100];
char b[100][100];
void print_LCS (string s1, int l1, int l2)
{
	if (l1 == 0 or l2 == 0)
		return;
	if (b[l1][l2] == 'd')
	{
		print_LCS (s1, l1-1, l2-1);
		cout << s1[l1 - 1] << " ";
	}
	else if (b[l1][l2] == 'u')
		print_LCS (s1, l1-1, l2);
	else
		print_LCS (s1, l1, l2-1);
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int l1 = s1.length();
	int l2 = s2.length();
	for (int i = 1; i <= max (l1, l2); i++)
	{
		for (int j = 1; j <= min (l1, l2); j++)
		{
			if (s1[i-1] == s2[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
				b[i][j] = 'd';
			}
			else
			{
				if (dp[i-1][j] >= dp[i][j-1])
				{
					dp[i][j] = dp[i-1][j];
					b[i][j] = 'u';
				}
				else
				{
					dp[i][j] = dp[i][j-1];
					b[i][j] = 'l';
				}
					
			}
		}
	}
	/*
	for (int i = 1; i <= max (l1, l2); i++)
	{
		for (int j = 1; j <= min (l1,l2); j++)
		{
			cout << b[i][j] << "\t";
		}
		cout << "\n";
	}
	*/
	cout << dp[max(l1,l2)][min (l1,l2)] << "\n";
	print_LCS (s1, max (l1, l2), min (l1, l2));
	cout << "\n";
}
