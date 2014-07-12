#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
set <string> printParens (int n)
{
	set <string> s1;
	if (n == 0)
	{
		s1.insert ("");
		return s1;
	}
	set <string> s2 = printParens (n-1);
	set <string>::iterator it;
	for (it = s2.begin(); it != s2.end(); it++)
	{
		string s = *it;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
			{
				string l = s.substr (0, i+1);
				string r = s.substr (i+1, s.length() - i - 1);
				s1.insert (l + "()" + r); 
			}
		}
		s1.insert (s + "()");

	}
	return s1;
}
int main()
{
	int n = 6;
	set <string> s = printParens (n);
	set <string>::iterator it;
	for (it = s.begin (); it != s.end(); it++)
		cout << *it << "\n";
}
