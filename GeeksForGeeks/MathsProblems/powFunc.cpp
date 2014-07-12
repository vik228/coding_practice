#include <iostream>
#include <cstdio>
using namespace std;
int myPow (int n, int i)
{
	//cout << n << " " << i << "\n";
	if (i == 0)
		return 0;
	return (n + myPow (n, i-1));
}
int main()
{
	int n,i;
	cin >> n >> i;
	int ans = n;
	for (int j = 0; j < i-1; j++)
	{
		ans = myPow (ans, n);
	
	}
	cout << ans << "\n";
}
