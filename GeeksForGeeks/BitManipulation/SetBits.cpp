#include <iostream>
#include <cstdio>
using namespace std;
int countSetBits (int n)
{
	int cnt = 0;
	while (n)
	{
		cnt += n&1;
		n >>= 1;

	}
	return cnt;
}
int main()
{
	int n;
	scanf ("%d",&n);
	cout << countSetBits (n) << "\n";
	return 0;
}
