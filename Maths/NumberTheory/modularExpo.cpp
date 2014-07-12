#include <iostream>
#include <cstdio>
using namespace std;
long long mulmod (long long, long long, long long);
long long modularExpo (long long a, long long b, long long c)
{
	long long x = 1, y = a;
	while (b > 0)
	{
		if (b % 2 == 1)
		{
			x = mulmod (x, y, c);
		}
		y = mulmod (y, y, c);
		b/= 2;
	}
	return x%c;
}
long long mulmod (long long a, long long b, long long c)
{
	long long x = 0, y = a%c;
	while (b > 0)
	{
		if (b % 2 == 1)
			x = (x+y)%c;
		y = (y*2)%c;
		b/= 2;
	}
	return x%c;
}
int main()
{
	cout << modularExpo (7, 107, 9) << "\n";
	return 0;
}
