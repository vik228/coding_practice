#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int LSubstr[100][100];
int find_LSubstr (string s1, string s2)
{
	int res = 0;
	for (int i = 0; i <= s1.length(); i++)
	{
		for (int j = 0; j <= s2.length(); j++)
		{
			if (i == 0 or j == 0)
				LSubstr[i][j] = 0;
			if (s1[i-1] == s2[j-1])
				LSubstr[i][j] = LSubstr[i-1][j-1] + 1;
			else
				LSubstr[i][j] = 0;
			res = max (res, LSubstr[i][j]);
		}
	}
	return res;
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << find_LSubstr(s1, s2) << "\n";
	return 0;
}
