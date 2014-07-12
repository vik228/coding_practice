#include <iostream>
#include <cstring>
using namespace std;
int makeLengthEqual (string &s1, string &s2)
{
	int len1 = s1.length(); 
	int len2 = s2.length();
	if (len1 < len2)
	{
		for (int i = 0; i < len2-len1; i++)
		{
			s1 = '0' + s1;
		
		}
		return len2;
	}
	else if (len1 > len2)
	{
		for (int i = 0; i < len1 - len2; i++)
		{
			s2 = '0' + s2;
		}
		return len1;
		
	}
}
string addBitStrings (string s1, string s2)
{
	int length = makeLengthEqual (s1, s2);
	//cout << s1 << " " << s2 << " " << length << "\n";
	int carry = 0;
	string add = " ";
	for (int i = length - 1; i >= 0; i--)
	{
		int a = s1[i] - '0';
		int b = s2[i] - '0';
		int c = (a ^ b ^ carry) + '0';
		add = (char)c + add;
		carry = (a&b)|(a&carry)|(b&carry);
	}
	return add;
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << addBitStrings(s1, s2) << "\n";
	return 0;

}
