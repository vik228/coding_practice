#include <iostream>
#include <cstdio>
using namespace std;
string convertBinaryToDecimal (int n)
{
	string s = "";
	while (n > 0)
	{
		//cout << n << " " << (n&1) << "\n";
		int i = (n&1) + '0';
		//cout << i << "\n";
		s = (char)i + s;
		n >>= 1;

	}
	return s;
}
int main()
{
	int n;
	scanf ("%d",&n);
	cout << convertBinaryToDecimal (n) << "\n";
	return 0;
}
