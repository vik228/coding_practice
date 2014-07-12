#include <iostream>
#include <cstdio>
using namespace std;
int addWithoutPlus (int x, int y)
{
	while (y != 0)
	{
		int carry = x & y;
		x = x^y;
		y = carry << 1;
	}
	return x;
}
int main()
{
	int x, y;
	cin >> x >> y;
	cout << addWithoutPlus (x, y) << "\n";
	return 0;
}
