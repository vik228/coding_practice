#include <iostream>
using namespace std;
int min (int x, int y)
{
	return (y^((x^y) & -(x < y)));
}
int max (int x, int y)
{
	return (x ^ ((x^y) & -(x < y)));
}
int main()
{
	cout << min (3, 2) << "\n";
	cout << min (2, 3) << "\n";
	cout << max (3, 2) << "\n";
	cout << max (2, 3) << "\n";
	cout << (-102 & 1) << "\n";
	return 0;
}
