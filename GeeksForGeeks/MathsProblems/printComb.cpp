#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 100
void printCombs (int itr,int n)
{
	static int data[MAX];
	if (n < 0)
		return;
	if (n == 0)
	{
		for (int i = 0; i < itr; i++)
			cout << data[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= 3; i++)
	{
		data[itr] = i;
		printCombs (itr+1, n-i);
	}

}
int main()
{
	int n;
	cin >> n;
	printCombs (0, n);
}
