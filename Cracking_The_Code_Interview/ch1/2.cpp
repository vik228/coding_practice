#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void reverse (string& s)
{
	int i = 0;
	int j = s.length() - 1;
	while (i != j)
	{
		s[i] = s[i] ^ s[j];
		s[j] = s[i] ^ s[j];
		s[i] = s[i] ^ s[j];
		i++;
		j--;
		//cout << s << "\n";
	}
}
int main ()
{
	int T;
	string s;
	scanf ("%d",&T);
	getline (cin, s);
	while (T--)
	{
		getline (cin, s);
		reverse (s);
		cout << s << "\n";
	}
}
