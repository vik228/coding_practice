/*
 This method is wrong....
 Test case : cdf and aff, these two strings have same sum but they are not permutations of each other.......
 */
#include <iostream>
#include <cstdio>
using namespace std;
bool isPermutation (string s1, string s2)
{
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		sum1 += s1[i];
		sum2 += s2[i];
	}
	if (sum1 == sum2)
		return true;
	else
		return false;
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.length() != s2.length())
		cout << "NO\n";
	else if (isPermutation (s1, s2))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}

