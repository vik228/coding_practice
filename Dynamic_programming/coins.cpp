#include <iostream>
#include <cstdio>
using namespace std;
#define INF 100000000
int Min[100];
int V[100];
int main()
{
	for (int i = 0; i < 100; i++)
	{
		Min[i] = INF;
	}
	int N;
	cout << "Enter the number of coins \n";
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> V[i];
	}
	int S;
	cout << "Enter the sum \n";
	cin >> S;
	Min[0] = 0;
	for (int i = 1; i <= S; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (V[j] <= i and (Min[i - V[j]] + 1) < Min[i])
				Min[i] = Min[i-V[j]] + 1;
		}
	}
	cout << Min[S] << "\n";
	return 0;

}
