#include <iostream>
#include <cstdio>
#include <vector>
int count[10];
using namespace std;
int out[10];
int main()
{
	vector <int> v1;
	int N;
	scanf ("%d",&N);
	int val;
	for (int i = 0; i < N; i++)
	{
		scanf ("%d",&val);
		v1.push_back (val);
		count[val] += 1;
	}
	for (int i = 1; i <= N; i++)
	{
		count[i] = count[i-1] + count[i];
	}
	for (int i = 0; i < N; i++)
		cout << count[i] << " ";
	cout << "\n";
	for (int i = 0; i < N; i++)
	{
		cout << v1[i] << " " << count[v1[i]] - 1 << "\n";
		out[count[v1[i]] - 1] = v1[i];
		--count[v1[i]];

	}
	for (int i = 0; i < N; i++)
	{
		v1[i] = out[i];
	}
	for (int i = 0; i < N; i++)
		cout << v1[i] << "\n";
	return 0;



}
