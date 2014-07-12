//program to determin if a string has all unique characters...
#include <iostream>
#include <cstdio>
#include <cstring>
bool isAvailable[256];
using namespace std;
bool isUnique (string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (isAvailable[s[i]])
			return false;
		else
			isAvailable[s[i]] = true;
	}
	return true;
}
int main()
{
	string s;
	getline (cin, s);
	if (isUnique (s))
		cout << "YES\n";
	else
		cout << "NO\n";
}
