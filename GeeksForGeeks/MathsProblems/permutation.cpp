#include <iostream>
#include <cstdio>
using namespace std;
void swap (char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void permute (char *a, int i, int n)
{
	int j;
	if (i == n)
		cout << a << "\n";
	else
	{
		for (int j = i; j <= n; j++)
		{
			cout << "firt swapping " << i << "th and " << j << "th" << "element\n";
			swap ((a+i), (a+j));
			permute (a, i+1, n);
			cout << "Second swapping " << i << "th and " << j << "th" << "element\n";
			swap ((a+i), (a+j));

		}
	}
}
int main()
{
	char a[] = "ABC";
	permute (a, 0, 2);
}
