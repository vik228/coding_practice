#include <iostream>
using namespace std;
int iterFIB(int A[], int n)
{
	A[0] = 0;
	A[1] = 1;
	for (int i = 2; i < n; i++)
		A[i] = A[i - 1] + A[i - 2];
	return A[n - 1];
}
int main()
{
	int A[7];
	cout << iterFIB(A,7);
	return 0;

}
