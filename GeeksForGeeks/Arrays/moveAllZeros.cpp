#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int v1[100];
int main()
{
	int cnt = 0;
	int val;
	int N;
	scanf ("%d",&N);
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		scanf ("%d",&val);
		if (val == 0)
			cnt++;
		else
			v1[j++] = val;
	}
	for (int i = 0; i < N; i++)
		cout << v1[i] << " ";
	cout << "\n";
}
