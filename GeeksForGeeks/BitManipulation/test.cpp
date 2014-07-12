#include  <iostream>
#include <cstdio>
using namespace std;
int main()
{
	cout << 2 << "\n";
	unsigned a = 9;
	int v = 9 & (~0 << 4);
	int k = ~0 << 4;
	cout << k << "\n";
	cout << ~a << "\n";
	return 0;
}
