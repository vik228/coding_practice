#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
bool isFibo (int n)
{
	int val1 = 5*n*n + 4;
	int val2 = 5*n*n - 4;
	int sqrtVal1 = sqrt (val1);
	int sqrtVal2 = sqrt (val2);
	if ((sqrtVal1*sqrtVal1 == val1) or sqrtVal2*sqrtVal2 == val2)
		return true;
	return false;
}
int main()
{
	int n;
	cin >> n;
	if (isFibo (n))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
