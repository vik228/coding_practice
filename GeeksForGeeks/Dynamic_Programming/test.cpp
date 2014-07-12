#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	string s = "abcdef";
	int i;
	scanf ("%d",&i);
	string a = s.substr (i + 1 , s.length() - i - 1);
	cout << a << "\n";
	return 0;

}
