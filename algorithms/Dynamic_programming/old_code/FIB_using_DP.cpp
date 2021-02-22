#include <iostream>
#include <cstring>
#define MAX 10
int A[MAX];
using namespace std;
int fib(int n)
{
	if ( n < 2)
		return n;
	else
	{
		if (!A[n])
			A[n] = fib(n-1) + fib(n-2);
		else
			return A[n];
	}
		
	
}
int main()
{
	memset(A,0,sizeof(A));
	int p = fib(7);
	for (int i = 0; i < 7; i++)
		cout << A[i] << "\n";
}
