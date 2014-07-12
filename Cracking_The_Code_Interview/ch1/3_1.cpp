#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
bool isPermutation (string A, string B)
{
	sort (A.begin(), A.end());
	sort (B.begin(), B.end());
	return (A.compare(B) == 0);
}
int main()
{
	string A, B;
	cin >> A >> B;
	if (isPermutation (A, B))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
