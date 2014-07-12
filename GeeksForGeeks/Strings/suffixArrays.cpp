#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
int main()
{
	string s;
	map <string, int> m1;
	cin >> s;
	vector <string> v;
	for (int i = 0; i < s.length(); i++)
	{
		m1[s.substr (i, s.length()-i)] = i;
		v1.push_back (s.substr (i, s.length()-i));
	}
	sort (v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << m1[v1[i]] << "\n";
	}
}
