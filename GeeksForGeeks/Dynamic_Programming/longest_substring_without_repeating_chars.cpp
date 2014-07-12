#include <iostream>
#include <cstdio>
#include <cstring>
bool occured[26];
using namespace std;
int ret_len (string s)
{
	int len = 0, max_len = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (!occured[s[i] - 'A'])
		{
			occured[s[i] - 'A'] = true;
			len++;
		}
		else
		{
			max_len = max (max_len, len);
			memset (occured, 0, sizeof (occured));
			len = 0;
		}
	}
	return max_len;
}
int main()
{
	string s;
	cin >> s;
	cout << ret_len (s) << "\n";
	return 0;
}
