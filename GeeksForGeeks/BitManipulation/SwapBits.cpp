#include <iostream>
#include <cstdio>
using namespace std;
int swapBits (int x, int p1, int p2, int n)
{
	int set1 = (x >> p1) & ((1U << n) - 1);
	int set2 = (x >> p2) & ((1U << n) - 1);
	int XOR = set1 xor set2;
	XOR = (XOR << p1) | (XOR << p2);
	int result = x^ XOR;
	return result;
}
int main()
{
	int x, n;
	cin >> x;
	int p1, p2;
	cin >> p1 >> p2 >> n;
	x = swapBits (x, p1, p2, n);
	cout << x << "\n";
	return 0;
}
