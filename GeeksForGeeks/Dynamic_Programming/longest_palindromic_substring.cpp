#include <iostream>
#include <cstdio>
using namespace std;
bool isPalin[100][100];
void longestPalindromicSubstring(string s)
{
	int n = s.length();
	int maxLen = 1;
	int start;
	for (int i = 0; i < n; i++)
	{
		isPalin[i][i] = true;
	}
	for (int i = 0; i < n-1; i++)
	{
		if (s[i] == s[i+1])
		{
			isPalin[i][i+1] = true;
			maxLen = 2;
			start = i;
		}
	}
	for (int l = 3; l <= n; l++)
	{
		for (int i = 0; i < n-l+1; i++)
		{
			int j = i + l - 1;
			isPalin[i][j] = ((s[i] == s[j]) and (isPalin[i+1][j-1]));
			if (isPalin[i][j])
			{
				if (l > maxLen)
				{
					start = i;
					maxLen = l;
				}
			}

		}
	}
	string ans;
	for (int i = start; i < (start + maxLen); i++)
	{
		cout << s[i];
	}
	cout << "\n";
}
int main()
{
	string s;
	cin >> s;
	longestPalindromicSubstring(s);
	return 0;

}
