#include <iostream>
#include <cstdio>
using namespace std;
bool isMultipleOf3 (int n)
{
	int odd_count = 0;
	int even_count = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		return true;
	if (n == 1)
		return false;
	while (n)
	{
		if (n&1)
			odd_count++;
		n >>= 1;
		if (n&1)
			even_count++;
		n >>= 1;
	}
}
int main()
{
	int n;
	cin >> n;
	if (isMultipleOf3(n))
		cout << "YES\n";
	else
		cout << "NO\n";
}
