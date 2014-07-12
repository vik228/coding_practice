#include <iostream>
#include <cstdio>
using namespace std;
bool oppositeSigns (int x, int y)
{
	//cout << (x^y) << "\n";
	return ((x^y) < 0);
}
int main()
{
	int m, n;
	scanf ("%d%d",&m,&n);
	if (oppositeSigns (m, n))
	{
		cout << "YES\n";
	}
	else
		cout << "NO\n";
	return 0;
}
