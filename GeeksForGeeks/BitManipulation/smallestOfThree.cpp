#include <iostream>
using namespace std;
int min (int x, int y)
{
	return (y + ((x - y) & (x - y) >> (sizeof (int)*8 - 1)));
}
int max (int x, int y)
{
	return (x - ((x-y) & (x-y) >> (sizeof (int)*8 - 1)));
}
int main()
{
	cout << min (2, 5) << "\n";
	cout << min (5, 2) << "\n";
	return 0;
}
