#include <iostream>
#include <cstdio>
using namespace std;
bool isLucky_iter (int n)
{
	//bool found = false;
	for (int i = 2;; i++)
	{
		if (i > n)
			return true;
		if (n%i == 0)
			return false;
		n -= n/i;
		
	}
}
bool isLucky_rec (int n)
{
	static int counter = 2;
	if (counter > n)
		return true;
	if (n%counter == 0)
		return false;
	n -= n/counter;
	counter++;
	return (isLucky_rec (n));
}
int main()
{
	int n;
	cin >> n;
	if (isLucky_iter(n))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
