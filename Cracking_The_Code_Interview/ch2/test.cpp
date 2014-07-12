#include <iostream>
using namespace std;
int recurse (int x, int y)
{
	cout << x << " " << y << "\n";
	if (y == 0)
		return 0;
	if (y > 0)
		return (x + recurse (x, y-1));
	if (y < 0)
		 return (-recurse (x, x-1));
}
int main()
{
	cout << recurse (3, 11) << "\n";
	return 0;
}
