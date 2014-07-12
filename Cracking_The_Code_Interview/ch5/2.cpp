#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string s;
void convert (double d)
{
	double ans;
	while (s.length() < 32 and d > 0)
	{
		ans = 2*d;
		int ans1 = (int)2*d;
		s += (ans1 + '0');
		d = ans - ans1;
		cout << d << "\n";
	}
}
int main()
{
	double d;
	cin >> d;
	convert(d);
	cout << s << "\n";
}
