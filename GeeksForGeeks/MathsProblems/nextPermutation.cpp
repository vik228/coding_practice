#include <iostream>
#include <cstring>
using namespace std;
bool generatePermutations (string& s)
{
	bool isPossible = true;
	int k = -1;
	for (int i = s.length()-1; i >= 0; i--)
	{
		if (s[i] > s[i-1])
		{
			k = i-1;
			break;
		}

	}
	if (k == -1)
		return false;
	int l = k+1;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] > s[k])
		{
			l = i;
			break;
		}
	}
	swap (s[k], s[l]);
	int i = k+1;
	int j = s.length() - 1;
	//cout << i << " " << j << "\n";
	while (i < j)
	{
		//cout << i << " " << j << "\n";
		swap (s[i], s[j]);
		i++;
		j--;


	}
	return true;
}
int main()
{
	string s = "ABC";
	while (generatePermutations (s))
	{
		for (int i = 0; i < s.length(); i++)
			cout << s[i];
		cout << "\n";
	}

}
