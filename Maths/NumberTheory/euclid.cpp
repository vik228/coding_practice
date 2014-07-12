#include <iostream>
#include <cstdio>
using namespace std;
int euclid (int a, int b)
{
	if (b == 0)
		return a;
	else
		return (euclid (b, a%b));
}
int euclidIterative (int a, int b)
{
	while (b > 0)
	{
		int p = a%b;
		a = b;
		b = p;
	}
	return a;
}
int main()
{
	int a, b;
	scanf ("%d%d",&a,&b);
	cout << euclidIterative (a, b) << "\n";
	return 0;
}
