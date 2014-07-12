#include <iostream>
#include <cstdio>
#include <cstring>
int isAvailable[8];
#define chk(i) ((isAvailable[i >> 8])&(1 << (i & 31))) 
#define set(i) ((isAvailable[i >> 8])|=(1 << (i & 31)))
using namespace std;
bool isUnique (string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		int v = chk(s[i]);
		if (v == 0)
			set(s[i]);
		else
			return false;
	}
	return true;
}
int main()
{
	int T;
	scanf ("%d",&T);
	string s;
	getline (cin, s);
	while (T--)
	{
		getline (cin, s);
		if (isUnique (s))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
