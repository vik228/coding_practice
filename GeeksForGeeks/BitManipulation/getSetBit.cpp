#include <iostream>
#include <cstdio>
using namespace std;
int getSetBit (int n)
{
	unsigned i = 1;
	unsigned j = 1;
	int pos = 1;
	while (!(j&n))
	{
		//cout << i << "\n";
		j = 1 << i;
		i++;
		pos++;
	}
	return pos;
}
int main()
{
	int n;
	cin >> n;
	if (n&(n-1))
		cout << "Invalid Number\n";
	else
		cout << getSetBit (n) << "\n";
	return 0;
}
