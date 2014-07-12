#include <iostream>
#include <cstdio>
using namespace std;
int input[100];
bool isSubsetSum (int n, int sum)
{
	cout << "Calling with " << n-1 << " " << sum << "\n";
	if (n == 0 and sum != 0)
		return false;
	if (sum == 0)
		return true;
	if (input[n-1] > sum)
		return isSubsetSum (n-1, sum);
	bool val1 = isSubsetSum (n-1, sum);
	//cout << "Calling with " << n-1 << " " << sum - input[n-1] << "\n";
	bool val2 = isSubsetSum (n-1, sum - input[n-1]);
	return (val1 || val2);
}
int main()
{
	int n;
	scanf ("%d",&n);
	int val = 0;
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&input[i]);
		val += input[i];
	}
	if (val % 2 == 1)

		cout << "No " << "\n";
	else if (isSubsetSum (n, val/2))
		cout << "yes " << "\n";
	return 0;

}
