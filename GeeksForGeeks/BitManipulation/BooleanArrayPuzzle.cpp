#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a[2] = {0};
	cin >> a[0] >> a[1];
	a[a[1]] = a[!a[1]];
	cout << a[0] << " " << a[1] << "\n";
	return 0;
}
