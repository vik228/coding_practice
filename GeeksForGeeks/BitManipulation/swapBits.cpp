#include <iostream>
#include <cstdio>
using namespace std;
unsigned int swapBits (unsigned int x)
{
	unsigned int even_bits = x & 0xAAAAAAAA;
	unsigned int odd_bits = x & 0x55555555;
	even_bits >>= 1;
	odd_bits <<= 1;
	return (even_bits | odd_bits);
}
int main()
{
	unsigned int a = 23;
	cout << swapBits (a) << "\n";
	return 0;
}
