#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector <int> input;
int findElement (int n)
{
	int min1 = input[0];
	for (int i = 1; i < n; i++)
	{
		min1 = min (min1, input[i]);
	}
	return min1;
}
int main()
{
	int n;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf ("%d",&val);
		input.push_back (val);
	}
	printf ("%d\n",findElement (n));
}
