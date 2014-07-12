#include <iostream>
#include <cstdio>
using namespace std;
int multiply (int n1, int n2)
{
	if (n2 == 0)
		return 0;
	return (n1 + multiply (n1, n2-1));
		
}

int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	cout << multiply (num1, num2) << "\n";
}
