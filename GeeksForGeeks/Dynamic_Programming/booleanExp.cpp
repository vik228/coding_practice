#include <iostream>
#include <cstdio>
using namespace std;
int dp[100][100];
bool isTrue[100][100];
int val[100];
char operand[100];
void findWays (int n, int res)
{
	for (int i = 0; i < n; i++)
	{
		if (val[i] == res)
		{
			dp[i][i] = 1;
			isTrue[i][i] = true;
		}

	}
	for (int l = 2; l < n; l++)
	{
		for (int i = 0; i < n-l+1; i++)
		{
			int j = i + l - 1;
			if (l == 2)
			{
				if (operand[i] == '^')
				{
					isTrue[i][j] = val[i] ^ val[j];
				}
				else if (operand[i] == '|')
					isTrue[i][j] = val[i] | val[j];
				else
					isTrue[i][j] = val[i] & val[j];
			}
			else
			{
				
			}


		}
	}
}
int main()
{
	string s;
	cin >> s;
	int k1 = 0, k2 = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0' or s[i] == '1')
			val[k1++] = (s[i] - '0');
		else
		{
			operand[k2++] = s[i];
		}
	}
	int res;
	scanf ("%d",&res);
	findWays (k1, res);
	return 0;
	
}

