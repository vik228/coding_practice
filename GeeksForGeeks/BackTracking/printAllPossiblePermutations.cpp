#include <iostream>
#include <cstring>
using namespace std;
void printAllKLength(string s, string prefix, int n, int k)
{
	if (k == 0)
	{
		cout << prefix << "\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		string newprefix = prefix + s[i];
		printAllKLength(s, newprefix, n, k-1);
	}

}
int main()
{
	string s;
	int k;
	cin >> s >> k;
	printAllKLength(s, "",s.length(), k);
}
