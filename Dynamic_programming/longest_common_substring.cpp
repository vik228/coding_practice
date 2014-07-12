#include <iostream>
#include <cstdio>
#include <cstring>
int dp[100][100];
using namespace std;
int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	int l1 = s1.length();
	int l2 = s2.length();
	int answer = 0;
	for (int i = 1; i <= l1; i++)
	{
		for (int j= 1; j <= l2; j++)
		{
			if (s1[i-1] == s2[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
				answer = max (answer, dp[i][j]);
			}
			else
				dp[i][j] = 0;
		}
	}
	for (int i = 0; i <= l1; i++)
	{
		for (int j = 0; j <= l2; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	cout <<  answer  << "\n";
	return 0;

}
