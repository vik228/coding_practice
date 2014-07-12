#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string in, pre;
int pos = 0;
void printPost (int i, int j, int p)
{
	int found = in.find (pre[pos++]);
	if (i > j)
	{
		return;
	}
	if (i == j)
	{
		cout << pre[pos-1] << " ";
		return;
	}
	printPost (i, found-1, pos);
	printPost (found+1, j, pos);
	cout << pre[p] << " ";

	return;
	
}
int main()
{
	cin >> in >> pre;
	printPost (0, in.length()-1, 0);
	return 0;
}
