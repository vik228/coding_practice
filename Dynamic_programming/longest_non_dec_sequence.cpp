#include <iostream>
#include <cstdio>
int A[100];
int dp[100];
using namespace std;
int main()
{
	int N;
	cout << "Enter the number of elements \n";
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	dp[0] = 1;
	for (int i = 1; i < N; i++)
	{
		if (A[i] >= A[i-1])
			dp[i] = dp[i-1] + 1;
		else
			dp[i] = dp[i-1];
	}
	cout << dp[N-1] << "\n";
	return 0;
	
}
