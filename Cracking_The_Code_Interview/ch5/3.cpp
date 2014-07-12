#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int A, B;
	scanf ("%d%d",&A,&B);
	int count = 0;
	for (int c = A^B; c != 0; c = c >> 2)
	{
		count += c & 1;
	}
	int val = (3 & 1);
	cout << count << "\n";
}
